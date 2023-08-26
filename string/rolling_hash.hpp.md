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
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"string/rolling_hash.hpp\"\
    \n\nnamespace noya2{\n\nstruct RollingHash {\n    using ull = unsigned long long;\n\
    \    RollingHash(const string &s = \"\"){ build(s);}\n    ull get(int l, int r){\
    \ \n        assert(0 <= l && l <= r && r <= n);\n        return cal_mod(inner_hash[r]\
    \ + POSITIVISER - mul_mod(inner_hash[l], pow_base[r-l]));\n    }\n    static ull\
    \ get_hash(const string &s){\n        int len = s.size();\n        set_hash();\n\
    \        extend_pow_base(len);\n        ull res = 0;\n        for (int i = 0;\
    \ i < len; i++) res = cal_mod(mul_mod(res,BASE) + s[i]);\n        return res;\n\
    \    }\n    template<class... Hash_Lengths> static ull concat(const Hash_Lengths&...\
    \ hash_length){\n        return inner_concat(0ULL,hash_length...);\n    }\n  private:\n\
    \    static ull inner_concat(const ull& temp){\n        return temp;\n    }\n\
    \    template<class... Tail> static ull inner_concat(const ull& temp, const ull&\
    \ hash, const int& len, const Tail&... tail){\n        return inner_concat(cal_mod(cal_mod(mul_mod(temp,pow_base[len]))+hash),tail...);\n\
    \    }\n    static constexpr ull MASK30 = (1ULL << 30) - 1;\n    static constexpr\
    \ ull MASK31 = (1ULL << 31) - 1;\n    static constexpr ull MASK61 = (1ULL << 61)\
    \ - 1;\n    static constexpr ull MOD = (1ULL << 61) - 1;\n    static constexpr\
    \ ull POSITIVISER = MOD * 4;\n    static ull BASE;\n    static vector<ull> pow_base;\n\
    \    static ull mul_mod(ull a, ull b){\n        ull au = a >> 31, ad = a & MASK31;\n\
    \        ull bu = b >> 31, bd = b & MASK31;\n        ull mid = ad * bu + au *\
    \ bd;\n        ull midu = mid >> 30, midd = mid & MASK30;\n        return (au\
    \ * bu * 2 + midu + (midd << 31) + ad * bd);\n    }\n    static ull cal_mod(ull\
    \ x){\n        ull xu = x >> 61;\n        ull xd = x & MASK61;\n        ull res\
    \ = xu + xd;\n        if (res >= MOD) res -= MOD;\n        return res;\n    }\n\
    \    static void set_hash(){\n        if (BASE == 0) BASE = (1UL<<31) + (random_device()()\
    \ & MASK31);\n    }\n    static void extend_pow_base(int len){\n        int nlen\
    \ = pow_base.size();\n        if (nlen > len) return ;\n        pow_base.resize(len+1);\n\
    \        for (int i = nlen; i <= len; i++){\n            pow_base[i] = cal_mod(mul_mod(pow_base[i-1],BASE));\n\
    \        }\n    }\n    string str;\n    int n;\n    vector<ull> inner_hash;\n\
    \    void build(const string &s){\n        set_hash();\n        str = s;\n   \
    \     n = s.size();\n        extend_pow_base(n);\n        inner_hash.resize(n+1);\n\
    \        inner_hash[0] = 0;\n        for (int i = 0; i < n; i++) inner_hash[i+1]\
    \ = cal_mod(mul_mod(inner_hash[i],BASE) + s[i]);\n    }\n};\nusing ull = unsigned\
    \ long long;\null RollingHash::BASE = 0;\nvector<ull> RollingHash::pow_base =\
    \ vector<ull>(1,1);\nusing roriha = RollingHash;\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\
    \nstruct RollingHash {\n    using ull = unsigned long long;\n    RollingHash(const\
    \ string &s = \"\"){ build(s);}\n    ull get(int l, int r){ \n        assert(0\
    \ <= l && l <= r && r <= n);\n        return cal_mod(inner_hash[r] + POSITIVISER\
    \ - mul_mod(inner_hash[l], pow_base[r-l]));\n    }\n    static ull get_hash(const\
    \ string &s){\n        int len = s.size();\n        set_hash();\n        extend_pow_base(len);\n\
    \        ull res = 0;\n        for (int i = 0; i < len; i++) res = cal_mod(mul_mod(res,BASE)\
    \ + s[i]);\n        return res;\n    }\n    template<class... Hash_Lengths> static\
    \ ull concat(const Hash_Lengths&... hash_length){\n        return inner_concat(0ULL,hash_length...);\n\
    \    }\n  private:\n    static ull inner_concat(const ull& temp){\n        return\
    \ temp;\n    }\n    template<class... Tail> static ull inner_concat(const ull&\
    \ temp, const ull& hash, const int& len, const Tail&... tail){\n        return\
    \ inner_concat(cal_mod(cal_mod(mul_mod(temp,pow_base[len]))+hash),tail...);\n\
    \    }\n    static constexpr ull MASK30 = (1ULL << 30) - 1;\n    static constexpr\
    \ ull MASK31 = (1ULL << 31) - 1;\n    static constexpr ull MASK61 = (1ULL << 61)\
    \ - 1;\n    static constexpr ull MOD = (1ULL << 61) - 1;\n    static constexpr\
    \ ull POSITIVISER = MOD * 4;\n    static ull BASE;\n    static vector<ull> pow_base;\n\
    \    static ull mul_mod(ull a, ull b){\n        ull au = a >> 31, ad = a & MASK31;\n\
    \        ull bu = b >> 31, bd = b & MASK31;\n        ull mid = ad * bu + au *\
    \ bd;\n        ull midu = mid >> 30, midd = mid & MASK30;\n        return (au\
    \ * bu * 2 + midu + (midd << 31) + ad * bd);\n    }\n    static ull cal_mod(ull\
    \ x){\n        ull xu = x >> 61;\n        ull xd = x & MASK61;\n        ull res\
    \ = xu + xd;\n        if (res >= MOD) res -= MOD;\n        return res;\n    }\n\
    \    static void set_hash(){\n        if (BASE == 0) BASE = (1UL<<31) + (random_device()()\
    \ & MASK31);\n    }\n    static void extend_pow_base(int len){\n        int nlen\
    \ = pow_base.size();\n        if (nlen > len) return ;\n        pow_base.resize(len+1);\n\
    \        for (int i = nlen; i <= len; i++){\n            pow_base[i] = cal_mod(mul_mod(pow_base[i-1],BASE));\n\
    \        }\n    }\n    string str;\n    int n;\n    vector<ull> inner_hash;\n\
    \    void build(const string &s){\n        set_hash();\n        str = s;\n   \
    \     n = s.size();\n        extend_pow_base(n);\n        inner_hash.resize(n+1);\n\
    \        inner_hash[0] = 0;\n        for (int i = 0; i < n; i++) inner_hash[i+1]\
    \ = cal_mod(mul_mod(inner_hash[i],BASE) + s[i]);\n    }\n};\nusing ull = unsigned\
    \ long long;\null RollingHash::BASE = 0;\nvector<ull> RollingHash::pow_base =\
    \ vector<ull>(1,1);\nusing roriha = RollingHash;\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-08-26 17:35:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
