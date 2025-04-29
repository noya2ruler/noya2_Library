#pragma once

#include"../data_structure/dsu.hpp"

namespace noya2 {

struct bipartite_dsu {
    int n, cc_bipartite;
    dsu d;
    bipartite_dsu (int _n = 0) : n(_n), cc_bipartite(_n), d(_n*2){}
    void inner_merge(int u, int v, int up, int vp){
        if (d.same(u, v)){
            assert(d.same(up, vp));
            return ;
        }
        if (inner_is_bipartite(u) || inner_is_bipartite(v)){
            cc_bipartite--;
        }
        d.merge(u, v);
        d.merge(up, vp);
    }
    void add_edge(int u, int v, bool w = true){
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        if (w){
            inner_merge(u, n + v, v, n + u);
        }
        else {
            inner_merge(u, v, n + u, n + v);
        }
    }
    bool is_bipartite() const {
        return d.group_count() == cc_bipartite * 2;
    }
    bool is_bipartite(int v){
        assert(0 <= v && v < n);
        return !d.same(v, n + v);
    }
    bool inner_is_bipartite(int v){
        return !d.same(v, (v < n ? n + v : v - n));
    }
    int bipartite_component_count() const {
        return cc_bipartite;
    }
    int non_bipartite_component_count() const {
        return d.group_count() - cc_bipartite * 2;
    }
    int component_count() const {
        return d.group_count() - cc_bipartite;
    }
};

} // namespace noya2