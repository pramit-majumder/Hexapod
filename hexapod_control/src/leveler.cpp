#include <algorithm>
#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"

using Coordinates = hexapod_interfaces::msg::Coordinates;
using namespace std::chrono_literals;

class Leveler : public rclcpp::Node
{
public:
  Leveler() : Node("leveler")
  {
    declare_parameter<double>("x", 0.0);
    declare_parameter<double>("y", 0.0);
    declare_parameter<double>("z", 0.0);

    for (int i = 1; i <= 6; ++i) {
      pubs_.push_back(
        create_publisher<Coordinates>("coords" + std::to_string(i), 10));
    }
  }

  void publish_once(std::chrono::seconds timeout = 5s)
  {
    // Wait until every publisher has at least one matched subscriber
    const auto deadline = std::chrono::steady_clock::now() + timeout;
    auto all_matched = [this]() {
      return std::all_of(pubs_.begin(), pubs_.end(),
        [](const auto & p) { return p->get_subscription_count() > 0; });
    };
    while (rclcpp::ok() && !all_matched() &&
           std::chrono::steady_clock::now() < deadline) {
      rclcpp::sleep_for(50ms);
    }

    if (!all_matched()) {
      for (const auto & p : pubs_) {
        if (p->get_subscription_count() == 0) {
          RCLCPP_WARN(get_logger(), "No subscriber on %s", p->get_topic_name());
        }
      }
    }

    Coordinates msg;
    msg.x = get_parameter("x").as_double();
    msg.y = get_parameter("y").as_double();
    msg.z = get_parameter("z").as_double();

    for (const auto & p : pubs_) {
      p->publish(msg);
    }

    RCLCPP_INFO(get_logger(), "Published: x=%.2f, y=%.2f, z=%.2f",
                msg.x, msg.y, msg.z);
  }

private:
  std::vector<rclcpp::Publisher<Coordinates>::SharedPtr> pubs_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Leveler>();

  node->publish_once();
  rclcpp::sleep_for(200ms);  // give reliable delivery a moment before teardown

  rclcpp::shutdown();
  return 0;
}