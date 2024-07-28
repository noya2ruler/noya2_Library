---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/CycleDetectionDirected.test.cpp
    title: test/graph/CycleDetectionDirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/cycle_detection.hpp\"\n\n#include <optional>\n#include\
    \ <vector>\n#include <utility>\n#include <algorithm>\n\n#line 2 \"data_structure/csr.hpp\"\
    \n\n#line 4 \"data_structure/csr.hpp\"\n#include<ranges>\n#include<cassert>\n\
    #line 7 \"data_structure/csr.hpp\"\n\nnamespace noya2::internal {\n\ntemplate<class\
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
    \   bool prepared = false;\n};\n\n} // namespace noya2::internal\n#line 9 \"graph/cycle_detection.hpp\"\
    \n\nnamespace noya2 {\n\nstd::optional<std::vector<int>> cycle_detection_directed(int\
    \ n, const std::vector<std::pair<int,int>> &es){\n    internal::csr<std::pair<int,int>>\
    \ g(n,es.size());\n    for (int i = 0; auto [u, v] : es){\n        g.add(u,std::pair<int,int>(v,\
    \ i));\n        i++;\n    }\n    g.build();\n    std::vector<bool> seen(n,false),\
    \ done(n,false);\n    std::vector<int> cycle;\n    // -1:over,-2:done\n    auto\
    \ dfs = [&](auto sfs, int v, int pid) -> int {\n        if (seen[v]) return v;\n\
    \        if (done[v]) return -1;\n        seen[v] = true;\n        for (auto &[to,\
    \ eid] : g[v]) if (eid != pid){\n            int nxt = sfs(sfs, to, eid);\n  \
    \          if (nxt != -1){\n                if (nxt == -2) return -2;\n      \
    \          cycle.emplace_back(eid);\n                if (nxt == v) return -2;\n\
    \                return nxt;\n            }\n        }\n        seen[v] = false;\n\
    \        done[v] = true;\n        return -1;\n    };\n    for (int i = 0; i <\
    \ n; i++){\n        if (dfs(dfs, i, -1) == -2){\n            std::reverse(cycle.begin(),\
    \ cycle.end());\n            return cycle;\n        }\n    }\n    return std::nullopt;\n\
    }\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <optional>\n#include <vector>\n#include <utility>\n\
    #include <algorithm>\n\n#include\"data_structure/csr.hpp\"\n\nnamespace noya2\
    \ {\n\nstd::optional<std::vector<int>> cycle_detection_directed(int n, const std::vector<std::pair<int,int>>\
    \ &es){\n    internal::csr<std::pair<int,int>> g(n,es.size());\n    for (int i\
    \ = 0; auto [u, v] : es){\n        g.add(u,std::pair<int,int>(v, i));\n      \
    \  i++;\n    }\n    g.build();\n    std::vector<bool> seen(n,false), done(n,false);\n\
    \    std::vector<int> cycle;\n    // -1:over,-2:done\n    auto dfs = [&](auto\
    \ sfs, int v, int pid) -> int {\n        if (seen[v]) return v;\n        if (done[v])\
    \ return -1;\n        seen[v] = true;\n        for (auto &[to, eid] : g[v]) if\
    \ (eid != pid){\n            int nxt = sfs(sfs, to, eid);\n            if (nxt\
    \ != -1){\n                if (nxt == -2) return -2;\n                cycle.emplace_back(eid);\n\
    \                if (nxt == v) return -2;\n                return nxt;\n     \
    \       }\n        }\n        seen[v] = false;\n        done[v] = true;\n    \
    \    return -1;\n    };\n    for (int i = 0; i < n; i++){\n        if (dfs(dfs,\
    \ i, -1) == -2){\n            std::reverse(cycle.begin(), cycle.end());\n    \
    \        return cycle;\n        }\n    }\n    return std::nullopt;\n}\n\n} //\
    \ namespace noya2"
  dependsOn:
  - data_structure/csr.hpp
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2024-07-02 16:43:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/CycleDetectionDirected.test.cpp
documentation_of: graph/cycle_detection.hpp
layout: document
redirect_from:
- /library/graph/cycle_detection.hpp
- /library/graph/cycle_detection.hpp.html
title: graph/cycle_detection.hpp
---
