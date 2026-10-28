#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"
#include "hexapod_interfaces/msg/leg_actuators.hpp"
#include "hexapod_interfaces/msg/leg.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

class control_leg : public rclcpp::Node
{
    public:
        control_leg() : Node("leg_control"), counter(1){

            RCLCPP_INFO(this->get_logger(), "Booting UP");

            // Publishes calculated joint angles to the leg controller
            leg = this->create_publisher<hexapod_interfaces::msg::LegActuators>("leg", 10);

            // Receives target foot coordinates and calculates IK
            coords = this->create_subscription<hexapod_interfaces::msg::Coordinates>(
                "coords", 10,
                std::bind(&control_leg::solver, this, std::placeholders::_1)
            );

            // Runs interpolation every 10 ms
            timer = this->create_wall_timer(
                std::chrono::milliseconds(this->milliss),
                std::bind(&control_leg::publisher, this)
            );

            x = 0.00;
            y = 0.00;
            z = 0.00;

            // Initial joint positions
            coxa = 90.0f;
            femur = 90.0f;
            tibia = 90.0f;
        }

    private:

        // Stores a 3D point or a set of three joint angles
        struct Point3d {
            float x;
            float y;
            float z;
        };

        void publisher(){

            if(!target_reached){

                time += 1;

                // Generate the next intermediate position
                Point3d current = lerp(
                    start,
                    end,
                    (float)time / ((float)this->sampling)
                );

                auto angles = hexapod_interfaces::msg::LegActuators();

                angles.coxa = current.x;
                angles.femur = current.y;
                angles.tibia = current.z;

                this->leg->publish(angles);

                if(time == this->sampling){
                    target_reached = true;
                    RCLCPP_INFO(this->get_logger(), "Finished Interpolating");
                }
            }
        }

        // Linear interpolation between the current and target angles
        Point3d lerp(Point3d start, Point3d end, float t){

            Point3d result;

            result.x = start.x + ((end.x - start.x) * t);
            result.y = start.y + ((end.y - start.y) * t);
            result.z = start.z + ((end.z - start.z) * t);

            return result;
        }

        void solver(const hexapod_interfaces::msg::Coordinates::SharedPtr msg){

            // Save the current joint angles as the interpolation starting point
            this->start = {this->coxa, this->femur, this->tibia};
            if(msg->sampling != 0){
                this->sampling = msg->sampling;
            }


            const double R2D = 180.0 / M_PI;
            auto sind  = [&](double deg){ return std::sin(deg / R2D); };
            auto atand = [&](double v)  { return std::atan(v) * R2D; };
            auto acosd = [&](double v)  { return std::acos(v) * R2D; };
         
            double a = this->coxa_l;     // MATLAB a
            double b = this->femur_l;    // MATLAB b
            double c = this->tibia_l;    // MATLAB c
            double target_x = msg->x;
            double target_y = msg->y;
            double target_z = -msg->z;   // MATLAB target_z is positive DOWN; msg->z is UP
         
            double t1 = std::atan2(target_y + a, target_x) * R2D;
            target_y = (target_y) / sind(t1);
            double d = std::sqrt(std::pow(target_y + a, 2) + std::pow(target_z, 2));
            double alpha = std::abs(atand((target_y + a) / -target_z));
            if (std::isnan(alpha)) {
                alpha = 0;
            }
            double beta = acosd(((b * b) + (d * d) - (c * c)) / (2 * b * d));
            if (std::isnan(beta)) {
                beta = 0;
            }
            double gamma = acosd(((b * b) + (c * c) - (d * d)) / (2 * b * c));
            double t2 = beta + alpha;
            double t3 = 180 - (gamma);
            double alpha2 = std::abs(90 - t2);
            t3 = 180 - (90 - alpha2);


            // IK angles into servo angles
            this->coxa = t1 * 180.0f / M_PI;

            this->femur = std::clamp(
                std::abs(alpha + beta + 90),
                0.0f,
                180.0f
            );

            this->tibia = std::clamp(
                std::abs(gamma),
                0.0f,
                180.0f
            );

            // Set the calculated angles as the interpolation target
            this->end = {this->coxa, this->femur, this->tibia};

            target_reached = false;

            RCLCPP_INFO(
                this->get_logger(),
                "Started Interpolating at %d samples and at %d Time",
                this->sampling,
                this->milliss
            );

            RCLCPP_INFO(
                this->get_logger(),
                "Coxa, Femur, Tibia: %f, %f, %f",
                std::abs(this->coxa),
                std::abs(this->femur),
                std::abs(this->tibia)
            );

            time = 0;
        }

        rclcpp::TimerBase::SharedPtr timer;

        int counter;

        float x, y, z;

        // Current joint angles
        float coxa, femur, tibia;

        // Physical leg segment lengths in mm
        const int coxa_l = 50;
        const int femur_l = 75;
        const int tibia_l = 112.256;

        bool target_reached = true;

        // Current interpolation step
        int time = 0;

        Point3d start;
        Point3d end;

        // 60 interpolation steps, each 10 ms apart
        int sampling = 60;
        int milliss = 10;

        rclcpp::Publisher<hexapod_interfaces::msg::LegActuators>::SharedPtr leg;

        rclcpp::Subscription<hexapod_interfaces::msg::Coordinates>::SharedPtr coords;
};


int main(int argc, char **argv){

    rclcpp::init(argc, argv);

    auto node = make_shared<control_leg>();

    rclcpp::spin(node);

    rclcpp::shutdown();
}
