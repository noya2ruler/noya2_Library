#pragma once

#include <type_traits>
#include <utility>
#include <algorithm>
#include "factorize.hpp"

namespace noya2::internal64bit {

template<typename T>
constexpr T safe_mod(T a, T p){
    a %= p;
    if constexpr (std::is_signed_v<T> || std::is_same_v<T, __int128_t>){
        if (a < 0) a += p;
    }
    return a;
}

template<typename T, typename U>
constexpr T pow_mod_constexpr(T x, U n, T p){
    if (p == 1) return 0;
    x = safe_mod(x, p);
    T ret = 1;
    while (n != 0){
        if (n % 2 == 1){
            ret = U(ret) * x % p;
        }
        x = U(x) * x % p;
        n /= 2;
    }
    return ret;
}

// return {g, y}
//   g = gcd(x, p), y * x == 1 (mod p/g)
template<typename T>
constexpr std::pair<T, T> inv_gcd(T x, T p){
    x = safe_mod(x, p);
    if (x == 0) return {p, 0};
    T s = p, t = x;
    T m0 = 0, m1 = 1;
    while (t != 0){
        T q = s / t;
        s -= t * q;
        m0 -= m1 * q;
        std::swap(s, t);
        std::swap(m0, m1);
    }
    if (m0 < 0) m0 += p / s;
    return {s, m0};
}

// p must be prime
long long primitive_root_ll(long long p){
    if (p == 2) return 1;
    auto fs = fast_factorize::factorize(p - 1);
    fs.erase(std::unique(fs.begin(), fs.end()), fs.end());
    for (long long g = 2; ; g++){
        bool ok = true;
        for (auto &f : fs){
            if (pow_mod_constexpr<long long, __int128_t>(g, (p - 1) / f, p) == 1){
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
    exit(1);
}

} // namespace noya2