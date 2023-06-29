---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: geometry/partition_by_circle.hpp
    title: geometry/partition_by_circle.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/geometry/aoj1198.test.cpp
    title: test/geometry/aoj1198.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/base_ld.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ ll linf = 2e18;\n#line 4 \"geometry/base_ld.hpp\"\n\nnamespace noya2 {\n\nusing\
    \ vec = complex<ld>;\n\nconst ld PI = acos(-1);\n\nvoid ldout(int len = 20) {\n\
    \    cout << fixed << setprecision(len);\n}\n\nint sgn(ld a, const ld eps = 1e-7)\
    \ {\n    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nbool same_vec(vec a,\
    \ vec b) {\n    a -= b;\n    return sgn(a.real()) == 0 && sgn(a.imag()) == 0;\n\
    }\n\nld dot(const vec &a, const vec &b) {\n    return (conj(a) * b).real();\n\
    }\n\nld cross(const vec &a, const vec &b) {\n    return (conj(a) * b).imag();\n\
    }\n\nint isp(const vec &a, const vec &b, const vec &c) {\n    int cross_sgn =\
    \ sgn(cross(b - a, c - a));\n    if (cross_sgn == 0) {\n        if (sgn(dot(b\
    \ - a, c - a)) < 0) return -2;\n        if (sgn(dot(a - b, c - b)) < 0) return\
    \ 2;\n    }\n    return cross_sgn;\n}\n\nvec rot90(const vec &a) {\n    return\
    \ {-a.imag(), a.real()};\n}\n\nvec rot(const vec &a, ld rad) {\n    return a *\
    \ vec(cosl(rad), sinl(rad));\n}\n\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace noya2\
    \ {\n\nusing vec = complex<ld>;\n\nconst ld PI = acos(-1);\n\nvoid ldout(int len\
    \ = 20) {\n    cout << fixed << setprecision(len);\n}\n\nint sgn(ld a, const ld\
    \ eps = 1e-7) {\n    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nbool same_vec(vec\
    \ a, vec b) {\n    a -= b;\n    return sgn(a.real()) == 0 && sgn(a.imag()) ==\
    \ 0;\n}\n\nld dot(const vec &a, const vec &b) {\n    return (conj(a) * b).real();\n\
    }\n\nld cross(const vec &a, const vec &b) {\n    return (conj(a) * b).imag();\n\
    }\n\nint isp(const vec &a, const vec &b, const vec &c) {\n    int cross_sgn =\
    \ sgn(cross(b - a, c - a));\n    if (cross_sgn == 0) {\n        if (sgn(dot(b\
    \ - a, c - a)) < 0) return -2;\n        if (sgn(dot(a - b, c - b)) < 0) return\
    \ 2;\n    }\n    return cross_sgn;\n}\n\nvec rot90(const vec &a) {\n    return\
    \ {-a.imag(), a.real()};\n}\n\nvec rot(const vec &a, ld rad) {\n    return a *\
    \ vec(cosl(rad), sinl(rad));\n}\n\n\n}  // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry/base_ld.hpp
  requiredBy:
  - geometry/partition_by_circle.hpp
  timestamp: '2023-06-27 02:17:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/geometry/aoj1198.test.cpp
documentation_of: geometry/base_ld.hpp
layout: document
redirect_from:
- /library/geometry/base_ld.hpp
- /library/geometry/base_ld.hpp.html
title: geometry/base_ld.hpp
---
