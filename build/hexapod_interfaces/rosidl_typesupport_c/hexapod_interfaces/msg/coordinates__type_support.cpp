// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from hexapod_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "hexapod_interfaces/msg/detail/coordinates__struct.h"
#include "hexapod_interfaces/msg/detail/coordinates__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace hexapod_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _Coordinates_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Coordinates_type_support_ids_t;

static const _Coordinates_type_support_ids_t _Coordinates_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Coordinates_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Coordinates_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Coordinates_type_support_symbol_names_t _Coordinates_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hexapod_interfaces, msg, Coordinates)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hexapod_interfaces, msg, Coordinates)),
  }
};

typedef struct _Coordinates_type_support_data_t
{
  void * data[2];
} _Coordinates_type_support_data_t;

static _Coordinates_type_support_data_t _Coordinates_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Coordinates_message_typesupport_map = {
  2,
  "hexapod_interfaces",
  &_Coordinates_message_typesupport_ids.typesupport_identifier[0],
  &_Coordinates_message_typesupport_symbol_names.symbol_name[0],
  &_Coordinates_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Coordinates_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Coordinates_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace hexapod_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, hexapod_interfaces, msg, Coordinates)() {
  return &::hexapod_interfaces::msg::rosidl_typesupport_c::Coordinates_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
