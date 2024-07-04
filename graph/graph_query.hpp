#pragma once

#include"../data_structure/csr.hpp"
#include"../template/utils.hpp"
#include"unweighted_type.hpp"

#include <numeric>
#include <utility>
#include <queue>
#include <deque>
#include <algorithm>

namespace noya2 {

template<typename Cost>
struct graph {
    int n;
    internal::csr<std::pair<int,Cost>> g;
    Cost dist_inf = std::numeric_limits<Cost>::max() / 2;
    graph (int _n = 0) : n(_n), g(_n) {}
    graph (int _n, int _m) : n(_n), g(_n,_m) {}
    // 有向辺を追加 (無向辺ではないことに注意！)
    int add_edge(int u, int v, Cost cost = 1){
        int id = g.add(u, {v,cost});
        return id;
    }
    void build(){
        g.build();
    }
    void set_inf(Cost new_inf){
        dist_inf = new_inf;
    }
    std::vector<Cost> dijkstra(int s){
        g.build();
        std::vector<Cost> dist(n,dist_inf);
        dist[s] = 0;
        using P = std::pair<Cost,int>;
        std::priority_queue<P,std::vector<P>,std::greater<P>> pque;
        pque.push(P(0,s));
        while (!pque.empty()){
            auto [d, v] = pque.top(); pque.pop();
            if (dist[v] < d) continue;
            for (auto [u, c] : g[v]){
                if (chmin(dist[u],d+c)){
                    pque.push(P(dist[u],u));
                }
            }
        }
        return dist;
    }
    std::vector<int> reconstruct(int s, int t, const std::vector<Cost> &dist){
        if (dist[t] == dist_inf) return {};
        g.build();
        std::vector<int> from(n,-1);
        std::queue<int> que;
        que.push(s);
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (auto [u, c] : g[v]){
                if (from[u] == -1 && dist[u] == dist[v] + c){
                    from[u] = v;
                    que.push(u);
                }
            }
        }
        std::vector<int> ans = {t};
        while (t != s){
            t = from[t];
            ans.emplace_back(t);
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
    std::vector<Cost> bfs01(int s){
        g.build();
        std::vector<Cost> dist(n,dist_inf);
        dist[s] = 0;
        std::deque<int> que;
        que.push_back(s);
        while (!que.empty()){
            int v = que.front(); que.pop_front();
            for (auto [u, c] : g[v]){
                if (chmin(dist[u],dist[v]+c)){
                    if (c == 0) que.push_front(u);
                    else que.push_back(u);
                }
            }
        }
        return dist;
    }
    std::vector<Cost> bfs1(int s){
        g.build();
        std::vector<Cost> dist(n,dist_inf);
        dist[s] = 0;
        std::queue<int> que;
        que.push(s);
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (auto [u, c] : g[v]){
                if (chmin(dist[u],dist[v]+c)){
                    que.push(u);
                }
            }
        }
        return dist;
    }
    std::vector<Cost> bellman_ford(int s, bool &ng_cycle){
        g.build();
        std::vector<Cost> dist(n,dist_inf);
        std::vector<int> ng;
        dist[s] = 0;
        int tm = 0;
        while (tm < n){
            bool finish = true;
            for (int v = 0; v < n; v++){
                if (dist[v] == dist_inf) continue;
                for (auto [u, c] : g[v]){
                    if (chmin(dist[u],dist[v]+c)){
                        finish = false;
                        if (tm == n-1) ng.emplace_back(u);
                    }
                }
            }
            if (finish) break;
            tm++;
        }
        ng_cycle = (tm == n);
        if (ng_cycle){
            for (auto v : ng) dist[v] = -dist_inf;
            tm = n;
            while (tm--){
                for (int v = 0; v < n; v++){
                    if (dist[v] != -dist_inf) continue;
                    for (auto [u, c] : g[v]){
                        dist[u] = -dist_inf;
                    }
                }
            }
        }
        return dist;
    }
    std::vector<std::vector<Cost>> warshall_floyd(){
        g.build();
        std::vector<std::vector<Cost>> dist(n,std::vector<Cost>(n,dist_inf));
        for (int v = 0; v < n; v++){
            dist[v][v] = 0;
            for (auto [u, c] : g[v]){
                chmin(dist[v][u],c);
            }
        }
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    chmin(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        return dist;
    }
    const auto operator[](int idx) const { return g[idx]; }
    auto operator[](int idx) { return g[idx]; }
};


template<>
struct graph<unweighted> {
    int n;
    internal::csr<int> g;
    int dist_inf = std::numeric_limits<int>::max() / 2;
    graph (int _n = 0) : n(_n), g(_n) {}
    graph (int _n, int _m) : n(_n), g(_n,_m) {}
    // 有向辺を追加 (無向辺ではないことに注意！)
    int add_edge(int u, int v){
        int id = g.add(u, v);
        return id;
    }
    void build(){
        g.build();
    }
    void set_inf(int new_inf){
        dist_inf = new_inf;
    }
    std::vector<int> reconstruct(int s, int t, const std::vector<int> &dist){
        if (dist[t] == dist_inf) return {};
        g.build();
        std::vector<int> from(n,-1);
        std::queue<int> que;
        que.push(s);
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (auto u : g[v]){
                if (from[u] == -1 && dist[u] == dist[v] + 1){
                    from[u] = v;
                    que.push(u);
                }
            }
        }
        std::vector<int> ans = {t};
        while (t != s){
            t = from[t];
            ans.emplace_back(t);
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
    std::vector<int> bfs(int s){
        g.build();
        std::vector<int> dist(n,dist_inf);
        dist[s] = 0;
        std::queue<int> que;
        que.push(s);
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (auto u : g[v]){
                if (chmin(dist[u],dist[v]+1)){
                    que.push(u);
                }
            }
        }
        return dist;
    }
    const auto operator[](int idx) const { return g[idx]; }
    auto operator[](int idx) { return g[idx]; }
};

template<>
struct graph<bool> {
    int n;
    internal::csr<std::pair<int,bool>> g;
    int dist_inf = std::numeric_limits<int>::max() / 2;
    graph (int _n = 0) : n(_n), g(_n) {}
    graph (int _n, int _m) : n(_n), g(_n,_m) {}
    // 有向辺を追加 (無向辺ではないことに注意！)
    int add_edge(int u, int v, bool cost){
        int id = g.add(u, {v, cost});
        return id;
    }
    void build(){
        g.build();
    }
    void set_inf(int new_inf){
        dist_inf = new_inf;
    }
    std::vector<int> reconstruct(int s, int t, const std::vector<int> &dist){
        if (dist[t] == dist_inf) return {};
        g.build();
        std::vector<int> from(n,-1);
        std::queue<int> que;
        que.push(s);
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (auto [u, b] : g[v]){
                int c = (int)b;
                if (from[u] == -1 && dist[u] == dist[v] + c){
                    from[u] = v;
                    que.push(u);
                }
            }
        }
        std::vector<int> ans = {t};
        while (t != s){
            t = from[t];
            ans.emplace_back(t);
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
    std::vector<int> bfs01(int s){
        g.build();
        std::vector<int> dist(n,dist_inf);
        dist[s] = 0;
        std::deque<int> que;
        que.push_back(s);
        while (!que.empty()){
            int v = que.front(); que.pop_front();
            for (auto [u, b] : g[v]){
                int c = (int)b;
                if (chmin(dist[u],dist[v]+c)){
                    if (c == 0) que.push_front(u);
                    else que.push_back(u);
                }
            }
        }
        return dist;
    }
    const auto operator[](int idx) const { return g[idx]; }
    auto operator[](int idx) { return g[idx]; }
};

} // namespace noya2