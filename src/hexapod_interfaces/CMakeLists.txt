cmake_minimum_required(VERSION 3.8)
project(hexapod_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/LegActuators.msg"
  "msg/Coordinates.msg"

  "srv/InverseKinematics.srv"
)

ament_package()
