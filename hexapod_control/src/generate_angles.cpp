#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/leg_actuators.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"
#include <cmath>

using namespace std;

class GenerateAngles : public rclcpp::Node
{
public:
    GenerateAngles() : Node("generate_angles"){
        RCLCPP_INFO(this->get_logger(), "Booting UP");
        leg = this->create_publisher<hexapod_interfaces::msg::LegActuators>("leg", 10);
        coords = this->create_subscription<hexapod_interfaces::msg::Coordinates>("coords", 10, std::bind(&GenerateAngles::solver, this, std::placeholders::_1));
    }

private:    
    void solver(const hexapod_interfaces::msg::Coordinates::SharedPtr msg){
        this->x = msg->x;
        this->y = msg->y;
        this->z = msg->z;

        auto angles = hexapod_interfaces::msg::LegActuators();  
        
        double a = this->femur_l;
        double b = this->tibia_l;
                
        RCLCPP_INFO(this->get_logger(), "A: %f", a);
        RCLCPP_INFO(this->get_logger(), "B: %f", b);
        
        double c = hypot(this->z - 0, this->y);
        
        RCLCPP_INFO(this->get_logger(), "C: %f", c);

        float alpha = atan2(y, z) * 180/3.14;
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

        float delta = (atan2(-x, y) * 180/3.14);
        RCLCPP_INFO(this->get_logger(), "Delta: %f", delta);

        angles.coxa = abs(90 - delta);
        angles.femur = abs(alpha + beta);
        angles.tibia = abs(180 - gamma);
        this->leg->publish(angles);

    }
    rclcpp::TimerBase::SharedPtr timer;
    int x = 0;
    int y = 0;
    int z = 0;
    int coxa_l = 50;
    int femur_l = 75;
    int tibia_l = 150;
    rclcpp::Publisher<hexapod_interfaces::msg::LegActuators>::SharedPtr leg;
    rclcpp::Subscription<hexapod_interfaces::msg::Coordinates>::SharedPtr coords;
};


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = make_shared<GenerateAngles>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}