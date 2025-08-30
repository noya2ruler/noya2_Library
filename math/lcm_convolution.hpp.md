---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/sieve.hpp
    title: math/sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Lcm_Convolution.test.cpp
    title: test/math/Lcm_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/lcm_convolution.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\n#line 2 \"math/sieve.hpp\"\n\n#line 5 \"math/sieve.hpp\"\n#include\
    \ <utility>\n\nnamespace noya2{\n\nstruct prime_sieve {\n    static std::vector<int>\
    \ primes, factor, mu;\n    prime_sieve (int n = 1024){\n        build(n);\n  \
    \  }\n    static void reserve(int n){\n        int sz = size();\n        if (sz\
    \ == 0){\n            build(n);\n            return ;\n        }\n        if (n\
    \ <= sz) return ;\n        while (sz < n) sz <<= 1;\n        build(sz);\n    }\n\
    \    // n in [1, size()] is available\n    static int size(){\n        return\
    \ (int)factor.size() - 1;\n    }\n  private:\n    static void build(int n){\n\
    \        primes.clear();\n        factor.assign(n + 1, 0);\n        mu.assign(n\
    \ + 1, 1);\n        for (int x = 2; x <= n; x++){\n            if (factor[x] ==\
    \ 0){\n                primes.emplace_back(x);\n                factor[x] = x;\n\
    \                mu[x] = -1;\n            }\n            for (int p : primes){\n\
    \                if (x * p > n || p > factor[x]) break;\n                factor[x\
    \ * p] = p;\n                mu[x * p] = (p == factor[x] ? 0 : -mu[x]);\n    \
    \        }\n        }\n    }\n} sieve;\nstd::vector<int> prime_sieve::primes;\n\
    std::vector<int> prime_sieve::factor;\nstd::vector<int> prime_sieve::mu;\n\nvoid\
    \ reserve_sieve(int n){\n    sieve.reserve(n);\n}\n\nint mobius_sieve(int n){\n\
    \    assert(1 <= n && n <= sieve.size());\n    return sieve.mu[n];\n}\n\nbool\
    \ is_prime_sieve(int n){\n    if (n <= 2) return n == 2;\n    assert(n <= sieve.size());\n\
    \    return sieve.factor[n] == n;\n}\n\n// pair(prime, exponent)\nstd::vector<std::pair<int,\
    \ int>> factorize_sieve(int n){\n    assert(1 <= n && n <= sieve.size());\n  \
    \  std::vector<std::pair<int, int>> ret;\n    int pre = 0;\n    while (n > 1){\n\
    \        int p = sieve.factor[n];\n        if (pre != p){\n            ret.emplace_back(p,\
    \ 1);\n        }\n        else {\n            ret.back().second += 1;\n      \
    \  }\n        pre = p;\n        n /= p;\n    }\n    return ret;\n}\n\nstd::vector<int>\
    \ divisors_sieve(int n){\n    assert(1 <= n && n <= sieve.size());\n    std::vector<int>\
    \ ret = {1};\n    int pre = 0, w = 1;\n    while (n > 1){\n        int p = sieve.factor[n];\n\
    \        int sz = ret.size();\n        if (pre != p){\n            w = ret.size();\n\
    \        }\n        ret.reserve(sz + w);\n        for (int i = 0; i < w; i++){\n\
    \            ret.emplace_back(ret[sz - w + i] * p);\n        }\n        pre =\
    \ p;\n        n /= p;\n    }\n    return ret;\n}\n\n} // namespace noya2\n#line\
    \ 7 \"math/lcm_convolution.hpp\"\n\nnamespace noya2 {\n\ntemplate <typename T>\n\
    std::vector<T> divisor_zeta_transform(const std::vector<T> &f){\n    int n = f.size()\
    \ - 1;\n    reserve_sieve(n);\n    auto F = f;\n    for (const auto &p : sieve.primes){\n\
    \        if (n < p) break;\n        for (int i = 1; i * p <= n; i++) F[i * p]\
    \ += F[i];\n    }\n    return F;\n}\n\ntemplate <typename  T>\nstd::vector<T>\
    \ divisor_mobius_transform(const std::vector<T> &F){\n    int n = F.size() - 1;\n\
    \    reserve_sieve(n);\n    auto f = F;\n    for (const auto &p : sieve.primes){\n\
    \        if (n < p) break;\n        for (int i = n / p; i >= 1; i--) f[i * p]\
    \ -= f[i];\n    }\n    return f;\n}\n\ntemplate <typename T>\nstd::vector<T> lcm_convolution(const\
    \ std::vector<T> &a, const std::vector<T> &b){\n    assert(a.size() == b.size());\n\
    \    int n = a.size();\n    auto ra = divisor_zeta_transform(a);\n    auto rb\
    \ = divisor_zeta_transform(b);\n    for (int i = 0; i < n; i++) ra[i] *= rb[i];\n\
    \    return divisor_mobius_transform(ra);\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\n#include\"../math/sieve.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate <typename T>\nstd::vector<T> divisor_zeta_transform(const\
    \ std::vector<T> &f){\n    int n = f.size() - 1;\n    reserve_sieve(n);\n    auto\
    \ F = f;\n    for (const auto &p : sieve.primes){\n        if (n < p) break;\n\
    \        for (int i = 1; i * p <= n; i++) F[i * p] += F[i];\n    }\n    return\
    \ F;\n}\n\ntemplate <typename  T>\nstd::vector<T> divisor_mobius_transform(const\
    \ std::vector<T> &F){\n    int n = F.size() - 1;\n    reserve_sieve(n);\n    auto\
    \ f = F;\n    for (const auto &p : sieve.primes){\n        if (n < p) break;\n\
    \        for (int i = n / p; i >= 1; i--) f[i * p] -= f[i];\n    }\n    return\
    \ f;\n}\n\ntemplate <typename T>\nstd::vector<T> lcm_convolution(const std::vector<T>\
    \ &a, const std::vector<T> &b){\n    assert(a.size() == b.size());\n    int n\
    \ = a.size();\n    auto ra = divisor_zeta_transform(a);\n    auto rb = divisor_zeta_transform(b);\n\
    \    for (int i = 0; i < n; i++) ra[i] *= rb[i];\n    return divisor_mobius_transform(ra);\n\
    }\n\n} // namespace noya2"
  dependsOn:
  - math/sieve.hpp
  isVerificationFile: false
  path: math/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2025-08-30 19:37:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Lcm_Convolution.test.cpp
documentation_of: math/lcm_convolution.hpp
layout: document
redirect_from:
- /library/math/lcm_convolution.hpp
- /library/math/lcm_convolution.hpp.html
title: math/lcm_convolution.hpp
---
