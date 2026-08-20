// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hexapod_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__BUILDER_HPP_
#define HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hexapod_interfaces/msg/detail/coordinates__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hexapod_interfaces
{

namespace msg
{

namespace builder
{

class Init_Coordinates_z
{
public:
  explicit Init_Coordinates_z(::hexapod_interfaces::msg::Coordinates & msg)
  : msg_(msg)
  {}
  ::hexapod_interfaces::msg::Coordinates z(::hexapod_interfaces::msg::Coordinates::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_interfaces::msg::Coordinates msg_;
};

class Init_Coordinates_y
{
public:
  explicit Init_Coordinates_y(::hexapod_interfaces::msg::Coordinates & msg)
  : msg_(msg)
  {}
  Init_Coordinates_z y(::hexapod_interfaces::msg::Coordinates::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Coordinates_z(msg_);
  }

private:
  ::hexapod_interfaces::msg::Coordinates msg_;
};

class Init_Coordinates_x
{
public:
  Init_Coordinates_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coordinates_y x(::hexapod_interfaces::msg::Coordinates::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Coordinates_y(msg_);
  }

private:
  ::hexapod_interfaces::msg::Coordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_interfaces::msg::Coordinates>()
{
  return hexapod_interfaces::msg::builder::Init_Coordinates_x();
}

}  // namespace hexapod_interfaces

#endif  // HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__BUILDER_HPP_
