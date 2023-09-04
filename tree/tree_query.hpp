#pragma once

#include<vector>
#include<cassert>
#include<iostream>
#include<limits>
#include<algorithm>
#include<queue>
#include<ranges>

struct Tree {
    Tree (int n_ = 0, int root_ = 0) : n(n_), root(root_), es(n-1), start(n+1,0){}
    void add_edge(int u, int v){
        static int id = 0;
        es[id] = u, start[id] = v;
        if (++id == n-1) build();
    }
    void input(int indexed = 1){
        for (int i = 0; i < n-1; i++){
            int u, v; std::cin >> u >> v;
            u -= indexed, v -= indexed;
            add_edge(u,v);
        }
    }
    void input_parents(int indexed = 1){
        for (int i = 0; i < n-1; i++){
            int p; std::cin >> p;
            p -= indexed;
            add_edge(p,i+1);
        }
    }
    int degree(int v){
        assert(0 <= v && v < n);
        return start[v+1] - start[v];
    }
    int parent(int v){
        assert(0 <= v && v < n);
        if (v == root) return -1;
        return es[start[v]];
    }
    int subtree_size(int v){
        assert(0 <= v && v < n);
        return sub[v];
    }
    int depth(int v){
        assert(0 <= v && v < n);
        return dep[v];
    }
    int la(int v, int d){
        assert(0 <= v && v < n);
        while (v != -1){
            int u = nxt[v];
            if (down[v] - d >= down[u]){
                v = tour[down[v] - d];
                break;
            }
            d -= down[v] - down[u] + 1;
            v = parent(u);
        }
        return v;
    }
    int lca(int u, int v){
        assert(0 <= v && v < n && 0 <= u && u < n);
        while (nxt[u] != nxt[v]){
            if (down[u] < down[v]) std::swap(u,v);
            u = es[start[nxt[u]]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    int jump(int from, int to, int d){
        int l = lca(from,to);
        if (d <= dep[from] - dep[l]){
            return la(from,d);
        }
        d -= dep[from] - dep[l];
        if (d <= dep[to] - dep[l]){
            return la(to,dep[to]-dep[l]-d);
        }
        return -1;
    }
    int dist(int u, int v){ return dep[lca(u,v)]*(-2) + dep[u] + dep[v]; }
    std::vector<int> path(int from, int to){
        int l = lca(from,to);
        const int sizf = dep[from]-dep[l], sizt = dep[to]-dep[l];
        std::vector<int> pf = {from}, pt;
        pf.reserve(sizf+1); pt.reserve(sizt);
        for (int i = 0; i < sizf; i++){
            from = parent(from);
            pf.push_back(from);
        }
        for (int i = 0; i < sizt; i++){
            pt.push_back(to);
            to = parent(to);
        }
        pf.insert(pf.end(),pt.rbegin(),pt.rend());
        return pf;
    }
    // dist, v1, v2
    std::tuple<int,int,int> diameter(){
        int v1 = std::max_element(dep.begin(),dep.end()) - dep.begin();
        std::vector<int> dist_from_v1(n,std::numeric_limits<int>::max());
        std::queue<int> que;
        que.push(v1);
        dist_from_v1[v1] = 0;
        while (!que.empty()){
            int p = que.front(); que.pop();
            for (int i = start[p]; i < start[p+1]; i++){
                if (dist_from_v1[es[i]] > dist_from_v1[p]+1){
                    dist_from_v1[es[i]] = dist_from_v1[p]+1;
                    que.push(es[i]);
                }
            }
        }
        int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();
        return std::make_tuple(dist_from_v1[v2],v1,v2);
    }
    const auto operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]); }
  private:
    void build(){
        std::vector<int> nes(2*(n-1)), fs = start;
        std::fill(start.begin(),start.end(),0);
        for (int i = 0; i < n-1; i++) start[es[i]+1]++, start[fs[i]+1]++;
        for (int i = 0; i < n; i++) start[i+1] += start[i];
        auto geta = start;
        for (int i = 0; i < n-1; i++){
            nes[geta[es[i]]++] = fs[i];
            nes[geta[fs[i]]++] = es[i];
        }
        std::swap(es,nes);
        init_bfs();
        init_dfs();
    }
    void init_bfs(){
        dep.resize(n,std::numeric_limits<int>::max());
        std::queue<int> que;
        que.push(root);
        dep[root] = 0;
        std::vector<int> order; order.reserve(n);
        while (!que.empty()){
            int p = que.front(); que.pop();
            order.push_back(p);
            for (int i = start[p]; i < start[p+1]; i++){
                auto q = es[i];
                if (dep[q] > dep[p]+1){
                    dep[q] = dep[p]+1;
                    que.push(q);
                }
                else {
                    std::swap(es[start[p]],es[i]);
                }
            }
        }
        sub.resize(n,0);
        for (int v : order | std::views::reverse){
            sub[v] = 1;
            int stv = start_skip_parent(v);
            for (int i = stv; i < start[v+1]; i++){
                sub[v] += sub[es[i]];
                if (sub[es[stv]] < sub[es[i]]) std::swap(es[stv],es[i]);
            }
        }
    }
    void init_dfs(){
        down.resize(n);
        tour.resize(n);
        nxt.resize(n);
        nxt[root] = root;
        int nowtime = 0;
        auto dfs = [&](auto sfs, int v) -> void {
            down[v] = nowtime++;
            tour[down[v]] = v;
            int stv = start_skip_parent(v);
            if (stv >= start[v+1]) return ;
            nxt[es[stv]] = nxt[v];
            sfs(sfs,es[stv]);
            for (int i = stv+1; i < start[v+1]; i++){
                nxt[es[i]] = es[i];
                sfs(sfs,es[i]);
            }
        };
        dfs(dfs,root);
    }
    inline int start_skip_parent(int v) const { return start[v]+int(v != root); }
    int n, root;
    std::vector<int> es, start, dep, sub, down, tour, nxt;
};