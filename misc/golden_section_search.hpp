#pragma once

#include <utility>
#include <functional>
#include <cassert>

namespace noya2 {

// if GETMIN = true (default)
//   return {argmin, min} of f(x) s.t. x in [lx, rx] inclusive
template<typename T, bool GETMIN = true>
std::pair<long long, T> golden_section_search(const std::function<T(long long)> &f, long long lx, long long rx){
    assert(lx <= rx);
    long long a = lx - 1, x, b;
    {
        long long s = 1, t = 2;
        while (t < rx - lx + 2){
            std::swap(s += t, t);
        }
        x = a + t - s;
        b = a + t;
    }
    T fx = f(x), fy;
    while (a + b != 2 * x){
        long long y = a + b - x;
        if (rx < y || (fy = f(y), GETMIN ? fx < fy : fx > fy)){
            b = a;
            a = y;
        }
        else {
            a = x;
            x = y;
            fx = fy;
        }
    }
    return {x, fx};
}

} // namespace noya2