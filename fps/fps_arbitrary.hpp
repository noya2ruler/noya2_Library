#pragma once

#include"formal_power_series.hpp"

namespace noya2{

template<typename T>
struct fps_arbitrary{
    using value_type = T;
    static vector<T> multiply(const vector<T> &a, const vector<T> &b){
        if (a.empty() || b.empty()) return {};
        vector<T> res((int)(a.size() + b.size())-1,T(0));
        rep(i,a.size()) rep(j,b.size()) res[i+j] += a[i] * b[j];
        return res;
    }
    static vector<T> inv(const vector<T> &a, int d = -1){
        abort();
    }
    static vector<T> integral(const vector<T> &a){
        abort();
    }
};
template<typename T> using fps = FormalPowerSeries<fps_arbitrary<T>>;

} // namespace noya2

