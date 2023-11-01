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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/Vertex_Add_Path_Sum.test.cpp
    title: test/tree/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace noya2 {\n\nstruct hldTree {\n    hldTree (int n_ = 0, int root_\
    \ = 0) : n(n_), root(root_), inner_edge_id(0){\n        down.resize(n);\n    \
    \    tour.resize(n);\n        if (n == 1) build();\n    }\n    void add_edge(int\
    \ u, int v){\n        down[inner_edge_id] = u;\n        tour[inner_edge_id] =\
    \ v;\n        if (++inner_edge_id == n-1) build();\n    }\n    int degree(int\
    \ v){\n        assert(0 <= v && v < n);\n        return start[v+1] - start[v];\n\
    \    }\n    int parent(int v){\n        assert(0 <= v && v < n);\n        if (v\
    \ == root) return -1;\n        return es[start[v]];\n    }\n    int subtree_size(int\
    \ v){\n        assert(0 <= v && v < n);\n        return sub[v];\n    }\n    int\
    \ depth(int v){\n        assert(0 <= v && v < n);\n        return dep[v];\n  \
    \  }\n    int la(int v, int d){\n        assert(0 <= v && v < n);\n        while\
    \ (v != -1){\n            int u = nxt[v];\n            if (down[v] - d >= down[u]){\n\
    \                v = tour[down[v] - d];\n                break;\n            }\n\
    \            d -= down[v] - down[u] + 1;\n            v = parent(u);\n       \
    \ }\n        return v;\n    }\n    int lca(int u, int v){\n        assert(0 <=\
    \ v && v < n && 0 <= u && u < n);\n        while (nxt[u] != nxt[v]){\n       \
    \     if (down[u] < down[v]) std::swap(u,v);\n            u = es[start[nxt[u]]];\n\
    \        }\n        return dep[u] < dep[v] ? u : v;\n    }\n    int jump(int from,\
    \ int to, int d){\n        int l = lca(from,to);\n        if (d <= dep[from] -\
    \ dep[l]){\n            return la(from,d);\n        }\n        d -= dep[from]\
    \ - dep[l];\n        if (d <= dep[to] - dep[l]){\n            return la(to,dep[to]-dep[l]-d);\n\
    \        }\n        return -1;\n    }\n    int dist(int u, int v){ return dep[lca(u,v)]*(-2)\
    \ + dep[u] + dep[v]; }\n    bool is_in_subtree(int r, int v){ return down[r] <\
    \ down[v] && up[v] <= up[r]; }\n    bool is_in_path(int lv, int mv, int rv){ return\
    \ dist(lv,mv) + dist(mv,rv) == dist(lv,rv); }\n    vector<int> path(int from,\
    \ int to){\n        int l = lca(from,to);\n        const int sizf = dep[from]-dep[l],\
    \ sizt = dep[to]-dep[l];\n        vector<int> pf = {from}, pt;\n        pf.reserve(sizf+1);\
    \ pt.reserve(sizt);\n        for (int i = 0; i < sizf; i++){\n            from\
    \ = parent(from);\n            pf.push_back(from);\n        }\n        for (int\
    \ i = 0; i < sizt; i++){\n            pt.push_back(to);\n            to = parent(to);\n\
    \        }\n        pf.insert(pf.end(),pt.rbegin(),pt.rend());\n        return\
    \ pf;\n    }\n    // dist, v1, v2\n    tuple<int,int,int> diameter(){\n      \
    \  int v1 = max_element(dep.begin(),dep.end()) - dep.begin();\n        vector<int>\
    \ dist_from_v1(n,numeric_limits<int>::max());\n        queue<int> que;\n     \
    \   que.push(v1);\n        dist_from_v1[v1] = 0;\n        while (!que.empty()){\n\
    \            int p = que.front(); que.pop();\n            for (int i = start[p];\
    \ i < start[p+1]; i++){\n                if (dist_from_v1[es[i]] > dist_from_v1[p]+1){\n\
    \                    dist_from_v1[es[i]] = dist_from_v1[p]+1;\n              \
    \      que.push(es[i]);\n                }\n            }\n        }\n       \
    \ int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();\n\
    \        return make_tuple(dist_from_v1[v2],v1,v2);\n    }\n    template<typename\
    \ F>\n    void path_query(int u, int v, bool vertex, const F &f){ // f is function\
    \ takes (left, right) as argument, range = [left,right).\n        int l = lca(u,v);\n\
    \        for (auto &p : ascend(u,l)){\n            int s = p.first + 1, t = p.second;\
    \ // p.first + 1 : depth(p.first) > depth(p.second), so [p.second,p.first] = [p.second,p.first+1)\n\
    \            s > t ? f(t,s) : f(s,t);\n        }\n        if (vertex) f(down[l],down[l]+1);\
    \ // vertex is true : query is for point \n        for (auto &p : descend(l,v)){\n\
    \            int s = p.first, t = p.second + 1; // p.second +1 : depth(p.first)\
    \ < depth(p.second), so [p.first,p.second] = [p.first,p.second+1)\n          \
    \  s > t ? f(t,s) : f(s,t);\n        }\n    }\n    template<typename F>\n    void\
    \ path_noncommutative_query(int u, int v, bool vertex, const F &f){ // op(l,r)\
    \ != op(r,l), so prod[u->...->v] != prod[v->...->u]\n        int l = lca(u,v);\n\
    \        for (auto &p : ascend(u,l)){\n            int s = p.first + 1, t = p.second;\
    \ // p.first + 1 : depth(p.first) > depth(p.second), so [p.second,p.first] = [p.second,p.first+1)\n\
    \            f(s,t); // le > ri ok\n        }\n        if (vertex) f(down[l],down[l]+1);\
    \ // vertex is true : query is for point \n        for (auto &p : descend(l,v)){\n\
    \            int s = p.first, t = p.second + 1; // p.second +1 : depth(p.first)\
    \ < depth(p.second), so [p.first,p.second] = [p.first,p.second+1)\n          \
    \  f(s,t); // le > ri ok\n        }\n    }\n    template<typename F>\n    void\
    \ subtree_query(int v, bool vertex, const F &f){\n        f(down[v] + (vertex\
    \ ? 0 : 1), up[v]);\n    }\n    const auto operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\
    \ }\n    const auto operator()(int idx){ return std::ranges::subrange(es.begin()+start_skip_parent(idx),es.begin()+start[idx+1]);\
    \ }\n    int set_id_v(int v) const {\n        return down[v];\n    }\n    int\
    \ set_id_e(int u, int v) const {\n        return (dep[u] < dep[v] ? down[v] :\
    \ down[u]);\n    }\n    int vertex_id(int i){\n        return tour[i];\n    }\n\
    \  private:\n    void build(){\n        es.resize((n-1)*2);\n        start.resize(n+2,0);\n\
    \        for (int i = 0; i < n-1; i++){\n            start[down[i]+2]++;\n   \
    \         start[tour[i]+2]++;\n        }\n        for (int i = 1; i <= n; i++){\n\
    \            start[i+1] += start[i];\n        }\n        for (int i = 0; i < n-1;\
    \ i++){\n            es[start[down[i]+1]++] = tour[i];\n            es[start[tour[i]+1]++]\
    \ = down[i];\n        }\n        init_bfs();\n        init_dfs();\n    }\n   \
    \ void init_bfs(){\n        dep.resize(n,numeric_limits<int>::max());\n      \
    \  up.resize(n);\n        int l = 0, r = 0;\n        auto push = [&](int x){\n\
    \            up[r++] = x;\n        };\n        auto pop_front = [&](){\n     \
    \       return up[l++];\n        };\n        dep[root] = 0;\n        push(root);\n\
    \        while (l < r){\n            int p = pop_front();\n            for (int\
    \ i = start[p]; i < start[p+1]; i++){\n                auto q = es[i];\n     \
    \           if (dep[q] > dep[p]+1){\n                    dep[q] = dep[p]+1;\n\
    \                    push(q);\n                }\n                else {\n   \
    \                 swap(es[start[p]],es[i]);\n                }\n            }\n\
    \        }\n        sub.resize(n,1);\n        for (int v : up | std::views::reverse){\n\
    \            const int stv = start_skip_parent(v);\n            for (int i = stv;\
    \ i < start[v+1]; i++){\n                sub[v] += sub[es[i]];\n             \
    \   if (sub[es[stv]] < sub[es[i]]) swap(es[stv],es[i]);\n            }\n     \
    \   }\n    }\n    void init_dfs(){\n        nxt.resize(n);\n        nxt[root]\
    \ = root;\n        int inner_clock = 0;\n        auto dfs = [&](auto sfs, int\
    \ v) -> void {\n            down[v] = inner_clock++;\n            tour[down[v]]\
    \ = v;\n            int stv = start_skip_parent(v);\n            if (stv < start[v+1]){\n\
    \                nxt[es[stv]] = nxt[v];\n                sfs(sfs,es[stv]);\n \
    \               for (int i = stv+1; i < start[v+1]; i++){\n                  \
    \  nxt[es[i]] = es[i];\n                    sfs(sfs,es[i]);\n                }\n\
    \            }\n            up[v] = inner_clock;\n        };\n        dfs(dfs,root);\n\
    \    }\n    vector<pair<int,int>> ascend(int u, int v){ // [u,v), depth[u] > depth[v]\n\
    \        vector<pair<int,int>> res;\n        while (nxt[u] != nxt[v]){\n     \
    \       res.emplace_back(down[u],down[nxt[u]]); // [s1,t1], [s2,t2], ...\n   \
    \         u = es[start[nxt[u]]]; // parent of nxt[u]\n        }\n        if (u\
    \ != v) res.emplace_back(down[u],down[v]+1); // [s,t). v is not in the range (down[]\
    \ is ordered opposite direction of depth)\n        return res;\n    }\n    vector<pair<int,int>>\
    \ descend(int u, int v){ // (u,v], depth[u] < depth[v]\n        if (u == v) return\
    \ {};\n        if (nxt[u] == nxt[v]){\n            return {pair<int,int>(down[u]+1,down[v])};\
    \ // (s,t]. u is not in the range\n        }\n        vector<pair<int,int>> res\
    \ = descend(u,es[start[nxt[v]]]); // descend(u, parent of nxt[v])\n        res.emplace_back(down[nxt[v]],down[v]);\
    \ // [s1,t1], [s2,t2], ...\n        return res;\n    }\n    int start_skip_parent(int\
    \ v) const { return start[v]+int(v != root); }\n    int n, root, inner_edge_id;\n\
    \    vector<int> es, start, dep, sub, down, up, tour, nxt;\n};\n\n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2 {\n\
    \nstruct hldTree {\n    hldTree (int n_ = 0, int root_ = 0) : n(n_), root(root_),\
    \ inner_edge_id(0){\n        down.resize(n);\n        tour.resize(n);\n      \
    \  if (n == 1) build();\n    }\n    void add_edge(int u, int v){\n        down[inner_edge_id]\
    \ = u;\n        tour[inner_edge_id] = v;\n        if (++inner_edge_id == n-1)\
    \ build();\n    }\n    int degree(int v){\n        assert(0 <= v && v < n);\n\
    \        return start[v+1] - start[v];\n    }\n    int parent(int v){\n      \
    \  assert(0 <= v && v < n);\n        if (v == root) return -1;\n        return\
    \ es[start[v]];\n    }\n    int subtree_size(int v){\n        assert(0 <= v &&\
    \ v < n);\n        return sub[v];\n    }\n    int depth(int v){\n        assert(0\
    \ <= v && v < n);\n        return dep[v];\n    }\n    int la(int v, int d){\n\
    \        assert(0 <= v && v < n);\n        while (v != -1){\n            int u\
    \ = nxt[v];\n            if (down[v] - d >= down[u]){\n                v = tour[down[v]\
    \ - d];\n                break;\n            }\n            d -= down[v] - down[u]\
    \ + 1;\n            v = parent(u);\n        }\n        return v;\n    }\n    int\
    \ lca(int u, int v){\n        assert(0 <= v && v < n && 0 <= u && u < n);\n  \
    \      while (nxt[u] != nxt[v]){\n            if (down[u] < down[v]) std::swap(u,v);\n\
    \            u = es[start[nxt[u]]];\n        }\n        return dep[u] < dep[v]\
    \ ? u : v;\n    }\n    int jump(int from, int to, int d){\n        int l = lca(from,to);\n\
    \        if (d <= dep[from] - dep[l]){\n            return la(from,d);\n     \
    \   }\n        d -= dep[from] - dep[l];\n        if (d <= dep[to] - dep[l]){\n\
    \            return la(to,dep[to]-dep[l]-d);\n        }\n        return -1;\n\
    \    }\n    int dist(int u, int v){ return dep[lca(u,v)]*(-2) + dep[u] + dep[v];\
    \ }\n    bool is_in_subtree(int r, int v){ return down[r] < down[v] && up[v] <=\
    \ up[r]; }\n    bool is_in_path(int lv, int mv, int rv){ return dist(lv,mv) +\
    \ dist(mv,rv) == dist(lv,rv); }\n    vector<int> path(int from, int to){\n   \
    \     int l = lca(from,to);\n        const int sizf = dep[from]-dep[l], sizt =\
    \ dep[to]-dep[l];\n        vector<int> pf = {from}, pt;\n        pf.reserve(sizf+1);\
    \ pt.reserve(sizt);\n        for (int i = 0; i < sizf; i++){\n            from\
    \ = parent(from);\n            pf.push_back(from);\n        }\n        for (int\
    \ i = 0; i < sizt; i++){\n            pt.push_back(to);\n            to = parent(to);\n\
    \        }\n        pf.insert(pf.end(),pt.rbegin(),pt.rend());\n        return\
    \ pf;\n    }\n    // dist, v1, v2\n    tuple<int,int,int> diameter(){\n      \
    \  int v1 = max_element(dep.begin(),dep.end()) - dep.begin();\n        vector<int>\
    \ dist_from_v1(n,numeric_limits<int>::max());\n        queue<int> que;\n     \
    \   que.push(v1);\n        dist_from_v1[v1] = 0;\n        while (!que.empty()){\n\
    \            int p = que.front(); que.pop();\n            for (int i = start[p];\
    \ i < start[p+1]; i++){\n                if (dist_from_v1[es[i]] > dist_from_v1[p]+1){\n\
    \                    dist_from_v1[es[i]] = dist_from_v1[p]+1;\n              \
    \      que.push(es[i]);\n                }\n            }\n        }\n       \
    \ int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();\n\
    \        return make_tuple(dist_from_v1[v2],v1,v2);\n    }\n    template<typename\
    \ F>\n    void path_query(int u, int v, bool vertex, const F &f){ // f is function\
    \ takes (left, right) as argument, range = [left,right).\n        int l = lca(u,v);\n\
    \        for (auto &p : ascend(u,l)){\n            int s = p.first + 1, t = p.second;\
    \ // p.first + 1 : depth(p.first) > depth(p.second), so [p.second,p.first] = [p.second,p.first+1)\n\
    \            s > t ? f(t,s) : f(s,t);\n        }\n        if (vertex) f(down[l],down[l]+1);\
    \ // vertex is true : query is for point \n        for (auto &p : descend(l,v)){\n\
    \            int s = p.first, t = p.second + 1; // p.second +1 : depth(p.first)\
    \ < depth(p.second), so [p.first,p.second] = [p.first,p.second+1)\n          \
    \  s > t ? f(t,s) : f(s,t);\n        }\n    }\n    template<typename F>\n    void\
    \ path_noncommutative_query(int u, int v, bool vertex, const F &f){ // op(l,r)\
    \ != op(r,l), so prod[u->...->v] != prod[v->...->u]\n        int l = lca(u,v);\n\
    \        for (auto &p : ascend(u,l)){\n            int s = p.first + 1, t = p.second;\
    \ // p.first + 1 : depth(p.first) > depth(p.second), so [p.second,p.first] = [p.second,p.first+1)\n\
    \            f(s,t); // le > ri ok\n        }\n        if (vertex) f(down[l],down[l]+1);\
    \ // vertex is true : query is for point \n        for (auto &p : descend(l,v)){\n\
    \            int s = p.first, t = p.second + 1; // p.second +1 : depth(p.first)\
    \ < depth(p.second), so [p.first,p.second] = [p.first,p.second+1)\n          \
    \  f(s,t); // le > ri ok\n        }\n    }\n    template<typename F>\n    void\
    \ subtree_query(int v, bool vertex, const F &f){\n        f(down[v] + (vertex\
    \ ? 0 : 1), up[v]);\n    }\n    const auto operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\
    \ }\n    const auto operator()(int idx){ return std::ranges::subrange(es.begin()+start_skip_parent(idx),es.begin()+start[idx+1]);\
    \ }\n    int set_id_v(int v) const {\n        return down[v];\n    }\n    int\
    \ set_id_e(int u, int v) const {\n        return (dep[u] < dep[v] ? down[v] :\
    \ down[u]);\n    }\n    int vertex_id(int i){\n        return tour[i];\n    }\n\
    \  private:\n    void build(){\n        es.resize((n-1)*2);\n        start.resize(n+2,0);\n\
    \        for (int i = 0; i < n-1; i++){\n            start[down[i]+2]++;\n   \
    \         start[tour[i]+2]++;\n        }\n        for (int i = 1; i <= n; i++){\n\
    \            start[i+1] += start[i];\n        }\n        for (int i = 0; i < n-1;\
    \ i++){\n            es[start[down[i]+1]++] = tour[i];\n            es[start[tour[i]+1]++]\
    \ = down[i];\n        }\n        init_bfs();\n        init_dfs();\n    }\n   \
    \ void init_bfs(){\n        dep.resize(n,numeric_limits<int>::max());\n      \
    \  up.resize(n);\n        int l = 0, r = 0;\n        auto push = [&](int x){\n\
    \            up[r++] = x;\n        };\n        auto pop_front = [&](){\n     \
    \       return up[l++];\n        };\n        dep[root] = 0;\n        push(root);\n\
    \        while (l < r){\n            int p = pop_front();\n            for (int\
    \ i = start[p]; i < start[p+1]; i++){\n                auto q = es[i];\n     \
    \           if (dep[q] > dep[p]+1){\n                    dep[q] = dep[p]+1;\n\
    \                    push(q);\n                }\n                else {\n   \
    \                 swap(es[start[p]],es[i]);\n                }\n            }\n\
    \        }\n        sub.resize(n,1);\n        for (int v : up | std::views::reverse){\n\
    \            const int stv = start_skip_parent(v);\n            for (int i = stv;\
    \ i < start[v+1]; i++){\n                sub[v] += sub[es[i]];\n             \
    \   if (sub[es[stv]] < sub[es[i]]) swap(es[stv],es[i]);\n            }\n     \
    \   }\n    }\n    void init_dfs(){\n        nxt.resize(n);\n        nxt[root]\
    \ = root;\n        int inner_clock = 0;\n        auto dfs = [&](auto sfs, int\
    \ v) -> void {\n            down[v] = inner_clock++;\n            tour[down[v]]\
    \ = v;\n            int stv = start_skip_parent(v);\n            if (stv < start[v+1]){\n\
    \                nxt[es[stv]] = nxt[v];\n                sfs(sfs,es[stv]);\n \
    \               for (int i = stv+1; i < start[v+1]; i++){\n                  \
    \  nxt[es[i]] = es[i];\n                    sfs(sfs,es[i]);\n                }\n\
    \            }\n            up[v] = inner_clock;\n        };\n        dfs(dfs,root);\n\
    \    }\n    vector<pair<int,int>> ascend(int u, int v){ // [u,v), depth[u] > depth[v]\n\
    \        vector<pair<int,int>> res;\n        while (nxt[u] != nxt[v]){\n     \
    \       res.emplace_back(down[u],down[nxt[u]]); // [s1,t1], [s2,t2], ...\n   \
    \         u = es[start[nxt[u]]]; // parent of nxt[u]\n        }\n        if (u\
    \ != v) res.emplace_back(down[u],down[v]+1); // [s,t). v is not in the range (down[]\
    \ is ordered opposite direction of depth)\n        return res;\n    }\n    vector<pair<int,int>>\
    \ descend(int u, int v){ // (u,v], depth[u] < depth[v]\n        if (u == v) return\
    \ {};\n        if (nxt[u] == nxt[v]){\n            return {pair<int,int>(down[u]+1,down[v])};\
    \ // (s,t]. u is not in the range\n        }\n        vector<pair<int,int>> res\
    \ = descend(u,es[start[nxt[v]]]); // descend(u, parent of nxt[v])\n        res.emplace_back(down[nxt[v]],down[v]);\
    \ // [s1,t1], [s2,t2], ...\n        return res;\n    }\n    int start_skip_parent(int\
    \ v) const { return start[v]+int(v != root); }\n    int n, root, inner_edge_id;\n\
    \    vector<int> es, start, dep, sub, down, up, tour, nxt;\n};\n\n} // namespace\
    \ noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2023-11-01 21:53:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/Vertex_Add_Path_Sum.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/tree/heavy_light_decomposition.hpp
- /library/tree/heavy_light_decomposition.hpp.html
title: tree/heavy_light_decomposition.hpp
---
