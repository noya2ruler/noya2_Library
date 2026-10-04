---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/Jump_on_Tree_hld.test.cpp
    title: test/tree/Jump_on_Tree_hld.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_query.hpp\"\n\n#include<vector>\n#include<cassert>\n\
    #include<iostream>\n#include<limits>\n#include<algorithm>\n#include<queue>\n#include<ranges>\n\
    \nstruct Tree {\n    Tree (int n_ = 0, int root_ = 0) : n(n_), root(root_), inner_edge_id(0),\
    \ es(n-1), start(n+1,0){\n        if (n == 1) build();\n    }\n    void add_edge(int\
    \ u, int v){\n        es[inner_edge_id] = u, start[inner_edge_id] = v;\n     \
    \   if (++inner_edge_id == n-1) build();\n    }\n    void input(int indexed =\
    \ 1){\n        for (int i = 0; i < n-1; i++){\n            int u, v; std::cin\
    \ >> u >> v;\n            u -= indexed, v -= indexed;\n            add_edge(u,v);\n\
    \        }\n    }\n    void input_parents(int indexed = 1){\n        for (int\
    \ i = 0; i < n-1; i++){\n            int p; std::cin >> p;\n            p -= indexed;\n\
    \            add_edge(p,i+1);\n        }\n    }\n    int degree(int v){\n    \
    \    assert(0 <= v && v < n);\n        return start[v+1] - start[v];\n    }\n\
    \    int parent(int v){\n        assert(0 <= v && v < n);\n        if (v == root)\
    \ return -1;\n        return es[start[v]];\n    }\n    int subtree_size(int v){\n\
    \        assert(0 <= v && v < n);\n        return sub[v];\n    }\n    int depth(int\
    \ v){\n        assert(0 <= v && v < n);\n        return dep[v];\n    }\n    int\
    \ la(int v, int d){\n        assert(0 <= v && v < n);\n        while (v != -1){\n\
    \            int u = nxt[v];\n            if (down[v] - d >= down[u]){\n     \
    \           v = tour[down[v] - d];\n                break;\n            }\n  \
    \          d -= down[v] - down[u] + 1;\n            v = parent(u);\n        }\n\
    \        return v;\n    }\n    int lca(int u, int v){\n        assert(0 <= v &&\
    \ v < n && 0 <= u && u < n);\n        while (nxt[u] != nxt[v]){\n            if\
    \ (down[u] < down[v]) std::swap(u,v);\n            u = es[start[nxt[u]]];\n  \
    \      }\n        return dep[u] < dep[v] ? u : v;\n    }\n    int jump(int from,\
    \ int to, int d){\n        int l = lca(from,to);\n        if (d <= dep[from] -\
    \ dep[l]){\n            return la(from,d);\n        }\n        d -= dep[from]\
    \ - dep[l];\n        if (d <= dep[to] - dep[l]){\n            return la(to,dep[to]-dep[l]-d);\n\
    \        }\n        return -1;\n    }\n    int dist(int u, int v){ return dep[lca(u,v)]*(-2)\
    \ + dep[u] + dep[v]; }\n    std::vector<int> path(int from, int to){\n       \
    \ int l = lca(from,to);\n        const int sizf = dep[from]-dep[l], sizt = dep[to]-dep[l];\n\
    \        std::vector<int> pf = {from}, pt;\n        pf.reserve(sizf+1); pt.reserve(sizt);\n\
    \        for (int i = 0; i < sizf; i++){\n            from = parent(from);\n \
    \           pf.push_back(from);\n        }\n        for (int i = 0; i < sizt;\
    \ i++){\n            pt.push_back(to);\n            to = parent(to);\n       \
    \ }\n        pf.insert(pf.end(),pt.rbegin(),pt.rend());\n        return pf;\n\
    \    }\n    // dist, v1, v2\n    std::tuple<int,int,int> diameter(){\n       \
    \ int v1 = std::max_element(dep.begin(),dep.end()) - dep.begin();\n        std::vector<int>\
    \ dist_from_v1(n,std::numeric_limits<int>::max());\n        std::queue<int> que;\n\
    \        que.push(v1);\n        dist_from_v1[v1] = 0;\n        while (!que.empty()){\n\
    \            int p = que.front(); que.pop();\n            for (int i = start[p];\
    \ i < start[p+1]; i++){\n                if (dist_from_v1[es[i]] > dist_from_v1[p]+1){\n\
    \                    dist_from_v1[es[i]] = dist_from_v1[p]+1;\n              \
    \      que.push(es[i]);\n                }\n            }\n        }\n       \
    \ int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();\n\
    \        return std::make_tuple(dist_from_v1[v2],v1,v2);\n    }\n    const auto\
    \ operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\
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
    \    std::vector<int> es, start, dep, sub, down, tour, nxt;\n};\n"
  code: "#pragma once\n\n#include<vector>\n#include<cassert>\n#include<iostream>\n\
    #include<limits>\n#include<algorithm>\n#include<queue>\n#include<ranges>\n\nstruct\
    \ Tree {\n    Tree (int n_ = 0, int root_ = 0) : n(n_), root(root_), inner_edge_id(0),\
    \ es(n-1), start(n+1,0){\n        if (n == 1) build();\n    }\n    void add_edge(int\
    \ u, int v){\n        es[inner_edge_id] = u, start[inner_edge_id] = v;\n     \
    \   if (++inner_edge_id == n-1) build();\n    }\n    void input(int indexed =\
    \ 1){\n        for (int i = 0; i < n-1; i++){\n            int u, v; std::cin\
    \ >> u >> v;\n            u -= indexed, v -= indexed;\n            add_edge(u,v);\n\
    \        }\n    }\n    void input_parents(int indexed = 1){\n        for (int\
    \ i = 0; i < n-1; i++){\n            int p; std::cin >> p;\n            p -= indexed;\n\
    \            add_edge(p,i+1);\n        }\n    }\n    int degree(int v){\n    \
    \    assert(0 <= v && v < n);\n        return start[v+1] - start[v];\n    }\n\
    \    int parent(int v){\n        assert(0 <= v && v < n);\n        if (v == root)\
    \ return -1;\n        return es[start[v]];\n    }\n    int subtree_size(int v){\n\
    \        assert(0 <= v && v < n);\n        return sub[v];\n    }\n    int depth(int\
    \ v){\n        assert(0 <= v && v < n);\n        return dep[v];\n    }\n    int\
    \ la(int v, int d){\n        assert(0 <= v && v < n);\n        while (v != -1){\n\
    \            int u = nxt[v];\n            if (down[v] - d >= down[u]){\n     \
    \           v = tour[down[v] - d];\n                break;\n            }\n  \
    \          d -= down[v] - down[u] + 1;\n            v = parent(u);\n        }\n\
    \        return v;\n    }\n    int lca(int u, int v){\n        assert(0 <= v &&\
    \ v < n && 0 <= u && u < n);\n        while (nxt[u] != nxt[v]){\n            if\
    \ (down[u] < down[v]) std::swap(u,v);\n            u = es[start[nxt[u]]];\n  \
    \      }\n        return dep[u] < dep[v] ? u : v;\n    }\n    int jump(int from,\
    \ int to, int d){\n        int l = lca(from,to);\n        if (d <= dep[from] -\
    \ dep[l]){\n            return la(from,d);\n        }\n        d -= dep[from]\
    \ - dep[l];\n        if (d <= dep[to] - dep[l]){\n            return la(to,dep[to]-dep[l]-d);\n\
    \        }\n        return -1;\n    }\n    int dist(int u, int v){ return dep[lca(u,v)]*(-2)\
    \ + dep[u] + dep[v]; }\n    std::vector<int> path(int from, int to){\n       \
    \ int l = lca(from,to);\n        const int sizf = dep[from]-dep[l], sizt = dep[to]-dep[l];\n\
    \        std::vector<int> pf = {from}, pt;\n        pf.reserve(sizf+1); pt.reserve(sizt);\n\
    \        for (int i = 0; i < sizf; i++){\n            from = parent(from);\n \
    \           pf.push_back(from);\n        }\n        for (int i = 0; i < sizt;\
    \ i++){\n            pt.push_back(to);\n            to = parent(to);\n       \
    \ }\n        pf.insert(pf.end(),pt.rbegin(),pt.rend());\n        return pf;\n\
    \    }\n    // dist, v1, v2\n    std::tuple<int,int,int> diameter(){\n       \
    \ int v1 = std::max_element(dep.begin(),dep.end()) - dep.begin();\n        std::vector<int>\
    \ dist_from_v1(n,std::numeric_limits<int>::max());\n        std::queue<int> que;\n\
    \        que.push(v1);\n        dist_from_v1[v1] = 0;\n        while (!que.empty()){\n\
    \            int p = que.front(); que.pop();\n            for (int i = start[p];\
    \ i < start[p+1]; i++){\n                if (dist_from_v1[es[i]] > dist_from_v1[p]+1){\n\
    \                    dist_from_v1[es[i]] = dist_from_v1[p]+1;\n              \
    \      que.push(es[i]);\n                }\n            }\n        }\n       \
    \ int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();\n\
    \        return std::make_tuple(dist_from_v1[v2],v1,v2);\n    }\n    const auto\
    \ operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\
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
    \    std::vector<int> es, start, dep, sub, down, tour, nxt;\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree_query.hpp
  requiredBy: []
  timestamp: '2023-09-22 14:25:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/Jump_on_Tree_hld.test.cpp
documentation_of: tree/tree_query.hpp
layout: document
redirect_from:
- /library/tree/tree_query.hpp
- /library/tree/tree_query.hpp.html
title: tree/tree_query.hpp
---
