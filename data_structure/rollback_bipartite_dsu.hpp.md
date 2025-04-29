---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/rollback_dsu.hpp
    title: data_structure/rollback_dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/rollback_bipartite_dsu.hpp\"\n\n#line 2 \"\
    data_structure/rollback_dsu.hpp\"\n\n#include <vector>\n#include <stack>\n#include\
    \ <utility>\n#include <cassert>\n\nnamespace noya2 {\n\nstruct rollback_dsu {\n\
    \    rollback_dsu (int _n = 0) : n(_n), cc(_n), par_or_siz(_n,-1) {}\n    int\
    \ leader(int v) const {\n        assert(0 <= v && v < n);\n        if (par_or_siz[v]\
    \ < 0) return v;\n        return leader(par_or_siz[v]);\n    }\n    bool same(int\
    \ u, int v) const {\n        return leader(u) == leader(v);\n    }\n    int merge(int\
    \ u, int v){\n        u = leader(u);\n        v = leader(v);\n        logs.push(make_pair(u,par_or_siz[u]));\n\
    \        logs.push(make_pair(v,par_or_siz[v]));\n        logs.push(make_pair(cc,\
    \ -1));\n        if (u == v) return u;\n        if (-par_or_siz[u] < -par_or_siz[v])\
    \ std::swap(u,v);\n        par_or_siz[u] += par_or_siz[v];\n        par_or_siz[v]\
    \ = u;\n        cc--;\n        return u;\n    }\n    int size(int v) const {\n\
    \        return -par_or_siz[leader(v)];\n    }\n    int group_count() const {\n\
    \        return cc;\n    }\n    void rollback(){\n        cc = logs.top().first;\
    \ logs.pop();\n        par_or_siz[logs.top().first] = logs.top().second; logs.pop();\n\
    \        par_or_siz[logs.top().first] = logs.top().second; logs.pop();\n    }\n\
    \  private:\n    int n, cc;\n    std::vector<int> par_or_siz;\n    std::stack<std::pair<int,int>>\
    \ logs;\n};\n\n} // namespace noya2\n#line 4 \"data_structure/rollback_bipartite_dsu.hpp\"\
    \n\nnamespace noya2 {\n\nstruct rollback_bipartite_dsu {\n    int n, cc_bipartite;\n\
    \    rollback_dsu d;\n    std::stack<bool> is_rollback;\n    rollback_bipartite_dsu\
    \ (int _n = 0) : n(_n), cc_bipartite(_n), d(_n*2){}\n    void inner_merge(int\
    \ u, int v, int up, int vp){\n        if (d.same(u, v)){\n            assert(d.same(up,\
    \ vp));\n            is_rollback.push(false);\n            return ;\n        }\n\
    \        if (inner_is_bipartite(u) || inner_is_bipartite(v)){\n            cc_bipartite--;\n\
    \            is_rollback.push(true);\n        }\n        else {\n            is_rollback.push(false);\n\
    \        }\n        d.merge(u, v);\n        d.merge(up, vp);\n        is_rollback.push(true);\n\
    \    }\n    void add_edge(int u, int v, bool w = true){\n        assert(0 <= u\
    \ && u < n);\n        assert(0 <= v && v < n);\n        if (w){\n            inner_merge(u,\
    \ n + v, v, n + u);\n        }\n        else {\n            inner_merge(u, v,\
    \ n + u, n + v);\n        }\n    }\n    bool is_bipartite() const {\n        return\
    \ d.group_count() == cc_bipartite * 2;\n    }\n    bool is_bipartite(int v){\n\
    \        assert(0 <= v && v < n);\n        return !d.same(v, n + v);\n    }\n\
    \    bool inner_is_bipartite(int v){\n        return !d.same(v, (v < n ? n + v\
    \ : v - n));\n    }\n    int bipartite_component_count() const {\n        return\
    \ cc_bipartite;\n    }\n    int non_bipartite_component_count() const {\n    \
    \    return d.group_count() - cc_bipartite * 2;\n    }\n    int component_count()\
    \ const {\n        return d.group_count() - cc_bipartite;\n    }\n    void rollback(){\n\
    \        if (is_rollback.top()){\n            is_rollback.pop();\n           \
    \ d.rollback();\n            d.rollback();\n            if (is_rollback.top()){\n\
    \                cc_bipartite++;\n            }\n            is_rollback.pop();\n\
    \        }\n        else {\n            is_rollback.pop();\n        }\n    }\n\
    };\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../data_structure/rollback_dsu.hpp\"\n\nnamespace\
    \ noya2 {\n\nstruct rollback_bipartite_dsu {\n    int n, cc_bipartite;\n    rollback_dsu\
    \ d;\n    std::stack<bool> is_rollback;\n    rollback_bipartite_dsu (int _n =\
    \ 0) : n(_n), cc_bipartite(_n), d(_n*2){}\n    void inner_merge(int u, int v,\
    \ int up, int vp){\n        if (d.same(u, v)){\n            assert(d.same(up,\
    \ vp));\n            is_rollback.push(false);\n            return ;\n        }\n\
    \        if (inner_is_bipartite(u) || inner_is_bipartite(v)){\n            cc_bipartite--;\n\
    \            is_rollback.push(true);\n        }\n        else {\n            is_rollback.push(false);\n\
    \        }\n        d.merge(u, v);\n        d.merge(up, vp);\n        is_rollback.push(true);\n\
    \    }\n    void add_edge(int u, int v, bool w = true){\n        assert(0 <= u\
    \ && u < n);\n        assert(0 <= v && v < n);\n        if (w){\n            inner_merge(u,\
    \ n + v, v, n + u);\n        }\n        else {\n            inner_merge(u, v,\
    \ n + u, n + v);\n        }\n    }\n    bool is_bipartite() const {\n        return\
    \ d.group_count() == cc_bipartite * 2;\n    }\n    bool is_bipartite(int v){\n\
    \        assert(0 <= v && v < n);\n        return !d.same(v, n + v);\n    }\n\
    \    bool inner_is_bipartite(int v){\n        return !d.same(v, (v < n ? n + v\
    \ : v - n));\n    }\n    int bipartite_component_count() const {\n        return\
    \ cc_bipartite;\n    }\n    int non_bipartite_component_count() const {\n    \
    \    return d.group_count() - cc_bipartite * 2;\n    }\n    int component_count()\
    \ const {\n        return d.group_count() - cc_bipartite;\n    }\n    void rollback(){\n\
    \        if (is_rollback.top()){\n            is_rollback.pop();\n           \
    \ d.rollback();\n            d.rollback();\n            if (is_rollback.top()){\n\
    \                cc_bipartite++;\n            }\n            is_rollback.pop();\n\
    \        }\n        else {\n            is_rollback.pop();\n        }\n    }\n\
    };\n\n} // namespace noya2"
  dependsOn:
  - data_structure/rollback_dsu.hpp
  isVerificationFile: false
  path: data_structure/rollback_bipartite_dsu.hpp
  requiredBy: []
  timestamp: '2025-04-29 20:10:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/rollback_bipartite_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/rollback_bipartite_dsu.hpp
- /library/data_structure/rollback_bipartite_dsu.hpp.html
title: data_structure/rollback_bipartite_dsu.hpp
---
