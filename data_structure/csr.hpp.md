---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_rectangle_sum.hpp
    title: data_structure/offline_rectangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph_query.hpp
    title: graph/graph_query.hpp
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: "\u5168\u90E8\u8F09\u305B\u6728"
  - icon: ':heavy_check_mark:'
    path: tree/simple_tree.hpp
    title: tree/simple_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Rectangle_Sum.test.cpp
    title: test/data_structure/Rectangle_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Shortest_Path2.test.cpp
    title: test/graph/Shortest_Path2.test.cpp
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
  bundledCode: "#line 2 \"data_structure/csr.hpp\"\n\n#include<vector>\n#include<ranges>\n\
    #include<cassert>\n#include<utility>\n\nnamespace noya2::internal {\n\ntemplate<class\
    \ E>\nstruct csr {\n    csr () {}\n    csr (int _n) : n(_n) {}\n    csr (int _n,\
    \ int m) : n(_n){\n        start.reserve(m);\n        elist.reserve(m);\n    }\n\
    \    // ACL style constructor (do not have to call build)\n    csr (int _n, const\
    \ std::vector<std::pair<int,E>> &idx_elem) : n(_n), start(_n + 2), elist(idx_elem.size())\
    \ {\n        for (auto &[i, e] : idx_elem){\n            start[i + 2]++;\n   \
    \     }\n        for (int i = 1; i < n; i++){\n            start[i + 2] += start[i\
    \ + 1];\n        }\n        for (auto &[i, e] : idx_elem){\n            elist[start[i\
    \ + 1]++] = e;\n        }\n        prepared = true;\n    }\n    int add(int idx,\
    \ E elem){\n        int eid = start.size();\n        start.emplace_back(idx);\n\
    \        elist.emplace_back(elem);\n        return eid;\n    }\n    void build(){\n\
    \        if (prepared) return ;\n        int m = start.size();\n        std::vector<E>\
    \ nelist(m);\n        std::vector<int> nstart(n + 2, 0);\n        for (int i =\
    \ 0; i < m; i++){\n            nstart[start[i] + 2]++;\n        }\n        for\
    \ (int i = 1; i < n; i++){\n            nstart[i + 2] += nstart[i + 1];\n    \
    \    }\n        for (int i = 0; i < m; i++){\n            nelist[nstart[start[i]\
    \ + 1]++] = elist[i];\n        }\n        swap(elist,nelist);\n        swap(start,nstart);\n\
    \        prepared = true;\n    }\n    const auto operator[](int idx) const {\n\
    \        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    auto operator[](int idx){\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    const auto operator()(int idx, int l, int r) const {\n        return\
    \ std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    auto operator()(int idx, int l, int r){\n        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    int n;\n    std::vector<int> start;\n    std::vector<E> elist;\n \
    \   bool prepared = false;\n};\n\n} // namespace noya2::internal\n"
  code: "#pragma once\n\n#include<vector>\n#include<ranges>\n#include<cassert>\n#include<utility>\n\
    \nnamespace noya2::internal {\n\ntemplate<class E>\nstruct csr {\n    csr () {}\n\
    \    csr (int _n) : n(_n) {}\n    csr (int _n, int m) : n(_n){\n        start.reserve(m);\n\
    \        elist.reserve(m);\n    }\n    // ACL style constructor (do not have to\
    \ call build)\n    csr (int _n, const std::vector<std::pair<int,E>> &idx_elem)\
    \ : n(_n), start(_n + 2), elist(idx_elem.size()) {\n        for (auto &[i, e]\
    \ : idx_elem){\n            start[i + 2]++;\n        }\n        for (int i = 1;\
    \ i < n; i++){\n            start[i + 2] += start[i + 1];\n        }\n       \
    \ for (auto &[i, e] : idx_elem){\n            elist[start[i + 1]++] = e;\n   \
    \     }\n        prepared = true;\n    }\n    int add(int idx, E elem){\n    \
    \    int eid = start.size();\n        start.emplace_back(idx);\n        elist.emplace_back(elem);\n\
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
    \    }\n    int n;\n    std::vector<int> start;\n    std::vector<E> elist;\n \
    \   bool prepared = false;\n};\n\n} // namespace noya2::internal"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/csr.hpp
  requiredBy:
  - data_structure/offline_rectangle_sum.hpp
  - tree/heavy_light_decomposition.hpp
  - tree/simple_tree.hpp
  - graph/graph_query.hpp
  timestamp: '2024-07-01 23:28:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Rectangle_Sum.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/Vertex_Add_Path_Sum.test.cpp
  - test/graph/Shortest_Path2.test.cpp
documentation_of: data_structure/csr.hpp
layout: document
redirect_from:
- /library/data_structure/csr.hpp
- /library/data_structure/csr.hpp.html
title: data_structure/csr.hpp
---
