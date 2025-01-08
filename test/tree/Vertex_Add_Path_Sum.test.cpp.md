---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
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
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/fenwick_tree.hpp\"\
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
    \n\n#line 6 \"tree/heavy_light_decomposition.hpp\"\n#include <ranges>\n#line 9\
    \ \"tree/heavy_light_decomposition.hpp\"\n\n// #include \"data_structure/csr.hpp\"\
    \n\nnamespace noya2 {\n\nstruct hld_tree {\n    int n, root;\n    std::vector<int>\
    \ down, nxt, sub, tour;\n\t// noya2::internal::csr<int> childs;\n\n    // default\
    \ constructor (nop)\n    hld_tree () {}\n\n    // tree with _n node\n    // after\
    \ construct, call input_edges / input_parents / add_edge _n - 1 times\n    hld_tree\
    \ (int _n, int _root = 0) : n(_n), root(_root), down(n), nxt(n), sub(n, 1), tour(n)\
    \ {\n        if (n == 1){\n            nxt[0] = -1;\n            down[0] = -1;\n\
    \            build_from_parents();\n        }\n    }\n\n    // par[i] < i, par[0]\
    \ == -1\n    hld_tree (const std::vector<int> &par) : n(par.size()), root(0),\
    \ down(n, -1), nxt(par), sub(n, 1), tour(n){\n        build_from_parents();\n\
    \    }\n\n    // par[i] < i, par[0] == -1\n    hld_tree (std::vector<int> &&par)\
    \ : n(par.size()), root(0), down(n, -1), sub(n, 1), tour(n) {\n        nxt.swap(par);\n\
    \        build_from_parents();\n    }\n\n    // distinct unweighted undirected\
    \ n - 1 edges of tree \n    hld_tree (const std::vector<std::pair<int, int>> &es,\
    \ int _root = 0) : n(es.size() + 1), root(_root), down(n), nxt(n), sub(n, 1),\
    \ tour(n) {\n        for (auto &[u, v] : es){\n            down[u]++;\n      \
    \      down[v]++;\n            nxt[u] ^= v;\n            nxt[v] ^= u;\n      \
    \  }\n        build_from_edges();\n    }\n\n    // input parents from cin\n  \
    \  template<int indexed = 1>\n    void input_parents(){\n        // using std::cin;\n\
    \        nxt[0] = -1;\n        for (int u = 1; u < n; u++){\n            cin >>\
    \ nxt[u];\n            nxt[u] -= indexed;\n        }\n        build_from_parents();\n\
    \    }\n\n    // input n - 1 edges from cin\n    template<int indexed = 1>\n \
    \   void input_edges(){\n        // using std::cin;\n        for (int i = 1; i\
    \ < n; i++){\n            int u, v; cin >> u >> v;\n            u -= indexed;\n\
    \            v -= indexed;\n            down[u]++;\n            down[v]++;\n \
    \           nxt[u] ^= v;\n            nxt[v] ^= u;\n        }\n        build_from_edges();\n\
    \    }\n\n    void add_edge(int u, int v){\n        down[u]++;\n        down[v]++;\n\
    \        nxt[u] ^= v;\n        nxt[v] ^= u;\n        // use tour[0] as counter\n\
    \        if (++tour[0] == n - 1){\n            build_from_edges();\n        }\n\
    \    }\n\n    size_t size() const {\n        return n;\n    }\n\n    // top vertex\
    \ of heavy path which contains v\n    int leader(int v) const {\n        return\
    \ nxt[v] < 0 ? v : nxt[v];\n    }\n\n    // level ancestor\n    // ret is ancestor\
    \ of v, dist(ret, v) == d\n    // if d > depth(v), return -1\n    int la(int v,\
    \ int d) const {\n        while (v != -1){\n            int u = leader(v);\n \
    \           if (down[v] - d >= down[u]){\n                v = tour[down[v] - d];\n\
    \                break;\n            }\n            d -= down[v] - down[u] + 1;\n\
    \            v = (u == root ? -1 : ~nxt[u]);\n        }\n        return v;\n \
    \   }\n\n    // lowest common ancestor of u and v\n    int lca(int u, int v) const\
    \ {\n        int du = down[u], dv = down[v];\n        if (du > dv){\n        \
    \    std::swap(du, dv);\n            std::swap(u, v);\n        }\n        if (dv\
    \ < du + sub[u]){\n            return u;\n        }\n        while (du < dv){\n\
    \            v = ~nxt[leader(v)];\n            dv = down[v];\n        }\n    \
    \    return v;\n    }\n\n    // distance from u to v\n    int dist(int u, int\
    \ v) const {\n        int _dist = 0;\n        while (leader(u) != leader(v)){\n\
    \            if (down[u] > down[v]) std::swap(u, v);\n            _dist += down[v]\
    \ - down[leader(v)] + 1;\n            v = ~nxt[leader(v)];\n        }\n      \
    \  _dist += std::abs(down[u] - down[v]);\n        return _dist;\n    }\n\n   \
    \ // d times move from to its neighbor (direction of to)\n    // if d > dist(from,\
    \ to), return -1\n    int jump(int from, int to, int d) const {\n        int _from\
    \ = from, _to = to;\n        int dist_from_lca = 0, dist_to_lca = 0;\n       \
    \ while (leader(_from) != leader(_to)){\n            if (down[_from] > down[_to]){\n\
    \                dist_from_lca += down[_from] - down[leader(_from)] + 1;\n   \
    \             _from = ~nxt[leader(_from)];\n            }\n            else {\n\
    \                dist_to_lca += down[_to] - down[leader(_to)] + 1;\n         \
    \       _to = ~nxt[leader(_to)];\n            }\n        }\n        if (down[_from]\
    \ > down[_to]){\n            dist_from_lca += down[_from] - down[_to];\n     \
    \   }\n        else {\n            dist_to_lca += down[_to] - down[_from];\n \
    \       }\n        if (d <= dist_from_lca){\n            return la(from, d);\n\
    \        }\n        d -= dist_from_lca;\n        if (d <= dist_to_lca){\n    \
    \        return la(to, dist_to_lca - d);\n        }\n        return -1;\n    }\n\
    \n    // parent of v (if v is root, return -1)\n    int parent(int v) const {\n\
    \        if (v == root) return -1;\n        return (nxt[v] < 0 ? ~nxt[v] : tour[down[v]\
    \ - 1]);\n    }\n\n    // visiting time in euler tour\n    // usage : seg.set(index(v),\
    \ X[v])\n    int index(int vertex) const {\n        return down[vertex];\n   \
    \ }\n    // usage : seg.set(index_edge(e.u, e.v), e.val)\n    int index(int vertex1,\
    \ int vertex2) const {\n        return std::max(down[vertex1], down[vertex2]);\n\
    \    }\n\n    // subtree size of v\n    int subtree_size(int v) const {\n    \
    \    return sub[v];\n    }\n\n    // prod in subtree v : seg.prod(subtree_l(v),\
    \ subtree_r(v))\n    int subtree_l(int v) const {\n        return down[v];\n \
    \   }\n    int subtree_r(int v) const {\n        return down[v] + sub[v];\n  \
    \  }\n\n    // v is in subtree r\n    bool is_in_subtree(int r, int v) const {\n\
    \        return subtree_l(r) <= subtree_l(v) && subtree_r(v) <= subtree_r(r);\n\
    \    }\n    \n    // distance table from s\n    std::vector<int> dist_table(int\
    \ s) const {\n        std::vector<int> table(n, -1);\n        table[s] = 0;\n\
    \        while (s != root){\n            table[parent(s)] = table[s] + 1;\n  \
    \          s = parent(s);\n        }\n        for (int v : tour){\n          \
    \  if (table[v] == -1){\n                table[v] = table[parent(v)] + 1;\n  \
    \          }\n        }\n        return table;\n    }\n\n    // dist, v1, v2\n\
    \    std::tuple<int, int, int> diameter() const {\n        std::vector<int> dep\
    \ = dist_table(root);\n        int v1 = std::ranges::max_element(dep) - dep.begin();\n\
    \        std::vector<int> fromv1 = dist_table(v1);\n        int v2 = std::ranges::max_element(fromv1)\
    \ - fromv1.begin();\n        return {fromv1[v2], v1, v2};\n    }\n\n    // vertex\
    \ array {from, ..., to}\n    std::vector<int> path(int from, int to) const {\n\
    \        int d = dist(from, to);\n        std::vector<int> _path(d + 1);\n   \
    \     int front = 0, back = d;\n        while (from != to){\n            if (down[from]\
    \ > down[to]){\n                _path[front++] = from;\n                from =\
    \ parent(from);\n            }\n            else {\n                _path[back--]\
    \ = to;\n                to = parent(to);\n            }\n        }\n        _path[front]\
    \ = from;\n        return _path;\n    }\n\n    // path decomposition and query\
    \ (vertex weighted)\n    // if l < r, decsending order tour[l, r)\n    // if l\
    \ > r, acsending order tour(l, r]\n    template<bool vertex = true>\n    void\
    \ path_query(int u, int v, auto f) const {\n        while (leader(u) != leader(v)){\n\
    \            if (down[u] < down[v]){\n                f(down[leader(v)], down[v]\
    \ + 1);\n                v = ~nxt[leader(v)];\n            }\n            else\
    \ {\n                f(down[u] + 1, down[leader(u)]);\n                u = ~nxt[leader(u)];\n\
    \            }\n        }\n        if constexpr (vertex){\n            if (down[u]\
    \ < down[v]){\n                f(down[u], down[v] + 1);\n            }\n     \
    \       else {\n                f(down[u] + 1, down[v]);\n            }\n    \
    \    }\n        else {\n            if (down[u] != down[v]){\n               \
    \ f(down[u] + 1, down[v] + 1);\n            }\n        }\n    }\n\n    // {parent,\
    \ mapping} : cptree i is correspond to tree mapping[i]. parent[i] is parent of\
    \ i in cptree.\n    // parent[i] < i, parent[0] == -1\n\tstd::pair<std::vector<int>,\
    \ std::vector<int>> compressed_tree(std::vector<int> vs) const {\n        if (vs.empty()){\n\
    \            return {{},{}};\n        }\n        auto comp = [&](int l, int r){\n\
    \            return down[l] < down[r];\n        };\n\t\tstd::ranges::sort(vs,\
    \ comp);\n\t\tint sz = vs.size(); vs.reserve(2*sz);\n        for (int i = 0; i\
    \ < sz-1; i++){\n            vs.emplace_back(lca(vs[i], vs[i+1]));\n        }\n\
    \        std::sort(vs.begin() + sz, vs.end(), comp);\n        std::ranges::inplace_merge(vs,\
    \ vs.begin() + sz, comp);\n        auto del = std::ranges::unique(vs);\n     \
    \   vs.erase(del.begin(), del.end());\n        sz = vs.size();\n        std::stack<int>\
    \ st;\n        std::vector<int> par(sz);\n        par[0] = -1;\n        st.push(0);\n\
    \        for (int i = 1; i < sz; i++){\n            while (!is_in_subtree(vs[st.top()],\
    \ vs[i])) st.pop();\n            par[i] = st.top();\n            st.push(i);\n\
    \        }\n        return {par, vs};\n\t}\n\n/*  CSR\n\n\t// build csr for using\
    \ operator()\n\tvoid build_csr(){\n\t\tchilds = noya2::internal::csr<int>(n, n\
    \ - 1);\n\t\tfor (int v = 0; v < n; v++){\n\t\t\tif (v == root) continue;\n\t\t\
    \tchilds.add(parent(v), v);\n\t\t}\n\t\tchilds.build();\n\t}\n\tconst auto operator()(int\
    \ v) const {\n\t\treturn childs[v];\n\t}\n\tauto operator()(int v){\n\t\treturn\
    \ childs[v];\n\t}\n*/\n\n    // hld_tree g;\n    // euler tour order : `for (int\
    \ v : g)`\n    // with range_adaptor : `for (int v : g | std::views::reverse)`\n\
    \    // bottom-up DP : `for (int v : g | std::views::drop(1) | std::views::reverse){\
    \ update dp[g.parent(v)] by dp[v] }`\n    auto begin() const {\n        return\
    \ tour.begin();\n    }\n    auto end() const {\n        return tour.end();\n \
    \   }\n\n  private:\n    // nxt[v] : parent of v, nxt[0] == -1\n    void build_from_parents(){\n\
    \        for (int u = n - 1; u >= 1; u--){\n            int v = nxt[u];\n    \
    \        sub[v] += sub[u];\n            down[v] = std::max(down[v], sub[u]);\n\
    \        }\n        for (int u = n - 1; u >= 1; u--){\n            int v = nxt[u];\n\
    \            if (down[v] == sub[u]){\n                sub[u] = ~sub[u];\n    \
    \            down[v] = ~down[v];\n            }\n        }\n\n        sub[0] =\
    \ ~down[0] + 1;\n        down[0] = 0;\n        for (int u = 1; u < n; u++){\n\
    \            int v = nxt[u];\n            int nsub = ~down[u] + 1;\n         \
    \   if (sub[u] < 0){\n                down[u] = down[v] + 1;\n               \
    \ nxt[u] = (nxt[v] < 0 ? v : nxt[v]);\n            }\n            else {\n   \
    \             down[u] = down[v] + sub[v];\n                sub[v] += sub[u];\n\
    \                nxt[u] = ~v;\n            }\n            sub[u] = nsub;\n   \
    \     }\n\n        for (int u = 0; u < n; u++){\n            tour[down[u]] = u;\n\
    \        }\n    }\n\n    // down[v] : degree of v\n    // nxt[v] : xor prod of\
    \ neighbor of v\n    void build_from_edges(){\n        // use tour as queue\n\
    \        int back = 0;\n        for (int u = 0; u < n; u++){\n            if (u\
    \ != root && down[u] == 1){\n                tour[back++] = u;\n            }\n\
    \        }\n        for (int front = 0; front < n - 1; front++){\n           \
    \ int u = tour[front];\n            down[u] = -1;\n            int v = nxt[u];\
    \ // parent of v\n            nxt[v] ^= u;\n            if (--down[v] == 1 &&\
    \ v != root){\n                tour[back++] = v;\n            }\n        }\n \
    \       // check : now, tour is reverse of topological order\n\n        tour.pop_back();\n\
    \n        // check : now, down[*] <= 1\n        for (int u : tour){\n        \
    \    int v = nxt[u];\n            // subtree size (initialized (1,1,...,1))\n\
    \            sub[v] += sub[u];\n            // heaviest subtree of its child\n\
    \            down[v] = std::max(down[v], sub[u]);\n        }\n        for (int\
    \ u : tour){\n            int v = nxt[u];\n            // whether u is not the\
    \ top of heavy path\n            if (down[v] == sub[u]){\n                sub[u]\
    \ = ~sub[u];\n                down[v] = ~down[v];\n            }\n        }\n\n\
    \        // after appearing v as u (or v == root), \n        // down[v] is the\
    \ visiting time of euler tour\n        // nxt[v] is the lowest vertex of heavy\
    \ path which contains v\n        //   (if v itself, nxt[v] is ~(parent of v))\n\
    \        // sub[v] + down[v] is the light child's starting time of euler tour\n\
    \        // note : heavy child's visiting time of euler tour is (the time of its\
    \ parent) + 1\n        sub[root] = ~down[root] + 1;\n        down[root] = 0;\n\
    \        nxt[root] = -1;\n        for (int u : tour | std::views::reverse){\n\
    \            int v = nxt[u];\n            int nsub = ~down[u] + 1;\n         \
    \   // heavy child\n            if (sub[u] < 0){\n                down[u] = down[v]\
    \ + 1;\n                nxt[u] = (nxt[v] < 0 ? v : nxt[v]);\n            }\n \
    \           // light child\n            else {\n                down[u] = down[v]\
    \ + sub[v];\n                sub[v] += sub[u];\n                nxt[u] = ~v;\n\
    \            }\n            sub[u] = nsub;\n        }\n\n        // tour is inverse\
    \ permutation of down\n        tour.push_back(0);\n        for (int u = 0; u <\
    \ n; u++){\n            tour[down[u]] = u;\n        }\n    }\n};\n\n} // namespace\
    \ noya2\n#line 6 \"test/tree/Vertex_Add_Path_Sum.test.cpp\"\n\nint main(){\n \
    \   int n, q; in(n,q);\n    vector<ll> a(n); in(a);\n    hld_tree g(n);\n    g.input_edges<0>();\n\
    \    fenwick_tree<ll> fen(n);\n    rep(v,n) fen.add(g.index(v),a[v]);\n    while\
    \ (q--){\n        int t; in(t);\n        if (t == 0){\n            int p, x; in(p,x);\n\
    \            fen.add(g.index(p),x);\n        }\n        else {\n            int\
    \ u, v; in(u,v);\n            ll ans = 0;\n            auto prod = [&](int l,\
    \ int r){\n                if (l > r) swap(l,r);\n                ans += fen.sum(l,r);\n\
    \            };\n            g.path_query(u,v,prod);\n            out(ans);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include\"../../template/template.hpp\"\n#include\"../../data_structure/fenwick_tree.hpp\"\
    \n#include\"../../tree/heavy_light_decomposition.hpp\"\n\nint main(){\n    int\
    \ n, q; in(n,q);\n    vector<ll> a(n); in(a);\n    hld_tree g(n);\n    g.input_edges<0>();\n\
    \    fenwick_tree<ll> fen(n);\n    rep(v,n) fen.add(g.index(v),a[v]);\n    while\
    \ (q--){\n        int t; in(t);\n        if (t == 0){\n            int p, x; in(p,x);\n\
    \            fen.add(g.index(p),x);\n        }\n        else {\n            int\
    \ u, v; in(u,v);\n            ll ans = 0;\n            auto prod = [&](int l,\
    \ int r){\n                if (l > r) swap(l,r);\n                ans += fen.sum(l,r);\n\
    \            };\n            g.path_query(u,v,prod);\n            out(ans);\n\
    \        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/fenwick_tree.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/tree/Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '2025-01-09 04:05:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Vertex_Add_Path_Sum.test.cpp
- /verify/test/tree/Vertex_Add_Path_Sum.test.cpp.html
title: test/tree/Vertex_Add_Path_Sum.test.cpp
---
