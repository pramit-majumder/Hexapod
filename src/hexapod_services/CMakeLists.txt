cmake_minimum_required(VERSION 3.8)
project(hexapod_services)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(hexapod_interfaces REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(solver src/inverse_kinematics.cpp)
ament_target_dependencies(solver rclcpp hexapod_interfaces)

install(TARGETS
  solver

  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
