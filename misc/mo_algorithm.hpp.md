---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/binomial_prefix_sum.hpp
    title: math/binomial_prefix_sum.hpp
  - icon: ':heavy_check_mark:'
    path: tree/Mo_on_Tree.hpp
    title: Mo on Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Range_Inversions_Query.test.cpp
    title: test/data_structure/Static_Range_Inversions_Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/aoj_0489.test.cpp
    title: test/tree/aoj_0489.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp
  bundledCode: "#line 2 \"misc/mo_algorithm.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    #include <functional>\n#include <cmath>\n#include <numeric>\n\n/*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
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
    \            rem(idx);\n        }\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n#include <functional>\n\
    #include <cmath>\n#include <numeric>\n\n/*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
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
    \            rem(idx);\n        }\n    }\n};\n\n} // namespace noya2\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo_algorithm.hpp
  requiredBy:
  - tree/Mo_on_Tree.hpp
  - math/binomial_prefix_sum.hpp
  timestamp: '2026-01-11 17:16:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/aoj_0489.test.cpp
  - test/data_structure/Static_Range_Inversions_Query.test.cpp
documentation_of: misc/mo_algorithm.hpp
layout: document
redirect_from:
- /library/misc/mo_algorithm.hpp
- /library/misc/mo_algorithm.hpp.html
title: misc/mo_algorithm.hpp
---
