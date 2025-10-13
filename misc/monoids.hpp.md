---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_rectangle_sum.hpp
    title: data_structure/offline_rectangle_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
    title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Rectangle_Sum.test.cpp
    title: test/data_structure/Rectangle_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Range_Inversions_Query.test.cpp
    title: test/data_structure/Static_Range_Inversions_Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj_dsl_1_b.test.cpp
    title: test/data_structure/aoj_dsl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/monoids.hpp\"\n\n#include<limits>\n\nnamespace noya2{\n\
    \ntemplate<typename T>\nstruct max_monoid {\n    using value_type = T;\n    static\
    \ constexpr T op(const T &a, const T &b){ return max(a,b); }\n    static constexpr\
    \ T e(){ return std::numeric_limits<T>::min(); }\n    static constexpr T inv(const\
    \ T &a){ return e(); }\n};\ntemplate<typename T>\nstruct min_monoid {\n    using\
    \ value_type = T;\n    static constexpr T op(const T &a, const T &b){ return min(a,b);\
    \ }\n    static constexpr T e(){ return std::numeric_limits<T>::max(); }\n   \
    \ static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename T>\n\
    struct plus_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a + b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return -a; }\n};\ntemplate<typename\
    \ T>\nstruct xor_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a ^ b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return a; }\n};\n\ntemplate<class\
    \ S, auto _op, auto _e>\nstruct monoid {\n    using value_type = S;\n    static\
    \ constexpr value_type op(value_type a, value_type b){\n        return _op(a,\
    \ b);\n    }\n    static constexpr value_type e(){\n        return _e();\n   \
    \ }\n};\n  \n} // namespace noya2\n"
  code: "#pragma once\n\n#include<limits>\n\nnamespace noya2{\n\ntemplate<typename\
    \ T>\nstruct max_monoid {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return max(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::min();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct min_monoid {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return min(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::max();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct plus_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a + b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return -a; }\n};\ntemplate<typename\
    \ T>\nstruct xor_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a ^ b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return a; }\n};\n\ntemplate<class\
    \ S, auto _op, auto _e>\nstruct monoid {\n    using value_type = S;\n    static\
    \ constexpr value_type op(value_type a, value_type b){\n        return _op(a,\
    \ b);\n    }\n    static constexpr value_type e(){\n        return _e();\n   \
    \ }\n};\n  \n} // namespace noya2\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/monoids.hpp
  requiredBy:
  - data_structure/offline_rectangle_sum.hpp
  timestamp: '2025-02-22 20:23:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - test/data_structure/Static_Range_Inversions_Query.test.cpp
  - test/data_structure/aoj_dsl_1_b.test.cpp
  - test/data_structure/Rectangle_Sum.test.cpp
documentation_of: misc/monoids.hpp
layout: document
redirect_from:
- /library/misc/monoids.hpp
- /library/misc/monoids.hpp.html
title: misc/monoids.hpp
---
