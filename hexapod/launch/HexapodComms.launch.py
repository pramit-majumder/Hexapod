import os
from launch import LaunchDescription
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_path

def generate_launch_description():

    arduino = Node(package="hexapod_communication", executable="communication")
    print("Arduino Started")
    IK = Node(package="hexapod_control", executable="generate_angles")
    print("IK Server Ready")
    return LaunchDescription([
        IK, arduino
    ])