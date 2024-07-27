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
    path: math/gcd_convolution.hpp
    title: math/gcd_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: math/lcm_convolution.hpp
    title: math/lcm_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Gcd_Convolution.test.cpp
    title: test/math/Gcd_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Lcm_Convolution.test.cpp
    title: test/math/Lcm_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/sieve.hpp\"\n\n#line 2 \"template/template.hpp\"\n\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"math/sieve.hpp\"\n\nnamespace\
    \ noya2{\n\nstruct Sieve {\n    vector<int> primes, factor, mu;\n    Sieve (int\
    \ N = 1024){\n        build(N);\n    }\n    void request(int N){\n        int\
    \ len = n_max();\n        if (len >= N) return ;\n        while (len < N) len\
    \ <<= 1;\n        build(len);\n    }\n    int n_max(){ return factor.size()-1;\
    \ }\n  private:\n    void build (int N){\n        primes.clear();\n        factor.resize(N+1);\
    \ fill(factor.begin(),factor.end(),0);\n        mu.resize(N+1); fill(mu.begin(),mu.end(),1);\n\
    \n        for(int n = 2; n <= N; n++) {\n            if (factor[n] == 0){\n  \
    \              primes.push_back(n);\n                factor[n] = n;\n        \
    \        mu[n] = -1;\n            }\n            for (int p : primes){\n     \
    \           if(n * p > N || p > factor[n]) break;\n                factor[n *\
    \ p] = p;\n                mu[n * p] = p == factor[n] ? 0 : -mu[n];\n        \
    \    }\n        }\n    }\n} sieve;\n\nint mobius_sieve(int n){\n    assert(1 <=\
    \ n && n <= sieve.n_max());\n    return sieve.mu[n];\n}\nbool is_prime_sieve(int\
    \ n){\n    if (n <= 2) return n == 2;\n    assert(n <= sieve.n_max());\n    return\
    \ sieve.factor[n] == n;\n}\n\nvector<pair<int,int>> prime_factorization_sieve(int\
    \ n){\n    assert(1 <= n && n <= sieve.n_max());\n    vector<int> facts;\n   \
    \ while (n > 1){\n        int p = sieve.factor[n];\n        facts.push_back(p);\n\
    \        n /= p;\n    }\n    vector<pair<int,int>> pes;\n    int siz = facts.size();\n\
    \    for (int l = 0, r = 0; l < siz; l = r){\n        while (r < siz && facts[r]\
    \ == facts[l]) r++;\n        pes.emplace_back(facts[l],r-l);\n    }\n    return\
    \ pes;\n}\n\nvector<int> divisor_enumeration_sieve(int n){\n    auto pes = prime_factorization_sieve(n);\n\
    \    vector<int> divs = {1};\n    for (auto [p, e] : pes){\n        vector<int>\
    \ nxt; nxt.reserve(divs.size() * (e+1));\n        for (auto x : divs){\n     \
    \       for (int tt = 0; tt <= e; tt++){\n                nxt.push_back(x);\n\
    \                x *= p;\n            }\n        }\n        swap(divs,nxt);\n\
    \    }\n    return divs;\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\
    \nstruct Sieve {\n    vector<int> primes, factor, mu;\n    Sieve (int N = 1024){\n\
    \        build(N);\n    }\n    void request(int N){\n        int len = n_max();\n\
    \        if (len >= N) return ;\n        while (len < N) len <<= 1;\n        build(len);\n\
    \    }\n    int n_max(){ return factor.size()-1; }\n  private:\n    void build\
    \ (int N){\n        primes.clear();\n        factor.resize(N+1); fill(factor.begin(),factor.end(),0);\n\
    \        mu.resize(N+1); fill(mu.begin(),mu.end(),1);\n\n        for(int n = 2;\
    \ n <= N; n++) {\n            if (factor[n] == 0){\n                primes.push_back(n);\n\
    \                factor[n] = n;\n                mu[n] = -1;\n            }\n\
    \            for (int p : primes){\n                if(n * p > N || p > factor[n])\
    \ break;\n                factor[n * p] = p;\n                mu[n * p] = p ==\
    \ factor[n] ? 0 : -mu[n];\n            }\n        }\n    }\n} sieve;\n\nint mobius_sieve(int\
    \ n){\n    assert(1 <= n && n <= sieve.n_max());\n    return sieve.mu[n];\n}\n\
    bool is_prime_sieve(int n){\n    if (n <= 2) return n == 2;\n    assert(n <= sieve.n_max());\n\
    \    return sieve.factor[n] == n;\n}\n\nvector<pair<int,int>> prime_factorization_sieve(int\
    \ n){\n    assert(1 <= n && n <= sieve.n_max());\n    vector<int> facts;\n   \
    \ while (n > 1){\n        int p = sieve.factor[n];\n        facts.push_back(p);\n\
    \        n /= p;\n    }\n    vector<pair<int,int>> pes;\n    int siz = facts.size();\n\
    \    for (int l = 0, r = 0; l < siz; l = r){\n        while (r < siz && facts[r]\
    \ == facts[l]) r++;\n        pes.emplace_back(facts[l],r-l);\n    }\n    return\
    \ pes;\n}\n\nvector<int> divisor_enumeration_sieve(int n){\n    auto pes = prime_factorization_sieve(n);\n\
    \    vector<int> divs = {1};\n    for (auto [p, e] : pes){\n        vector<int>\
    \ nxt; nxt.reserve(divs.size() * (e+1));\n        for (auto x : divs){\n     \
    \       for (int tt = 0; tt <= e; tt++){\n                nxt.push_back(x);\n\
    \                x *= p;\n            }\n        }\n        swap(divs,nxt);\n\
    \    }\n    return divs;\n}\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: math/sieve.hpp
  requiredBy:
  - math/gcd_convolution.hpp
  - math/lcm_convolution.hpp
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Gcd_Convolution.test.cpp
  - test/math/Lcm_Convolution.test.cpp
documentation_of: math/sieve.hpp
layout: document
redirect_from:
- /library/math/sieve.hpp
- /library/math/sieve.hpp.html
title: math/sieve.hpp
---