// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hexapod_interfaces:msg/LegActuators.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__BUILDER_HPP_
#define HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hexapod_interfaces/msg/detail/leg_actuators__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hexapod_interfaces
{

namespace msg
{

namespace builder
{

class Init_LegActuators_tibia
{
public:
  explicit Init_LegActuators_tibia(::hexapod_interfaces::msg::LegActuators & msg)
  : msg_(msg)
  {}
  ::hexapod_interfaces::msg::LegActuators tibia(::hexapod_interfaces::msg::LegActuators::_tibia_type arg)
  {
    msg_.tibia = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_interfaces::msg::LegActuators msg_;
};

class Init_LegActuators_femur
{
public:
  explicit Init_LegActuators_femur(::hexapod_interfaces::msg::LegActuators & msg)
  : msg_(msg)
  {}
  Init_LegActuators_tibia femur(::hexapod_interfaces::msg::LegActuators::_femur_type arg)
  {
    msg_.femur = std::move(arg);
    return Init_LegActuators_tibia(msg_);
  }

private:
  ::hexapod_interfaces::msg::LegActuators msg_;
};

class Init_LegActuators_coxa
{
public:
  Init_LegActuators_coxa()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LegActuators_femur coxa(::hexapod_interfaces::msg::LegActuators::_coxa_type arg)
  {
    msg_.coxa = std::move(arg);
    return Init_LegActuators_femur(msg_);
  }

private:
  ::hexapod_interfaces::msg::LegActuators msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_interfaces::msg::LegActuators>()
{
  return hexapod_interfaces::msg::builder::Init_LegActuators_coxa();
}

}  // namespace hexapod_interfaces

#endif  // HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__BUILDER_HPP_
