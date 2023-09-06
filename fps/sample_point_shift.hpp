#pragma once

#include"../template/template.hpp"
#include"../fps/formal_power_series.hpp"
#include"../utility/modint_new.hpp"

namespace noya2{

template<Fps_Info Info>
requires Modint<typename Info::value_type>
FormalPowerSeries<Info> sample_point_shift(FormalPowerSeries<Info> y, typename Info::value_type t, int m){
    using fps = FormalPowerSeries<Info>;
    using mint = typename Info::value_type;
    ll T = t.val();
    int k = (int)(y.size()) - 1;
    if (T <= k){
        fps ret(m);
        int ptr = 0;
        for (ll i = T; i <= k && ptr < m; i++){
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
    if (T+m > mint::mod()){
        auto pref = sample_point_shift(y,T,mint::mod()-T);
        auto suf  = sample_point_shift(y,0,m-(int)(pref.size()));
        copy(suf.begin(),suf.end(),back_inserter(pref));
        return pref;
    }
    binomial<mint> bnm;
    fps d(k+1);
    for (int i = 0; i <= k; i++){
        d[i] = bnm.ifact(i) * bnm.ifact(k-i) * y[i];
        if ((k-i)&1) d[i] = -d[i];
    }
    vector<mint> fact(m+k+1); fact[0] = 1;
    for (int i = 0; i < m+k; i++) fact[i+1] = fact[i] * (T-k+i);
    fps h(m+k); h[m+k-1] = fact[m+k].inv();
    for (int i = m+k-1; i >= 1; i--) h[i-1] = h[i] * (T-k+i);
    for (int i = 0; i < m+k; i++) h[i] *= fact[i];
    auto dh = d * h;
    fps ret(m);
    mint cur = T;
    for (int i = 1; i <= k; i++) cur *= T-i;
    for (int i = 0; i < m; i++){
        ret[i] = cur * dh[k+i];
        cur *= T+i+1;
        cur *= h[i];
    }
    return ret;
}

} // namespace noya2