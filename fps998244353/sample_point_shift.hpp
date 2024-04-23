#pragma once

#include"fps998244353.hpp"

namespace noya2 {

std::vector<modint998244353> sample_point_shift(fps998244353 y, modint998244353 t, int m){
    long long T = t.val();
    int k = (int)(y.size()) - 1;
    if (T <= k){
        std::vector<modint998244353> ret(m);
        int ptr = 0;
        for (long long i = T; i <= k && ptr < m; i++){
            ret[ptr++] = y[i];
        }
        if (k+1 < T+m){
            auto suf = sample_point_shift(y,k+1,m-ptr);
            for (int i = k+1; i < T+m; i++){
                ret[ptr++] = suf[i-(k+1)];
            }
        }
        return ret;
    }
    if (T+m > modint998244353::mod()){
        auto pref = sample_point_shift(y,T,modint998244353::mod()-T);
        auto suf  = sample_point_shift(y,0,m-(int)(pref.size()));
        copy(suf.begin(),suf.end(),back_inserter(pref));
        return pref;
    }
    binomial<modint998244353> bnm;
    fps998244353 d(k+1);
    for (int i = 0; i <= k; i++){
        d[i] = bnm.ifact(i) * bnm.ifact(k-i) * y[i];
        if ((k-i)&1) d[i] = -d[i];
    }
    std::vector<modint998244353> fact(m+k+1); fact[0] = 1;
    for (int i = 0; i < m+k; i++) fact[i+1] = fact[i] * (T-k+i);
    fps998244353 h(m+k); h[m+k-1] = fact[m+k].inv();
    for (int i = m+k-1; i >= 1; i--) h[i-1] = h[i] * (T-k+i);
    for (int i = 0; i < m+k; i++) h[i] *= fact[i];
    auto dh = d * h;
    std::vector<modint998244353> ret(m);
    modint998244353 cur = T;
    for (int i = 1; i <= k; i++) cur *= T-i;
    for (int i = 0; i < m; i++){
        ret[i] = cur * dh[k+i];
        cur *= T+i+1;
        cur *= h[i];
    }
    return ret;
}

} // namespace noya2