---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/concepts.hpp
    title: misc/concepts.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Unionfind_with_Potential_NonCommutative_Group.test.cpp
    title: test/data_structure/Unionfind_with_Potential_NonCommutative_Group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj_dsl_1_b.test.cpp
    title: test/data_structure/aoj_dsl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/potentialized_dsu.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <algorithm>\n\n#line 2 \"misc/concepts.hpp\"\n\n\
    #include<concepts>\n\nnamespace noya2 {\n\ntemplate<class monoid>\nconcept Monoid\
    \ = requires {\n    typename monoid::value_type;\n    {monoid::op(declval<typename\
    \ monoid::value_type>(),declval<typename monoid::value_type>())} -> std::same_as<typename\
    \ monoid::value_type>;\n    {monoid::e()} -> std::same_as<typename monoid::value_type>;\n\
    };\n\ntemplate<class group>\nconcept Group = requires {\n    requires Monoid<group>;\n\
    \    {group::inv(declval<typename group::value_type>())} -> std::same_as<typename\
    \ group::value_type>;\n};\n\n} // namespace noya2\n#line 8 \"data_structure/potentialized_dsu.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<Group G>\nstruct potentialized_dsu {\n    using\
    \ T = typename G::value_type;\n    potentialized_dsu (int n = 0) : _n(n), parent_or_size(n,-1),\
    \ pot(n, G::e()) {}\n    // p[u] = op(p[v], d), u is higher than v by d\n    int\
    \ merge(int u, int v, T d){\n        int x = leader(u), y = leader(v);\n     \
    \   if (x == y){\n            if (diff(u, v) == d) return x;\n            else\
    \ return -1;\n        }\n        d = G::op(potential(u), G::inv(G::op(potential(v),\
    \ d)));\n        if (-parent_or_size[x] < -parent_or_size[y]){\n            d\
    \ = G::inv(d);\n            std::swap(x, y);\n        }\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        pot[y] = d;\n\
    \        return x;\n    }\n    int leader(int v){\n        assert(0 <= v && v\
    \ < _n);\n        if (parent_or_size[v] < 0) return v;\n        int l = leader(parent_or_size[v]);\n\
    \        pot[v] = G::op(pot[parent_or_size[v]], pot[v]);\n        return parent_or_size[v]\
    \ = l;\n    }\n    bool same(int u, int v){\n        return leader(u) == leader(v);\n\
    \    }\n    int size(int v){\n        return -parent_or_size[leader(v)];\n   \
    \ }\n    T potential(int v){\n        leader(v);\n        return pot[v];\n   \
    \ }\n    // p[u] = op(p[v], d)\n    // d = op(inv(p[v]), p[u])\n    T diff(int\
    \ u, int v){\n        return G::op(G::inv(potential(v)), potential(u));\n    }\n\
    \    std::vector<std::vector<int>> groups() {\n        std::vector<int> leader_buf(_n),\
    \ group_size(_n);\n        for (int i = 0; i < _n; i++) {\n            leader_buf[i]\
    \ = leader(i);\n            group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    \  private:\n    int _n;\n    std::vector<int> parent_or_size;\n    std::vector<T>\
    \ pot;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\
    \n#include\"../misc/concepts.hpp\"\n\nnamespace noya2 {\n\ntemplate<Group G>\n\
    struct potentialized_dsu {\n    using T = typename G::value_type;\n    potentialized_dsu\
    \ (int n = 0) : _n(n), parent_or_size(n,-1), pot(n, G::e()) {}\n    // p[u] =\
    \ op(p[v], d), u is higher than v by d\n    int merge(int u, int v, T d){\n  \
    \      int x = leader(u), y = leader(v);\n        if (x == y){\n            if\
    \ (diff(u, v) == d) return x;\n            else return -1;\n        }\n      \
    \  d = G::op(potential(u), G::inv(G::op(potential(v), d)));\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]){\n            d = G::inv(d);\n            std::swap(x,\
    \ y);\n        }\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        pot[y] = d;\n        return x;\n    }\n    int leader(int v){\n\
    \        assert(0 <= v && v < _n);\n        if (parent_or_size[v] < 0) return\
    \ v;\n        int l = leader(parent_or_size[v]);\n        pot[v] = G::op(pot[parent_or_size[v]],\
    \ pot[v]);\n        return parent_or_size[v] = l;\n    }\n    bool same(int u,\
    \ int v){\n        return leader(u) == leader(v);\n    }\n    int size(int v){\n\
    \        return -parent_or_size[leader(v)];\n    }\n    T potential(int v){\n\
    \        leader(v);\n        return pot[v];\n    }\n    // p[u] = op(p[v], d)\n\
    \    // d = op(inv(p[v]), p[u])\n    T diff(int u, int v){\n        return G::op(G::inv(potential(v)),\
    \ potential(u));\n    }\n    std::vector<std::vector<int>> groups() {\n      \
    \  std::vector<int> leader_buf(_n), group_size(_n);\n        for (int i = 0; i\
    \ < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    \  private:\n    int _n;\n    std::vector<int> parent_or_size;\n    std::vector<T>\
    \ pot;\n};\n\n} // namespace noya2"
  dependsOn:
  - misc/concepts.hpp
  isVerificationFile: false
  path: data_structure/potentialized_dsu.hpp
  requiredBy: []
  timestamp: '2024-08-13 15:38:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Unionfind_with_Potential_NonCommutative_Group.test.cpp
  - test/data_structure/aoj_dsl_1_b.test.cpp
documentation_of: data_structure/potentialized_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/potentialized_dsu.hpp
- /library/data_structure/potentialized_dsu.hpp.html
title: data_structure/potentialized_dsu.hpp
---
