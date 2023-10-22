---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout_old.hpp
    title: template/inout_old.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_modint.hpp
    title: fps/fps_modint.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_ntt.hpp
    title: fps/fps_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt.hpp
    title: fps/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/relaxed_convolution.hpp
    title: fps/relaxed_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sample_point_shift.hpp
    title: fps/sample_point_shift.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
    title: test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Convolution1000000007.test.cpp
    title: test/fps/Convolution1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Inv_of_Formal_Power_Series.test.cpp
    title: test/fps/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
    title: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/convolution.test.cpp
    title: test/fps/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/convolution_relaxed_convolution.test.cpp
    title: test/fps/convolution_relaxed_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Determinant_of_Matrix.test.cpp
    title: test/math/Determinant_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Lcm_Convolution.test.cpp
    title: test/math/Lcm_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime.hpp\"\n\n#line 2 \"template/template.hpp\"\n\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"math/prime.hpp\"\
    \n\nnamespace noya2 {\n\nconstexpr ll safe_mod(ll x, ll m) {\n    x %= m;\n  \
    \  if (x < 0) x += m;\n    return x;\n}\n\nconstexpr ll pow_mod_constexpr(ll x,\
    \ ll n, int m) {\n    if (m == 1) return 0;\n    uint _m = (uint)(m);\n    ull\
    \ r = 1;\n    ull y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r =\
    \ (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return\
    \ r;\n}\n\nconstexpr bool is_prime_constexpr(int n) {\n    if (n <= 1) return\
    \ false;\n    if (n == 2 || n == 7 || n == 61) return true;\n    if (n % 2 ==\
    \ 0) return false;\n    ll d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    constexpr\
    \ ll bases[3] = {2, 7, 61};\n    for (ll a : bases) {\n        ll t = d;\n   \
    \     ll y = pow_mod_constexpr(a, t, n);\n        while (t != n - 1 && y != 1\
    \ && y != n - 1) {\n            y = y * y % n;\n            t <<= 1;\n       \
    \ }\n        if (y != n - 1 && t % 2 == 0) {\n            return false;\n    \
    \    }\n    }\n    return true;\n}\ntemplate <int n> constexpr bool is_prime_flag\
    \ = is_prime_constexpr(n);\n\nconstexpr std::pair<long long, long long> inv_gcd(long\
    \ long a, long long b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b,\
    \ 0};\n    long long s = b, t = a;\n    long long m0 = 0, m1 = 1;\n    while (t)\
    \ {\n        long long u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\
    \ \n        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n  \
    \  return {s, m0};\n}\n\nconstexpr int primitive_root_constexpr(int m) {\n   \
    \ if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (ll)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root_flag\
    \ = primitive_root_constexpr(m);\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2 {\n\
    \nconstexpr ll safe_mod(ll x, ll m) {\n    x %= m;\n    if (x < 0) x += m;\n \
    \   return x;\n}\n\nconstexpr ll pow_mod_constexpr(ll x, ll n, int m) {\n    if\
    \ (m == 1) return 0;\n    uint _m = (uint)(m);\n    ull r = 1;\n    ull y = safe_mod(x,\
    \ m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y = (y *\
    \ y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    ll d = n - 1;\n    while (d %\
    \ 2 == 0) d /= 2;\n    constexpr ll bases[3] = {2, 7, 61};\n    for (ll a : bases)\
    \ {\n        ll t = d;\n        ll y = pow_mod_constexpr(a, t, n);\n        while\
    \ (t != n - 1 && y != 1 && y != n - 1) {\n            y = y * y % n;\n       \
    \     t <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n         \
    \   return false;\n        }\n    }\n    return true;\n}\ntemplate <int n> constexpr\
    \ bool is_prime_flag = is_prime_constexpr(n);\n\nconstexpr std::pair<long long,\
    \ long long> inv_gcd(long long a, long long b) {\n    a = safe_mod(a, b);\n  \
    \  if (a == 0) return {b, 0};\n    long long s = b, t = a;\n    long long m0 =\
    \ 0, m1 = 1;\n    while (t) {\n        long long u = s / t;\n        s -= t *\
    \ u;\n        m0 -= m1 * u; \n        auto tmp = s;\n        s = t;\n        t\
    \ = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if\
    \ (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int\
    \ x = (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (ll)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root_flag\
    \ = primitive_root_constexpr(m);\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy:
  - utility/modint.hpp
  - fps/ntt.hpp
  - fps/sample_point_shift.hpp
  - fps/fps_modint.hpp
  - fps/relaxed_convolution.hpp
  - fps/fps_ntt.hpp
  timestamp: '2023-10-09 15:49:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/convolution_relaxed_convolution.test.cpp
  - test/fps/Convolution1000000007.test.cpp
  - test/fps/convolution.test.cpp
  - test/fps/Inv_of_Formal_Power_Series.test.cpp
  - test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
  - test/math/Lcm_Convolution.test.cpp
  - test/math/Determinant_of_Matrix.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
documentation_of: math/prime.hpp
layout: document
redirect_from:
- /library/math/prime.hpp
- /library/math/prime.hpp.html
title: math/prime.hpp
---
