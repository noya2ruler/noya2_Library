---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Diameter.test.cpp
    title: test/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/Tree_core.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,n) for (int i = 0; i < (int)(n);\
    \ i++)\n#define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n#define all(v)\
    \ v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\nusing ull\
    \ = unsigned long long;\n\nusing namespace std;\n\nnamespace noya2{\n\n/*\u3000\
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\ntemplate <typename\
    \ T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n\
    \    return true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n \
    \   if (a >= b) return false;\n    a = b;\n    return true;\n}\n\ntemplate<class\
    \ T>istream &operator>>(istream &is, vector<T> &v){\n    for (auto &e : v) is\
    \ >> e;\n    return is;\n}\n\nvoid fast_io(){\n    cin.tie(0); ios::sync_with_stdio(0);\
    \ cout << fixed << setprecision(15);\n}\n\nconst int iinf = 1'000'000'007;\nconst\
    \ ll linf = 2e18;\n#line 4 \"tree/Tree_core.hpp\"\n\nnamespace noya2{\n\nstruct\
    \ naiveTree { // undirected unweighted tree\n    naiveTree (int _n = 0) : n(_n){\n\
    \        es0.resize(_n);\n        es1.resize(_n);\n    }\n    void add_edge(int\
    \ u, int v, int id = -1){\n        es0[u].emplace_back(v);\n        es0[v].emplace_back(u);\n\
    \        es1[u].emplace_back(v,id);\n        es1[v].emplace_back(u,id);\n    }\n\
    \    void input(int _indexed = 1){\n        rep(i,n-1){\n            int u, v;\
    \ cin >> u >> v;\n            u -= _indexed;\n            v -= _indexed;\n   \
    \         add_edge(u,v);\n        }\n    }\n    const vector<int>& operator[](int\
    \ idx) const { return es0[idx]; }\n    const vector<pair<int,int>>& operator()(int\
    \ idx) const {return es1[idx]; }\n  private:\n    int n;\n    vector<vector<int>>\
    \ es0;\n    vector<vector<pair<int,int>>> es1;\n};\n\n\nstruct usefulTree { //\
    \ rooted unweighted tree\n    usefulTree (int _n = 0, int _root = 0) : n(_n),\
    \ root(_root) {\n        es.resize(n);\n    }\n    void add_edge(int u, int v){\n\
    \        es[u].emplace_back(v);\n        es[v].emplace_back(u);\n    }\n    void\
    \ input(int _indexed = 1){\n        rep(i,n-1){\n            int u, v; cin >>\
    \ u >> v;\n            u -= _indexed;\n            v -= _indexed;\n          \
    \  add_edge(u,v);\n        }\n    }\n    const vector<int>& operator[](int idx)\
    \ const { return es[idx]; }\n    int parent(int v){ return par[0][v]; }\n    int\
    \ subtree_size(int v){\n        if (sub[v] != -1) return sub[v];\n        sub[v]\
    \ = 1;\n        for (int child : es[v]){\n            if (child != par[0][v])\
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
    \ noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\
    \nstruct naiveTree { // undirected unweighted tree\n    naiveTree (int _n = 0)\
    \ : n(_n){\n        es0.resize(_n);\n        es1.resize(_n);\n    }\n    void\
    \ add_edge(int u, int v, int id = -1){\n        es0[u].emplace_back(v);\n    \
    \    es0[v].emplace_back(u);\n        es1[u].emplace_back(v,id);\n        es1[v].emplace_back(u,id);\n\
    \    }\n    void input(int _indexed = 1){\n        rep(i,n-1){\n            int\
    \ u, v; cin >> u >> v;\n            u -= _indexed;\n            v -= _indexed;\n\
    \            add_edge(u,v);\n        }\n    }\n    const vector<int>& operator[](int\
    \ idx) const { return es0[idx]; }\n    const vector<pair<int,int>>& operator()(int\
    \ idx) const {return es1[idx]; }\n  private:\n    int n;\n    vector<vector<int>>\
    \ es0;\n    vector<vector<pair<int,int>>> es1;\n};\n\n\nstruct usefulTree { //\
    \ rooted unweighted tree\n    usefulTree (int _n = 0, int _root = 0) : n(_n),\
    \ root(_root) {\n        es.resize(n);\n    }\n    void add_edge(int u, int v){\n\
    \        es[u].emplace_back(v);\n        es[v].emplace_back(u);\n    }\n    void\
    \ input(int _indexed = 1){\n        rep(i,n-1){\n            int u, v; cin >>\
    \ u >> v;\n            u -= _indexed;\n            v -= _indexed;\n          \
    \  add_edge(u,v);\n        }\n    }\n    const vector<int>& operator[](int idx)\
    \ const { return es[idx]; }\n    int parent(int v){ return par[0][v]; }\n    int\
    \ subtree_size(int v){\n        if (sub[v] != -1) return sub[v];\n        sub[v]\
    \ = 1;\n        for (int child : es[v]){\n            if (child != par[0][v])\
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
    \ noya2"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: tree/Tree_core.hpp
  requiredBy: []
  timestamp: '2023-06-30 12:42:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Tree_Diameter.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
documentation_of: tree/Tree_core.hpp
layout: document
redirect_from:
- /library/tree/Tree_core.hpp
- /library/tree/Tree_core.hpp.html
title: tree/Tree_core.hpp
---
