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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/Determinant_of_Matrix.test.cpp
    title: test/math/Determinant_of_Matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\n#line 2 \"template/template.hpp\"\n\
    using namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout_old.hpp\"\
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
    \ YES() : NO(); }\n\n} // namespace noya2\n#line 1 \"template/utils.hpp\"\nnamespace\
    \ noya2{\n\nunsigned long long inner_binary_gcd(unsigned long long a, unsigned\
    \ long long b){\n    if (a == 0 || b == 0) return a + b;\n    int n = __builtin_ctzll(a);\
    \ a >>= n;\n    int m = __builtin_ctzll(b); b >>= m;\n    while (a != b) {\n \
    \       int mm = __builtin_ctzll(a - b);\n        bool f = a > b;\n        unsigned\
    \ long long c = f ? a : b;\n        b = f ? b : a;\n        a = (c - b) >> mm;\n\
    \    }\n    return a << min(n, m);\n}\n\ntemplate<typename T> T gcd_fast(T a,\
    \ T b){ return static_cast<T>(inner_binary_gcd(abs(a),abs(b))); }\n\nlong long\
    \ sqrt_fast(long long n) {\n    if (n <= 0) return 0;\n    long long x = sqrt(n);\n\
    \    while ((x + 1) * (x + 1) <= n) x++;\n    while (x * x > n) x--;\n    return\
    \ x;\n}\n\ntemplate<typename T> T floor_div(const T n, const T d) {\n    assert(d\
    \ != 0);\n    return n / d - static_cast<T>((n ^ d) < 0 && n % d != 0);\n}\n\n\
    template<typename T> T ceil_div(const T n, const T d) {\n    assert(d != 0);\n\
    \    return n / d + static_cast<T>((n ^ d) >= 0 && n % d != 0);\n}\n\ntemplate<typename\
    \ T> void uniq(vector<T> &v){\n    sort(v.begin(),v.end());\n    v.erase(unique(v.begin(),v.end()),v.end());\n\
    }\n\ntemplate <typename T, typename U> inline bool chmin(T &x, U y) { return (y\
    \ < x) ? (x = y, true) : false; }\n\ntemplate <typename T, typename U> inline\
    \ bool chmax(T &x, U y) { return (x < y) ? (x = y, true) : false; }\n\ntemplate<typename\
    \ T> inline bool range(T l, T x, T r){ return l <= x && x < r; }\n\n} // namespace\
    \ noya2\n#line 8 \"template/template.hpp\"\n\n#define rep(i,n) for (int i = 0;\
    \ i < (int)(n); i++)\n#define repp(i,m,n) for (int i = (m); i < (int)(n); i++)\n\
    #define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n#define all(v) (v).begin(),(v).end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\n\
    using ull = unsigned long long;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\n\
    using pil = pair<int,ll>;\nusing pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000\
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"math/matrix.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<typename T> struct Matrix{\n    int rows, cols;\n\
    \    vector<vector<T>> m;\n    Matrix (int h = 0, int w = -1, T init = T(0)) :\
    \ m(h,vector<T>((w == -1 ? h : w),init)){\n        rows = h, cols = (w == -1 ?\
    \ h : w);\n    } \n    Matrix (vector<vector<T>> _init) : m(_init), rows(_init.size()),\
    \ cols(_init.at(0).size()){}\n    vector<T>& operator[](const int i) const {return\
    \ m[i];}\n    vector<T>& operator[](const int i) {return m[i];}\n    Matrix &operator+=\
    \ (const Matrix &r){\n        assert(this->rows == r.rows && this->cols == r.cols);\n\
    \        for (int i = 0; i < r.rows; ++i){\n            for (int j = 0; j < r.cols;\
    \ ++j){\n                m[i][j] += r.m[i][j];\n            }\n        }\n   \
    \     return *this;\n    }\n    Matrix &operator-= (const Matrix &r){\n      \
    \  assert(this->rows == r.rows && this->cols == r.cols);\n        for (int i =\
    \ 0; i < r.rows; ++i){\n            for (int j = 0; j < r.cols; ++j){\n      \
    \          m[i][j] -= r.m[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n    Matrix &operator*= (const Matrix &r){\n        assert(this->cols ==\
    \ r.rows);\n        Matrix res(rows, r.cols);\n        for (int i = 0; i < rows;\
    \ ++i){\n            for (int j = 0; j < r.cols; ++j){\n                for (int\
    \ k = 0; k < r.rows; ++k){\n                    res[i][j] += m[i][k] * r.m[k][j];\n\
    \                }\n            }\n        }\n        return *this = res;\n  \
    \  }\n    Matrix operator+ (const Matrix &r) const {return Matrix(*this) += r;}\n\
    \    Matrix operator- (const Matrix &r) const {return Matrix(*this) -= r;}\n \
    \   Matrix operator* (const Matrix &r) const {return Matrix(*this) *= r;}\n  \
    \  bool operator== (const Matrix &r){\n        if (rows != r.rows || cols != r.cols)\
    \ return false;\n        for (int i = 0; i < r.rows; ++i){\n            for (int\
    \ j = 0; j < r.cols; ++j){\n                if (m[i][j] != r.m[i][j]) return false;\n\
    \            }\n        }\n        return true;\n    }\n    Matrix& operator+=(const\
    \ T &r){\n        for (int i = 0; i < rows; ++i){\n            for (int j = 0;\
    \ j < cols; ++j){\n                m[i][j] += r;\n            }\n        }\n \
    \       return *this;\n    }\n    Matrix& operator-=(const T &r){\n        for\
    \ (int i = 0; i < rows; ++i){\n            for (int j = 0; j < cols; ++j){\n \
    \               m[i][j] -= r;\n            }\n        }\n        return *this;\n\
    \    }\n    Matrix& operator*=(const T &r){\n        for (int i = 0; i < rows;\
    \ ++i){\n            for (int j = 0; j < cols; ++j){\n                m[i][j]\
    \ *= r;\n            }\n        }\n        return *this;\n    }\n    Matrix& operator/=(const\
    \ T &r){\n        for (int i = 0; i < rows; ++i){\n            for (int j = 0;\
    \ j < cols; ++j){\n                m[i][j] /= r;\n            }\n        }\n \
    \       return *this;\n    }\n    Matrix operator+ (const T &r) const {return\
    \ Matrix(*this) += r;}\n    Matrix operator- (const T &r) const {return Matrix(*this)\
    \ -= r;}\n    Matrix operator* (const T &r) const {return Matrix(*this) *= r;}\n\
    \    Matrix operator/ (const T &r) const {return Matrix(*this) /= r;}\n    Matrix\
    \ e(){\n        assert(this->rows == this->cols);\n        Matrix res(this->rows,\
    \ this->rows);\n        for (int i = 0; i < rows; ++i) res[i][i] = 1;\n      \
    \  return res;\n    }\n    Matrix pow(long long n){\n        assert(this->rows\
    \ == this->cols);\n        if (n == 0) return e();\n        Matrix f = pow(n /\
    \ 2);\n        Matrix ans = f * f;\n        if (n % 2 == 1) ans *= *this;\n  \
    \      return ans;\n    }\n    // for T = int, long long, double, long double\n\
    \    void show(){\n        for (int i = 0; i < rows; ++i){\n            for (int\
    \ j = 0; j < cols; ++j){\n                cout << m[i][j] << (j+1 == this->cols\
    \ ? \"\\n\" : \" \");\n            }\n        }\n    }\n    T determinant() const\
    \ {\n        Matrix B(*this);\n        assert(rows == cols);\n        T ret =\
    \ 1;\n        for (int i = 0; i < rows; i++) {\n            int idx = -1;\n  \
    \          for (int j = i; j < cols; j++) {\n                if (B[j][i] != 0)\
    \ {\n                    idx = j;\n                    break;\n              \
    \  }\n            }\n            if (idx == -1) return 0;\n            if (i !=\
    \ idx) {\n                ret *= T(-1);\n                swap(B[i], B[idx]);\n\
    \            }\n            ret *= B[i][i];\n            T inv = T(1) / B[i][i];\n\
    \            for (int j = 0; j < cols; j++) {\n                B[i][j] *= inv;\n\
    \            }\n            for (int j = i + 1; j < rows; j++) {\n           \
    \     T a = B[j][i];\n                if (a == 0) continue;\n                for\
    \ (int k = i; k < cols; k++) {\n                    B[j][k] -= B[i][k] * a;\n\
    \                }\n            }\n        }\n        return ret;\n    }\n};\n\
    \n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\
    \ntemplate<typename T> struct Matrix{\n    int rows, cols;\n    vector<vector<T>>\
    \ m;\n    Matrix (int h = 0, int w = -1, T init = T(0)) : m(h,vector<T>((w ==\
    \ -1 ? h : w),init)){\n        rows = h, cols = (w == -1 ? h : w);\n    } \n \
    \   Matrix (vector<vector<T>> _init) : m(_init), rows(_init.size()), cols(_init.at(0).size()){}\n\
    \    vector<T>& operator[](const int i) const {return m[i];}\n    vector<T>& operator[](const\
    \ int i) {return m[i];}\n    Matrix &operator+= (const Matrix &r){\n        assert(this->rows\
    \ == r.rows && this->cols == r.cols);\n        for (int i = 0; i < r.rows; ++i){\n\
    \            for (int j = 0; j < r.cols; ++j){\n                m[i][j] += r.m[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix &operator-=\
    \ (const Matrix &r){\n        assert(this->rows == r.rows && this->cols == r.cols);\n\
    \        for (int i = 0; i < r.rows; ++i){\n            for (int j = 0; j < r.cols;\
    \ ++j){\n                m[i][j] -= r.m[i][j];\n            }\n        }\n   \
    \     return *this;\n    }\n    Matrix &operator*= (const Matrix &r){\n      \
    \  assert(this->cols == r.rows);\n        Matrix res(rows, r.cols);\n        for\
    \ (int i = 0; i < rows; ++i){\n            for (int j = 0; j < r.cols; ++j){\n\
    \                for (int k = 0; k < r.rows; ++k){\n                    res[i][j]\
    \ += m[i][k] * r.m[k][j];\n                }\n            }\n        }\n     \
    \   return *this = res;\n    }\n    Matrix operator+ (const Matrix &r) const {return\
    \ Matrix(*this) += r;}\n    Matrix operator- (const Matrix &r) const {return Matrix(*this)\
    \ -= r;}\n    Matrix operator* (const Matrix &r) const {return Matrix(*this) *=\
    \ r;}\n    bool operator== (const Matrix &r){\n        if (rows != r.rows || cols\
    \ != r.cols) return false;\n        for (int i = 0; i < r.rows; ++i){\n      \
    \      for (int j = 0; j < r.cols; ++j){\n                if (m[i][j] != r.m[i][j])\
    \ return false;\n            }\n        }\n        return true;\n    }\n    Matrix&\
    \ operator+=(const T &r){\n        for (int i = 0; i < rows; ++i){\n         \
    \   for (int j = 0; j < cols; ++j){\n                m[i][j] += r;\n         \
    \   }\n        }\n        return *this;\n    }\n    Matrix& operator-=(const T\
    \ &r){\n        for (int i = 0; i < rows; ++i){\n            for (int j = 0; j\
    \ < cols; ++j){\n                m[i][j] -= r;\n            }\n        }\n   \
    \     return *this;\n    }\n    Matrix& operator*=(const T &r){\n        for (int\
    \ i = 0; i < rows; ++i){\n            for (int j = 0; j < cols; ++j){\n      \
    \          m[i][j] *= r;\n            }\n        }\n        return *this;\n  \
    \  }\n    Matrix& operator/=(const T &r){\n        for (int i = 0; i < rows; ++i){\n\
    \            for (int j = 0; j < cols; ++j){\n                m[i][j] /= r;\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix operator+\
    \ (const T &r) const {return Matrix(*this) += r;}\n    Matrix operator- (const\
    \ T &r) const {return Matrix(*this) -= r;}\n    Matrix operator* (const T &r)\
    \ const {return Matrix(*this) *= r;}\n    Matrix operator/ (const T &r) const\
    \ {return Matrix(*this) /= r;}\n    Matrix e(){\n        assert(this->rows ==\
    \ this->cols);\n        Matrix res(this->rows, this->rows);\n        for (int\
    \ i = 0; i < rows; ++i) res[i][i] = 1;\n        return res;\n    }\n    Matrix\
    \ pow(long long n){\n        assert(this->rows == this->cols);\n        if (n\
    \ == 0) return e();\n        Matrix f = pow(n / 2);\n        Matrix ans = f *\
    \ f;\n        if (n % 2 == 1) ans *= *this;\n        return ans;\n    }\n    //\
    \ for T = int, long long, double, long double\n    void show(){\n        for (int\
    \ i = 0; i < rows; ++i){\n            for (int j = 0; j < cols; ++j){\n      \
    \          cout << m[i][j] << (j+1 == this->cols ? \"\\n\" : \" \");\n       \
    \     }\n        }\n    }\n    T determinant() const {\n        Matrix B(*this);\n\
    \        assert(rows == cols);\n        T ret = 1;\n        for (int i = 0; i\
    \ < rows; i++) {\n            int idx = -1;\n            for (int j = i; j < cols;\
    \ j++) {\n                if (B[j][i] != 0) {\n                    idx = j;\n\
    \                    break;\n                }\n            }\n            if\
    \ (idx == -1) return 0;\n            if (i != idx) {\n                ret *= T(-1);\n\
    \                swap(B[i], B[idx]);\n            }\n            ret *= B[i][i];\n\
    \            T inv = T(1) / B[i][i];\n            for (int j = 0; j < cols; j++)\
    \ {\n                B[i][j] *= inv;\n            }\n            for (int j =\
    \ i + 1; j < rows; j++) {\n                T a = B[j][i];\n                if\
    \ (a == 0) continue;\n                for (int k = i; k < cols; k++) {\n     \
    \               B[j][k] -= B[i][k] * a;\n                }\n            }\n  \
    \      }\n        return ret;\n    }\n};\n\n} // namespace noya2\n"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2023-08-26 17:35:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/Determinant_of_Matrix.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
