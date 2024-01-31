#include <iostream>
#include <vector>

void print_vec(const std::vector<float>& v) {
    std::cout << "{";
    for (auto& ele : v) {
        std::cout << ele << " ";
    }
    std::cout << "}";
}

bool summarize_results(const std::vector<bool>& results) {
    int pass = 0;
    int fail = 0;

    for (auto&& ele : results) {
        if (ele) pass++;
        else fail ++;
    }

    std::cout << "\n\nPASSED: " << pass << " / " << results.size() << std::endl;
    std::cout << "FAILED: " << fail << " / " << results.size() << std::endl;

    return fail == 0;
}

bool is_close(std::vector<float>& v1, std::vector<float>& v2, float thresh = 1e-4) {
    if (v1.size() != v2.size()) return false;

    for (int i = 0; i < v1.size(); i++) {
        if (fabs(v1[i] - v2[i]) > thresh) return false;
    }
    return true;
}
