---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':x:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/modint61.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout.hpp\"\
    \nnamespace noya2 {\n\ntemplate<typename T> concept Scanable  = requires (ifstream\
    \ &is, T &a){ is >> a; };\ntemplate<typename T> concept Printable = requires (ofstream\
    \ &os, T &a){ os << a; };\n\ntemplate <typename Scanable> istream &operator>>(istream\
    \ &is, vector<Scanable> &v);\ntemplate <typename Printable> ostream &operator<<(ostream\
    \ &os, const vector<Printable> &v);\n\ntemplate <typename T, typename U>\nrequires\
    \ Scanable<T> && Scanable<U>\nistream &operator>>(istream &is, pair<T, U> &p){\n\
    \    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename T, typename\
    \ U>\nrequires Printable<T> && Printable<U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p){\n    os << p.first << \" \" << p.second;\n    return os;\n\
    }\n\ntemplate <typename Scanable>\nistream &operator>>(istream &is, vector<Scanable>\
    \ &v){\n    for (auto &x : v) is >> x;\n    return is;\n}\ntemplate <typename\
    \ Printable>\nostream &operator<<(ostream &os, const vector<Printable> &v){\n\
    \    int s = (int)v.size();\n    for (int i = 0; i < s; i++) os << (i ? \" \"\
    \ : \"\") << v[i];\n    return os;\n}\n\nvoid in() {}\ntemplate <typename Scanable,\
    \ class... U>\nvoid in(Scanable &t, U &...u){\n    cin >> t;\n    in(u...);\n\
    }\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename Printable, class... U,\
    \ char sep = ' '>\nvoid out(const Printable &t, const U &...u){\n    cout << t;\n\
    \    if (sizeof...(u)) cout << sep;\n    out(u...);\n}\ntemplate<typename Printable>\n\
    void out(const vector<vector<Printable>> &vv){\n    int s = (int)vv.size();\n\
    \    for (int i = 0; i < s; i++) out(vv[i]);\n}\n\nstruct IoSetup {\n    IoSetup(){\n\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"utility/modint61.hpp\"\
    \n\nstruct modint61 {\n    static constexpr bool is_modint = true;\n    static\
    \ constexpr ll mod = (1LL << 61) - 1;\n    ll val;\n    constexpr modint61(const\
    \ ll x = 0) : val(x) {\n        while (val < 0) val += mod;\n        while (val\
    \ >= mod) val -= mod;\n    }\n    bool operator<(const modint61& other) const\
    \ {\n        return val < other.val;\n    } // To use std::map\n    bool operator==(const\
    \ modint61& p) const { return val == p.val; }\n    bool operator!=(const modint61&\
    \ p) const { return val != p.val; }\n    modint61& operator+=(const modint61&\
    \ p) {\n        if ((val += p.val) >= mod) val -= mod;\n        return *this;\n\
    \    }\n    modint61& operator-=(const modint61& p) {\n        if ((val += mod\
    \ - p.val) >= mod) val -= mod;\n        return *this;\n    }\n    modint61& operator*=(const\
    \ modint61& p) {\n        ll a = val, b = p.val;\n        const ll MASK30 = (1LL\
    \ << 30) - 1;\n        const ll MASK31 = (1LL << 31) - 1;\n        const ll MASK61\
    \ = (1LL << 61) - 1;\n        ll au = a >> 31, ad = a & MASK31;\n        ll bu\
    \ = b >> 31, bd = b & MASK31;\n        ll x = ad * bu + au * bd;\n        ll xu\
    \ = x >> 30, xd = x & MASK30;\n        x = au * bu * 2 + xu + (xd << 31) + ad\
    \ * bd;\n        xu = x >> 61, xd = x & MASK61;\n        x = xu + xd;\n      \
    \  if (x >= MASK61) x -= MASK61;\n        val = x;\n        return *this;\n  \
    \  }\n    modint61 operator-() const { return modint61(get_mod() - val); }\n \
    \   modint61& operator/=(const modint61& p) {\n        *this *= p.inv();\n   \
    \     return *this;\n    }\n    modint61 operator+(const modint61& p) const {\
    \ return modint61(*this) += p; }\n    modint61 operator-(const modint61& p) const\
    \ { return modint61(*this) -= p; }\n    modint61 operator*(const modint61& p)\
    \ const { return modint61(*this) *= p; }\n    modint61 operator/(const modint61&\
    \ p) const { return modint61(*this) /= p; }\n\n    modint61 inv() const {\n  \
    \      ll a = val, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n      \
    \      t = a / b;\n            swap(a -= t * b, b), swap(u -= t * v, v);\n   \
    \     }\n        return modint61(u);\n    }\n    modint61 pow(ll n) const {\n\
    \        modint61 ret(1), mul(val);\n        while (n > 0) {\n            if (n\
    \ & 1) ret = ret * mul;\n            mul = mul * mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    static constexpr ll get_mod() { return\
    \ mod; }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nstruct modint61 {\n\
    \    static constexpr bool is_modint = true;\n    static constexpr ll mod = (1LL\
    \ << 61) - 1;\n    ll val;\n    constexpr modint61(const ll x = 0) : val(x) {\n\
    \        while (val < 0) val += mod;\n        while (val >= mod) val -= mod;\n\
    \    }\n    bool operator<(const modint61& other) const {\n        return val\
    \ < other.val;\n    } // To use std::map\n    bool operator==(const modint61&\
    \ p) const { return val == p.val; }\n    bool operator!=(const modint61& p) const\
    \ { return val != p.val; }\n    modint61& operator+=(const modint61& p) {\n  \
    \      if ((val += p.val) >= mod) val -= mod;\n        return *this;\n    }\n\
    \    modint61& operator-=(const modint61& p) {\n        if ((val += mod - p.val)\
    \ >= mod) val -= mod;\n        return *this;\n    }\n    modint61& operator*=(const\
    \ modint61& p) {\n        ll a = val, b = p.val;\n        const ll MASK30 = (1LL\
    \ << 30) - 1;\n        const ll MASK31 = (1LL << 31) - 1;\n        const ll MASK61\
    \ = (1LL << 61) - 1;\n        ll au = a >> 31, ad = a & MASK31;\n        ll bu\
    \ = b >> 31, bd = b & MASK31;\n        ll x = ad * bu + au * bd;\n        ll xu\
    \ = x >> 30, xd = x & MASK30;\n        x = au * bu * 2 + xu + (xd << 31) + ad\
    \ * bd;\n        xu = x >> 61, xd = x & MASK61;\n        x = xu + xd;\n      \
    \  if (x >= MASK61) x -= MASK61;\n        val = x;\n        return *this;\n  \
    \  }\n    modint61 operator-() const { return modint61(get_mod() - val); }\n \
    \   modint61& operator/=(const modint61& p) {\n        *this *= p.inv();\n   \
    \     return *this;\n    }\n    modint61 operator+(const modint61& p) const {\
    \ return modint61(*this) += p; }\n    modint61 operator-(const modint61& p) const\
    \ { return modint61(*this) -= p; }\n    modint61 operator*(const modint61& p)\
    \ const { return modint61(*this) *= p; }\n    modint61 operator/(const modint61&\
    \ p) const { return modint61(*this) /= p; }\n\n    modint61 inv() const {\n  \
    \      ll a = val, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n      \
    \      t = a / b;\n            swap(a -= t * b, b), swap(u -= t * v, v);\n   \
    \     }\n        return modint61(u);\n    }\n    modint61 pow(ll n) const {\n\
    \        modint61 ret(1), mul(val);\n        while (n > 0) {\n            if (n\
    \ & 1) ret = ret * mul;\n            mul = mul * mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    static constexpr ll get_mod() { return\
    \ mod; }\n};"
  dependsOn:
  - template/template.hpp
  - template/inout.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: utility/modint61.hpp
  requiredBy: []
  timestamp: '2023-08-24 20:23:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/modint61.hpp
layout: document
redirect_from:
- /library/utility/modint61.hpp
- /library/utility/modint61.hpp.html
title: utility/modint61.hpp
---
