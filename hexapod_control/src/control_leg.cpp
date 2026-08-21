#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"
#include "hexapod_interfaces/msg/leg_actuators.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class control_leg : public rclcpp::Node
{
    public:
        control_leg() : Node("leg_control"), counter(1){
            RCLCPP_INFO(this->get_logger(), "Booting UP");
            leg = this->create_publisher<hexapod_interfaces::msg::LegActuators>("leg", 10);
            coords = this->create_subscription<hexapod_interfaces::msg::Coordinates>("coords", 10, std::bind(&control_leg::traverse, this, std::placeholders::_1));
            x = 0.00;
            y = 0.00;
            z = 0.00;            
        }
    private:
        struct Point3d {
            float x;
            float y;
            float z;
        };

        Point3d lerp(Point3d start, Point3d end, float t){
            Point3d result;
            result.x = start.x + ((end.x - start.x) * t);
            result.y = start.y + ((end.y - start.y) * t);
            result.z = start.z + ((end.z - start.z) * t);
            
            return result;
        }
        
        void traverse(const hexapod_interfaces::msg::Coordinates::SharedPtr msg){
            Point3d start = {this->x, this->y, this->z};
            Point3d end = {msg->x, msg->y, msg->z};

            for(int i = 0; i <= 50; i++){

                float s = (float)i/50.0f;
                this->result = lerp(start, end, s);
                solver(result.x, result.y, result.z);
                RCLCPP_INFO(this->get_logger(), "X: %f", this->result.x);
                RCLCPP_INFO(this->get_logger(), "Y: %f", this->result.y);
                RCLCPP_INFO(this->get_logger(), "Z: %f", this->result.z);
                RCLCPP_INFO(this->get_logger(), "");
                
            }

        }

        void solver(float _x, float _y, float _z){

            auto angles = hexapod_interfaces::msg::LegActuators();  
            
            double a = this->femur_l;
            double b = this->tibia_l;
                    
            RCLCPP_INFO(this->get_logger(), "A: %f", a);
            RCLCPP_INFO(this->get_logger(), "B: %f", b);
            
            double c = hypot(_z - 0, _y);
            
            RCLCPP_INFO(this->get_logger(), "C: %f", c);

            float alpha = atan2(_y, _z) * 180/3.14;
            RCLCPP_INFO(this->get_logger(), "Alpha: %f", alpha);

            float beta = (acos(( ( a * a ) +( c * c ) - ( b * b )) / 
                                ( 2 * a * c )))
                                * 180/3.14;

            if (std::isnan(beta)) {
                beta = 90;
            }

            RCLCPP_INFO(this->get_logger(), "Beta: %f", beta);

            float gamma = acos(( ( a * a ) + ( b * b ) - ( c * c )) / 
                                (2 * a * b ) )* 180/3.14;

            if (std::isnan(gamma)) {
            gamma = 90;
            }
            RCLCPP_INFO(this->get_logger(), "Gamma: %f", gamma);

            float delta = (atan2(-_x, _y) * 180/3.14);
            RCLCPP_INFO(this->get_logger(), "Delta: %f", delta);

            angles.coxa = abs(90 - delta);
            angles.femur = abs(alpha + beta);
            angles.tibia = abs(180 - gamma);
            this->leg->publish(angles);

        }

    rclcpp::TimerBase::SharedPtr timer;
    int counter;
    float x, y, z;
    int coxa_l = 50;
    int femur_l = 75;
    int tibia_l = 110.71389;
    Point3d result;
    rclcpp::Publisher<hexapod_interfaces::msg::LegActuators>::SharedPtr leg;
    rclcpp::Subscription<hexapod_interfaces::msg::Coordinates>::SharedPtr coords;
};


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = make_shared<control_leg>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}