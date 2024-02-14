#pragma once

#include"../template/template.hpp"
#include"formal_power_series.hpp"
#include"../utility/modint.hpp"

namespace noya2 {

template<Fps_Info Info>
requires Modint<typename Info::value_type>
vector<typename Info::value_type> multipoint_evaluation_geo(const FormalPowerSeries<Info> &f, typename Info::value_type a, typename Info::value_type r, int m){
    using mint = typename Info::value_type;
    using fps = FormalPowerSeries<Info>;
    int n = f.size();
    if (r.val() == 0){
        vector<mint> ans(m);
        repp(i,1,m) ans[i] = f[0];
        ans[0] = f.eval(a);
        return ans;
    }
    fps p(n);
    mint aprd = 1;
    mint ir = r.inv();
    mint irpp = 1, irp = 1;
    rep(i,n){
        p[n-1-i] = aprd * f[i] * irpp;
        irpp *= irp;
        irp *= ir;
        aprd *= a;
    }
    fps q(n+m-1);
    mint rpp = 1, rp = 1;
    rep(i,n+m-1){
        q[i] = rpp;
        rpp *= rp;
        rp *= r;
    }
    p *= q;
    vector<mint> ans(m);
    irpp = 1, irp = 1;
    rep(i,m){
        ans[i] = p[n-1+i] * irpp;
        irpp *= irp;
        irp *= ir;
    }
    return ans;
}

} // namespace noya2