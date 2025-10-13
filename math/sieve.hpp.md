---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/gcd_convolution.hpp
    title: math/gcd_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: math/lcm_convolution.hpp
    title: math/lcm_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Gcd_Convolution.test.cpp
    title: test/math/Gcd_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Lcm_Convolution.test.cpp
    title: test/math/Lcm_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/sieve.hpp\"\n\n#include <vector>\n#include <cassert>\n\
    #include <utility>\n\nnamespace noya2{\n\nstruct prime_sieve {\n    static std::vector<int>\
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
    \ p;\n        n /= p;\n    }\n    return ret;\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n#include <utility>\n\
    \nnamespace noya2{\n\nstruct prime_sieve {\n    static std::vector<int> primes,\
    \ factor, mu;\n    prime_sieve (int n = 1024){\n        build(n);\n    }\n   \
    \ static void reserve(int n){\n        int sz = size();\n        if (sz == 0){\n\
    \            build(n);\n            return ;\n        }\n        if (n <= sz)\
    \ return ;\n        while (sz < n) sz <<= 1;\n        build(sz);\n    }\n    //\
    \ n in [1, size()] is available\n    static int size(){\n        return (int)factor.size()\
    \ - 1;\n    }\n  private:\n    static void build(int n){\n        primes.clear();\n\
    \        factor.assign(n + 1, 0);\n        mu.assign(n + 1, 1);\n        for (int\
    \ x = 2; x <= n; x++){\n            if (factor[x] == 0){\n                primes.emplace_back(x);\n\
    \                factor[x] = x;\n                mu[x] = -1;\n            }\n\
    \            for (int p : primes){\n                if (x * p > n || p > factor[x])\
    \ break;\n                factor[x * p] = p;\n                mu[x * p] = (p ==\
    \ factor[x] ? 0 : -mu[x]);\n            }\n        }\n    }\n} sieve;\nstd::vector<int>\
    \ prime_sieve::primes;\nstd::vector<int> prime_sieve::factor;\nstd::vector<int>\
    \ prime_sieve::mu;\n\nvoid reserve_sieve(int n){\n    sieve.reserve(n);\n}\n\n\
    int mobius_sieve(int n){\n    assert(1 <= n && n <= sieve.size());\n    return\
    \ sieve.mu[n];\n}\n\nbool is_prime_sieve(int n){\n    if (n <= 2) return n ==\
    \ 2;\n    assert(n <= sieve.size());\n    return sieve.factor[n] == n;\n}\n\n\
    // pair(prime, exponent)\nstd::vector<std::pair<int, int>> factorize_sieve(int\
    \ n){\n    assert(1 <= n && n <= sieve.size());\n    std::vector<std::pair<int,\
    \ int>> ret;\n    int pre = 0;\n    while (n > 1){\n        int p = sieve.factor[n];\n\
    \        if (pre != p){\n            ret.emplace_back(p, 1);\n        }\n    \
    \    else {\n            ret.back().second += 1;\n        }\n        pre = p;\n\
    \        n /= p;\n    }\n    return ret;\n}\n\nstd::vector<int> divisors_sieve(int\
    \ n){\n    assert(1 <= n && n <= sieve.size());\n    std::vector<int> ret = {1};\n\
    \    int pre = 0, w = 1;\n    while (n > 1){\n        int p = sieve.factor[n];\n\
    \        int sz = ret.size();\n        if (pre != p){\n            w = ret.size();\n\
    \        }\n        ret.reserve(sz + w);\n        for (int i = 0; i < w; i++){\n\
    \            ret.emplace_back(ret[sz - w + i] * p);\n        }\n        pre =\
    \ p;\n        n /= p;\n    }\n    return ret;\n}\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: math/sieve.hpp
  requiredBy:
  - math/gcd_convolution.hpp
  - math/lcm_convolution.hpp
  timestamp: '2025-08-30 19:37:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Lcm_Convolution.test.cpp
  - test/math/Gcd_Convolution.test.cpp
documentation_of: math/sieve.hpp
layout: document
redirect_from:
- /library/math/sieve.hpp
- /library/math/sieve.hpp.html
title: math/sieve.hpp
---
