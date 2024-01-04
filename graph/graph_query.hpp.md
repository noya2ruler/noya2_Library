---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph_query.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/csr.hpp\"\
    \n\n#line 4 \"data_structure/csr.hpp\"\n#include<ranges>\n#line 7 \"data_structure/csr.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<class E>\nstruct csr {\n    csr (int n_ = 0,\
    \ int m_ = -1) : n(n_), m(m_) {\n        if (m >= 0){\n            es.reserve(m);\n\
    \            start.reserve(m);\n        }\n        if (m == 0){\n            build();\n\
    \        }\n    }\n    int add(int idx, E elem){\n        int eid = start.size();\n\
    \        es.emplace_back(elem);\n        start.emplace_back(idx);\n        if\
    \ (eid+1 == m) build();\n        return eid;\n    }\n    void build(){\n     \
    \   if (m == -2) return ;\n        m = start.size();\n        std::vector<E> nes(m);\n\
    \        std::vector<int> nstart(n+2,0);\n        for (int i = 0; i < m; i++)\
    \ nstart[start[i]+2]++;\n        for (int i = 1; i < n; i++) nstart[i+2] += nstart[i+1];\n\
    \        for (int i = 0; i < m; i++) nes[nstart[start[i]+1]++] = es[i];\n    \
    \    swap(es,nes);\n        swap(start,nstart);\n        m = -2;\n    }\n    const\
    \ auto operator[](int idx) const {\n        assert(m == -2);\n        return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\n\
    \    }\n  private:\n    int n, m;\n    std::vector<E> es;\n    std::vector<int>\
    \ start;\n};\n\n} // namespace noya2\n#line 5 \"graph/graph_query.hpp\"\n\nnamespace\
    \ noya2 {\n\ntemplate<typename Cost>\nstruct Graph {\n    int n;\n    csr<pair<int,Cost>>\
    \ g;\n    Cost dist_inf;\n    Graph (int n_ = 0, int m_ = -1) : n(n_), g(n_,m_)\
    \ {\n        dist_inf = numeric_limits<Cost>::max() / 2;\n    }\n    int add_edge(int\
    \ u, int v, Cost cost = 1){\n        return g.add(u,pair<int,Cost>(v,cost));\n\
    \    }\n    void build(){\n        g.build();\n    }\n    void set_inf(Cost new_inf){\n\
    \        dist_inf = new_inf;\n    }\n    vector<Cost> dijkstra(int s){\n     \
    \   vector<Cost> dist(n,dist_inf);\n        dist[s] = 0;\n        using P = pair<Cost,int>;\n\
    \        priority_queue<P,vector<P>,greater<P>> pque;\n        pque.push(P(0,s));\n\
    \        while (!pque.empty()){\n            auto [d, v] = pque.top(); pque.pop();\n\
    \            if (dist[v] < d) continue;\n            for (auto [u, c] : g[v]){\n\
    \                if (chmin(dist[u],d+c)){\n                    pque.push(P(dist[u],u));\n\
    \                }\n            }\n        }\n        return dist;\n    }\n  \
    \  vector<int> reconstruct(int s, int t, const vector<Cost> &dist){\n        if\
    \ (dist[t] == linf) return {};\n        vector<int> from(n,-1);\n        queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()){\n            int v\
    \ = que.front(); que.pop();\n            for (auto [u, c] : g[v]){\n         \
    \       if (from[u] == -1 && dist[u] == dist[v] + c){\n                    from[u]\
    \ = v;\n                    que.push(u);\n                }\n            }\n \
    \       }\n        vector<int> ans = {t};\n        while (t != s){\n         \
    \   t = from[t];\n            ans.emplace_back(t);\n        }\n        reverse(all(ans));\n\
    \        return ans;\n    }\n    vector<Cost> bfs01(int s){\n        vector<Cost>\
    \ dist(n,iinf);\n        dist[s] = 0;\n        deque<int> que;\n        que.push_back(s);\n\
    \        while (!que.empty()){\n            int v = que.front(); que.pop_front();\n\
    \            for (auto [u, c] : g[v]){\n                if (chmin(dist[u],dist[v]+c)){\n\
    \                    if (c == 0) que.push_front(u);\n                    else\
    \ que.push_back(u);\n                }\n            }\n        }\n        return\
    \ dist;\n    }\n    vector<Cost> bellman_ford(int s, bool &ng_cycle){\n      \
    \  vector<Cost> dist(n,dist_inf);\n        vector<int> ng;\n        dist[s] =\
    \ 0;\n        int tm = 0;\n        while (tm < n){\n            bool finish =\
    \ true;\n            for (int v = 0; v < n; v++){\n                if (dist[v]\
    \ == dist_inf) continue;\n                for (auto [u, c] : g[v]){\n        \
    \            if (chmin(dist[u],dist[v]+c)){\n                        finish =\
    \ false;\n                        if (tm == n-1) ng.emplace_back(u);\n       \
    \             }\n                }\n            }\n            if (finish) break;\n\
    \            tm++;\n        }\n        ng_cycle = (tm == n);\n        if (ng_cycle){\n\
    \            for (auto v : ng) dist[v] = -dist_inf;\n            tm = n;\n   \
    \         while (tm--){\n                for (int v = 0; v < n; v++){\n      \
    \              if (dist[v] != -dist_inf) continue;\n                    for (auto\
    \ [u, c] : g[v]){\n                        dist[u] = -dist_inf;\n            \
    \        }\n                }\n            }\n        }\n        return dist;\n\
    \    }\n    vector<vector<Cost>> warshall_floyd(){\n        vector<vector<Cost>>\
    \ dist(n,vector<Cost>(n,dist_inf));\n        rep(v,n){\n            dist[v][v]\
    \ = 0;\n            for (auto [u, c] : g[v]){\n                chmin(dist[v][u],c);\n\
    \            }\n        }\n        rep(k,n) rep(i,n) rep(j,n){\n            chmin(dist[i][j],dist[i][k]+dist[k][j]);\n\
    \        }\n        return dist;\n    }\n    const auto operator[](int idx) const\
    \ { return g[idx]; }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../data_structure/csr.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<typename Cost>\nstruct Graph {\n    int n;\n\
    \    csr<pair<int,Cost>> g;\n    Cost dist_inf;\n    Graph (int n_ = 0, int m_\
    \ = -1) : n(n_), g(n_,m_) {\n        dist_inf = numeric_limits<Cost>::max() /\
    \ 2;\n    }\n    int add_edge(int u, int v, Cost cost = 1){\n        return g.add(u,pair<int,Cost>(v,cost));\n\
    \    }\n    void build(){\n        g.build();\n    }\n    void set_inf(Cost new_inf){\n\
    \        dist_inf = new_inf;\n    }\n    vector<Cost> dijkstra(int s){\n     \
    \   vector<Cost> dist(n,dist_inf);\n        dist[s] = 0;\n        using P = pair<Cost,int>;\n\
    \        priority_queue<P,vector<P>,greater<P>> pque;\n        pque.push(P(0,s));\n\
    \        while (!pque.empty()){\n            auto [d, v] = pque.top(); pque.pop();\n\
    \            if (dist[v] < d) continue;\n            for (auto [u, c] : g[v]){\n\
    \                if (chmin(dist[u],d+c)){\n                    pque.push(P(dist[u],u));\n\
    \                }\n            }\n        }\n        return dist;\n    }\n  \
    \  vector<int> reconstruct(int s, int t, const vector<Cost> &dist){\n        if\
    \ (dist[t] == linf) return {};\n        vector<int> from(n,-1);\n        queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()){\n            int v\
    \ = que.front(); que.pop();\n            for (auto [u, c] : g[v]){\n         \
    \       if (from[u] == -1 && dist[u] == dist[v] + c){\n                    from[u]\
    \ = v;\n                    que.push(u);\n                }\n            }\n \
    \       }\n        vector<int> ans = {t};\n        while (t != s){\n         \
    \   t = from[t];\n            ans.emplace_back(t);\n        }\n        reverse(all(ans));\n\
    \        return ans;\n    }\n    vector<Cost> bfs01(int s){\n        vector<Cost>\
    \ dist(n,iinf);\n        dist[s] = 0;\n        deque<int> que;\n        que.push_back(s);\n\
    \        while (!que.empty()){\n            int v = que.front(); que.pop_front();\n\
    \            for (auto [u, c] : g[v]){\n                if (chmin(dist[u],dist[v]+c)){\n\
    \                    if (c == 0) que.push_front(u);\n                    else\
    \ que.push_back(u);\n                }\n            }\n        }\n        return\
    \ dist;\n    }\n    vector<Cost> bellman_ford(int s, bool &ng_cycle){\n      \
    \  vector<Cost> dist(n,dist_inf);\n        vector<int> ng;\n        dist[s] =\
    \ 0;\n        int tm = 0;\n        while (tm < n){\n            bool finish =\
    \ true;\n            for (int v = 0; v < n; v++){\n                if (dist[v]\
    \ == dist_inf) continue;\n                for (auto [u, c] : g[v]){\n        \
    \            if (chmin(dist[u],dist[v]+c)){\n                        finish =\
    \ false;\n                        if (tm == n-1) ng.emplace_back(u);\n       \
    \             }\n                }\n            }\n            if (finish) break;\n\
    \            tm++;\n        }\n        ng_cycle = (tm == n);\n        if (ng_cycle){\n\
    \            for (auto v : ng) dist[v] = -dist_inf;\n            tm = n;\n   \
    \         while (tm--){\n                for (int v = 0; v < n; v++){\n      \
    \              if (dist[v] != -dist_inf) continue;\n                    for (auto\
    \ [u, c] : g[v]){\n                        dist[u] = -dist_inf;\n            \
    \        }\n                }\n            }\n        }\n        return dist;\n\
    \    }\n    vector<vector<Cost>> warshall_floyd(){\n        vector<vector<Cost>>\
    \ dist(n,vector<Cost>(n,dist_inf));\n        rep(v,n){\n            dist[v][v]\
    \ = 0;\n            for (auto [u, c] : g[v]){\n                chmin(dist[v][u],c);\n\
    \            }\n        }\n        rep(k,n) rep(i,n) rep(j,n){\n            chmin(dist[i][j],dist[i][k]+dist[k][j]);\n\
    \        }\n        return dist;\n    }\n    const auto operator[](int idx) const\
    \ { return g[idx]; }\n};\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/csr.hpp
  isVerificationFile: false
  path: graph/graph_query.hpp
  requiredBy: []
  timestamp: '2024-01-04 13:41:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_query.hpp
layout: document
redirect_from:
- /library/graph/graph_query.hpp
- /library/graph/graph_query.hpp.html
title: graph/graph_query.hpp
---