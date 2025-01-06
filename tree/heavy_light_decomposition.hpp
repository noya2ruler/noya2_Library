#pragma once

#include <vector>
#include <algorithm>
#include <stack>
#include <ranges>
#include <cassert>
#include <utility>

#include "data_structure/csr.hpp"

namespace noya2 {

struct hld_tree {
    int n, root;
    std::vector<int> down, nxt, sub, tour;
	noya2::internal::csr<int> childs;

    // default constructor (nop)
    hld_tree () {}

    // tree with _n node
    // after construct, call input_edges / input_parents / add_edge _n - 1 times
    hld_tree (int _n, int _root = 0) : n(_n), root(_root), down(n), nxt(n), sub(n, 1), tour(n) {
        if (n == 1){
            nxt[0] = -1;
            down[0] = -1;
            build_from_parents();
        }
    }

    // par[i] < i, par[0] == -1
    hld_tree (const std::vector<int> &par) : n(par.size()), root(0), down(n, -1), nxt(par), sub(n, 1), tour(n){
        build_from_parents();
    }

    // par[i] < i, par[0] == -1
    hld_tree (std::vector<int> &&par) : n(par.size()), root(0), down(n, -1), sub(n, 1), tour(n) {
        nxt.swap(par);
        build_from_parents();
    }

    // distinct unweighted undirected n - 1 edges of tree 
    hld_tree (const std::vector<std::pair<int, int>> &es, int _root = 0) : n(es.size() + 1), root(_root), down(n), nxt(n), sub(n, 1), tour(n) {
        for (auto &[u, v] : es){
            down[u]++;
            down[v]++;
            nxt[u] ^= v;
            nxt[v] ^= u;
        }
        build_from_edges();
    }

    // input parents from cin
    template<int indexed = 1>
    void input_parents(){
        // using std::cin;
        nxt[0] = -1;
        for (int u = 1; u < n; u++){
            cin >> nxt[u];
            nxt[u] -= indexed;
        }
        build_from_parents();
    }

    // input n - 1 edges from cin
    template<int indexed = 1>
    void input_edges(){
        // using std::cin;
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            u -= indexed;
            v -= indexed;
            down[u]++;
            down[v]++;
            nxt[u] ^= v;
            nxt[v] ^= u;
        }
        build_from_edges();
    }

    void add_edge(int u, int v){
        down[u]++;
        down[v]++;
        nxt[u] ^= v;
        nxt[v] ^= u;
        // use tour[0] as counter
        if (++tour[0] == n - 1){
            build_from_edges();
        }
    }

    // top vertex of heavy path which contains v
    int leader(int v) const {
        return nxt[v] < 0 ? v : nxt[v];
    }

    // level ancestor
    // ret is ancestor of v, dist(ret, v) == d
    // if d > depth(v), return -1
    int la(int v, int d) const {
        while (v != -1){
            int u = leader(v);
            if (down[v] - d >= down[u]){
                v = tour[down[v] - d];
                break;
            }
            d -= down[v] - down[u] + 1;
            v = (u == root ? -1 : ~nxt[u]);
        }
        return v;
    }

    // lowest common ancestor of u and v
    int lca(int u, int v) const {
        int du = down[u], dv = down[v];
        if (du > dv){
            std::swap(du, dv);
            std::swap(u, v);
        }
        if (dv < du + sub[u]){
            return u;
        }
        while (du < dv){
            v = ~nxt[leader(v)];
            dv = down[v];
        }
        return v;
    }

    // distance from u to v
    int dist(int u, int v) const {
        int _dist = 0;
        while (leader(u) != leader(v)){
            if (down[u] > down[v]) std::swap(u, v);
            _dist += down[v] - down[leader(v)] + 1;
            v = ~nxt[leader(v)];
        }
        _dist += std::abs(down[u] - down[v]);
        return _dist;
    }

