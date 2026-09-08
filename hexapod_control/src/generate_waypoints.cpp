#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"

using namespace std;
using namespace std::placeholders;
class generate_waypoints : public rclcpp::Node
{
    public:
        generate_waypoints() : Node("waypoints"){
            time_wait = 1000;
            coords = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords", 10);
            timer = this->create_wall_timer(chrono::milliseconds(this->time_wait), bind(&generate_waypoints::call, this));
        }

    private:
        void call(){
            auto node = hexapod_interfaces::msg::Coordinates();
            node.x = this->waypoints[0][this->i];
            node.y = this->waypoints[1][this->i];
            node.z = this->waypoints[2][this->i];
            this->i++;
            if(i > 2){
                i = 0;
            }
            this->coords->publish(node);
            RCLCPP_INFO(this->get_logger(), "X: %f", node.x);
            RCLCPP_INFO(this->get_logger(), "Y: %f", node.y);
            RCLCPP_INFO(this->get_logger(), "Z: %f", node.z);
        }
        int time_wait;
        float waypoints[3][3] = {
            {90.0f, 0.0f, -90.0f},
            {90.0f, 90.0f, 90.0f},
            {60.0f, -30.0f, 60.0f}
        };
        int i = 0;
        rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords;
        rclcpp::TimerBase::SharedPtr timer;

};


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = make_shared<generate_waypoints>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}