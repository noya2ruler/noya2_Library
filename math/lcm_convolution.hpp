#pragma once

#include <vector>
#include <cassert>

#include"../math/sieve.hpp"

namespace noya2 {

template <typename T>
std::vector<T> divisor_zeta_transform(const std::vector<T> &f){
    int n = f.size() - 1;
    reserve_sieve(n);
    auto F = f;
    for (const auto &p : sieve.primes){
        if (n < p) break;
        for (int i = 1; i * p <= n; i++) F[i * p] += F[i];
    }
    return F;
}

template <typename  T>
std::vector<T> divisor_mobius_transform(const std::vector<T> &F){
    int n = F.size() - 1;
    reserve_sieve(n);
    auto f = F;
    for (const auto &p : sieve.primes){
        if (n < p) break;
        for (int i = n / p; i >= 1; i--) f[i * p] -= f[i];
    }
    return f;
}

template <typename T>
std::vector<T> lcm_convolution(const std::vector<T> &a, const std::vector<T> &b){
    assert(a.size() == b.size());
    int n = a.size();
    auto ra = divisor_zeta_transform(a);
    auto rb = divisor_zeta_transform(b);
    for (int i = 0; i < n; i++) ra[i] *= rb[i];
    return divisor_mobius_transform(ra);
}

} // namespace noya2