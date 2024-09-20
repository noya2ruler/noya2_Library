---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/rollback_dsu.hpp
    title: data_structure/rollback_dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj_2235.test.cpp
    title: test/data_structure/aoj_2235.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/offline_dynamic_connectivity.hpp\"\n\n#line\
    \ 2 \"data_structure/rollback_dsu.hpp\"\n\n#include <vector>\n#include <stack>\n\
    #include <utility>\n#include <cassert>\n\nnamespace noya2 {\n\nstruct rollback_dsu\
    \ {\n    rollback_dsu (int _n = 0) : n(_n), par_or_siz(_n,-1) {}\n    int leader(int\
    \ v){\n        assert(0 <= v && v < n);\n        if (par_or_siz[v] < 0) return\
    \ v;\n        return leader(par_or_siz[v]);\n    }\n    bool same(int u, int v){\n\
    \        return leader(u) == leader(v);\n    }\n    int merge(int u, int v){\n\
    \        u = leader(u);\n        v = leader(v);\n        logs.push(make_pair(u,par_or_siz[u]));\n\
    \        logs.push(make_pair(v,par_or_siz[v]));\n        if (u == v) return u;\n\
    \        if (-par_or_siz[u] < -par_or_siz[v]) std::swap(u,v);\n        par_or_siz[u]\
    \ += par_or_siz[v];\n        par_or_siz[v] = u;\n        return u;\n    }\n  \
    \  int size(int v){\n        return -par_or_siz[leader(v)];\n    }\n    void rollback(){\n\
    \        par_or_siz[logs.top().first] = logs.top().second; logs.pop();\n     \
    \   par_or_siz[logs.top().first] = logs.top().second; logs.pop();\n    }\n  private:\n\
    \    int n;\n    std::vector<int> par_or_siz;\n    std::stack<std::pair<int,int>>\
    \ logs;\n};\n\n} // namespace noya2\n#line 4 \"data_structure/offline_dynamic_connectivity.hpp\"\
    \n\n#line 8 \"data_structure/offline_dynamic_connectivity.hpp\"\n\nnamespace noya2\
    \ {\n\nstruct offline_dynamic_connectivity : rollback_dsu {\n    using rollback_dsu::operator=;\n\
    \    offline_dynamic_connectivity () {}\n    offline_dynamic_connectivity (int\
    \ _n, unsigned int t_max, size_t reserve_edge = 0) : n(_n) {\n        sz = bit_ceil(t_max);\n\
    \        ids.resize(sz*2);\n        *this = rollback_dsu(n);\n        edges.reserve(reserve_edge);\n\
    \        inner_clock = -1;\n    }\n    // for time interval [l, r), connect u,\
    \ v\n    void add_edge(int l, int r, int u, int v){\n        assert(0 <= l &&\
    \ l <= r && r <= sz);\n        assert(0 <= u && u < n && 0 <= v && v < n);\n \
    \       l += sz, r += sz;\n        int edge_id = edges.size();\n        while\
    \ (l < r){\n            if (l & 1) ids[l++].push_back(edge_id);\n            if\
    \ (r & 1) ids[--r].push_back(edge_id);\n            l >>= 1, r >>= 1;\n      \
    \  }\n        edges.emplace_back(u,v);\n    }\n    void build(){\n        inner_clock\
    \ = 1;\n        while (true){\n            add_block(inner_clock);\n         \
    \   if (inner_clock == sz) break;\n            inner_clock <<= 1;\n        }\n\
    \    }\n    // leap to time t, change this dsu\n    void set(int t){\n       \
    \ assert(0 <= t && t < sz && inner_clock != -1);\n        t += sz;\n        if\
    \ (inner_clock == t) return ;\n        int k = 32 - countl_zero((unsigned int)(inner_clock\
    \ ^ t));\n        for (int i = 0; i < k; i++){\n            del_block(inner_clock);\n\
    \            inner_clock >>= 1;\n        }\n        for (int i = k-1; i >= 0;\
    \ i--){\n            inner_clock <<= 1;\n            if (t >> i & 1) inner_clock++;\n\
    \            add_block(inner_clock);\n        }\n        inner_clock = t;\n  \
    \  }\n  private:\n    void add_block(int i){\n        for (auto &id : ids[i]){\n\
    \            this->merge(edges[id].first,edges[id].second);\n        }\n    }\n\
    \    void del_block(int i){\n        int ctr = ids[i].size();\n        while (ctr--)\
    \ this->rollback();\n    }\n    int n, sz, inner_clock;\n    std::vector<std::vector<int>>\
    \ ids;\n    std::vector<std::pair<int,int>> edges;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../data_structure/rollback_dsu.hpp\"\n\n#include\
    \ <vector>\n#include <utility>\n#include <cassert>\n\nnamespace noya2 {\n\nstruct\
    \ offline_dynamic_connectivity : rollback_dsu {\n    using rollback_dsu::operator=;\n\
    \    offline_dynamic_connectivity () {}\n    offline_dynamic_connectivity (int\
    \ _n, unsigned int t_max, size_t reserve_edge = 0) : n(_n) {\n        sz = bit_ceil(t_max);\n\
    \        ids.resize(sz*2);\n        *this = rollback_dsu(n);\n        edges.reserve(reserve_edge);\n\
    \        inner_clock = -1;\n    }\n    // for time interval [l, r), connect u,\
    \ v\n    void add_edge(int l, int r, int u, int v){\n        assert(0 <= l &&\
    \ l <= r && r <= sz);\n        assert(0 <= u && u < n && 0 <= v && v < n);\n \
    \       l += sz, r += sz;\n        int edge_id = edges.size();\n        while\
    \ (l < r){\n            if (l & 1) ids[l++].push_back(edge_id);\n            if\
    \ (r & 1) ids[--r].push_back(edge_id);\n            l >>= 1, r >>= 1;\n      \
    \  }\n        edges.emplace_back(u,v);\n    }\n    void build(){\n        inner_clock\
    \ = 1;\n        while (true){\n            add_block(inner_clock);\n         \
    \   if (inner_clock == sz) break;\n            inner_clock <<= 1;\n        }\n\
    \    }\n    // leap to time t, change this dsu\n    void set(int t){\n       \
    \ assert(0 <= t && t < sz && inner_clock != -1);\n        t += sz;\n        if\
    \ (inner_clock == t) return ;\n        int k = 32 - countl_zero((unsigned int)(inner_clock\
    \ ^ t));\n        for (int i = 0; i < k; i++){\n            del_block(inner_clock);\n\
    \            inner_clock >>= 1;\n        }\n        for (int i = k-1; i >= 0;\
    \ i--){\n            inner_clock <<= 1;\n            if (t >> i & 1) inner_clock++;\n\
    \            add_block(inner_clock);\n        }\n        inner_clock = t;\n  \
    \  }\n  private:\n    void add_block(int i){\n        for (auto &id : ids[i]){\n\
    \            this->merge(edges[id].first,edges[id].second);\n        }\n    }\n\
    \    void del_block(int i){\n        int ctr = ids[i].size();\n        while (ctr--)\
    \ this->rollback();\n    }\n    int n, sz, inner_clock;\n    std::vector<std::vector<int>>\
    \ ids;\n    std::vector<std::pair<int,int>> edges;\n};\n\n} // namespace noya2"
  dependsOn:
  - data_structure/rollback_dsu.hpp
  isVerificationFile: false
  path: data_structure/offline_dynamic_connectivity.hpp
  requiredBy: []
  timestamp: '2024-09-20 17:32:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/aoj_2235.test.cpp
documentation_of: data_structure/offline_dynamic_connectivity.hpp
layout: document
redirect_from:
- /library/data_structure/offline_dynamic_connectivity.hpp
- /library/data_structure/offline_dynamic_connectivity.hpp.html
title: data_structure/offline_dynamic_connectivity.hpp
---
