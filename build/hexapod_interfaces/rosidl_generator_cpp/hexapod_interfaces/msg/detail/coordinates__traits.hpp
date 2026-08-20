// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hexapod_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__TRAITS_HPP_
#define HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hexapod_interfaces/msg/detail/coordinates__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hexapod_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Coordinates & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Coordinates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Coordinates & msg, bool use_flow_style = false)
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
  const hexapod_interfaces::msg::Coordinates & msg,
  std::ostream & out, size_t indentation = 0)
{
  hexapod_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hexapod_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const hexapod_interfaces::msg::Coordinates & msg)
{
  return hexapod_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hexapod_interfaces::msg::Coordinates>()
{
  return "hexapod_interfaces::msg::Coordinates";
}

template<>
inline const char * name<hexapod_interfaces::msg::Coordinates>()
{
  return "hexapod_interfaces/msg/Coordinates";
}

template<>
struct has_fixed_size<hexapod_interfaces::msg::Coordinates>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hexapod_interfaces::msg::Coordinates>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hexapod_interfaces::msg::Coordinates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__TRAITS_HPP_
