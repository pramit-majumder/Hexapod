// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hexapod_interfaces:srv/InverseKinematics.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__STRUCT_HPP_
#define HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hexapod_interfaces__srv__InverseKinematics_Request __attribute__((deprecated))
#else
# define DEPRECATED__hexapod_interfaces__srv__InverseKinematics_Request __declspec(deprecated)
#endif

namespace hexapod_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct InverseKinematics_Request_
{
  using Type = InverseKinematics_Request_<ContainerAllocator>;

  explicit InverseKinematics_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
      this->y = 0ll;
      this->z = 0ll;
      this->coxa_length = 0ll;
      this->femur_length = 0ll;
      this->tibia_length = 0ll;
    }
  }

  explicit InverseKinematics_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
      this->y = 0ll;
      this->z = 0ll;
      this->coxa_length = 0ll;
      this->femur_length = 0ll;
      this->tibia_length = 0ll;
    }
  }

  // field types and members
  using _x_type =
    int64_t;
  _x_type x;
  using _y_type =
    int64_t;
  _y_type y;
  using _z_type =
    int64_t;
  _z_type z;
  using _coxa_length_type =
    int64_t;
  _coxa_length_type coxa_length;
  using _femur_length_type =
    int64_t;
  _femur_length_type femur_length;
  using _tibia_length_type =
    int64_t;
  _tibia_length_type tibia_length;

  // setters for named parameter idiom
  Type & set__x(
    const int64_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int64_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const int64_t & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__coxa_length(
    const int64_t & _arg)
  {
    this->coxa_length = _arg;
    return *this;
  }
  Type & set__femur_length(
    const int64_t & _arg)
  {
    this->femur_length = _arg;
    return *this;
  }
  Type & set__tibia_length(
    const int64_t & _arg)
  {
    this->tibia_length = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hexapod_interfaces__srv__InverseKinematics_Request
    std::shared_ptr<hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hexapod_interfaces__srv__InverseKinematics_Request
    std::shared_ptr<hexapod_interfaces::srv::InverseKinematics_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InverseKinematics_Request_ & other) const
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
    if (this->coxa_length != other.coxa_length) {
      return false;
    }
    if (this->femur_length != other.femur_length) {
      return false;
    }
    if (this->tibia_length != other.tibia_length) {
      return false;
    }
    return true;
  }
  bool operator!=(const InverseKinematics_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InverseKinematics_Request_

// alias to use template instance with default allocator
using InverseKinematics_Request =
  hexapod_interfaces::srv::InverseKinematics_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hexapod_interfaces


#ifndef _WIN32
# define DEPRECATED__hexapod_interfaces__srv__InverseKinematics_Response __attribute__((deprecated))
#else
# define DEPRECATED__hexapod_interfaces__srv__InverseKinematics_Response __declspec(deprecated)
#endif

namespace hexapod_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct InverseKinematics_Response_
{
  using Type = InverseKinematics_Response_<ContainerAllocator>;

  explicit InverseKinematics_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->coxa = 0.0f;
      this->femur = 0.0f;
      this->tibia = 0.0f;
    }
  }

  explicit InverseKinematics_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->coxa = 0.0f;
      this->femur = 0.0f;
      this->tibia = 0.0f;
    }
  }

  // field types and members
  using _coxa_type =
    float;
  _coxa_type coxa;
  using _femur_type =
    float;
  _femur_type femur;
  using _tibia_type =
    float;
  _tibia_type tibia;

  // setters for named parameter idiom
  Type & set__coxa(
    const float & _arg)
  {
    this->coxa = _arg;
    return *this;
  }
  Type & set__femur(
    const float & _arg)
  {
    this->femur = _arg;
    return *this;
  }
  Type & set__tibia(
    const float & _arg)
  {
    this->tibia = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hexapod_interfaces__srv__InverseKinematics_Response
    std::shared_ptr<hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hexapod_interfaces__srv__InverseKinematics_Response
    std::shared_ptr<hexapod_interfaces::srv::InverseKinematics_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InverseKinematics_Response_ & other) const
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
  bool operator!=(const InverseKinematics_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InverseKinematics_Response_

// alias to use template instance with default allocator
using InverseKinematics_Response =
  hexapod_interfaces::srv::InverseKinematics_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hexapod_interfaces

namespace hexapod_interfaces
{

namespace srv
{

struct InverseKinematics
{
  using Request = hexapod_interfaces::srv::InverseKinematics_Request;
  using Response = hexapod_interfaces::srv::InverseKinematics_Response;
};

}  // namespace srv

}  // namespace hexapod_interfaces

#endif  // HEXAPOD_INTERFACES__SRV__DETAIL__INVERSE_KINEMATICS__STRUCT_HPP_
