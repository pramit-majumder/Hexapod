// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hexapod_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__STRUCT_HPP_
#define HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hexapod_interfaces__msg__Coordinates __attribute__((deprecated))
#else
# define DEPRECATED__hexapod_interfaces__msg__Coordinates __declspec(deprecated)
#endif

namespace hexapod_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Coordinates_
{
  using Type = Coordinates_<ContainerAllocator>;

  explicit Coordinates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
    }
  }

  explicit Coordinates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hexapod_interfaces::msg::Coordinates_<ContainerAllocator> *;
  using ConstRawPtr =
    const hexapod_interfaces::msg::Coordinates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hexapod_interfaces::msg::Coordinates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hexapod_interfaces::msg::Coordinates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hexapod_interfaces::msg::Coordinates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hexapod_interfaces::msg::Coordinates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hexapod_interfaces::msg::Coordinates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hexapod_interfaces::msg::Coordinates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hexapod_interfaces::msg::Coordinates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hexapod_interfaces::msg::Coordinates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hexapod_interfaces__msg__Coordinates
    std::shared_ptr<hexapod_interfaces::msg::Coordinates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hexapod_interfaces__msg__Coordinates
    std::shared_ptr<hexapod_interfaces::msg::Coordinates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coordinates_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coordinates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coordinates_

// alias to use template instance with default allocator
using Coordinates =
  hexapod_interfaces::msg::Coordinates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hexapod_interfaces

#endif  // HEXAPOD_INTERFACES__MSG__DETAIL__COORDINATES__STRUCT_HPP_
