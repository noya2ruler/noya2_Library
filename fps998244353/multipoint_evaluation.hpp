#pragma once

#include"fps998244353.hpp"

namespace noya2 {

std::vector<modint998244353> multipoint_evaluation(fps998244353 f, const std::vector<modint998244353> &xs){
    const int n = xs.size();
    int sz = 1;
    while(sz < n) sz <<= 1;
    std::vector<fps998244353> g(sz+sz,{1});
    for(int i = 0; i < n; i++) g[i+sz] = {-xs[i],1};
    for(int i = sz; i-->1;) g[i] = g[i<<1] * g[i<<1|1];
    g[1] = f.remainder(g[1]);
    for(int i = 2; i < sz+n; i++) g[i] = g[i>>1].remainder(g[i]);
    std::vector<modint998244353> res(n);
    for(int i = 0; i < n; i++) res[i] = (g[i+sz].empty() ? modint998244353() : g[i+sz][0]);
    return res;
}

std::vector<modint998244353> multipoint_evaluation_geo(const fps998244353 &f, modint998244353 a, modint998244353 r, int m){
    using mint = modint998244353;
    int n = f.size();
    if (r.val() == 0){
        std::vector<mint> ans(m);
        repp(i,1,m) ans[i] = f[0];
        ans[0] = f.eval(a);
        return ans;
    }
    fps998244353 p(n);
    mint aprd = 1;
    mint ir = r.inv();
    mint irpp = 1, irp = 1;
    for (int i = 0; i < n; i++){
        p[n-1-i] = aprd * f[i] * irpp;
        irpp *= irp;
        irp *= ir;
        aprd *= a;
    }
    fps998244353 q(n+m-1);
    mint rpp = 1, rp = 1;
    for (int i = 0; i < n+m-1; i++){
        q[i] = rpp;
        rpp *= rp;
        rp *= r;
    }
    p *= q;
    std::vector<mint> ans(m);
    irpp = 1, irp = 1;
    for (int i = 0; i < m; i++){
        ans[i] = p[n-1+i] * irpp;
        irpp *= irp;
        irp *= ir;
    }
    return ans;
}

} // namespace noya2