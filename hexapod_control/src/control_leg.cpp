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

            constexpr double R2D = 180.0 / M_PI;
            auto sind  = [&](double deg) { return std::sin(deg / R2D); };
            auto atand = [&](double v)   { return std::atan(v) * R2D; };
            auto acosd = [&](double v)   { return std::acos(std::clamp(v, -1.0, 1.0)) * R2D; };
        
            const double a = this->coxa_l;
            const double b = this->femur_l;
            const double c = this->tibia_l;
        
            const double target_x = msg->x;
            double target_y = msg->y;
            const double target_z = -msg->z;   // positive DOWN; msg->z is UP
        
            // ---- Coxa ----
            double t1 = std::atan2(target_y + a, target_x) * R2D;
        
            // Horizontal reach in the leg plane (guard against sin(t1) ~ 0)
            const double s = sind(t1);
            if (std::abs(s) > 1e-6) {
                target_y = target_y / s;
            } else {
                target_y = std::abs(target_x);   // target lies along the x axis
            }
        
            // ---- Femur / Tibia ----
            const double d = std::sqrt(std::pow(target_y, 2) + std::pow(target_z, 2));
        
            // Reachability check
            if (d > b + c || d < std::abs(b - c) || d < 1e-9) {
                RCLCPP_WARN(this->get_logger(),
                            "Target (%.1f, %.1f, %.1f) unreachable (d = %.1f, range %.1f..%.1f)",
                            msg->x, msg->y, msg->z, d, std::abs(b - c), b + c);
                return;   // keep the previous pose, don't touch start/end
            }
        
            // Update sampling only once the target is accepted
            if (msg->sampling != 0) {
                this->sampling = msg->sampling;
            }
        
            double alpha = (std::abs(target_z) > 1e-9)
                               ? std::abs(atand((target_y) / -target_z))
                               : 90.0;
        
            const double beta  = acosd(((b * b) + (d * d) - (c * c)) / (2 * b * d));
            const double gamma = acosd(((b * b) + (c * c) - (d * d)) / (2 * b * c));
        
            // ---- Servo angles ----
            // ---- t2, t3 (same as MATLAB) ----
            const double t2     = beta + alpha;
            if(t2 >= 90){
                const double alpha2 = std::abs(90.0 - t2);
                t3 = 180.0 - (90.0 - alpha2);
            }
            else{
                t3 = 180 - gamma;
            }
            // ASSUMPTION: keep your original mapping (femur = alpha + beta + 90, tibia = gamma).
            // Swap in t2 / t3 below if you want the MATLAB-style mapping instead.
            const double femur_deg = std::clamp(std::abs(t2), 0.0, 180.0);
            const double tibia_deg = std::clamp(std::abs(t3),               0.0, 180.0);
        
            // Interpolation start = current angles, end = new target
            this->start = {this->coxa, this->femur, this->tibia};
        
            this->coxa  = t1;          // already in degrees
            this->femur = femur_deg;
            this->tibia = tibia_deg;
        
            this->end = {this->coxa, this->femur, this->tibia};
            this->target_reached = false;
            this->time = 0;
        
            RCLCPP_INFO(this->get_logger(),
                        "Started interpolating: %ld samples, %ld ms",
                        static_cast<long>(this->sampling),
                        static_cast<long>(this->milliss));
            RCLCPP_INFO(this->get_logger(),
                        "Coxa, Femur, Tibia: %.2f, %.2f, %.2f",
                        this->coxa, this->femur, this->tibia);
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
        double t3 = 0;     
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
