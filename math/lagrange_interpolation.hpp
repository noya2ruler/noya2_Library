#pragma once

#include"binomial.hpp"

namespace noya2 {

/**
 * @brief Lagrange interpolation
 * @note y is at most n-degree polynomial of x
 * 
 * @tparam mint (use noya2::binomial<mint>::ifact(int))
 * @param y value of y(0), y(1), ... y(n)
 * @param x specific value of x
 * @return mint y(x)
 */
template<typename mint>
mint lagrange_interpolation(const std::vector<mint> &y, mint x){
    if (x.val() < y.size()){
        return y[x.val()];
    }
    int n = y.size() - 1;
    std::vector<mint> lui(n+1,1), rui(n+1,1);
    mint a = x;
    for (int i = 0; i < n; i++){
        lui[i+1] = lui[i] * a;
        a -= 1;
    }
    for (int i = n-1; i >= 0; i--){
        rui[i] = rui[i+1] * a;
        a += 1;
    }
    mint ans = 0;
    binomial<mint> bnm;
    for (int i = 0; i <= n; i++){
        mint tmp = y[i] * lui[i] * rui[i] * bnm.ifact(i) * bnm.ifact(n-i);
        ans += ((n-i) & 1) ? -tmp : tmp;
    }
    return ans;
}

} // namespace noya2