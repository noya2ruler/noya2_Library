#pragma once

#include"fps998244353.hpp"

namespace noya2 {


fps998244353 polynomial_taylor_shift(fps998244353 f, modint998244353 a){
    binomial<modint998244353> bnm;
    int n = f.size();
    rep(i,n) f[i] *= bnm.fact(i);
    std::reverse(all(f));
    fps998244353 g(n,1);
    for (int i = 1; i < n; i++) g[i] = g[i-1] * a * bnm.inv(i);
    f *= g;
    f.resize(n);
    std::reverse(f.begin(),f.end());
    rep(i,n) f[i] *= bnm.ifact(i);
    return f;
}

} // namespace 