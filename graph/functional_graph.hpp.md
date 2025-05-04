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
  bundledCode: "#line 2 \"graph/functional_graph.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n#include <ranges>\n#include <utility>\n\nnamespace noya2 {\n\nstruct\
    \ functional_graph {\n    int n;\n    std::vector<int> f;\n    // down[v] is length_of_cycle\
    \ + euler_tour_time starting root of v\n    // sub[v] is subtree_size of v \"\
    - 1\"\n    std::vector<int> down, sub;\n    std::vector<int> depth_or_cycleposition,\
    \ root_or_leader;\n    functional_graph (const std::vector<int> &_f) : n(_f.size()),\
    \ f(_f), sub(n, 0), depth_or_cycleposition(n, 0), root_or_leader(n) {\n      \
    \  std::vector<int> deg(n, 0);\n        for (int v = 0; v < n; v++){\n       \
    \     assert(0 <= f[v] && f[v] < n);\n            deg[f[v]]++;\n            root_or_leader[v]\
    \ = v;\n        }\n        std::vector<int> ord; ord.reserve(n);\n        for\
    \ (int v = 0; v < n; v++){\n            if (deg[v] == 0){\n                ord.emplace_back(v);\n\
    \            }\n        }\n        for (int i = 0; i < (int)(ord.size()); i++){\n\
    \            int v = ord[i];\n            sub[f[v]] += sub[v] + 1;\n         \
    \   if (--deg[f[v]] == 0){\n                ord.emplace_back(f[v]);\n        \
    \    }\n        }\n        down = sub;\n        for (int v = 0; v < n; v++){\n\
    \            if (deg[v] == 0) continue;\n            int start = v, length = 0;\n\
    \            do {\n                v = f[v];\n                length++;\n    \
    \        } while(v != start);\n            do {\n                down[v] += length;\n\
    \                v = f[v];\n            } while(v != start);\n        }\n    \
    \    for (int v : ord | std::views::reverse){\n            int p = f[v];\n   \
    \         down[v] = std::exchange(down[p], down[p] - down[v] - 1);\n         \
    \   depth_or_cycleposition[v] = depth_or_cycleposition[p] + 1;\n            root_or_leader[v]\
    \ = root_or_leader[p];\n        }\n        for (int v = 0; v < n; v++){\n    \
    \        if (deg[v] == 0) continue;\n            int start = v, pos = 0;\n   \
    \         do {\n                depth_or_cycleposition[v] = ~pos;\n          \
    \      root_or_leader[v] = ~start;\n                v = f[v];\n              \
    \  pos++;\n            } while(v != start);\n        }\n    }\n    // nearest\
    \ cycle point\n    int root(int v) const {\n        return (root_or_leader[v]\
    \ < 0 ? v : root_or_leader[v]);\n    }\n    // component leader\n    int leader(int\
    \ v) const {\n        return ~root_or_leader[root(v)];\n    }\n    bool reachable(int\
    \ from, int to) const {\n        if (leader(from) != leader(to)) return false;\n\
    \        if (on_cycle(to)) return true;\n        if (root(from) != root(to)) return\
    \ false;\n        return down[to] <= down[from] && down[from]+sub[from] <= down[to]+sub[to];\n\
    \    }\n    bool on_cycle(int v) const {\n        return (root_or_leader[v] <\
    \ 0);\n    }\n    int depth(int v) const {\n        return (depth_or_cycleposition[v]\
    \ < 0 ? 0 : depth_or_cycleposition[v]);\n    }\n    int cycle_length(int v) const\
    \ {\n        return down[root(v)];\n    }\n    int dist(int from, int to) const\
    \ {\n        if (!reachable(from, to)) return -1;\n        if (!on_cycle(to)){\n\
    \            return depth(from) - depth(to);\n        }\n        int ret = depth(from);\n\
    \        from = root(from);\n        int pos_from = ~depth_or_cycleposition[from];\n\
    \        int pos_to = ~depth_or_cycleposition[to];\n        ret += pos_to - pos_from;\n\
    \        if (pos_from > pos_to){\n            ret += down[from]; // += cycle length\n\
    \        }\n        return ret;\n    }\n    bool on_simple_path(int via, int from,\
    \ int to) const {\n        if (!reachable(from, via) || !reachable(via, to)) return\
    \ false;\n        if (!on_cycle(via)){\n            return true;\n        }\n\
    \        from = root(from);\n        return (dist(from, via) + dist(via, to) ==\
    \ dist(from, to));\n    }\n    int operator[](int idx) const {\n        return\
    \ f[idx];\n    }\n    // subrange cycle(int leader?)\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n#include <ranges>\n\
    #include <utility>\n\nnamespace noya2 {\n\nstruct functional_graph {\n    int\
    \ n;\n    std::vector<int> f;\n    // down[v] is length_of_cycle + euler_tour_time\
    \ starting root of v\n    // sub[v] is subtree_size of v \"- 1\"\n    std::vector<int>\
    \ down, sub;\n    std::vector<int> depth_or_cycleposition, root_or_leader;\n \
    \   functional_graph (const std::vector<int> &_f) : n(_f.size()), f(_f), sub(n,\
    \ 0), depth_or_cycleposition(n, 0), root_or_leader(n) {\n        std::vector<int>\
    \ deg(n, 0);\n        for (int v = 0; v < n; v++){\n            assert(0 <= f[v]\
    \ && f[v] < n);\n            deg[f[v]]++;\n            root_or_leader[v] = v;\n\
    \        }\n        std::vector<int> ord; ord.reserve(n);\n        for (int v\
    \ = 0; v < n; v++){\n            if (deg[v] == 0){\n                ord.emplace_back(v);\n\
    \            }\n        }\n        for (int i = 0; i < (int)(ord.size()); i++){\n\
    \            int v = ord[i];\n            sub[f[v]] += sub[v] + 1;\n         \
    \   if (--deg[f[v]] == 0){\n                ord.emplace_back(f[v]);\n        \
    \    }\n        }\n        down = sub;\n        for (int v = 0; v < n; v++){\n\
    \            if (deg[v] == 0) continue;\n            int start = v, length = 0;\n\
    \            do {\n                v = f[v];\n                length++;\n    \
    \        } while(v != start);\n            do {\n                down[v] += length;\n\
    \                v = f[v];\n            } while(v != start);\n        }\n    \
    \    for (int v : ord | std::views::reverse){\n            int p = f[v];\n   \
    \         down[v] = std::exchange(down[p], down[p] - down[v] - 1);\n         \
    \   depth_or_cycleposition[v] = depth_or_cycleposition[p] + 1;\n            root_or_leader[v]\
    \ = root_or_leader[p];\n        }\n        for (int v = 0; v < n; v++){\n    \
    \        if (deg[v] == 0) continue;\n            int start = v, pos = 0;\n   \
    \         do {\n                depth_or_cycleposition[v] = ~pos;\n          \
    \      root_or_leader[v] = ~start;\n                v = f[v];\n              \
    \  pos++;\n            } while(v != start);\n        }\n    }\n    // nearest\
    \ cycle point\n    int root(int v) const {\n        return (root_or_leader[v]\
    \ < 0 ? v : root_or_leader[v]);\n    }\n    // component leader\n    int leader(int\
    \ v) const {\n        return ~root_or_leader[root(v)];\n    }\n    bool reachable(int\
    \ from, int to) const {\n        if (leader(from) != leader(to)) return false;\n\
    \        if (on_cycle(to)) return true;\n        if (root(from) != root(to)) return\
    \ false;\n        return down[to] <= down[from] && down[from]+sub[from] <= down[to]+sub[to];\n\
    \    }\n    bool on_cycle(int v) const {\n        return (root_or_leader[v] <\
    \ 0);\n    }\n    int depth(int v) const {\n        return (depth_or_cycleposition[v]\
    \ < 0 ? 0 : depth_or_cycleposition[v]);\n    }\n    int cycle_length(int v) const\
    \ {\n        return down[root(v)];\n    }\n    int dist(int from, int to) const\
    \ {\n        if (!reachable(from, to)) return -1;\n        if (!on_cycle(to)){\n\
    \            return depth(from) - depth(to);\n        }\n        int ret = depth(from);\n\
    \        from = root(from);\n        int pos_from = ~depth_or_cycleposition[from];\n\
    \        int pos_to = ~depth_or_cycleposition[to];\n        ret += pos_to - pos_from;\n\
    \        if (pos_from > pos_to){\n            ret += down[from]; // += cycle length\n\
    \        }\n        return ret;\n    }\n    bool on_simple_path(int via, int from,\
    \ int to) const {\n        if (!reachable(from, via) || !reachable(via, to)) return\
    \ false;\n        if (!on_cycle(via)){\n            return true;\n        }\n\
    \        from = root(from);\n        return (dist(from, via) + dist(via, to) ==\
    \ dist(from, to));\n    }\n    int operator[](int idx) const {\n        return\
    \ f[idx];\n    }\n    // subrange cycle(int leader?)\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2025-05-04 19:55:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional_graph.hpp
layout: document
redirect_from:
- /library/graph/functional_graph.hpp
- /library/graph/functional_graph.hpp.html
title: graph/functional_graph.hpp
---
