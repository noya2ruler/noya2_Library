---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/bipartite_dsu.hpp\"\n\n#line 2 \"data_structure/dsu.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\nnamespace noya2{\n\
    \nstruct dsu {\n  public:\n    dsu() : _n(0), _cc(0) {}\n    dsu(int n) : _n(n),\
    \ _cc(n), parent_or_size(n, -1) {}\n\n    int merge(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a),\
    \ y = leader(b);\n        if (x == y) return x;\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        _cc--;\n        return x;\n    }\n\n\
    \    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int\
    \ a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0)\
    \ return a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n \
    \   }\n\n    int size(int a) {\n        assert(0 <= a && a < _n);\n        return\
    \ -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> leader_buf(_n), group_size(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \    int group_count() const {\n        return _cc;\n    }\n\n  private:\n   \
    \ int _n, _cc;\n    // root node: -1 * component size\n    // otherwise: parent\n\
    \    std::vector<int> parent_or_size;\n};\n\n} // namespace noya2\n#line 4 \"\
    data_structure/bipartite_dsu.hpp\"\n\nnamespace noya2 {\n\nstruct bipartite_dsu\
    \ {\n    int n, cc_bipartite;\n    dsu d;\n    bipartite_dsu (int _n = 0) : n(_n),\
    \ cc_bipartite(_n), d(_n*2){}\n    void inner_merge(int u, int v, int up, int\
    \ vp){\n        if (d.same(u, v)){\n            assert(d.same(up, vp));\n    \
    \        return ;\n        }\n        if (inner_is_bipartite(u) || inner_is_bipartite(v)){\n\
    \            cc_bipartite--;\n        }\n        d.merge(u, v);\n        d.merge(up,\
    \ vp);\n    }\n    void add_edge(int u, int v, bool w = true){\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        if (w){\n       \
    \     inner_merge(u, n + v, v, n + u);\n        }\n        else {\n          \
    \  inner_merge(u, v, n + u, n + v);\n        }\n    }\n    bool is_bipartite()\
    \ const {\n        return d.group_count() == cc_bipartite * 2;\n    }\n    bool\
    \ is_bipartite(int v){\n        assert(0 <= v && v < n);\n        return !d.same(v,\
    \ n + v);\n    }\n    bool inner_is_bipartite(int v){\n        return !d.same(v,\
    \ (v < n ? n + v : v - n));\n    }\n    int bipartite_component_count() const\
    \ {\n        return cc_bipartite;\n    }\n    int non_bipartite_component_count()\
    \ const {\n        return d.group_count() - cc_bipartite * 2;\n    }\n    int\
    \ component_count() const {\n        return d.group_count() - cc_bipartite;\n\
    \    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../data_structure/dsu.hpp\"\n\nnamespace noya2\
    \ {\n\nstruct bipartite_dsu {\n    int n, cc_bipartite;\n    dsu d;\n    bipartite_dsu\
    \ (int _n = 0) : n(_n), cc_bipartite(_n), d(_n*2){}\n    void inner_merge(int\
    \ u, int v, int up, int vp){\n        if (d.same(u, v)){\n            assert(d.same(up,\
    \ vp));\n            return ;\n        }\n        if (inner_is_bipartite(u) ||\
    \ inner_is_bipartite(v)){\n            cc_bipartite--;\n        }\n        d.merge(u,\
    \ v);\n        d.merge(up, vp);\n    }\n    void add_edge(int u, int v, bool w\
    \ = true){\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        if (w){\n            inner_merge(u, n + v, v, n + u);\n        }\n  \
    \      else {\n            inner_merge(u, v, n + u, n + v);\n        }\n    }\n\
    \    bool is_bipartite() const {\n        return d.group_count() == cc_bipartite\
    \ * 2;\n    }\n    bool is_bipartite(int v){\n        assert(0 <= v && v < n);\n\
    \        return !d.same(v, n + v);\n    }\n    bool inner_is_bipartite(int v){\n\
    \        return !d.same(v, (v < n ? n + v : v - n));\n    }\n    int bipartite_component_count()\
    \ const {\n        return cc_bipartite;\n    }\n    int non_bipartite_component_count()\
    \ const {\n        return d.group_count() - cc_bipartite * 2;\n    }\n    int\
    \ component_count() const {\n        return d.group_count() - cc_bipartite;\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn:
  - data_structure/dsu.hpp
  isVerificationFile: false
  path: data_structure/bipartite_dsu.hpp
  requiredBy: []
  timestamp: '2025-04-29 20:10:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/bipartite_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/bipartite_dsu.hpp
- /library/data_structure/bipartite_dsu.hpp.html
title: data_structure/bipartite_dsu.hpp
---
