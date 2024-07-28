---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/RangeParallelUnionfind.test.cpp
    title: test/data_structure/RangeParallelUnionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/range_parallel_dsu.hpp\"\n\n#line 2 \"data_structure/dsu.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\nnamespace noya2{\n\
    \nstruct dsu {\n  public:\n    dsu() : _n(0) {}\n    dsu(int n) : _n(n), parent_or_size(n,\
    \ -1) {}\n\n    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n\n    int size(int a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n} // namespace noya2\n#line\
    \ 4 \"data_structure/range_parallel_dsu.hpp\"\n\nnamespace noya2 {\n\nstruct range_parallel_dsu\
    \ : dsu {\n    using dsu::operator=;\n    int n;\n    std::vector<dsu> ds;\n \
    \   range_parallel_dsu (int _n0) : n(_n0) {\n        int msb = 31 - countl_zero((unsigned\
    \ int)(n));\n        ds.resize(msb, dsu(n));\n        (*this) = dsu(n);\n    }\n\
    \    // for k = 0, 1, ... ,d-1\n    // merge(i+k,j+k)\n    std::vector<std::tuple<int,int,int>>\
    \ merge_range(int i, int j, int d){\n        assert(i + d <= n);\n        assert(j\
    \ + d <= n);\n        if (d == 0) return {};\n        int msb = std::bit_width((unsigned\
    \ int)(d)) - 1;\n        std::vector<std::tuple<int,int,int>> connected;\n   \
    \     inner_merge(i, j, msb, connected);\n        inner_merge(i + d - (1<<msb),\
    \ j + d - (1<<msb), msb, connected);\n        return connected;\n    }\n  private:\n\
    \    // d = 2^k\n    void inner_merge(int i, int j, int k, std::vector<std::tuple<int,int,int>>\
    \ &connected){\n        // k >= 0\n        if (k == 0){\n            i = this->leader(i);\n\
    \            j = this->leader(j);\n            if (i == j) return ;\n        \
    \    int l = this->merge(i, j);\n            connected.emplace_back(i, j, l);\n\
    \        }\n        else {\n            k--;\n            if (ds[k].same(i, j))\
    \ return ;\n            ds[k].merge(i, j);\n            inner_merge(i, j, k, connected);\n\
    \            inner_merge(i + (1<<k), j + (1<<k), k, connected);\n        }\n \
    \   }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"data_structure/dsu.hpp\"\n\nnamespace noya2 {\n\
    \nstruct range_parallel_dsu : dsu {\n    using dsu::operator=;\n    int n;\n \
    \   std::vector<dsu> ds;\n    range_parallel_dsu (int _n0) : n(_n0) {\n      \
    \  int msb = 31 - countl_zero((unsigned int)(n));\n        ds.resize(msb, dsu(n));\n\
    \        (*this) = dsu(n);\n    }\n    // for k = 0, 1, ... ,d-1\n    // merge(i+k,j+k)\n\
    \    std::vector<std::tuple<int,int,int>> merge_range(int i, int j, int d){\n\
    \        assert(i + d <= n);\n        assert(j + d <= n);\n        if (d == 0)\
    \ return {};\n        int msb = std::bit_width((unsigned int)(d)) - 1;\n     \
    \   std::vector<std::tuple<int,int,int>> connected;\n        inner_merge(i, j,\
    \ msb, connected);\n        inner_merge(i + d - (1<<msb), j + d - (1<<msb), msb,\
    \ connected);\n        return connected;\n    }\n  private:\n    // d = 2^k\n\
    \    void inner_merge(int i, int j, int k, std::vector<std::tuple<int,int,int>>\
    \ &connected){\n        // k >= 0\n        if (k == 0){\n            i = this->leader(i);\n\
    \            j = this->leader(j);\n            if (i == j) return ;\n        \
    \    int l = this->merge(i, j);\n            connected.emplace_back(i, j, l);\n\
    \        }\n        else {\n            k--;\n            if (ds[k].same(i, j))\
    \ return ;\n            ds[k].merge(i, j);\n            inner_merge(i, j, k, connected);\n\
    \            inner_merge(i + (1<<k), j + (1<<k), k, connected);\n        }\n \
    \   }\n};\n\n} // namespace noya2"
  dependsOn:
  - data_structure/dsu.hpp
  isVerificationFile: false
  path: data_structure/range_parallel_dsu.hpp
  requiredBy: []
  timestamp: '2024-07-28 16:18:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/RangeParallelUnionfind.test.cpp
documentation_of: data_structure/range_parallel_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/range_parallel_dsu.hpp
- /library/data_structure/range_parallel_dsu.hpp.html
title: data_structure/range_parallel_dsu.hpp
---
