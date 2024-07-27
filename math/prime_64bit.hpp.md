---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/PrimitiveRoot.test.cpp
    title: test/math/PrimitiveRoot.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime_64bit.hpp\"\n\n#include <type_traits>\n#include\
    \ <utility>\n#include <algorithm>\n#line 2 \"math/factorize.hpp\"\n\n#include\
    \ <stddef.h>\n#include <stdint.h>\n#line 6 \"math/factorize.hpp\"\n#include <initializer_list>\n\
    #include <iostream>\n#include <vector>\n#line 10 \"math/factorize.hpp\"\n\nnamespace\
    \ fast_factorize {\n\n/*\n    See : https://judge.yosupo.jp/submission/189742\n\
    */\n\n// ---- gcd ----\n\nuint64_t gcd_stein_impl( uint64_t x, uint64_t y ) {\n\
    \    if( x == y ) { return x; }\n    const uint64_t a = y - x;\n    const uint64_t\
    \ b = x - y;\n    const int n = __builtin_ctzll( b );\n    const uint64_t s =\
    \ x < y ? a : b;\n    const uint64_t t = x < y ? x : y;\n    return gcd_stein_impl(\
    \ s >> n, t );\n}\n\nuint64_t gcd_stein( uint64_t x, uint64_t y ) {\n    if( x\
    \ == 0 ) { return y; }\n    if( y == 0 ) { return x; }\n    const int n = __builtin_ctzll(\
    \ x );\n    const int m = __builtin_ctzll( y );\n    return gcd_stein_impl( x\
    \ >> n, y >> m ) << ( n < m ? n : m );\n}\n\n// ---- is_prime ----\n\nuint64_t\
    \ mod_pow( uint64_t x, uint64_t y, uint64_t mod ) {\n    uint64_t ret = 1;\n \
    \   uint64_t acc = x;\n    for( ; y; y >>= 1 ) {\n        if( y & 1 ) {\n    \
    \        ret = __uint128_t(ret) * acc % mod;\n        }\n        acc = __uint128_t(acc)\
    \ * acc % mod;\n    }\n    return ret;\n}\n\nbool miller_rabin( uint64_t n, const\
    \ std::initializer_list<uint64_t>& as ) {\n    return std::all_of( as.begin(),\
    \ as.end(), [n]( uint64_t a ) {\n        if( n <= a ) { return true; }\n\n   \
    \     int e = __builtin_ctzll( n - 1 );\n        uint64_t z = mod_pow( a, ( n\
    \ - 1 ) >> e, n );\n        if( z == 1 || z == n - 1 ) { return true; }\n\n  \
    \      while( --e ) {\n            z = __uint128_t(z) * z % n;\n            if(\
    \ z == 1 ) { return false; }\n            if( z == n - 1 ) { return true; }\n\
    \        }\n\n        return false;\n    });\n}\n\nbool is_prime( uint64_t n )\
    \ {\n    if( n == 2 ) { return true; }\n    if( n % 2 == 0 ) { return false; }\n\
    \    if( n < 4759123141 ) { return miller_rabin( n, { 2, 7, 61 } ); }\n    return\
    \ miller_rabin( n, { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 } );\n}\n\
    \n// ---- Montgomery ----\n\nclass Montgomery {\n    uint64_t mod;\n    uint64_t\
    \ R;\npublic:\n    Montgomery( uint64_t n ) : mod(n), R(n) {\n       for( size_t\
    \ i = 0; i < 5; ++i ) {\n          R *= 2 - mod * R;\n       }\n    }\n\n    uint64_t\
    \ fma( uint64_t a, uint64_t b, uint64_t c ) const {\n        const __uint128_t\
    \ d = __uint128_t(a) * b;\n        const uint64_t    e = c + mod + ( d >> 64 );\n\
    \        const uint64_t    f = uint64_t(d) * R;\n        const uint64_t    g =\
    \ ( __uint128_t(f) * mod ) >> 64;\n        return e - g;\n    }\n\n    uint64_t\
    \ mul( uint64_t a, uint64_t b ) const {\n        return fma( a, b, 0 );\n    }\n\
    };\n\n// ---- Pollard's rho algorithm ----\n\nuint64_t pollard_rho( uint64_t n\
    \ ) {\n    if( n % 2 == 0 ) { return 2; }\n    const Montgomery m( n );\n\n  \
    \  constexpr uint64_t C1 = 1;\n    constexpr uint64_t C2 = 2;\n    constexpr uint64_t\
    \ M = 512;\n\n    uint64_t Z1 = 1;\n    uint64_t Z2 = 2;\nretry:\n    uint64_t\
    \ z1 = Z1;\n    uint64_t z2 = Z2;\n    for( size_t k = M; ; k *= 2 ) {\n     \
    \   const uint64_t x1 = z1 + n;\n        const uint64_t x2 = z2 + n;\n       \
    \ for( size_t j = 0; j < k; j += M ) {\n            const uint64_t y1 = z1;\n\
    \            const uint64_t y2 = z2;\n\n            uint64_t q1 = 1;\n       \
    \     uint64_t q2 = 2;\n            z1 = m.fma( z1, z1, C1 );\n            z2\
    \ = m.fma( z2, z2, C2 );\n            for( size_t i = 0; i < M; ++i ) {\n    \
    \            const uint64_t t1 = x1 - z1;\n                const uint64_t t2 =\
    \ x2 - z2;\n                z1 = m.fma( z1, z1, C1 );\n                z2 = m.fma(\
    \ z2, z2, C2 );\n                q1 = m.mul( q1, t1 );\n                q2 = m.mul(\
    \ q2, t2 );\n            }\n            q1 = m.mul( q1, x1 - z1 );\n         \
    \   q2 = m.mul( q2, x2 - z2 );\n\n            const uint64_t q3 = m.mul( q1, q2\
    \ );\n            const uint64_t g3 = gcd_stein( n, q3 );\n            if( g3\
    \ == 1 ) { continue; }\n            if( g3 != n ) { return g3; }\n\n         \
    \   const uint64_t g1 = gcd_stein( n, q1 );\n            const uint64_t g2 = gcd_stein(\
    \ n, q2 );\n\n            const uint64_t C = g1 != 1 ? C1 : C2;\n            const\
    \ uint64_t x = g1 != 1 ? x1 : x2;\n            uint64_t       z = g1 != 1 ? y1\
    \ : y2;\n            uint64_t       g = g1 != 1 ? g1 : g2;\n\n            if(\
    \ g == n ) {\n                do {\n                    z = m.fma( z, z, C );\n\
    \                    g = gcd_stein( n, x - z );\n                } while( g ==\
    \ 1 );\n            }\n            if( g != n ) {\n                return g;\n\
    \            }\n\n            Z1 += 2;\n            Z2 += 2;\n            goto\
    \ retry;\n        }\n    }\n}\n\nvoid factorize_impl( uint64_t n, std::vector<uint64_t>&\
    \ ret ) {\n    if( n <= 1 ) { return; }\n    if( is_prime( n ) ) { ret.push_back(\
    \ n ); return; }\n\n    const uint64_t p = pollard_rho( n );\n\n    factorize_impl(\
    \ p, ret );\n    factorize_impl( n / p, ret );\n}\n\nstd::vector<uint64_t> factorize(\
    \ uint64_t n ) {\n    std::vector<uint64_t> ret;\n    factorize_impl( n, ret );\n\
    \    std::sort( ret.begin(), ret.end() );\n    return ret;\n}\n\n} // namespace\
    \ fast_factorize\n\nnamespace noya2 {\n\nstd::vector<std::pair<long long, int>>\
    \ factorize(long long n){\n    std::vector<std::pair<long long, int>> ans;\n \
    \   auto ps = fast_factorize::factorize(n);\n    int sz = ps.size();\n    for\
    \ (int l = 0, r = 0; l < sz; l = r){\n        while (r < sz && ps[l] == ps[r])\
    \ r++;\n        ans.emplace_back(ps[l], r-l);\n    }\n    return ans;\n}\n\nstd::vector<long\
    \ long> divisors(long long n){\n    auto ps = fast_factorize::factorize(n);\n\
    \    int sz = ps.size();\n    std::vector<long long> ans = {1};\n    for (int\
    \ l = 0, r = 0; l < sz; l = r){\n        while (r < sz && ps[l] == ps[r]) r++;\n\
    \        int e = r - l;\n        int len = ans.size();\n        ans.reserve(len*(e+1));\n\
    \        long long mul = ps[l];\n        while (true){\n            for (int i\
    \ = 0; i < len; i++){\n                ans.emplace_back(ans[i]*mul);\n       \
    \     }\n            if (--e == 0) break;\n            mul *= ps[l];\n       \
    \ }\n    }\n    return ans;\n}\n\nstd::vector<long long> divisors(const std::vector<std::pair<long\
    \ long, int>> &pes){\n    std::vector<long long> ans = {1};\n    for (auto [p,\
    \ e] : pes){\n        int len = ans.size();\n        ans.reserve(len*(e+1));\n\
    \        long long mul = p;\n        while (true){\n            for (int i = 0;\
    \ i < len; i++){\n                ans.emplace_back(ans[i]*mul);\n            }\n\
    \            if (--e == 0) break;\n            mul *= p;\n        }\n    }\n \
    \   return ans;\n}\n\n} // namespace noya2\n#line 7 \"math/prime_64bit.hpp\"\n\
    \nnamespace noya2::internal64bit {\n\ntemplate<typename T>\nconstexpr T safe_mod(T\
    \ a, T p){\n    a %= p;\n    if constexpr (std::is_signed_v<T> || std::is_same_v<T,\
    \ __int128_t>){\n        if (a < 0) a += p;\n    }\n    return a;\n}\n\ntemplate<typename\
    \ T, typename U>\nconstexpr T pow_mod_constexpr(T x, U n, T p){\n    if (p ==\
    \ 1) return 0;\n    x = safe_mod(x, p);\n    T ret = 1;\n    while (n != 0){\n\
    \        if (n % 2 == 1){\n            ret = U(ret) * x % p;\n        }\n    \
    \    x = U(x) * x % p;\n        n /= 2;\n    }\n    return ret;\n}\n\n// return\
    \ {g, y}\n//   g = gcd(x, p), y * x == 1 (mod p/g)\ntemplate<typename T>\nconstexpr\
    \ std::pair<T, T> inv_gcd(T x, T p){\n    x = safe_mod(x, p);\n    if (x == 0)\
    \ return {p, 0};\n    T s = p, t = x;\n    T m0 = 0, m1 = 1;\n    while (t !=\
    \ 0){\n        T q = s / t;\n        s -= t * q;\n        m0 -= m1 * q;\n    \
    \    std::swap(s, t);\n        std::swap(m0, m1);\n    }\n    if (m0 < 0) m0 +=\
    \ p / s;\n    return {s, m0};\n}\n\n// p must be prime\nlong long primitive_root_ll(long\
    \ long p){\n    if (p == 2) return 1;\n    auto fs = fast_factorize::factorize(p\
    \ - 1);\n    fs.erase(std::unique(fs.begin(), fs.end()), fs.end());\n    for (long\
    \ long g = 2; ; g++){\n        bool ok = true;\n        for (auto &f : fs){\n\
    \            if (pow_mod_constexpr<long long, __int128_t>(g, (p - 1) / f, p) ==\
    \ 1){\n                ok = false;\n                break;\n            }\n  \
    \      }\n        if (ok) return g;\n    }\n    exit(1);\n}\n\n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include <type_traits>\n#include <utility>\n#include <algorithm>\n\
    #include \"factorize.hpp\"\n\nnamespace noya2::internal64bit {\n\ntemplate<typename\
    \ T>\nconstexpr T safe_mod(T a, T p){\n    a %= p;\n    if constexpr (std::is_signed_v<T>\
    \ || std::is_same_v<T, __int128_t>){\n        if (a < 0) a += p;\n    }\n    return\
    \ a;\n}\n\ntemplate<typename T, typename U>\nconstexpr T pow_mod_constexpr(T x,\
    \ U n, T p){\n    if (p == 1) return 0;\n    x = safe_mod(x, p);\n    T ret =\
    \ 1;\n    while (n != 0){\n        if (n % 2 == 1){\n            ret = U(ret)\
    \ * x % p;\n        }\n        x = U(x) * x % p;\n        n /= 2;\n    }\n   \
    \ return ret;\n}\n\n// return {g, y}\n//   g = gcd(x, p), y * x == 1 (mod p/g)\n\
    template<typename T>\nconstexpr std::pair<T, T> inv_gcd(T x, T p){\n    x = safe_mod(x,\
    \ p);\n    if (x == 0) return {p, 0};\n    T s = p, t = x;\n    T m0 = 0, m1 =\
    \ 1;\n    while (t != 0){\n        T q = s / t;\n        s -= t * q;\n       \
    \ m0 -= m1 * q;\n        std::swap(s, t);\n        std::swap(m0, m1);\n    }\n\
    \    if (m0 < 0) m0 += p / s;\n    return {s, m0};\n}\n\n// p must be prime\n\
    long long primitive_root_ll(long long p){\n    if (p == 2) return 1;\n    auto\
    \ fs = fast_factorize::factorize(p - 1);\n    fs.erase(std::unique(fs.begin(),\
    \ fs.end()), fs.end());\n    for (long long g = 2; ; g++){\n        bool ok =\
    \ true;\n        for (auto &f : fs){\n            if (pow_mod_constexpr<long long,\
    \ __int128_t>(g, (p - 1) / f, p) == 1){\n                ok = false;\n       \
    \         break;\n            }\n        }\n        if (ok) return g;\n    }\n\
    \    exit(1);\n}\n\n} // namespace noya2"
  dependsOn:
  - math/factorize.hpp
  isVerificationFile: false
  path: math/prime_64bit.hpp
  requiredBy: []
  timestamp: '2024-07-03 00:53:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/PrimitiveRoot.test.cpp
documentation_of: math/prime_64bit.hpp
layout: document
redirect_from:
- /library/math/prime_64bit.hpp
- /library/math/prime_64bit.hpp.html
title: math/prime_64bit.hpp
---