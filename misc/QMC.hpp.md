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
    links:
    - https://i05nagai.github.io/memorandum/math/sobol_sequence.html
    - https://yoshiiz.blog.fc2.com/blog-entry-199.html
  bundledCode: "#line 2 \"misc/QMC.hpp\"\n\n/*\n\n\u5B9F\u88C5\u306E\u53C2\u8003\u306B\
    \u3057\u305F\uFF1A\nhttps://i05nagai.github.io/memorandum/math/sobol_sequence.html\n\
    \nsobol<32> sb({0,1});\nll id = 0;\nll x = sb.get(++id);\n\n\u306A\u3069\u306E\
    \u3088\u3046\u306B\u3057\u3066\u4F7F\u3046\u3002\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\u306B\u306F\u65E2\u7D04\u591A\u9805\u5F0F\u3092\u6295\u3052\u308B\
    \u3002\n5\u6B21\u4EE5\u4E0B\u306E\u65E2\u7D04\u591A\u9805\u5F0F\u4E00\u89A7\uFF1A\
    \nhttps://yoshiiz.blog.fc2.com/blog-entry-199.html\n\n*/\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 19 \"misc/QMC.hpp\"\n\nnamespace\
    \ noya2{\n\nrandom_device rd;\nmt19937_64 mt_for_sobol(rd());\n\ntemplate<int\
    \ bk>\nstruct sobol{\n    vector<ll> ms, vs;\n    sobol (const vector<ll> &f){\n\
    \        int s = f.size() - 1;\n        ms.resize(bk);\n        for (int i = 0;\
    \ i < s; i++){\n            ms[i] = 2 * (mt_for_sobol() % (1LL << i)) + 1;\n \
    \       }\n        for (int j = s; j < bk; j++){\n            ms[j] = ms[j-s];\n\
    \            for (int i = 1; i <= s; i++){\n                ms[j] ^= (f[i] <<\
    \ i) * ms[j-i];\n            }\n        }\n        vs.resize(bk);\n        for\
    \ (int i = 0; i < bk; i++){\n            vs[i] = ms[i] << (bk-1-i);\n        }\n\
    \    }\n    ll get(ll id){\n        ll res = 0;\n        for (int i = 0; i < bk;\
    \ i++){\n            res ^= (id >> i & 1) * vs[i];\n        }\n        return\
    \ res;\n    }\n    ld getld(ll id, ld lo, ld hi){\n        return lo + (hi - lo)\
    \ * ld(get(id)) / d;\n    }\n    static constexpr ld d = 1LL<<bk;\n};\n\n} //\
    \ namespace noya2\n"
  code: "#pragma once\n\n/*\n\n\u5B9F\u88C5\u306E\u53C2\u8003\u306B\u3057\u305F\uFF1A\
    \nhttps://i05nagai.github.io/memorandum/math/sobol_sequence.html\n\nsobol<32>\
    \ sb({0,1});\nll id = 0;\nll x = sb.get(++id);\n\n\u306A\u3069\u306E\u3088\u3046\
    \u306B\u3057\u3066\u4F7F\u3046\u3002\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u306B\u306F\u65E2\u7D04\u591A\u9805\u5F0F\u3092\u6295\u3052\u308B\u3002\n5\u6B21\
    \u4EE5\u4E0B\u306E\u65E2\u7D04\u591A\u9805\u5F0F\u4E00\u89A7\uFF1A\nhttps://yoshiiz.blog.fc2.com/blog-entry-199.html\n\
    \n*/\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\nrandom_device\
    \ rd;\nmt19937_64 mt_for_sobol(rd());\n\ntemplate<int bk>\nstruct sobol{\n   \
    \ vector<ll> ms, vs;\n    sobol (const vector<ll> &f){\n        int s = f.size()\
    \ - 1;\n        ms.resize(bk);\n        for (int i = 0; i < s; i++){\n       \
    \     ms[i] = 2 * (mt_for_sobol() % (1LL << i)) + 1;\n        }\n        for (int\
    \ j = s; j < bk; j++){\n            ms[j] = ms[j-s];\n            for (int i =\
    \ 1; i <= s; i++){\n                ms[j] ^= (f[i] << i) * ms[j-i];\n        \
    \    }\n        }\n        vs.resize(bk);\n        for (int i = 0; i < bk; i++){\n\
    \            vs[i] = ms[i] << (bk-1-i);\n        }\n    }\n    ll get(ll id){\n\
    \        ll res = 0;\n        for (int i = 0; i < bk; i++){\n            res ^=\
    \ (id >> i & 1) * vs[i];\n        }\n        return res;\n    }\n    ld getld(ll\
    \ id, ld lo, ld hi){\n        return lo + (hi - lo) * ld(get(id)) / d;\n    }\n\
    \    static constexpr ld d = 1LL<<bk;\n};\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: misc/QMC.hpp
  requiredBy: []
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/QMC.hpp
layout: document
redirect_from:
- /library/misc/QMC.hpp
- /library/misc/QMC.hpp.html
title: misc/QMC.hpp
---
