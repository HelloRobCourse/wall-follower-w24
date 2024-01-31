#include <iostream>
#include <cmath>

#include <mbot_bridge/robot.h>
#include <wall_follower/common/utils.h>


int main(int argc, const char *argv[])
{
    // Initialize the robot.
    mbot_bridge::MBot robot;

    /**
     * TODO: (P1.1) Write code to make the robot drive in a square. Then,
     * modify your code so that the robot drives in a square 3 times.
     *
     * HINT: A function to send velocity commands to the robot is provided. To
     * use it, use the following code:
     *
     *      robot.drive(vx, vy, wz);
     *
     * Replace vx, vy, and wz with the velocity in the x direction (vx), y
     * direction (vy), and the angular velocity (wz). You can also use this code:
     *
     *      sleepFor(secs);
     *
     * to sleep for "secs" seconds (replace with desired number of seconds).
     */

    // Stop the robot.
    std::cout << "Stopping the robot!!" << std::endl;
    robot.stop();
    return 0;
}
