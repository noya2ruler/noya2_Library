#pragma once

#include <vector>

namespace noya2 {

std::vector<int> centroid_decomposition(const auto &g){
    int n = g.size();
    if (n == 0){
        return {};
    }
    std::vector<int> sub(n), order;
    order.reserve(n);
    auto subtree = [&](auto sfs, int v, int f) -> void {
        sub[v] = 1;
        for (int u : g[v]){
            if (u == f) continue;
            sfs(sfs, u, v);
            sub[v] += sub[u];
        }
    };
    subtree(subtree,0,-1);
    auto fixed_root = [&](auto self, int root, int par, int cur_size) -> void {
        auto dfs = [&](auto sfs, int v, int f, int sz) -> int {
            int heavy = 0, child = -1;
            for (int u : g[v]){
                if (u == f) continue;
                if (heavy < sub[u]){
                    heavy = sub[u];
                    child = u;
                }
            }
            if (heavy > sz/2){
                int ret = sfs(sfs, child, v, sz);
                sub[v] -= ret;
                return ret;
            }
            else {
                order.emplace_back(v);
                for (int u : g[v]){
                    if (u == f) continue;
                    self(self, u, v, sub[u]);
                }
                int ret = sub[v];
                sub[v] = 0;
                return ret;
            }
        };
        while (cur_size > 0){
            cur_size -= dfs(dfs, root, par, cur_size);
        }
    };
    fixed_root(fixed_root, 0, -1, n);
    return order;
}

std::vector<int> centroid_decomposition_tree(const auto &g){
    int n = g.size();
    if (n == 0){
        return {};
    }
    std::vector<int> sub(n), par_tree(n);
    auto subtree = [&](auto sfs, int v, int f) -> void {
        sub[v] = 1;
        for (int u : g[v]){
            if (u == f) continue;
            sfs(sfs, u, v);
            sub[v] += sub[u];
        }
    };
    subtree(subtree,0,-1);
    auto fixed_root = [&](auto self, int root, int par, int cur_size, int cpre) -> void {
        auto dfs = [&](auto sfs, int v, int f, int sz) -> int {
            int heavy = 0, child = -1;
            for (int u : g[v]){
                if (u == f) continue;
                if (heavy < sub[u]){
                    heavy = sub[u];
                    child = u;
                }
            }
            if (heavy > sz/2){
                int ret = sfs(sfs, child, v, sz);
                sub[v] -= ret;
                return ret;
            }
            else {
                par_tree[v] = cpre;
                for (int u : g[v]){
                    if (u == f) continue;
                    self(self, u, v, sub[u], v);
                }
                int ret = sub[v];
                cpre = v;
                sub[v] = 0;
                return ret;
            }
        };
        while (cur_size > 0){
            cur_size -= dfs(dfs, root, par, cur_size);
        }
    };
    fixed_root(fixed_root, 0, -1, n, -1);
    return par_tree;
}

} // namespace noya2