---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: "\u5168\u90E8\u8F09\u305B\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/FrequencyTableofTreeDistance.test.cpp
    title: test/tree/FrequencyTableofTreeDistance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Add_Path_Sum.test.cpp
    title: test/tree/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/simple_tree.hpp\"\n\n#include <iostream>\n#line 2 \"\
    data_structure/csr.hpp\"\n\n#include<vector>\n#include<ranges>\n#include<cassert>\n\
    #include<utility>\n\nnamespace noya2::internal {\n\ntemplate<class E>\nstruct\
    \ csr {\n    csr () {}\n    csr (int _n) : n(_n) {}\n    csr (int _n, int m) :\
    \ n(_n){\n        start.reserve(m);\n        elist.reserve(m);\n    }\n    //\
    \ ACL style constructor (do not have to call build)\n    csr (int _n, const std::vector<std::pair<int,E>>\
    \ &idx_elem) : n(_n), start(_n + 2), elist(idx_elem.size()) {\n        for (auto\
    \ &[i, e] : idx_elem){\n            start[i + 2]++;\n        }\n        for (int\
    \ i = 1; i < n; i++){\n            start[i + 2] += start[i + 1];\n        }\n\
    \        for (auto &[i, e] : idx_elem){\n            elist[start[i + 1]++] = e;\n\
    \        }\n        prepared = true;\n    }\n    int add(int idx, E elem){\n \
    \       int eid = start.size();\n        start.emplace_back(idx);\n        elist.emplace_back(elem);\n\
    \        return eid;\n    }\n    void build(){\n        if (prepared) return ;\n\
    \        int m = start.size();\n        std::vector<E> nelist(m);\n        std::vector<int>\
    \ nstart(n + 2, 0);\n        for (int i = 0; i < m; i++){\n            nstart[start[i]\
    \ + 2]++;\n        }\n        for (int i = 1; i < n; i++){\n            nstart[i\
    \ + 2] += nstart[i + 1];\n        }\n        for (int i = 0; i < m; i++){\n  \
    \          nelist[nstart[start[i] + 1]++] = elist[i];\n        }\n        swap(elist,nelist);\n\
    \        swap(start,nstart);\n        prepared = true;\n    }\n    const auto\
    \ operator[](int idx) const {\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    auto operator[](int idx){\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    const auto operator()(int idx, int l, int r) const {\n        return\
    \ std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    auto operator()(int idx, int l, int r){\n        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    size_t size() const {\n        return n;\n    }\n    int n;\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    bool prepared = false;\n};\n\n} // namespace\
    \ noya2::internal\n#line 5 \"tree/simple_tree.hpp\"\n\nnamespace noya2 {\n\nstruct\
    \ simple_tree {\n    internal::csr<int> g;\n    simple_tree () {}\n    simple_tree\
    \ (int _n) : g(_n, (_n - 1)*2) {\n        if (_n == 1){\n            g.build();\n\
    \        }\n    }\n    void add_edge(int u, int v){\n        g.add(u, v);\n  \
    \      int id = g.add(v, u);\n        if (id + 1 == (g.n - 1)*2) g.build();\n\
    \    }\n    void input(int indexed = 1){\n        for (int i = 0; i < g.n - 1;\
    \ i++){\n            int u, v; cin >> u >> v;\n            u -= indexed, v -=\
    \ indexed;\n            add_edge(u, v);\n        }\n    }\n    void input_parents(int\
    \ indexed = 1){\n        for (int i = 0; i < g.n - 1; i++){\n            int v;\
    \ cin >> v;\n            v -= indexed;\n            add_edge(i + 1, v);\n    \
    \    }\n    }\n    const auto operator[](int v) const {\n        return g[v];\n\
    \    }\n    auto operator[](int v){\n        return g[v];\n    }\n    size_t size()\
    \ const {\n        return g.size();\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <iostream>\n#include \"../data_structure/csr.hpp\"\
    \n\nnamespace noya2 {\n\nstruct simple_tree {\n    internal::csr<int> g;\n   \
    \ simple_tree () {}\n    simple_tree (int _n) : g(_n, (_n - 1)*2) {\n        if\
    \ (_n == 1){\n            g.build();\n        }\n    }\n    void add_edge(int\
    \ u, int v){\n        g.add(u, v);\n        int id = g.add(v, u);\n        if\
    \ (id + 1 == (g.n - 1)*2) g.build();\n    }\n    void input(int indexed = 1){\n\
    \        for (int i = 0; i < g.n - 1; i++){\n            int u, v; cin >> u >>\
    \ v;\n            u -= indexed, v -= indexed;\n            add_edge(u, v);\n \
    \       }\n    }\n    void input_parents(int indexed = 1){\n        for (int i\
    \ = 0; i < g.n - 1; i++){\n            int v; cin >> v;\n            v -= indexed;\n\
    \            add_edge(i + 1, v);\n        }\n    }\n    const auto operator[](int\
    \ v) const {\n        return g[v];\n    }\n    auto operator[](int v){\n     \
    \   return g[v];\n    }\n    size_t size() const {\n        return g.size();\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn:
  - data_structure/csr.hpp
  isVerificationFile: false
  path: tree/simple_tree.hpp
  requiredBy:
  - tree/heavy_light_decomposition.hpp
  timestamp: '2024-10-30 04:43:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Vertex_Add_Path_Sum.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/FrequencyTableofTreeDistance.test.cpp
documentation_of: tree/simple_tree.hpp
layout: document
redirect_from:
- /library/tree/simple_tree.hpp
- /library/tree/simple_tree.hpp.html
title: tree/simple_tree.hpp
---
