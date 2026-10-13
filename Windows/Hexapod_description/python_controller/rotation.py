import time

import numpy as np
import mujoco
import mujoco.viewer

MODEL_PATH = r"C:\Users\ASUS\Desktop\Hexapod\Scripts\Training\scene.xml"

SWEEP = True        # True: move the femur joints back and forth so you can see the mesh rotate around its axis
SWEEP_AMP = 0.6     # radians
SWEEP_FREQ = 0.5    # Hz
SLOWDOWN = 1.0      # 1.0 = real-time, 4.0 = 4x slower

model = mujoco.MjModel.from_xml_path(MODEL_PATH)
data = mujoco.MjData(model)

# Pick out only the femur actuators by name (femur_56 ... femur_61 in hexapod.xml)
femur_ids = [
    i for i in range(model.nu)
    if not (mujoco.mj_id2name(model, mujoco.mjtObj.mjOBJ_ACTUATOR, i) or "").lower().startswith("holder")
]
if not femur_ids:
    raise RuntimeError(
        "No actuators whose name starts with 'femur' were found. "
        "Check the <actuator> block in your scene/hexapod XML."
    )
print("Controlling femur actuators:",
      [mujoco.mj_id2name(model, mujoco.mjtObj.mjOBJ_ACTUATOR, i) for i in femur_ids])

# Make the joint axis arrows bigger and thicker (the model is small)
model.vis.scale.jointlength = 2.0
model.vis.scale.jointwidth = 0.04

sim_dt = model.opt.timestep
render_dt = 1.0 / 60.0

with mujoco.viewer.launch_passive(model, data) as viewer:
    # Show the axis of every joint (all groups 0-5)
    viewer.opt.flags[mujoco.mjtVisFlag.mjVIS_JOINT] = True
    viewer.opt.jointgroup[:] = 1

    last_render_time = time.time()

    while viewer.is_running():
        step_start = time.time()

        # All other actuators (the holders) stay at ctrl = 0
        data.ctrl[:] = 0.0
        if SWEEP:
            target = SWEEP_AMP * np.sin(2 * np.pi * SWEEP_FREQ * data.time)
            data.ctrl[femur_ids] = target

        mujoco.mj_step(model, data)

        if time.time() - last_render_time >= render_dt:
            viewer.sync()
            last_render_time = time.time()

        time_until_next_step = (sim_dt * SLOWDOWN) - (time.time() - step_start)
        if time_until_next_step > 0:
            time.sleep(time_until_next_step)