# Custom 18-DOF Hexapod Robot

![Status](https://img.shields.io/badge/status-prototype-orange)
![Platform](https://img.shields.io/badge/platform-Arduino%20%7C%20Raspberry%20Pi-blue)
![Communication](https://img.shields.io/badge/communication-Serial%20%7C%20I2C-green)
![License](https://img.shields.io/badge/license-MIT-blue)

A custom-built 18-DOF hexapod robot developed as an undergraduate robotics project by Pramit Majumder, Mechatronics Engineering, KIIT. The project integrates mechanical design, servo control, inverse kinematics, ROS 2, gait generation, and real-world locomotion.

The robot is being developed as a complete hardware–software robotics system, covering mechanical construction, electronics, embedded control, kinematics, trajectory generation, and physical testing.

## Project Status

The project is currently under development. Mechanical assembly, servo and electronics testing, ROS 2 control architecture, inverse kinematics, and gait generation are being developed in parallel. Full-body locomotion testing is planned after the mechanical, electrical, and control subsystems have been validated.

## Robot Overview

The robot has six independently controlled legs. Each leg contains three actuated joints:

- Coxa.
- Femur.
- Tibia.

The total number of degrees of freedom is:

\[
6\text{ legs} \times 3\text{ DOF per leg}=18\text{ DOF}
\]

Each leg is modeled as a 3-DOF serial manipulator, allowing the foot position to be controlled in three-dimensional space.

### Approximate Leg Dimensions

| Link | Length |
|---|---:|
| Coxa | 50 mm |
| Femur | 75 mm |
| Tibia | 112 mm |

The approximate coxa–femur–tibia proportion is 0.67:1:1.5.

## Hardware

### Actuation

- 18 × MG995 servo motors.
- Three servo motors per leg.
- PCA9685 PWM servo drivers.

### Main Controllers

- Arduino Mega for low-level servo control.
- Raspberry Pi 4B for higher-level computation and robot control.

### Additional Hardware

- Custom and 3D-printed ABS structural components.
- Hexagonal top and base plates.
- Bearings for selected joints.
- M3 and M4 mechanical fasteners.
- External servo power supply.
- ESP32-CAM for future perception and scouting functionality.

The servo power system is electrically separated from the logic and control electronics. A common ground must be maintained between the servo supply, PCA9685 boards, Arduino, and communication interface.

## Software Architecture

The software stack is divided into high-level computation and low-level actuation layers:

```text
                         ROS 2
                           |
              +------------+------------+
              |                         |
       Waypoint Generator              IK
              |                         |
              +------------+------------+
                           |
                      Leg Control
                           |
                    Serial / MCU Link
                           |
                    Arduino Mega
                           |
                         I2C
                           |
                       PCA9685
                           |
                    18 Servo Motors
```

High-level motion commands are separated from the low-level servo implementation. This allows the kinematics, gait, and planning layers to operate using Cartesian or joint-space commands without depending directly on the servo driver implementation.

## ROS 2 Packages

### `hexapod_interfaces`

Custom ROS 2 interfaces used for communication among the robot's software components.

#### `Coordinates`

Represents a desired Cartesian foot position and the associated leg geometry:

```text
int64 x
int64 y
int64 z

int64 coxa_length
int64 femur_length
int64 tibia_length

float32 coxa
float32 femur
float32 tibia
```

The coordinate and geometry fields may be refactored into separate messages as the interface matures, so that input geometry and calculated joint angles are represented more clearly.

#### `LegActuators`

Transmits calculated joint actuator positions to the low-level controller. The message is intended to carry mapped actuator commands after servo offsets, direction inversions, and leg-specific calibration have been applied.

### `leg_control`

The `leg_control` node converts joint commands into actuator commands and communicates with the microcontroller through a serial connection.

### `waypoint_generator`

The waypoint-generation node produces discrete Cartesian foot positions for individual legs and coordinated gait execution.

## Communication Architecture

The robot uses a layered communication system:

- Serial communication for the Raspberry Pi–Arduino control link.
- I2C communication between the Arduino and PCA9685 PWM drivers.
- PWM signals from the PCA9685 boards to the servo motors.

The communication layer should include command validation, timeout handling, range checks, and a safe output state when the connection is interrupted.

## Motion Pipeline

The intended motion pipeline is:

```text
Desired Motion
      |
      v
Waypoints
      |
      v
Foot Coordinates
      |
      v
Inverse Kinematics
      |
      v
Joint Angles
      |
      v
Servo Mapping
      |
      v
Servo Commands
      |
      v
Physical Robot
```

## Kinematics

Each leg is modeled as a 3-DOF serial manipulator consisting of:

- Coxa joint.
- Femur joint.
- Tibia joint.

The inverse kinematics (IK) system calculates the three joint angles required to place the foot at a desired Cartesian position:

\[
P=(x,y,z)
\]

where \(x\), \(y\), and \(z\) represent the desired foot position relative to the leg coordinate frame.

The coxa joint primarily rotates the leg about the vertical axis, while the femur and tibia joints control the foot position in the resulting vertical plane.

### Leg Parameters

The current physical leg dimensions are:

\[
L_c=50\text{ mm},\qquad L_f=75\text{ mm},\qquad L_t=112\text{ mm}
\]

where:

- \(L_c\) is the coxa length.
- \(L_f\) is the femur length.
- \(L_t\) is the tibia length.

The equations below assume a defined leg coordinate convention in which the coxa angle is measured using `atan2(y, x)`, and the femur–tibia plane uses the reduced horizontal distance and signed vertical coordinate. Servo mounting conventions may require angle offsets, sign changes, or alternate elbow configurations.

### Coxa Angle

The coxa joint determines the horizontal rotation of the leg around the vertical axis:

\[
\boxed{\theta_c=\operatorname{atan2}(y,x)}
\]

### Horizontal Distance

The horizontal distance from the coxa joint to the foot is:

\[
r=\sqrt{x^2+y^2}
\]

After removing the coxa link length, the effective horizontal distance for the femur–tibia plane is:

\[
\boxed{r'=r-L_c}
\]

or, equivalently:

\[
\boxed{r'=\sqrt{x^2+y^2}-L_c}
\]

### Femur–Tibia Distance

The distance between the femur joint and the desired foot position is:

\[
\boxed{D=\sqrt{r'^2+z^2}}
\]

### Tibia Angle

Using the law of cosines, the internal femur–tibia angle is:

\[
\boxed{\theta_t=\cos^{-1}\left(\frac{L_f^2+L_t^2-D^2}{2L_fL_t}\right)}
\]

The servo command for the tibia is obtained from this geometric angle using the selected physical mounting convention. For example, an actuated knee may require \(\pi-\theta_t\), a sign inversion, or an offset.

### Femur Angle

First, calculate the angle between the horizontal axis and the line connecting the femur joint to the foot:

\[
\alpha=\operatorname{atan2}(z,r')
\]

The internal angle between the femur link and the line connecting the femur joint to the foot is:

\[
\beta=\cos^{-1}\left(\frac{L_f^2+D^2-L_t^2}{2L_fD}\right)
\]

For the selected branch of the IK solution, the femur angle is:

\[
\boxed{\theta_f=\operatorname{atan2}(z,r')+\cos^{-1}\left(\frac{L_f^2+D^2-L_t^2}{2L_fD}\right)}
\]

The alternate elbow configuration can be obtained by changing the sign of the triangle term. The final branch must be selected according to the physical leg geometry, desired posture, joint limits, and collision constraints.

### Complete IK Formulation

The complete inverse kinematics calculation is summarized as:

\[
\boxed{\theta_c=\operatorname{atan2}(y,x)}
\]

\[
\boxed{r'=\sqrt{x^2+y^2}-L_c}
\]

\[
\boxed{D=\sqrt{r'^2+z^2}}
\]

\[
\boxed{\theta_t=\cos^{-1}\left(\frac{L_f^2+L_t^2-D^2}{2L_fL_t}\right)}
\]

\[
\boxed{\theta_f=\operatorname{atan2}(z,r')+\cos^{-1}\left(\frac{L_f^2+D^2-L_t^2}{2L_fD}\right)}
\]

The resulting geometric joint-angle vector is:

\[
\boxed{(\theta_c,\theta_f,\theta_t)}
\]

These geometric angles are subsequently converted into servo commands. Servo offsets, direction inversions, left/right leg mirroring, calibration limits, and mounting orientation are handled separately according to the physical configuration of each leg.

Before evaluating the inverse trigonometric functions in software, the cosine arguments should be clamped to the interval \([-1,1]\) to protect against floating-point rounding errors.

### Reachability

A requested foot position is reachable only when the femur–tibia distance satisfies:

\[
\boxed{|L_f-L_t|\le D\le L_f+L_t}
\]

For the current leg dimensions:

\[
\boxed{37\text{ mm}\le D\le187\text{ mm}}
\]

Positions outside this workspace cannot be reached by the femur–tibia pair using the current link geometry. In practice, the usable workspace is smaller because of servo limits, mechanical interference, structural deflection, cable routing, and collision avoidance.

The geometric reachability check should be performed before calculating the inverse trigonometric terms. A complete implementation should also check the coxa angle range, femur and tibia servo limits, and whether the resulting configuration causes self-collision or ground contact.

### Coordinate-to-Actuator Pipeline

```text
Desired Foot Position
          |
          v
       (x, y, z)
          |
          v
  Reachability and Limits Check
          |
          v
    Inverse Kinematics
          |
          +----> Coxa Angle
          |
          +----> Femur Angle
          |
          +----> Tibia Angle
          |
          v
  Servo Mapping / Calibration
          |
          v
    PCA9685 PWM Commands
          |
          v
        Servos
```

## Motion Generation

The robot is intended to support both individual leg motion and coordinated six-leg locomotion. Development proceeds through the following stages:

1. Individual servo testing.
2. Individual leg movement.
3. Full-leg synchronization.
4. Cartesian foot positioning.
5. Waypoint generation.
6. Gait generation.
7. Coordinated leg movement.
8. Full-body locomotion testing.

The project distinguishes between point-to-point movement and continuous trajectories. Point-to-point motion commands a leg or joint between defined positions, whereas trajectory-based motion generates intermediate states over time to provide smoother motion and better control of velocity and acceleration.

## Gait Development

The gait system will coordinate:

- Leg lifting.
- Foot placement.
- Swing and stance phases.
- Body support.
- Foot trajectories.
- Inter-leg timing.
- Stability during weight transfer.

The gait generator will provide target foot positions to the inverse kinematics layer rather than directly commanding servo motors.

```text
Gait Generator
      |
      v
Foot Trajectory
      |
      v
Cartesian Coordinates
      |
      v
Inverse Kinematics
      |
      v
Joint Angles
      |
      v
Servo Controller
```

## Mechanical Design

The mechanical structure is designed and fabricated using 3D-printed components. Current printed parts use ABS filament with approximately 15% infill.

The mechanical design prioritizes:

- Low mass.
- Sufficient joint strength.
- Simple assembly.
- Replaceable components.
- Accessible electronics.
- Practical servo mounting.

Bearings are used at selected mechanical joints to reduce friction and mechanical loading. Final structural validation should account for servo torque, impact loads, printed-part anisotropy, fastener pull-out, and deflection under static and dynamic conditions.

## Electronics

The basic servo-control architecture is:

```text
ROS 2 / Raspberry Pi
          |
        Serial
          |
    Arduino Mega
          |
          I2C
          |
       PCA9685
          |
    18 Servo Motors
```

The PCA9685 provides dedicated PWM channels, allowing the Arduino to control the robot's servos without requiring one hardware PWM output per servo. The Arduino handles low-level timing and actuator commands, while the Raspberry Pi performs higher-level computation, kinematics, waypoint generation, and gait control.

The power system should be designed for the high instantaneous current demand of 18 MG995 servos. Logic power and servo power should use appropriate regulation, wiring, fusing, connectors, and a common ground. Emergency stop and staged power-up procedures are recommended during testing.

## Development Environment

### Robotics

- ROS 2.
- Ubuntu 22.04.
- Python.
- C++.
- Arduino.
- Raspberry Pi.

The project focuses on direct physical robot development, embedded control, ROS 2 integration, and hardware validation.

## Planned Learning-Based Control

A future direction is the investigation of neural-network-based robot control. Potential applications include:

- Neural-network inverse kinematics.
- Learned foot-position mapping.
- Reinforcement-learning-based gait generation.
- Sim-to-real policy transfer.

The learning-based controller is intended to complement, rather than replace, the conventional robot model and control pipeline. Analytical kinematics, joint limits, safety checks, and low-level actuator protections should remain available as a reliable baseline and safety layer.

## Development Roadmap

1. Design the hexapod structure.
2. Design the individual leg geometry.
3. Manufacture the initial mechanical components.
4. Assemble and validate one leg.
5. Test individual servos.
6. Establish PCA9685 servo control.
7. Complete the mechanical assembly.
8. Complete and validate the power system.
9. Finalize the top plate.
10. Test all 18 actuators.
11. Implement and validate inverse kinematics.
12. Implement waypoint generation.
13. Research and select a gait.
14. Implement gait generation.
15. Test coordinated leg movement.
16. Test complete robot locomotion.
17. Develop a learning-based controller.
18. Investigate sim-to-real transfer.

## Repository Structure

```text
hexapod/
├── README.md
├── ros2_ws/
│   └── src/
│       ├── hexapod_interfaces/
│       ├── leg_control/
│       └── waypoint_generator/
├── firmware/
│   └── arduino/
├── kinematics/
├── gait/
├── CAD/
├── documentation/
└── tests/
```

The repository structure may change as the project develops.

## Project Goals

The primary goal is to develop a complete custom hexapod platform rather than simply assemble a commercially available robot. The project combines:

- Mechanical design.
- Embedded systems.
- Robotics control.
- Forward and inverse kinematics.
- Motion planning.
- Gait generation.
- ROS 2 integration.
- Computer vision.
- Machine learning.

The final system is intended to provide a platform for experimenting with conventional and learning-based approaches to legged robotics.

## License

The project is intended to be released under the MIT License. The license status should be finalized when the repository is published.

## Author

**Pramit Majumder**  
Mechatronics Engineering  
KIIT  
Undergraduate Robotics Project

