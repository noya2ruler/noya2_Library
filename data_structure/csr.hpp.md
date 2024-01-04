---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/graph_query.hpp
    title: graph/graph_query.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Shortest_Path2.test.cpp
    title: test/graph/Shortest_Path2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/csr.hpp\"\n\n#include<vector>\n#include<ranges>\n\
    #include<cassert>\n#include<utility>\n\nnamespace noya2 {\n\ntemplate<class E>\n\
    struct csr {\n    csr (int n_ = 0, int m_ = -1) : n(n_), m(m_) {\n        if (m\
    \ >= 0){\n            es.reserve(m);\n            start.reserve(m);\n        }\n\
    \        if (m == 0){\n            build();\n        }\n    }\n    int add(int\
    \ idx, E elem){\n        int eid = start.size();\n        es.emplace_back(elem);\n\
    \        start.emplace_back(idx);\n        if (eid+1 == m) build();\n        return\
    \ eid;\n    }\n    void build(){\n        if (m == -2) return ;\n        m = start.size();\n\
    \        std::vector<E> nes(m);\n        std::vector<int> nstart(n+2,0);\n   \
    \     for (int i = 0; i < m; i++) nstart[start[i]+2]++;\n        for (int i =\
    \ 1; i < n; i++) nstart[i+2] += nstart[i+1];\n        for (int i = 0; i < m; i++)\
    \ nes[nstart[start[i]+1]++] = es[i];\n        swap(es,nes);\n        swap(start,nstart);\n\
    \        m = -2;\n    }\n    const auto operator[](int idx) const {\n        assert(m\
    \ == -2);\n        return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\n\
    \    }\n  private:\n    int n, m;\n    std::vector<E> es;\n    std::vector<int>\
    \ start;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<vector>\n#include<ranges>\n#include<cassert>\n#include<utility>\n\
    \nnamespace noya2 {\n\ntemplate<class E>\nstruct csr {\n    csr (int n_ = 0, int\
    \ m_ = -1) : n(n_), m(m_) {\n        if (m >= 0){\n            es.reserve(m);\n\
    \            start.reserve(m);\n        }\n        if (m == 0){\n            build();\n\
    \        }\n    }\n    int add(int idx, E elem){\n        int eid = start.size();\n\
    \        es.emplace_back(elem);\n        start.emplace_back(idx);\n        if\
    \ (eid+1 == m) build();\n        return eid;\n    }\n    void build(){\n     \
    \   if (m == -2) return ;\n        m = start.size();\n        std::vector<E> nes(m);\n\
    \        std::vector<int> nstart(n+2,0);\n        for (int i = 0; i < m; i++)\
    \ nstart[start[i]+2]++;\n        for (int i = 1; i < n; i++) nstart[i+2] += nstart[i+1];\n\
    \        for (int i = 0; i < m; i++) nes[nstart[start[i]+1]++] = es[i];\n    \
    \    swap(es,nes);\n        swap(start,nstart);\n        m = -2;\n    }\n    const\
    \ auto operator[](int idx) const {\n        assert(m == -2);\n        return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\n\
    \    }\n  private:\n    int n, m;\n    std::vector<E> es;\n    std::vector<int>\
    \ start;\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/csr.hpp
  requiredBy:
  - graph/graph_query.hpp
  timestamp: '2024-01-04 13:41:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Shortest_Path2.test.cpp
documentation_of: data_structure/csr.hpp
layout: document
redirect_from:
- /library/data_structure/csr.hpp
- /library/data_structure/csr.hpp.html
title: data_structure/csr.hpp
---
