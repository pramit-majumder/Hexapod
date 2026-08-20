// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hexapod_interfaces:msg/LegActuators.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__STRUCT_H_
#define HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LegActuators in the package hexapod_interfaces.
typedef struct hexapod_interfaces__msg__LegActuators
{
  int64_t coxa;
  int64_t femur;
  int64_t tibia;
} hexapod_interfaces__msg__LegActuators;

// Struct for a sequence of hexapod_interfaces__msg__LegActuators.
typedef struct hexapod_interfaces__msg__LegActuators__Sequence
{
  hexapod_interfaces__msg__LegActuators * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hexapod_interfaces__msg__LegActuators__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__STRUCT_H_
