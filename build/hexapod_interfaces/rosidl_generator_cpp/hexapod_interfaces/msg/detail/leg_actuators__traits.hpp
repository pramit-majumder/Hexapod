// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hexapod_interfaces:msg/LegActuators.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__TRAITS_HPP_
#define HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hexapod_interfaces/msg/detail/leg_actuators__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hexapod_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LegActuators & msg,
  std::ostream & out)
{
  out << "{";
  // member: coxa
  {
    out << "coxa: ";
    rosidl_generator_traits::value_to_yaml(msg.coxa, out);
    out << ", ";
  }

  // member: femur
  {
    out << "femur: ";
    rosidl_generator_traits::value_to_yaml(msg.femur, out);
    out << ", ";
  }

  // member: tibia
  {
    out << "tibia: ";
    rosidl_generator_traits::value_to_yaml(msg.tibia, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LegActuators & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: coxa
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coxa: ";
    rosidl_generator_traits::value_to_yaml(msg.coxa, out);
    out << "\n";
  }

  // member: femur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "femur: ";
    rosidl_generator_traits::value_to_yaml(msg.femur, out);
    out << "\n";
  }

  // member: tibia
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tibia: ";
    rosidl_generator_traits::value_to_yaml(msg.tibia, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LegActuators & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace hexapod_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use hexapod_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hexapod_interfaces::msg::LegActuators & msg,
  std::ostream & out, size_t indentation = 0)
{
  hexapod_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hexapod_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const hexapod_interfaces::msg::LegActuators & msg)
{
  return hexapod_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hexapod_interfaces::msg::LegActuators>()
{
  return "hexapod_interfaces::msg::LegActuators";
}

template<>
inline const char * name<hexapod_interfaces::msg::LegActuators>()
{
  return "hexapod_interfaces/msg/LegActuators";
}

template<>
struct has_fixed_size<hexapod_interfaces::msg::LegActuators>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hexapod_interfaces::msg::LegActuators>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hexapod_interfaces::msg::LegActuators>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__TRAITS_HPP_
