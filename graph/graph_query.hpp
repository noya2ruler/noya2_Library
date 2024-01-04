#pragma once

#include"../template/template.hpp"
#include"../data_structure/csr.hpp"

namespace noya2 {

template<typename Cost>
struct Graph {
    int n;
    csr<pair<int,Cost>> g;
    Cost dist_inf;
    Graph (int n_ = 0, int m_ = -1) : n(n_), g(n_,m_) {
        dist_inf = numeric_limits<Cost>::max() / 2;
    }
    int add_edge(int u, int v, Cost cost = 1){
        return g.add(u,pair<int,Cost>(v,cost));
    }
    void build(){
        g.build();
    }
    void set_inf(Cost new_inf){
        dist_inf = new_inf;
    }
    vector<Cost> dijkstra(int s){
        vector<Cost> dist(n,dist_inf);
        dist[s] = 0;
        using P = pair<Cost,int>;
        priority_queue<P,vector<P>,greater<P>> pque;
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
    vector<int> reconstruct(int s, int t, const vector<Cost> &dist){
        if (dist[t] == linf) return {};
        vector<int> from(n,-1);
        queue<int> que;
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
        vector<int> ans = {t};
        while (t != s){
            t = from[t];
            ans.emplace_back(t);
        }
        reverse(all(ans));
        return ans;
    }
    vector<Cost> bfs01(int s){
        vector<Cost> dist(n,iinf);
        dist[s] = 0;
        deque<int> que;
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
    vector<Cost> bellman_ford(int s, bool &ng_cycle){
        vector<Cost> dist(n,dist_inf);
        vector<int> ng;
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
    vector<vector<Cost>> warshall_floyd(){
        vector<vector<Cost>> dist(n,vector<Cost>(n,dist_inf));
        rep(v,n){
            dist[v][v] = 0;
            for (auto [u, c] : g[v]){
                chmin(dist[v][u],c);
            }
        }
        rep(k,n) rep(i,n) rep(j,n){
            chmin(dist[i][j],dist[i][k]+dist[k][j]);
        }
        return dist;
    }
    const auto operator[](int idx) const { return g[idx]; }
};

} // namespace noya2