// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hexapod_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice
#include "hexapod_interfaces/msg/detail/coordinates__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hexapod_interfaces__msg__Coordinates__init(hexapod_interfaces__msg__Coordinates * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
hexapod_interfaces__msg__Coordinates__fini(hexapod_interfaces__msg__Coordinates * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

bool
hexapod_interfaces__msg__Coordinates__are_equal(const hexapod_interfaces__msg__Coordinates * lhs, const hexapod_interfaces__msg__Coordinates * rhs)
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
  return true;
}

bool
hexapod_interfaces__msg__Coordinates__copy(
  const hexapod_interfaces__msg__Coordinates * input,
  hexapod_interfaces__msg__Coordinates * output)
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
  return true;
}

hexapod_interfaces__msg__Coordinates *
hexapod_interfaces__msg__Coordinates__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__msg__Coordinates * msg = (hexapod_interfaces__msg__Coordinates *)allocator.allocate(sizeof(hexapod_interfaces__msg__Coordinates), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hexapod_interfaces__msg__Coordinates));
  bool success = hexapod_interfaces__msg__Coordinates__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hexapod_interfaces__msg__Coordinates__destroy(hexapod_interfaces__msg__Coordinates * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hexapod_interfaces__msg__Coordinates__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hexapod_interfaces__msg__Coordinates__Sequence__init(hexapod_interfaces__msg__Coordinates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__msg__Coordinates * data = NULL;

  if (size) {
    data = (hexapod_interfaces__msg__Coordinates *)allocator.zero_allocate(size, sizeof(hexapod_interfaces__msg__Coordinates), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hexapod_interfaces__msg__Coordinates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hexapod_interfaces__msg__Coordinates__fini(&data[i - 1]);
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
hexapod_interfaces__msg__Coordinates__Sequence__fini(hexapod_interfaces__msg__Coordinates__Sequence * array)
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
      hexapod_interfaces__msg__Coordinates__fini(&array->data[i]);
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

hexapod_interfaces__msg__Coordinates__Sequence *
hexapod_interfaces__msg__Coordinates__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_interfaces__msg__Coordinates__Sequence * array = (hexapod_interfaces__msg__Coordinates__Sequence *)allocator.allocate(sizeof(hexapod_interfaces__msg__Coordinates__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hexapod_interfaces__msg__Coordinates__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hexapod_interfaces__msg__Coordinates__Sequence__destroy(hexapod_interfaces__msg__Coordinates__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hexapod_interfaces__msg__Coordinates__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hexapod_interfaces__msg__Coordinates__Sequence__are_equal(const hexapod_interfaces__msg__Coordinates__Sequence * lhs, const hexapod_interfaces__msg__Coordinates__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hexapod_interfaces__msg__Coordinates__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hexapod_interfaces__msg__Coordinates__Sequence__copy(
  const hexapod_interfaces__msg__Coordinates__Sequence * input,
  hexapod_interfaces__msg__Coordinates__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hexapod_interfaces__msg__Coordinates);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hexapod_interfaces__msg__Coordinates * data =
      (hexapod_interfaces__msg__Coordinates *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hexapod_interfaces__msg__Coordinates__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hexapod_interfaces__msg__Coordinates__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hexapod_interfaces__msg__Coordinates__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
