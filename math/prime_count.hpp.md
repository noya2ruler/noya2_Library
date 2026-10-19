---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/CountingPrimes.test.cpp
    title: test/math/CountingPrimes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/182619
  bundledCode: "#line 2 \"math/prime_count.hpp\"\n\n#include <vector>\n#include <cmath>\n\
    \nnamespace noya2 {\n\n// ref : https://judge.yosupo.jp/submission/182619\n\n\
    // #{p : prime | p <= n}. n <= 10^13\nlong long prime_count(long long n){\n  \
    \  struct S {\n        int rough;\n        long long large;\n        int id;\n\
    \    };\n    if (n <= 1) return 0;\n    const int v = static_cast<int>(sqrtl(n));\n\
    \    int pc = 0;\n    std::vector<int> smalls(v + 1);\n    for (int i = 2; i <=\
    \ v; i++){\n        smalls[i] = (i + 1) / 2;\n    }\n    std::vector<int> skip(v\
    \ + 1, false);\n    std::vector<S> z((v + 1) / 2);\n    for (int i = 0; i < (v\
    \ + 1) / 2; i++){\n        z[i] = {2 * i + 1, (n / (2 * i + 1) + 1) / 2, i};\n\
    \    }\n    for (int p = 3; p <= v; p++){\n        if (smalls[p] <= smalls[p -\
    \ 1]) continue;\n        const int q = p * p;\n        pc++;\n        if (1LL\
    \ * q * q > n) break;\n        skip[p] = true;\n        for (int i = q; i <= v;\
    \ i += 2 * p){\n            skip[i] = true;\n        }\n        int ns = 0;\n\
    \        for (auto e : z){\n            if (skip[e.rough]) continue;\n       \
    \     long long d = 1LL * e.rough * p;\n            e.large += pc - (d <= v ?\
    \ z[smalls[d] - pc].large : smalls[n / d]);\n            e.id = ns;\n        \
    \    z[ns++] = e;\n        }\n        z.resize(ns);\n        for (int j = v /\
    \ p; j >= p; --j){\n            const int c = smalls[j] - pc, e = std::min(j *\
    \ p + p, v + 1);\n            for (int i = j * p; i < e; i++){\n             \
    \   smalls[i] -= c;\n            }\n        }\n    }\n    long long ans = z[0].large;\n\
    \    z.erase(z.begin());\n    for (auto &[rough, large, k] : z){\n        const\
    \ long long m = n / rough;\n        k--;\n        ans -= large - (pc + k);\n \
    \       for (auto [p, _, l] : z){\n            if (l >= k || p * p > m) break;\n\
    \            ans += smalls[m / p] - (pc + l);\n        }\n    }\n    return ans;\n\
    }\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cmath>\n\nnamespace noya2 {\n\
    \n// ref : https://judge.yosupo.jp/submission/182619\n\n// #{p : prime | p <=\
    \ n}. n <= 10^13\nlong long prime_count(long long n){\n    struct S {\n      \
    \  int rough;\n        long long large;\n        int id;\n    };\n    if (n <=\
    \ 1) return 0;\n    const int v = static_cast<int>(sqrtl(n));\n    int pc = 0;\n\
    \    std::vector<int> smalls(v + 1);\n    for (int i = 2; i <= v; i++){\n    \
    \    smalls[i] = (i + 1) / 2;\n    }\n    std::vector<int> skip(v + 1, false);\n\
    \    std::vector<S> z((v + 1) / 2);\n    for (int i = 0; i < (v + 1) / 2; i++){\n\
    \        z[i] = {2 * i + 1, (n / (2 * i + 1) + 1) / 2, i};\n    }\n    for (int\
    \ p = 3; p <= v; p++){\n        if (smalls[p] <= smalls[p - 1]) continue;\n  \
    \      const int q = p * p;\n        pc++;\n        if (1LL * q * q > n) break;\n\
    \        skip[p] = true;\n        for (int i = q; i <= v; i += 2 * p){\n     \
    \       skip[i] = true;\n        }\n        int ns = 0;\n        for (auto e :\
    \ z){\n            if (skip[e.rough]) continue;\n            long long d = 1LL\
    \ * e.rough * p;\n            e.large += pc - (d <= v ? z[smalls[d] - pc].large\
    \ : smalls[n / d]);\n            e.id = ns;\n            z[ns++] = e;\n      \
    \  }\n        z.resize(ns);\n        for (int j = v / p; j >= p; --j){\n     \
    \       const int c = smalls[j] - pc, e = std::min(j * p + p, v + 1);\n      \
    \      for (int i = j * p; i < e; i++){\n                smalls[i] -= c;\n   \
    \         }\n        }\n    }\n    long long ans = z[0].large;\n    z.erase(z.begin());\n\
    \    for (auto &[rough, large, k] : z){\n        const long long m = n / rough;\n\
    \        k--;\n        ans -= large - (pc + k);\n        for (auto [p, _, l] :\
    \ z){\n            if (l >= k || p * p > m) break;\n            ans += smalls[m\
    \ / p] - (pc + l);\n        }\n    }\n    return ans;\n}\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_count.hpp
  requiredBy: []
  timestamp: '2024-10-09 01:31:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/CountingPrimes.test.cpp
documentation_of: math/prime_count.hpp
layout: document
redirect_from:
- /library/math/prime_count.hpp
- /library/math/prime_count.hpp.html
title: math/prime_count.hpp
---
