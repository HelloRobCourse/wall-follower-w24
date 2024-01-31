#include <iostream>
#include <cmath>

#include <signal.h>

#include <mbot_bridge/robot.h>
#include <wall_follower/common/utils.h>

bool ctrl_c_pressed;
void ctrlc(int)
{
    ctrl_c_pressed = true;
}


int main(int argc, const char *argv[])
{
    signal(SIGINT, ctrlc);
    signal(SIGTERM, ctrlc);

    // Initialize the robot.
    mbot_bridge::MBot robot;
    // Create empty vectors to store the scan data.
    std::vector<float> ranges;
    std::vector<float> thetas;

    /**
     * TODO: Declare any variables you need here.
     */

    while (true) {
        // This function gets the Lidar scan data.
        robot.readLidarScan(ranges, thetas);

        /**
         * TODO: (P1.2) Write code to follow the nearest wall here.
         *
         * HINT: You should use the functions crossProduct and findMinDist.
         */

        if (ctrl_c_pressed) break;
    }

    // Stop the robot.
    robot.stop();
    return 0;
}
