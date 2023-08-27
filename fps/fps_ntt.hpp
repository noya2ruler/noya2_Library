#pragma once

#include"formal_power_series.hpp"
#include"ntt_new.hpp"

namespace noya2{

template<typename T>
struct fps_ntt{
    static NTT<T> ntt;
    static vector<T> multiply(const vector<T> &a, const vector<T> &b){
        return ntt.multiply(a,b);
    }
};
template<typename T> NTT<T> fps_ntt<T>::ntt;
template<typename T> using fps = FormalPowerSeries<T,fps_ntt<T>>;

} // namespace noya2

