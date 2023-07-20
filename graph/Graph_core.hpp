#pragma once

#include"../template/template.hpp"

namespace noya2 {

struct naiveGraph { // undirected unweighted tree
    naiveGraph (int _n = 0) : n(_n){
        es0.resize(n);
        es1.resize(n);
        _vis.resize(n,0);
    }
    void add_edge(int u, int v, bool undirect = true, int id = -1){
        es0[u].emplace_back(v);
        es1[u].emplace_back(v,id);
        if (undirect){
            es0[v].emplace_back(u);
            es1[v].emplace_back(u,id);
        }
    }
    void input(int m, int _indexed = 1, bool undirect = true){
        rep(i,m){
            int u, v; in(u,v);
            u -= _indexed;
            v -= _indexed;
            add_edge(u,v,undirect,i);
        }
    }
    bool yet(int v){ return _vis[v] == 0; }
    void visit(int v) { _vis[v]++; }
    void reset(int v = -1){ 
        if (v == -1) fill(all(_vis),0);
        else _vis[v] = 0;
    }
    const vector<int>& operator[](int idx) const { return es0[idx]; }
    const vector<pair<int,int>>& operator()(int idx) const {return es1[idx]; }
  private:
    int n;
    vector<vector<int>> es0;
    vector<vector<pair<int,int>>> es1;
    vector<int> _vis;
};

struct usefulGraph { // directed weighted graph
    usefulGraph (int _n = 0) : n(_n){
        es.resize(n);
        _vis.resize(n,0);
    }
    void add_edge(int u, int v, bool undirect = true, ll cost = 1){
        es[u].emplace_back(v,cost);
        if (undirect){
            es[v].emplace_back(u,cost);
        }
    }
    void input(int m, int _indexed = 1, bool undirect = true){
        rep(i,m){
            int u, v; in(u,v);
            ll cost; in(cost);
            u -= _indexed;
            v -= _indexed;
            add_edge(u,v,undirect,cost);
        }
    }
    bool yet(int v){ return _vis[v] == 0; }
    void visit(int v) { _vis[v]++; }
    void reset(int v = -1){ 
        if (v == -1) fill(all(_vis),0);
        else _vis[v] = 0;
    }
    vector<ll> dijkstra(int s){ // all edge weight >= 0
        vector<ll> dist(n,linf);
        dist[s] = 0LL;
        priority_queue<pli,vector<pli>,greater<pli>> pque;
        pque.push(pli(0,s));
        while (!pque.empty()){
            auto [d, f] = pque.top(); pque.pop();
            if (dist[f] < d) continue;
            for (auto [t, cost] : es[f]){
                if (chmin(dist[t],d+cost)){
                    pque.push(pli(dist[t],t));
                }
            }
        }
        return dist;
    }
    vector<int> reconstruct(int s, int t, const vector<ll> &dist){
        if (dist[t] == linf) return {};
        vector<int> froms(n,-1);
        queue<int> que;
        que.push(s);
        froms[s] = s;
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (auto [u, cost] : es[v]){
                if (froms[u] == -1 && dist[v] + cost == dist[u]){
                    froms[u] = v;
                    que.push(u);
                }
            }
        }
        vector<int> ans = {t};
        while (t != s){
            t = froms[t];
            ans.emplace_back(t);
        }
        reverse(all(ans));
        return ans;
    }
    vector<ll> bfs01(int s){ // all edge weight = 0 or 1
        vector<ll> dist(n,linf);
        dist[s] = 0;
        deque<int> que;
        que.push_back(s);
        while (!que.empty()){
            auto f = que.front(); que.pop_front();
            for (auto [t, cost] : es[f]){
                if (chmin(dist[t],dist[f]+cost)){
                    if (cost == 0) que.push_front(t);
                    else que.push_back(t);
                }
            }
        }
        return dist;
    }
    vector<ll> bellman_ford(int s, bool &ng_cycle){
        vector<ll> dist(n,linf);
        vector<int> ng;
        dist[s] = 0;
        int tm = 0;
        while (tm < n){
            bool finish = true;
            for (int f = 0; f < n; f++){
                if (dist[f] == linf) continue;
                for (auto [t, cost] : es[f]){
                    if (chmin(dist[t],dist[f]+cost)){
                        finish = false;
                        if (tm == n-1) ng.emplace_back(t);
                    }
                }
            }
            if (finish) break;
            tm++;
        }
        ng_cycle = (tm == n);
        if (ng_cycle){
            for (auto v : ng) dist[v] = -linf;
            tm = n;
            while (tm--){
                for (int f = 0; f < n; f++){
                    if (dist[f] != -linf) continue;
                    for (auto e : es[f]){
                        dist[e.first] = -linf;
                    }
                }
            }
        }
        return dist;
    }
    vector<vector<ll>> warshall_floyd(){
        vector<vector<ll>> res(n,vector<ll>(n,linf));
        rep(i,n){
            res[i][i] = 0;
            for (auto [t, cost] : es[i]){
                chmin(res[i][t],cost);
            }
        }
        rep(k,n) rep(i,n) rep(j,n){
            chmin(res[i][j],res[i][k]+res[k][j]);
        }
        return res;
    }
    const vector<pair<int,ll>>& operator[](int idx) const { return es[idx]; }
  private:
    int n;
    vector<vector<pair<int,ll>>> es;
    vector<int> _vis;
};

} // namespace noya2