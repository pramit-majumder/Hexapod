// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hexapod_interfaces:srv/InverseKinematics.idl
// generated code does not contain a copyright notice
#include "hexapod_interfaces/srv/detail/inverse_kinematics__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
hexapod_interfaces__srv__InverseKinematics_Request__init(hexapod_interfaces__srv__InverseKinematics_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // coxa_length
  // femur_length
  // tibia_length
  return true;
}

void
hexapod_interfaces__srv__InverseKinematics_Request__fini(hexapod_interfaces__srv__InverseKinematics_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // coxa_length
  // femur_length
  // tibia_length
}

bool
hexapod_interfaces__srv__InverseKinematics_Request__are_equal(const hexapod_interfaces__srv__InverseKinematics_Request * lhs, const hexapod_interfaces__srv__InverseKinematics_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // coxa_length
  if (lhs->coxa_length != rhs->coxa_length) {
    return false;
  }
  // femur_length
  if (lhs->femur_length != rhs->femur_length) {
    return false;
  }
  // tibia_length
  if (lhs->tibia_length != rhs->tibia_length) {
    return false;
  }
  return true;
}

bool
hexapod_interfaces__srv__InverseKinematics_Request__copy(
  const hexapod_interfaces__srv__InverseKinematics_Request * input,
  hexapod_interfaces__srv__InverseKinematics_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // coxa_length
  output->coxa_length = input->coxa_length;
  // femur_length
  output->femur_length = input->femur_length;
  // tibia_length
  output->tibia_length = input->tibia_length;
  return true;
}

