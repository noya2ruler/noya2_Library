---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  - icon: ':heavy_check_mark:'
    path: tree/simple_tree.hpp
    title: tree/simple_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Add_Path_Sum.test.cpp
    title: test/tree/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#line 2 \"tree/simple_tree.hpp\"\
    \n\n#include <iostream>\n#line 2 \"data_structure/csr.hpp\"\n\n#include<vector>\n\
    #include<ranges>\n#include<cassert>\n#include<utility>\n\nnamespace noya2::internal\
    \ {\n\ntemplate<class E>\nstruct csr {\n    csr () {}\n    csr (int _n) : n(_n)\
    \ {}\n    csr (int _n, int m) : n(_n){\n        start.reserve(m);\n        elist.reserve(m);\n\
    \    }\n    // ACL style constructor (do not have to call build)\n    csr (int\
    \ _n, const std::vector<std::pair<int,E>> &idx_elem) : n(_n), start(_n + 2), elist(idx_elem.size())\
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
    \    }\n    size_t size() const {\n        return n;\n    }\n    int n;\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    bool prepared = false;\n};\n\n} // namespace\
    \ noya2::internal\n#line 5 \"tree/simple_tree.hpp\"\n\nnamespace noya2 {\n\nstruct\
    \ simple_tree {\n    internal::csr<int> g;\n    simple_tree () {}\n    simple_tree\
    \ (int _n) : g(_n, (_n - 1)*2) {\n        if (_n == 1){\n            g.build();\n\
    \        }\n    }\n    void add_edge(int u, int v){\n        g.add(u, v);\n  \
    \      int id = g.add(v, u);\n        if (id + 1 == (g.n - 1)*2) g.build();\n\
    \    }\n    void input(int indexed = 1){\n        for (int i = 0; i < g.n - 1;\
    \ i++){\n            int u, v; cin >> u >> v;\n            u -= indexed, v -=\
    \ indexed;\n            add_edge(u, v);\n        }\n    }\n    void input_parents(int\
    \ indexed = 1){\n        for (int i = 0; i < g.n - 1; i++){\n            int v;\
    \ cin >> v;\n            v -= indexed;\n            add_edge(i + 1, v);\n    \
    \    }\n    }\n    const auto operator[](int v) const {\n        return g[v];\n\
    \    }\n    auto operator[](int v){\n        return g[v];\n    }\n    size_t size()\
    \ const {\n        return g.size();\n    }\n};\n\n} // namespace noya2\n#line\
    \ 4 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace noya2 {\n\nstruct hld_tree\
    \ {\n    internal::csr<int> g;\n    hld_tree () {}\n    hld_tree (int _n, int\
    \ _root = 0) : g(_n,(_n - 1)*2), n(_n), root(_root) {\n        if (_n == 1){\n\
    \            build();\n        }\n    }\n    hld_tree (simple_tree _g, int _root\
    \ = 0) : g(_g.g), n(_g.g.n), root(_root){\n        build();\n    }\n\n    size_t\
    \ size() const {\n        return g.n;\n    }\n\n    void add_edge(int u, int v){\n\
    \        g.add(u, v);\n        int id = g.add(v, u);\n        if (id + 1 == (n\
    \ - 1)*2) build();\n    }\n    void input(int indexed = 1){\n        for (int\
    \ i = 0; i < n - 1; i++){\n            int u, v; cin >> u >> v;\n            u\
    \ -= indexed, v -= indexed;\n            add_edge(u, v);\n        }\n    }\n \
    \   void input_parents(int indexed = 1){\n        for (int i = 0; i < n - 1; i++){\n\
    \            int v; cin >> v;\n            v -= indexed;\n            add_edge(i\
    \ + 1, v);\n        }\n    }\n\n    int depth(int v) const {\n        return dep[v];\n\
    \    }\n\n    int parent(int v) const {\n        if (v == root) return -1;\n \
    \       return g[v].back();\n    }\n\n    int degree(int v) const {\n        return\
    \ g[v].size();\n    }\n\n    int subtree_size(int v) const {\n        return sub[v];\n\
    \    }\n\n    // if d > dep[v], return -1\n    int la(int v, int d) const {\n\
    \        while (v != -1){\n            int u = nxt[v];\n            if (down[v]\
    \ - d >= down[u]){\n                v = tour[down[v] - d];\n                break;\n\
    \            }\n            d -= down[v] - down[u] + 1;\n            v = parent(u);\n\
    \        }\n        return v;\n    }\n\n    int lca(int u, int v) const {\n  \
    \      while (nxt[u] != nxt[v]){\n            if (down[u] < down[v]) swap(u,v);\n\
    \            u = parent(nxt[u]);\n        }\n        return dep[u] < dep[v] ?\
    \ u : v;\n    }\n\n    int dist(int u, int v) const {\n        return dep[u] +\
    \ dep[v] - 2*dep[lca(u,v)];\n    }\n\n    // if d > dist(from, to), return -1\n\
    \    int jump(int from, int to, int d) const {\n        int l = lca(from,to);\n\
    \        if (d <= dep[from] - dep[l]){\n            return la(from, d);\n    \
    \    }\n        d -= dep[from] - dep[l];\n        if (d <= dep[to] - dep[l]){\n\
    \            return la(to, dep[to] - dep[l] - d);\n        }\n        return -1;\n\
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
    };\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"simple_tree.hpp\"\n\nnamespace noya2 {\n\nstruct\
    \ hld_tree {\n    internal::csr<int> g;\n    hld_tree () {}\n    hld_tree (int\
    \ _n, int _root = 0) : g(_n,(_n - 1)*2), n(_n), root(_root) {\n        if (_n\
    \ == 1){\n            build();\n        }\n    }\n    hld_tree (simple_tree _g,\
    \ int _root = 0) : g(_g.g), n(_g.g.n), root(_root){\n        build();\n    }\n\
    \n    size_t size() const {\n        return g.n;\n    }\n\n    void add_edge(int\
    \ u, int v){\n        g.add(u, v);\n        int id = g.add(v, u);\n        if\
    \ (id + 1 == (n - 1)*2) build();\n    }\n    void input(int indexed = 1){\n  \
    \      for (int i = 0; i < n - 1; i++){\n            int u, v; cin >> u >> v;\n\
    \            u -= indexed, v -= indexed;\n            add_edge(u, v);\n      \
    \  }\n    }\n    void input_parents(int indexed = 1){\n        for (int i = 0;\
    \ i < n - 1; i++){\n            int v; cin >> v;\n            v -= indexed;\n\
    \            add_edge(i + 1, v);\n        }\n    }\n\n    int depth(int v) const\
    \ {\n        return dep[v];\n    }\n\n    int parent(int v) const {\n        if\
    \ (v == root) return -1;\n        return g[v].back();\n    }\n\n    int degree(int\
    \ v) const {\n        return g[v].size();\n    }\n\n    int subtree_size(int v)\
    \ const {\n        return sub[v];\n    }\n\n    // if d > dep[v], return -1\n\
    \    int la(int v, int d) const {\n        while (v != -1){\n            int u\
    \ = nxt[v];\n            if (down[v] - d >= down[u]){\n                v = tour[down[v]\
    \ - d];\n                break;\n            }\n            d -= down[v] - down[u]\
    \ + 1;\n            v = parent(u);\n        }\n        return v;\n    }\n\n  \
    \  int lca(int u, int v) const {\n        while (nxt[u] != nxt[v]){\n        \
    \    if (down[u] < down[v]) swap(u,v);\n            u = parent(nxt[u]);\n    \
    \    }\n        return dep[u] < dep[v] ? u : v;\n    }\n\n    int dist(int u,\
    \ int v) const {\n        return dep[u] + dep[v] - 2*dep[lca(u,v)];\n    }\n\n\
    \    // if d > dist(from, to), return -1\n    int jump(int from, int to, int d)\
    \ const {\n        int l = lca(from,to);\n        if (d <= dep[from] - dep[l]){\n\
    \            return la(from, d);\n        }\n        d -= dep[from] - dep[l];\n\
    \        if (d <= dep[to] - dep[l]){\n            return la(to, dep[to] - dep[l]\
    \ - d);\n        }\n        return -1;\n    }\n\n    // seg.set(index(v), X[v]);\n\
    \    int index(int vertex) const {\n        return down[vertex];\n    }\n\n  \
    \  int index_from_edge(int u, int v) const {\n        return (dep[u] < dep[v]\
    \ ? down[v] : down[u]);\n    }\n\n    // X[vertex(i)] = seg.get(i);\n    int vertex(int\
    \ index) const {\n        return tour[index];\n    }\n\n    int subtree_l(int\
    \ v) const {\n        return down[v];\n    }\n\n    int subtree_r(int v) const\
    \ {\n        return down[v] + sub[v];\n    }\n\n    // if r == v, return true\n\
    \    bool is_in_subtree(int r, int v) const {\n        return subtree_l(r) <=\
    \ subtree_l(v) && subtree_l(v) < subtree_r(r);\n    }\n\n    bool is_in_path(int\
    \ lv, int mv, int rv) const {\n        return dist(lv,mv) + dist(mv,rv) == dist(lv,rv);\n\
    \    }\n\n    // dist, v1, v2\n    tuple<int,int,int> diameter(){\n        int\
    \ v1 = max_element(dep.begin(),dep.end()) - dep.begin();\n        vector<int>\
    \ dist_from_v1(n,numeric_limits<int>::max());\n        queue<int> que;\n     \
    \   que.push(v1);\n        dist_from_v1[v1] = 0;\n        while (!que.empty()){\n\
    \            int v = que.front(); que.pop();\n            for (int u : g[v]){\n\
    \                if (dist_from_v1[u] > dist_from_v1[v]+1){\n                 \
    \   dist_from_v1[u] = dist_from_v1[v]+1;\n                    que.push(u);\n \
    \               }\n            }\n        }\n        int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end())\
    \ - dist_from_v1.begin();\n        return make_tuple(dist_from_v1[v2],v1,v2);\n\
    \    }\n\n    // vertex array : vector<int> {from, v1, v2, ... , to}\n    vector<int>\
    \ path(int from, int to){\n        int l = lca(from,to);\n        const int sizf\
    \ = dep[from]-dep[l], sizt = dep[to]-dep[l];\n        vector<int> pf = {from},\
    \ pt;\n        pf.reserve(sizf+1); pt.reserve(sizt);\n        for (int i = 0;\
    \ i < sizf; i++){\n            from = parent(from);\n            pf.push_back(from);\n\
    \        }\n        for (int i = 0; i < sizt; i++){\n            pt.push_back(to);\n\
    \            to = parent(to);\n        }\n        pf.insert(pf.end(),pt.rbegin(),pt.rend());\n\
    \        return pf;\n    }\n\n    template<typename F>\n    void path_query(int\
    \ u, int v, bool vertex, const F &f){\n        int l = lca(u,v);\n        for\
    \ (auto [s, t] : ascend(u, l)){\n            f(t, s + 1);\n        }\n       \
    \ if (vertex) f(down[l], down[l] + 1);\n        for (auto [s, t] : descend(l,\
    \ v)){\n            f(s, t + 1);\n        }\n    }\n\n    template<typename F>\n\
    \    void path_noncommutative_query(int u, int v, bool vertex, const F &f){\n\
    \        int l = lca(u,v);\n        for (auto [s, t] : ascend(u, l)){\n      \
    \      f(s + 1, t); // l > r ok\n        }\n        if (vertex) f(down[l],down[l]\
    \ + 1);\n        for (auto [s, t] : descend(l, v)){\n            f(s, t + 1);\
    \ // l > r ok\n        }\n    }\n\n    template<typename F>\n    void subtree_query(int\
    \ v, bool vertex, const F &f){\n        f(down[v] + (vertex ? 0 : 1), down[v]\
    \ + sub[v]);\n    }\n\n    // adjacent to v\n    const auto operator[](int v)\
    \ const {\n        return g[v];\n    }\n    auto operator[](int v){\n        return\
    \ g[v];\n    }\n\n    // only child\n    const auto operator()(int v) const {\n\
    \        return g(v, 0, degree(v) - (v == root ? 0 : 1));\n    }\n    auto operator()(int\
    \ v){\n        return g(v, 0, degree(v) - (v == root ? 0 : 1));\n    }\n\n  private:\n\
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
    };\n\n} // namespace noya2"
  dependsOn:
  - tree/simple_tree.hpp
  - data_structure/csr.hpp
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2024-10-30 04:43:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Vertex_Add_Path_Sum.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
title: "\u5168\u90E8\u8F09\u305B\u6728"
---

