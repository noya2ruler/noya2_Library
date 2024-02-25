#pragma once

#include"simple_tree.hpp"

namespace noya2 {

struct hld_tree {
    internal::csr<int> g;
    hld_tree () {}
    hld_tree (int _n, int _root = 0) : g(_n,(_n - 1)*2), n(_n), root(_root) {}
    hld_tree (simple_tree _g, int _root = 0) : g(_g.g), n(_g.g.n), root(_root){}

    void add_edge(int u, int v){
        g.add(u, v);
        int id = g.add(v, u);
        if (id + 1 == (g.n - 1)*2) build();
    }
    void input(int indexed = 1){
        for (int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v;
            u -= indexed, v -= indexed;
            add_edge(u, v);
        }
    }
    void input_parents(int indexed = 1){
        for (int i = 0; i < n - 1; i++){
            int v; cin >> v;
            v -= indexed;
            add_edge(i + 1, v);
        }
    }

    int depth(int v) const {
        return dep[v];
    }

    int parent(int v) const {
        if (v == root) return -1;
        return g[v].back();
    }

    int degree(int v) const {
        return g[v].size();
    }

    int subtree_size(int v) const {
        return sub[v];
    }

    // if d > dep[v], return -1
    int la(int v, int d) const {
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

    int lca(int u, int v) const {
        while (nxt[u] != nxt[v]){
            if (down[u] < down[v]) swap(u,v);
            u = parent(nxt[u]);
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v) const {
        return dep[u] + dep[v] - 2*dep[lca(u,v)];
    }

    // if d > dist(from, to), return -1
    int jump(int from, int to, int d) const {
        int l = lca(from,to);
        if (d <= dep[from] - dep[l]){
            return la(from, d);
        }
        d -= dep[from] - dep[l];
        if (d <= dep[to] - dep[l]){
            return la(to, dep[to] - dep[l] - d);
        }
        return -1;
    }

    // seg.set(index(v), X[v]);
    int index(int vertex) const {
        return down[vertex];
    }

    int index_from_edge(int u, int v) const {
        return (dep[u] < dep[v] ? down[v] : down[u]);
    }

    // X[vertex(i)] = seg.get(i);
    int vertex(int index) const {
        return tour[index];
    }

    int subtree_l(int v) const {
        return down[v];
    }

    int subtree_r(int v) const {
        return down[v] + sub[v];
    }

    // if r == v, return true
    bool is_in_subtree(int r, int v) const {
        return subtree_l(r) <= subtree_l(v) && subtree_l(v) < subtree_r(r);
    }

    bool is_in_path(int lv, int mv, int rv) const {
        return dist(lv,mv) + dist(mv,rv) == dist(lv,rv);
    }

    // dist, v1, v2
    tuple<int,int,int> diameter(){
        int v1 = max_element(dep.begin(),dep.end()) - dep.begin();
        vector<int> dist_from_v1(n,numeric_limits<int>::max());
        queue<int> que;
        que.push(v1);
        dist_from_v1[v1] = 0;
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (int u : g[v]){
                if (dist_from_v1[u] > dist_from_v1[v]+1){
                    dist_from_v1[u] = dist_from_v1[v]+1;
                    que.push(u);
                }
            }
        }
        int v2 = max_element(dist_from_v1.begin(),dist_from_v1.end()) - dist_from_v1.begin();
        return make_tuple(dist_from_v1[v2],v1,v2);
    }

    // vertex array : vector<int> {from, v1, v2, ... , to}
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

    template<typename F>
    void path_query(int u, int v, bool vertex, const F &f){
        int l = lca(u,v);
        for (auto [s, t] : ascend(u, l)){
            f(t, s + 1);
        }
        if (vertex) f(down[l], down[l] + 1);
        for (auto [s, t] : descend(l, v)){
            f(s, t + 1);
        }
    }

    template<typename F>
    void path_noncommutative_query(int u, int v, bool vertex, const F &f){
        int l = lca(u,v);
        for (auto [s, t] : ascend(u, l)){
            f(s + 1, t); // l > r ok
        }
        if (vertex) f(down[l],down[l] + 1);
        for (auto [s, t] : descend(l, v)){
            f(s, t + 1); // l > r ok
        }
    }

    template<typename F>
    void subtree_query(int v, bool vertex, const F &f){
        f(down[v] + (vertex ? 0 : 1), down[v] + sub[v]);
    }

    // adjacent to v
    const auto operator[](int v) const {
        return g[v];
    }
    auto operator[](int v){
        return g[v];
    }

    // only child
    const auto operator()(int v) const {
        return g(v, 0, degree(v) - (v == root ? 0 : 1));
    }
    auto operator()(int v){
        return g(v, 0, degree(v) - (v == root ? 0 : 1));
    }

  private:
    int n, root;
    vector<int> dep, sub, down, tour, nxt;

    // v is ancestor of u.
    // enumerate [closed] intervals of down ( interval [l, r] may hold l > r ).
    vector<pair<int,int>> ascend(int u, int v){
        vector<pair<int,int>> res;
        while (nxt[u] != nxt[v]){
            res.emplace_back(down[u], down[nxt[u]]);
            u = parent(nxt[u]);
        }
        if (u != v) res.emplace_back(down[u], down[v]+1);
        return res;
    }

    // u is ancestor of v.
    // enumerate [closed] intervals of down ( interval [l, r] may hold l > r ).
    vector<pair<int,int>> descend(int u, int v){
        if (u == v) return {};
        if (nxt[u] == nxt[v]){
            return {pair<int,int>(down[u]+1, down[v])};
        }
        vector<pair<int,int>> res = descend(u, parent(nxt[v]));
        res.emplace_back(down[nxt[v]], down[v]);
        return res;
    }

    void build(){
        g.build();
        init_sz();
        init_hld();
    }

    /*
        setup dep, sub
        if v is not root, g[v].back() is parent of v.
        if v is not leaf (i.e. v has child), g[v].front() is heavy child of v.
    */
    void init_sz(){
        dep.resize(n, 0);
        sub.resize(n, 1);
        auto dfs = [&](auto sfs, int v, int f) -> void {
            for (int &u : g[v]){
                // only one chance to take parent as u.
                if (u == f) swap(g[v].back(), u);
                // twice means u is the last element of g[v], i.e. parent of v.
                if (u == f) break;
                dep[u] = dep[v]+1;
                sfs(sfs, u, v);
                sub[v] += sub[u];
                if (sub[g[v].front()] < sub[u]){
                    swap(g[v].front(), u);
                }
            }
        };
        dfs(dfs, root, -1);
    }

    /*
        setup down, tour, nxt
        only heavy child c of v, nxt[c] = nxt[v]. for other child c, nxt[c] = c.
    */
    void init_hld(){
        down.resize(n);
        tour.resize(n);
        nxt.resize(n);
        nxt[root] = root;
        int clock = 0;
        auto dfs = [&](auto sfs, int v) -> void {
            down[v] = clock++;
            tour[down[v]] = v;
            // in case of no child, nothing to do
            if ((*this)(v).empty()) return ;
            // heavy child
            nxt[(*this)(v).front()] = nxt[v];
            sfs(sfs, (*this)(v).front());
            // other child
            for (int u : (*this)(v).next()){
                nxt[u] = u;
                sfs(sfs, u);
            }
        };
        dfs(dfs, root);
    }

  public:
    struct compressed_tree : public simple_tree {
        using simple_tree::simple_tree;
        using simple_tree::operator=;
        hld_tree &g;
        compressed_tree (hld_tree &g_, vector<int> vs) : g(g_){
            auto comp = [&](int lv, int rv){
                return g.index(lv) < g.index(rv);
            };
            sort(vs.begin(),vs.end(),comp);
            int sz = vs.size();
            for (int i = 0; i < sz-1; i++){
                vs.emplace_back(g.lca(vs[i],vs[i+1]));
            }
            sort(vs.begin(),vs.end(),comp);
            vs.erase(unique(vs.begin(),vs.end()),vs.end());
            sz = vs.size();
            (*this) = simple_tree(sz);
            real_vertex = vs;
            for (int i = 0; i < sz; i++){
                g.virtual_vertex[real_vertex[i]] = i;
            }
            stack<int> st;
            st.push(0);
            for (int i = 1; i < sz; i++){
                while (!g.is_in_subtree(real_vertex[st.top()], real_vertex[i])) st.pop();
                (*this).add_edge(st.top(),i);
                st.push(i);
            }
        }
        vector<int> real_vertex;
        int real_v(int virtual_v) const {
            return real_vertex[virtual_v];
        }
        int virtual_v(int real_v) const {
            return g.virtual_vertex[real_v];
        }
        size_t size() const {
            return real_vertex.size();
        }
    };
    compressed_tree compressed_tree_gen(const vector<int> &vs){
        if ((int)virtual_vertex.size() != n) virtual_vertex.resize(n);
        return compressed_tree(*this, vs);
    }
    vector<int> virtual_vertex;
};

} // namespace noya2