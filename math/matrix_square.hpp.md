---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':question:'
    path: template/inout_old.hpp
    title: template/inout_old.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix_square.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout_old.hpp\"\
    \nnamespace noya2 {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p){\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v){\n    int\
    \ s = (int)v.size();\n    for (int i = 0; i < s; i++) os << (i ? \" \" : \"\"\
    ) << v[i];\n    return os;\n}\ntemplate <typename T>\nistream &operator>>(istream\
    \ &is, vector<T> &v){\n    for (auto &x : v) is >> x;\n    return is;\n}\n\nvoid\
    \ in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...u){\n    cin\
    \ >> t;\n    in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...u){\n    cout\
    \ << t;\n    if (sizeof...(u)) cout << sep;\n    out(u...);\n}\n\ntemplate<typename\
    \ T>\nvoid out(const vector<vector<T>> &vv){\n    int s = (int)vv.size();\n  \
    \  for (int i = 0; i < s; i++) out(vv[i]);\n}\n\nstruct IoSetup {\n    IoSetup(){\n\
    \        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout\
    \ << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n \
    \   }\n} iosetup_noya2;\n\n} // namespace noya2\n#line 1 \"template/const.hpp\"\
    \nnamespace noya2{\n\nconst int iinf = 1'000'000'007;\nconst long long linf =\
    \ 2'000'000'000'000'000'000LL;\nconst long long mod998 =  998244353;\nconst long\
    \ long mod107 = 1000000007;\nconst long double pi = 3.14159265358979323;\nconst\
    \ vector<int> dx = {0,1,0,-1,1,1,-1,-1};\nconst vector<int> dy = {1,0,-1,0,1,-1,-1,1};\n\
    const string ALP = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\nconst string alp = \"abcdefghijklmnopqrstuvwxyz\"\
    ;\nconst string NUM = \"0123456789\";\n\nvoid yes(){ cout << \"Yes\\n\"; }\nvoid\
    \ no(){ cout << \"No\\n\"; }\nvoid YES(){ cout << \"YES\\n\"; }\nvoid NO(){ cout\
    \ << \"NO\\n\"; }\nvoid yn(bool t){ t ? yes() : no(); }\nvoid YN(bool t){ t ?\
    \ YES() : NO(); }\n\n} // namespace noya2\n#line 2 \"template/utils.hpp\"\n\n\
    #line 6 \"template/utils.hpp\"\n\nnamespace noya2{\n\nunsigned long long inner_binary_gcd(unsigned\
    \ long long a, unsigned long long b){\n    if (a == 0 || b == 0) return a + b;\n\
    \    int n = __builtin_ctzll(a); a >>= n;\n    int m = __builtin_ctzll(b); b >>=\
    \ m;\n    while (a != b) {\n        int mm = __builtin_ctzll(a - b);\n       \
    \ bool f = a > b;\n        unsigned long long c = f ? a : b;\n        b = f ?\
    \ b : a;\n        a = (c - b) >> mm;\n    }\n    return a << std::min(n, m);\n\
    }\n\ntemplate<typename T> T gcd_fast(T a, T b){ return static_cast<T>(inner_binary_gcd(std::abs(a),std::abs(b)));\
    \ }\n\nlong long sqrt_fast(long long n) {\n    if (n <= 0) return 0;\n    long\
    \ long x = sqrt(n);\n    while ((x + 1) * (x + 1) <= n) x++;\n    while (x * x\
    \ > n) x--;\n    return x;\n}\n\ntemplate<typename T> T floor_div(const T n, const\
    \ T d) {\n    assert(d != 0);\n    return n / d - static_cast<T>((n ^ d) < 0 &&\
    \ n % d != 0);\n}\n\ntemplate<typename T> T ceil_div(const T n, const T d) {\n\
    \    assert(d != 0);\n    return n / d + static_cast<T>((n ^ d) >= 0 && n % d\
    \ != 0);\n}\n\ntemplate<typename T> void uniq(std::vector<T> &v){\n    std::sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n}\n\ntemplate <typename T, typename\
    \ U> inline bool chmin(T &x, U y) { return (y < x) ? (x = y, true) : false; }\n\
    \ntemplate <typename T, typename U> inline bool chmax(T &x, U y) { return (x <\
    \ y) ? (x = y, true) : false; }\n\ntemplate<typename T> inline bool range(T l,\
    \ T x, T r){ return l <= x && x < r; }\n\n} // namespace noya2\n#line 8 \"template/template.hpp\"\
    \n\n#define rep(i,n) for (int i = 0; i < (int)(n); i++)\n#define repp(i,m,n) for\
    \ (int i = (m); i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1);\
    \ i >= 0; i--)\n#define all(v) (v).begin(),(v).end()\n\nusing ll = long long;\n\
    using ld = long double;\nusing uint = unsigned int;\nusing ull = unsigned long\
    \ long;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pil = pair<int,ll>;\n\
    using pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000\
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"math/matrix_square.hpp\"\n\n\
    namespace noya2{\n\ntemplate<typename T, int max_w>\nstruct Matrix_Square {\n\
    \    array<T,max_w*max_w> m;\n    inline static int w = max_w;\n    static void\
    \ set_w(int new_w){ w = new_w; }\n    constexpr Matrix_Square (){ m = {}; }\n\
    \    constexpr Matrix_Square (array<T,max_w*max_w> init) { m = init; }\n    constexpr\
    \ Matrix_Square (array<array<T,max_w>,max_w> init){\n        for (int i = 0; i\
    \ < w; i++){\n            for (int j = 0; j < w; j++){\n                m[id(i,j)]\
    \ = init[i][j];\n            }\n        }\n    }\n    T &operator[](pair<int,int>\
    \ idx) { return m[id(idx.first,idx.second)]; }\n    T operator[](pair<int,int>\
    \ idx) const { return m[id(idx.first,idx.second)]; }\n    constexpr size_t size(){\
    \ return w; }\n    using Matrix = Matrix_Square;\n    constexpr Matrix &operator+=\
    \ (const Matrix &r){\n        for (int i = 0; i < w; ++i){\n            for (int\
    \ j = 0; j < w; ++j){\n                m[id(i,j)] += r.m[id(i,j)];\n         \
    \   }\n        }\n        return *this;\n    }\n    constexpr Matrix &operator-=\
    \ (const Matrix &r){\n        for (int i = 0; i < w; ++i){\n            for (int\
    \ j = 0; j < w; ++j){\n                m[id(i,j)] -= r.m[id(i,j)];\n         \
    \   }\n        }\n        return *this;\n    }\n    constexpr Matrix &operator*=\
    \ (const Matrix &r){\n        Matrix res = {};\n        for (int i = 0; i < w;\
    \ i++){\n            for (int k = 0; k < w; k++){\n                for (int j\
    \ = 0; j < w; j++){\n                    res.m[id(i,j)] += m[id(i,k)] * r.m[id(k,j)];\n\
    \                }\n            }\n        }\n        return *this = res;\n  \
    \  }\n    constexpr Matrix operator+ (const Matrix &r) const {return Matrix(*this)\
    \ += r;}\n    constexpr Matrix operator- (const Matrix &r) const {return Matrix(*this)\
    \ -= r;}\n    constexpr Matrix operator* (const Matrix &r) const {return Matrix(*this)\
    \ *= r;}\n    constexpr bool operator== (const Matrix &r){\n        for (int i\
    \ = 0; i < w; ++i){\n            for (int j = 0; j < w; ++j){\n              \
    \  if (m[id(i,j)] != r.m[id(i,j)]) return false;\n            }\n        }\n \
    \       return true;\n    }\n    constexpr Matrix& operator*=(const T &r){\n \
    \       for (int i = 0; i < w; ++i){\n            for (int j = 0; j < w; ++j){\n\
    \                m[id(i,j)] *= r;\n            }\n        }\n        return *this;\n\
    \    }\n    constexpr Matrix& operator/=(const T &r){\n        for (int i = 0;\
    \ i < w; ++i){\n            for (int j = 0; j < w; ++j){\n                m[id(i,j)]\
    \ /= r;\n            }\n        }\n        return *this;\n    }\n    constexpr\
    \ Matrix operator* (const T &r) const {return Matrix(*this) *= r;}\n    constexpr\
    \ Matrix operator/ (const T &r) const {return Matrix(*this) /= r;}\n    friend\
    \ constexpr Matrix operator+(const Matrix& lhs, const Matrix& rhs) {\n       \
    \ return Matrix(lhs) += rhs;\n    }\n    friend constexpr Matrix operator-(const\
    \ Matrix& lhs, const Matrix& rhs) {\n        return Matrix(lhs) -= rhs;\n    }\n\
    \    friend constexpr Matrix operator*(const Matrix& lhs, const Matrix& rhs) {\n\
    \        return Matrix(lhs) *= rhs;\n    }\n    friend constexpr Matrix operator*(const\
    \ Matrix& lhs, const T& r){\n        return Matrix(lhs) *= r;\n    }\n    friend\
    \ constexpr Matrix operator*(const T& l, const Matrix &rhs){\n        return Matrix(rhs)\
    \ *= l;\n    }\n    friend constexpr Matrix operator/(const Matrix& lhs, const\
    \ T& r){\n        return Matrix(lhs) /= r;\n    }\n    static constexpr Matrix\
    \ e(){\n        array<T,max_w*max_w> res = {};\n        for (int i = 0; i < w;\
    \ i++) res[id(i,i)] = T(1);\n        return res;\n    }\n    constexpr Matrix\
    \ pow(ll n) const {\n        Matrix res = e(), x = *this;\n        while (n){\n\
    \            if (n&1) res *= x;\n            x *= x;\n            n >>= 1;\n \
    \       }\n        return res;\n    }\n    constexpr T determinant() const {\n\
    \        auto B = this->m;\n        T ret = 1;\n        for (int i = 0; i < w;\
    \ i++) {\n            int idx = -1;\n            for (int j = i; j < w; j++) {\n\
    \                if (B[id(j,i)] != 0) {\n                    idx = j;\n      \
    \              break;\n                }\n            }\n            if (idx ==\
    \ -1) return 0;\n            if (i != idx) {\n                ret *= T(-1);\n\
    \                for (int j = 0; j < w; j++) swap(B[id(i,j)],B[id(idx,j)]);\n\
    \            }\n            ret *= B[id(i,i)];\n            T inv = T(1) / B[id(i,i)];\n\
    \            for (int j = 0; j < w; j++) {\n                B[id(i,j)] *= inv;\n\
    \            }\n            for (int j = i + 1; j < w; j++) {\n              \
    \  T a = B[id(j,i)];\n                if (a == 0) continue;\n                for\
    \ (int k = i; k < w; k++) {\n                    B[id(j,k)] -= B[id(i,k)] * a;\n\
    \                }\n            }\n        }\n        return ret;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Matrix& p) {\n     \
    \   for (int i = 0; i < w; i++){\n            if (i != 0) os << '\\n';\n     \
    \       for (int j = 0; j < w; j++){\n                if (j != 0) os << ' ';\n\
    \                os << p.m[id(i,j)];\n            }\n        }\n        return\
    \ os;\n    }\n    friend std::istream &operator>>(std::istream &is, Matrix &p)\
    \ {\n        for (int i = 0; i < w; i++){\n            for (int j = 0; j < w;\
    \ j++){\n                is >> p.m[id(i,j)];\n            }\n        }\n     \
    \   return (is);\n    }\n  private:\n    static constexpr int id(int i, int j){\
    \ return i*max_w+j; }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\
    \ntemplate<typename T, int max_w>\nstruct Matrix_Square {\n    array<T,max_w*max_w>\
    \ m;\n    inline static int w = max_w;\n    static void set_w(int new_w){ w =\
    \ new_w; }\n    constexpr Matrix_Square (){ m = {}; }\n    constexpr Matrix_Square\
    \ (array<T,max_w*max_w> init) { m = init; }\n    constexpr Matrix_Square (array<array<T,max_w>,max_w>\
    \ init){\n        for (int i = 0; i < w; i++){\n            for (int j = 0; j\
    \ < w; j++){\n                m[id(i,j)] = init[i][j];\n            }\n      \
    \  }\n    }\n    T &operator[](pair<int,int> idx) { return m[id(idx.first,idx.second)];\
    \ }\n    T operator[](pair<int,int> idx) const { return m[id(idx.first,idx.second)];\
    \ }\n    constexpr size_t size(){ return w; }\n    using Matrix = Matrix_Square;\n\
    \    constexpr Matrix &operator+= (const Matrix &r){\n        for (int i = 0;\
    \ i < w; ++i){\n            for (int j = 0; j < w; ++j){\n                m[id(i,j)]\
    \ += r.m[id(i,j)];\n            }\n        }\n        return *this;\n    }\n \
    \   constexpr Matrix &operator-= (const Matrix &r){\n        for (int i = 0; i\
    \ < w; ++i){\n            for (int j = 0; j < w; ++j){\n                m[id(i,j)]\
    \ -= r.m[id(i,j)];\n            }\n        }\n        return *this;\n    }\n \
    \   constexpr Matrix &operator*= (const Matrix &r){\n        Matrix res = {};\n\
    \        for (int i = 0; i < w; i++){\n            for (int k = 0; k < w; k++){\n\
    \                for (int j = 0; j < w; j++){\n                    res.m[id(i,j)]\
    \ += m[id(i,k)] * r.m[id(k,j)];\n                }\n            }\n        }\n\
    \        return *this = res;\n    }\n    constexpr Matrix operator+ (const Matrix\
    \ &r) const {return Matrix(*this) += r;}\n    constexpr Matrix operator- (const\
    \ Matrix &r) const {return Matrix(*this) -= r;}\n    constexpr Matrix operator*\
    \ (const Matrix &r) const {return Matrix(*this) *= r;}\n    constexpr bool operator==\
    \ (const Matrix &r){\n        for (int i = 0; i < w; ++i){\n            for (int\
    \ j = 0; j < w; ++j){\n                if (m[id(i,j)] != r.m[id(i,j)]) return\
    \ false;\n            }\n        }\n        return true;\n    }\n    constexpr\
    \ Matrix& operator*=(const T &r){\n        for (int i = 0; i < w; ++i){\n    \
    \        for (int j = 0; j < w; ++j){\n                m[id(i,j)] *= r;\n    \
    \        }\n        }\n        return *this;\n    }\n    constexpr Matrix& operator/=(const\
    \ T &r){\n        for (int i = 0; i < w; ++i){\n            for (int j = 0; j\
    \ < w; ++j){\n                m[id(i,j)] /= r;\n            }\n        }\n   \
    \     return *this;\n    }\n    constexpr Matrix operator* (const T &r) const\
    \ {return Matrix(*this) *= r;}\n    constexpr Matrix operator/ (const T &r) const\
    \ {return Matrix(*this) /= r;}\n    friend constexpr Matrix operator+(const Matrix&\
    \ lhs, const Matrix& rhs) {\n        return Matrix(lhs) += rhs;\n    }\n    friend\
    \ constexpr Matrix operator-(const Matrix& lhs, const Matrix& rhs) {\n       \
    \ return Matrix(lhs) -= rhs;\n    }\n    friend constexpr Matrix operator*(const\
    \ Matrix& lhs, const Matrix& rhs) {\n        return Matrix(lhs) *= rhs;\n    }\n\
    \    friend constexpr Matrix operator*(const Matrix& lhs, const T& r){\n     \
    \   return Matrix(lhs) *= r;\n    }\n    friend constexpr Matrix operator*(const\
    \ T& l, const Matrix &rhs){\n        return Matrix(rhs) *= l;\n    }\n    friend\
    \ constexpr Matrix operator/(const Matrix& lhs, const T& r){\n        return Matrix(lhs)\
    \ /= r;\n    }\n    static constexpr Matrix e(){\n        array<T,max_w*max_w>\
    \ res = {};\n        for (int i = 0; i < w; i++) res[id(i,i)] = T(1);\n      \
    \  return res;\n    }\n    constexpr Matrix pow(ll n) const {\n        Matrix\
    \ res = e(), x = *this;\n        while (n){\n            if (n&1) res *= x;\n\
    \            x *= x;\n            n >>= 1;\n        }\n        return res;\n \
    \   }\n    constexpr T determinant() const {\n        auto B = this->m;\n    \
    \    T ret = 1;\n        for (int i = 0; i < w; i++) {\n            int idx =\
    \ -1;\n            for (int j = i; j < w; j++) {\n                if (B[id(j,i)]\
    \ != 0) {\n                    idx = j;\n                    break;\n        \
    \        }\n            }\n            if (idx == -1) return 0;\n            if\
    \ (i != idx) {\n                ret *= T(-1);\n                for (int j = 0;\
    \ j < w; j++) swap(B[id(i,j)],B[id(idx,j)]);\n            }\n            ret *=\
    \ B[id(i,i)];\n            T inv = T(1) / B[id(i,i)];\n            for (int j\
    \ = 0; j < w; j++) {\n                B[id(i,j)] *= inv;\n            }\n    \
    \        for (int j = i + 1; j < w; j++) {\n                T a = B[id(j,i)];\n\
    \                if (a == 0) continue;\n                for (int k = i; k < w;\
    \ k++) {\n                    B[id(j,k)] -= B[id(i,k)] * a;\n                }\n\
    \            }\n        }\n        return ret;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Matrix& p) {\n        for (int i = 0; i\
    \ < w; i++){\n            if (i != 0) os << '\\n';\n            for (int j = 0;\
    \ j < w; j++){\n                if (j != 0) os << ' ';\n                os <<\
    \ p.m[id(i,j)];\n            }\n        }\n        return os;\n    }\n    friend\
    \ std::istream &operator>>(std::istream &is, Matrix &p) {\n        for (int i\
    \ = 0; i < w; i++){\n            for (int j = 0; j < w; j++){\n              \
    \  is >> p.m[id(i,j)];\n            }\n        }\n        return (is);\n    }\n\
    \  private:\n    static constexpr int id(int i, int j){ return i*max_w+j; }\n\
    };\n\n} // namespace noya2\n"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: math/matrix_square.hpp
  requiredBy: []
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix_square.hpp
layout: document
redirect_from:
- /library/math/matrix_square.hpp
- /library/math/matrix_square.hpp.html
title: math/matrix_square.hpp
---
