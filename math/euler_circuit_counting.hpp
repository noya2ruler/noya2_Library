#pragma once

#include"../math/spanning_tree_counting.hpp"
#include"../math/binomial.hpp"

namespace noya2 {

// BEST theorem
// https://en.wikipedia.org/wiki/BEST_theorem
template<typename T>
T euler_circuit_counting(int n, vector<tuple<int,int,ll>> es){
    // i_deg == o_deg
    vector<ll> deg(n,0);
    for (auto [u, v, c] : es){
        deg[u] -= c;
        deg[v] += c;
    }
    rep(i,n) if (deg[i] != 0) return T(0);
    // edges are connected
    int m = es.size();
    vector<bool> vis(n,false);
    vector<vector<int>> g(n);
    rep(i,m){
        auto [u, v, c] = es[i];
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    rep(s,n){
        if (g[s].empty()) continue;
        queue<int> que;
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
    vector<int> ids(n);
    int nonzero = 0;
    rep(v,n){
        if (!g[v].empty()){
            ids[v] = nonzero++;
        }
    }
    vector<tuple<int,int,T>> nes(m);
    rep(i,m){
        auto [u, v, c] = es[i];
        nes[i] = {ids[u],ids[v],c};
        deg[v] += c;
    }
    binomial<T> bnm;
    T ans = directed_spanning_tree_counting(nonzero,nes);
    rep(i,n){
        if (deg[i] > 0){
            ans *= bnm.fact(deg[i]-1);
        }
    }
    return ans;
}

} // namespace noya2