# `hld_tree`

根付き木に関する大抵のことが行えるライブラリを目指す。

頂点数を $n$ とすると、頂点番号は $0,1,\dots ,n-1$ で管理される。

空間計算量は全体で $\Theta(n)$ である。より正確には、（圧縮木の構築を行わない場合）合計で長さ $8n+\Theta(1)$ の `vector<int>` を使用する。

重軽分解を基本とした実装を行なっている。

グラフは隣接リストで保持されるが、二次元配列 `vector<vector<int>>` ではなく `noya2::internal::csr<int>` による一次元に圧縮した配列を利用している。

## (constructor)

```cpp
hld_tree (); // ... (1)
hld_tree (int n, int root = 0); // ... (2)
hld_tree (simple_tree g, int root = 0) // ... (3)
```

### 概要

`hld_tree` オブジェクトを次に示す通りの要素で初期化し、構築する。

### 効果

- (1) : デフォルトコンストラクタ。なにもしない。特に、意味のある木を構築しない。
- (2) : 頂点数が `n` の、`root` を根とする根付き木を、辺がない状態で構築する。辺は `add_edge` によって追加する。
- (3) : 木構造が `g` であり、`root` を根とする根付き木を構築する。`build` が呼ばれる。

### 計算量

- (1) : $\Theta (1)$
- (2) : $\Theta (n)$
- (3) : $\Theta (n)$ (ここで $n$ は木構造 `g` の頂点数)

