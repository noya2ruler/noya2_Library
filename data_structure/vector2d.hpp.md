---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/vector2d.hpp\"\n\n#include<vector>\n#include<ranges>\n\
    \nnamespace noya2{\n\ntemplate<class E>\nstruct vector2d {\n    vector2d (int\
    \ n_ = 0, int m_ = -1) : n(n_), m(m_) {\n        if (m == -1) m = n-1;\n     \
    \   es.resize(m);\n        start.resize(m,0);\n        if (m == 0) build();\n\
    \    }\n    void add(int from, E e){\n        static int id = 0;\n        es[id]\
    \ = e, start[id] = from;\n        if (++id == m) build();\n    }\n    const auto\
    \ operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\
    \ }\n  private:\n    void build(){\n        std::vector<E> nes(m);\n        std::vector<int>\
    \ nstart(n+1,0);\n        for (int i = 0; i < m; i++) nstart[start[i]+1]++;\n\
    \        for (int i = 0; i < n; i++) nstart[i+1] += nstart[i];\n        auto geta\
    \ = nstart;\n        for (int i = 0; i < m; i++) nes[geta[start[i]]++] = es[i];\n\
    \        std::swap(nes,es); std::swap(nstart,start);\n    }\n    int n, m;\n \
    \   std::vector<E> es;\n    std::vector<int> start;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<vector>\n#include<ranges>\n\nnamespace noya2{\n\n\
    template<class E>\nstruct vector2d {\n    vector2d (int n_ = 0, int m_ = -1) :\
    \ n(n_), m(m_) {\n        if (m == -1) m = n-1;\n        es.resize(m);\n     \
    \   start.resize(m,0);\n        if (m == 0) build();\n    }\n    void add(int\
    \ from, E e){\n        static int id = 0;\n        es[id] = e, start[id] = from;\n\
    \        if (++id == m) build();\n    }\n    const auto operator[](int idx){ return\
    \ std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]); }\n  private:\n\
    \    void build(){\n        std::vector<E> nes(m);\n        std::vector<int> nstart(n+1,0);\n\
    \        for (int i = 0; i < m; i++) nstart[start[i]+1]++;\n        for (int i\
    \ = 0; i < n; i++) nstart[i+1] += nstart[i];\n        auto geta = nstart;\n  \
    \      for (int i = 0; i < m; i++) nes[geta[start[i]]++] = es[i];\n        std::swap(nes,es);\
    \ std::swap(nstart,start);\n    }\n    int n, m;\n    std::vector<E> es;\n   \
    \ std::vector<int> start;\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/vector2d.hpp
  requiredBy: []
  timestamp: '2023-09-10 23:02:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/vector2d.hpp
layout: document
redirect_from:
- /library/data_structure/vector2d.hpp
- /library/data_structure/vector2d.hpp.html
title: data_structure/vector2d.hpp
---
