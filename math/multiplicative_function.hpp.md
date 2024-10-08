---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/multiplicative_function.hpp\"\n\n#include <vector>\n\
    #include <cmath>\n#include <cassert>\n\nnamespace noya2 {\n\nstd::vector<int>\
    \ prime_enumerate(int N){\n    std::vector<bool> psieve(N / 3 + 1, true);\n  \
    \  int qe = psieve.size();\n    for (int p = 5, d = 4, i = 1, sqn = std::sqrt(N);\
    \ p <= sqn; p += d = 6 - d, i++){\n        if (!psieve[i]) continue;\n       \
    \ for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p; q < qe;\
    \ q += r = s - r){\n            psieve[q] = false;\n        }\n    }\n    std::vector<int>\
    \ ret = {2, 3};\n    for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++){\n\
    \        if (psieve[i]) ret.emplace_back(p);\n    }\n    while (!ret.empty() &&\
    \ ret.back() > N) ret.pop_back();\n    return ret;\n}\n\nstruct mf_prefix_sum\
    \ {\n    long long M, sq, s;\n    std::vector<int> p;\n    int ps;\n    mf_prefix_sum(long\
    \ long m) : M(m) {\n        assert(m <= 1e15);\n        sq = std::sqrt(M);\n \
    \       while (sq * sq > M) sq--;\n        while ((sq + 1) * (sq + 1) <= M) sq++;\n\
    \        if (m != 0){\n            long long hls = quo(M, sq);\n            while\
    \ (hls != 1 && quo(M, hls - 1) == sq) hls--;\n            s = hls + sq;\n    \
    \    }\n        p = prime_enumerate(sq);\n        ps = p.size();\n    }\n    //\
    \ calc : sum[2 <= prime <= M/i] f(prime)\n    // T f(int prime) : f(prime)\n \
    \   // T sum(long long r) : sum[2 <= x <= r] f(x)\n    // T mul(int prime, T s)\
    \ : sum[x in R] f(prime * x), for s = sum[x in R] f(x), R = { x <= M/i | lpf(x)\
    \ >= prime }\n    template<typename T>\n    std::vector<T> table(auto f, auto\
    \ sum, auto mul) const {\n        if (M == 0) return {};\n        long long hls\
    \ = s - sq;\n        std::vector<T> hl(hls);\n        for (int i = 1; i < hls;\
    \ i++){\n            hl[i] = sum(quo(M, i));\n        }\n        std::vector<T>\
    \ hs(sq + 1);\n        for (int i = 1; i <= sq; i++){\n            hs[i] = sum(i);\n\
    \        }\n        T psum = {};\n        for (auto &x : p){\n            long\
    \ long x2 = (long long)(x) * x;\n            long long imax = std::min<long long>(hls,\
    \ quo(M, x2) + 1);\n            for (long long i = 1, ix = x; i < imax; i++, ix\
    \ += x){\n                hl[i] -= mul(x, (ix < hls ? hl[ix] : hs[quo(M, ix)])\
    \ - psum);\n            }\n            for (int n = sq; n >= x2; n--){\n     \
    \           hs[n] -= mul(x, hs[quo(n, x)] - psum);\n            }\n          \
    \  psum += f(x);\n        }\n        hl.reserve(sq * 2 + 10);\n        for (int\
    \ i = hs.size(); --i; ) hl.push_back(hs[i]);\n        assert((int)(hl.size())\
    \ == s);\n        return hl;\n    }\n    // calc : sum[1 <= x <= M] f(x), f is\
    \ multiplicative\n    // T f(int prime, int e) : f(prime ^ e)\n    template<typename\
    \ T>\n    T run(auto f, const std::vector<T> &Fprime) const {\n        if (M ==\
    \ 0) return {};\n        assert((int)(Fprime.size()) == s);\n        T ans = Fprime[idx(M)]\
    \ + 1; // + 1 : f(1)\n        auto dfs = [&](auto sfs, int i, int c, long long\
    \ prod, T cur) -> void {\n            ans += cur * f(p[i], c + 1);\n         \
    \   long long lim = quo(M, prod);\n            if (lim >= 1LL * p[i] * p[i]){\n\
    \                sfs(sfs, i, c + 1, p[i] * prod, cur);\n            }\n      \
    \      cur *= f(p[i], c);\n            ans += cur * (Fprime[idx(lim)] - Fprime[idx(p[i])]);\n\
    \            int j = i + 1;\n            for (; j < ps && p[j] < (1 << 21) &&\
    \ 1LL * p[j] * p[j] * p[j] <= lim; j++){\n                sfs(sfs, j, 1, prod\
    \ * p[j], cur);\n            }\n            for (; j < ps && 1LL * p[j] * p[j]\
    \ <= lim; j++){\n                T sm = f(p[j], 2);\n                int id1 =\
    \ idx(quo(lim, p[j])), id2 = idx(p[j]);\n                sm += f(p[j], 1) * (Fprime[id1]\
    \ - Fprime[id2]);\n                ans += cur * sm;\n            }\n        };\n\
    \        for (int i = 0; i < ps; i++){\n            dfs(dfs, i, 1, p[i], 1);\n\
    \        }\n        return ans;\n    }\n    long long quo(long long n, long long\
    \ d) const { return n / d; }\n    long long idx(long long n) const { return n\
    \ <= sq ? s - n : quo(M, n); }\n    long long val(long long i) const { return\
    \ i >= s - sq ? s - i : quo(M, i); }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cmath>\n#include <cassert>\n\
    \nnamespace noya2 {\n\nstd::vector<int> prime_enumerate(int N){\n    std::vector<bool>\
    \ psieve(N / 3 + 1, true);\n    int qe = psieve.size();\n    for (int p = 5, d\
    \ = 4, i = 1, sqn = std::sqrt(N); p <= sqn; p += d = 6 - d, i++){\n        if\
    \ (!psieve[i]) continue;\n        for (int q = p * p / 3, r = d * p / 3 + (d *\
    \ p % 3 == 2), s = 2 * p; q < qe; q += r = s - r){\n            psieve[q] = false;\n\
    \        }\n    }\n    std::vector<int> ret = {2, 3};\n    for (int p = 5, d =\
    \ 4, i = 1; p <= N; p += d = 6 - d, i++){\n        if (psieve[i]) ret.emplace_back(p);\n\
    \    }\n    while (!ret.empty() && ret.back() > N) ret.pop_back();\n    return\
    \ ret;\n}\n\nstruct mf_prefix_sum {\n    long long M, sq, s;\n    std::vector<int>\
    \ p;\n    int ps;\n    mf_prefix_sum(long long m) : M(m) {\n        assert(m <=\
    \ 1e15);\n        sq = std::sqrt(M);\n        while (sq * sq > M) sq--;\n    \
    \    while ((sq + 1) * (sq + 1) <= M) sq++;\n        if (m != 0){\n          \
    \  long long hls = quo(M, sq);\n            while (hls != 1 && quo(M, hls - 1)\
    \ == sq) hls--;\n            s = hls + sq;\n        }\n        p = prime_enumerate(sq);\n\
    \        ps = p.size();\n    }\n    // calc : sum[2 <= prime <= M/i] f(prime)\n\
    \    // T f(int prime) : f(prime)\n    // T sum(long long r) : sum[2 <= x <= r]\
    \ f(x)\n    // T mul(int prime, T s) : sum[x in R] f(prime * x), for s = sum[x\
    \ in R] f(x), R = { x <= M/i | lpf(x) >= prime }\n    template<typename T>\n \
    \   std::vector<T> table(auto f, auto sum, auto mul) const {\n        if (M ==\
    \ 0) return {};\n        long long hls = s - sq;\n        std::vector<T> hl(hls);\n\
    \        for (int i = 1; i < hls; i++){\n            hl[i] = sum(quo(M, i));\n\
    \        }\n        std::vector<T> hs(sq + 1);\n        for (int i = 1; i <= sq;\
    \ i++){\n            hs[i] = sum(i);\n        }\n        T psum = {};\n      \
    \  for (auto &x : p){\n            long long x2 = (long long)(x) * x;\n      \
    \      long long imax = std::min<long long>(hls, quo(M, x2) + 1);\n          \
    \  for (long long i = 1, ix = x; i < imax; i++, ix += x){\n                hl[i]\
    \ -= mul(x, (ix < hls ? hl[ix] : hs[quo(M, ix)]) - psum);\n            }\n   \
    \         for (int n = sq; n >= x2; n--){\n                hs[n] -= mul(x, hs[quo(n,\
    \ x)] - psum);\n            }\n            psum += f(x);\n        }\n        hl.reserve(sq\
    \ * 2 + 10);\n        for (int i = hs.size(); --i; ) hl.push_back(hs[i]);\n  \
    \      assert((int)(hl.size()) == s);\n        return hl;\n    }\n    // calc\
    \ : sum[1 <= x <= M] f(x), f is multiplicative\n    // T f(int prime, int e) :\
    \ f(prime ^ e)\n    template<typename T>\n    T run(auto f, const std::vector<T>\
    \ &Fprime) const {\n        if (M == 0) return {};\n        assert((int)(Fprime.size())\
    \ == s);\n        T ans = Fprime[idx(M)] + 1; // + 1 : f(1)\n        auto dfs\
    \ = [&](auto sfs, int i, int c, long long prod, T cur) -> void {\n           \
    \ ans += cur * f(p[i], c + 1);\n            long long lim = quo(M, prod);\n  \
    \          if (lim >= 1LL * p[i] * p[i]){\n                sfs(sfs, i, c + 1,\
    \ p[i] * prod, cur);\n            }\n            cur *= f(p[i], c);\n        \
    \    ans += cur * (Fprime[idx(lim)] - Fprime[idx(p[i])]);\n            int j =\
    \ i + 1;\n            for (; j < ps && p[j] < (1 << 21) && 1LL * p[j] * p[j] *\
    \ p[j] <= lim; j++){\n                sfs(sfs, j, 1, prod * p[j], cur);\n    \
    \        }\n            for (; j < ps && 1LL * p[j] * p[j] <= lim; j++){\n   \
    \             T sm = f(p[j], 2);\n                int id1 = idx(quo(lim, p[j])),\
    \ id2 = idx(p[j]);\n                sm += f(p[j], 1) * (Fprime[id1] - Fprime[id2]);\n\
    \                ans += cur * sm;\n            }\n        };\n        for (int\
    \ i = 0; i < ps; i++){\n            dfs(dfs, i, 1, p[i], 1);\n        }\n    \
    \    return ans;\n    }\n    long long quo(long long n, long long d) const { return\
    \ n / d; }\n    long long idx(long long n) const { return n <= sq ? s - n : quo(M,\
    \ n); }\n    long long val(long long i) const { return i >= s - sq ? s - i : quo(M,\
    \ i); }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: math/multiplicative_function.hpp
  requiredBy: []
  timestamp: '2024-10-09 02:36:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/multiplicative_function.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function.hpp
- /library/math/multiplicative_function.hpp.html
title: math/multiplicative_function.hpp
---