    // d times move from to its neighbor (direction of to)
    // if d > dist(from, to), return -1
    int jump(int from, int to, int d) const {
        int _from = from, _to = to;
        int dist_from_lca = 0, dist_to_lca = 0;
        while (leader(_from) != leader(_to)){
            if (down[_from] > down[_to]){
                dist_from_lca += down[_from] - down[leader(_from)] + 1;
                _from = ~nxt[leader(_from)];
            }
            else {
                dist_to_lca += down[_to] - down[leader(_to)] + 1;
                _to = ~nxt[leader(_to)];
            }
        }
        if (down[_from] > down[_to]){
            dist_from_lca += down[_from] - down[_to];
        }
        else {
            dist_to_lca += down[_to] - down[_from];
        }
        if (d <= dist_from_lca){
            return la(from, d);
        }
        d -= dist_from_lca;
        if (d <= dist_to_lca){
            return la(to, dist_to_lca - d);
        }
        return -1;
    }

    // parent of v (if v is root, return -1)
    int parent(int v) const {
        if (v == root) return -1;
        return (nxt[v] < 0 ? ~nxt[v] : tour[down[v] - 1]);
    }

    // visiting time in euler tour
    // usage : seg.set(index(v), X[v])
    int index(int vertex) const {
        return down[vertex];
    }
    // usage : seg.set(index_edge(e.u, e.v), e.val)
    int index(int vertex1, int vertex2) const {
        return std::max(down[vertex1], down[vertex2]);
    }

    // subtree size of v
    int subtree_size(int v) const {
        return sub[v];
    }

    // prod in subtree v : seg.prod(subtree_l(v), subtree_r(v))
    int subtree_l(int v) const {
        return down[v];
    }
    int subtree_r(int v) const {
        return down[v] + sub[v];
    }

    // v is in subtree r
    bool is_in_subtree(int r, int v) const {
        return subtree_l(r) <= subtree_l(v) && subtree_r(v) <= subtree_r(r);
    }
    
    // distance table from s
    std::vector<int> dist_table(int s) const {
        std::vector<int> table(n, -1);
        table[s] = 0;
        while (s != root){
            table[parent(s)] = table[s] + 1;
            s = parent(s);
        }
        for (int v : tour){
            if (table[v] == -1){
                table[v] = table[parent(v)] + 1;
            }
        }
        return table;
    }

    // dist, v1, v2
    std::tuple<int, int, int> diameter() const {
        std::vector<int> dep = dist_table(root);
        int v1 = std::ranges::max_element(dep) - dep.begin();
        std::vector<int> fromv1 = dist_table(v1);
        int v2 = std::ranges::max_element(fromv1) - fromv1.begin();
        return {fromv1[v2], v1, v2};
    }

    // vertex array {from, ..., to}
    std::vector<int> path(int from, int to) const {
        int d = dist(from, to);
        std::vector<int> _path(d + 1);
        int front = 0, back = d;
        while (from != to){
            if (down[from] > down[to]){
                _path[front++] = from;
                from = parent(from);
            }
            else {
                _path[back--] = to;
                to = parent(to);
            }
        }
        _path[front] = from;
        return _path;
    }

    // path decomposition and query (vertex weighted)
    // if l < r, decsending order tour[l, r)
    // if l > r, acsending order tour(l, r]
    template<bool vertex = true>
    void path_query(int u, int v, auto f) const {
        while (leader(u) != leader(v)){
            if (down[u] < down[v]){
                f(down[leader(v)], down[v] + 1);
                v = ~nxt[leader(v)];
            }
            else {
                f(down[u] + 1, down[leader(u)]);
                u = ~nxt[leader(u)];
            }
        }
        if constexpr (vertex){
            if (down[u] < down[v]){
                f(down[u], down[v] + 1);
            }
            else {
                f(down[u] + 1, down[v]);
            }
        }
        else {
            if (down[u] != down[v]){
                f(down[u] + 1, down[v] + 1);
            }
        }
    }

    // {parent, mapping} : cptree i is correspond to tree mapping[i]. parent[i] is parent of i in cptree.
    // parent[i] < i, parent[0] == -1
	std::pair<std::vector<int>, std::vector<int>> compressed_tree(std::vector<int> vs) const {
        if (vs.empty()){
            return {{},{}};
        }
        auto comp = [&](int l, int r){
            return down[l] < down[r];
        };
		std::ranges::sort(vs, comp);
		int sz = vs.size(); vs.reserve(2*sz);
        for (int i = 0; i < sz-1; i++){
            vs.emplace_back(lca(vs[i], vs[i+1]));
        }
        std::sort(vs.begin() + sz, vs.end(), comp);
        std::ranges::inplace_merge(vs, vs.begin() + sz, comp);
        auto del = std::ranges::unique(vs);
        vs.erase(del.begin(), del.end());
        sz = vs.size();
        std::stack<int> st;
        std::vector<int> par(sz);
        par[0] = -1;
        st.push(0);
        for (int i = 1; i < sz; i++){
            while (!is_in_subtree(vs[st.top()], vs[i])) st.pop();
            par[i] = st.top();
            st.push(i);
        }
        return {par, vs};
	}

