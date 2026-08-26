#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"
#include "hexapod_interfaces/msg/leg_actuators.hpp"
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
            leg = this->create_publisher<hexapod_interfaces::msg::LegActuators>("leg", 10);
            coords = this->create_subscription<hexapod_interfaces::msg::Coordinates>("coords", 10, std::bind(&control_leg::solver, this, std::placeholders::_1));
            timer = this->create_wall_timer(std::chrono::milliseconds(this->milliss), std::bind(&control_leg::placeholder_method, this));
            // coords = this->create_subscription<hexapod_interfaces::msg::Coordinates>("coords", 10, std::bind(&control_leg::solver, this, std::placeholders::_1));
            x = 0.00;
            y = 0.00;
            z = 0.00;   
            coxa = 90.0f;
            femur = 90.0f;
            tibia = 90.0f;
        }
    private:
        struct Point3d {
            float x;
            float y;
            float z;
        };

        void placeholder_method(){
            if(!target_reached){
                time += 1;
                Point3d current = lerp(start, end, (float)time/((float) this->sampling));
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

        Point3d lerp(Point3d start, Point3d end, float t){
            Point3d result;
            result.x = start.x + ((end.x - start.x) * t);
            result.y = start.y + ((end.y - start.y) * t);
            result.z = start.z + ((end.z - start.z) * t);
            
            return result;
        }

        void solver(const hexapod_interfaces::msg::Coordinates::SharedPtr msg){  
            this->start = {this->coxa, this->femur, this->tibia}; 
            
            double a = this->femur_l;
            double b = this->tibia_l;
            double c = hypot(msg->z - 0, msg->y);
            

            float alpha = atan2(-msg->z, msg->y) * 180.0f/M_PI;
            float beta = (acos(( ( a * a ) +( c * c ) - ( b * b )) / ( 2 * a * c ))) * 180.0f/M_PI;

            if (std::isnan(beta)) {
                beta = 90.0f;
            }

            float gamma = acos(( ( a * a ) + ( b * b ) - ( c * c )) / (2 * a * b ) )* 180.0f/M_PI;

            if (std::isnan(gamma)) {
                gamma = 90.0f;
            }
            
            float delta = (msg->x == 0 ? 0.0f : (atan2(msg->x, msg->y) * 180.0f/M_PI));
                
            this->coxa = 90 - delta;
            RCLCPP_INFO(this->get_logger(), "X: %f, %f, %f", msg->x, atan(msg->x/msg->y), this->coxa);
            this->femur = std::clamp(std::abs(alpha + beta + 90), 0.0f, 180.0f);
            this->tibia = std::clamp(std::abs(gamma), 0.0f, 180.0f);

            this->end = {this->coxa, this->femur, this->tibia};
            target_reached = false;
            RCLCPP_INFO(this->get_logger(), "Started Interpolating at %d samples and at %d Time", this->sampling, this->milliss);
            time = 0;
        }

    rclcpp::TimerBase::SharedPtr timer;
    int counter;
    float x, y, z;
    float coxa, femur, tibia;
    const int coxa_l = 50;
    const int femur_l = 75;
    const int tibia_l = 112.256;
    bool target_reached = true;
    int time = 0;
    Point3d start;
    Point3d end;
    int sampling = 200;
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
