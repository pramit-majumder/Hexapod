#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import serial # type: ignore
import time
from hexapod_interfaces.msg import LegActuators


class DriverNode(Node):
    def __init__(self):
        super().__init__("Client")
        self.sub = self.create_subscription(LegActuators, "leg", self.move_leg, 10)

    def move_leg(self, msg):
        cmd = str(int(msg.coxa)) + ";" + str(int(msg.femur)) + ";" + str(int(msg.tibia)) + "\n"
        self.get_logger().info(cmd)


def main(args=None):

    rclpy.init(args=args)
    node = DriverNode()
    rclpy.spin(node)
    rclpy.shutdown()