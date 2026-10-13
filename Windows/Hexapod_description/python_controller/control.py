import mujoco
import mujoco.viewer
import time

MODEL_PATH = r"C:\Users\ASUS\Desktop\Hexapod\Scripts\Training\scene.xml"

model = mujoco.MjModel.from_xml_path(MODEL_PATH)
data = mujoco.MjData(model)

sim_dt = model.opt.timestep
render_dt = 1.0 / 60.0

SLOWDOWN = 1.0  # 1.0 = real-time, 4.0 = 4x slower

with mujoco.viewer.launch_passive(model, data) as viewer:

    last_render_time = time.time()

    while viewer.is_running():
        step_start = time.time()
        
        mujoco.mj_step(model, data)

        if time.time() - last_render_time >= render_dt:
            viewer.sync()
            last_render_time = time.time()

        time_until_next_step = (sim_dt * SLOWDOWN) - (time.time() - step_start)
        if time_until_next_step > 0:
            time.sleep(time_until_next_step)