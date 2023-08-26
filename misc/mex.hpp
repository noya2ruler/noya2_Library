#pragma once

#include"../template/template.hpp"

namespace noya2 {

template<typename T>
int mex(const vector<T> &a){
    int n = a.size();
    vector<bool> has(n,false);
    rep(i,n) if (a[i] < n) has[i] = true;
    rep(i,n) if (!has[i]) return i;
    return n;
}

} // namespace noya2