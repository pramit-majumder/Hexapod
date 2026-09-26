from launch import LaunchDescription
from launch_ros.actions import Node

import random
import string
import time
import sys


def glitch_text(text, delay=0.02, cycles=4):

    chars = string.ascii_uppercase + string.digits + "!@#$%^&*"

    output = [" "] * len(text)

    for i, target in enumerate(text):

        if target == " ":
            output[i] = " "
            sys.stdout.write("\r" + "".join(output))
            sys.stdout.flush()
            continue

        for _ in range(cycles):
            output[i] = random.choice(chars)

            sys.stdout.write("\r" + "".join(output))
            sys.stdout.flush()

            time.sleep(delay)

        output[i] = target

        sys.stdout.write("\r" + "".join(output))
        sys.stdout.flush()

        time.sleep(delay)

    print()


def generate_launch_description():

    logo = r"""
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

    glitch_text("\n" + logo, delay=0.02, cycles=1)

    print("========================================")

    glitch_text(
        "DECEPTICON SYSTEM INITIALIZING",
        delay=0.02,
        cycles=1
    )

    print("========================================")

    glitch_text(
        "SOUNDWAVE SUPERIOR.",
        delay=0.02,
        cycles=1
    )

    glitch_text(
        "AUTOBOTS INFERIOR.",
        delay=0.02,
        cycles=1
    )

    print("========================================")
    print()

    return LaunchDescription([
        # Add ROS 2 nodes here
    ])