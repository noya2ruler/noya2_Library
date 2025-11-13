#pragma once

#include <cassert>

namespace noya2 {

// f(i) := floor(a * i + b / m)
// y^{f(0)} x y^{f(1)-f(0)} x y^{f(2)-f(1)} x ... x y^{f(n) - f(n-1)}
// = y^{f(0)} prod[i in [0, n)] x y^{f(i+1)-f(i)}
template<class S, auto op, auto e, typename I = long long>
S floor_sum_monoid(I n, I m, I a, I b, S x, S y){
    assert(n >= 0);
    assert(m >= 1);
    assert(a >= 0);
    assert(b >= 0);
    auto pow_monoid = [](S v, I p) -> S {
        S ret = e();
        while (p){
            if (p & 1){
                ret = op(ret, v);
            }
            v = op(v, v);
            p >>= 1;
        }
        return ret;
    };
    S ret = pow_monoid(y, b / m);
    b %= m;
    x = op(x, pow_monoid(y, a / m));
    a %= m;
    I k = (a * n + b) / m;
    if (k == 0){
        return op(ret, pow_monoid(x, n));
    }
    ret = op(ret, floor_sum_monoid<S,op,e>(k - 1, a, m, m - b + a - 1, y, x));
    return op(ret, op(y, pow_monoid(x, n - (m * k - b + a - 1) / a)));
}

} // namespace noya2