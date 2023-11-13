#pragma once

#include"../template/template.hpp"
#include"../misc/monoids.hpp"
#include"../misc/concepts.hpp"

namespace noya2 {

template<Group G>
struct potentialized_dsu {
    using T = typename G::value_type;
    potentialized_dsu (int n_ = 0) : n(n_), parent_or_size(n_,-1) {
        auto ee = G::e();
        pot.resize(n,ee);
    }
    int merge(int u, int v, T d){
        int x = leader(u), y = leader(v);
        if (x == y){
            if (diff(u,v) == d) return x;
            else return -1;
        }
        d = G::op(G::op(potential(u),d),G::inv(potential(v)));
        if (-parent_or_size[x] < -parent_or_size[y]){
            d = G::inv(d);
            swap(x,y);
        }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        pot[y] = d;
        return x;
    }
    int leader(int v){
        assert(0 <= v && v < n);
        if (parent_or_size[v] < 0) return v;
        int l = leader(parent_or_size[v]);
        pot[v] = G::op(pot[v],pot[parent_or_size[v]]);
        return parent_or_size[v] = l;
    }
    bool same(int u, int v){
        return leader(u) == leader(v);
    }
    int size(int v){
        return -parent_or_size[leader(v)];
    }
    T potential(int v){
        leader(v);
        return pot[v];
    }
    T diff(int u, int v){
        return G::op(G::inv(potential(u)),potential(v));
    }
    int n;
    vector<int> parent_or_size;
    vector<T> pot;
};

} // namespace noya2