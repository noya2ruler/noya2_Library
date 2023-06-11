---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparce_table.hpp
    title: data_structure/sparce_table.hpp
  - icon: ':warning:'
    path: misc/QMC.hpp
    title: misc/QMC.hpp
  - icon: ':heavy_check_mark:'
    path: tree/RerootingDP.hpp
    title: Rerooting DP
  - icon: ':heavy_check_mark:'
    path: tree/Tree_core.hpp
    title: tree/Tree_core.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_RMQ.test.cpp
    title: test/data_structure/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rerooting_DP.test.cpp
    title: test/tree/Rerooting_DP.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define\
    \ rep(i,n) for (int i = 0; i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1);\
    \ i >= 0; i--)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing\
    \ ld = long double;\nusing ull = unsigned long long;\n\nusing namespace std;\n\
    \nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace\
    \ noya2;\n\ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a <=\
    \ b) return false;\n    a = b;\n    return true;\n}\ntemplate <typename T> bool\
    \ chmax(T &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n    return\
    \ true;\n}\n\ntemplate<class T>istream &operator>>(istream &is, vector<T> &v){\n\
    \    for (auto &e : v) is >> e;\n    return is;\n}\n\nvoid fast_io(){\n    cin.tie(0);\
    \ ios::sync_with_stdio(0); cout << fixed << setprecision(15);\n}\n\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\n\n#define rep(i,n) for (int i =\
    \ 0; i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n\
    #define all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\nusing namespace std;\n\nnamespace noya2{\n\n\
    /*\u3000~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\ntemplate\
    \ <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    template<class T>istream &operator>>(istream &is, vector<T> &v){\n    for (auto\
    \ &e : v) is >> e;\n    return is;\n}\n\nvoid fast_io(){\n    cin.tie(0); ios::sync_with_stdio(0);\
    \ cout << fixed << setprecision(15);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - misc/QMC.hpp
  - tree/Tree_core.hpp
  - tree/RerootingDP.hpp
  - data_structure/sparce_table.hpp
  timestamp: '2023-06-10 15:19:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/Rerooting_DP.test.cpp
  - test/data_structure/Static_RMQ.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
