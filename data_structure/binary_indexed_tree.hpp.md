---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/concepts.hpp
    title: misc/concepts.hpp
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
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/offline_rectangle_sum.hpp
    title: data_structure/offline_rectangle_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
    title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - icon: ':x:'
    path: test/data_structure/Rectangle_Sum.test.cpp
    title: test/data_structure/Rectangle_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Range_Inversions_Query.test.cpp
    title: test/data_structure/Static_Range_Inversions_Query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/binary_indexed_tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"misc/concepts.hpp\"\n\n#include<concepts>\n\
    \nnamespace noya2 {\n\ntemplate<class monoid>\nconcept Monoid = requires {\n \
    \   typename monoid::value_type;\n    {monoid::op(declval<typename monoid::value_type>(),declval<typename\
    \ monoid::value_type>())} -> std::same_as<typename monoid::value_type>;\n    {monoid::e()}\
    \ -> std::same_as<typename monoid::value_type>;\n};\n\ntemplate<class group>\n\
    concept Group = requires {\n    requires Monoid<group>;\n    {group::inv(declval<typename\
    \ group::value_type>())} -> std::same_as<typename group::value_type>;\n};\n\n\
    } // namespace noya2\n#line 5 \"data_structure/binary_indexed_tree.hpp\"\n\nnamespace\
    \ noya2{\n\ntemplate <Group G>\nstruct binary_indexed_tree {\n    using T = typename\
    \ G::value_type;\n    binary_indexed_tree (int _n = 0) : n(_n), d(_n + 1, G::e())\
    \ {}\n    void add(int i, T val) {\n        for (int x = i+1; x <= n; x += x &\
    \ -x) {\n            d[x] = G::op(d[x],val);\n        }\n    }\n    T prod(int\
    \ r){\n        return prefix_prod(r);\n    }\n    T prod(int l, int r) {\n   \
    \     return G::op(G::inv(prefix_prod(l)),prefix_prod(r));\n    }\n    T get(int\
    \ i){\n        return prod(i,i+1);\n    }\n    void set(int i, T val){\n     \
    \   add(i,G::op(G::inv(get(i)),val));\n    }\n  private:\n    int n;\n    std::vector<T>\
    \ d;\n    T prefix_prod(int i) {\n        assert(0 <= i && i <= n);\n        T\
    \ ret = G::e();\n        for (int x = i; x > 0; x -= x & -x) {\n            ret\
    \ = G::op(ret,d[x]);\n        }\n        return ret;\n    }\n};\n\n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../misc/concepts.hpp\"\
    \n\nnamespace noya2{\n\ntemplate <Group G>\nstruct binary_indexed_tree {\n   \
    \ using T = typename G::value_type;\n    binary_indexed_tree (int _n = 0) : n(_n),\
    \ d(_n + 1, G::e()) {}\n    void add(int i, T val) {\n        for (int x = i+1;\
    \ x <= n; x += x & -x) {\n            d[x] = G::op(d[x],val);\n        }\n   \
    \ }\n    T prod(int r){\n        return prefix_prod(r);\n    }\n    T prod(int\
    \ l, int r) {\n        return G::op(G::inv(prefix_prod(l)),prefix_prod(r));\n\
    \    }\n    T get(int i){\n        return prod(i,i+1);\n    }\n    void set(int\
    \ i, T val){\n        add(i,G::op(G::inv(get(i)),val));\n    }\n  private:\n \
    \   int n;\n    std::vector<T> d;\n    T prefix_prod(int i) {\n        assert(0\
    \ <= i && i <= n);\n        T ret = G::e();\n        for (int x = i; x > 0; x\
    \ -= x & -x) {\n            ret = G::op(ret,d[x]);\n        }\n        return\
    \ ret;\n    }\n};\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - misc/concepts.hpp
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.hpp
  requiredBy:
  - data_structure/offline_rectangle_sum.hpp
  timestamp: '2024-07-28 17:00:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/data_structure/Rectangle_Sum.test.cpp
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - test/data_structure/Static_Range_Inversions_Query.test.cpp
documentation_of: data_structure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/data_structure/binary_indexed_tree.hpp
- /library/data_structure/binary_indexed_tree.hpp.html
title: data_structure/binary_indexed_tree.hpp
---