hexapod_interfaces__srv__InverseKinematics_Request *
hexapod_interfaces__srv__InverseKinematics_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__srv__InverseKinematics_Request * msg = (hexapod_interfaces__srv__InverseKinematics_Request *)allocator.allocate(sizeof(hexapod_interfaces__srv__InverseKinematics_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hexapod_interfaces__srv__InverseKinematics_Request));
  bool success = hexapod_interfaces__srv__InverseKinematics_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hexapod_interfaces__srv__InverseKinematics_Request__destroy(hexapod_interfaces__srv__InverseKinematics_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hexapod_interfaces__srv__InverseKinematics_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hexapod_interfaces__srv__InverseKinematics_Request__Sequence__init(hexapod_interfaces__srv__InverseKinematics_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__srv__InverseKinematics_Request * data = NULL;

  if (size) {
    data = (hexapod_interfaces__srv__InverseKinematics_Request *)allocator.zero_allocate(size, sizeof(hexapod_interfaces__srv__InverseKinematics_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hexapod_interfaces__srv__InverseKinematics_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hexapod_interfaces__srv__InverseKinematics_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hexapod_interfaces__srv__InverseKinematics_Request__Sequence__fini(hexapod_interfaces__srv__InverseKinematics_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hexapod_interfaces__srv__InverseKinematics_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hexapod_interfaces__srv__InverseKinematics_Request__Sequence *
hexapod_interfaces__srv__InverseKinematics_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__srv__InverseKinematics_Request__Sequence * array = (hexapod_interfaces__srv__InverseKinematics_Request__Sequence *)allocator.allocate(sizeof(hexapod_interfaces__srv__InverseKinematics_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hexapod_interfaces__srv__InverseKinematics_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hexapod_interfaces__srv__InverseKinematics_Request__Sequence__destroy(hexapod_interfaces__srv__InverseKinematics_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hexapod_interfaces__srv__InverseKinematics_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hexapod_interfaces__srv__InverseKinematics_Request__Sequence__are_equal(const hexapod_interfaces__srv__InverseKinematics_Request__Sequence * lhs, const hexapod_interfaces__srv__InverseKinematics_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hexapod_interfaces__srv__InverseKinematics_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hexapod_interfaces__srv__InverseKinematics_Request__Sequence__copy(
  const hexapod_interfaces__srv__InverseKinematics_Request__Sequence * input,
  hexapod_interfaces__srv__InverseKinematics_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hexapod_interfaces__srv__InverseKinematics_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hexapod_interfaces__srv__InverseKinematics_Request * data =
      (hexapod_interfaces__srv__InverseKinematics_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hexapod_interfaces__srv__InverseKinematics_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hexapod_interfaces__srv__InverseKinematics_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hexapod_interfaces__srv__InverseKinematics_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
hexapod_interfaces__srv__InverseKinematics_Response__init(hexapod_interfaces__srv__InverseKinematics_Response * msg)
{
  if (!msg) {
    return false;
  }
  // coxa
  // femur
  // tibia
  return true;
}

void
hexapod_interfaces__srv__InverseKinematics_Response__fini(hexapod_interfaces__srv__InverseKinematics_Response * msg)
{
  if (!msg) {
    return;
  }
  // coxa
  // femur
  // tibia
}

bool
hexapod_interfaces__srv__InverseKinematics_Response__are_equal(const hexapod_interfaces__srv__InverseKinematics_Response * lhs, const hexapod_interfaces__srv__InverseKinematics_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // coxa
  if (lhs->coxa != rhs->coxa) {
    return false;
  }
  // femur
  if (lhs->femur != rhs->femur) {
    return false;
  }
  // tibia
  if (lhs->tibia != rhs->tibia) {
    return false;
  }
  return true;
}

bool
hexapod_interfaces__srv__InverseKinematics_Response__copy(
  const hexapod_interfaces__srv__InverseKinematics_Response * input,
  hexapod_interfaces__srv__InverseKinematics_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // coxa
  output->coxa = input->coxa;
  // femur
  output->femur = input->femur;
  // tibia
  output->tibia = input->tibia;
  return true;
}

hexapod_interfaces__srv__InverseKinematics_Response *
hexapod_interfaces__srv__InverseKinematics_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__srv__InverseKinematics_Response * msg = (hexapod_interfaces__srv__InverseKinematics_Response *)allocator.allocate(sizeof(hexapod_interfaces__srv__InverseKinematics_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hexapod_interfaces__srv__InverseKinematics_Response));
  bool success = hexapod_interfaces__srv__InverseKinematics_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hexapod_interfaces__srv__InverseKinematics_Response__destroy(hexapod_interfaces__srv__InverseKinematics_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hexapod_interfaces__srv__InverseKinematics_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hexapod_interfaces__srv__InverseKinematics_Response__Sequence__init(hexapod_interfaces__srv__InverseKinematics_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__srv__InverseKinematics_Response * data = NULL;

  if (size) {
    data = (hexapod_interfaces__srv__InverseKinematics_Response *)allocator.zero_allocate(size, sizeof(hexapod_interfaces__srv__InverseKinematics_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hexapod_interfaces__srv__InverseKinematics_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hexapod_interfaces__srv__InverseKinematics_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hexapod_interfaces__srv__InverseKinematics_Response__Sequence__fini(hexapod_interfaces__srv__InverseKinematics_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hexapod_interfaces__srv__InverseKinematics_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hexapod_interfaces__srv__InverseKinematics_Response__Sequence *
hexapod_interfaces__srv__InverseKinematics_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__srv__InverseKinematics_Response__Sequence * array = (hexapod_interfaces__srv__InverseKinematics_Response__Sequence *)allocator.allocate(sizeof(hexapod_interfaces__srv__InverseKinematics_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hexapod_interfaces__srv__InverseKinematics_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hexapod_interfaces__srv__InverseKinematics_Response__Sequence__destroy(hexapod_interfaces__srv__InverseKinematics_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hexapod_interfaces__srv__InverseKinematics_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hexapod_interfaces__srv__InverseKinematics_Response__Sequence__are_equal(const hexapod_interfaces__srv__InverseKinematics_Response__Sequence * lhs, const hexapod_interfaces__srv__InverseKinematics_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hexapod_interfaces__srv__InverseKinematics_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hexapod_interfaces__srv__InverseKinematics_Response__Sequence__copy(
  const hexapod_interfaces__srv__InverseKinematics_Response__Sequence * input,
  hexapod_interfaces__srv__InverseKinematics_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hexapod_interfaces__srv__InverseKinematics_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hexapod_interfaces__srv__InverseKinematics_Response * data =
      (hexapod_interfaces__srv__InverseKinematics_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hexapod_interfaces__srv__InverseKinematics_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hexapod_interfaces__srv__InverseKinematics_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hexapod_interfaces__srv__InverseKinematics_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
