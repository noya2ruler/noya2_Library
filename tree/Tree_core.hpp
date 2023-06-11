#pragma once

#include"../template/template.hpp"

namespace noya2{

struct naiveTree { // undirected unweighted tree
    naiveTree (int _n = 0) : n(_n){
        es0.resize(_n);
        es1.resize(_n);
    }
    void add_edge(int u, int v, int id = -1){
        es0[u].emplace_back(v);
        es0[v].emplace_back(u);
        es1[u].emplace_back(v,id);
        es1[v].emplace_back(u,id);
    }
    void input(int _indexed = 1){
        rep(i,n-1){
            int u, v; cin >> u >> v;
            u -= _indexed;
            v -= _indexed;
            add_edge(u,v);
        }
    }
    const vector<int>& operator[](int idx) const { return es0[idx]; }
    const vector<pair<int,int>>& operator()(int idx) const {return es1[idx]; }
  private:
    int n;
    vector<vector<int>> es0;
    vector<vector<pair<int,int>>> es1;
};


struct usefulTree { // rooted tree
    usefulTree (int _n = 0, int _root = 0) : n(_n), root(_root) {
        es.resize(n);
    }
    void add_edge(int u, int v){
        es[u].emplace_back(v);
        es[v].emplace_back(u);
    }
    void input(int _indexed = 1){
        rep(i,n-1){
            int u, v; cin >> u >> v;
            u -= _indexed;
            v -= _indexed;
            add_edge(u,v);
        }
    }
    const vector<int>& operator[](int idx) const { return es[idx]; }
    int parent(int v){ return par[0][v]; }
    int subtree_size(int v){
        if (sub[v] != -1) return sub[v];
        sub[v] = 1;
        for (int child : es[v]){
            if (child != par[0][v]) sub[v] += subtree_size(child);
        }
        return sub[v];
    }
    int depth(int v){ return dep[v]; }
    int lca(int u, int v){
        if (dep[u] > dep[v]) swap(u,v);
        for (int i = 0; i < p2size; i++) if ((dep[v] - dep[u]) >> i & 1) v = par[i][v];
        if (u == v) return u;
        for (int i = p2size-1; i >= 0; i--){
            if (par[i][u] != par[i][v]){
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
    int jump_to_root(int from, int d){
        for (int i = 0; i < p2size; i++){
            if ((d >> i & 1) == 1 && from != -1) from = par[i][from];
        }
        return from;
    }
    int jump(int from, int to, int d){
        int l = lca(from,to);
        if (d <= dep[from] - dep[l]){
            return jump_to_root(from,d);
        }
        d -= dep[from] - dep[l];
        if (d <= dep[to] - dep[l]){
            return jump_to_root(to,dep[to]-dep[l]-d);
        }
        return -1;
    }
    vector<int> path(int from, int to){
        int l = lca(from,to);
        int nf = from, nt = to;
        vector<int> pf = {from}, pt = {to};
        while (nf != l){
            nf = par[0][nf];
            pf.emplace_back(nf);
        }
        while (nt != l){
            nt = par[0][nt];
            pt.emplace_back(nt);
        }
        for (int i = pt.size()-2; i >= 0; i--) pf.emplace_back(pt[i]);
        return pf;
    }
    int dist(int u, int v){ return dep[u] + dep[v] - 2 * dep[lca(u,v)];}
    void build(){
        par.clear();
        dep.clear();
        sub.clear();
        p2size = 1;
        int _ni = 1; // _ni = 2^(p2size - 1), n-1 <= 2^(p2size - 1) must be holded
        while (_ni < n-1) p2size++, _ni <<= 1;
        par.resize(p2size,vector<int>(n,-1));
        dep.resize(n,-1);
        sub.resize(n,-1);
        queue<int> que;
        que.push(root);
        dep[root] = 0;
        while (!que.empty()){
            int p = que.front(); que.pop();
            for (int to : es[p]){
                if (dep[to] == -1){
                    par[0][to] = p;
                    dep[to] = dep[p] + 1;
                    que.push(to);
                }
            }
        }
        for (int i = 1; i < p2size; i++){
            for (int v = 0; v < n; v++){
                if (par[i-1][v] == -1) continue;
                par[i][v] = par[i-1][par[i-1][v]];
            }
        }
    }
  private:
    int n, root;
    vector<vector<int>> es;
    int p2size;
    vector<vector<int>> par;
    vector<int> dep, sub;
};

} // namespace noya2