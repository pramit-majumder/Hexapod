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
            timer = this->create_wall_timer(std::chrono::milliseconds(200), std::bind(&control_leg::placeholder_method, this));
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
                Point3d current = lerp(start, end, (float)time/50.0f);
                auto angles = hexapod_interfaces::msg::LegActuators();
                angles.coxa = current.x;
                angles.femur = current.y;
                angles.tibia = current.z;
                this->leg->publish(angles);
                if(time == 50){
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

        // void transport(const hexapod_interfaces::msg::Coordinates::SharedPtr msg){

        //     Point3d start = {this->coxa, this->femur, this->tibia};
        //     Point3d end = solver_grad(msg->x, msg->y, msg->z);
        //     RCLCPP_INFO(this->get_logger(), "Interpolating from (%f, %f, %f) to (%f, %f, %f)", start.x, start.y, start.z, end.x, end.y, end.z);
        //     auto angles = hexapod_interfaces::msg::LegActuators();
        //     for(int i = 0; i <= 50; i++){

        //         float s = (float)i/50.0f;
        //         this->result = lerp(start, end, s);
                
        //         angles.coxa = result.x;
        //         angles.femur = result.y;
        //         angles.tibia = result.z;

        //         this->leg->publish(angles);  
        //         std::this_thread::sleep_for( std::chrono::milliseconds(100)); 
        //     }
        // }

        // Point3d solver_grad(float _x, float _y, float _z){  
            
        //     double a = this->femur_l;
        //     double b = this->tibia_l;
        //     RCLCPP_INFO(this->get_logger(), "X: %f", _x);
        //     RCLCPP_INFO(this->get_logger(), "Y: %f", _y);
        //     RCLCPP_INFO(this->get_logger(), "Z: %f", _z);
        //     RCLCPP_INFO(this->get_logger(), "A: %f", a);
        //     RCLCPP_INFO(this->get_logger(), "B: %f", b);
            
        //     double c = hypot(_z - 0, _y);
            
        //     RCLCPP_INFO(this->get_logger(), "C: %f", c);

        //     float alpha = atan2(-_z, _y) * 180.0f/M_PI;
        //     RCLCPP_INFO(this->get_logger(), "Alpha: %f", alpha);

        //     float beta = (acos(( ( a * a ) +( c * c ) - ( b * b )) / 
        //                         ( 2 * a * c )))
        //                         * 180.0f/M_PI;

        //     if (std::isnan(beta)) {
        //         beta = 90.0f;
        //     }

        //     RCLCPP_INFO(this->get_logger(), "Beta: %f", beta);

        //     float gamma = acos(( ( a * a ) + ( b * b ) - ( c * c )) / 
        //                         (2 * a * b ) )* 180.0f/M_PI;

        //     if (std::isnan(gamma)) {
        //         gamma = 90.0f;
        //     }
        //     RCLCPP_INFO(this->get_logger(), "Gamma: %f", gamma);

        //     float delta = (_x == 0 ? 90.0f : (atan2(-_x, _y) * 180.0f/M_PI));
        //     RCLCPP_INFO(this->get_logger(), "Delta: %f", delta);

        //     Point3d angles;
        //     angles.x = std::clamp(std::abs(delta), 0.0f, 180.0f);
        //     angles.y = std::clamp(std::abs(alpha + beta + 90), 0.0f, 180.0f);
        //     angles.z = std::clamp(std::abs(gamma), 0.0f, 180.0f);

        //     this->coxa = angles.x;
        //     this->femur = angles.y;
        //     this->tibia = angles.z;
        //     RCLCPP_INFO(this->get_logger(), "COXA: %d", angles.x);
        //     RCLCPP_INFO(this->get_logger(), "FEMUR: %d", angles.y);
        //     RCLCPP_INFO(this->get_logger(), "TIBIA: %d", angles.z);


        //     return angles;
        // }

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

            float delta = (msg->x == 0 ? 90.0f : (atan2(-msg->x, msg->y) * 180.0f/M_PI));
                
            this->coxa = std::clamp(std::abs(delta), 0.0f, 180.0f);
            this->femur = std::clamp(std::abs(alpha + beta + 90), 0.0f, 180.0f);
            this->tibia = std::clamp(std::abs(gamma), 0.0f, 180.0f);

            this->end = {this->coxa, this->femur, this->tibia};
            target_reached = false;
            RCLCPP_INFO(this->get_logger(), "Started Interpolating");
            time = 0;
        }

    rclcpp::TimerBase::SharedPtr timer;
    int counter;
    float x, y, z;
    float coxa, femur, tibia;
    int coxa_l = 50;
    int femur_l = 75;
    int tibia_l = 112.256;
    bool target_reached = true;
    int time = 0;
    Point3d start;
    Point3d end;
    rclcpp::Publisher<hexapod_interfaces::msg::LegActuators>::SharedPtr leg;
    rclcpp::Subscription<hexapod_interfaces::msg::Coordinates>::SharedPtr coords;
    
};


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = make_shared<control_leg>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}