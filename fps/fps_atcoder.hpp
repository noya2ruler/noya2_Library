#pragma once

#include"formal_power_series.hpp"
#include<atcoder/convolution>

namespace noya2{

template<typename T>
struct fps_atcoder{
    static vector<T> multiply(const vector<T> &a, const vector<T> &b){
        return atcoder::convolution(a,b);
    }
};
template<typename T> using fps = FormalPowerSeries<T,fps_atcoder<T>>;

} // namespace noya2

