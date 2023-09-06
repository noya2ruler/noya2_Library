#pragma once

#include"formal_power_series.hpp"
#include"../math/binomial.hpp"
#include"ntt.hpp"

namespace noya2{

template<typename T>
struct fps_ntt{
    using value_type = T;
    static NTT<T> ntt;
    static vector<T> multiply(const vector<T> &a, const vector<T> &b){
        return ntt.multiply(a,b);
    }
    static vector<T> inv(const vector<T> &a, int d = -1){
        const int n = a.size();
        if (d == -1) d = n;
        vector<T> res = {a[0].inv()};
        for (int siz = 1; siz < d; siz <<= 1){
            vector<T> f(a.begin(),a.begin()+min(n,siz*2)), g(res);
            f.resize(siz*2), g.resize(siz*2);
            ntt.ntt(f), ntt.ntt(g);
            for (int i = 0; i < siz*2; i++) f[i] *= g[i];
            ntt.intt(f,true);
            f.erase(f.begin(),f.begin()+siz);
            f.resize(siz*2);
            ntt.ntt(f);
            for (int i = 0; i < siz*2; i++) f[i] *= g[i];
            ntt.intt(f,true);
            T siz2_inv = T(siz*2).inv(); siz2_inv *= -siz2_inv;
            for (int i = 0; i < siz; i++) f[i] *= siz2_inv;
            res.insert(res.end(),f.begin(),f.begin()+siz);
        }
        res.resize(d);
        return res;
    }
    static binomial<T> bnm;
    static vector<T> integral(const vector<T> &a){
        const int n = a.size();
        vector<T> res(n+1);
        for (int i = 1; i <= n; i++) res[i] = a[i-1] * bnm.inv(i);
        return res;
    }
};
template<typename T> NTT<T> fps_ntt<T>::ntt;
template<typename T> using FPS_ntt = FormalPowerSeries<fps_ntt<T>>;

} // namespace noya2

