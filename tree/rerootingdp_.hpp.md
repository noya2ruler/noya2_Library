---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/rerootingdp_.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <ranges>\n\nnamespace noya2 {\n\n// g[from] contains outgoing edges (to,\
    \ edgeid(from, to))\n// (E, op, e) is commutative monoid\n// ~edgeid(from, to)\
    \ == edgeid(to, from)\n// return calculator of dp(r, v)\ntemplate<class V, class\
    \ E>\nauto rerootingdp(auto op, E e, auto put_edge, auto put_vertex, const std::vector<std::vector<std::pair<int,\
    \ int>>> &g, int root = 0){\n    struct dp {\n        // dp(r, v) : root is r,\
    \ dp of subtree v\n        // ans[v]  = dp(v, v)\n        // from[v] = dp(v, par(v))\n\
    \        // to[v]   = dp(par(v), v)\n        // from[root] and to[root] is undefined\n\
    \        std::vector<V> ans, from, to;\n        std::vector<int> down, up;\n \
    \       std::vector<std::vector<int>> childs;\n        bool is_in_subtree(int\
    \ r, int v){\n            return down[r] < down[v] && up[v] <= up[r];\n      \
    \  }\n        V operator()(int r, int v){\n            if (r == v) return ans[v];\n\
    \            if (!is_in_subtree(v, r)) return to[v];\n            int le = 0,\
    \ ri = childs[v].size();\n            while (ri - le > 1){\n                int\
    \ md = (le + ri) / 2;\n                if (down[childs[v][md]] <= down[r]){\n\
    \                    le = md;\n                }\n                else {\n   \
    \                 ri = md;\n                }\n            }\n            return\
    \ from[childs[v][le]];\n        }\n    };\n    int n = g.size();\n    std::vector<E>\
    \ from(n, e), to(n, e);\n    std::vector<V> dp_to(n);\n    std::vector<std::vector<int>>\
    \ childs(n);\n    std::vector<int> down(n), up(n);\n    int t = 0;\n    auto dfs\
    \ = [&](auto sfs, int v, int f) -> void {\n        down[v] = t++;\n        childs[v].reserve(g[v].size());\n\
    \        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n    \
    \        childs[v].emplace_back(c);\n            sfs(sfs, c, v);\n           \
    \ dp_to[c] = put_vertex(to[c], c);\n            to[c] = put_edge(dp_to[c], eid);\n\
    \            to[v] = op(to[v], to[c]);\n        }\n        up[v] = t;\n    };\n\
    \    dfs(dfs, root, -1);\n    std::vector<V> dp_ans(n), dp_from(n);\n    std::vector<E>\
    \ inner(n);\n    auto bfs = [&](auto sfs, int v, int f) -> void {\n        int\
    \ sz = g[v].size();\n        inner[sz] = e;\n        int i = sz-1;\n        for\
    \ (auto [c, eid] : g[v] | std::views::reverse){\n            if (c == f) continue;\n\
    \            inner[i] = op(inner[i+1], to[c]);\n            i--;\n        }\n\
    \        dp_ans[v] = put_vertex(op(inner[++i], from[v]), v);\n        E rui =\
    \ e;\n        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n\
    \            dp_from[c] = put_vertex(op(op(rui, inner[++i]), from[v]), v);\n \
    \           from[c] = put_edge(dp_from[c], ~eid);\n            rui = op(rui, to[c]);\n\
    \        }\n        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n\
    \            sfs(sfs, c, v);\n        }\n    };\n    bfs(bfs, root, -1);\n   \
    \ return dp{dp_ans, dp_from, dp_to, down, up, childs};\n}\n\n}  // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <ranges>\n\
    \nnamespace noya2 {\n\n// g[from] contains outgoing edges (to, edgeid(from, to))\n\
    // (E, op, e) is commutative monoid\n// ~edgeid(from, to) == edgeid(to, from)\n\
    // return calculator of dp(r, v)\ntemplate<class V, class E>\nauto rerootingdp(auto\
    \ op, E e, auto put_edge, auto put_vertex, const std::vector<std::vector<std::pair<int,\
    \ int>>> &g, int root = 0){\n    struct dp {\n        // dp(r, v) : root is r,\
    \ dp of subtree v\n        // ans[v]  = dp(v, v)\n        // from[v] = dp(v, par(v))\n\
    \        // to[v]   = dp(par(v), v)\n        // from[root] and to[root] is undefined\n\
    \        std::vector<V> ans, from, to;\n        std::vector<int> down, up;\n \
    \       std::vector<std::vector<int>> childs;\n        bool is_in_subtree(int\
    \ r, int v){\n            return down[r] < down[v] && up[v] <= up[r];\n      \
    \  }\n        V operator()(int r, int v){\n            if (r == v) return ans[v];\n\
    \            if (!is_in_subtree(v, r)) return to[v];\n            int le = 0,\
    \ ri = childs[v].size();\n            while (ri - le > 1){\n                int\
    \ md = (le + ri) / 2;\n                if (down[childs[v][md]] <= down[r]){\n\
    \                    le = md;\n                }\n                else {\n   \
    \                 ri = md;\n                }\n            }\n            return\
    \ from[childs[v][le]];\n        }\n    };\n    int n = g.size();\n    std::vector<E>\
    \ from(n, e), to(n, e);\n    std::vector<V> dp_to(n);\n    std::vector<std::vector<int>>\
    \ childs(n);\n    std::vector<int> down(n), up(n);\n    int t = 0;\n    auto dfs\
    \ = [&](auto sfs, int v, int f) -> void {\n        down[v] = t++;\n        childs[v].reserve(g[v].size());\n\
    \        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n    \
    \        childs[v].emplace_back(c);\n            sfs(sfs, c, v);\n           \
    \ dp_to[c] = put_vertex(to[c], c);\n            to[c] = put_edge(dp_to[c], eid);\n\
    \            to[v] = op(to[v], to[c]);\n        }\n        up[v] = t;\n    };\n\
    \    dfs(dfs, root, -1);\n    std::vector<V> dp_ans(n), dp_from(n);\n    std::vector<E>\
    \ inner(n);\n    auto bfs = [&](auto sfs, int v, int f) -> void {\n        int\
    \ sz = g[v].size();\n        inner[sz] = e;\n        int i = sz-1;\n        for\
    \ (auto [c, eid] : g[v] | std::views::reverse){\n            if (c == f) continue;\n\
    \            inner[i] = op(inner[i+1], to[c]);\n            i--;\n        }\n\
    \        dp_ans[v] = put_vertex(op(inner[++i], from[v]), v);\n        E rui =\
    \ e;\n        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n\
    \            dp_from[c] = put_vertex(op(op(rui, inner[++i]), from[v]), v);\n \
    \           from[c] = put_edge(dp_from[c], ~eid);\n            rui = op(rui, to[c]);\n\
    \        }\n        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n\
    \            sfs(sfs, c, v);\n        }\n    };\n    bfs(bfs, root, -1);\n   \
    \ return dp{dp_ans, dp_from, dp_to, down, up, childs};\n}\n\n}  // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: tree/rerootingdp_.hpp
  requiredBy: []
  timestamp: '2024-10-02 20:20:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/rerootingdp_.hpp
layout: document
redirect_from:
- /library/tree/rerootingdp_.hpp
- /library/tree/rerootingdp_.hpp.html
title: tree/rerootingdp_.hpp
---
