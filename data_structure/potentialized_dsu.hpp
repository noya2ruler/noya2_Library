#pragma once

#include <vector>
#include <cassert>
#include <algorithm>

#include"../misc/concepts.hpp"

namespace noya2 {

template<Group G>
struct potentialized_dsu {
    using T = typename G::value_type;
    potentialized_dsu (int n = 0) : _n(n), parent_or_size(n,-1), pot(n, G::e()) {}
    int merge(int u, int v, T d){
        int x = leader(u), y = leader(v);
        if (x == y){
            if (diff(u,v) == d) return x;
            else return -1;
        }
        d = G::op(G::op(potential(u),d),G::inv(potential(v)));
        if (-parent_or_size[x] < -parent_or_size[y]){
            d = G::inv(d);
            std::swap(x,y);
        }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        pot[y] = d;
        return x;
    }
    int leader(int v){
        assert(0 <= v && v < _n);
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
    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
  private:
    int _n;
    std::vector<int> parent_or_size;
    std::vector<T> pot;
};

} // namespace noya2