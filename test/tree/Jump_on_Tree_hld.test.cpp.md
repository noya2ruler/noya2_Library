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
    path: tree/tree_query.hpp
    title: tree/tree_query.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"test/tree/Jump_on_Tree_hld.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"tree/tree_query.hpp\"\n\n#line\
    \ 9 \"tree/tree_query.hpp\"\n#include<ranges>\n\nstruct Tree {\n    Tree (int\
    \ n_ = 0, int root_ = 0) : n(n_), root(root_), inner_edge_id(0), es(n-1), start(n+1,0){\n\
    \        if (n == 1) build();\n    }\n    void add_edge(int u, int v){\n     \
    \   es[inner_edge_id] = u, start[inner_edge_id] = v;\n        if (++inner_edge_id\
    \ == n-1) build();\n    }\n    void input(int indexed = 1){\n        for (int\
    \ i = 0; i < n-1; i++){\n            int u, v; std::cin >> u >> v;\n         \
    \   u -= indexed, v -= indexed;\n            add_edge(u,v);\n        }\n    }\n\
    \    void input_parents(int indexed = 1){\n        for (int i = 0; i < n-1; i++){\n\
    \            int p; std::cin >> p;\n            p -= indexed;\n            add_edge(p,i+1);\n\
    \        }\n    }\n    int degree(int v){\n        assert(0 <= v && v < n);\n\
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
    \ }\n    std::vector<int> path(int from, int to){\n        int l = lca(from,to);\n\
    \        const int sizf = dep[from]-dep[l], sizt = dep[to]-dep[l];\n        std::vector<int>\
    \ pf = {from}, pt;\n        pf.reserve(sizf+1); pt.reserve(sizt);\n        for\
    \ (int i = 0; i < sizf; i++){\n            from = parent(from);\n            pf.push_back(from);\n\
    \        }\n        for (int i = 0; i < sizt; i++){\n            pt.push_back(to);\n\
    \            to = parent(to);\n        }\n        pf.insert(pf.end(),pt.rbegin(),pt.rend());\n\
    \        return pf;\n    }\n    // dist, v1, v2\n    std::tuple<int,int,int> diameter(){\n\
    \        int v1 = std::max_element(dep.begin(),dep.end()) - dep.begin();\n   \
    \     std::vector<int> dist_from_v1(n,std::numeric_limits<int>::max());\n    \
    \    std::queue<int> que;\n        que.push(v1);\n        dist_from_v1[v1] = 0;\n\
    \        while (!que.empty()){\n            int p = que.front(); que.pop();\n\
    \            for (int i = start[p]; i < start[p+1]; i++){\n                if\
    \ (dist_from_v1[es[i]] > dist_from_v1[p]+1){\n                    dist_from_v1[es[i]]\
    \ = dist_from_v1[p]+1;\n                    que.push(es[i]);\n               \
    \ }\n            }\n        }\n        int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end())\
    \ - dist_from_v1.begin();\n        return std::make_tuple(dist_from_v1[v2],v1,v2);\n\
    \    }\n    const auto operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\
    \ }\n  private:\n    void build(){\n        std::vector<int> nes(2*(n-1)), fs\
    \ = start;\n        std::fill(start.begin(),start.end(),0);\n        for (int\
    \ i = 0; i < n-1; i++) start[es[i]+1]++, start[fs[i]+1]++;\n        for (int i\
    \ = 0; i < n; i++) start[i+1] += start[i];\n        auto geta = start;\n     \
    \   for (int i = 0; i < n-1; i++){\n            nes[geta[es[i]]++] = fs[i];\n\
    \            nes[geta[fs[i]]++] = es[i];\n        }\n        std::swap(es,nes);\n\
    \        init_bfs();\n        init_dfs();\n    }\n    void init_bfs(){\n     \
    \   dep.resize(n,std::numeric_limits<int>::max());\n        std::queue<int> que;\n\
    \        que.push(root);\n        dep[root] = 0;\n        std::vector<int> order;\
    \ order.reserve(n);\n        while (!que.empty()){\n            int p = que.front();\
    \ que.pop();\n            order.push_back(p);\n            for (int i = start[p];\
    \ i < start[p+1]; i++){\n                auto q = es[i];\n                if (dep[q]\
    \ > dep[p]+1){\n                    dep[q] = dep[p]+1;\n                    que.push(q);\n\
    \                }\n                else {\n                    std::swap(es[start[p]],es[i]);\n\
    \                }\n            }\n        }\n        sub.resize(n,0);\n     \
    \   for (int v : order | std::views::reverse){\n            sub[v] = 1;\n    \
    \        int stv = start_skip_parent(v);\n            for (int i = stv; i < start[v+1];\
    \ i++){\n                sub[v] += sub[es[i]];\n                if (sub[es[stv]]\
    \ < sub[es[i]]) std::swap(es[stv],es[i]);\n            }\n        }\n    }\n \
    \   void init_dfs(){\n        down.resize(n);\n        tour.resize(n);\n     \
    \   nxt.resize(n);\n        nxt[root] = root;\n        int nowtime = 0;\n    \
    \    auto dfs = [&](auto sfs, int v) -> void {\n            down[v] = nowtime++;\n\
    \            tour[down[v]] = v;\n            int stv = start_skip_parent(v);\n\
    \            if (stv >= start[v+1]) return ;\n            nxt[es[stv]] = nxt[v];\n\
    \            sfs(sfs,es[stv]);\n            for (int i = stv+1; i < start[v+1];\
    \ i++){\n                nxt[es[i]] = es[i];\n                sfs(sfs,es[i]);\n\
    \            }\n        };\n        dfs(dfs,root);\n    }\n    inline int start_skip_parent(int\
    \ v) const { return start[v]+int(v != root); }\n    int n, root, inner_edge_id;\n\
    \    std::vector<int> es, start, dep, sub, down, tour, nxt;\n};\n#line 5 \"test/tree/Jump_on_Tree_hld.test.cpp\"\
    \n\nint main(){\n    int n, q; in(n,q);\n    Tree g(n);\n    g.input(0);\n   \
    \ while (q--){\n        int u, v, k; in(u,v,k);\n        out(g.jump(u,v,k));\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\"\
    ../../template/template.hpp\"\n#include\"../../tree/tree_query.hpp\"\n\nint main(){\n\
    \    int n, q; in(n,q);\n    Tree g(n);\n    g.input(0);\n    while (q--){\n \
    \       int u, v, k; in(u,v,k);\n        out(g.jump(u,v,k));\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - tree/tree_query.hpp
  isVerificationFile: true
  path: test/tree/Jump_on_Tree_hld.test.cpp
  requiredBy: []
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Jump_on_Tree_hld.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Jump_on_Tree_hld.test.cpp
- /verify/test/tree/Jump_on_Tree_hld.test.cpp.html
title: test/tree/Jump_on_Tree_hld.test.cpp
---
