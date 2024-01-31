#ifndef WALL_FOLLOWER_COMMON_UTILS_H
#define WALL_FOLLOWER_COMMON_UTILS_H

#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#define HIGH 1e6


/**
 * Gets the current time in microseconds.
 */
static inline int getTimeMicro()
{
    auto now = std::chrono::system_clock::now();
    return now.time_since_epoch().count();
}

/**
 * Sleeps for the provided number of seconds.
 */
static inline void sleepFor(const double secs)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(secs * 1000)));
}

/**
 * Normalizes angle to range [-PI, PI].
 * @param  angle Angle to normalize.
 * @return       Normalized angle.
 */
static inline double normalizeAngle(const double angle)
{
    const double result = fmod(angle + M_PI, 2.0 * M_PI);
    if(result <= 0) return result + M_PI;
    return result - M_PI;
}

/**
 * Performs a cross product between two 3D vectors.
 * @param  v1 First vector.
 * @param  v2 Second vector.
 * @return    Cross product between v1 and v2.
 */
std::vector<float> crossProduct(const std::vector<float>& v1, const std::vector<float>& v2);

/**
 * Finds the index of the minimum distance in the given vector of Lidar ranges.
 * @param  ranges Vector of floats.
 * @return        The index (location) of the smallest value in ranges.
 */
int findMinDist(const std::vector<float>& ranges);

#endif  // WALL_FOLLOWER_COMMON_UTILS_H
