cmake_minimum_required(VERSION 3.8)
project(hexapod_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(hexapod_interfaces REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(controller src/control_leg.cpp)
ament_target_dependencies(controller rclcpp hexapod_interfaces)

add_executable(generate_angles src/generate_angles.cpp)
ament_target_dependencies(generate_angles rclcpp hexapod_interfaces)

install(TARGETS
  controller
  generate_angles

  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
