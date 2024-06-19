---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
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
    path: test/data_structure/RangeParallelUnionfind.test.cpp
    title: test/data_structure/RangeParallelUnionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/range_parallel_dsu.hpp\"\n\n#line 2 \"data_structure/dsu.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
    #line 1 \"template/inout_old.hpp\"\nnamespace noya2 {\n\ntemplate <typename T,\
    \ typename U>\nostream &operator<<(ostream &os, const pair<T, U> &p){\n    os\
    \ << p.first << \" \" << p.second;\n    return os;\n}\ntemplate <typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &p){\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ const vector<T> &v){\n    int s = (int)v.size();\n    for (int i = 0; i < s;\
    \ i++) os << (i ? \" \" : \"\") << v[i];\n    return os;\n}\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (auto &x : v) is\
    \ >> x;\n    return is;\n}\n\nvoid in() {}\ntemplate <typename T, class... U>\n\
    void in(T &t, U &...u){\n    cin >> t;\n    in(u...);\n}\n\nvoid out() { cout\
    \ << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\nvoid out(const\
    \ T &t, const U &...u){\n    cout << t;\n    if (sizeof...(u)) cout << sep;\n\
    \    out(u...);\n}\n\ntemplate<typename T>\nvoid out(const vector<vector<T>> &vv){\n\
    \    int s = (int)vv.size();\n    for (int i = 0; i < s; i++) out(vv[i]);\n}\n\
    \nstruct IoSetup {\n    IoSetup(){\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n\
    \    }\n} iosetup_noya2;\n\n} // namespace noya2\n#line 1 \"template/const.hpp\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"data_structure/dsu.hpp\"\
    \n\nnamespace noya2{\n\nstruct dsu {\n  public:\n    dsu() : _n(0) {}\n    dsu(int\
    \ n) : _n(n), parent_or_size(n, -1) {}\n\n    int merge(int a, int b) {\n    \
    \    assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n        int\
    \ x = leader(a), y = leader(b);\n        if (x == y) return x;\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        return x;\n    }\n\n    bool same(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return\
    \ a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n    }\n\n\
    \    int size(int a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n} // namespace noya2\n#line\
    \ 4 \"data_structure/range_parallel_dsu.hpp\"\n\nnamespace noya2 {\n\nstruct range_parallel_dsu\
    \ : dsu {\n    using dsu::operator=;\n    int n;\n    std::vector<dsu> ds;\n \
    \   range_parallel_dsu (int _n0) : n(_n0) {\n        int msb = 31 - countl_zero((unsigned\
    \ int)(n));\n        ds.resize(msb, dsu(n));\n        (*this) = dsu(n);\n    }\n\
    \    // for k = 0, 1, ... ,d-1\n    // merge(i+k,j+k)\n    std::vector<std::tuple<int,int,int>>\
    \ merge_range(int i, int j, int d){\n        assert(i + d <= n);\n        assert(j\
    \ + d <= n);\n        if (d == 0) return {};\n        int msb = std::bit_width((unsigned\
    \ int)(d)) - 1;\n        std::vector<std::tuple<int,int,int>> connected;\n   \
    \     inner_merge(i, j, msb, connected);\n        inner_merge(i + d - (1<<msb),\
    \ j + d - (1<<msb), msb, connected);\n        return connected;\n    }\n  private:\n\
    \    // d = 2^k\n    void inner_merge(int i, int j, int k, std::vector<std::tuple<int,int,int>>\
    \ &connected){\n        // k >= 0\n        if (k == 0){\n            i = this->leader(i);\n\
    \            j = this->leader(j);\n            if (i == j) return ;\n        \
    \    int l = this->merge(i, j);\n            connected.emplace_back(i, j, l);\n\
    \        }\n        else {\n            k--;\n            if (ds[k].same(i, j))\
    \ return ;\n            ds[k].merge(i, j);\n            inner_merge(i, j, k, connected);\n\
    \            inner_merge(i + (1<<k), j + (1<<k), k, connected);\n        }\n \
    \   }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"data_structure/dsu.hpp\"\n\nnamespace noya2 {\n\
    \nstruct range_parallel_dsu : dsu {\n    using dsu::operator=;\n    int n;\n \
    \   std::vector<dsu> ds;\n    range_parallel_dsu (int _n0) : n(_n0) {\n      \
    \  int msb = 31 - countl_zero((unsigned int)(n));\n        ds.resize(msb, dsu(n));\n\
    \        (*this) = dsu(n);\n    }\n    // for k = 0, 1, ... ,d-1\n    // merge(i+k,j+k)\n\
    \    std::vector<std::tuple<int,int,int>> merge_range(int i, int j, int d){\n\
    \        assert(i + d <= n);\n        assert(j + d <= n);\n        if (d == 0)\
    \ return {};\n        int msb = std::bit_width((unsigned int)(d)) - 1;\n     \
    \   std::vector<std::tuple<int,int,int>> connected;\n        inner_merge(i, j,\
    \ msb, connected);\n        inner_merge(i + d - (1<<msb), j + d - (1<<msb), msb,\
    \ connected);\n        return connected;\n    }\n  private:\n    // d = 2^k\n\
    \    void inner_merge(int i, int j, int k, std::vector<std::tuple<int,int,int>>\
    \ &connected){\n        // k >= 0\n        if (k == 0){\n            i = this->leader(i);\n\
    \            j = this->leader(j);\n            if (i == j) return ;\n        \
    \    int l = this->merge(i, j);\n            connected.emplace_back(i, j, l);\n\
    \        }\n        else {\n            k--;\n            if (ds[k].same(i, j))\
    \ return ;\n            ds[k].merge(i, j);\n            inner_merge(i, j, k, connected);\n\
    \            inner_merge(i + (1<<k), j + (1<<k), k, connected);\n        }\n \
    \   }\n};\n\n} // namespace noya2"
  dependsOn:
  - data_structure/dsu.hpp
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: data_structure/range_parallel_dsu.hpp
  requiredBy: []
  timestamp: '2024-06-19 21:22:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/RangeParallelUnionfind.test.cpp
documentation_of: data_structure/range_parallel_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/range_parallel_dsu.hpp
- /library/data_structure/range_parallel_dsu.hpp.html
title: data_structure/range_parallel_dsu.hpp
---
