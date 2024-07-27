#pragma once

#include"../math/spanning_tree_counting.hpp"
#include"../math/binomial.hpp"

namespace noya2 {

// BEST theorem
// https://en.wikipedia.org/wiki/BEST_theorem
template<typename T>
T euler_circuit_counting(int n, const std::vector<std::tuple<int, int, long long>> &es){
    // i_deg == o_deg
    std::vector<long long> deg(n,0);
    for (auto [u, v, c] : es){
        deg[u] -= c;
        deg[v] += c;
    }
    for (int i = 0; i < n; i++) if (deg[i] != 0) return T(0);
    // edges are connected
    int m = es.size();
    std::vector<bool> vis(n,false);
    std::vector<std::vector<int>> g(n);
    for (auto [u, v, c] : es){
        if (c == 0) continue;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int s = 0; s < n; s++){
        if (g[s].empty()) continue;
        std::queue<int> que;
        que.push(s);
        vis[s] = true;
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (int u : g[v]){
                if (!vis[u]){
                    vis[u] = true;
                    que.push(u);
                }
            }
        }
        break;
    }
    for (auto [u, v, c] : es){
        if (!vis[u]) return T(0);
    }
    // directed spanning tree counting
    std::vector<int> ids(n);
    int nonzero = 0;
    for (int v = 0; v < n; v++){
        if (!g[v].empty()){
            ids[v] = nonzero++;
        }
    }
    std::vector<std::tuple<int, int, T>> nes(m);
    for (int i = 0; i < m; i++){
        auto [u, v, c] = es[i];
        nes[i] = {ids[u],ids[v],c};
        deg[v] += c;
    }
    binomial<T> bnm;
    T ans = directed_spanning_tree_counting(nonzero,nes);
    for (int i = 0; i < n; i++){
        if (deg[i] > 0){
            ans *= bnm.fact(deg[i]-1);
        }
    }
    return ans;
}

} // namespace noya2