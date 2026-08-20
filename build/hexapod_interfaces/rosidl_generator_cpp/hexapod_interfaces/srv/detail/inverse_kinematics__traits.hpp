// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hexapod_interfaces:srv/InverseKinematics.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__TRAITS_HPP_
#define HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hexapod_interfaces/srv/detail/inverse_kinematics__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hexapod_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const InverseKinematics_Request & msg,
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
    out << ", ";
  }

  // member: coxa_length
  {
    out << "coxa_length: ";
    rosidl_generator_traits::value_to_yaml(msg.coxa_length, out);
    out << ", ";
  }

  // member: femur_length
  {
    out << "femur_length: ";
    rosidl_generator_traits::value_to_yaml(msg.femur_length, out);
    out << ", ";
  }

  // member: tibia_length
  {
    out << "tibia_length: ";
    rosidl_generator_traits::value_to_yaml(msg.tibia_length, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const InverseKinematics_Request & msg,
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

  // member: coxa_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coxa_length: ";
    rosidl_generator_traits::value_to_yaml(msg.coxa_length, out);
    out << "\n";
  }

  // member: femur_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "femur_length: ";
    rosidl_generator_traits::value_to_yaml(msg.femur_length, out);
    out << "\n";
  }

  // member: tibia_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tibia_length: ";
    rosidl_generator_traits::value_to_yaml(msg.tibia_length, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const InverseKinematics_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hexapod_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use hexapod_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hexapod_interfaces::srv::InverseKinematics_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hexapod_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hexapod_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const hexapod_interfaces::srv::InverseKinematics_Request & msg)
{
  return hexapod_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hexapod_interfaces::srv::InverseKinematics_Request>()
{
  return "hexapod_interfaces::srv::InverseKinematics_Request";
}

template<>
inline const char * name<hexapod_interfaces::srv::InverseKinematics_Request>()
{
  return "hexapod_interfaces/srv/InverseKinematics_Request";
}

template<>
struct has_fixed_size<hexapod_interfaces::srv::InverseKinematics_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hexapod_interfaces::srv::InverseKinematics_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hexapod_interfaces::srv::InverseKinematics_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hexapod_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const InverseKinematics_Response & msg,
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
  const InverseKinematics_Response & msg,
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

inline std::string to_yaml(const InverseKinematics_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hexapod_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use hexapod_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hexapod_interfaces::srv::InverseKinematics_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hexapod_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hexapod_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const hexapod_interfaces::srv::InverseKinematics_Response & msg)
{
  return hexapod_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hexapod_interfaces::srv::InverseKinematics_Response>()
{
  return "hexapod_interfaces::srv::InverseKinematics_Response";
}

template<>
inline const char * name<hexapod_interfaces::srv::InverseKinematics_Response>()
{
  return "hexapod_interfaces/srv/InverseKinematics_Response";
}

template<>
struct has_fixed_size<hexapod_interfaces::srv::InverseKinematics_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hexapod_interfaces::srv::InverseKinematics_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hexapod_interfaces::srv::InverseKinematics_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hexapod_interfaces::srv::InverseKinematics>()
{
  return "hexapod_interfaces::srv::InverseKinematics";
}

template<>
inline const char * name<hexapod_interfaces::srv::InverseKinematics>()
{
  return "hexapod_interfaces/srv/InverseKinematics";
}

template<>
struct has_fixed_size<hexapod_interfaces::srv::InverseKinematics>
  : std::integral_constant<
    bool,
    has_fixed_size<hexapod_interfaces::srv::InverseKinematics_Request>::value &&
    has_fixed_size<hexapod_interfaces::srv::InverseKinematics_Response>::value
  >
{
};

template<>
struct has_bounded_size<hexapod_interfaces::srv::InverseKinematics>
  : std::integral_constant<
    bool,
    has_bounded_size<hexapod_interfaces::srv::InverseKinematics_Request>::value &&
    has_bounded_size<hexapod_interfaces::srv::InverseKinematics_Response>::value
  >
{
};

template<>
struct is_service<hexapod_interfaces::srv::InverseKinematics>
  : std::true_type
{
};

template<>
struct is_service_request<hexapod_interfaces::srv::InverseKinematics_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hexapod_interfaces::srv::InverseKinematics_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__TRAITS_HPP_
