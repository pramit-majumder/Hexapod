// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hexapod_interfaces:msg/LegActuators.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__STRUCT_HPP_
#define HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hexapod_interfaces__msg__LegActuators __attribute__((deprecated))
#else
# define DEPRECATED__hexapod_interfaces__msg__LegActuators __declspec(deprecated)
#endif

namespace hexapod_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LegActuators_
{
  using Type = LegActuators_<ContainerAllocator>;

  explicit LegActuators_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->coxa = 0ll;
      this->femur = 0ll;
      this->tibia = 0ll;
    }
  }

  explicit LegActuators_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->coxa = 0ll;
      this->femur = 0ll;
      this->tibia = 0ll;
    }
  }

  // field types and members
  using _coxa_type =
    int64_t;
  _coxa_type coxa;
  using _femur_type =
    int64_t;
  _femur_type femur;
  using _tibia_type =
    int64_t;
  _tibia_type tibia;

  // setters for named parameter idiom
  Type & set__coxa(
    const int64_t & _arg)
  {
    this->coxa = _arg;
    return *this;
  }
  Type & set__femur(
    const int64_t & _arg)
  {
    this->femur = _arg;
    return *this;
  }
  Type & set__tibia(
    const int64_t & _arg)
  {
    this->tibia = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hexapod_interfaces::msg::LegActuators_<ContainerAllocator> *;
  using ConstRawPtr =
    const hexapod_interfaces::msg::LegActuators_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hexapod_interfaces::msg::LegActuators_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hexapod_interfaces::msg::LegActuators_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hexapod_interfaces::msg::LegActuators_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hexapod_interfaces::msg::LegActuators_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hexapod_interfaces::msg::LegActuators_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hexapod_interfaces::msg::LegActuators_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hexapod_interfaces::msg::LegActuators_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hexapod_interfaces::msg::LegActuators_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hexapod_interfaces__msg__LegActuators
    std::shared_ptr<hexapod_interfaces::msg::LegActuators_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hexapod_interfaces__msg__LegActuators
    std::shared_ptr<hexapod_interfaces::msg::LegActuators_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LegActuators_ & other) const
  {
    if (this->coxa != other.coxa) {
      return false;
    }
    if (this->femur != other.femur) {
      return false;
    }
    if (this->tibia != other.tibia) {
      return false;
    }
    return true;
  }
  bool operator!=(const LegActuators_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LegActuators_

// alias to use template instance with default allocator
using LegActuators =
  hexapod_interfaces::msg::LegActuators_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hexapod_interfaces

#endif  // HEXAPOD_INTERFACES__MSG__DETAIL__LEG_ACTUATORS__STRUCT_HPP_