### 備考

- (1) はグローバルに `hld_tree` を置いておくときに使える。`main` 内部で初期化を行うが、グローバルに置いた関数で木の操作を行うときなど。

```cpp
hld_tree g;

int calc(int v){
    return g.depth(v);
}

int main(){
    int n; cin >> n; // 木 g の頂点数を入力
    g = hld_tree(n); // g を (2) の方法で初期化(代入)
    g.input(); // 木を入力
    cout << calc(n-1) << endl; // 頂点 n-1 の深さを出力
}
```

- (1) の方法で初期化されたオブジェクトに対して、どのメンバ関数も呼び出してはならない。宣言後に (2),(3) によって構築されたオブジェクトの代入が行われることを想定している。

- (3) は木構造 `simple_tree` を得ている場合にそのまま `hld_tree` にするためのコンストラクタである。`hld_tree::compressed_tree` は `simple_tree` を継承しているが、`hld_tree` の機能を持っていない。そのような場合に `add_edge` を経由せずに簡単に `hld_tree` を構築するための機能である。

## add_edge

```cpp
void add_edge(int u, int v);
```

### 概要

頂点 `u`, `v` を結ぶ（無向）辺を追加する。

### 要件

- $0\le u, v\lt n$
- コンストラクタ (2) で構築した場合、この関数はちょうど $n-1$ 回呼ばれる。
  - `input`, `input_parents` を読んだ場合は、内部で $n-1$ 回の `add_edge` が呼ばれる。
