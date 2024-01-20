#pragma once

#include"../template/template.hpp"

namespace noya2 {

struct hldTree {
    hldTree (int n_ = 0, int root_ = 0) : n(n_), root(root_), inner_edge_id(0){
        down.resize(n);
        tour.resize(n);
        if (n == 1) build();
    }
    void add_edge(int u, int v){
        down[inner_edge_id] = u;
        tour[inner_edge_id] = v;
        if (++inner_edge_id == n-1) build();
    }
    void input(int indexed = 1){
        for (int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v;
            u -= indexed, v -= indexed;
            add_edge(u,v);
        }
    }
    void input_parents(int indexed = 1){
        for (int i = 0; i < n-1; i++){
            int p; cin >> p;
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
    bool is_in_subtree(int r, int v){ return down[r] < down[v] && up[v] <= up[r]; }
    bool is_in_path(int lv, int mv, int rv){ return dist(lv,mv) + dist(mv,rv) == dist(lv,rv); }
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
                if (dist_from_v1[es[i]] > dist_from_v1[p]+1){
                    dist_from_v1[es[i]] = dist_from_v1[p]+1;
                    que.push(es[i]);
                }
            }
        }
        int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();
        return make_tuple(dist_from_v1[v2],v1,v2);
    }
    template<typename F>
    void path_query(int u, int v, bool vertex, const F &f){ // f is function takes (left, right) as argument, range = [left,right).
        int l = lca(u,v);
        for (auto &p : ascend(u,l)){
            int s = p.first + 1, t = p.second; // p.first + 1 : depth(p.first) > depth(p.second), so [p.second,p.first] = [p.second,p.first+1)
            s > t ? f(t,s) : f(s,t);
        }
        if (vertex) f(down[l],down[l]+1); // vertex is true : query is for point 
        for (auto &p : descend(l,v)){
            int s = p.first, t = p.second + 1; // p.second +1 : depth(p.first) < depth(p.second), so [p.first,p.second] = [p.first,p.second+1)
            s > t ? f(t,s) : f(s,t);
        }
    }
    template<typename F>
    void path_noncommutative_query(int u, int v, bool vertex, const F &f){ // op(l,r) != op(r,l), so prod[u->...->v] != prod[v->...->u]
        int l = lca(u,v);
        for (auto &p : ascend(u,l)){
            int s = p.first + 1, t = p.second; // p.first + 1 : depth(p.first) > depth(p.second), so [p.second,p.first] = [p.second,p.first+1)
            f(s,t); // le > ri ok
        }
        if (vertex) f(down[l],down[l]+1); // vertex is true : query is for point 
        for (auto &p : descend(l,v)){
            int s = p.first, t = p.second + 1; // p.second +1 : depth(p.first) < depth(p.second), so [p.first,p.second] = [p.first,p.second+1)
            f(s,t); // le > ri ok
        }
    }
    template<typename F>
    void subtree_query(int v, bool vertex, const F &f){
        f(down[v] + (vertex ? 0 : 1), up[v]);
    }
    const auto operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]); }
    const auto operator()(int idx){ return std::ranges::subrange(es.begin()+start_skip_parent(idx),es.begin()+start[idx+1]); }
    int set_id_v(int v) const {
        return down[v];
    }
    int set_id_e(int u, int v) const {
        return (dep[u] < dep[v] ? down[v] : down[u]);
    }
    int vertex_id(int i){
        return tour[i];
    }
    int subtree_l(int v) const {
        return down[v];
    }
    int subtree_r(int v) const {
        return up[v];
    }
  private:
    void build(){
        es.resize((n-1)*2);
        start.resize(n+2,0);
        for (int i = 0; i < n-1; i++){
            start[down[i]+2]++;
            start[tour[i]+2]++;
        }
        for (int i = 1; i <= n; i++){
            start[i+1] += start[i];
        }
        for (int i = 0; i < n-1; i++){
            es[start[down[i]+1]++] = tour[i];
            es[start[tour[i]+1]++] = down[i];
        }
        init_bfs();
        init_dfs();
    }
    void init_bfs(){
        dep.resize(n,numeric_limits<int>::max());
        up.resize(n);
        int l = 0, r = 0;
        auto push = [&](int x){
            up[r++] = x;
        };
        auto pop_front = [&](){
            return up[l++];
        };
        dep[root] = 0;
        push(root);
        while (l < r){
            int p = pop_front();
            for (int i = start[p]; i < start[p+1]; i++){
                auto q = es[i];
                if (dep[q] > dep[p]+1){
                    dep[q] = dep[p]+1;
                    push(q);
                }
                else {
                    swap(es[start[p]],es[i]);
                }
            }
        }
        sub.resize(n,1);
        for (int v : up | std::views::reverse){
            const int stv = start_skip_parent(v);
            for (int i = stv; i < start[v+1]; i++){
                sub[v] += sub[es[i]];
                if (sub[es[stv]] < sub[es[i]]) swap(es[stv],es[i]);
            }
        }
    }
    void init_dfs(){
        nxt.resize(n);
        nxt[root] = root;
        int inner_clock = 0;
        auto dfs = [&](auto sfs, int v) -> void {
            down[v] = inner_clock++;
            tour[down[v]] = v;
            int stv = start_skip_parent(v);
            if (stv < start[v+1]){
                nxt[es[stv]] = nxt[v];
                sfs(sfs,es[stv]);
                for (int i = stv+1; i < start[v+1]; i++){
                    nxt[es[i]] = es[i];
                    sfs(sfs,es[i]);
                }
            }
            up[v] = inner_clock;
        };
        dfs(dfs,root);
    }
    vector<pair<int,int>> ascend(int u, int v){ // [u,v), depth[u] > depth[v]
        vector<pair<int,int>> res;
        while (nxt[u] != nxt[v]){
            res.emplace_back(down[u],down[nxt[u]]); // [s1,t1], [s2,t2], ...
            u = es[start[nxt[u]]]; // parent of nxt[u]
        }
        if (u != v) res.emplace_back(down[u],down[v]+1); // [s,t). v is not in the range (down[] is ordered opposite direction of depth)
        return res;
    }
    vector<pair<int,int>> descend(int u, int v){ // (u,v], depth[u] < depth[v]
        if (u == v) return {};
        if (nxt[u] == nxt[v]){
            return {pair<int,int>(down[u]+1,down[v])}; // (s,t]. u is not in the range
        }
        vector<pair<int,int>> res = descend(u,es[start[nxt[v]]]); // descend(u, parent of nxt[v])
        res.emplace_back(down[nxt[v]],down[v]); // [s1,t1], [s2,t2], ...
        return res;
    }
    int start_skip_parent(int v) const { return start[v]+int(v != root); }
    int n, root, inner_edge_id;
    vector<int> es, start, dep, sub, down, up, tour, nxt;
};

} // namespace noya2