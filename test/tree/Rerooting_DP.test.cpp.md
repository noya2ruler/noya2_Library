---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/RerootingDP.hpp
    title: Rerooting DP
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1976
    links:
    - https://yukicoder.me/problems/no/1976
  bundledCode: "#line 1 \"test/tree/Rerooting_DP.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1976\"\
    \n\n#line 2 \"tree/RerootingDP.hpp\"\n\n#line 2 \"template/template.hpp\"\n\n\
    #include<bits/stdc++.h>\n\n#define rep(i,n) for (int i = 0; i < (int)(n); i++)\n\
    #define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n#define all(v) v.begin(),v.end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    \nusing namespace std;\n\nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000\
    */\n\n}\n\nusing namespace noya2;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\ntemplate<class T>istream &operator>>(istream\
    \ &is, vector<T> &v){\n    for (auto &e : v) is >> e;\n    return is;\n}\n\nvoid\
    \ fast_io(){\n    cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(15);\n\
    }\n\nconst int iinf = 1'000'000'007;\nconst ll linf = 2e18;\n#line 4 \"tree/RerootingDP.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate <class E, class V, E (*merge)(E, E), E (*e)(),\
    \ E (*put_edge)(V, int), V (*put_vertex)(E, int)>\nstruct RerootingDP {\n    struct\
    \ edge {\n        int to, idx, xdi;\n    };\n    RerootingDP(int _n = 0) : n(_n)\
    \ {\n        es.resize(n);\n    }\n    void add_edge(int u, int v, int idx1, int\
    \ idx2) {\n        es[u].push_back({v, idx1, idx2});\n        es[v].push_back({u,\
    \ idx2, idx1});\n    }\n    vector<V> build(int v = 0) {\n        root = v;\n\
    \        outs.resize(n);\n        subdp.resize(n);\n        in.resize(n), up.resize(n);\n\
    \        int tnow = 0;\n        dfs(root, -1, tnow);\n        return subdp;\n\
    \    }\n    vector<V> reroot() {\n        reverse_edge.resize(n);\n        reverse_edge[root]\
    \ = e();\n        reverse_dp.resize(n);\n        answers.resize(n);\n        bfs(root);\n\
    \        return answers;\n    }\n    V get(int r, int v) {\n        if (r == v)\
    \ return answers[r];\n        if (!(in[v] < in[r] && up[r] <= up[v])) return subdp[v];\n\
    \        int le = 0, ri = outs[v].size();\n        while (ri - le > 1) {\n   \
    \         int md = (le + ri) / 2;\n            if (in[es[v][md].to] <= in[r])\n\
    \                le = md;\n            else\n                ri = md;\n      \
    \  }\n        return reverse_dp[es[v][le].to];\n    }\n    const vector<edge>\
    \ &operator[](int idx) const {\n        return es[idx];\n    }\n\n  private:\n\
    \    int n, root;\n    vector<vector<edge>> es;\n    vector<vector<E>> outs;\n\
    \    vector<E> reverse_edge;\n    vector<V> subdp, reverse_dp, answers;\n    vector<int>\
    \ in, up;\n    void dfs(int v, int p, int &t) {\n        E val = e();\n      \
    \  in[v] = t++;\n        for (auto &u : es[v]) {\n            if (u.to == p &&\
    \ u.to != es[v].back().to) swap(u, es[v].back());\n            if (u.to == p)\
    \ continue;\n            dfs(u.to, v, t);\n            E nval = put_edge(subdp[u.to],\
    \ u.idx);\n            outs[v].emplace_back(nval);\n            val = merge(val,\
    \ nval);\n        }\n        subdp[v] = put_vertex(val, v);\n        up[v] = t;\n\
    \    }\n    void bfs(int v) {\n        int siz = outs[v].size();\n        vector<E>\
    \ lui(siz + 1), rui(siz + 1);\n        lui[0] = e(), rui[siz] = e();\n       \
    \ for (int i = 0; i < siz; i++) lui[i + 1] = merge(lui[i], outs[v][i]);\n    \
    \    for (int i = siz - 1; i >= 0; i--) rui[i] = merge(outs[v][i], rui[i + 1]);\n\
    \        for (int i = 0; i < siz; i++) {\n            reverse_dp[es[v][i].to]\
    \ = put_vertex(merge(merge(lui[i], rui[i + 1]), reverse_edge[v]), v);\n      \
    \      reverse_edge[es[v][i].to] = put_edge(reverse_dp[es[v][i].to], es[v][i].xdi);\n\
    \            bfs(es[v][i].to);\n        }\n        answers[v] = put_vertex(merge(lui[siz],\
    \ reverse_edge[v]), v);\n    }\n};\n\n}  // namespace noya2\n#line 4 \"test/tree/Rerooting_DP.test.cpp\"\
    \n\n#line 6 \"test/tree/Rerooting_DP.test.cpp\"\n\n\nusing P = pair<int, int>;\n\
    P merge(P a, P b) {\n    return P(max(max(a.first, b.first), a.second + b.second),\n\
    \             max(a.second, b.second));\n}\nP e() {\n    return P(0, 0);\n}\n\
    P pute(P v, int id) {\n    return P(max(v.first, v.second + 1), v.second + 1);\n\
    }\nP putv(P e, int id) {\n    return e;\n}\n\nint main() {\n    int n;\n    cin\
    \ >> n;\n    RerootingDP<P, P, merge, e, pute, putv> g(n);\n    for (int i = 0;\
    \ i < n - 1; i++) {\n        int u, v;\n        cin >> u >> v;\n        u--, v--;\n\
    \        g.add_edge(u, v, i, i);\n    }\n    g.build();\n    g.reroot();\n   \
    \ int ans = n;\n    for (int u = 0; u < n; u++) {\n        for (auto [v, idx,\
    \ dxi] : g[u]) {\n            int x = g.get(u, v).first;\n            int y =\
    \ g.get(v, u).first;\n            ans = min(ans, max({x, y, (x + 1) / 2 + (y +\
    \ 1) / 2 + 1}));\n        }\n    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1976\"\n\n#include \"\
    ../../tree/RerootingDP.hpp\"\n\n#include \"../../template/template.hpp\"\n\n\n\
    using P = pair<int, int>;\nP merge(P a, P b) {\n    return P(max(max(a.first,\
    \ b.first), a.second + b.second),\n             max(a.second, b.second));\n}\n\
    P e() {\n    return P(0, 0);\n}\nP pute(P v, int id) {\n    return P(max(v.first,\
    \ v.second + 1), v.second + 1);\n}\nP putv(P e, int id) {\n    return e;\n}\n\n\
    int main() {\n    int n;\n    cin >> n;\n    RerootingDP<P, P, merge, e, pute,\
    \ putv> g(n);\n    for (int i = 0; i < n - 1; i++) {\n        int u, v;\n    \
    \    cin >> u >> v;\n        u--, v--;\n        g.add_edge(u, v, i, i);\n    }\n\
    \    g.build();\n    g.reroot();\n    int ans = n;\n    for (int u = 0; u < n;\
    \ u++) {\n        for (auto [v, idx, dxi] : g[u]) {\n            int x = g.get(u,\
    \ v).first;\n            int y = g.get(v, u).first;\n            ans = min(ans,\
    \ max({x, y, (x + 1) / 2 + (y + 1) / 2 + 1}));\n        }\n    }\n    cout <<\
    \ ans << endl;\n}"
  dependsOn:
  - tree/RerootingDP.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/tree/Rerooting_DP.test.cpp
  requiredBy: []
  timestamp: '2023-06-30 12:42:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Rerooting_DP.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Rerooting_DP.test.cpp
- /verify/test/tree/Rerooting_DP.test.cpp.html
title: test/tree/Rerooting_DP.test.cpp
---
