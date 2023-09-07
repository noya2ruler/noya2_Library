#pragma once

#include"formal_power_series.hpp"
#include"ntt.hpp"

namespace noya2{

namespace ArbitraryModConvolution {

constexpr int m0 = 167772161;
constexpr int m1 = 469762049;
constexpr int m2 = 754974721;
using mint0 = static_modint<m0>;
using mint1 = static_modint<m1>;
using mint2 = static_modint<m2>;
constexpr int r01 = mint1(m0).inv().val();
constexpr int r02 = mint2(m0).inv().val();
constexpr int r12 = mint2(m1).inv().val();
constexpr int r02r12 = (long long)(r02) * r12 % m2;
constexpr long long w1 = m0;
constexpr long long w2 = (long long)(m0) * m1;

template <typename T, typename submint>
vector<submint> mul(const vector<T> &a, const vector<T> &b) {
    static NTT<submint> ntt;
    vector<submint> s(a.size()), t(b.size());
    for (int i = 0; i < (int)a.size(); ++i) s[i] = (long long)(a[i] % submint::mod());
    for (int i = 0; i < (int)b.size(); ++i) t[i] = (long long)(b[i] % submint::mod());
    return ntt.multiply(s, t);
}

template <typename T>
vector<int> multiply(const vector<T> &s, const vector<T> &t, int mod) {
    auto d0 = mul<T, mint0>(s, t);
    auto d1 = mul<T, mint1>(s, t);
    auto d2 = mul<T, mint2>(s, t);
    int n = d0.size();
    vector<int> ret(n);
    const int W1 = w1 % mod;
    const int W2 = w2 % mod;
    for (int i = 0; i < n; i++) {
        int n1 = d1[i].val(), n2 = d2[i].val(), a = d0[i].val();
        int b = (long long)(n1 + m1 - a) * r01 % m1;
        int c = ((long long)(n2 + m2 - a) * r02r12 + (long long)(m2 - b) * r12) % m2;
        ret[i] = ((long long)(a) + (long long)(b) * W1 + (long long)(c) * W2) % mod;
    }
    return ret;
}

template <typename mint>
vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
    if (a.size() == 0 && b.size() == 0) return {};
    if (min<int>(a.size(), b.size()) < 128) {
        vector<mint> ret(a.size() + b.size() - 1);
        for (int i = 0; i < (int)a.size(); ++i)
            for (int j = 0; j < (int)b.size(); ++j) ret[i + j] += a[i] * b[j];
        return ret;
    }
    vector<int> s(a.size()), t(b.size());
    for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].val();
    for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i].val();
    vector<int> u = multiply<int>(s, t, mint::mod());
    vector<mint> ret(u.size());
    for (int i = 0; i < (int)u.size(); ++i) ret[i] = mint(u[i]);
    return ret;
}

} // namespace ArbitraryModConvolution

template<Modint T>
struct fps_modint{
    using value_type = T;
    static vector<T> multiply(const vector<T> &a, const vector<T> &b){
        return ArbitraryModConvolution::multiply(a,b);
    }
    static vector<T> inv(const vector<T> &a, int d = -1){ assert(false); }
    static vector<T> integral(const vector<T> &a){ assert(false); }
};
template<typename T> using FPS_modint = FormalPowerSeries<fps_modint<T>>;

} // namespace noya2

