---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/euler_circuit_counting.hpp
    title: math/euler_circuit_counting.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/CountingEulerianCircuits.test.cpp
    title: test/math/CountingEulerianCircuits.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/spanning_tree_counting.hpp\"\n\n#line 2 \"math/matrix.hpp\"\
    \n\n#include <vector>\n#include <array>\n#include <iostream>\n#include <ranges>\n\
    #include <cassert>\n\nnamespace noya2 {\n\ntemplate<typename T, size_t hw = -1uz>\n\
    struct matrix {\n    static constexpr int h = hw, w = hw;\n    std::array<T, hw*hw>\
    \ m;\n    matrix () : m({}) {}\n    matrix (const std::array<T, hw*hw> &_m) :\
    \ m(_m) {}\n    matrix (const std::array<std::array<T, hw>, hw> &_m){\n      \
    \  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){\n            m[idx(i,j)]\
    \ = _m[i][j];\n        }\n    }\n    matrix (const std::vector<std::vector<T>>\
    \ &_m){\n        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){\n  \
    \          m[idx(i,j)] = _m[i][j];\n        }\n    }\n    auto operator[](int\
    \ i) const {\n        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);\n\
    \    }\n    auto operator[](int i){\n        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);\n\
    \    }\n    matrix &operator+= (const matrix &r){\n        for (int i = 0; i <\
    \ h; ++i){\n            for (int j = 0; j < w; ++j){\n                m[idx(i,j)]\
    \ += r.m[idx(i,j)];\n            }\n        }\n        return *this;\n    }\n\
    \    matrix &operator-= (const matrix &r){\n        for (int i = 0; i < h; ++i){\n\
    \            for (int j = 0; j < w; ++j){\n                m[idx(i,j)] -= r.m[idx(i,j)];\n\
    \            }\n        }\n        return *this;\n    }\n    matrix &operator*=\
    \ (const matrix &r){\n        matrix ret;\n        for (int i = 0; i < h; i++){\n\
    \            for (int k = 0; k < w; k++){\n                for (int j = 0; j <\
    \ r.w; j++){\n                    ret.m[idx(i,j)] += m[idx(i,k)] * r.m[idx(k,j)];\n\
    \                }\n            }\n        }\n        return *this = ret;\n  \
    \  }\n    matrix operator+ (const matrix &r) const { return matrix(*this) += r;\
    \ }\n    matrix operator- (const matrix &r) const { return matrix(*this) -= r;\
    \ }\n    matrix operator* (const matrix &r) const { return matrix(*this) *= r;\
    \ }\n    matrix& operator*=(const T &r){\n        for (int i = 0; i < h; ++i){\n\
    \            for (int j = 0; j < w; ++j){\n                m[idx(i,j)] *= r;\n\
    \            }\n        }\n        return *this;\n    }\n    friend matrix operator*\
    \ (const T &r, const matrix &mat){\n        return matrix(mat) *= r;\n    }\n\
    \    friend matrix operator* (const matrix &mat, const T &r){\n        return\
    \ matrix(mat) *= r;\n    }\n    matrix pow(long long n){\n        if (n == 0)\
    \ return e();\n        matrix f = pow(n / 2);\n        matrix ret = f * f;\n \
    \       if (n & 1) ret *= (*this);\n        return ret;\n    }\n    int idx(int\
    \ i, int j){\n        return i * w + j;\n    }\n    static matrix e(){\n     \
    \   matrix ret;\n        for (int i = 0; i < h; i++){\n            ret[i][i] =\
    \ T(1);\n        }\n        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const matrix &mat){\n        for (int i = 0; i < mat.h; i++){\n       \
    \     if (i != 0) os << '\\n';\n            for (int j = 0; j < mat.w; j++){\n\
    \                if (j != 0) os << ' ';\n                os << mat[i][j];\n  \
    \          }\n        }\n        return os;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, matrix &mat){\n        for (int i = 0; i < mat.h; i++){\n            for\
    \ (int j = 0; j < mat.w; j++){\n                is >> mat[i][j];\n           \
    \ }\n        }\n        return is;\n    }\n    friend bool operator==(const matrix\
    \ &a, const matrix &b){\n        for (int i = 0; i < a.h; i++){\n            for\
    \ (int j = 0; j < a.w; j++){\n                if (a[i][j] != b[i][j]){\n     \
    \               return false;\n                }\n            }\n        }\n \
    \       return true;\n    }\n};\n\ntemplate<typename T>\nstruct matrix<T,-1uz>\
    \ {\n    int h, w;\n    std::vector<T> m;\n    matrix () {}\n    matrix (int _h)\
    \ : matrix(_h,_h) {}\n    matrix (int _h, int _w) : h(_h), w(_w), m(_h*_w) {}\n\
    \    matrix (int _h, int _w, const std::vector<T> &_m) : h(_h), w(_w), m(_m) {\n\
    \        assert((int)_m.size() == _h*_w);\n    }\n    matrix (const std::vector<std::vector<T>>\
    \ &_m){\n        h = _m.size();\n        assert(h >= 1);\n        w = _m[0].size();\n\
    \        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){\n          \
    \  m[idx(i,j)] = _m[i][j];\n        }\n    }\n    auto operator[](int i) const\
    \ {\n        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);\n\
    \    }\n    auto operator[](int i){\n        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);\n\
    \    }\n    matrix &operator+= (const matrix &r){\n        for (int i = 0; i <\
    \ h; ++i){\n            for (int j = 0; j < w; ++j){\n                m[idx(i,j)]\
    \ += r.m[idx(i,j)];\n            }\n        }\n        return *this;\n    }\n\
    \    matrix &operator-= (const matrix &r){\n        for (int i = 0; i < h; ++i){\n\
    \            for (int j = 0; j < w; ++j){\n                m[idx(i,j)] -= r.m[idx(i,j)];\n\
    \            }\n        }\n        return *this;\n    }\n    matrix &operator*=\
    \ (const matrix &r){\n        matrix ret(h, r.w);\n        for (int i = 0; i <\
    \ h; i++){\n            for (int k = 0; k < w; k++){\n                for (int\
    \ j = 0; j < r.w; j++){\n                    ret.m[idx(i,j)] += m[idx(i,k)] *\
    \ r.m[idx(k,j)];\n                }\n            }\n        }\n        return\
    \ *this = ret;\n    }\n    matrix operator+ (const matrix &r) const { return matrix(*this)\
    \ += r; }\n    matrix operator- (const matrix &r) const { return matrix(*this)\
    \ -= r; }\n    matrix operator* (const matrix &r) const { return matrix(*this)\
    \ *= r; }\n    matrix& operator*=(const T &r){\n        for (int i = 0; i < h;\
    \ ++i){\n            for (int j = 0; j < w; ++j){\n                m[idx(i,j)]\
    \ *= r;\n            }\n        }\n        return *this;\n    }\n    friend matrix\
    \ operator* (const T &r, const matrix &mat){\n        return matrix(mat) *= r;\n\
    \    }\n    friend matrix operator* (const matrix &mat, const T &r){\n       \
    \ return matrix(mat) *= r;\n    }\n    matrix pow(long long n){\n        if (n\
    \ == 0) return e(h);\n        matrix f = pow(n / 2);\n        matrix ret = f *\
    \ f;\n        if (n & 1) ret *= (*this);\n        return ret;\n    }\n    int\
    \ idx(int i, int j){\n        return i * w + j;\n    }\n    static matrix e(int\
    \ _h){\n        auto ret = matrix(_h, _h);\n        for (int i = 0; i < _h; i++){\n\
    \            ret[i][i] = T(1);\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const matrix &mat){\n        for\
    \ (int i = 0; i < mat.h; i++){\n            if (i != 0) os << '\\n';\n       \
    \     for (int j = 0; j < mat.w; j++){\n                if (j != 0) os << ' ';\n\
    \                os << mat[i][j];\n            }\n        }\n        return os;\n\
    \    }\n    friend std::istream &operator>>(std::istream &is, matrix &mat){\n\
    \        for (int i = 0; i < mat.h; i++){\n            for (int j = 0; j < mat.w;\
    \ j++){\n                is >> mat[i][j];\n            }\n        }\n        return\
    \ is;\n    }\n};\n\ntemplate<typename T, size_t _hw = -1uz>\nT determinant(matrix<T,\
    \ _hw> mat){\n    int hw = mat.h;\n    T ret = 1;\n    for (int i = 0; i < hw;\
    \ i++) {\n        int idx = -1;\n        for (int j = i; j < hw; j++) {\n    \
    \        if (mat[j][i] != 0) {\n                idx = j;\n                break;\n\
    \            }\n        }\n        if (idx == -1) return 0;\n        if (i !=\
    \ idx) {\n            ret *= T(-1);\n            for (int j = 0; j < hw; j++){\n\
    \                std::swap(mat[i][j],mat[idx][j]);\n            }\n        }\n\
    \        ret *= mat[i][i];\n        T inv = T(1) / mat[i][i];\n        for (int\
    \ j = 0; j < hw; j++) {\n            mat[i][j] *= inv;\n        }\n        for\
    \ (int j = i + 1; j < hw; j++) {\n            T a = mat[j][i];\n            if\
    \ (a == 0) continue;\n            for (int k = i; k < hw; k++) {\n           \
    \     mat[j][k] -= mat[i][k] * a;\n            }\n        }\n    }\n    return\
    \ ret;\n}\n\n} // namespace noya2\n#line 4 \"math/spanning_tree_counting.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<typename T>\nT directed_spanning_tree_counting(int\
    \ n, const std::vector<std::tuple<int,int,T>> &es){\n    matrix<T> mat(n-1,n-1);\n\
    \    for (auto [u, v, c] : es){\n        if (u < n-1 && v < n-1){\n          \
    \  mat[u][v] -= c;\n        }\n        if (v < n-1){\n            mat[v][v] +=\
    \ c;\n        }\n    }\n    return determinant(mat);\n}\n\ntemplate<typename T>\n\
    T undirected_spanning_tree_counting(int n, const std::vector<std::tuple<int,int,T>>\
    \ &es){\n    matrix<T> mat(n-1,n-1);\n    for (auto [u, v, c] : es){\n       \
    \ if (u < n-1 && v < n-1){\n            mat[u][v] -= c;\n            mat[v][u]\
    \ -= c;\n        }\n        if (v < n-1){\n            mat[v][v] += c;\n     \
    \   }\n        if (u < n-1){\n            mat[u][u] += c;\n        }\n    }\n\
    \    return determinant(mat);\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../math/matrix.hpp\"\n\nnamespace noya2 {\n\ntemplate<typename\
    \ T>\nT directed_spanning_tree_counting(int n, const std::vector<std::tuple<int,int,T>>\
    \ &es){\n    matrix<T> mat(n-1,n-1);\n    for (auto [u, v, c] : es){\n       \
    \ if (u < n-1 && v < n-1){\n            mat[u][v] -= c;\n        }\n        if\
    \ (v < n-1){\n            mat[v][v] += c;\n        }\n    }\n    return determinant(mat);\n\
    }\n\ntemplate<typename T>\nT undirected_spanning_tree_counting(int n, const std::vector<std::tuple<int,int,T>>\
    \ &es){\n    matrix<T> mat(n-1,n-1);\n    for (auto [u, v, c] : es){\n       \
    \ if (u < n-1 && v < n-1){\n            mat[u][v] -= c;\n            mat[v][u]\
    \ -= c;\n        }\n        if (v < n-1){\n            mat[v][v] += c;\n     \
    \   }\n        if (u < n-1){\n            mat[u][u] += c;\n        }\n    }\n\
    \    return determinant(mat);\n}\n\n} // namespace noya2"
  dependsOn:
  - math/matrix.hpp
  isVerificationFile: false
  path: math/spanning_tree_counting.hpp
  requiredBy:
  - math/euler_circuit_counting.hpp
  timestamp: '2024-08-13 15:38:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/CountingEulerianCircuits.test.cpp
documentation_of: math/spanning_tree_counting.hpp
layout: document
redirect_from:
- /library/math/spanning_tree_counting.hpp
- /library/math/spanning_tree_counting.hpp.html
title: math/spanning_tree_counting.hpp
---
