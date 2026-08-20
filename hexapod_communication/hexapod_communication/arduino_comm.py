#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import serial # type: ignore
import time
from hexapod_interfaces.msg import LegActuators


class ArduinoDriverNode(Node):
    def __init__(self, ser):
        super().__init__("arduino_client")
        self.ser_ = ser
        self.sub = self.create_subscription(LegActuators, "leg", self.move_leg, 10)

    def move_leg(self, msg):
        cmd = str(int(msg.coxa)) + ";" + str(int(msg.femur)) + ";" + str(int(msg.tibia))
        self.ser_.write(cmd.encode('utf-8'))
        self.get_logger().info(cmd)


def main(args=None):
    # Init serial
    ser = None
    while True:
        try:
            ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1.0)
            print("Successfully connected to Serial.")
            time.sleep(1)
            ser.reset_input_buffer()
            break
        except serial.SerialException:
            print("Could not connect to Serial. Retrying in 1 second...")
            time.sleep(1)

    rclpy.init(args=args)
    node = ArduinoDriverNode(ser)
    rclpy.spin(node)
    ser.close()
    rclpy.shutdown()