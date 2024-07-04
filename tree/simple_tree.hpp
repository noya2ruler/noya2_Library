#pragma once

#include"../template/template.hpp"
#include"../data_structure/csr.hpp"

namespace noya2 {

struct simple_tree {
    internal::csr<int> g;
    simple_tree () {}
    simple_tree (int _n) : g(_n, (_n - 1)*2) {
        if (_n == 1){
            g.build();
        }
    }
    void add_edge(int u, int v){
        g.add(u, v);
        int id = g.add(v, u);
        if (id + 1 == (g.n - 1)*2) g.build();
    }
    void input(int indexed = 1){
        for (int i = 0; i < g.n - 1; i++){
            int u, v; cin >> u >> v;
            u -= indexed, v -= indexed;
            add_edge(u, v);
        }
    }
    void input_parents(int indexed = 1){
        for (int i = 0; i < g.n - 1; i++){
            int v; cin >> v;
            v -= indexed;
            add_edge(i + 1, v);
        }
    }
    const auto operator[](int v) const {
        return g[v];
    }
    auto operator[](int v){
        return g[v];
    }
    int size() const {
        return g.n;
    }
};

} // namespace noya2