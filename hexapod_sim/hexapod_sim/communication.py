from std_msgs.msg import Float64MultiArray
import time
import numpy as np
import mujoco
import mujoco.viewer
from hexapod_interfaces.msg import LegActuators
import math
import rclpy
from rclpy.node import Node

PATH = "/home/waves/hexapod/src/Windows/Hexapod_description/XML/scene.xml"


class HexapodNode(Node):
    def __init__(self):
        super().__init__("hexapod_mujoco")
        self.target = None  # filled in main() once the model is loaded
        self.leg1 = self.create_subscription(LegActuators, "leg1", self.on_leg1, 10)

        self.leg2 = self.create_subscription(LegActuators, "leg2", self.on_leg2, 10)

        self.leg3 = self.create_subscription(LegActuators, "leg3", self.on_leg3, 10)

        self.leg4 = self.create_subscription(LegActuators, "leg4", self.on_leg4, 10)

        self.leg5 = self.create_subscription(LegActuators, "leg5", self.on_leg5, 10)

        self.leg6 = self.create_subscription(LegActuators, "leg6", self.on_leg6, 10)

        self.leg = self.create_subscription(LegActuators, "leg", self.on_leg, 10)

    def on_leg(self, msg):
        coxa = (msg.coxa - 90) * math.pi / 180
        femur = (msg.femur - 90) * math.pi / 180
        tibia = (180 - msg.tibia - 90) * math.pi / 180
        if self.target is not None:
            self.target[0] = coxa
            self.target[1] = femur
            self.target[2] = tibia
            
            self.target[3] = coxa
            self.target[4] = femur
            self.target[5] = tibia
                        
            self.target[6] = coxa
            self.target[7] = femur
            self.target[8] = tibia
            
            self.target[9] = coxa
            self.target[10] = femur
            self.target[11] = tibia
            
            self.target[12] = coxa
            self.target[13] = femur
            self.target[14] = tibia

            self.target[15] = coxa
            self.target[16] = femur
            self.target[17] = tibia
                                             
        self.get_logger().info(f"Leg1:coxa={coxa:.3f}:femur={femur:.3f}:tibia={tibia:.3f}")

    def on_leg1(self, msg):
        coxa = (msg.coxa - 90) * math.pi / 180
        femur = (msg.femur - 90) * math.pi / 180
        tibia = (180 - msg.tibia - 90) * math.pi / 180
        if self.target is not None:
            self.target[0] = coxa
            self.target[1] = femur
            self.target[2] = tibia
        self.get_logger().info(f"Leg1:coxa={coxa:.3f}:femur={femur:.3f}:tibia={tibia:.3f}")

    def on_leg2(self, msg):
        coxa = (msg.coxa - 90) * math.pi / 180
        femur = (msg.femur - 90) * math.pi / 180
        tibia = (msg.tibia - 90) * math.pi / 180
        if self.target is not None:
            self.target[3] = coxa
            self.target[4] = femur
            self.target[5] = tibia
        self.get_logger().info(f"Leg2:coxa={coxa:.3f}:femur={femur:.3f}:tibia={tibia:.3f}")

    def on_leg3(self, msg):
        coxa = (msg.coxa - 90) * math.pi / 180
        femur = (msg.femur - 90) * math.pi / 180
        tibia = (msg.tibia - 90) * math.pi / 180
        if self.target is not None:
            self.target[6] = coxa
            self.target[7] = femur
            self.target[8] = tibia
        self.get_logger().info(f"Leg3:coxa={coxa:.3f}:femur={femur:.3f}:tibia={tibia:.3f}")

    def on_leg4(self, msg):
        coxa = (msg.coxa - 90) * math.pi / 180
        femur = (msg.femur - 90) * math.pi / 180
        tibia = (msg.tibia - 90) * math.pi / 180
        if self.target is not None:
            self.target[9] = coxa
            self.target[10] = femur
            self.target[11] = tibia
        self.get_logger().info(f"Leg4:coxa={coxa:.3f}:femur={femur:.3f}:tibia={tibia:.3f}")
    
    def on_leg5(self, msg):
        coxa = (msg.coxa - 90) * math.pi / 180
        femur = (msg.femur - 90) * math.pi / 180
        tibia = (msg.tibia - 90) * math.pi / 180
        if self.target is not None:
            self.target[12] = coxa
            self.target[13] = femur
            self.target[14] = tibia
        self.get_logger().info(f"Leg5:coxa={coxa:.3f}:femur={femur:.3f}:tibia={tibia:.3f}")
    
    def on_leg6(self, msg):
        coxa = (msg.coxa - 90) * math.pi / 180
        femur = (msg.femur - 90) * math.pi / 180
        tibia = (msg.tibia - 90) * math.pi / 180
        if self.target is not None:
            self.target[15] = coxa
            self.target[16] = femur
            self.target[17] = tibia
        self.get_logger().info(f"Leg6:coxa={coxa:.3f}:femur={femur:.3f}:tibia={tibia:.3f}")

def main():
    rclpy.init()
    node = HexapodNode()

    model = mujoco.MjModel.from_xml_path(PATH)
    data = mujoco.MjData(model)

    # Holds the commanded angle for every actuator; starts at 0 rad
    node.target = np.zeros(model.nu)

    for i in range(model.nu):
        print(i, mujoco.mj_id2name(model, mujoco.mjtObj.mjOBJ_ACTUATOR, i))

    sim_dt = model.opt.timestep
    render_dt = 1.0 / 60.0

    with mujoco.viewer.launch_passive(model, data) as viewer:
        last_render = time.time()

        while viewer.is_running() and rclpy.ok():
            t0 = time.time()

            rclpy.spin_once(node, timeout_sec=0.0)

            data.ctrl[:] = node.target
            mujoco.mj_step(model, data)

            if time.time() - last_render >= render_dt:
                viewer.sync()
                last_render = time.time()

            rem = sim_dt - (time.time() - t0)
            if rem > 0:
                time.sleep(rem)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()