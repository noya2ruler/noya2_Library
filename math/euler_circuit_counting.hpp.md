---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: math/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: math/spanning_tree_counting.hpp
    title: math/spanning_tree_counting.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/CountingEulerianCircuits.test.cpp
    title: test/math/CountingEulerianCircuits.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/BEST_theorem
  bundledCode: "#line 2 \"math/euler_circuit_counting.hpp\"\n\n#line 2 \"math/spanning_tree_counting.hpp\"\
    \n\n#line 2 \"math/matrix.hpp\"\n\n#include <vector>\n#include <array>\n#include\
    \ <iostream>\n#include <ranges>\n#include <cassert>\n\nnamespace noya2 {\n\ntemplate<typename\
    \ T, size_t hw = -1uz>\nstruct matrix {\n    static constexpr int h = hw, w =\
    \ hw;\n    std::array<T, hw*hw> m;\n    matrix () : m({}) {}\n    matrix (const\
    \ std::array<T, hw*hw> &_m) : m(_m) {}\n    matrix (const std::array<std::array<T,\
    \ hw>, hw> &_m){\n        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){\n\
    \            m[idx(i,j)] = _m[i][j];\n        }\n    }\n    matrix (const std::vector<std::vector<T>>\
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
    \    return determinant(mat);\n}\n\n} // namespace noya2\n#line 2 \"math/binomial.hpp\"\
    \n\n#line 4 \"math/binomial.hpp\"\nnamespace noya2 {\n\ntemplate<typename mint>\n\
    struct binomial {\n    binomial(int len = 300000){ extend(len); }\n    static\
    \ mint fact(int n){\n        if (n < 0) return 0;\n        while (n >= (int)_fact.size())\
    \ extend();\n        return _fact[n];\n    }\n    static mint ifact(int n){\n\
    \        if (n < 0) return 0;\n        while (n >= (int)_fact.size()) extend();\n\
    \        return _ifact[n];\n    }\n    static mint inv(int n){\n        return\
    \ ifact(n) * fact(n-1);\n    }\n    static mint C(int n, int r){\n        if (!(0\
    \ <= r && r <= n)) return 0;\n        return fact(n) * ifact(r) * ifact(n-r);\n\
    \    }\n    static mint P(int n, int r){\n        if (!(0 <= r && r <= n)) return\
    \ 0;\n        return fact(n) * ifact(n-r);\n    }\n    static mint catalan(int\
    \ n){\n        return C(n * 2, n) * inv(n + 1);\n    }\n    inline mint operator()(int\
    \ n, int r) { return C(n, r); }\n    template<class... Cnts>\n    static mint\
    \ M(const Cnts&... cnts){\n        return multinomial(0,1,cnts...);\n    }\n \
    \   static void initialize(int len = 2){\n        _fact.clear();\n        _ifact.clear();\n\
    \        extend(len);\n    }\n  private:\n    static mint multinomial(const int&\
    \ sum, const mint& div_prod){\n        if (sum < 0) return 0;\n        return\
    \ fact(sum) * div_prod;\n    }\n    template<class... Tail>\n    static mint multinomial(const\
    \ int& sum, const mint& div_prod, const int& n1, const Tail&... tail){\n     \
    \   if (n1 < 0) return 0;\n        return multinomial(sum+n1,div_prod*ifact(n1),tail...);\n\
    \    }\n    static inline std::vector<mint> _fact, _ifact;\n    static void extend(int\
    \ len = -1){\n        if (_fact.empty()){\n            _fact = _ifact = {1,1};\n\
    \        }\n        int siz = _fact.size();\n        if (len == -1) len = siz\
    \ * 2;\n        len = (int)min<long long>(len, mint::mod() - 1);\n        if (len\
    \ < siz) return ;\n        _fact.resize(len+1), _ifact.resize(len+1);\n      \
    \  for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1] * i;\n        _ifact[len]\
    \ = _fact[len].inv();\n        for (int i = len; i > siz; i--) _ifact[i-1] = _ifact[i]\
    \ * i;\n    }\n};\n\n} // namespace noya2\n#line 5 \"math/euler_circuit_counting.hpp\"\
    \n\nnamespace noya2 {\n\n// BEST theorem\n// https://en.wikipedia.org/wiki/BEST_theorem\n\
    template<typename T>\nT euler_circuit_counting(int n, const std::vector<std::tuple<int,\
    \ int, long long>> &es){\n    // i_deg == o_deg\n    std::vector<long long> deg(n,0);\n\
    \    for (auto [u, v, c] : es){\n        deg[u] -= c;\n        deg[v] += c;\n\
    \    }\n    for (int i = 0; i < n; i++) if (deg[i] != 0) return T(0);\n    //\
    \ edges are connected\n    int m = es.size();\n    std::vector<bool> vis(n,false);\n\
    \    std::vector<std::vector<int>> g(n);\n    for (auto [u, v, c] : es){\n   \
    \     if (c == 0) continue;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n    for (int s = 0; s < n; s++){\n        if (g[s].empty()) continue;\n\
    \        std::queue<int> que;\n        que.push(s);\n        vis[s] = true;\n\
    \        while (!que.empty()){\n            int v = que.front(); que.pop();\n\
    \            for (int u : g[v]){\n                if (!vis[u]){\n            \
    \        vis[u] = true;\n                    que.push(u);\n                }\n\
    \            }\n        }\n        break;\n    }\n    for (auto [u, v, c] : es){\n\
    \        if (!vis[u]) return T(0);\n    }\n    // directed spanning tree counting\n\
    \    std::vector<int> ids(n);\n    int nonzero = 0;\n    for (int v = 0; v < n;\
    \ v++){\n        if (!g[v].empty()){\n            ids[v] = nonzero++;\n      \
    \  }\n    }\n    std::vector<std::tuple<int, int, T>> nes(m);\n    for (int i\
    \ = 0; i < m; i++){\n        auto [u, v, c] = es[i];\n        nes[i] = {ids[u],ids[v],c};\n\
    \        deg[v] += c;\n    }\n    binomial<T> bnm;\n    T ans = directed_spanning_tree_counting(nonzero,nes);\n\
    \    for (int i = 0; i < n; i++){\n        if (deg[i] > 0){\n            ans *=\
    \ bnm.fact(deg[i]-1);\n        }\n    }\n    return ans;\n}\n\n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include\"../math/spanning_tree_counting.hpp\"\n#include\"\
    ../math/binomial.hpp\"\n\nnamespace noya2 {\n\n// BEST theorem\n// https://en.wikipedia.org/wiki/BEST_theorem\n\
    template<typename T>\nT euler_circuit_counting(int n, const std::vector<std::tuple<int,\
    \ int, long long>> &es){\n    // i_deg == o_deg\n    std::vector<long long> deg(n,0);\n\
    \    for (auto [u, v, c] : es){\n        deg[u] -= c;\n        deg[v] += c;\n\
    \    }\n    for (int i = 0; i < n; i++) if (deg[i] != 0) return T(0);\n    //\
    \ edges are connected\n    int m = es.size();\n    std::vector<bool> vis(n,false);\n\
    \    std::vector<std::vector<int>> g(n);\n    for (auto [u, v, c] : es){\n   \
    \     if (c == 0) continue;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n    for (int s = 0; s < n; s++){\n        if (g[s].empty()) continue;\n\
    \        std::queue<int> que;\n        que.push(s);\n        vis[s] = true;\n\
    \        while (!que.empty()){\n            int v = que.front(); que.pop();\n\
    \            for (int u : g[v]){\n                if (!vis[u]){\n            \
    \        vis[u] = true;\n                    que.push(u);\n                }\n\
    \            }\n        }\n        break;\n    }\n    for (auto [u, v, c] : es){\n\
    \        if (!vis[u]) return T(0);\n    }\n    // directed spanning tree counting\n\
    \    std::vector<int> ids(n);\n    int nonzero = 0;\n    for (int v = 0; v < n;\
    \ v++){\n        if (!g[v].empty()){\n            ids[v] = nonzero++;\n      \
    \  }\n    }\n    std::vector<std::tuple<int, int, T>> nes(m);\n    for (int i\
    \ = 0; i < m; i++){\n        auto [u, v, c] = es[i];\n        nes[i] = {ids[u],ids[v],c};\n\
    \        deg[v] += c;\n    }\n    binomial<T> bnm;\n    T ans = directed_spanning_tree_counting(nonzero,nes);\n\
    \    for (int i = 0; i < n; i++){\n        if (deg[i] > 0){\n            ans *=\
    \ bnm.fact(deg[i]-1);\n        }\n    }\n    return ans;\n}\n\n} // namespace\
    \ noya2"
  dependsOn:
  - math/spanning_tree_counting.hpp
  - math/matrix.hpp
  - math/binomial.hpp
  isVerificationFile: false
  path: math/euler_circuit_counting.hpp
  requiredBy: []
  timestamp: '2025-01-28 23:59:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/CountingEulerianCircuits.test.cpp
documentation_of: math/euler_circuit_counting.hpp
layout: document
redirect_from:
- /library/math/euler_circuit_counting.hpp
- /library/math/euler_circuit_counting.hpp.html
title: math/euler_circuit_counting.hpp
---
