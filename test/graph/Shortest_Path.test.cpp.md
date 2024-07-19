---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph_query.hpp
    title: graph/graph_query.hpp
  - icon: ':heavy_check_mark:'
    path: graph/unweighted_type.hpp
    title: graph/unweighted_type.hpp
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/graph/Shortest_Path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"graph/graph_query.hpp\"\n\n#line\
    \ 2 \"data_structure/csr.hpp\"\n\n#line 4 \"data_structure/csr.hpp\"\n#include<ranges>\n\
    #line 7 \"data_structure/csr.hpp\"\n\nnamespace noya2::internal {\n\ntemplate<class\
    \ E>\nstruct csr {\n    csr () {}\n    csr (int _n) : n(_n) {}\n    csr (int _n,\
    \ int m) : n(_n){\n        start.reserve(m);\n        elist.reserve(m);\n    }\n\
    \    // ACL style constructor (do not have to call build)\n    csr (int _n, const\
    \ std::vector<std::pair<int,E>> &idx_elem) : n(_n), start(_n + 2), elist(idx_elem.size())\
    \ {\n        for (auto &[i, e] : idx_elem){\n            start[i + 2]++;\n   \
    \     }\n        for (int i = 1; i < n; i++){\n            start[i + 2] += start[i\
    \ + 1];\n        }\n        for (auto &[i, e] : idx_elem){\n            elist[start[i\
    \ + 1]++] = e;\n        }\n        prepared = true;\n    }\n    int add(int idx,\
    \ E elem){\n        int eid = start.size();\n        start.emplace_back(idx);\n\
    \        elist.emplace_back(elem);\n        return eid;\n    }\n    void build(){\n\
    \        if (prepared) return ;\n        int m = start.size();\n        std::vector<E>\
    \ nelist(m);\n        std::vector<int> nstart(n + 2, 0);\n        for (int i =\
    \ 0; i < m; i++){\n            nstart[start[i] + 2]++;\n        }\n        for\
    \ (int i = 1; i < n; i++){\n            nstart[i + 2] += nstart[i + 1];\n    \
    \    }\n        for (int i = 0; i < m; i++){\n            nelist[nstart[start[i]\
    \ + 1]++] = elist[i];\n        }\n        swap(elist,nelist);\n        swap(start,nstart);\n\
    \        prepared = true;\n    }\n    const auto operator[](int idx) const {\n\
    \        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    auto operator[](int idx){\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    const auto operator()(int idx, int l, int r) const {\n        return\
    \ std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    auto operator()(int idx, int l, int r){\n        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    int n;\n    std::vector<int> start;\n    std::vector<E> elist;\n \
    \   bool prepared = false;\n};\n\n} // namespace noya2::internal\n#line 2 \"graph/unweighted_type.hpp\"\
    \n\nnamespace noya2 {\n\nstruct unweighted {};\n\n} // namespace noya2\n#line\
    \ 6 \"graph/graph_query.hpp\"\n\n#line 12 \"graph/graph_query.hpp\"\n\nnamespace\
    \ noya2 {\n\ntemplate<typename Cost>\nstruct graph {\n    int n;\n    internal::csr<std::pair<int,Cost>>\
    \ g;\n    Cost dist_inf = std::numeric_limits<Cost>::max() / 2;\n    graph (int\
    \ _n = 0) : n(_n), g(_n) {}\n    graph (int _n, int _m) : n(_n), g(_n,_m) {}\n\
    \    // \u6709\u5411\u8FBA\u3092\u8FFD\u52A0 (\u7121\u5411\u8FBA\u3067\u306F\u306A\
    \u3044\u3053\u3068\u306B\u6CE8\u610F\uFF01)\n    int add_edge(int u, int v, Cost\
    \ cost = 1){\n        int id = g.add(u, {v,cost});\n        return id;\n    }\n\
    \    template<bool directed>\n    static graph input(int _n, int _m, int indexed\
    \ = 1){\n        if constexpr (directed){\n            graph g(_n, _m*2);\n  \
    \          for (int i = 0; i < _m; i++){\n                int u, v; std::cin >>\
    \ u >> v;\n                u -= indexed, v -= indexed;\n                Cost c;\
    \ std::cin >> c;\n                g.add_edge(u, v, c);\n                g.add_edge(v,\
    \ u, c);\n            }\n            g.build();\n            return g;\n     \
    \   }\n        else {\n            graph g(_n, _m);\n            for (int i =\
    \ 0; i < _m; i++){\n                int u, v; std::cin >> u >> v;\n          \
    \      u -= indexed, v -= indexed;\n                Cost c; std::cin >> c;\n \
    \               g.add_edge(u, v, c);\n            }\n            g.build();\n\
    \            return g;\n        }\n    }\n    void build(){\n        g.build();\n\
    \    }\n    void set_inf(Cost new_inf){\n        dist_inf = new_inf;\n    }\n\
    \    std::vector<Cost> dijkstra(int s){\n        g.build();\n        std::vector<Cost>\
    \ dist(n,dist_inf);\n        dist[s] = 0;\n        using P = std::pair<Cost,int>;\n\
    \        std::priority_queue<P,std::vector<P>,std::greater<P>> pque;\n       \
    \ pque.push(P(0,s));\n        while (!pque.empty()){\n            auto [d, v]\
    \ = pque.top(); pque.pop();\n            if (dist[v] < d) continue;\n        \
    \    for (auto [u, c] : g[v]){\n                if (chmin(dist[u],d+c)){\n   \
    \                 pque.push(P(dist[u],u));\n                }\n            }\n\
    \        }\n        return dist;\n    }\n    std::vector<int> reconstruct(int\
    \ s, int t, const std::vector<Cost> &dist){\n        if (dist[t] == dist_inf)\
    \ return {};\n        g.build();\n        std::vector<int> from(n,-1);\n     \
    \   std::queue<int> que;\n        que.push(s);\n        while (!que.empty()){\n\
    \            int v = que.front(); que.pop();\n            for (auto [u, c] : g[v]){\n\
    \                if (from[u] == -1 && dist[u] == dist[v] + c){\n             \
    \       from[u] = v;\n                    que.push(u);\n                }\n  \
    \          }\n        }\n        std::vector<int> ans = {t};\n        while (t\
    \ != s){\n            t = from[t];\n            ans.emplace_back(t);\n       \
    \ }\n        std::reverse(ans.begin(),ans.end());\n        return ans;\n    }\n\
    \    std::vector<Cost> bfs01(int s){\n        g.build();\n        std::vector<Cost>\
    \ dist(n,dist_inf);\n        dist[s] = 0;\n        std::deque<int> que;\n    \
    \    que.push_back(s);\n        while (!que.empty()){\n            int v = que.front();\
    \ que.pop_front();\n            for (auto [u, c] : g[v]){\n                if\
    \ (chmin(dist[u],dist[v]+c)){\n                    if (c == 0) que.push_front(u);\n\
    \                    else que.push_back(u);\n                }\n            }\n\
    \        }\n        return dist;\n    }\n    std::vector<Cost> bfs1(int s){\n\
    \        g.build();\n        std::vector<Cost> dist(n,dist_inf);\n        dist[s]\
    \ = 0;\n        std::queue<int> que;\n        que.push(s);\n        while (!que.empty()){\n\
    \            int v = que.front(); que.pop();\n            for (auto [u, c] : g[v]){\n\
    \                if (chmin(dist[u],dist[v]+c)){\n                    que.push(u);\n\
    \                }\n            }\n        }\n        return dist;\n    }\n  \
    \  std::vector<Cost> bellman_ford(int s, bool &ng_cycle){\n        g.build();\n\
    \        std::vector<Cost> dist(n,dist_inf);\n        std::vector<int> ng;\n \
    \       dist[s] = 0;\n        int tm = 0;\n        while (tm < n){\n         \
    \   bool finish = true;\n            for (int v = 0; v < n; v++){\n          \
    \      if (dist[v] == dist_inf) continue;\n                for (auto [u, c] :\
    \ g[v]){\n                    if (chmin(dist[u],dist[v]+c)){\n               \
    \         finish = false;\n                        if (tm == n-1) ng.emplace_back(u);\n\
    \                    }\n                }\n            }\n            if (finish)\
    \ break;\n            tm++;\n        }\n        ng_cycle = (tm == n);\n      \
    \  if (ng_cycle){\n            for (auto v : ng) dist[v] = -dist_inf;\n      \
    \      tm = n;\n            while (tm--){\n                for (int v = 0; v <\
    \ n; v++){\n                    if (dist[v] != -dist_inf) continue;\n        \
    \            for (auto [u, c] : g[v]){\n                        dist[u] = -dist_inf;\n\
    \                    }\n                }\n            }\n        }\n        return\
    \ dist;\n    }\n    std::vector<std::vector<Cost>> warshall_floyd(){\n       \
    \ g.build();\n        std::vector<std::vector<Cost>> dist(n,std::vector<Cost>(n,dist_inf));\n\
    \        for (int v = 0; v < n; v++){\n            dist[v][v] = 0;\n         \
    \   for (auto [u, c] : g[v]){\n                chmin(dist[v][u],c);\n        \
    \    }\n        }\n        for (int k = 0; k < n; k++){\n            for (int\
    \ i = 0; i < n; i++){\n                for (int j = 0; j < n; j++){\n        \
    \            chmin(dist[i][j],dist[i][k]+dist[k][j]);\n                }\n   \
    \         }\n        }\n        return dist;\n    }\n    const auto operator[](int\
    \ idx) const { return g[idx]; }\n    auto operator[](int idx) { return g[idx];\
    \ }\n};\n\n\ntemplate<>\nstruct graph<unweighted> {\n    int n;\n    internal::csr<int>\
    \ g;\n    int dist_inf = std::numeric_limits<int>::max() / 2;\n    graph (int\
    \ _n = 0) : n(_n), g(_n) {}\n    graph (int _n, int _m) : n(_n), g(_n,_m) {}\n\
    \    // \u6709\u5411\u8FBA\u3092\u8FFD\u52A0 (\u7121\u5411\u8FBA\u3067\u306F\u306A\
    \u3044\u3053\u3068\u306B\u6CE8\u610F\uFF01)\n    int add_edge(int u, int v){\n\
    \        int id = g.add(u, v);\n        return id;\n    }\n    template<bool directed>\n\
    \    static graph input(int _n, int _m, int indexed = 1){\n        if constexpr\
    \ (directed){\n            graph g(_n, _m*2);\n            for (int i = 0; i <\
    \ _m; i++){\n                int u, v; std::cin >> u >> v;\n                u\
    \ -= indexed, v -= indexed;\n                g.add_edge(u, v);\n             \
    \   g.add_edge(v, u);\n            }\n            g.build();\n            return\
    \ g;\n        }\n        else {\n            graph g(_n, _m);\n            for\
    \ (int i = 0; i < _m; i++){\n                int u, v; std::cin >> u >> v;\n \
    \               u -= indexed, v -= indexed;\n                g.add_edge(u, v);\n\
    \            }\n            g.build();\n            return g;\n        }\n   \
    \ }\n    void build(){\n        g.build();\n    }\n    void set_inf(int new_inf){\n\
    \        dist_inf = new_inf;\n    }\n    std::vector<int> reconstruct(int s, int\
    \ t, const std::vector<int> &dist){\n        if (dist[t] == dist_inf) return {};\n\
    \        g.build();\n        std::vector<int> from(n,-1);\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()){\n            int v\
    \ = que.front(); que.pop();\n            for (auto u : g[v]){\n              \
    \  if (from[u] == -1 && dist[u] == dist[v] + 1){\n                    from[u]\
    \ = v;\n                    que.push(u);\n                }\n            }\n \
    \       }\n        std::vector<int> ans = {t};\n        while (t != s){\n    \
    \        t = from[t];\n            ans.emplace_back(t);\n        }\n        std::reverse(ans.begin(),ans.end());\n\
    \        return ans;\n    }\n    std::vector<int> bfs(int s){\n        g.build();\n\
    \        std::vector<int> dist(n,dist_inf);\n        dist[s] = 0;\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()){\n            int v\
    \ = que.front(); que.pop();\n            for (auto u : g[v]){\n              \
    \  if (chmin(dist[u],dist[v]+1)){\n                    que.push(u);\n        \
    \        }\n            }\n        }\n        return dist;\n    }\n    const auto\
    \ operator[](int idx) const { return g[idx]; }\n    auto operator[](int idx) {\
    \ return g[idx]; }\n};\n\ntemplate<>\nstruct graph<bool> {\n    int n;\n    internal::csr<std::pair<int,bool>>\
    \ g;\n    int dist_inf = std::numeric_limits<int>::max() / 2;\n    graph (int\
    \ _n = 0) : n(_n), g(_n) {}\n    graph (int _n, int _m) : n(_n), g(_n,_m) {}\n\
    \    // \u6709\u5411\u8FBA\u3092\u8FFD\u52A0 (\u7121\u5411\u8FBA\u3067\u306F\u306A\
    \u3044\u3053\u3068\u306B\u6CE8\u610F\uFF01)\n    int add_edge(int u, int v, bool\
    \ cost){\n        int id = g.add(u, {v, cost});\n        return id;\n    }\n \
    \   void build(){\n        g.build();\n    }\n    void set_inf(int new_inf){\n\
    \        dist_inf = new_inf;\n    }\n    std::vector<int> reconstruct(int s, int\
    \ t, const std::vector<int> &dist){\n        if (dist[t] == dist_inf) return {};\n\
    \        g.build();\n        std::vector<int> from(n,-1);\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()){\n            int v\
    \ = que.front(); que.pop();\n            for (auto [u, b] : g[v]){\n         \
    \       int c = (int)b;\n                if (from[u] == -1 && dist[u] == dist[v]\
    \ + c){\n                    from[u] = v;\n                    que.push(u);\n\
    \                }\n            }\n        }\n        std::vector<int> ans = {t};\n\
    \        while (t != s){\n            t = from[t];\n            ans.emplace_back(t);\n\
    \        }\n        std::reverse(ans.begin(),ans.end());\n        return ans;\n\
    \    }\n    std::vector<int> bfs01(int s){\n        g.build();\n        std::vector<int>\
    \ dist(n,dist_inf);\n        dist[s] = 0;\n        std::deque<int> que;\n    \
    \    que.push_back(s);\n        while (!que.empty()){\n            int v = que.front();\
    \ que.pop_front();\n            for (auto [u, b] : g[v]){\n                int\
    \ c = (int)b;\n                if (chmin(dist[u],dist[v]+c)){\n              \
    \      if (c == 0) que.push_front(u);\n                    else que.push_back(u);\n\
    \                }\n            }\n        }\n        return dist;\n    }\n  \
    \  const auto operator[](int idx) const { return g[idx]; }\n    auto operator[](int\
    \ idx) { return g[idx]; }\n};\n\n} // namespace noya2\n#line 5 \"test/graph/Shortest_Path.test.cpp\"\
    \n\nint main(){\n    int n, m, s, t; in(n,m,s,t);\n    auto g = graph<ll>::input<false>(n,\
    \ m, 0);\n    auto dist = g.dijkstra(s);\n    if (dist[t] == g.dist_inf){\n  \
    \      out(-1);\n        return 0;\n    }\n    auto ans = g.reconstruct(s,t,dist);\n\
    \    out(dist[t],ans.size()-1);\n    rep(i,ans.size()-1) out(ans[i],ans[i+1]);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\"\
    template/template.hpp\"\n#include\"graph/graph_query.hpp\"\n\nint main(){\n  \
    \  int n, m, s, t; in(n,m,s,t);\n    auto g = graph<ll>::input<false>(n, m, 0);\n\
    \    auto dist = g.dijkstra(s);\n    if (dist[t] == g.dist_inf){\n        out(-1);\n\
    \        return 0;\n    }\n    auto ans = g.reconstruct(s,t,dist);\n    out(dist[t],ans.size()-1);\n\
    \    rep(i,ans.size()-1) out(ans[i],ans[i+1]);\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - graph/graph_query.hpp
  - data_structure/csr.hpp
  - graph/unweighted_type.hpp
  isVerificationFile: true
  path: test/graph/Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2024-07-20 01:03:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Shortest_Path.test.cpp
- /verify/test/graph/Shortest_Path.test.cpp.html
title: test/graph/Shortest_Path.test.cpp
---