- $n-1$ 回呼ばれた後、グラフは木になっている。

### 計算量

償却定数時間。 $n-1$ 回の呼び出しに対して、内部での `build` の処理も含めて合計で $\Theta(n)$ 時間である。

### 備考

この関数が $n-1$ 回呼ばれたとき、内部で自動的に `build` が呼ばれる。それまでに辺の追加以外の関数を呼び出してはならない。
なお、`build` は `private` 指定されており、外部から直接呼び出すことはできない。

## input, input_parents

```cpp
void input(int indexed = 1); // ... (1)
void input_parents(int indexed = 1); // ... (2)
```

### 概要

辺の情報を標準入力から受け取って、辺を追加する。入力される頂点番号は `indexed, indexed+1, ..., indexed+n-1` のいずれかとする。

### 効果

- (1) : 木の構造が、 $i$ 番目の辺が頂点 $u_i,v_i$ を結ぶとして、以下の形式で与えられるとする。これらの入力を受け取って、辺をすべて `add_edge` に投げる。
> $u_1$ $v_1$
> 
> $u_2$ $v_2$
> 
> $\vdots$
>
> $u_{n-1}$ $v_{n-1}$

- (2) : 木の構造が、 根を `root` としたときの頂点 $i$ の親が頂点 $p_i$ として、以下の形式で与えられるとする。これらの入力を受け取って、辺の情報 $(i,p_i)$ に変換して、辺をすべて `add_edge` に投げる。 $i$ は 0_indexed であるが、入力 $p_i$ は指定した `indexed`_indexed である。
> $p_1$ $p_2$ $p_{n-1}$

### 計算量

- (1),(2) : $\Theta (n)$

### 備考

入力は `std::cin >>` によって受け取られる。入力を別の方法で行いたい場合は、入力と辺の追加は切り離し、辺の追加を `add_edge` で行うことができる。

木構造の指定方法は以下の $4$ つに限られる。

- コンストラクタ (3) による構築
- `add_edge` を $n-1$ 回呼ぶ
- `input` を $1$ 回呼ぶ
- `input_parents` を $1$ 回呼ぶ

どの方法でも木構造を指定できるが、複数の方法で行うことはできない。

