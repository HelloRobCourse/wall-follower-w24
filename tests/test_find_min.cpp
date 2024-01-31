#include <iostream>
#include <vector>

#include <wall_follower/common/utils.h>

#include "test_utils.h"


bool run_test(std::vector<float>& v, int ans) {
    int out = findMinDist(v);
    bool res = out == ans;

    if (!res) {
        std::cout << "\tFailed! For vector: ";
        print_vec(v);
        std::cout << " expected: " << ans << " but got: " << out;
    }
    else std::cout << "\tPassed!";

    return res;
}

int main(int argc, const char *argv[])
{
    std::cout << "\n*** FIND MIN RAY TESTS ***" << std::endl;

    std::vector<bool> results;

    std::cout << "\n\tBasic vector test... ";
    std::vector<float> v1 = {0.5, 200, 12.6, 0.2, 0.3, 10.4, 61, 0.99, 1.5};
    bool t1 = run_test(v1, 3);
    results.push_back(t1);

    std::cout << "\n\tIgnore zeros test... ";
    std::vector<float> v2 = {9, 7, 5, 3, 1, 0, 2, 4, 6, 8};
    bool t2 = run_test(v2, 4);
    results.push_back(t2);

    std::cout << "\n\tIgnore first zero test... ";
    std::vector<float> v3 = {0, 0.01, 1, 0.011, 10, 1};
    bool t3 = run_test(v3, 1);
    results.push_back(t3);

    std::cout << "\n\tIgnore first zeros test... ";
    std::vector<float> v4 = {0, 0, 0, 0.01, 1, 0.011, 10, 1};
    bool t4 = run_test(v4, 3);
    results.push_back(t4);

    bool pass = summarize_results(results);
    if (!pass) {
        std::cout << "\nTESTS FAILED :(" << std::endl;
        return -1;
    }

    std::cout << "\nTESTS PASSED! :)" << std::endl;
    return 0;
}
