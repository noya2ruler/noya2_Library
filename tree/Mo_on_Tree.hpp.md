---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/pakencamp-2022-day1/submissions/43052952
  bundledCode: "#line 2 \"tree/Mo_on_Tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ ll linf = 2e18;\n#line 2 \"misc/mo_algorithm.hpp\"\n\n/*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
    \n*/\n\n#line 10 \"misc/mo_algorithm.hpp\"\n\nnamespace noya2{\n\nstruct Mo {\n\
    \    int width;\n    std::vector<int> left, right, order;\n\n    Mo(int N = 1,\
    \ int Q = 1): order(Q) {\n        width = std::max<int>(1, 1.0 * N / std::max<double>(1.0,\
    \ std::sqrt(Q * 2.0 / 3.0)));\n        std::iota(begin(order), end(order), 0);\n\
    \    }\n\n    void insert(int l, int r) { /* [l, r) */\n        left.emplace_back(l);\n\
    \        right.emplace_back(r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename DL, typename DR, typename REM>\n    void run(const AL& add_left,\
    \ const AR& add_right, const DL& delete_left,\n        const DR& delete_right,\
    \ const REM& rem) {\n        assert(left.size() == order.size());\n        sort(begin(order),\
    \ end(order), [&](int a, int b) {\n            int ablock = left[a] / width, bblock\
    \ = left[b] / width;\n            if (ablock != bblock) return ablock < bblock;\n\
    \            if (ablock & 1) return right[a] < right[b];\n            return right[a]\
    \ > right[b];\n            });\n        int nl = 0, nr = 0;\n        for (auto\
    \ idx : order) {\n            while (nl > left[idx]) add_left(--nl);\n       \
    \     while (nr < right[idx]) add_right(nr++);\n            while (nl < left[idx])\
    \ delete_left(nl++);\n            while (nr > right[idx]) delete_right(--nr);\n\
    \            rem(idx);\n        }\n    }\n};\n\n}\n#line 5 \"tree/Mo_on_Tree.hpp\"\
    \n\n/*\n\nMoTree_edge is verified with : https://atcoder.jp/contests/pakencamp-2022-day1/submissions/43052952\n\
    \n*/\n\nnamespace noya2{\n\ntemplate<class T>\nstruct MoTree_edge {\n    int n;\n\
    \    vector<vector<pair<int,T>>> es;\n    MoTree_edge (int _n) : n(_n) {\n   \
    \     es.resize(n);\n    }\n    void add_edge(int u, int v, T w){\n        es[u].emplace_back(v,w);\n\
    \        es[v].emplace_back(u,w);\n    }\n    vector<int> in;\n    vector<pair<int,T>>\
    \ vals;\n    Mo mo;\n    void build(int q){\n        int tnow = 0;\n        auto\
    \ dfs = [&](auto dfs, int v, int f) -> void {\n            in[v] = tnow++;\n \
    \           for (auto [u, w] : es[v]){\n                if (u == f) continue;\n\
    \                vals.emplace_back(u,w);\n                dfs(dfs,u,v);\n    \
    \            vals.emplace_back(u,w);\n                tnow++;\n            }\n\
    \        };\n        in.resize(n);\n        dfs(dfs,0,-1);\n        mo = Mo(2*n-2,q);\n\
    \    }\n    void insert(int u, int v){\n        u = in[u], v = in[v];\n      \
    \  if (u > v) swap(u,v);\n        mo.insert(u,v);\n    }\n    template<typename\
    \ ADD, typename DEL, typename REM>\n    void run(const ADD &add, const DEL &del,\
    \ const REM &rem){\n        vector<bool> contain(n,false);\n        auto change\
    \ = [&](int i){\n            int id = vals[i].first;\n            if (contain[id]){\n\
    \                del(vals[i].second);\n                contain[id] = false;\n\
    \            }\n            else {\n                add(vals[i].second);\n   \
    \             contain[id] = true;\n            }\n        };\n        mo.run(change,change,change,change,rem);\n\
    \    }\n};\n\n\ntemplate<class T>\nstruct MoTree_vertex {\n    int n;\n    vector<vector<int>>\
    \ es;\n    vector<T> b;\n    MoTree_vertex (int _n, vector<T> _b) : n(_n), b(_b)\
    \ {\n        es.resize(n);\n    }\n    void add_edge(int u, int v){\n        es[u].emplace_back(v);\n\
    \        es[v].emplace_back(u);\n    }\n    vector<int> in;\n    vector<pair<int,T>>\
    \ vals;\n    vector<int> lcas;\n    Mo mo;\n    void build(int q){\n        vals.reserve(2*n-2);\n\
    \        lcas.reserve(q);\n        int tnow = 0;\n        auto dfs = [&](auto\
    \ dfs, int v, int f) -> void {\n            in[v] = tnow++;\n            for (auto\
    \ u : es[v]){\n                if (u == f) continue;\n                vals.emplace_back(u,b[u]);\n\
    \                dfs(dfs,u,v);\n                vals.emplace_back(u,b[u]);\n \
    \               tnow++;\n            }\n        };\n        in.resize(n);\n  \
    \      dfs(dfs,0,-1);\n        mo = Mo(2*n-2,q);\n    }\n    \n    void insert(int\
    \ u, int v, int lca){\n        u = in[u], v = in[v];\n        if (u > v) swap(u,v);\n\
    \        mo.insert(u,v);\n        lcas.push_back(lca);\n    }\n    template<typename\
    \ ADD, typename DEL, typename REM>\n    void run(const ADD &add, const DEL &del,\
    \ const REM &rem){\n        vector<bool> contain(n,false);\n        auto change\
    \ = [&](int i){\n            int id = vals[i].first;\n            if (contain[id]){\n\
    \                del(vals[i].second);\n                contain[id] = false;\n\
    \            }\n            else {\n                add(vals[i].second);\n   \
    \             contain[id] = true;\n            }\n        };\n        auto rem_add_lca\
    \ = [&](int i){\n            add(b[lcas[i]]);\n            rem(i);\n         \
    \   del(b[lcas[i]]);\n        };\n        mo.run(change,change,change,change,rem_add_lca);\n\
    \    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../misc/mo_algorithm.hpp\"\
    \n\n/*\n\nMoTree_edge is verified with : https://atcoder.jp/contests/pakencamp-2022-day1/submissions/43052952\n\
    \n*/\n\nnamespace noya2{\n\ntemplate<class T>\nstruct MoTree_edge {\n    int n;\n\
    \    vector<vector<pair<int,T>>> es;\n    MoTree_edge (int _n) : n(_n) {\n   \
    \     es.resize(n);\n    }\n    void add_edge(int u, int v, T w){\n        es[u].emplace_back(v,w);\n\
    \        es[v].emplace_back(u,w);\n    }\n    vector<int> in;\n    vector<pair<int,T>>\
    \ vals;\n    Mo mo;\n    void build(int q){\n        int tnow = 0;\n        auto\
    \ dfs = [&](auto dfs, int v, int f) -> void {\n            in[v] = tnow++;\n \
    \           for (auto [u, w] : es[v]){\n                if (u == f) continue;\n\
    \                vals.emplace_back(u,w);\n                dfs(dfs,u,v);\n    \
    \            vals.emplace_back(u,w);\n                tnow++;\n            }\n\
    \        };\n        in.resize(n);\n        dfs(dfs,0,-1);\n        mo = Mo(2*n-2,q);\n\
    \    }\n    void insert(int u, int v){\n        u = in[u], v = in[v];\n      \
    \  if (u > v) swap(u,v);\n        mo.insert(u,v);\n    }\n    template<typename\
    \ ADD, typename DEL, typename REM>\n    void run(const ADD &add, const DEL &del,\
    \ const REM &rem){\n        vector<bool> contain(n,false);\n        auto change\
    \ = [&](int i){\n            int id = vals[i].first;\n            if (contain[id]){\n\
    \                del(vals[i].second);\n                contain[id] = false;\n\
    \            }\n            else {\n                add(vals[i].second);\n   \
    \             contain[id] = true;\n            }\n        };\n        mo.run(change,change,change,change,rem);\n\
    \    }\n};\n\n\ntemplate<class T>\nstruct MoTree_vertex {\n    int n;\n    vector<vector<int>>\
    \ es;\n    vector<T> b;\n    MoTree_vertex (int _n, vector<T> _b) : n(_n), b(_b)\
    \ {\n        es.resize(n);\n    }\n    void add_edge(int u, int v){\n        es[u].emplace_back(v);\n\
    \        es[v].emplace_back(u);\n    }\n    vector<int> in;\n    vector<pair<int,T>>\
    \ vals;\n    vector<int> lcas;\n    Mo mo;\n    void build(int q){\n        vals.reserve(2*n-2);\n\
    \        lcas.reserve(q);\n        int tnow = 0;\n        auto dfs = [&](auto\
    \ dfs, int v, int f) -> void {\n            in[v] = tnow++;\n            for (auto\
    \ u : es[v]){\n                if (u == f) continue;\n                vals.emplace_back(u,b[u]);\n\
    \                dfs(dfs,u,v);\n                vals.emplace_back(u,b[u]);\n \
    \               tnow++;\n            }\n        };\n        in.resize(n);\n  \
    \      dfs(dfs,0,-1);\n        mo = Mo(2*n-2,q);\n    }\n    \n    void insert(int\
    \ u, int v, int lca){\n        u = in[u], v = in[v];\n        if (u > v) swap(u,v);\n\
    \        mo.insert(u,v);\n        lcas.push_back(lca);\n    }\n    template<typename\
    \ ADD, typename DEL, typename REM>\n    void run(const ADD &add, const DEL &del,\
    \ const REM &rem){\n        vector<bool> contain(n,false);\n        auto change\
    \ = [&](int i){\n            int id = vals[i].first;\n            if (contain[id]){\n\
    \                del(vals[i].second);\n                contain[id] = false;\n\
    \            }\n            else {\n                add(vals[i].second);\n   \
    \             contain[id] = true;\n            }\n        };\n        auto rem_add_lca\
    \ = [&](int i){\n            add(b[lcas[i]]);\n            rem(i);\n         \
    \   del(b[lcas[i]]);\n        };\n        mo.run(change,change,change,change,rem_add_lca);\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - misc/mo_algorithm.hpp
  isVerificationFile: false
  path: tree/Mo_on_Tree.hpp
  requiredBy: []
  timestamp: '2023-06-30 13:53:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/Mo_on_Tree.hpp
layout: document
redirect_from:
- /library/tree/Mo_on_Tree.hpp
- /library/tree/Mo_on_Tree.hpp.html
title: tree/Mo_on_Tree.hpp
---
