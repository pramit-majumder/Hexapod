import time
import numpy as np
import mujoco
import mujoco.viewer

PATH = "/home/waves/hexapod/src/Windows/Hexapod_description/XML/scene.xml"
model = mujoco.MjModel.from_xml_path(PATH)
data = mujoco.MjData(model)

for i in range(model.nu):
    print(i, mujoco.mj_id2name(model, mujoco.mjtObj.mjOBJ_ACTUATOR, i))

sim_dt = model.opt.timestep
render_dt = 1.0 / 60.0

with mujoco.viewer.launch_passive(model, data) as viewer:
    last_render = time.time()

    while viewer.is_running():
        t0 = time.time()

        data.ctrl[:] = 1.57 * np.sin(2 * np.pi * 0.5 * data.time)  # -90 to +90 deg
        mujoco.mj_step(model, data)

        if time.time() - last_render >= render_dt:
            viewer.sync()
            last_render = time.time()

        rem = sim_dt - (time.time() - t0)
        if rem > 0:
            time.sleep(rem)