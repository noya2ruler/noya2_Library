---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Graph_core.hpp
    title: graph/Graph_core.hpp
  - icon: ':heavy_check_mark:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/graph/Shortest_Path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout.hpp\"\
    \nnamespace noya2 {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p){\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<vector<T>> &vv){\n    int\
    \ s = (int)vv.size();\n    for (int i = 0; i < s; i++) os << (i ? \"\\n\" : \"\
    \") << vv[i];\n    return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v){\n    int s = (int)v.size();\n    for (int i = 0; i\
    \ < s; i++) os << (i ? \" \" : \"\") << v[i];\n    return os;\n}\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (auto &x : v) is\
    \ >> x;\n    return is;\n}\n\nvoid in() {}\ntemplate <typename T, class... U>\n\
    void in(T &t, U &...u){\n    cin >> t;\n    in(u...);\n}\n\nvoid out() { cout\
    \ << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\nvoid out(const\
    \ T &t, const U &...u){\n    cout << t;\n    if (sizeof...(u)) cout << sep;\n\
    \    out(u...);\n}\n\nstruct IoSetup {\n    IoSetup(){\n        cin.tie(nullptr);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(15);\n\
    \        cerr << fixed << setprecision(7);\n    }\n} iosetup_noya2;\n\n} // namespace\
    \ noya2\n#line 1 \"template/const.hpp\"\nnamespace noya2{\n\nconst int iinf =\
    \ 1'000'000'007;\nconst long long linf = 2'000'000'000'000'000'000LL;\nconst long\
    \ long mod998 =  998244353;\nconst long long mod107 = 1000000007;\nconst long\
    \ double pi = 3.14159265358979323;\nconst vector<int> dx = {0,1,0,-1,1,1,-1,-1};\n\
    const vector<int> dy = {1,0,-1,0,1,-1,-1,1};\nconst string ALP = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ;\nconst string alp = \"abcdefghijklmnopqrstuvwxyz\";\nconst string NUM = \"0123456789\"\
    ;\n\nvoid yes(){ cout << \"Yes\\n\"; }\nvoid no(){ cout << \"No\\n\"; }\nvoid\
    \ YES(){ cout << \"YES\\n\"; }\nvoid NO(){ cout << \"NO\\n\"; }\nvoid yn(bool\
    \ t){ t ? yes() : no(); }\nvoid YN(bool t){ t ? YES() : NO(); }\n\n} // namespace\
    \ noya2\n#line 1 \"template/utils.hpp\"\nnamespace noya2{\n\nunsigned long long\
    \ inner_binary_gcd(unsigned long long a, unsigned long long b){\n    if (a ==\
    \ 0 || b == 0) return a + b;\n    int n = __builtin_ctzll(a);\n    int m = __builtin_ctzll(b);\n\
    \    a >>= n;\n    b >>= m;\n    while (a != b) {\n        int m = __builtin_ctzll(a\
    \ - b);\n        bool f = a > b;\n        unsigned long long c = f ? a : b;\n\
    \        b = f ? b : a;\n        a = (c - b) >> m;\n    }\n    return a << min(n,\
    \ m);\n}\n\ntemplate<typename T>\nT gcd_fast(T a, T b){\n    return static_cast<T>(inner_binary_gcd(abs(a),abs(b)));\n\
    }\n\ntemplate<typename T>\nT floor_div(const T n, const T d) {\n    assert(d !=\
    \ 0);\n    return n / d - static_cast<T>((n ^ d) < 0 && n % d != 0);\n}\n\ntemplate<typename\
    \ T>\nT ceil_div(const T n, const T d) {\n    assert(d != 0);\n    return n /\
    \ d + static_cast<T>((n ^ d) >= 0 && n % d != 0);\n}\n\ntemplate<typename T> void\
    \ uniq(vector<T> &v){\n    sort(all(v));\n    v.erase(unique(all(v)),v.end());\n\
    }\n\ntemplate <typename T, typename U>\ninline bool chmin(T &x, U y) {\n    return\
    \ (y < x) ? (x = y, true) : false;\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool chmax(T &x, U y) {\n    return (x < y) ? (x = y, true) : false;\n}\n\n\
    template<typename T>\ninline bool range(T l, T x, T r){\n    return l <= x &&\
    \ x < r;\n}\n\n} // namespace noya2\n#line 8 \"template/template.hpp\"\n\n#define\
    \ rep(i,n) for (int i = 0; i < (int)(n); i++)\n#define repp(i,m,n) for (int i\
    \ = (m); i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1); i >= 0;\
    \ i--)\n#define all(v) (v).begin(),(v).end()\n\nusing ll = long long;\nusing ld\
    \ = long double;\nusing uint = unsigned int;\nusing ull = unsigned long long;\n\
    using pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pil = pair<int,ll>;\n\
    using pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000\
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"graph/Graph_core.hpp\"\n\n#line\
    \ 4 \"graph/Graph_core.hpp\"\n\nnamespace noya2 {\n\nstruct naiveGraph { // undirected\
    \ unweighted tree\n    naiveGraph (int _n = 0) : n(_n){\n        es0.resize(n);\n\
    \        es1.resize(n);\n        _vis.resize(n,0);\n    }\n    void add_edge(int\
    \ u, int v, bool undirect = true, int id = -1){\n        es0[u].emplace_back(v);\n\
    \        es1[u].emplace_back(v,id);\n        if (undirect){\n            es0[v].emplace_back(u);\n\
    \            es1[v].emplace_back(u,id);\n        }\n    }\n    void input(int\
    \ m, int _indexed = 1, bool undirect = true){\n        rep(i,m){\n           \
    \ int u, v; in(u,v);\n            u -= _indexed;\n            v -= _indexed;\n\
    \            add_edge(u,v,undirect,i);\n        }\n    }\n    bool yet(int v){\
    \ return _vis[v] == 0; }\n    void visit(int v) { _vis[v]++; }\n    void reset(int\
    \ v = -1){ \n        if (v == -1) fill(all(_vis),0);\n        else _vis[v] = 0;\n\
    \    }\n    const vector<int>& operator[](int idx) const { return es0[idx]; }\n\
    \    const vector<pair<int,int>>& operator()(int idx) const {return es1[idx];\
    \ }\n  private:\n    int n;\n    vector<vector<int>> es0;\n    vector<vector<pair<int,int>>>\
    \ es1;\n    vector<int> _vis;\n};\n\nstruct usefulGraph { // directed weighted\
    \ graph\n    usefulGraph (int _n = 0) : n(_n){\n        es.resize(n);\n      \
    \  _vis.resize(n,0);\n    }\n    void add_edge(int u, int v, bool undirect = true,\
    \ ll cost = 1){\n        es[u].emplace_back(v,cost);\n        if (undirect){\n\
    \            es[v].emplace_back(u,cost);\n        }\n    }\n    void input(int\
    \ m, int _indexed = 1, bool undirect = true){\n        rep(i,m){\n           \
    \ int u, v; in(u,v);\n            ll cost; in(cost);\n            u -= _indexed;\n\
    \            v -= _indexed;\n            add_edge(u,v,undirect,cost);\n      \
    \  }\n    }\n    bool yet(int v){ return _vis[v] == 0; }\n    void visit(int v)\
    \ { _vis[v]++; }\n    void reset(int v = -1){ \n        if (v == -1) fill(all(_vis),0);\n\
    \        else _vis[v] = 0;\n    }\n    vector<ll> dijkstra(int s){ // all edge\
    \ weight >= 0\n        vector<ll> dist(n,linf);\n        dist[s] = 0LL;\n    \
    \    priority_queue<pli,vector<pli>,greater<pli>> pque;\n        pque.push(pli(0,s));\n\
    \        while (!pque.empty()){\n            auto [d, f] = pque.top(); pque.pop();\n\
    \            if (dist[f] < d) continue;\n            for (auto [t, cost] : es[f]){\n\
    \                if (chmin(dist[t],d+cost)){\n                    pque.push(pli(dist[t],t));\n\
    \                }\n            }\n        }\n        return dist;\n    }\n  \
    \  vector<int> reconstruct(int s, int t, const vector<ll> &dist){\n        if\
    \ (dist[t] == linf) return {};\n        vector<int> froms(n,-1);\n        queue<int>\
    \ que;\n        que.push(s);\n        froms[s] = s;\n        while (!que.empty()){\n\
    \            int v = que.front(); que.pop();\n            for (auto [u, cost]\
    \ : es[v]){\n                if (froms[u] == -1 && dist[v] + cost == dist[u]){\n\
    \                    froms[u] = v;\n                    que.push(u);\n       \
    \         }\n            }\n        }\n        vector<int> ans = {t};\n      \
    \  while (t != s){\n            t = froms[t];\n            ans.emplace_back(t);\n\
    \        }\n        reverse(all(ans));\n        return ans;\n    }\n    vector<ll>\
    \ bfs01(int s){ // all edge weight = 0 or 1\n        vector<ll> dist(n,linf);\n\
    \        dist[s] = 0;\n        deque<int> que;\n        que.push_back(s);\n  \
    \      while (!que.empty()){\n            auto f = que.front(); que.pop_front();\n\
    \            for (auto [t, cost] : es[f]){\n                if (chmin(dist[t],dist[f]+cost)){\n\
    \                    if (cost == 0) que.push_front(t);\n                    else\
    \ que.push_back(t);\n                }\n            }\n        }\n        return\
    \ dist;\n    }\n    vector<ll> bellman_ford(int s, bool &ng_cycle){\n        vector<ll>\
    \ dist(n,linf);\n        vector<int> ng;\n        dist[s] = 0;\n        int tm\
    \ = 0;\n        while (tm < n){\n            bool finish = true;\n           \
    \ for (int f = 0; f < n; f++){\n                if (dist[f] == linf) continue;\n\
    \                for (auto [t, cost] : es[f]){\n                    if (chmin(dist[t],dist[f]+cost)){\n\
    \                        finish = false;\n                        if (tm == n-1)\
    \ ng.emplace_back(t);\n                    }\n                }\n            }\n\
    \            if (finish) break;\n            tm++;\n        }\n        ng_cycle\
    \ = (tm == n);\n        if (ng_cycle){\n            for (auto v : ng) dist[v]\
    \ = -linf;\n            tm = n;\n            while (tm--){\n                for\
    \ (int f = 0; f < n; f++){\n                    if (dist[f] != -linf) continue;\n\
    \                    for (auto e : es[f]){\n                        dist[e.first]\
    \ = -linf;\n                    }\n                }\n            }\n        }\n\
    \        return dist;\n    }\n    vector<vector<ll>> warshall_floyd(){\n     \
    \   vector<vector<ll>> res(n,vector<ll>(n,linf));\n        rep(i,n){\n       \
    \     res[i][i] = 0;\n            for (auto [t, cost] : es[i]){\n            \
    \    chmin(res[i][t],cost);\n            }\n        }\n        rep(k,n) rep(i,n)\
    \ rep(j,n){\n            chmin(res[i][j],res[i][k]+res[k][j]);\n        }\n  \
    \      return res;\n    }\n    const vector<pair<int,ll>>& operator[](int idx)\
    \ const { return es[idx]; }\n  private:\n    int n;\n    vector<vector<pair<int,ll>>>\
    \ es;\n    vector<int> _vis;\n};\n\n} // namespace noya2\n#line 5 \"test/graph/Shortest_Path.test.cpp\"\
    \n\nint main(){\n    int n, m, s, t; in(n,m,s,t);\n    usefulGraph g(n);\n   \
    \ g.input(m,0,false);\n    auto dist = g.dijkstra(s);\n    if (dist[t] == linf){\n\
    \        out(-1);\n        return 0;\n    }\n    auto ans = g.reconstruct(s,t,dist);\n\
    \    out(dist[t],ans.size()-1);\n    rep(i,ans.size()-1) out(ans[i],ans[i+1]);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\"\
    template/template.hpp\"\n#include\"graph/Graph_core.hpp\"\n\nint main(){\n   \
    \ int n, m, s, t; in(n,m,s,t);\n    usefulGraph g(n);\n    g.input(m,0,false);\n\
    \    auto dist = g.dijkstra(s);\n    if (dist[t] == linf){\n        out(-1);\n\
    \        return 0;\n    }\n    auto ans = g.reconstruct(s,t,dist);\n    out(dist[t],ans.size()-1);\n\
    \    rep(i,ans.size()-1) out(ans[i],ans[i+1]);\n}"
  dependsOn:
  - template/template.hpp
  - template/inout.hpp
  - template/const.hpp
  - template/utils.hpp
  - graph/Graph_core.hpp
  isVerificationFile: true
  path: test/graph/Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2023-07-23 15:58:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Shortest_Path.test.cpp
- /verify/test/graph/Shortest_Path.test.cpp.html
title: test/graph/Shortest_Path.test.cpp
---
