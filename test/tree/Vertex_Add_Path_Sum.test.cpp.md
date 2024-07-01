---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
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
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: "\u5168\u90E8\u8F09\u305B\u6728"
  - icon: ':heavy_check_mark:'
    path: tree/simple_tree.hpp
    title: tree/simple_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/tree/Vertex_Add_Path_Sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 2 \"template/template.hpp\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/fenwick_tree.hpp\"\
    \n\n#line 4 \"data_structure/fenwick_tree.hpp\"\n\nnamespace noya2{\n\ntemplate\
    \ <class T> struct fenwick_tree {\n  public:\n    fenwick_tree() : _n(0) {}\n\
    \    explicit fenwick_tree(int n_) : _n(n_), data(n_) {}\n\n    void add(int p,\
    \ T x) {\n        assert(0 <= p && p < _n);\n        p++;\n        while (p <=\
    \ _n) {\n            data[p - 1] += x;\n            p += p & -p;\n        }\n\
    \    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n\
    \        return sum(r) - sum(l);\n    }\n\n  private:\n    int _n;\n    vector<T>\
    \ data;\n\n    T sum(int r) {\n        T s = 0;\n        while (r > 0) {\n   \
    \         s += data[r - 1];\n            r -= r & -r;\n        }\n        return\
    \ s;\n    }\n};\n\n} // namespace noya2\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\n#line 2 \"tree/simple_tree.hpp\"\n\n#line 2 \"data_structure/csr.hpp\"\n\n\
    #line 4 \"data_structure/csr.hpp\"\n#include<ranges>\n#line 7 \"data_structure/csr.hpp\"\
    \n\nnamespace noya2::internal {\n\ntemplate<class E>\nstruct csr {\n    csr ()\
    \ {}\n    csr (int _n) : n(_n) {}\n    csr (int _n, int m) : n(_n){\n        start.reserve(m);\n\
    \        elist.reserve(m);\n    }\n    // ACL style constructor (do not have to\
    \ call build)\n    csr (int _n, const std::vector<std::pair<int,E>> &idx_elem)\
    \ : n(_n), start(_n + 2), elist(idx_elem.size()) {\n        for (auto &[i, e]\
    \ : idx_elem){\n            start[i + 2]++;\n        }\n        for (int i = 1;\
    \ i < n; i++){\n            start[i + 2] += start[i + 1];\n        }\n       \
    \ for (auto &[i, e] : idx_elem){\n            elist[start[i + 1]++] = e;\n   \
    \     }\n        prepared = true;\n    }\n    int add(int idx, E elem){\n    \
    \    int eid = start.size();\n        start.emplace_back(idx);\n        elist.emplace_back(elem);\n\
    \        return eid;\n    }\n    void build(){\n        if (prepared) return ;\n\
    \        int m = start.size();\n        std::vector<E> nelist(m);\n        std::vector<int>\
    \ nstart(n + 2, 0);\n        for (int i = 0; i < m; i++){\n            nstart[start[i]\
    \ + 2]++;\n        }\n        for (int i = 1; i < n; i++){\n            nstart[i\
    \ + 2] += nstart[i + 1];\n        }\n        for (int i = 0; i < m; i++){\n  \
    \          nelist[nstart[start[i] + 1]++] = elist[i];\n        }\n        swap(elist,nelist);\n\
    \        swap(start,nstart);\n        prepared = true;\n    }\n    const auto\
    \ operator[](int idx) const {\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    auto operator[](int idx){\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    const auto operator()(int idx, int l, int r) const {\n        return\
    \ std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    auto operator()(int idx, int l, int r){\n        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    int n;\n    std::vector<int> start;\n    std::vector<E> elist;\n \
    \   bool prepared = false;\n};\n\n} // namespace noya2::internal\n#line 5 \"tree/simple_tree.hpp\"\
    \n\nnamespace noya2 {\n\nstruct simple_tree {\n    internal::csr<int> g;\n   \
    \ simple_tree () {}\n    simple_tree (int _n) : g(_n, (_n - 1)*2) {\n        if\
    \ (_n == 1){\n            g.build();\n        }\n    }\n    void add_edge(int\
    \ u, int v){\n        g.add(u, v);\n        int id = g.add(v, u);\n        if\
    \ (id + 1 == (g.n - 1)*2) g.build();\n    }\n    void input(int indexed = 1){\n\
    \        for (int i = 0; i < g.n - 1; i++){\n            int u, v; cin >> u >>\
    \ v;\n            u -= indexed, v -= indexed;\n            add_edge(u, v);\n \
    \       }\n    }\n    void input_parents(int indexed = 1){\n        for (int i\
    \ = 0; i < g.n - 1; i++){\n            int v; cin >> v;\n            v -= indexed;\n\
    \            add_edge(i + 1, v);\n        }\n    }\n    const auto operator[](int\
    \ v) const {\n        return g[v];\n    }\n    auto operator[](int v){\n     \
    \   return g[v];\n    }\n};\n\n} // namespace noya2\n#line 4 \"tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace noya2 {\n\nstruct hld_tree {\n    internal::csr<int> g;\n    hld_tree\
    \ () {}\n    hld_tree (int _n, int _root = 0) : g(_n,(_n - 1)*2), n(_n), root(_root)\
    \ {\n        if (_n == 1){\n            build();\n        }\n    }\n    hld_tree\
    \ (simple_tree _g, int _root = 0) : g(_g.g), n(_g.g.n), root(_root){\n       \
    \ build();\n    }\n\n    void add_edge(int u, int v){\n        g.add(u, v);\n\
    \        int id = g.add(v, u);\n        if (id + 1 == (n - 1)*2) build();\n  \
    \  }\n    void input(int indexed = 1){\n        for (int i = 0; i < n - 1; i++){\n\
    \            int u, v; cin >> u >> v;\n            u -= indexed, v -= indexed;\n\
    \            add_edge(u, v);\n        }\n    }\n    void input_parents(int indexed\
    \ = 1){\n        for (int i = 0; i < n - 1; i++){\n            int v; cin >> v;\n\
    \            v -= indexed;\n            add_edge(i + 1, v);\n        }\n    }\n\
    \n    int depth(int v) const {\n        return dep[v];\n    }\n\n    int parent(int\
    \ v) const {\n        if (v == root) return -1;\n        return g[v].back();\n\
    \    }\n\n    int degree(int v) const {\n        return g[v].size();\n    }\n\n\
    \    int subtree_size(int v) const {\n        return sub[v];\n    }\n\n    //\
    \ if d > dep[v], return -1\n    int la(int v, int d) const {\n        while (v\
    \ != -1){\n            int u = nxt[v];\n            if (down[v] - d >= down[u]){\n\
    \                v = tour[down[v] - d];\n                break;\n            }\n\
    \            d -= down[v] - down[u] + 1;\n            v = parent(u);\n       \
    \ }\n        return v;\n    }\n\n    int lca(int u, int v) const {\n        while\
    \ (nxt[u] != nxt[v]){\n            if (down[u] < down[v]) swap(u,v);\n       \
    \     u = parent(nxt[u]);\n        }\n        return dep[u] < dep[v] ? u : v;\n\
    \    }\n\n    int dist(int u, int v) const {\n        return dep[u] + dep[v] -\
    \ 2*dep[lca(u,v)];\n    }\n\n    // if d > dist(from, to), return -1\n    int\
    \ jump(int from, int to, int d) const {\n        int l = lca(from,to);\n     \
    \   if (d <= dep[from] - dep[l]){\n            return la(from, d);\n        }\n\
    \        d -= dep[from] - dep[l];\n        if (d <= dep[to] - dep[l]){\n     \
    \       return la(to, dep[to] - dep[l] - d);\n        }\n        return -1;\n\
    \    }\n\n    // seg.set(index(v), X[v]);\n    int index(int vertex) const {\n\
    \        return down[vertex];\n    }\n\n    int index_from_edge(int u, int v)\
    \ const {\n        return (dep[u] < dep[v] ? down[v] : down[u]);\n    }\n\n  \
    \  // X[vertex(i)] = seg.get(i);\n    int vertex(int index) const {\n        return\
    \ tour[index];\n    }\n\n    int subtree_l(int v) const {\n        return down[v];\n\
    \    }\n\n    int subtree_r(int v) const {\n        return down[v] + sub[v];\n\
    \    }\n\n    // if r == v, return true\n    bool is_in_subtree(int r, int v)\
    \ const {\n        return subtree_l(r) <= subtree_l(v) && subtree_l(v) < subtree_r(r);\n\
    \    }\n\n    bool is_in_path(int lv, int mv, int rv) const {\n        return\
    \ dist(lv,mv) + dist(mv,rv) == dist(lv,rv);\n    }\n\n    // dist, v1, v2\n  \
    \  tuple<int,int,int> diameter(){\n        int v1 = max_element(dep.begin(),dep.end())\
    \ - dep.begin();\n        vector<int> dist_from_v1(n,numeric_limits<int>::max());\n\
    \        queue<int> que;\n        que.push(v1);\n        dist_from_v1[v1] = 0;\n\
    \        while (!que.empty()){\n            int v = que.front(); que.pop();\n\
    \            for (int u : g[v]){\n                if (dist_from_v1[u] > dist_from_v1[v]+1){\n\
    \                    dist_from_v1[u] = dist_from_v1[v]+1;\n                  \
    \  que.push(u);\n                }\n            }\n        }\n        int v2 =\
    \ max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();\n\
    \        return make_tuple(dist_from_v1[v2],v1,v2);\n    }\n\n    // vertex array\
    \ : vector<int> {from, v1, v2, ... , to}\n    vector<int> path(int from, int to){\n\
    \        int l = lca(from,to);\n        const int sizf = dep[from]-dep[l], sizt\
    \ = dep[to]-dep[l];\n        vector<int> pf = {from}, pt;\n        pf.reserve(sizf+1);\
    \ pt.reserve(sizt);\n        for (int i = 0; i < sizf; i++){\n            from\
    \ = parent(from);\n            pf.push_back(from);\n        }\n        for (int\
    \ i = 0; i < sizt; i++){\n            pt.push_back(to);\n            to = parent(to);\n\
    \        }\n        pf.insert(pf.end(),pt.rbegin(),pt.rend());\n        return\
    \ pf;\n    }\n\n    template<typename F>\n    void path_query(int u, int v, bool\
    \ vertex, const F &f){\n        int l = lca(u,v);\n        for (auto [s, t] :\
    \ ascend(u, l)){\n            f(t, s + 1);\n        }\n        if (vertex) f(down[l],\
    \ down[l] + 1);\n        for (auto [s, t] : descend(l, v)){\n            f(s,\
    \ t + 1);\n        }\n    }\n\n    template<typename F>\n    void path_noncommutative_query(int\
    \ u, int v, bool vertex, const F &f){\n        int l = lca(u,v);\n        for\
    \ (auto [s, t] : ascend(u, l)){\n            f(s + 1, t); // l > r ok\n      \
    \  }\n        if (vertex) f(down[l],down[l] + 1);\n        for (auto [s, t] :\
    \ descend(l, v)){\n            f(s, t + 1); // l > r ok\n        }\n    }\n\n\
    \    template<typename F>\n    void subtree_query(int v, bool vertex, const F\
    \ &f){\n        f(down[v] + (vertex ? 0 : 1), down[v] + sub[v]);\n    }\n\n  \
    \  // adjacent to v\n    const auto operator[](int v) const {\n        return\
    \ g[v];\n    }\n    auto operator[](int v){\n        return g[v];\n    }\n\n \
    \   // only child\n    const auto operator()(int v) const {\n        return g(v,\
    \ 0, degree(v) - (v == root ? 0 : 1));\n    }\n    auto operator()(int v){\n \
    \       return g(v, 0, degree(v) - (v == root ? 0 : 1));\n    }\n\n  private:\n\
    \    int n, root;\n    vector<int> dep, sub, down, tour, nxt;\n\n    // v is ancestor\
    \ of u.\n    // enumerate [closed] intervals of down ( interval [l, r] may hold\
    \ l > r ).\n    vector<pair<int,int>> ascend(int u, int v){\n        vector<pair<int,int>>\
    \ res;\n        while (nxt[u] != nxt[v]){\n            res.emplace_back(down[u],\
    \ down[nxt[u]]);\n            u = parent(nxt[u]);\n        }\n        if (u !=\
    \ v) res.emplace_back(down[u], down[v]+1);\n        return res;\n    }\n\n   \
    \ // u is ancestor of v.\n    // enumerate [closed] intervals of down ( interval\
    \ [l, r] may hold l > r ).\n    vector<pair<int,int>> descend(int u, int v){\n\
    \        if (u == v) return {};\n        if (nxt[u] == nxt[v]){\n            return\
    \ {pair<int,int>(down[u]+1, down[v])};\n        }\n        vector<pair<int,int>>\
    \ res = descend(u, parent(nxt[v]));\n        res.emplace_back(down[nxt[v]], down[v]);\n\
    \        return res;\n    }\n\n    void build(){\n        g.build();\n       \
    \ init_sz();\n        init_hld();\n    }\n\n    /*\n        setup dep, sub\n \
    \       if v is not root, g[v].back() is parent of v.\n        if v is not leaf\
    \ (i.e. v has child), g[v].front() is heavy child of v.\n    */\n    void init_sz(){\n\
    \        dep.resize(n, 0);\n        sub.resize(n, 1);\n        auto dfs = [&](auto\
    \ sfs, int v, int f) -> void {\n            for (int &u : g[v]){\n           \
    \     // only one chance to take parent as u.\n                if (u == f) swap(g[v].back(),\
    \ u);\n                // twice means u is the last element of g[v], i.e. parent\
    \ of v.\n                if (u == f) break;\n                dep[u] = dep[v]+1;\n\
    \                sfs(sfs, u, v);\n                sub[v] += sub[u];\n        \
    \        if (sub[g[v].front()] < sub[u]){\n                    swap(g[v].front(),\
    \ u);\n                }\n            }\n        };\n        dfs(dfs, root, -1);\n\
    \    }\n\n    /*\n        setup down, tour, nxt\n        only heavy child c of\
    \ v, nxt[c] = nxt[v]. for other child c, nxt[c] = c.\n    */\n    void init_hld(){\n\
    \        down.resize(n);\n        tour.resize(n);\n        nxt.resize(n);\n  \
    \      nxt[root] = root;\n        int clock = 0;\n        auto dfs = [&](auto\
    \ sfs, int v) -> void {\n            down[v] = clock++;\n            tour[down[v]]\
    \ = v;\n            // in case of no child, nothing to do\n            if ((*this)(v).empty())\
    \ return ;\n            // heavy child\n            nxt[(*this)(v).front()] =\
    \ nxt[v];\n            sfs(sfs, (*this)(v).front());\n            // other child\n\
    \            for (int u : (*this)(v).next()){\n                nxt[u] = u;\n \
    \               sfs(sfs, u);\n            }\n        };\n        dfs(dfs, root);\n\
    \    }\n\n  public:\n    struct compressed_tree : public simple_tree {\n     \
    \   using simple_tree::simple_tree;\n        using simple_tree::operator=;\n \
    \       hld_tree &g;\n        compressed_tree (hld_tree &g_, vector<int> vs) :\
    \ g(g_){\n            auto comp = [&](int lv, int rv){\n                return\
    \ g.index(lv) < g.index(rv);\n            };\n            sort(vs.begin(),vs.end(),comp);\n\
    \            int sz = vs.size();\n            for (int i = 0; i < sz-1; i++){\n\
    \                vs.emplace_back(g.lca(vs[i],vs[i+1]));\n            }\n     \
    \       sort(vs.begin(),vs.end(),comp);\n            vs.erase(unique(vs.begin(),vs.end()),vs.end());\n\
    \            sz = vs.size();\n            (*this) = simple_tree(sz);\n       \
    \     real_vertex = vs;\n            for (int i = 0; i < sz; i++){\n         \
    \       g.virtual_vertex[real_vertex[i]] = i;\n            }\n            stack<int>\
    \ st;\n            st.push(0);\n            for (int i = 1; i < sz; i++){\n  \
    \              while (!g.is_in_subtree(real_vertex[st.top()], real_vertex[i]))\
    \ st.pop();\n                (*this).add_edge(st.top(),i);\n                st.push(i);\n\
    \            }\n        }\n        vector<int> real_vertex;\n        int real_v(int\
    \ virtual_v) const {\n            return real_vertex[virtual_v];\n        }\n\
    \        int virtual_v(int real_v) const {\n            return g.virtual_vertex[real_v];\n\
    \        }\n        size_t size() const {\n            return real_vertex.size();\n\
    \        }\n    };\n    compressed_tree compressed_tree_gen(const vector<int>\
    \ &vs){\n        if ((int)virtual_vertex.size() != n) virtual_vertex.resize(n);\n\
    \        return compressed_tree(*this, vs);\n    }\n    vector<int> virtual_vertex;\n\
    };\n\n} // namespace noya2\n#line 6 \"test/tree/Vertex_Add_Path_Sum.test.cpp\"\
    \n\nint main(){\n    int n, q; in(n,q);\n    vector<ll> a(n); in(a);\n    hld_tree\
    \ g(n);\n    g.input(0);\n    fenwick_tree<ll> fen(n);\n    rep(v,n) fen.add(g.index(v),a[v]);\n\
    \    while (q--){\n        int t; in(t);\n        if (t == 0){\n            int\
    \ p, x; in(p,x);\n            fen.add(g.index(p),x);\n        }\n        else\
    \ {\n            int u, v; in(u,v);\n            ll ans = 0;\n            auto\
    \ prod = [&](int l, int r){\n                ans += fen.sum(l,r);\n          \
    \  };\n            g.path_query(u,v,true,prod);\n            out(ans);\n     \
    \   }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include\"../../template/template.hpp\"\n#include\"../../data_structure/fenwick_tree.hpp\"\
    \n#include\"../../tree/heavy_light_decomposition.hpp\"\n\nint main(){\n    int\
    \ n, q; in(n,q);\n    vector<ll> a(n); in(a);\n    hld_tree g(n);\n    g.input(0);\n\
    \    fenwick_tree<ll> fen(n);\n    rep(v,n) fen.add(g.index(v),a[v]);\n    while\
    \ (q--){\n        int t; in(t);\n        if (t == 0){\n            int p, x; in(p,x);\n\
    \            fen.add(g.index(p),x);\n        }\n        else {\n            int\
    \ u, v; in(u,v);\n            ll ans = 0;\n            auto prod = [&](int l,\
    \ int r){\n                ans += fen.sum(l,r);\n            };\n            g.path_query(u,v,true,prod);\n\
    \            out(ans);\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/fenwick_tree.hpp
  - tree/heavy_light_decomposition.hpp
  - tree/simple_tree.hpp
  - data_structure/csr.hpp
  isVerificationFile: true
  path: test/tree/Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-07-01 23:28:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Vertex_Add_Path_Sum.test.cpp
- /verify/test/tree/Vertex_Add_Path_Sum.test.cpp.html
title: test/tree/Vertex_Add_Path_Sum.test.cpp
---
