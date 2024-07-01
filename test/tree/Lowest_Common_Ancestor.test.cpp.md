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
  - icon: ':heavy_check_mark:'
    path: tree/Tree_core.hpp
    title: tree/Tree_core.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/tree/Lowest_Common_Ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"tree/Tree_core.hpp\"\n\n#line\
    \ 4 \"tree/Tree_core.hpp\"\n\nnamespace noya2{\n\nstruct naiveTree { // undirected\
    \ unweighted tree\n    naiveTree (int _n = 0) : n(_n){\n        es0.resize(_n);\n\
    \        es1.resize(_n);\n    }\n    void add_edge(int u, int v, int id = -1){\n\
    \        es0[u].emplace_back(v);\n        es0[v].emplace_back(u);\n        es1[u].emplace_back(v,id);\n\
    \        es1[v].emplace_back(u,id);\n    }\n    void input(int _indexed = 1){\n\
    \        rep(i,n-1){\n            int u, v; cin >> u >> v;\n            u -= _indexed;\n\
    \            v -= _indexed;\n            add_edge(u,v);\n        }\n    }\n  \
    \  const vector<int>& operator[](int idx) const { return es0[idx]; }\n    const\
    \ vector<pair<int,int>>& operator()(int idx) const {return es1[idx]; }\n  private:\n\
    \    int n;\n    vector<vector<int>> es0;\n    vector<vector<pair<int,int>>> es1;\n\
    };\n\n\nstruct usefulTree { // rooted unweighted tree\n    usefulTree (int _n\
    \ = 0, int _root = 0) : n(_n), root(_root) {\n        es.resize(n);\n    }\n \
    \   void add_edge(int u, int v){\n        es[u].emplace_back(v);\n        es[v].emplace_back(u);\n\
    \    }\n    void input(int _indexed = 1){\n        rep(i,n-1){\n            int\
    \ u, v; cin >> u >> v;\n            u -= _indexed;\n            v -= _indexed;\n\
    \            add_edge(u,v);\n        }\n    }\n    const vector<int>& operator[](int\
    \ idx) const { return es[idx]; }\n    int parent(int v){ return par[0][v]; }\n\
    \    int subtree_size(int v){\n        if (sub[v] != -1) return sub[v];\n    \
    \    sub[v] = 1;\n        for (int child : es[v]){\n            if (child != par[0][v])\
    \ sub[v] += subtree_size(child);\n        }\n        return sub[v];\n    }\n \
    \   int depth(int v){ return dep[v]; }\n    int lca(int u, int v){\n        if\
    \ (dep[u] > dep[v]) swap(u,v);\n        for (int i = 0; i < p2size; i++) if ((dep[v]\
    \ - dep[u]) >> i & 1) v = par[i][v];\n        if (u == v) return u;\n        for\
    \ (int i = p2size-1; i >= 0; i--){\n            if (par[i][u] != par[i][v]){\n\
    \                u = par[i][u];\n                v = par[i][v];\n            }\n\
    \        }\n        return par[0][u];\n    }\n    int jump_to_root(int from, int\
    \ d){\n        for (int i = 0; i < p2size; i++){\n            if ((d >> i & 1)\
    \ == 1 && from != -1) from = par[i][from];\n        }\n        return from;\n\
    \    }\n    int jump(int from, int to, int d){\n        int l = lca(from,to);\n\
    \        if (d <= dep[from] - dep[l]){\n            return jump_to_root(from,d);\n\
    \        }\n        d -= dep[from] - dep[l];\n        if (d <= dep[to] - dep[l]){\n\
    \            return jump_to_root(to,dep[to]-dep[l]-d);\n        }\n        return\
    \ -1;\n    }\n    vector<int> path(int from, int to){\n        int l = lca(from,to);\n\
    \        int nf = from, nt = to;\n        vector<int> pf = {from}, pt = {to};\n\
    \        while (nf != l){\n            nf = par[0][nf];\n            pf.emplace_back(nf);\n\
    \        }\n        while (nt != l){\n            nt = par[0][nt];\n         \
    \   pt.emplace_back(nt);\n        }\n        for (int i = pt.size()-2; i >= 0;\
    \ i--) pf.emplace_back(pt[i]);\n        return pf;\n    }\n    int dist(int u,\
    \ int v){ return dep[u] + dep[v] - 2 * dep[lca(u,v)]; }\n    pair<int,pair<int,int>>\
    \ diameter(){\n        int ma1 = -1, p1 = -1;\n        rep(i,n) if (chmax(ma1,dep[i]))\
    \ p1 = i;\n        queue<int> que;\n        que.push(p1);\n        vector<int>\
    \ dist_from_p1(n,iinf);\n        dist_from_p1[p1] = 0;\n        int ma2 = 0, p2\
    \ = p1;\n        while (!que.empty()){\n            int p = que.front(); que.pop();\n\
    \            for (int q : es[p]){\n                if (chmin(dist_from_p1[q],dist_from_p1[p]+1)){\n\
    \                    que.push(q);\n                    if (chmax(ma2,dist_from_p1[q]))\
    \ p2 = q;\n                }\n            }\n        }\n        return make_pair(ma2,make_pair(p1,p2));\n\
    \    }\n    void build(){\n        par.clear();\n        dep.clear();\n      \
    \  sub.clear();\n        p2size = 1;\n        int _ni = 1; // _ni = 2^(p2size\
    \ - 1), n-1 <= 2^(p2size - 1) must be holded\n        while (_ni < n-1) p2size++,\
    \ _ni <<= 1;\n        par.resize(p2size,vector<int>(n,-1));\n        dep.resize(n,-1);\n\
    \        sub.resize(n,-1);\n        queue<int> que;\n        que.push(root);\n\
    \        dep[root] = 0;\n        while (!que.empty()){\n            int p = que.front();\
    \ que.pop();\n            for (int to : es[p]){\n                if (dep[to] ==\
    \ -1){\n                    par[0][to] = p;\n                    dep[to] = dep[p]\
    \ + 1;\n                    que.push(to);\n                }\n            }\n\
    \        }\n        for (int i = 1; i < p2size; i++){\n            for (int v\
    \ = 0; v < n; v++){\n                if (par[i-1][v] == -1) continue;\n      \
    \          par[i][v] = par[i-1][par[i-1][v]];\n            }\n        }\n    }\n\
    \  private:\n    int n, root;\n    vector<vector<int>> es;\n    int p2size;\n\
    \    vector<vector<int>> par;\n    vector<int> dep, sub;\n};\n\n} // namespace\
    \ noya2\n#line 5 \"test/tree/Lowest_Common_Ancestor.test.cpp\"\n\nint main(){\n\
    \    int n, q; in(n,q);\n    usefulTree g(n);\n    rep(i,n-1){\n        int p;\
    \ in(p);\n        g.add_edge(i+1,p);\n    }\n    g.build();\n    while (q--){\n\
    \        int u, v; in(u,v);\n        out(g.lca(u,v));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include\"../../template/template.hpp\"\
    \n#include\"../../tree/Tree_core.hpp\"\n\nint main(){\n    int n, q; in(n,q);\n\
    \    usefulTree g(n);\n    rep(i,n-1){\n        int p; in(p);\n        g.add_edge(i+1,p);\n\
    \    }\n    g.build();\n    while (q--){\n        int u, v; in(u,v);\n       \
    \ out(g.lca(u,v));\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - tree/Tree_core.hpp
  isVerificationFile: true
  path: test/tree/Lowest_Common_Ancestor.test.cpp
  requiredBy: []
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Lowest_Common_Ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Lowest_Common_Ancestor.test.cpp
- /verify/test/tree/Lowest_Common_Ancestor.test.cpp.html
title: test/tree/Lowest_Common_Ancestor.test.cpp
---
