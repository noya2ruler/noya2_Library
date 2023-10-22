#pragma once

#include"../math/sieve.hpp"

namespace noya2 {

template<typename T>
vector<T> multiple_zeta_transform(const vector<T> &f){
    int n = f.size() - 1;
    sieve.request(n);
    auto F = f;
    for (const auto &p : sieve.primes){
        if (n < p) break;
        for (int i = n / p; i >= 1; i--) F[i] += F[i * p];
    }
    return F;
}

template<typename T>
vector<T> multiple_mobius_transform(const vector<T> &F){
    int n = F.size() - 1;
    sieve.request(n);
    auto f = F;
    for (const auto &p : sieve.primes){
        if (n < p) break;
        for (int i = 1; i * p <= n; i++) f[i] -= f[i * p];
    }
    return f;
}

template<typename T>
vector<T> gcd_convolution(const vector<T> &a, const vector<T> &b){
    assert(a.size() == b.size());
    int n = a.size();
    auto ra = multiple_zeta_transform(a);
    auto rb = multiple_zeta_transform(b);
    for (int i = 0; i < n; i++) ra[i] *= rb[i];
    return multiple_mobius_transform(ra);
}

} // namespace noya2