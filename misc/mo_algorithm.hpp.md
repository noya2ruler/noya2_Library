---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp
  bundledCode: "#line 2 \"misc/mo_algorithm.hpp\"\n\n/*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
    \n*/\n\n#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define\
    \ rep(i,n) for (int i = 0; i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1);\
    \ i >= 0; i--)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing\
    \ ld = long double;\nusing ull = unsigned long long;\n\nusing namespace std;\n\
    \nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace\
    \ noya2;\n\ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a <=\
    \ b) return false;\n    a = b;\n    return true;\n}\ntemplate <typename T> bool\
    \ chmax(T &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n    return\
    \ true;\n}\n\ntemplate<class T>istream &operator>>(istream &is, vector<T> &v){\n\
    \    for (auto &e : v) is >> e;\n    return is;\n}\n\nvoid fast_io(){\n    cin.tie(0);\
    \ ios::sync_with_stdio(0); cout << fixed << setprecision(15);\n}\n\nconst int\
    \ iinf = 1'000'000'007;\nconst ll linf = 2e18;\n#line 10 \"misc/mo_algorithm.hpp\"\
    \n\nnamespace noya2{\n\nstruct Mo {\n    int width;\n    std::vector<int> left,\
    \ right, order;\n\n    Mo(int N = 1, int Q = 1): order(Q) {\n        width = std::max<int>(1,\
    \ 1.0 * N / std::max<double>(1.0, std::sqrt(Q * 2.0 / 3.0)));\n        std::iota(begin(order),\
    \ end(order), 0);\n    }\n\n    void insert(int l, int r) { /* [l, r) */\n   \
    \     left.emplace_back(l);\n        right.emplace_back(r);\n    }\n\n    template\
    \ <typename AL, typename AR, typename DL, typename DR, typename REM>\n    void\
    \ run(const AL& add_left, const AR& add_right, const DL& delete_left,\n      \
    \  const DR& delete_right, const REM& rem) {\n        assert(left.size() == order.size());\n\
    \        sort(begin(order), end(order), [&](int a, int b) {\n            int ablock\
    \ = left[a] / width, bblock = left[b] / width;\n            if (ablock != bblock)\
    \ return ablock < bblock;\n            if (ablock & 1) return right[a] < right[b];\n\
    \            return right[a] > right[b];\n            });\n        int nl = 0,\
    \ nr = 0;\n        for (auto idx : order) {\n            while (nl > left[idx])\
    \ add_left(--nl);\n            while (nr < right[idx]) add_right(nr++);\n    \
    \        while (nl < left[idx]) delete_left(nl++);\n            while (nr > right[idx])\
    \ delete_right(--nr);\n            rem(idx);\n        }\n    }\n};\n\n}\n"
  code: "#pragma once\n\n/*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
    \n*/\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\nstruct Mo\
    \ {\n    int width;\n    std::vector<int> left, right, order;\n\n    Mo(int N\
    \ = 1, int Q = 1): order(Q) {\n        width = std::max<int>(1, 1.0 * N / std::max<double>(1.0,\
    \ std::sqrt(Q * 2.0 / 3.0)));\n        std::iota(begin(order), end(order), 0);\n\
    \    }\n\n    void insert(int l, int r) { /* [l, r) */\n        left.emplace_back(l);\n\
    \        right.emplace_back(r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename DL, typename DR, typename REM>\n    void run(const AL& add_left,\
    \ const AR& add_right, const DL& delete_left,\n        const DR& delete_right,\
    \ const REM& rem) {\n        assert(left.size() == order.size());\n        sort(begin(order),\
    \ end(order), [&](int a, int b) {\n            int ablock = left[a] / width, bblock\
    \ = left[b] / width;\n            if (ablock != bblock) return ablock < bblock;\n\
    \            if (ablock & 1) return right[a] < right[b];\n            return right[a]\
    \ > right[b];\n            });\n        int nl = 0, nr = 0;\n        for (auto\
    \ idx : order) {\n            while (nl > left[idx]) add_left(--nl);\n       \
    \     while (nr < right[idx]) add_right(nr++);\n            while (nl < left[idx])\
    \ delete_left(nl++);\n            while (nr > right[idx]) delete_right(--nr);\n\
    \            rem(idx);\n        }\n    }\n};\n\n}\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: misc/mo_algorithm.hpp
  requiredBy: []
  timestamp: '2023-06-30 12:42:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/mo_algorithm.hpp
layout: document
redirect_from:
- /library/misc/mo_algorithm.hpp
- /library/misc/mo_algorithm.hpp.html
title: misc/mo_algorithm.hpp
---
