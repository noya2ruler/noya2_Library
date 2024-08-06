---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/range_tree.hpp
    title: data_structure/range_tree.hpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/compress.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace noya2{\n\ntemplate<typename T>\nstruct compress {\n\
    \    std::vector<T> raws;\n    compress () {}\n    compress (const vector<T> &_raws)\
    \ : raws(_raws){ build(); }\n    void build(){\n        std::sort(raws.begin(),\
    \ raws.end());\n        raws.erase(std::unique(raws.begin(), raws.end()), raws.end());\n\
    \    }\n    int id(const T &raw){ return lb(raw); }\n    T raw(const int &id){\
    \ return raws[id]; }\n    void add(const T &raw){ raws.emplace_back(raw); }\n\
    \    void reserve(size_t sz){ raws.reserve(sz); }\n    size_t size(){ return raws.size();\
    \ }\n    int lb(const T &raw){ return lower_bound(all(raws),raw) - raws.begin();\
    \ }\n    int ub(const T &raw){ return upper_bound(all(raws),raw) - raws.begin();\
    \ }\n    bool contains(const T &raw){\n        int jd = lb(raw);\n        if (jd\
    \ < (int)size()) return raws[jd] == raw;\n        return false;\n    }\n    int\
    \ contains_id(const T &raw){\n        int jd = lb(raw);\n        if (jd < (int)size()\
    \ && raws[jd] == raw) return jd;\n        return -1;\n    }\n};\n\n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace noya2{\n\
    \ntemplate<typename T>\nstruct compress {\n    std::vector<T> raws;\n    compress\
    \ () {}\n    compress (const vector<T> &_raws) : raws(_raws){ build(); }\n   \
    \ void build(){\n        std::sort(raws.begin(), raws.end());\n        raws.erase(std::unique(raws.begin(),\
    \ raws.end()), raws.end());\n    }\n    int id(const T &raw){ return lb(raw);\
    \ }\n    T raw(const int &id){ return raws[id]; }\n    void add(const T &raw){\
    \ raws.emplace_back(raw); }\n    void reserve(size_t sz){ raws.reserve(sz); }\n\
    \    size_t size(){ return raws.size(); }\n    int lb(const T &raw){ return lower_bound(all(raws),raw)\
    \ - raws.begin(); }\n    int ub(const T &raw){ return upper_bound(all(raws),raw)\
    \ - raws.begin(); }\n    bool contains(const T &raw){\n        int jd = lb(raw);\n\
    \        if (jd < (int)size()) return raws[jd] == raw;\n        return false;\n\
    \    }\n    int contains_id(const T &raw){\n        int jd = lb(raw);\n      \
    \  if (jd < (int)size() && raws[jd] == raw) return jd;\n        return -1;\n \
    \   }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy:
  - data_structure/range_tree.hpp
  timestamp: '2024-07-28 17:15:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - test/data_structure/Rectangle_Sum.test.cpp
  - test/data_structure/Static_Range_Inversions_Query.test.cpp
documentation_of: data_structure/compress.hpp
layout: document
redirect_from:
- /library/data_structure/compress.hpp
- /library/data_structure/compress.hpp.html
title: data_structure/compress.hpp
---
