#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"

using namespace std;
using namespace std::placeholders;

class generate_waypoints : public rclcpp::Node
{
    public:
        generate_waypoints() : Node("waypoints"){

            // Time between each waypoint
            time_wait = 3000;

            // Publishes target coordinates
            coords1 = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords1", 10);
            coords2 = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords2", 10);
            coords3 = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords3", 10);
            coords4 = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords4", 10);
            coords5 = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords5", 10);
            coords6 = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords6", 10);

            // Calls the waypoint generator every 1 second
            timer = this->create_wall_timer(chrono::milliseconds(this->time_wait), bind(&generate_waypoints::call, this));
        }

    private:

        void call(){
            auto node1 = hexapod_interfaces::msg::Coordinates();
            auto node2 = hexapod_interfaces::msg::Coordinates();

            // Select the current waypoint
            node1.x = this->waypoints[this->i][0];
            node1.y = this->waypoints[this->i][1];
            node1.z = this->waypoints[this->i][2];

            node2.x = this->waypoints[this->j][0];
            node2.y = this->waypoints[this->j][1];
            node2.z = this->waypoints[this->j][2];

            // Move to the next waypoint
            this->j++;
            this->i++;

            // Restart after the third waypoint
            if(i > 3){
                i = 0;
            }
            if(j > 3){
                j = 0;
            }

            this->coords1->publish(node1);
            this->coords3->publish(node1);
            this->coords5->publish(node1);

            this->coords2->publish(node2);
            this->coords4->publish(node2);
            this->coords6->publish(node2);

            RCLCPP_INFO(this->get_logger(), "I: %d", i);
            RCLCPP_INFO(this->get_logger(), "X: %f", node1.x);
            RCLCPP_INFO(this->get_logger(), "Y: %f", node1.y);
            RCLCPP_INFO(this->get_logger(), "Z: %f", node1.z);

            RCLCPP_INFO(this->get_logger(), "J: %d", j);
            RCLCPP_INFO(this->get_logger(), "X: %f", node2.x);
            RCLCPP_INFO(this->get_logger(), "Y: %f", node2.y);
            RCLCPP_INFO(this->get_logger(), "Z: %f", node2.z);
        }

        int time_wait;

        // Three waypoints represented as X, Y and Z coordinate arrays
        float waypoints[4][3] = {
            {25.0f, 50.0f, 112.0f},
            {0.0f, 50.0f, 50.0f},
            {-25.0f, 50.0f, 50.0f},
            {-0.0f, 50.0f, 112.0f}
        };

        int i = 0;
        int j = 2;

        rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords1;
        rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords2;
        rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords3;
        rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords4;
        rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords5;
        rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords6;
        rclcpp::TimerBase::SharedPtr timer;
};


int main(int argc, char **argv){

    rclcpp::init(argc, argv);

    auto node = make_shared<generate_waypoints>();

    rclcpp::spin(node);

    rclcpp::shutdown();
}