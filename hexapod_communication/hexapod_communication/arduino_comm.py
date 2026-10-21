#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import serial  # type: ignore
import time
from hexapod_interfaces.msg import LegActuators


class ArduinoDriverNode(Node):
    def __init__(self, ser):
        super().__init__("arduino_client")
        self.ser_ = ser
        self.subs_ = []
        for i in range(1, 7):
            self.subs_.append(self.create_subscription(
                LegActuators, f"leg{i}",
                lambda msg, leg=i: self.move_leg(leg, msg), 10))
        self.create_timer(0.01, self.read_serial)  # poll the Arduino 100x per second

    def move_leg(self, leg, msg):
        # Send: leg;coxa;femur;tibia\n   (leg is 1-6)
        cmd = f"{leg};{round(msg.coxa)};{round(msg.femur)};{round(msg.tibia)}\n"
        self.ser_.write(cmd.encode("utf-8"))

    def read_serial(self):
        # Print whatever the Arduino echoed back
        while self.ser_.in_waiting > 0:
            line = self.ser_.readline().decode("utf-8", errors="ignore").strip()
            if not line:
                continue
            if line.startswith("ERR"):
                self.get_logger().warn(f"Arduino: {line}")
            else:
                self.get_logger().info(f"Arduino: {line}")


def main(args=None):
    print("starting", flush=True)
    # Connect with ACM0, else try ACM1
    ser = None
    while True:
        try:
            ser = serial.Serial('/dev/ttyACM0', 115200, timeout=0.1)
            print("Successfully connected to Serial.", flush=True)
            time.sleep(1)
            ser.reset_input_buffer()
            break
        except serial.SerialException:
            try:
                ser = serial.Serial('/dev/ttyACM1', 115200, timeout=0.1)
                print("Successfully connected to Serial.", flush=True)
                time.sleep(1)
                ser.reset_input_buffer()
                break
            except serial.SerialException:
                print("Could not connect to Serial. Retrying in 1 second...", flush=True)
                time.sleep(1)

    rclpy.init(args=args)
    node = ArduinoDriverNode(ser)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        ser.close()
        rclpy.shutdown()


if __name__ == '__main__':
    main()