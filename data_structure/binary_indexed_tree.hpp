#pragma once

#include"../template/template.hpp"
#include"../misc/monoids.hpp"

namespace noya2{

template <class G> struct BinaryIndexedTree {
    using T = typename G::value_type;
    BinaryIndexedTree(int n_ = 0) : n(n_), d(std::vector<T>(n_ + 1, G::e())) {}
    void add(int i, T val) {
        for (int x = i+1; x <= n; x += x & -x) {
            d[x] = G::op(d[x],val);
        }
    }
    T prod(int l, int r = -1) {
        if (r == -1) return prefix_prod(l);
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
template<typename T> using BIT_Plus = BinaryIndexedTree<Plus_group<T>>;
template<typename T> using BIT_Xor = BinaryIndexedTree<Xor_group<T>>;

} // namespace noya2