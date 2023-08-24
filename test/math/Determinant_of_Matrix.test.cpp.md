---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utils.hpp
    title: template/utils.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/math/Determinant_of_Matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout.hpp\"\
    \nnamespace noya2 {\n\ntemplate <typename T> ostream &operator<<(ostream &os,\
    \ const vector<T> &v);\ntemplate <typename T> istream &operator>>(istream &is,\
    \ vector<T> &v);\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
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
    \ << t;\n    if (sizeof...(u)) cout << sep;\n    out(u...);\n}\ntemplate<typename\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"test/math/Determinant_of_Matrix.test.cpp\"\
    \n\n#line 2 \"math/matrix.hpp\"\n\n#line 4 \"math/matrix.hpp\"\n\nnamespace noya2{\n\
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
    \      }\n        return ret;\n    }\n};\n\n} // namespace noya2\n#line 2 \"utility/modint.hpp\"\
    \n\n// AtCoderLibrary \u3092\u305D\u306E\u307E\u307E\u30D1\u30AF\u3063\u3066\u3044\
    \u308B \u306A\u306B\u3082\u308F\u304B\u3063\u3066\u3044\u306A\u3044\n// \\( x\
    \ _______ x) ~\n\n#line 8 \"utility/modint.hpp\"\n#include <type_traits>\n#line\
    \ 10 \"utility/modint.hpp\"\n\nnamespace noya2 {\n\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\n\nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n\n  \
    \  explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m +\
    \ 1) {}\n\n    unsigned int umod() const { return _m; }\n\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        unsigned long long z = a;\n        z\
    \ *= b;\n#ifdef _MSC_VER\n        unsigned long long x;\n        _umul128(z, im,\
    \ &x);\n#else\n        unsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n#endif\n        unsigned int v = (unsigned int)(z\
    \ - x * _m);\n        if (_m <= v) v += _m;\n        return v;\n    }\n};\n\n\
    constexpr long long pow_mod_constexpr(long long x, long long n, int m) {\n   \
    \ if (m == 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned\
    \ long long r = 1;\n    unsigned long long y = safe_mod(x, m);\n    while (n)\
    \ {\n        if (n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n       \
    \ n >>= 1;\n    }\n    return r;\n}\n\nconstexpr bool is_prime_constexpr(int n)\
    \ {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    long long\
    \ s = b, t = a;\n    long long m0 = 0, m1 = 1;\n\n    while (t) {\n        long\
    \ long u = s / t;\n        s -= t * u;\n        m0 -= m1 * u; \n\n        auto\
    \ tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 =\
    \ m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n    return {s,\
    \ m0};\n}\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2)\
    \ return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return\
    \ 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n\
    \    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x = (m -\
    \ 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n}  // namespace noya2\n\nnamespace noya2 {\n\
    \n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value || std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 = typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value || std::is_same<T, unsigned __int128>::value, std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128 =\
    \ typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ || is_signed_int128<T>::value || is_unsigned_int128<T>::value, std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_signed_int = typename\
    \ std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || is_signed_int128<T>::value,\
    \ std::true_type, std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int\
    \ = typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value)\
    \ || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\n\n\
    template <class T>\nusing to_unsigned = typename std::conditional<is_signed_int128<T>::value,\
    \ make_unsigned_int128<T>, typename std::conditional<std::is_signed<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type>::type;\n\n#else\n\ntemplate\
    \ <class T> using is_integral = typename std::is_integral<T>;\n\ntemplate <class\
    \ T>\nusing is_signed_int = typename std::conditional<is_integral<T>::value &&\
    \ std::is_signed<T>::value, std::true_type, std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int = typename std::conditional<is_integral<T>::value\
    \ && std::is_unsigned<T>::value, std::true_type, std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing to_unsigned = typename std::conditional<is_signed_int<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type;\n\n#endif\n\ntemplate <class\
    \ T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace noya2\n\nnamespace noya2 {\n\nstruct modint_base {};\nstruct static_modint_base\
    \ : modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace noya2\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : noya2::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, noya2::is_signed_int_t<T>* = nullptr>\n \
    \   static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, noya2::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = noya2::inv_gcd(_v, m);\n      \
    \      assert(eg.first == 1);\n            return eg.second;\n        }\n    }\n\
    \n    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr\
    \ unsigned int umod() { return m; }\n    static constexpr bool prime = noya2::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : noya2::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = noya2::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, noya2::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n      \
    \  long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x +=\
    \ mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, noya2::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = noya2::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static noya2::barrett\
    \ bt;\n    static unsigned int umod() { return bt.umod(); }\n};\ntemplate <int\
    \ id> noya2::barrett dynamic_modint<id>::bt(998244353);\n\nusing modint998244353\
    \ = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n\nnamespace noya2 {\n\ntemplate <class T>\n\
    using is_static_modint = std::is_base_of<noya2::static_modint_base, T>;\n\ntemplate\
    \ <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace noya2\n#line 7 \"test/math/Determinant_of_Matrix.test.cpp\"\n\
    using mint = modint998244353;\n\nint main(){\n    int n; in(n);\n    Matrix<mint>\
    \ mat(n);\n    rep(i,n) rep(j,n){\n        ll x; in(x);\n        mat[i][j] = x;\n\
    \    }\n    out(mat.determinant());\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\"\
    template/template.hpp\"\n\n#include\"../../math/matrix.hpp\"\n#include\"../../utility/modint.hpp\"\
    \nusing mint = modint998244353;\n\nint main(){\n    int n; in(n);\n    Matrix<mint>\
    \ mat(n);\n    rep(i,n) rep(j,n){\n        ll x; in(x);\n        mat[i][j] = x;\n\
    \    }\n    out(mat.determinant());\n}"
  dependsOn:
  - template/template.hpp
  - template/inout.hpp
  - template/const.hpp
  - template/utils.hpp
  - math/matrix.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/math/Determinant_of_Matrix.test.cpp
  requiredBy: []
  timestamp: '2023-08-24 17:11:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Determinant_of_Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/math/Determinant_of_Matrix.test.cpp
- /verify/test/math/Determinant_of_Matrix.test.cpp.html
title: test/math/Determinant_of_Matrix.test.cpp
---
