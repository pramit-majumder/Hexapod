// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hexapod_interfaces:msg/LegActuators.idl
// generated code does not contain a copyright notice
#include "hexapod_interfaces/msg/detail/leg_actuators__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hexapod_interfaces/msg/detail/leg_actuators__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace hexapod_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_interfaces
cdr_serialize(
  const hexapod_interfaces::msg::LegActuators & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: coxa
  cdr << ros_message.coxa;
  // Member: femur
  cdr << ros_message.femur;
  // Member: tibia
  cdr << ros_message.tibia;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hexapod_interfaces::msg::LegActuators & ros_message)
{
  // Member: coxa
  cdr >> ros_message.coxa;

  // Member: femur
  cdr >> ros_message.femur;

  // Member: tibia
  cdr >> ros_message.tibia;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_interfaces
get_serialized_size(
  const hexapod_interfaces::msg::LegActuators & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: coxa
  {
    size_t item_size = sizeof(ros_message.coxa);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: femur
  {
    size_t item_size = sizeof(ros_message.femur);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tibia
  {
    size_t item_size = sizeof(ros_message.tibia);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_interfaces
max_serialized_size_LegActuators(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: coxa
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: femur
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tibia
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = hexapod_interfaces::msg::LegActuators;
    is_plain =
      (
      offsetof(DataType, tibia) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _LegActuators__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hexapod_interfaces::msg::LegActuators *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LegActuators__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hexapod_interfaces::msg::LegActuators *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LegActuators__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hexapod_interfaces::msg::LegActuators *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LegActuators__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LegActuators(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LegActuators__callbacks = {
  "hexapod_interfaces::msg",
  "LegActuators",
  _LegActuators__cdr_serialize,
  _LegActuators__cdr_deserialize,
  _LegActuators__get_serialized_size,
  _LegActuators__max_serialized_size
};

static rosidl_message_type_support_t _LegActuators__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LegActuators__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hexapod_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hexapod_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<hexapod_interfaces::msg::LegActuators>()
{
  return &hexapod_interfaces::msg::typesupport_fastrtps_cpp::_LegActuators__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hexapod_interfaces, msg, LegActuators)() {
  return &hexapod_interfaces::msg::typesupport_fastrtps_cpp::_LegActuators__handle;
}

#ifdef __cplusplus
}
#endif