	// build csr for using operator[], operator()
	void build_csr(){
		childs = noya2::internal::csr<int>(n, n - 1);
		for (int v = 0; v < n; v++){
			if (v == root) continue;
			childs.add(parent(v), v);
		}
		childs.build();
	}
	const auto operator()(int v) const {
		return childs[v];
	}
	auto operator()(int v){
		return childs[v];
	}

  private:
    // nxt[v] : parent of v, nxt[0] == -1
    void build_from_parents(){
        for (int u = n - 1; u >= 1; u--){
            int v = nxt[u];
            sub[v] += sub[u];
            down[v] = std::max(down[v], sub[u]);
        }
        for (int u = n - 1; u >= 1; u--){
            int v = nxt[u];
            if (down[v] == sub[u]){
                sub[u] = ~sub[u];
                down[v] = ~down[v];
            }
        }

        sub[0] = ~down[0] + 1;
        down[0] = 0;
        for (int u = 1; u < n; u++){
            int v = nxt[u];
            int nsub = ~down[u] + 1;
            if (sub[u] < 0){
                down[u] = down[v] + 1;
                nxt[u] = (nxt[v] < 0 ? v : nxt[v]);
            }
            else {
                down[u] = down[v] + sub[v];
                sub[v] += sub[u];
                nxt[u] = ~v;
            }
            sub[u] = nsub;
        }

        for (int u = 0; u < n; u++){
            tour[down[u]] = u;
        }
    }

    // down[v] : degree of v
    // nxt[v] : xor prod of neighbor of v
    void build_from_edges(){
        // use tour as queue
        int back = 0;
        for (int u = 0; u < n; u++){
            if (u != root && down[u] == 1){
                tour[back++] = u;
            }
        }
        for (int front = 0; front < n - 1; front++){
            int u = tour[front];
            down[u] = -1;
            int v = nxt[u]; // parent of v
            nxt[v] ^= u;
            if (--down[v] == 1 && v != root){
                tour[back++] = v;
            }
        }
        // check : now, tour is reverse of topological order

        tour.pop_back();

        // check : now, down[*] <= 1
        for (int u : tour){
            int v = nxt[u];
            // subtree size (initialized (1,1,...,1))
            sub[v] += sub[u];
            // heaviest subtree of its child
            down[v] = std::max(down[v], sub[u]);
        }
        for (int u : tour){
            int v = nxt[u];
            // whether u is not the top of heavy path
            if (down[v] == sub[u]){
                sub[u] = ~sub[u];
                down[v] = ~down[v];
            }
        }

        // after appearing v as u (or v == root), 
        // down[v] is the visiting time of euler tour
        // nxt[v] is the lowest vertex of heavy path which contains v
        //   (if v itself, nxt[v] is ~(parent of v))
        // sub[v] + down[v] is the light child's starting time of euler tour
        // note : heavy child's visiting time of euler tour is (the time of its parent) + 1
        sub[root] = ~down[root] + 1;
        down[root] = 0;
        nxt[root] = -1;
        for (int u : tour | std::views::reverse){
            int v = nxt[u];
            int nsub = ~down[u] + 1;
            // heavy child
            if (sub[u] < 0){
                down[u] = down[v] + 1;
                nxt[u] = (nxt[v] < 0 ? v : nxt[v]);
            }
            // light child
            else {
                down[u] = down[v] + sub[v];
                sub[v] += sub[u];
                nxt[u] = ~v;
            }
            sub[u] = nsub;
        }

        // tour is inverse permutation of down
        tour.push_back(0);
        for (int u = 0; u < n; u++){
            tour[down[u]] = u;
        }
    }
};

} // namespace noya2