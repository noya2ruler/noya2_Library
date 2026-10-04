---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/FrequencyTableofTreeDistance.test.cpp
    title: test/tree/FrequencyTableofTreeDistance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/centroid_decomposition.hpp\"\n\n#include <vector>\n\
    \nnamespace noya2 {\n\nstd::vector<int> centroid_decomposition(const auto &g){\n\
    \    int n = g.size();\n    if (n == 0){\n        return {};\n    }\n    std::vector<int>\
    \ sub(n), order;\n    order.reserve(n);\n    auto subtree = [&](auto sfs, int\
    \ v, int f) -> void {\n        sub[v] = 1;\n        for (int u : g[v]){\n    \
    \        if (u == f) continue;\n            sfs(sfs, u, v);\n            sub[v]\
    \ += sub[u];\n        }\n    };\n    subtree(subtree,0,-1);\n    auto fixed_root\
    \ = [&](auto self, int root, int par, int cur_size) -> void {\n        auto dfs\
    \ = [&](auto sfs, int v, int f, int sz) -> int {\n            int heavy = 0, child\
    \ = -1;\n            for (int u : g[v]){\n                if (u == f) continue;\n\
    \                if (heavy < sub[u]){\n                    heavy = sub[u];\n \
    \                   child = u;\n                }\n            }\n           \
    \ if (heavy > sz/2){\n                int ret = sfs(sfs, child, v, sz);\n    \
    \            sub[v] -= ret;\n                return ret;\n            }\n    \
    \        else {\n                order.emplace_back(v);\n                for (int\
    \ u : g[v]){\n                    if (u == f) continue;\n                    self(self,\
    \ u, v, sub[u]);\n                }\n                int ret = sub[v];\n     \
    \           sub[v] = 0;\n                return ret;\n            }\n        };\n\
    \        while (cur_size > 0){\n            cur_size -= dfs(dfs, root, par, cur_size);\n\
    \        }\n    };\n    fixed_root(fixed_root, 0, -1, n);\n    return order;\n\
    }\n\nstd::vector<int> centroid_decomposition_tree(const auto &g){\n    int n =\
    \ g.size();\n    if (n == 0){\n        return {};\n    }\n    std::vector<int>\
    \ sub(n), par_tree(n);\n    auto subtree = [&](auto sfs, int v, int f) -> void\
    \ {\n        sub[v] = 1;\n        for (int u : g[v]){\n            if (u == f)\
    \ continue;\n            sfs(sfs, u, v);\n            sub[v] += sub[u];\n    \
    \    }\n    };\n    subtree(subtree,0,-1);\n    auto fixed_root = [&](auto self,\
    \ int root, int par, int cur_size, int cpre) -> void {\n        auto dfs = [&](auto\
    \ sfs, int v, int f, int sz) -> int {\n            int heavy = 0, child = -1;\n\
    \            for (int u : g[v]){\n                if (u == f) continue;\n    \
    \            if (heavy < sub[u]){\n                    heavy = sub[u];\n     \
    \               child = u;\n                }\n            }\n            if (heavy\
    \ > sz/2){\n                int ret = sfs(sfs, child, v, sz);\n              \
    \  sub[v] -= ret;\n                return ret;\n            }\n            else\
    \ {\n                par_tree[v] = cpre;\n                for (int u : g[v]){\n\
    \                    if (u == f) continue;\n                    self(self, u,\
    \ v, sub[u], v);\n                }\n                int ret = sub[v];\n     \
    \           cpre = v;\n                sub[v] = 0;\n                return ret;\n\
    \            }\n        };\n        while (cur_size > 0){\n            cur_size\
    \ -= dfs(dfs, root, par, cur_size);\n        }\n    };\n    fixed_root(fixed_root,\
    \ 0, -1, n, -1);\n    return par_tree;\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace noya2 {\n\nstd::vector<int>\
    \ centroid_decomposition(const auto &g){\n    int n = g.size();\n    if (n ==\
    \ 0){\n        return {};\n    }\n    std::vector<int> sub(n), order;\n    order.reserve(n);\n\
    \    auto subtree = [&](auto sfs, int v, int f) -> void {\n        sub[v] = 1;\n\
    \        for (int u : g[v]){\n            if (u == f) continue;\n            sfs(sfs,\
    \ u, v);\n            sub[v] += sub[u];\n        }\n    };\n    subtree(subtree,0,-1);\n\
    \    auto fixed_root = [&](auto self, int root, int par, int cur_size) -> void\
    \ {\n        auto dfs = [&](auto sfs, int v, int f, int sz) -> int {\n       \
    \     int heavy = 0, child = -1;\n            for (int u : g[v]){\n          \
    \      if (u == f) continue;\n                if (heavy < sub[u]){\n         \
    \           heavy = sub[u];\n                    child = u;\n                }\n\
    \            }\n            if (heavy > sz/2){\n                int ret = sfs(sfs,\
    \ child, v, sz);\n                sub[v] -= ret;\n                return ret;\n\
    \            }\n            else {\n                order.emplace_back(v);\n \
    \               for (int u : g[v]){\n                    if (u == f) continue;\n\
    \                    self(self, u, v, sub[u]);\n                }\n          \
    \      int ret = sub[v];\n                sub[v] = 0;\n                return\
    \ ret;\n            }\n        };\n        while (cur_size > 0){\n           \
    \ cur_size -= dfs(dfs, root, par, cur_size);\n        }\n    };\n    fixed_root(fixed_root,\
    \ 0, -1, n);\n    return order;\n}\n\nstd::vector<int> centroid_decomposition_tree(const\
    \ auto &g){\n    int n = g.size();\n    if (n == 0){\n        return {};\n   \
    \ }\n    std::vector<int> sub(n), par_tree(n);\n    auto subtree = [&](auto sfs,\
    \ int v, int f) -> void {\n        sub[v] = 1;\n        for (int u : g[v]){\n\
    \            if (u == f) continue;\n            sfs(sfs, u, v);\n            sub[v]\
    \ += sub[u];\n        }\n    };\n    subtree(subtree,0,-1);\n    auto fixed_root\
    \ = [&](auto self, int root, int par, int cur_size, int cpre) -> void {\n    \
    \    auto dfs = [&](auto sfs, int v, int f, int sz) -> int {\n            int\
    \ heavy = 0, child = -1;\n            for (int u : g[v]){\n                if\
    \ (u == f) continue;\n                if (heavy < sub[u]){\n                 \
    \   heavy = sub[u];\n                    child = u;\n                }\n     \
    \       }\n            if (heavy > sz/2){\n                int ret = sfs(sfs,\
    \ child, v, sz);\n                sub[v] -= ret;\n                return ret;\n\
    \            }\n            else {\n                par_tree[v] = cpre;\n    \
    \            for (int u : g[v]){\n                    if (u == f) continue;\n\
    \                    self(self, u, v, sub[u], v);\n                }\n       \
    \         int ret = sub[v];\n                cpre = v;\n                sub[v]\
    \ = 0;\n                return ret;\n            }\n        };\n        while\
    \ (cur_size > 0){\n            cur_size -= dfs(dfs, root, par, cur_size);\n  \
    \      }\n    };\n    fixed_root(fixed_root, 0, -1, n, -1);\n    return par_tree;\n\
    }\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-07-06 19:03:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/FrequencyTableofTreeDistance.test.cpp
documentation_of: tree/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/tree/centroid_decomposition.hpp
- /library/tree/centroid_decomposition.hpp.html
title: tree/centroid_decomposition.hpp
---
