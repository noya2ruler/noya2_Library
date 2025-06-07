---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_dynamic_connectivity.hpp
    title: data_structure/offline_dynamic_connectivity.hpp
  - icon: ':warning:'
    path: data_structure/rollback_bipartite_dsu.hpp
    title: data_structure/rollback_bipartite_dsu.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj_2235.test.cpp
    title: test/data_structure/aoj_2235.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/rollback_dsu.hpp\"\n\n#include <vector>\n\
    #include <stack>\n#include <utility>\n#include <cassert>\n\nnamespace noya2 {\n\
    \nstruct rollback_dsu {\n    rollback_dsu (int _n = 0) : n(_n), cc(_n), par_or_siz(_n,-1)\
    \ {}\n    int leader(int v) const {\n        assert(0 <= v && v < n);\n      \
    \  if (par_or_siz[v] < 0) return v;\n        return leader(par_or_siz[v]);\n \
    \   }\n    bool same(int u, int v) const {\n        return leader(u) == leader(v);\n\
    \    }\n    int merge(int u, int v){\n        u = leader(u);\n        v = leader(v);\n\
    \        logs.emplace(u, par_or_siz[u]);\n        logs.emplace(v, par_or_siz[v]);\n\
    \        logs.emplace(cc, 0);\n        if (u == v) return u;\n        if (-par_or_siz[u]\
    \ < -par_or_siz[v]) std::swap(u,v);\n        par_or_siz[u] += par_or_siz[v];\n\
    \        par_or_siz[v] = u;\n        cc--;\n        return u;\n    }\n    int\
    \ size(int v) const {\n        return -par_or_siz[leader(v)];\n    }\n    int\
    \ group_count() const {\n        return cc;\n    }\n    void rollback(){\n   \
    \     cc = logs.top().first; logs.pop();\n        par_or_siz[logs.top().first]\
    \ = logs.top().second; logs.pop();\n        par_or_siz[logs.top().first] = logs.top().second;\
    \ logs.pop();\n    }\n  private:\n    int n, cc;\n    std::vector<int> par_or_siz;\n\
    \    std::stack<std::pair<int,int>> logs;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <stack>\n#include <utility>\n\
    #include <cassert>\n\nnamespace noya2 {\n\nstruct rollback_dsu {\n    rollback_dsu\
    \ (int _n = 0) : n(_n), cc(_n), par_or_siz(_n,-1) {}\n    int leader(int v) const\
    \ {\n        assert(0 <= v && v < n);\n        if (par_or_siz[v] < 0) return v;\n\
    \        return leader(par_or_siz[v]);\n    }\n    bool same(int u, int v) const\
    \ {\n        return leader(u) == leader(v);\n    }\n    int merge(int u, int v){\n\
    \        u = leader(u);\n        v = leader(v);\n        logs.emplace(u, par_or_siz[u]);\n\
    \        logs.emplace(v, par_or_siz[v]);\n        logs.emplace(cc, 0);\n     \
    \   if (u == v) return u;\n        if (-par_or_siz[u] < -par_or_siz[v]) std::swap(u,v);\n\
    \        par_or_siz[u] += par_or_siz[v];\n        par_or_siz[v] = u;\n       \
    \ cc--;\n        return u;\n    }\n    int size(int v) const {\n        return\
    \ -par_or_siz[leader(v)];\n    }\n    int group_count() const {\n        return\
    \ cc;\n    }\n    void rollback(){\n        cc = logs.top().first; logs.pop();\n\
    \        par_or_siz[logs.top().first] = logs.top().second; logs.pop();\n     \
    \   par_or_siz[logs.top().first] = logs.top().second; logs.pop();\n    }\n  private:\n\
    \    int n, cc;\n    std::vector<int> par_or_siz;\n    std::stack<std::pair<int,int>>\
    \ logs;\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/rollback_dsu.hpp
  requiredBy:
  - data_structure/rollback_bipartite_dsu.hpp
  - data_structure/offline_dynamic_connectivity.hpp
  timestamp: '2025-06-07 18:37:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/aoj_2235.test.cpp
documentation_of: data_structure/rollback_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/rollback_dsu.hpp
- /library/data_structure/rollback_dsu.hpp.html
title: data_structure/rollback_dsu.hpp
---
