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
    path: geometry/partition_by_circle.hpp
    title: geometry/partition_by_circle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/aoj1198.test.cpp
    title: test/geometry/aoj1198.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/base_ld.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"geometry/base_ld.hpp\"\
    \n\nnamespace noya2 {\n\nusing vec = complex<ld>;\n\nconst ld PI = acos(-1);\n\
    \nint sgn(ld a, const ld eps = 1e-7) {\n    return (a < -eps) ? -1 : (a > eps)\
    \ ? 1 : 0;\n}\n\nbool same_vec(vec a, vec b) {\n    a -= b;\n    return sgn(a.real())\
    \ == 0 && sgn(a.imag()) == 0;\n}\n\nld dot(const vec &a, const vec &b) {\n   \
    \ return (conj(a) * b).real();\n}\n\nld cross(const vec &a, const vec &b) {\n\
    \    return (conj(a) * b).imag();\n}\n\nint isp(const vec &a, const vec &b, const\
    \ vec &c) {\n    int cross_sgn = sgn(cross(b - a, c - a));\n    if (cross_sgn\
    \ == 0) {\n        if (sgn(dot(b - a, c - a)) < 0) return -2;\n        if (sgn(dot(a\
    \ - b, c - b)) < 0) return 2;\n    }\n    return cross_sgn;\n}\n\nvec rot90(const\
    \ vec &a) {\n    return {-a.imag(), a.real()};\n}\n\nvec rot(const vec &a, ld\
    \ rad) {\n    return a * vec(cosl(rad), sinl(rad));\n}\n\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace noya2\
    \ {\n\nusing vec = complex<ld>;\n\nconst ld PI = acos(-1);\n\nint sgn(ld a, const\
    \ ld eps = 1e-7) {\n    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nbool\
    \ same_vec(vec a, vec b) {\n    a -= b;\n    return sgn(a.real()) == 0 && sgn(a.imag())\
    \ == 0;\n}\n\nld dot(const vec &a, const vec &b) {\n    return (conj(a) * b).real();\n\
    }\n\nld cross(const vec &a, const vec &b) {\n    return (conj(a) * b).imag();\n\
    }\n\nint isp(const vec &a, const vec &b, const vec &c) {\n    int cross_sgn =\
    \ sgn(cross(b - a, c - a));\n    if (cross_sgn == 0) {\n        if (sgn(dot(b\
    \ - a, c - a)) < 0) return -2;\n        if (sgn(dot(a - b, c - b)) < 0) return\
    \ 2;\n    }\n    return cross_sgn;\n}\n\nvec rot90(const vec &a) {\n    return\
    \ {-a.imag(), a.real()};\n}\n\nvec rot(const vec &a, ld rad) {\n    return a *\
    \ vec(cosl(rad), sinl(rad));\n}\n\n\n}  // namespace lib\n"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: geometry/base_ld.hpp
  requiredBy:
  - geometry/partition_by_circle.hpp
  timestamp: '2023-08-26 17:35:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/aoj1198.test.cpp
documentation_of: geometry/base_ld.hpp
layout: document
redirect_from:
- /library/geometry/base_ld.hpp
- /library/geometry/base_ld.hpp.html
title: geometry/base_ld.hpp
---
