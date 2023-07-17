#pragma once

#include"../template/template.hpp"
#include"../data_structure/fenwick_tree.hpp"

namespace noya2{

template<class T>
ll inversion(const vector<T> &a){
    auto b = a;
    uniq(b);
    fenwick_tree<T> fen(b.size());
    ll ans = 0;
    for (auto &x : a){
        int id = lower_bound(all(b),x) - b.begin();
        ans += fen.sum(id+1,b.size());
        fen.add(id,1);
    }
    return ans;
}

} // namespace noya2