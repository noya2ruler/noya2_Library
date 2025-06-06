#pragma once

/*

usage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp

*/

#include"../template/template.hpp"

namespace noya2{

struct Mo {
    int width;
    std::vector<int> left, right, order;

    Mo(int N = 1, int Q = 1): order(Q) {
        width = std::max<int>(1, 1.0 * N / std::max<double>(1.0, std::sqrt(Q * 2.0 / 3.0)));
        std::iota(begin(order), end(order), 0);
        left.reserve(Q);
        right.reserve(Q);
    }

    void insert(int l, int r) { /* [l, r) */
        left.emplace_back(l);
        right.emplace_back(r);
    }

    template <typename AL, typename AR, typename DL, typename DR, typename REM>
    void run(const AL& add_left, const AR& add_right, const DL& delete_left,
        const DR& delete_right, const REM& rem) {
        assert(left.size() == order.size());
        sort(begin(order), end(order), [&](int a, int b) {
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

}
