#include <iostream>
#include <vector>

#include <wall_follower/common/utils.h>

#include "test_utils.h"

bool run_test(std::vector<float>& v1, std::vector<float>& v2, std::vector<float>& ans) {
    auto out = crossProduct(v1, v2);
    bool res = is_close(ans, out);

    if (!res) {
        std::cout << "\tFailed! For vector: ";
        print_vec(v1);
        std::cout << " x ";
        print_vec(v2);
        std::cout << " expected: ";
        print_vec(ans);
        std::cout << " but got: ";
        print_vec(out);
    }
    else std::cout << "\tPassed!";

    return res;
}

int main(int argc, const char *argv[])
{
    std::cout << "\n*** CROSS PRODUCT TESTS ***" << std::endl;

    std::vector<bool> results;

    std::vector<float> v1 = {0, 0, 1};
    std::vector<float> v2 = {-0.5, 0.3, 0};
    std::vector<float> v3 = {0.5, -1.2, 0.7};

    std::cout << "\n\tCross Product test (1)... ";
    std::vector<float> res1 = {-0.3, -0.5, 0};
    bool t1 = run_test(v1, v2, res1);
    results.push_back(t1);

    std::cout << "\n\tCross Product test (2)... ";
    std::vector<float> res2 = {0.21, 0.35, 0.45};
    bool t2 = run_test(v2, v3, res2);
    results.push_back(t2);

    std::cout << "\n\tCross Product test (3)... ";
    std::vector<float> res3 = {-1.2, -0.5, 0};
    bool t3 = run_test(v3, v1, res3);
    results.push_back(t3);

    // std::cout << "\n\tIgnore zeros test... ";
    // std::vector<float> v2 = {9, 7, 5, 3, 1, 0, 2, 4, 6, 8};
    // bool t2 = run_test(v2, 4);
    // results.push_back(t2);

    // std::cout << "\n\tIgnore first zero test... ";
    // std::vector<float> v3 = {0, 0.01, 1, 0.011, 10, 1};
    // bool t3 = run_test(v3, 1);
    // results.push_back(t3);

    // std::cout << "\n\tIgnore first zeros test... ";
    // std::vector<float> v4 = {0, 0, 0, 0.01, 1, 0.011, 10, 1};
    // bool t4 = run_test(v4, 3);
    // results.push_back(t4);

    bool pass = summarize_results(results);
    if (!pass) {
        std::cout << "\nTESTS FAILED :(" << std::endl;
        return -1;
    }

    std::cout << "\nTESTS PASSED! :)" << std::endl;
    return 0;
}
