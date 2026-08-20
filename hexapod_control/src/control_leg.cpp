#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"

using namespace std;

class control_leg : public rclcpp::Node
{
public:
    control_leg() : Node("leg_control"), counter(1){
        RCLCPP_INFO(this->get_logger(), "Booting UP");
        coords = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords", 10);
        x = 0;
        y = 150;
        z = 50;
        timer = this->create_wall_timer(chrono::seconds(1), bind(&control_leg::callback, this));
    }
private:
    void callback(){
        
        this->y += 10 * this->f;
        RCLCPP_INFO(this->get_logger(), "Random: %d", 10 * this->f);

        if(this->y > 225){
            this->f = -1;
        }
        if( this->y < 150){
            this->f = 1;
        }
        auto node = hexapod_interfaces::msg::Coordinates();
        node.x = this->x;
        node.y = this->y;
        node.z = this->z;
        RCLCPP_INFO(this->get_logger(), "X: %d", this->x);
        RCLCPP_INFO(this->get_logger(), "Y: %d", this->y);
        RCLCPP_INFO(this->get_logger(), "Z: %d", this->z);
        this->coords->publish(node);

    }
    rclcpp::TimerBase::SharedPtr timer;
    int counter;
    int x, y, z;
    int f = 1;
    rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords;
};


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = make_shared<control_leg>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}