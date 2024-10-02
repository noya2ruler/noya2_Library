#pragma once

#include <vector>
#include <utility>
#include <ranges>

namespace noya2 {

// g[from] contains outgoing edges (to, edgeid(from, to))
// (E, op, e) is commutative monoid
// ~edgeid(from, to) == edgeid(to, from)
// return calculator of dp(r, v)
template<class V, class E>
auto rerootingdp(auto op, E e, auto put_edge, auto put_vertex, const std::vector<std::vector<std::pair<int, int>>> &g, int root = 0){
    struct dp {
        // dp(r, v) : root is r, dp of subtree v
        // ans[v]  = dp(v, v)
        // from[v] = dp(v, par(v))
        // to[v]   = dp(par(v), v)
        // from[root] and to[root] is undefined
        std::vector<V> ans, from, to;
        std::vector<int> down, up;
        std::vector<std::vector<int>> childs;
        bool is_in_subtree(int r, int v){
            return down[r] < down[v] && up[v] <= up[r];
        }
        V operator()(int r, int v){
            if (r == v) return ans[v];
            if (!is_in_subtree(v, r)) return to[v];
            int le = 0, ri = childs[v].size();
            while (ri - le > 1){
                int md = (le + ri) / 2;
                if (down[childs[v][md]] <= down[r]){
                    le = md;
                }
                else {
                    ri = md;
                }
            }
            return from[childs[v][le]];
        }
    };
    int n = g.size();
    std::vector<E> from(n, e), to(n, e);
    std::vector<V> dp_to(n);
    std::vector<std::vector<int>> childs(n);
    std::vector<int> down(n), up(n);
    int t = 0;
    auto dfs = [&](auto sfs, int v, int f) -> void {
        down[v] = t++;
        childs[v].reserve(g[v].size());
        for (auto [c, eid] : g[v]){
            if (c == f) continue;
            childs[v].emplace_back(c);
            sfs(sfs, c, v);
            dp_to[c] = put_vertex(to[c], c);
            to[c] = put_edge(dp_to[c], eid);
            to[v] = op(to[v], to[c]);
        }
        up[v] = t;
    };
    dfs(dfs, root, -1);
    std::vector<V> dp_ans(n), dp_from(n);
    std::vector<E> inner(n);
    auto bfs = [&](auto sfs, int v, int f) -> void {
        int sz = g[v].size();
        inner[sz] = e;
        int i = sz-1;
        for (auto [c, eid] : g[v] | std::views::reverse){
            if (c == f) continue;
            inner[i] = op(inner[i+1], to[c]);
            i--;
        }
        dp_ans[v] = put_vertex(op(inner[++i], from[v]), v);
        E rui = e;
        for (auto [c, eid] : g[v]){
            if (c == f) continue;
            dp_from[c] = put_vertex(op(op(rui, inner[++i]), from[v]), v);
            from[c] = put_edge(dp_from[c], ~eid);
            rui = op(rui, to[c]);
        }
        for (auto [c, eid] : g[v]){
            if (c == f) continue;
            sfs(sfs, c, v);
        }
    };
    bfs(bfs, root, -1);
    return dp{dp_ans, dp_from, dp_to, down, up, childs};
}

}  // namespace noya2