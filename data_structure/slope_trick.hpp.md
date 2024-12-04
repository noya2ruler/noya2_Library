---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/yuki_1077.test.cpp
    title: test/data_structure/yuki_1077.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/slope_trick.hpp\"\n\n#include <queue>\n#include\
    \ <limits>\n#include <functional>\n#include <algorithm>\n#include <utility>\n\n\
    namespace noya2{\n\ntemplate< typename T >\nstruct slope_trick {\n \n    static\
    \ constexpr T INF = std::numeric_limits< T >::max() / 3;\n \n    T min_f;\n  \
    \  std::priority_queue<T,std::vector<T>,std::less<>> L;\n    std::priority_queue<T,std::vector<T>,std::greater<>>\
    \ R;\n    T add_l, add_r;\n \n    void push_R(const T& a) {\n        R.push(a\
    \ - add_r);\n    }\n \n    T top_R() const {\n        if (R.empty()) return INF;\n\
    \        else return R.top() + add_r;\n    }\n \n    T pop_R() {\n        T val\
    \ = top_R();\n        if (!R.empty()) R.pop();\n        return val;\n    }\n \n\
    \    void push_L(const T& a) {\n        L.push(a - add_l);\n    }\n \n    T top_L()\
    \ const {\n        if (L.empty()) return -INF;\n        else return L.top() +\
    \ add_l;\n    }\n \n    T pop_L() {\n        T val = top_L();\n        if (!L.empty())\
    \ L.pop();\n        return val;\n    }\n \n    size_t size() {\n        return\
    \ L.size() + R.size();\n    }\n \n    slope_trick() : min_f(0), add_l(0), add_r(0)\
    \ {}\n\n    T min() const {\n        return min_f;\n    }\n    \n    std::pair<T,\
    \ T> argmin() const {\n        return {top_L(), top_R()};\n    }\n \n    // f(x)\
    \ += a\n    void add_all(const T& a) {\n        min_f += a;\n    }\n \n    //\
    \ add \\_\n    // f(x) += max(a - x, 0)\n    void add_a_minus_x(const T& a) {\n\
    \        min_f += std::max(T(0), a - top_R());\n        push_R(a);\n        push_L(pop_R());\n\
    \    }\n \n    // add _/\n    // f(x) += max(x - a, 0)\n    void add_x_minus_a(const\
    \ T& a) {\n        min_f += std::max(T(0), top_L() - a);\n        push_L(a);\n\
    \        push_R(pop_L());\n    }\n \n    // add \\/\n    // f(x) += abs(x - a)\n\
    \    void add_abs(const T& a) {\n        add_a_minus_x(a);\n        add_x_minus_a(a);\n\
    \    }\n \n    // \\/ -> \\_\n    // f_{new} (x) = min f(y) (y <= x)\n    void\
    \ clear_right() {\n        while (!R.empty()) R.pop();\n    }\n \n    // \\/ ->\
    \ _/\n    // f_{new} (x) = min f(y) (y >= x)\n    void clear_left() {\n      \
    \  while (!L.empty()) L.pop();\n    }\n \n    // \\/ -> \\_/\n    // f_{new} (x)\
    \ = min f(y) (x-b <= y <= x-a)\n    void shift(const T& a, const T& b) {\n   \
    \     assert(a <= b);\n        add_l += a;\n        add_r += b;\n    }\n \n  \
    \  // \\/. -> .\\/\n    // f_{new} (x) = f(x - a)\n    void shift(const T& a)\
    \ {\n        shift(a, a);\n    }\n \n    // L, R \u3092\u7834\u58CA\u3059\u308B\
    \n    T get(const T& x) {\n        T ret = min_f;\n        while (!L.empty())\
    \ {\n            ret += max(T(0), pop_L() - x);\n        }\n        while (!R.empty())\
    \ {\n            ret += max(T(0), x - pop_R());\n        }\n        return ret;\n\
    \    }\n \n    void merge(slope_trick& st) {\n        if (st.size() > size())\
    \ {\n            std::swap(st.L, L);\n            std::swap(st.R, R);\n      \
    \      std::swap(st.add_l, add_l);\n            std::swap(st.add_r, add_r);\n\
    \            std::swap(st.min_f, min_f);\n        }\n        while (!st.R.empty())\
    \ {\n            add_x_minus_a(st.pop_R());\n        }\n        while (!st.L.empty())\
    \ {\n            add_a_minus_x(st.pop_L());\n        }\n        min_f += st.min_f;\n\
    \    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <queue>\n#include <limits>\n#include <functional>\n\
    #include <algorithm>\n#include <utility>\n\nnamespace noya2{\n\ntemplate< typename\
    \ T >\nstruct slope_trick {\n \n    static constexpr T INF = std::numeric_limits<\
    \ T >::max() / 3;\n \n    T min_f;\n    std::priority_queue<T,std::vector<T>,std::less<>>\
    \ L;\n    std::priority_queue<T,std::vector<T>,std::greater<>> R;\n    T add_l,\
    \ add_r;\n \n    void push_R(const T& a) {\n        R.push(a - add_r);\n    }\n\
    \ \n    T top_R() const {\n        if (R.empty()) return INF;\n        else return\
    \ R.top() + add_r;\n    }\n \n    T pop_R() {\n        T val = top_R();\n    \
    \    if (!R.empty()) R.pop();\n        return val;\n    }\n \n    void push_L(const\
    \ T& a) {\n        L.push(a - add_l);\n    }\n \n    T top_L() const {\n     \
    \   if (L.empty()) return -INF;\n        else return L.top() + add_l;\n    }\n\
    \ \n    T pop_L() {\n        T val = top_L();\n        if (!L.empty()) L.pop();\n\
    \        return val;\n    }\n \n    size_t size() {\n        return L.size() +\
    \ R.size();\n    }\n \n    slope_trick() : min_f(0), add_l(0), add_r(0) {}\n\n\
    \    T min() const {\n        return min_f;\n    }\n    \n    std::pair<T, T>\
    \ argmin() const {\n        return {top_L(), top_R()};\n    }\n \n    // f(x)\
    \ += a\n    void add_all(const T& a) {\n        min_f += a;\n    }\n \n    //\
    \ add \\_\n    // f(x) += max(a - x, 0)\n    void add_a_minus_x(const T& a) {\n\
    \        min_f += std::max(T(0), a - top_R());\n        push_R(a);\n        push_L(pop_R());\n\
    \    }\n \n    // add _/\n    // f(x) += max(x - a, 0)\n    void add_x_minus_a(const\
    \ T& a) {\n        min_f += std::max(T(0), top_L() - a);\n        push_L(a);\n\
    \        push_R(pop_L());\n    }\n \n    // add \\/\n    // f(x) += abs(x - a)\n\
    \    void add_abs(const T& a) {\n        add_a_minus_x(a);\n        add_x_minus_a(a);\n\
    \    }\n \n    // \\/ -> \\_\n    // f_{new} (x) = min f(y) (y <= x)\n    void\
    \ clear_right() {\n        while (!R.empty()) R.pop();\n    }\n \n    // \\/ ->\
    \ _/\n    // f_{new} (x) = min f(y) (y >= x)\n    void clear_left() {\n      \
    \  while (!L.empty()) L.pop();\n    }\n \n    // \\/ -> \\_/\n    // f_{new} (x)\
    \ = min f(y) (x-b <= y <= x-a)\n    void shift(const T& a, const T& b) {\n   \
    \     assert(a <= b);\n        add_l += a;\n        add_r += b;\n    }\n \n  \
    \  // \\/. -> .\\/\n    // f_{new} (x) = f(x - a)\n    void shift(const T& a)\
    \ {\n        shift(a, a);\n    }\n \n    // L, R \u3092\u7834\u58CA\u3059\u308B\
    \n    T get(const T& x) {\n        T ret = min_f;\n        while (!L.empty())\
    \ {\n            ret += max(T(0), pop_L() - x);\n        }\n        while (!R.empty())\
    \ {\n            ret += max(T(0), x - pop_R());\n        }\n        return ret;\n\
    \    }\n \n    void merge(slope_trick& st) {\n        if (st.size() > size())\
    \ {\n            std::swap(st.L, L);\n            std::swap(st.R, R);\n      \
    \      std::swap(st.add_l, add_l);\n            std::swap(st.add_r, add_r);\n\
    \            std::swap(st.min_f, min_f);\n        }\n        while (!st.R.empty())\
    \ {\n            add_x_minus_a(st.pop_R());\n        }\n        while (!st.L.empty())\
    \ {\n            add_a_minus_x(st.pop_L());\n        }\n        min_f += st.min_f;\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2024-12-04 14:24:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/yuki_1077.test.cpp
documentation_of: data_structure/slope_trick.hpp
layout: document
redirect_from:
- /library/data_structure/slope_trick.hpp
- /library/data_structure/slope_trick.hpp.html
title: data_structure/slope_trick.hpp
---
