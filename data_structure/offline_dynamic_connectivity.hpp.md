---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/rollback_dsu.hpp
    title: data_structure/rollback_dsu.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj_2235.test.cpp
    title: test/data_structure/aoj_2235.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/offline_dynamic_connectivity.hpp\"\n\n#line\
    \ 2 \"data_structure/rollback_dsu.hpp\"\n\n#line 2 \"template/template.hpp\"\n\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"data_structure/rollback_dsu.hpp\"\
    \n\nnamespace noya2 {\n\nstruct rollback_dsu {\n    rollback_dsu (int n_ = 0)\
    \ : n(n_), par_or_siz(n_,-1) {};\n    int leader(int v){\n        assert(0 <=\
    \ v && v < n);\n        if (par_or_siz[v] < 0) return v;\n        return leader(par_or_siz[v]);\n\
    \    }\n    bool same(int u, int v){\n        return leader(u) == leader(v);\n\
    \    }\n    int merge(int u, int v){\n        u = leader(u);\n        v = leader(v);\n\
    \        logs.push(make_pair(u,par_or_siz[u]));\n        logs.push(make_pair(v,par_or_siz[v]));\n\
    \        if (u == v) return u;\n        if (-par_or_siz[u] < -par_or_siz[v]) swap(u,v);\n\
    \        par_or_siz[u] += par_or_siz[v];\n        par_or_siz[v] = u;\n       \
    \ return u;\n    }\n    int size(int v){\n        return -par_or_siz[leader(v)];\n\
    \    }\n    void rollback(){\n        par_or_siz[logs.top().first] = logs.top().second;\
    \ logs.pop();\n        par_or_siz[logs.top().first] = logs.top().second; logs.pop();\n\
    \    }\n  private:\n    int n;\n    vector<int> par_or_siz;\n    stack<pair<int,int>>\
    \ logs;\n};\n\n} // namespace noya2\n#line 4 \"data_structure/offline_dynamic_connectivity.hpp\"\
    \n\nnamespace noya2 {\n\nstruct offline_dynamic_connectivity : rollback_dsu {\n\
    \    using rollback_dsu::operator=;\n    offline_dynamic_connectivity (int n_\
    \ = 0, unsigned int t_max = 0, size_t reserve_edge = 0) : n(n_) {\n        size\
    \ = bit_ceil(t_max);\n        ids.resize(size*2);\n        *this = rollback_dsu(n);\n\
    \        edges.reserve(reserve_edge);\n        inner_clock = -1;\n    }\n    void\
    \ add_edge(int l, int r, int u, int v){\n        assert(0 <= l && l <= r && r\
    \ <= size);\n        assert(0 <= u && u < n && 0 <= v && v < n);\n        l +=\
    \ size, r += size;\n        int edge_id = edges.size();\n        while (l < r){\n\
    \            if (l & 1) ids[l++].push_back(edge_id);\n            if (r & 1) ids[--r].push_back(edge_id);\n\
    \            l >>= 1, r >>= 1;\n        }\n        edges.emplace_back(u,v);\n\
    \    }\n    void build(){\n        inner_clock = 1;\n        while (inner_clock\
    \ != size){\n            add_block(inner_clock);\n            inner_clock <<=\
    \ 1;\n        }\n    }\n    void set(int t){\n        assert(0 <= t && t < size\
    \ && inner_clock != -1);\n        t += size;\n        if (inner_clock == t) return\
    \ ;\n        int k = 32 - countl_zero((unsigned int)(inner_clock ^ t));\n    \
    \    for (int i = 0; i < k; i++){\n            del_block(inner_clock);\n     \
    \       inner_clock >>= 1;\n        }\n        for (int i = k-1; i >= 0; i--){\n\
    \            inner_clock <<= 1;\n            if (t >> i & 1) inner_clock++;\n\
    \            add_block(inner_clock);\n        }\n        inner_clock = t;\n  \
    \  }\n  private:\n    void add_block(int i){\n        for (auto &id : ids[i]){\n\
    \            this->merge(edges[id].first,edges[id].second);\n        }\n    }\n\
    \    void del_block(int i){\n        int ctr = ids[i].size();\n        while (ctr--)\
    \ this->rollback();\n    }\n    int n, size, inner_clock;\n    vector<vector<int>>\
    \ ids;\n    vector<pair<int,int>> edges;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../data_structure/rollback_dsu.hpp\"\n\nnamespace\
    \ noya2 {\n\nstruct offline_dynamic_connectivity : rollback_dsu {\n    using rollback_dsu::operator=;\n\
    \    offline_dynamic_connectivity (int n_ = 0, unsigned int t_max = 0, size_t\
    \ reserve_edge = 0) : n(n_) {\n        size = bit_ceil(t_max);\n        ids.resize(size*2);\n\
    \        *this = rollback_dsu(n);\n        edges.reserve(reserve_edge);\n    \
    \    inner_clock = -1;\n    }\n    void add_edge(int l, int r, int u, int v){\n\
    \        assert(0 <= l && l <= r && r <= size);\n        assert(0 <= u && u <\
    \ n && 0 <= v && v < n);\n        l += size, r += size;\n        int edge_id =\
    \ edges.size();\n        while (l < r){\n            if (l & 1) ids[l++].push_back(edge_id);\n\
    \            if (r & 1) ids[--r].push_back(edge_id);\n            l >>= 1, r >>=\
    \ 1;\n        }\n        edges.emplace_back(u,v);\n    }\n    void build(){\n\
    \        inner_clock = 1;\n        while (inner_clock != size){\n            add_block(inner_clock);\n\
    \            inner_clock <<= 1;\n        }\n    }\n    void set(int t){\n    \
    \    assert(0 <= t && t < size && inner_clock != -1);\n        t += size;\n  \
    \      if (inner_clock == t) return ;\n        int k = 32 - countl_zero((unsigned\
    \ int)(inner_clock ^ t));\n        for (int i = 0; i < k; i++){\n            del_block(inner_clock);\n\
    \            inner_clock >>= 1;\n        }\n        for (int i = k-1; i >= 0;\
    \ i--){\n            inner_clock <<= 1;\n            if (t >> i & 1) inner_clock++;\n\
    \            add_block(inner_clock);\n        }\n        inner_clock = t;\n  \
    \  }\n  private:\n    void add_block(int i){\n        for (auto &id : ids[i]){\n\
    \            this->merge(edges[id].first,edges[id].second);\n        }\n    }\n\
    \    void del_block(int i){\n        int ctr = ids[i].size();\n        while (ctr--)\
    \ this->rollback();\n    }\n    int n, size, inner_clock;\n    vector<vector<int>>\
    \ ids;\n    vector<pair<int,int>> edges;\n};\n\n} // namespace noya2"
  dependsOn:
  - data_structure/rollback_dsu.hpp
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: data_structure/offline_dynamic_connectivity.hpp
  requiredBy: []
  timestamp: '2023-10-23 03:10:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/aoj_2235.test.cpp
documentation_of: data_structure/offline_dynamic_connectivity.hpp
layout: document
redirect_from:
- /library/data_structure/offline_dynamic_connectivity.hpp
- /library/data_structure/offline_dynamic_connectivity.hpp.html
title: data_structure/offline_dynamic_connectivity.hpp
---
