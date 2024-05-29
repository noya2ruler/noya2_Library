#pragma once

#include "fps998244353.hpp"

namespace noya2 {

fps998244353 product_1_minus_x_pow_a(const std::vector<int> &a, int d){
    std::vector<int> cnt(d, 0);
    for (auto x : a){
        if (x < d){
            cnt[x]++;
        }
    }
    fps998244353 log_f(d);
    if (cnt[0] > 0){
        return log_f;
    }
    if (a.empty()){
        if (d > 0) {
            log_f[0] = 1;
        }
        return log_f;
    }
    for (int x = 1; x < d; x++){
        for (int i = 1; x * i < d; i++){
            log_f[x*i] -= cnt[x] * binomial<modint998244353>::inv(i);
        }
    }
    return log_f.exp(d);
}

} // nasmespace noya2