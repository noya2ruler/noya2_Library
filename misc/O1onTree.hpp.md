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
  bundledCode: "#line 2 \"misc/O1onTree.hpp\"\n\n#include <vector>\n#include <queue>\n\
    #include <cassert>\n#include <bit>\n#include <concepts>\n\nnamespace noya2 {\n\
    \n// root is vertex 0, par[i] < i\n// bool comp(int u, int v), comp(u, v) ? [u,\
    \ ...] < [v, ...] : [u, ...] >= [v, ...]\n// void merge(int u, int v), [p, ...]\
    \ ++ [v, ...]  -- merge(p, v) -->  [p, ......]\ntemplate<bool get_order = true>\n\
    std::conditional_t<get_order, std::vector<int>, void> O1onTree(int n, const std::vector<int>\
    \ &par, auto comp, auto merge){\n    if (n == 1){\n        if constexpr (get_order){\n\
    \            return {0};\n        }\n        else {\n            return ;\n  \
    \      }\n    }\n    assert(ssize(par) == n);\n    for (int i = 0; i < n; i++){\n\
    \        assert(par[i] < i);\n    }\n    // dsu without weighted union heuristic\n\
    \    std::vector<int> uf(n, -1);\n    // leader is the highest vertex among the\
    \ connected component\n    auto leader = [&](int a){\n        auto dfs = [&](auto\
    \ sfs, int v){\n            if (uf[v] < 0) return v;\n            return uf[v]\
    \ = sfs(sfs,uf[v]);\n        };\n        return dfs(dfs,a);\n    };\n    // updatable\
    \ priority_queue using segtree\n    int sz = std::bit_ceil<uint32_t>(n);\n   \
    \ std::vector<int> seg(sz);\n    std::vector<bool> done(sz, true);\n    auto op\
    \ = [&](int a, int b){\n        if (done[b]) return a;\n        if (done[a]) return\
    \ b;\n        return comp(a, b) ? a : b;\n    };\n    // definition of op is updated\n\
    \    auto update = [&](int i){\n        i += sz;\n        i >>= 1;\n        //\
    \ segtree leaf i always contains i\n        seg[i] = op(i * 2 - sz, i * 2 + 1\
    \ - sz);\n        while (i > 1){\n            i >>= 1;\n            seg[i] = op(seg[i\
    \ * 2], seg[i * 2 + 1]);\n        }\n    };\n    for (int i = 1; i < n; i++){\n\
    \        done[i] = false;\n    }\n    for (int i = sz - 1; i >= sz / 2; i--){\n\
    \        seg[i] = op(i * 2 - sz, i * 2 + 1 - sz);\n    }\n    for (int i = sz\
    \ / 2 - 1; i >= 1; i--){\n        seg[i] = op(seg[i * 2], seg[i * 2 + 1]);\n \
    \   }\n    std::vector<int> poped_time(n);\n    poped_time[0] = 0;\n    for (int\
    \ i = 1; i < n; i++){\n        int c = seg[1];\n        int p = leader(par[c]);\n\
    \        done[c] = true;\n        merge(p, c);\n        uf[c] = p;\n        update(c);\n\
    \        update(p);\n        poped_time[c] = i;\n    }\n    if constexpr (!get_order){\n\
    \        return ;\n    }\n    // topological sort of vertex by comparison of poped_time\n\
    \    std::vector<std::vector<int>> childs(n);\n    for (int v = 1; v < n; v++){\n\
    \        childs[par[v]].emplace_back(v);\n    }\n    std::priority_queue<long\
    \ long, std::vector<long long>, std::greater<long long>> tvs;\n    auto val =\
    \ [&](int v) -> long long {\n        return ((long long)(poped_time[v]) << 32)\
    \ | v;\n    };\n    tvs.push(0);\n    std::vector<int> order; order.reserve(n);\n\
    \    const long long mask = (1LL << 32) - 1;\n    while (!tvs.empty()){\n    \
    \    int v = tvs.top() & mask; tvs.pop();\n        order.emplace_back(v);\n  \
    \      for (int c : childs[v]){\n            tvs.push(val(c));\n        }\n  \
    \  }\n    if constexpr (get_order){\n        return order;\n    }\n}\n\n// root\
    \ is vertex 0, par[i] < i\ntemplate<typename T, bool get_order = true>\nrequires\
    \ requires (T x, T y){\n    x < y;\n    {T::op(x, y)} -> std::same_as<T>;\n}\n\
    std::conditional_t<get_order, std::vector<int>, T> O1onTree(int n, const std::vector<int>\
    \ &par, std::vector<T> a){\n    assert(ssize(par) == n);\n    for (int i = 0;\
    \ i < n; i++){\n        assert(par[i] < i);\n    }\n    std::vector<int> uf(n,\
    \ -1);\n    auto leader = [&](int aa){\n        auto dfs = [&](auto sfs, int v){\n\
    \            if (uf[v] < 0) return v;\n            return uf[v] = sfs(sfs,uf[v]);\n\
    \        };\n        return dfs(dfs,aa);\n    };\n    using dat = std::pair<T,\
    \ long long>;\n    std::priority_queue<dat> pque;\n    for (int i = 1; i < n;\
    \ i++){\n        pque.push({a[i], i});\n    }\n    const long long mask = (1LL\
    \ << 32) - 1;\n    const int time_max = (1 << 30);\n    std::vector<int> latest(n,0);\n\
    \    std::vector<int> poped_time(n);\n    poped_time[0] = 0;\n    int idx = 1;\n\
    \    while (!pque.empty()){\n        auto [xc, tc] = pque.top(); pque.pop();\n\
    \        if (latest[tc & mask] > (tc >> 32)) continue;\n        int c = (tc &\
    \ mask);\n        latest[c] = time_max;\n        int p = leader(par[c]);\n   \
    \     uf[c] = p;\n        a[p] = T::op(a[p], xc);\n        if (p != 0){\n    \
    \        latest[p]++;\n            pque.push({a[p], ((long long)(latest[p]) <<\
    \ 32) | p});\n        }\n        poped_time[c] = idx++;\n    }\n    if constexpr\
    \ (!get_order){\n        return a[0];\n    }\n    std::vector<std::vector<int>>\
    \ childs(n);\n    for (int v = 1; v < n; v++){\n        childs[par[v]].emplace_back(v);\n\
    \    }\n    std::priority_queue<long long, std::vector<long long>, std::greater<long\
    \ long>> tvs;\n    auto val = [&](int v) -> long long {\n        return ((long\
    \ long)(poped_time[v]) << 32) | v;\n    };\n    tvs.push(0);\n    std::vector<int>\
    \ order; order.reserve(n);\n    while (!tvs.empty()){\n        int v = tvs.top()\
    \ & mask; tvs.pop();\n        order.emplace_back(v);\n        for (int c : childs[v]){\n\
    \            tvs.push(val(c));\n        }\n    }\n    if constexpr (get_order){\n\
    \        return order;\n    }\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include <cassert>\n\
    #include <bit>\n#include <concepts>\n\nnamespace noya2 {\n\n// root is vertex\
    \ 0, par[i] < i\n// bool comp(int u, int v), comp(u, v) ? [u, ...] < [v, ...]\
    \ : [u, ...] >= [v, ...]\n// void merge(int u, int v), [p, ...] ++ [v, ...]  --\
    \ merge(p, v) -->  [p, ......]\ntemplate<bool get_order = true>\nstd::conditional_t<get_order,\
    \ std::vector<int>, void> O1onTree(int n, const std::vector<int> &par, auto comp,\
    \ auto merge){\n    if (n == 1){\n        if constexpr (get_order){\n        \
    \    return {0};\n        }\n        else {\n            return ;\n        }\n\
    \    }\n    assert(ssize(par) == n);\n    for (int i = 0; i < n; i++){\n     \
    \   assert(par[i] < i);\n    }\n    // dsu without weighted union heuristic\n\
    \    std::vector<int> uf(n, -1);\n    // leader is the highest vertex among the\
    \ connected component\n    auto leader = [&](int a){\n        auto dfs = [&](auto\
    \ sfs, int v){\n            if (uf[v] < 0) return v;\n            return uf[v]\
    \ = sfs(sfs,uf[v]);\n        };\n        return dfs(dfs,a);\n    };\n    // updatable\
    \ priority_queue using segtree\n    int sz = std::bit_ceil<uint32_t>(n);\n   \
    \ std::vector<int> seg(sz);\n    std::vector<bool> done(sz, true);\n    auto op\
    \ = [&](int a, int b){\n        if (done[b]) return a;\n        if (done[a]) return\
    \ b;\n        return comp(a, b) ? a : b;\n    };\n    // definition of op is updated\n\
    \    auto update = [&](int i){\n        i += sz;\n        i >>= 1;\n        //\
    \ segtree leaf i always contains i\n        seg[i] = op(i * 2 - sz, i * 2 + 1\
    \ - sz);\n        while (i > 1){\n            i >>= 1;\n            seg[i] = op(seg[i\
    \ * 2], seg[i * 2 + 1]);\n        }\n    };\n    for (int i = 1; i < n; i++){\n\
    \        done[i] = false;\n    }\n    for (int i = sz - 1; i >= sz / 2; i--){\n\
    \        seg[i] = op(i * 2 - sz, i * 2 + 1 - sz);\n    }\n    for (int i = sz\
    \ / 2 - 1; i >= 1; i--){\n        seg[i] = op(seg[i * 2], seg[i * 2 + 1]);\n \
    \   }\n    std::vector<int> poped_time(n);\n    poped_time[0] = 0;\n    for (int\
    \ i = 1; i < n; i++){\n        int c = seg[1];\n        int p = leader(par[c]);\n\
    \        done[c] = true;\n        merge(p, c);\n        uf[c] = p;\n        update(c);\n\
    \        update(p);\n        poped_time[c] = i;\n    }\n    if constexpr (!get_order){\n\
    \        return ;\n    }\n    // topological sort of vertex by comparison of poped_time\n\
    \    std::vector<std::vector<int>> childs(n);\n    for (int v = 1; v < n; v++){\n\
    \        childs[par[v]].emplace_back(v);\n    }\n    std::priority_queue<long\
    \ long, std::vector<long long>, std::greater<long long>> tvs;\n    auto val =\
    \ [&](int v) -> long long {\n        return ((long long)(poped_time[v]) << 32)\
    \ | v;\n    };\n    tvs.push(0);\n    std::vector<int> order; order.reserve(n);\n\
    \    const long long mask = (1LL << 32) - 1;\n    while (!tvs.empty()){\n    \
    \    int v = tvs.top() & mask; tvs.pop();\n        order.emplace_back(v);\n  \
    \      for (int c : childs[v]){\n            tvs.push(val(c));\n        }\n  \
    \  }\n    if constexpr (get_order){\n        return order;\n    }\n}\n\n// root\
    \ is vertex 0, par[i] < i\ntemplate<typename T, bool get_order = true>\nrequires\
    \ requires (T x, T y){\n    x < y;\n    {T::op(x, y)} -> std::same_as<T>;\n}\n\
    std::conditional_t<get_order, std::vector<int>, T> O1onTree(int n, const std::vector<int>\
    \ &par, std::vector<T> a){\n    assert(ssize(par) == n);\n    for (int i = 0;\
    \ i < n; i++){\n        assert(par[i] < i);\n    }\n    std::vector<int> uf(n,\
    \ -1);\n    auto leader = [&](int aa){\n        auto dfs = [&](auto sfs, int v){\n\
    \            if (uf[v] < 0) return v;\n            return uf[v] = sfs(sfs,uf[v]);\n\
    \        };\n        return dfs(dfs,aa);\n    };\n    using dat = std::pair<T,\
    \ long long>;\n    std::priority_queue<dat> pque;\n    for (int i = 1; i < n;\
    \ i++){\n        pque.push({a[i], i});\n    }\n    const long long mask = (1LL\
    \ << 32) - 1;\n    const int time_max = (1 << 30);\n    std::vector<int> latest(n,0);\n\
    \    std::vector<int> poped_time(n);\n    poped_time[0] = 0;\n    int idx = 1;\n\
    \    while (!pque.empty()){\n        auto [xc, tc] = pque.top(); pque.pop();\n\
    \        if (latest[tc & mask] > (tc >> 32)) continue;\n        int c = (tc &\
    \ mask);\n        latest[c] = time_max;\n        int p = leader(par[c]);\n   \
    \     uf[c] = p;\n        a[p] = T::op(a[p], xc);\n        if (p != 0){\n    \
    \        latest[p]++;\n            pque.push({a[p], ((long long)(latest[p]) <<\
    \ 32) | p});\n        }\n        poped_time[c] = idx++;\n    }\n    if constexpr\
    \ (!get_order){\n        return a[0];\n    }\n    std::vector<std::vector<int>>\
    \ childs(n);\n    for (int v = 1; v < n; v++){\n        childs[par[v]].emplace_back(v);\n\
    \    }\n    std::priority_queue<long long, std::vector<long long>, std::greater<long\
    \ long>> tvs;\n    auto val = [&](int v) -> long long {\n        return ((long\
    \ long)(poped_time[v]) << 32) | v;\n    };\n    tvs.push(0);\n    std::vector<int>\
    \ order; order.reserve(n);\n    while (!tvs.empty()){\n        int v = tvs.top()\
    \ & mask; tvs.pop();\n        order.emplace_back(v);\n        for (int c : childs[v]){\n\
    \            tvs.push(val(c));\n        }\n    }\n    if constexpr (get_order){\n\
    \        return order;\n    }\n}\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/O1onTree.hpp
  requiredBy: []
  timestamp: '2024-10-30 04:35:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/O1onTree.hpp
layout: document
redirect_from:
- /library/misc/O1onTree.hpp
- /library/misc/O1onTree.hpp.html
title: misc/O1onTree.hpp
---
