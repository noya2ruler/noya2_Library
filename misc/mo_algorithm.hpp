#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <numeric>

/*

usage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp

*/

namespace noya2{

struct mo_algorithm {
    int width;
    std::vector<int> left, right, order;

    mo_algorithm (int n = 1, int q = 1): order(q) {
        width = std::max<int>(1, 1.0 * n / std::max<double>(1.0, std::sqrt(q * 2.0 / 3.0)));
        std::iota(begin(order), end(order), 0);
        left.reserve(q);
        right.reserve(q);
    }

    void insert(int l, int r) { /* [l, r) */
        left.emplace_back(l);
        right.emplace_back(r);
    }

    void run(auto add_left, auto add_right, auto delete_left, auto delete_right, auto rem){
        assert(left.size() == order.size());
        std::sort(begin(order), end(order), [&](int a, int b) {
            int ablock = left[a] / width, bblock = left[b] / width;
            if (ablock != bblock) return ablock < bblock;
            if (ablock & 1) return right[a] < right[b];
            return right[a] > right[b];
            });
        int nl = 0, nr = 0;
        for (auto idx : order) {
            while (nl > left[idx]) add_left(--nl);
            while (nr < right[idx]) add_right(nr++);
            while (nl < left[idx]) delete_left(nl++);
            while (nr > right[idx]) delete_right(--nr);
            rem(idx);
        }
    }
};

} // namespace noya2
