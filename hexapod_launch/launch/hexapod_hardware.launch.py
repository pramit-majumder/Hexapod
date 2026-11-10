from launch import LaunchDescription
from launch_ros.actions import Node

import random
import string
import sys
import time

GLITCH_CHARS = string.ascii_uppercase + string.digits + "!@#$%^&*"
BLANKS = (" ", "\u2800")  # space and braille blank


def glitch_text(text, delay=0.02, cycles=4):
    """Single-line glitch-in effect. Do not pass multi-line text."""
    output = [" "] * len(text)

    for i, target in enumerate(text):
        if target in BLANKS:
            output[i] = target
            continue

        for _ in range(cycles):
            output[i] = random.choice(GLITCH_CHARS)
            sys.stdout.write("\r" + "".join(output))
            sys.stdout.flush()
            time.sleep(delay)

        output[i] = target
        sys.stdout.write("\r" + "".join(output))
        sys.stdout.flush()
        time.sleep(delay)

    print()


def glitch_block(text, delay=0.002, cycles=1):
    """Glitch a multi-line block one line at a time."""
    for line in text.split("\n"):
        glitch_text(line, delay=delay, cycles=cycles)


LOGO = r"""
              ⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⠀ ⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
            ⢸⣄⠀⠀⠀⠀⠀⠀⠀⠀⣧⡀⠀⠀⠀⠀⢀⣼⠀⠀⠀⠀⠀⠀⠀⠀  ⣠
           ⠀⣿⣧⣀⡀⠀⠀⠀⠀⠀⠀⣿⣷⡀⠀⠀⢀⣾⡟⠀⠀⠀⠀⠀⠀⢀⣀⣴⣿⠀
           ⠀⣿⣿⣿⣿⣿⣷⣶⣤⣤ ⢸⣿⣿⣿⣿⣿⣿⡇⠀⣠⣤⣶⣶⣿⣿⣿⣿⡟⠀
           ⠀⢹⣿⣿⣤⣈⣉⠛⠛⠿ ⠸⣿⣷⠀⠀⣾⣿⠀⠸⠿⠟⠛⠋⣉⣁⣿⣿⡇⠀
           ⠀⢸⣿⣿⡟⠛⠿⠿⣷⣶⡄⠀⣿⣿⣇⣸⣿⡟⠀⣤⣴⣶⡾⠿⠟⢻⣿⣿⠀
           ⠀⠘⣿⣿⣿⣷⣶⣤⣤⣀⠁⠀⠻⣿⣿⣿⣿⠇⠀⠉⣁⣠⣤⣴⣶⣾⣿⡿⠀⠀
            ⠀⠈⢿⣿⡿⢿⣿⣿⣿⣿⣷⣄⠈⠻⟟⠁⣠⣾⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀
           ⠀⠀⣧⡀⠻⣿⣄⠈⠉⠛⠛⠿⢿⣷⣄⣴⣾⡿⠿⠟⠛⠉⢉⣴⣿⠋⢠⡎⠀⠀
           ⠀⠀⣿⣷⡄⠘⢿⣷⣄⠀⠀⠀⢠⣿⣿⣿⣧⠀⠀⠀⢀⣴⣿⡟⠁⣰⣿⡇⠀⠀
           ⠀⠀⢻⣿⣿⣦⠈⢻⣿⣷⣄⢀⣿⣿⣿⣿⣿⣧⠀⣰⣿⣿⠏⢀⣾⣿⣿⠇⠀⠀
           ⠀⠀⢸⣿⣿⣿⣷⡀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⣠⣿⣿⣿⣿⠀⠀⠀
           ⠀⠀⢸⣿⣿⣿⣿⣿⣄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢀⣴⣿⣿⣿⣿⣿⠀⠀⠀
           ⠀⠀⠘⠿⣿⣿⣿⣿⣿⣧⡀⠻⣿⣿⣿⣿⣿⡿⠃⢠⣾⣿⣿⣿⣿⣿⠏⠀⠀⠀
             ⠀⠀⠀⠉⠙⠻⢿⣿⣷⡄⠘⢿⣿⣿⠟⠀⣴⣿⣿⠿⠟⠋⠁⠀⠀⠀⠀⠀
            ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠦⠈⠻⠋⠀⠞⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
"""


def show_banner():
    glitch_block(LOGO, delay=0.002, cycles=1)
    print("=" * 40)
    glitch_text("DECEPTICON SYSTEM INITIALIZING", delay=0.02, cycles=1)
    print("=" * 40)
    glitch_text("SOUNDWAVE SUPERIOR.", delay=0.02, cycles=1)
    glitch_text("AUTOBOTS INFERIOR.", delay=0.02, cycles=1)
    print("=" * 40)
    print()


def generate_launch_description():
    # show_banner()

    nodes = []
    nodes.append(
        Node(
            package='hexapod_communication',
            executable='communication',
            name='communication',
            output='screen',
        )
    )
    for i in range(1, 7):
        nodes.append(
            Node(
                package='hexapod_control',
                executable='controller',
                name=f'controller_leg{i}',
                output='screen',
                remappings=[
                    ('leg', f'leg{i}'),
                    ('coords', f'coords{i}'),
                ],
            )
        )

    return LaunchDescription(nodes)