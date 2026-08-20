// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hexapod_interfaces:srv/InverseKinematics.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__BUILDER_HPP_
#define HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hexapod_interfaces/srv/detail/inverse_kinematics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hexapod_interfaces
{

namespace srv
{

namespace builder
{

class Init_InverseKinematics_Request_tibia_length
{
public:
  explicit Init_InverseKinematics_Request_tibia_length(::hexapod_interfaces::srv::InverseKinematics_Request & msg)
  : msg_(msg)
  {}
  ::hexapod_interfaces::srv::InverseKinematics_Request tibia_length(::hexapod_interfaces::srv::InverseKinematics_Request::_tibia_length_type arg)
  {
    msg_.tibia_length = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Request msg_;
};

class Init_InverseKinematics_Request_femur_length
{
public:
  explicit Init_InverseKinematics_Request_femur_length(::hexapod_interfaces::srv::InverseKinematics_Request & msg)
  : msg_(msg)
  {}
  Init_InverseKinematics_Request_tibia_length femur_length(::hexapod_interfaces::srv::InverseKinematics_Request::_femur_length_type arg)
  {
    msg_.femur_length = std::move(arg);
    return Init_InverseKinematics_Request_tibia_length(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Request msg_;
};

class Init_InverseKinematics_Request_coxa_length
{
public:
  explicit Init_InverseKinematics_Request_coxa_length(::hexapod_interfaces::srv::InverseKinematics_Request & msg)
  : msg_(msg)
  {}
  Init_InverseKinematics_Request_femur_length coxa_length(::hexapod_interfaces::srv::InverseKinematics_Request::_coxa_length_type arg)
  {
    msg_.coxa_length = std::move(arg);
    return Init_InverseKinematics_Request_femur_length(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Request msg_;
};

class Init_InverseKinematics_Request_z
{
public:
  explicit Init_InverseKinematics_Request_z(::hexapod_interfaces::srv::InverseKinematics_Request & msg)
  : msg_(msg)
  {}
  Init_InverseKinematics_Request_coxa_length z(::hexapod_interfaces::srv::InverseKinematics_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_InverseKinematics_Request_coxa_length(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Request msg_;
};

class Init_InverseKinematics_Request_y
{
public:
  explicit Init_InverseKinematics_Request_y(::hexapod_interfaces::srv::InverseKinematics_Request & msg)
  : msg_(msg)
  {}
  Init_InverseKinematics_Request_z y(::hexapod_interfaces::srv::InverseKinematics_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_InverseKinematics_Request_z(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Request msg_;
};

class Init_InverseKinematics_Request_x
{
public:
  Init_InverseKinematics_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InverseKinematics_Request_y x(::hexapod_interfaces::srv::InverseKinematics_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_InverseKinematics_Request_y(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_interfaces::srv::InverseKinematics_Request>()
{
  return hexapod_interfaces::srv::builder::Init_InverseKinematics_Request_x();
}

}  // namespace hexapod_interfaces


namespace hexapod_interfaces
{

namespace srv
{

namespace builder
{

class Init_InverseKinematics_Response_tibia
{
public:
  explicit Init_InverseKinematics_Response_tibia(::hexapod_interfaces::srv::InverseKinematics_Response & msg)
  : msg_(msg)
  {}
  ::hexapod_interfaces::srv::InverseKinematics_Response tibia(::hexapod_interfaces::srv::InverseKinematics_Response::_tibia_type arg)
  {
    msg_.tibia = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Response msg_;
};

class Init_InverseKinematics_Response_femur
{
public:
  explicit Init_InverseKinematics_Response_femur(::hexapod_interfaces::srv::InverseKinematics_Response & msg)
  : msg_(msg)
  {}
  Init_InverseKinematics_Response_tibia femur(::hexapod_interfaces::srv::InverseKinematics_Response::_femur_type arg)
  {
    msg_.femur = std::move(arg);
    return Init_InverseKinematics_Response_tibia(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Response msg_;
};

class Init_InverseKinematics_Response_coxa
{
public:
  Init_InverseKinematics_Response_coxa()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InverseKinematics_Response_femur coxa(::hexapod_interfaces::srv::InverseKinematics_Response::_coxa_type arg)
  {
    msg_.coxa = std::move(arg);
    return Init_InverseKinematics_Response_femur(msg_);
  }

private:
  ::hexapod_interfaces::srv::InverseKinematics_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_interfaces::srv::InverseKinematics_Response>()
{
  return hexapod_interfaces::srv::builder::Init_InverseKinematics_Response_coxa();
}

}  // namespace hexapod_interfaces

#endif  // HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__BUILDER_HPP_
