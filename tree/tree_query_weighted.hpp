#pragma once

#include"../template/template.hpp"

namespace noya2{

struct Tree_weighted {
    Tree_weighted (int n_ = 0, int root_ = 0) : n(n_), root(root_), inner_edge_id(0), es(n-1), start(n+1,0){
        if (n == 1) build();
    }
    void add_edge(int u, int v, ll w){
        es[inner_edge_id] = {u,w}, start[inner_edge_id] = v;
        if (++inner_edge_id == n-1) build();
    }
    void input(int indexed = 1){
        rep(i,n-1){
            int u, v; ll w; cin >> u >> v >> w;
            u -= indexed, v -= indexed;
            add_edge(u,v,w);
        }
    }
    void input_parents(int indexed = 1){
        rep(i,n-1){
            int p; ll w; cin >> p >> w;
            p -= indexed;
            add_edge(p,i+1,w);
        }
    }
    int degree(int v){
        assert(0 <= v && v < n);
        return start[v+1] - start[v];
    }
    int parent(int v){
        assert(0 <= v && v < n);
        if (v == root) return -1;
        return es[start[v]].first;
    }
    int subtree_size(int v){
        assert(0 <= v && v < n);
        return sub[v];
    }
    int depth(int v){
        assert(0 <= v && v < n);
        return dep[v];
    }
    ll depth_weighted(int v){
        assert(0 <= v && v < n);
        return wdep[v];
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
    pair<int,ll> la_weighted(int v, ll d){
        assert(0 <= v && v < n);
        if (d > wdep[v]) return make_pair(-1,0LL);
        if (d == wdep[v]) return make_pair(root,0LL);
        while (v != -1){
            int u = nxt[v];
            if (d < wdep[v] - wdep[u]) break;
            d -= wdep[v] - wdep[u];
            if (d < es[start[u]].second){
                return make_pair(u,d);
            }
            d -= es[start[u]].second;
            v = parent(u);
        }
        int le = down[nxt[v]], ri = down[v];
        while (ri - le > 1){
            int md = (le + ri) / 2;
            if (d >= wdep[v] - wdep[tour[md]]) ri = md;
            else le = md;
        }
        return make_pair(tour[ri],d-(wdep[v]-wdep[tour[ri]]));
    }
    int lca(int u, int v){
        assert(0 <= v && v < n && 0 <= u && u < n);
        while (nxt[u] != nxt[v]){
            if (down[u] < down[v]) swap(u,v);
            u = es[start[nxt[u]]].first;
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
    pair<int,ll> jump_weighted(int from, int to, ll d){
        int l = lca(from,to);
        if (d <= wdep[from] - wdep[l]){
            return la_weighted(from,d);
        }
        d -= wdep[from] - wdep[l];
        if (d <= wdep[to] - wdep[l]){
            return la_weighted(to,wdep[to]-wdep[l]-d);
        }
        return make_pair(-1,0LL);
    }
    int dist(int u, int v){ return dep[lca(u,v)]*(-2) + dep[u] + dep[v]; }
    ll dist_weighted(int u, int v){ return wdep[lca(u,v)]*(-2) + wdep[u] + wdep[v]; }
    vector<int> path(int from, int to){
        int l = lca(from,to);
        const int sizf = dep[from]-dep[l], sizt = dep[to]-dep[l];
        vector<int> pf = {from}, pt;
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
    tuple<int,int,int> diameter(){
        int v1 = max_element(dep.begin(),dep.end()) - dep.begin();
        vector<int> dist_from_v1(n,numeric_limits<int>::max());
        queue<int> que;
        que.push(v1);
        dist_from_v1[v1] = 0;
        while (!que.empty()){
            int p = que.front(); que.pop();
            for (int i = start[p]; i < start[p+1]; i++){
                if (chmin(dist_from_v1[es[i].first],dist_from_v1[p]+1)){
                    que.push(es[i].first);
                }
            }
        }
        int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();
        return make_tuple(dist_from_v1[v2],v1,v2);
    }
    // dist, v1, v2
    tuple<ll,int,int> diameter_weighted(){
        int v1 = max_element(wdep.begin(),wdep.end()) - wdep.begin();
        vector<ll> dist_from_v1(n,numeric_limits<ll>::max());
        queue<int> que;
        que.push(v1);
        dist_from_v1[v1] = 0;
        while (!que.empty()){
            int p = que.front(); que.pop();
            for (int i = start[p]; i < start[p+1]; i++){
                if (chmin(dist_from_v1[es[i].first],dist_from_v1[p]+es[i].second)){
                    que.push(es[i].first);
                }
            }
        }
        int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();
        return make_tuple(dist_from_v1[v2],v1,v2);
    }
    const auto operator[](int idx){ return ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]); }
  private:
    void build(){
        vector<pair<int,ll>> nes(2*(n-1));
        vector<int> fs = start;
        fill(start.begin(),start.end(),0);
        for (int i = 0; i < n-1; i++) start[es[i].first+1]++, start[fs[i]+1]++;
        for (int i = 0; i < n; i++) start[i+1] += start[i];
        auto geta = start;
        for (int i = 0; i < n-1; i++){
            nes[geta[es[i].first]++] = {fs[i],es[i].second};
            nes[geta[fs[i]]++] = es[i];
        }
        swap(es,nes);
        init_bfs();
        init_dfs();
    }
    void init_bfs(){
        dep.resize(n,numeric_limits<int>::max());
        wdep.resize(n);
        queue<int> que;
        que.push(root);
        dep[root] = 0;
        vector<int> order; order.reserve(n);
        while (!que.empty()){
            int p = que.front(); que.pop();
            order.push_back(p);
            for (int i = start[p]; i < start[p+1]; i++){
                auto [q, w] = es[i];
                if (chmin(dep[q],dep[p]+1)){
                    wdep[q] = wdep[p] + w;
                    que.push(q);
                }
                else {
                    swap(es[start[p]],es[i]);
                }
            }
        }
        sub.resize(n,0);
        for (int v : order | views::reverse){
            sub[v] = 1;
            int stv = start_skip_parent(v);
            for (int i = stv; i < start[v+1]; i++){
                sub[v] += sub[es[i].first];
                if (sub[es[stv].first] < sub[es[i].first]) swap(es[stv],es[i]);
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
            nxt[es[stv].first] = nxt[v];
            sfs(sfs,es[stv].first);
            for (int i = stv+1; i < start[v+1]; i++){
                nxt[es[i].first] = es[i].first;
                sfs(sfs,es[i].first);
            }
        };
        dfs(dfs,root);
    }
    inline int start_skip_parent(int v) const { return start[v]+int(v != root); }
    int n, root, inner_edge_id;
    vector<pair<int,ll>> es;
    vector<int> start, dep, sub, down, tour, nxt;
    vector<ll> wdep;
};

} // namespace noya2