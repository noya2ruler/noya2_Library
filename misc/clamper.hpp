#pragma once

#include <algorithm>
#include <limits>

namespace noya2 {

template<typename T>
struct clamper {
    static constexpr T lim_l = std::numeric_limits<T>::min() / 3;
    static constexpr T lim_r = std::numeric_limits<T>::max() / 3;
    // l <= r must be hold (not checked)
    T a, l, r;
    // identity
    constexpr clamper () : a(0), l(lim_l), r(lim_r) {}
    // add only
    constexpr clamper (T _a) : a(_a), l(lim_l), r(lim_r) {}
    // clamp only
    constexpr clamper (T _l, T _r) : a(0), l(_l), r(_r) {}
    // add and clamp
    constexpr clamper (T _a, T _l, T _r) : a(_a), l(_l), r(_r) {}
    static constexpr clamper add_chmax(T _a, T _l){
        return clamper(_a, _l, lim_r);
    }
    static constexpr clamper add_chmin(T _a, T _r){
        return clamper(_a, lim_l, _r);
    }
    static constexpr clamper chmax(T _l){
        return clamper(0, _l, lim_r);
    }
    static constexpr clamper chmin(T _r){
        return clamper(0, lim_l, _r);
    }
    constexpr T eval(T x) const {
        return std::clamp(x + a, l, r);
    }
    // (f o g)(x) = f(g(x))
    friend constexpr clamper composition(const clamper &f, const clamper &g){
        return clamper(f.a + g.a, f.eval(g.l), f.eval(g.r));
    }
};

} // namespace noya2