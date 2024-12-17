#pragma once

#include<cassert>

#include"template/utils.hpp"

namespace noya2 {

// find x in (l, r) s.t. f(l) >= f(x) <= f(r)
// condition : f(l) >= f(m) <= f(r)
template<typename Idx>
Idx local_minimum(Idx l, Idx m, Idx r, auto f){
    assert(l < m && m < r); // invariable
    auto fl = f(l), fm = f(m), fr = f(r);
    assert(fl >= fm && fm <= fr); // invariable
    while (r - l > 2){
        Idx lp = floor_div<Idx>(l + m, 2);
        Idx rp = ceil_div<Idx>(m + r, 2);
        auto flp = f(lp), frp = f(rp);
        if (flp < fm){
            r = m;
            m = lp;
            fr = fm;
            fm = flp;
        }
        else if (fm > frp){
            l = m;
            m = rp;
            fl = fm;
            fm = frp;
        }
        else {
            l = lp;
            fl = flp;
            r = rp;
            fr = frp;
        }
    }
    return m;
}

} // namespace noya2