#pragma once

#include"../template/template.hpp"
#include"../misc/concepts.hpp"

namespace noya2{

template <Group G>
struct binary_indexed_tree {
    using T = typename G::value_type;
    binary_indexed_tree (int _n = 0) : n(_n), d(_n + 1, G::e()) {}
    void add(int i, T val) {
        for (int x = i+1; x <= n; x += x & -x) {
            d[x] = G::op(d[x],val);
        }
    }
    T prod(int r){
        return prefix_prod(r);
    }
    T prod(int l, int r) {
        return G::op(G::inv(prefix_prod(l)),prefix_prod(r));
    }
    T get(int i){
        return prod(i,i+1);
    }
    void set(int i, T val){
        add(i,G::op(G::inv(get(i)),val));
    }
  private:
    int n;
    std::vector<T> d;
    T prefix_prod(int i) {
        assert(0 <= i && i <= n);
        T ret = G::e();
        for (int x = i; x > 0; x -= x & -x) {
            ret = G::op(ret,d[x]);
        }
        return ret;
    }
};

} // namespace noya2