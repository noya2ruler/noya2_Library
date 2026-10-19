---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: math/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/binomial_prefix_sum.hpp\"\n\n#line 2 \"math/binomial.hpp\"\
    \n\n#include<vector>\nnamespace noya2 {\n\ntemplate<typename mint>\nstruct binomial\
    \ {\n    binomial(int len = 300000){ extend(len); }\n    static mint fact(int\
    \ n){\n        if (n < 0) return 0;\n        while (n >= (int)_fact.size()) extend();\n\
    \        return _fact[n];\n    }\n    static mint ifact(int n){\n        if (n\
    \ < 0) return 0;\n        while (n >= (int)_fact.size()) extend();\n        return\
    \ _ifact[n];\n    }\n    static mint inv(int n){\n        return ifact(n) * fact(n-1);\n\
    \    }\n    static mint C(int n, int r){\n        if (!(0 <= r && r <= n)) return\
    \ 0;\n        return fact(n) * ifact(r) * ifact(n-r);\n    }\n    static mint\
    \ P(int n, int r){\n        if (!(0 <= r && r <= n)) return 0;\n        return\
    \ fact(n) * ifact(n-r);\n    }\n    static mint catalan(int n){\n        return\
    \ C(n * 2, n) * inv(n + 1);\n    }\n    inline mint operator()(int n, int r) {\
    \ return C(n, r); }\n    template<class... Cnts>\n    static mint M(const Cnts&...\
    \ cnts){\n        return multinomial(0,1,cnts...);\n    }\n    static void initialize(int\
    \ len = 2){\n        _fact.clear();\n        _ifact.clear();\n        _fact =\
    \ {1,1};\n        _ifact = {1,1};\n        extend(len);\n    }\n  private:\n \
    \   static mint multinomial(const int& sum, const mint& div_prod){\n        if\
    \ (sum < 0) return 0;\n        return fact(sum) * div_prod;\n    }\n    template<class...\
    \ Tail>\n    static mint multinomial(const int& sum, const mint& div_prod, const\
    \ int& n1, const Tail&... tail){\n        if (n1 < 0) return 0;\n        return\
    \ multinomial(sum+n1,div_prod*ifact(n1),tail...);\n    }\n    static std::vector<mint>\
    \ _fact, _ifact;\n    static void extend(int len = -1){\n        int siz = _fact.size();\n\
    \        if (siz == 0){\n            _fact = {1,1};\n            _ifact = {1,1};\n\
    \            siz = _fact.size();\n        }\n        if (len == -1) len = siz\
    \ * 2;\n        len = (int)min<long long>(len, mint::mod() - 1);\n        if (len\
    \ < siz) return ;\n        _fact.resize(len+1), _ifact.resize(len+1);\n      \
    \  for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1] * i;\n        assert(_fact[len].val()\
    \ != 0);\n        _ifact[len] = _fact[len].inv();\n        for (int i = len; i\
    \ > siz; i--) _ifact[i-1] = _ifact[i] * i;\n    }\n};\ntemplate<typename mint>\
    \ std::vector<mint> noya2::binomial<mint>::_fact = {1,1};\ntemplate<typename mint>\
    \ std::vector<mint> noya2::binomial<mint>::_ifact = {1,1};\n\n} // namespace noya2\n\
    #line 2 \"misc/mo_algorithm.hpp\"\n\n#line 4 \"misc/mo_algorithm.hpp\"\n#include\
    \ <algorithm>\n#include <functional>\n#include <cmath>\n#include <numeric>\n\n\
    /*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
    \n*/\n\nnamespace noya2{\n\nstruct mo_algorithm {\n    int width;\n    std::vector<int>\
    \ left, right, order;\n\n    mo_algorithm (int n = 1, int q = 1): order(q) {\n\
    \        width = std::max<int>(1, 1.0 * n / std::max<double>(1.0, std::sqrt(q\
    \ * 2.0 / 3.0)));\n        std::iota(begin(order), end(order), 0);\n        left.reserve(q);\n\
    \        right.reserve(q);\n    }\n\n    void insert(int l, int r) { /* [l, r)\
    \ */\n        left.emplace_back(l);\n        right.emplace_back(r);\n    }\n\n\
    \    void run(auto add_left, auto add_right, auto delete_left, auto delete_right,\
    \ auto rem){\n        assert(left.size() == order.size());\n        std::sort(begin(order),\
    \ end(order), [&](int a, int b) {\n            int ablock = left[a] / width, bblock\
    \ = left[b] / width;\n            if (ablock != bblock) return ablock < bblock;\n\
    \            if (ablock & 1) return right[a] < right[b];\n            return right[a]\
    \ > right[b];\n            });\n        int nl = 0, nr = 0;\n        for (auto\
    \ idx : order) {\n            while (nl > left[idx]) add_left(--nl);\n       \
    \     while (nr < right[idx]) add_right(nr++);\n            while (nl < left[idx])\
    \ delete_left(nl++);\n            while (nr > right[idx]) delete_right(--nr);\n\
    \            rem(idx);\n        }\n    }\n};\n\n} // namespace noya2\n#line 5\
    \ \"math/binomial_prefix_sum.hpp\"\n\nnamespace noya2 {\n\ntemplate<typename mint>\n\
    struct binomial_prefix_sum {\n    int m;\n    std::vector<mint> table;\n    binomial<mint>\
    \ binom;\n    binomial_prefix_sum() {}\n    binomial_prefix_sum(int nmax){\n \
    \       m = sqrt(nmax) + 1;\n        table.resize(m * m);\n        // 0 <= i,\
    \ j < m\n        // table[i * m + j] = sum_{k in [0, j * m + m)} binom{i * m +\
    \ m}{k}\n        for (int i = 0; i < m; i++){\n            mint sum = 0;\n   \
    \         int n = i * m + m;\n            int j = 0;\n            for (int k =\
    \ 0; k <= n; k++){\n                sum += binom(n, k);\n                if ((k\
    \ + 1) % m == 0){\n                    assert(k + 1 == j * m + m);\n         \
    \           table[i * m + j] = sum;\n                    j++;\n              \
    \  }\n            }\n            // for ( ; j < m; j++){\n            //     table[i\
    \ * m + j] = sum;\n            // }\n        }\n    }\n    // sum_{i in [0, k)}\
    \ binom{n}{i}\n    mint operator()(int n, int k){\n        if (k <= 0){\n    \
    \        return 0;\n        }\n        if (k >= n+1){\n            return mint(2).pow(n);\n\
    \        }\n        if (k < m){\n            mint ans = 0;\n            for (int\
    \ i = 0; i < k; i++){\n                ans += binom(n, i);\n            }\n  \
    \          return ans;\n        }\n        // n >= k >= m\n        int i = (n\
    \ - m) / m;\n        int j = (k - m) / m;\n        mint ans = table[i * m + j];\n\
    \        int nn = i * m + m, kk = j * m + m;\n        while (nn < n){\n      \
    \      ans *= 2;\n            ans -= binom(nn, kk - 1);\n            nn++;\n \
    \       }\n        while (kk < k){\n            ans += binom(n, kk);\n       \
    \     kk++;\n        }\n        return ans;\n    }\n};\n\n// for nks[i] = {n,\
    \ k}, ret[i] = \\sum_{i in [0, k)} binom{n}{i}\ntemplate<typename mint>\nstd::vector<mint>\
    \ multipoint_binomial_prefix_sum(std::vector<std::pair<int, int>> nks){\n    int\
    \ q = nks.size();\n    int mx = 0;\n    for (auto [n, k] : nks){\n        if (mx\
    \ < n) mx = n;\n    }\n    mo_algorithm mo(mx + 1, q);\n    binomial<mint> binom;\n\
    \    for (auto [n, k] : nks){\n        mo.insert(std::clamp(k, 0, n + 1), n);\n\
    \    }\n    int n = 0, k = 0;\n    mint cur = 0;\n    auto addl = [&](int kk){\n\
    \        cur -= binom(n, --k);\n    };\n    auto dell = [&](int kk){\n       \
    \ cur += binom(n, k++);\n    };\n    const mint i2 = mint(2).inv();\n    auto\
    \ delr = [&](int){\n        cur += binom(n - 1, k - 1);\n        cur *= i2;\n\
    \        n--;\n    };\n    auto addr = [&](int){\n        cur *= 2;\n        cur\
    \ -= binom(n, k - 1);\n        n++;\n    };\n    vector<mint> ans(q);\n    auto\
    \ rem = [&](int i){\n        ans[i] = cur;\n    };\n    mo.run(addl, addr, dell,\
    \ delr, rem);\n    return ans;\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"math/binomial.hpp\"\n#include\"misc/mo_algorithm.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<typename mint>\nstruct binomial_prefix_sum {\n\
    \    int m;\n    std::vector<mint> table;\n    binomial<mint> binom;\n    binomial_prefix_sum()\
    \ {}\n    binomial_prefix_sum(int nmax){\n        m = sqrt(nmax) + 1;\n      \
    \  table.resize(m * m);\n        // 0 <= i, j < m\n        // table[i * m + j]\
    \ = sum_{k in [0, j * m + m)} binom{i * m + m}{k}\n        for (int i = 0; i <\
    \ m; i++){\n            mint sum = 0;\n            int n = i * m + m;\n      \
    \      int j = 0;\n            for (int k = 0; k <= n; k++){\n               \
    \ sum += binom(n, k);\n                if ((k + 1) % m == 0){\n              \
    \      assert(k + 1 == j * m + m);\n                    table[i * m + j] = sum;\n\
    \                    j++;\n                }\n            }\n            // for\
    \ ( ; j < m; j++){\n            //     table[i * m + j] = sum;\n            //\
    \ }\n        }\n    }\n    // sum_{i in [0, k)} binom{n}{i}\n    mint operator()(int\
    \ n, int k){\n        if (k <= 0){\n            return 0;\n        }\n       \
    \ if (k >= n+1){\n            return mint(2).pow(n);\n        }\n        if (k\
    \ < m){\n            mint ans = 0;\n            for (int i = 0; i < k; i++){\n\
    \                ans += binom(n, i);\n            }\n            return ans;\n\
    \        }\n        // n >= k >= m\n        int i = (n - m) / m;\n        int\
    \ j = (k - m) / m;\n        mint ans = table[i * m + j];\n        int nn = i *\
    \ m + m, kk = j * m + m;\n        while (nn < n){\n            ans *= 2;\n   \
    \         ans -= binom(nn, kk - 1);\n            nn++;\n        }\n        while\
    \ (kk < k){\n            ans += binom(n, kk);\n            kk++;\n        }\n\
    \        return ans;\n    }\n};\n\n// for nks[i] = {n, k}, ret[i] = \\sum_{i in\
    \ [0, k)} binom{n}{i}\ntemplate<typename mint>\nstd::vector<mint> multipoint_binomial_prefix_sum(std::vector<std::pair<int,\
    \ int>> nks){\n    int q = nks.size();\n    int mx = 0;\n    for (auto [n, k]\
    \ : nks){\n        if (mx < n) mx = n;\n    }\n    mo_algorithm mo(mx + 1, q);\n\
    \    binomial<mint> binom;\n    for (auto [n, k] : nks){\n        mo.insert(std::clamp(k,\
    \ 0, n + 1), n);\n    }\n    int n = 0, k = 0;\n    mint cur = 0;\n    auto addl\
    \ = [&](int kk){\n        cur -= binom(n, --k);\n    };\n    auto dell = [&](int\
    \ kk){\n        cur += binom(n, k++);\n    };\n    const mint i2 = mint(2).inv();\n\
    \    auto delr = [&](int){\n        cur += binom(n - 1, k - 1);\n        cur *=\
    \ i2;\n        n--;\n    };\n    auto addr = [&](int){\n        cur *= 2;\n  \
    \      cur -= binom(n, k - 1);\n        n++;\n    };\n    vector<mint> ans(q);\n\
    \    auto rem = [&](int i){\n        ans[i] = cur;\n    };\n    mo.run(addl, addr,\
    \ dell, delr, rem);\n    return ans;\n}\n\n} // namespace noya2"
  dependsOn:
  - math/binomial.hpp
  - misc/mo_algorithm.hpp
  isVerificationFile: false
  path: math/binomial_prefix_sum.hpp
  requiredBy: []
  timestamp: '2026-06-22 00:51:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/binomial_prefix_sum.hpp
layout: document
redirect_from:
- /library/math/binomial_prefix_sum.hpp
- /library/math/binomial_prefix_sum.hpp.html
title: math/binomial_prefix_sum.hpp
---
