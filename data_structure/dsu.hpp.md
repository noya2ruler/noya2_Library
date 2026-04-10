---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data_structure/bipartite_dsu.hpp
    title: data_structure/bipartite_dsu.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_parallel_dsu.hpp
    title: data_structure/range_parallel_dsu.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/partition_by_circle.hpp
    title: geometry/partition_by_circle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/RangeParallelUnionfind.test.cpp
    title: test/data_structure/RangeParallelUnionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Unionfind.test.cpp
    title: test/data_structure/Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/aoj1198.test.cpp
    title: test/geometry/aoj1198.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dsu.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n\nnamespace noya2{\n\nstruct dsu {\n  public:\n\
    \    dsu() : _n(0), _cc(0) {}\n    dsu(int n) : _n(n), _cc(n), parent_or_size(n,\
    \ -1) {}\n\n    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        _cc--;\n        return x;\n    }\n\n    bool same(int a, int b)\
    \ {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n  \
    \      return leader(a) == leader(b);\n    }\n\n    int leader(int a) {\n    \
    \    assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return a;\n\
    \        return parent_or_size[a] = leader(parent_or_size[a]);\n    }\n\n    int\
    \ size(int a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \    int group_count() const {\n        return _cc;\n    }\n\n  private:\n   \
    \ int _n, _cc;\n    // root node: -1 * component size\n    // otherwise: parent\n\
    \    std::vector<int> parent_or_size;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\
    \nnamespace noya2{\n\nstruct dsu {\n  public:\n    dsu() : _n(0), _cc(0) {}\n\
    \    dsu(int n) : _n(n), _cc(n), parent_or_size(n, -1) {}\n\n    int merge(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        int x = leader(a), y = leader(b);\n        if (x == y) return\
    \ x;\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n\
    \        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] =\
    \ x;\n        _cc--;\n        return x;\n    }\n\n    bool same(int a, int b)\
    \ {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n  \
    \      return leader(a) == leader(b);\n    }\n\n    int leader(int a) {\n    \
    \    assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return a;\n\
    \        return parent_or_size[a] = leader(parent_or_size[a]);\n    }\n\n    int\
    \ size(int a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \    int group_count() const {\n        return _cc;\n    }\n\n  private:\n   \
    \ int _n, _cc;\n    // root node: -1 * component size\n    // otherwise: parent\n\
    \    std::vector<int> parent_or_size;\n};\n\n} // namespace noya2\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dsu.hpp
  requiredBy:
  - geometry/partition_by_circle.hpp
  - data_structure/bipartite_dsu.hpp
  - data_structure/range_parallel_dsu.hpp
  timestamp: '2025-04-29 17:55:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/aoj1198.test.cpp
  - test/data_structure/RangeParallelUnionfind.test.cpp
  - test/data_structure/Unionfind.test.cpp
documentation_of: data_structure/dsu.hpp
layout: document
redirect_from:
- /library/data_structure/dsu.hpp
- /library/data_structure/dsu.hpp.html
title: data_structure/dsu.hpp
---
