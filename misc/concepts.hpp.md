---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.hpp
    title: data_structure/binary_indexed_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_rectangle_sum.hpp
    title: data_structure/offline_rectangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/potentialized_dsu.hpp
    title: data_structure/potentialized_dsu.hpp
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
  bundledCode: "#line 2 \"misc/concepts.hpp\"\n\n#include<concepts>\n\nnamespace noya2\
    \ {\n\ntemplate<class monoid>\nconcept Monoid = requires {\n    typename monoid::value_type;\n\
    \    {monoid::op(declval<typename monoid::value_type>(),declval<typename monoid::value_type>())}\
    \ -> std::same_as<typename monoid::value_type>;\n    {monoid::e()} -> std::same_as<typename\
    \ monoid::value_type>;\n};\n\ntemplate<class group>\nconcept Group = requires\
    \ {\n    requires Monoid<group>;\n    {group::inv(declval<typename group::value_type>())}\
    \ -> std::same_as<typename group::value_type>;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<concepts>\n\nnamespace noya2 {\n\ntemplate<class\
    \ monoid>\nconcept Monoid = requires {\n    typename monoid::value_type;\n   \
    \ {monoid::op(declval<typename monoid::value_type>(),declval<typename monoid::value_type>())}\
    \ -> std::same_as<typename monoid::value_type>;\n    {monoid::e()} -> std::same_as<typename\
    \ monoid::value_type>;\n};\n\ntemplate<class group>\nconcept Group = requires\
    \ {\n    requires Monoid<group>;\n    {group::inv(declval<typename group::value_type>())}\
    \ -> std::same_as<typename group::value_type>;\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/concepts.hpp
  requiredBy:
  - data_structure/potentialized_dsu.hpp
  - data_structure/binary_indexed_tree.hpp
  - data_structure/offline_rectangle_sum.hpp
  timestamp: '2023-11-13 11:52:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - test/data_structure/aoj_dsl_1_b.test.cpp
  - test/data_structure/Static_Range_Inversions_Query.test.cpp
  - test/data_structure/Rectangle_Sum.test.cpp
documentation_of: misc/concepts.hpp
layout: document
redirect_from:
- /library/misc/concepts.hpp
- /library/misc/concepts.hpp.html
title: misc/concepts.hpp
---
