// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hexapod_interfaces:srv/InverseKinematics.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__STRUCT_H_
#define HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/InverseKinematics in the package hexapod_interfaces.
typedef struct hexapod_interfaces__srv__InverseKinematics_Request
{
  int64_t x;
  int64_t y;
  int64_t z;
  int64_t coxa_length;
  int64_t femur_length;
  int64_t tibia_length;
} hexapod_interfaces__srv__InverseKinematics_Request;

// Struct for a sequence of hexapod_interfaces__srv__InverseKinematics_Request.
typedef struct hexapod_interfaces__srv__InverseKinematics_Request__Sequence
{
  hexapod_interfaces__srv__InverseKinematics_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hexapod_interfaces__srv__InverseKinematics_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/InverseKinematics in the package hexapod_interfaces.
typedef struct hexapod_interfaces__srv__InverseKinematics_Response
{
  float coxa;
  float femur;
  float tibia;
} hexapod_interfaces__srv__InverseKinematics_Response;

// Struct for a sequence of hexapod_interfaces__srv__InverseKinematics_Response.
typedef struct hexapod_interfaces__srv__InverseKinematics_Response__Sequence
{
  hexapod_interfaces__srv__InverseKinematics_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hexapod_interfaces__srv__InverseKinematics_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__STRUCT_H_
