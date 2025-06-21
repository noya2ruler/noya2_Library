---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_RMQ.test.cpp
    title: test/data_structure/Static_RMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_table.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\nnamespace noya2{\n\ntemplate<class S, S (*op)(S, S)>\nstruct\
    \ sparse_table {\n    std::vector<std::vector<S>> table;\n    sparse_table ()\
    \ {}\n    sparse_table (const std::vector<S> &vec){\n        int n = vec.size(),\
    \ n2 = 0;\n        while ((1<<n2) <= n) n2++;\n        table.resize(n2);\n   \
    \     table[0] = vec;\n        for (int i = 0; i < n2-1; i++){\n            int\
    \ nsz = table[i].size() - (1 << i);\n            table[i + 1].resize(nsz);\n \
    \           for (int j = 0; j < nsz; j++){\n                table[i + 1][j] =\
    \ op(table[i][j], table[i][j + (1 << i)]);\n            }\n        }\n    }\n\
    \    // \u5358\u4F4D\u5143\u3092\u8981\u6C42\u3057\u306A\u3044\u306E\u3067 if\
    \ (l >= r) return e() \u307F\u305F\u3044\u306A\u3053\u3068\u3092\u3057\u3066\u3044\
    \u306A\u3044\u3001\u6CE8\u610F\u3059\u308B\u3053\u3068\uFF01\uFF01\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= (int)(table[0].size()));\n\
    \        int lgs = 31 - __builtin_clz((unsigned int)(r-l));\n        return op(table[lgs][l],\
    \ table[lgs][r - (1 << lgs)]);\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\nnamespace noya2{\n\
    \ntemplate<class S, S (*op)(S, S)>\nstruct sparse_table {\n    std::vector<std::vector<S>>\
    \ table;\n    sparse_table () {}\n    sparse_table (const std::vector<S> &vec){\n\
    \        int n = vec.size(), n2 = 0;\n        while ((1<<n2) <= n) n2++;\n   \
    \     table.resize(n2);\n        table[0] = vec;\n        for (int i = 0; i <\
    \ n2-1; i++){\n            int nsz = table[i].size() - (1 << i);\n           \
    \ table[i + 1].resize(nsz);\n            for (int j = 0; j < nsz; j++){\n    \
    \            table[i + 1][j] = op(table[i][j], table[i][j + (1 << i)]);\n    \
    \        }\n        }\n    }\n    // \u5358\u4F4D\u5143\u3092\u8981\u6C42\u3057\
    \u306A\u3044\u306E\u3067 if (l >= r) return e() \u307F\u305F\u3044\u306A\u3053\
    \u3068\u3092\u3057\u3066\u3044\u306A\u3044\u3001\u6CE8\u610F\u3059\u308B\u3053\
    \u3068\uFF01\uFF01\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l < r && r <= (int)(table[0].size()));\n        int lgs = 31 - __builtin_clz((unsigned\
    \ int)(r-l));\n        return op(table[lgs][l], table[lgs][r - (1 << lgs)]);\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2025-06-21 17:06:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Static_RMQ.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---
