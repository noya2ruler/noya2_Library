---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/concepts.hpp
    title: misc/concepts.hpp
  - icon: ':heavy_check_mark:'
    path: misc/monoids.hpp
    title: misc/monoids.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj_dsl_1_b.test.cpp
    title: test/data_structure/aoj_dsl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/potentialized_dsu.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"misc/monoids.hpp\"\n\n#line 4\
    \ \"misc/monoids.hpp\"\n\nnamespace noya2{\n\ntemplate<typename T>\nstruct Max_monoid\
    \ {\n    using value_type = T;\n    static constexpr T op(const T &a, const T\
    \ &b){ return max(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::min();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct Min_monoid {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return min(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::max();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct Plus_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a + b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return -a; }\n};\ntemplate<typename\
    \ T>\nstruct Xor_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a ^ b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return a; }\n};\n    \n} // namespace\
    \ noya2\n#line 2 \"misc/concepts.hpp\"\n\n#include<concepts>\n\nnamespace noya2\
    \ {\n\ntemplate<class monoid>\nconcept Monoid = requires {\n    typename monoid::value_type;\n\
    \    {monoid::op(declval<typename monoid::value_type>(),declval<typename monoid::value_type>())}\
    \ -> std::same_as<typename monoid::value_type>;\n    {monoid::e()} -> std::same_as<typename\
    \ monoid::value_type>;\n};\n\ntemplate<class group>\nconcept Group = requires\
    \ {\n    requires Monoid<group>;\n    {group::inv(declval<typename group::value_type>())}\
    \ -> std::same_as<typename group::value_type>;\n};\n\n} // namespace noya2\n#line\
    \ 6 \"data_structure/potentialized_dsu.hpp\"\n\nnamespace noya2 {\n\ntemplate<Group\
    \ G>\nstruct potentialized_dsu {\n    using T = typename G::value_type;\n    potentialized_dsu\
    \ (int n_ = 0) : n(n_), parent_or_size(n_,-1) {\n        auto ee = G::e();\n \
    \       pot.resize(n,ee);\n    }\n    int merge(int u, int v, T d){\n        int\
    \ x = leader(u), y = leader(v);\n        if (x == y){\n            if (diff(u,v)\
    \ == d) return x;\n            else return -1;\n        }\n        d = G::op(G::op(potential(u),d),G::inv(potential(v)));\n\
    \        if (-parent_or_size[x] < -parent_or_size[y]){\n            d = G::inv(d);\n\
    \            swap(x,y);\n        }\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        pot[y] = d;\n        return x;\n    }\n\
    \    int leader(int v){\n        assert(0 <= v && v < n);\n        if (parent_or_size[v]\
    \ < 0) return v;\n        int l = leader(parent_or_size[v]);\n        pot[v] =\
    \ G::op(pot[v],pot[parent_or_size[v]]);\n        return parent_or_size[v] = l;\n\
    \    }\n    bool same(int u, int v){\n        return leader(u) == leader(v);\n\
    \    }\n    int size(int v){\n        return -parent_or_size[leader(v)];\n   \
    \ }\n    T potential(int v){\n        leader(v);\n        return pot[v];\n   \
    \ }\n    T diff(int u, int v){\n        return G::op(G::inv(potential(u)),potential(v));\n\
    \    }\n    int n;\n    vector<int> parent_or_size;\n    vector<T> pot;\n};\n\n\
    } // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../misc/monoids.hpp\"\
    \n#include\"../misc/concepts.hpp\"\n\nnamespace noya2 {\n\ntemplate<Group G>\n\
    struct potentialized_dsu {\n    using T = typename G::value_type;\n    potentialized_dsu\
    \ (int n_ = 0) : n(n_), parent_or_size(n_,-1) {\n        auto ee = G::e();\n \
    \       pot.resize(n,ee);\n    }\n    int merge(int u, int v, T d){\n        int\
    \ x = leader(u), y = leader(v);\n        if (x == y){\n            if (diff(u,v)\
    \ == d) return x;\n            else return -1;\n        }\n        d = G::op(G::op(potential(u),d),G::inv(potential(v)));\n\
    \        if (-parent_or_size[x] < -parent_or_size[y]){\n            d = G::inv(d);\n\
    \            swap(x,y);\n        }\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        pot[y] = d;\n        return x;\n    }\n\
    \    int leader(int v){\n        assert(0 <= v && v < n);\n        if (parent_or_size[v]\
    \ < 0) return v;\n        int l = leader(parent_or_size[v]);\n        pot[v] =\
    \ G::op(pot[v],pot[parent_or_size[v]]);\n        return parent_or_size[v] = l;\n\
    \    }\n    bool same(int u, int v){\n        return leader(u) == leader(v);\n\
    \    }\n    int size(int v){\n        return -parent_or_size[leader(v)];\n   \
    \ }\n    T potential(int v){\n        leader(v);\n        return pot[v];\n   \
    \ }\n    T diff(int u, int v){\n        return G::op(G::inv(potential(u)),potential(v));\n\
    \    }\n    int n;\n    vector<int> parent_or_size;\n    vector<T> pot;\n};\n\n\
    } // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - misc/monoids.hpp
  - misc/concepts.hpp
  isVerificationFile: false
  path: data_structure/potentialized_dsu.hpp
  requiredBy: []
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/aoj_dsl_1_b.test.cpp
documentation_of: data_structure/potentialized_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/potentialized_dsu.hpp
- /library/data_structure/potentialized_dsu.hpp.html
title: data_structure/potentialized_dsu.hpp
---
