#include <algorithm>
#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"

using Coordinates = hexapod_interfaces::msg::Coordinates;
using namespace std::chrono_literals;

class DefaultState : public rclcpp::Node
{
public:
  DefaultState() : Node("default_state")
  {
    for (int i = 1; i <= 6; ++i) {
      pubs_.push_back(
        create_publisher<Coordinates>("coords" + std::to_string(i), 10));
    }
  }

  void publish_once(std::chrono::seconds timeout = 5s)
  {
    const auto deadline = std::chrono::steady_clock::now() + timeout;
    auto all_matched = [this]() {
      return std::all_of(pubs_.begin(), pubs_.end(),
        [](const auto & p) { return p->get_subscription_count() > 0; });
    };
    while (rclcpp::ok() && !all_matched() &&
           std::chrono::steady_clock::now() < deadline) {
      rclcpp::sleep_for(50ms);
    }

    for (const auto & p : pubs_) {
      if (p->get_subscription_count() == 0) {
        RCLCPP_WARN(get_logger(), "No subscriber on %s", p->get_topic_name());
      }
    }

    Coordinates msg;
    msg.x = 0.0;
    msg.y = 60.0;
    msg.z = 75.0;

    for (const auto & p : pubs_) {
      p->publish(msg);
    }
    RCLCPP_INFO(get_logger(), "Published default state: x=%.1f y=%.1f z=%.1f",
                msg.x, msg.y, msg.z);
  }

private:
  std::vector<rclcpp::Publisher<Coordinates>::SharedPtr> pubs_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<DefaultState>();
  node->publish_once();
  rclcpp::sleep_for(200ms);  // heuristic: let reliable delivery finish
  rclcpp::shutdown();
  return 0;
}