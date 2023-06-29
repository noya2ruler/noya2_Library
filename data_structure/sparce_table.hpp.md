---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
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
  bundledCode: "#line 2 \"data_structure/sparce_table.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,n) for (int i = 0; i < (int)(n);\
    \ i++)\n#define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n#define all(v)\
    \ v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\nusing ull\
    \ = unsigned long long;\n\nusing namespace std;\n\nnamespace noya2{\n\n/*\u3000\
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\ntemplate <typename\
    \ T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n\
    \    return true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n \
    \   if (a >= b) return false;\n    a = b;\n    return true;\n}\n\ntemplate<class\
    \ T>istream &operator>>(istream &is, vector<T> &v){\n    for (auto &e : v) is\
    \ >> e;\n    return is;\n}\n\nvoid fast_io(){\n    cin.tie(0); ios::sync_with_stdio(0);\
    \ cout << fixed << setprecision(15);\n}\n\nconst int iinf = 1'000'000'007;\nconst\
    \ ll linf = 2e18;\n#line 4 \"data_structure/sparce_table.hpp\"\n\nnamespace noya2{\n\
    \ntemplate<class S, S (*op)(S, S)>\nstruct SparseTable{\n    vector<vector<S>>\
    \ table;\n    SparseTable (const vector<S> &vec){\n        int n = vec.size(),\
    \ n2 = 0;\n        while ((1<<n2) < n) n2++;\n        table.resize(n2+1);\n  \
    \      for (int i = 0; i <= n2; i++){\n            table[i].resize(n);\n     \
    \       if (i == 0){\n                for (int j = 0; j < n; j++){\n         \
    \           table[i][j] = vec[j];\n                }\n            }\n        \
    \    else {\n                for (int j = 0; j < n; j++){\n                  \
    \  if (j + (1 << (i-1)) < n) table[i][j] = op(table[i-1][j],table[i-1][j + (1\
    \ << (i-1))]);\n                    else table[i][j] = table[i-1][j];\n      \
    \          }\n            }\n        }\n    }\n    // \u5358\u4F4D\u5143\u3092\
    \u8981\u6C42\u3057\u306A\u3044\u306E\u3067 if (l >= r) return e() \u307F\u305F\
    \u3044\u306A\u3053\u3068\u3092\u3057\u3066\u3044\u306A\u3044\u3001\u6CE8\u610F\
    \u3059\u308B\u3053\u3068\uFF01\uFF01\n    S get(int l, int r){\n        assert(r\
    \ - l > 0);\n        int lgs = 31 - __builtin_clz((unsigned int)(r-l));\n    \
    \    return op(table[lgs][l], table[lgs][r - (1 << lgs)]);\n    }\n};\n\n} //\
    \ namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\
    \ntemplate<class S, S (*op)(S, S)>\nstruct SparseTable{\n    vector<vector<S>>\
    \ table;\n    SparseTable (const vector<S> &vec){\n        int n = vec.size(),\
    \ n2 = 0;\n        while ((1<<n2) < n) n2++;\n        table.resize(n2+1);\n  \
    \      for (int i = 0; i <= n2; i++){\n            table[i].resize(n);\n     \
    \       if (i == 0){\n                for (int j = 0; j < n; j++){\n         \
    \           table[i][j] = vec[j];\n                }\n            }\n        \
    \    else {\n                for (int j = 0; j < n; j++){\n                  \
    \  if (j + (1 << (i-1)) < n) table[i][j] = op(table[i-1][j],table[i-1][j + (1\
    \ << (i-1))]);\n                    else table[i][j] = table[i-1][j];\n      \
    \          }\n            }\n        }\n    }\n    // \u5358\u4F4D\u5143\u3092\
    \u8981\u6C42\u3057\u306A\u3044\u306E\u3067 if (l >= r) return e() \u307F\u305F\
    \u3044\u306A\u3053\u3068\u3092\u3057\u3066\u3044\u306A\u3044\u3001\u6CE8\u610F\
    \u3059\u308B\u3053\u3068\uFF01\uFF01\n    S get(int l, int r){\n        assert(r\
    \ - l > 0);\n        int lgs = 31 - __builtin_clz((unsigned int)(r-l));\n    \
    \    return op(table[lgs][l], table[lgs][r - (1 << lgs)]);\n    }\n};\n\n} //\
    \ namespace noya2"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/sparce_table.hpp
  requiredBy: []
  timestamp: '2023-06-12 11:44:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Static_RMQ.test.cpp
documentation_of: data_structure/sparce_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparce_table.hpp
- /library/data_structure/sparce_table.hpp.html
title: data_structure/sparce_table.hpp
---
