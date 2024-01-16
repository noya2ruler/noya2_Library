#pragma once

#include"../template/template.hpp"
#include"../utility/modint.hpp"

namespace noya2{

template<Modint mint>
struct NTT {
    static constexpr uint mod = mint::mod();
    static constexpr ull mod2 = (ull)mod * mod;
    static constexpr uint pr  = primitive_root_constexpr(mod);
    static constexpr int level = countr_zero(mod-1);
    mint wp[level+1], wm[level+1];
    void set_ws(){
        mint r = mint(pr).pow((mod-1) >> level);
        wp[level] = r, wm[level] = r.inv();
        for (int i = level-1; i >= 0; i--){
            wp[i] = wp[i+1] * wp[i+1];
            wm[i] = wm[i+1] * wm[i+1];
        }
    }
    NTT () { set_ws(); }
    void fft4(vector<mint> &a, int k, int s = 0){
        uint im = wm[2].val();
        uint n = 1<<k;
        uint len = n;
        int l = k;
        while (len > 1){
            if (l == 1){
                for (int i = 0; i < (1<<(k-1)); i++){
                    int i0 = s + i*2, i1 = i0+1;
                    a[i0] += a[i1];
                    a[i1]  = a[i0] - a[i1] * 2;
                }
                len >>= 1;
                l -= 1;
            }
            else {
                int len4 = len/4;
                int nlen = n/len;
                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;
                for (int i = 0; i < len4; i++){
                    int offset = 0;
                    for (int j = 0; j < nlen; j++){
                        int i0 = s + i + offset, i1 = i0 + len4, i2 = i1 + len4, i3 = i2 + len4;
                        uint a0 = a[i0].val();
                        uint a1 = a[i1].val();
                        uint a2 = a[i2].val();
                        uint a3 = a[i3].val();
                        uint a0p2 = a0 + a2;
                        uint a1p3 = a1 + a3;
                        ull b0m2 = (a0 + mod - a2) * r1;
                        ull b1m3 = (a1 + mod - a3) * imr1;
                        ull c0m2 = (a0 + mod - a2) * r3;
                        ull c1m3 = (a1 + mod - a3) * imr3;
                        a[i0] = a0p2 + a1p3;
                        a[i1] = b0m2 + b1m3;
                        a[i2] = (a0p2 + mod*2 - a1p3) * r2;
                        a[i3] = c0m2 + mod2*2 - c1m3;
                        offset += len;
                    }
                    r1 = r1 * wm[l].val() % mod;
                    r2 = r1 * r1 % mod;
                    r3 = r1 * r2 % mod;
                    imr1 = im * r1 % mod;
                    imr3 = im * r3 % mod;
                }
                len >>= 2;
                l -= 2;
            }
        }
    }
    void ifft4(vector<mint> &a, int k, int s = 0){
        uint im = wp[2].val();
        uint n = 1<<k;
        uint len = (k & 1 ? 2 : 4);
        int l = (k & 1 ? 1 : 2);
        while (len <= n){
            if (l == 1){
                for (int i = 0; i < (1<<(k-1)); i++){
                    int i0 = s + i*2, i1 = i0+1;
                    a[i0] += a[i1];
                    a[i1]  = a[i0] - a[i1] * 2;
                }
                len <<= 2;
                l += 2;
            }
            else {
                int len4 = len/4;
                int nlen = n/len;
                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;
                for (int i = 0; i < len4; i++){
                    int offset = 0;
                    for (int j = 0; j < nlen; j++){
                        int i0 = s + i + offset, i1 = i0 + len4, i2 = i1 + len4, i3 = i2 + len4;
                        ull a0 = a[i0].val();
                        ull a1 = a[i1].val() * r1;
                        ull a2 = a[i2].val() * r2;
                        ull a3 = a[i3].val() * r3;
                        ull b1 = a[i1].val() * imr1;
                        ull b3 = a[i3].val() * imr3;
                        ull a0p2 = a0 + a2;
                        ull a1p3 = a1 + a3;
                        ull a0m2 = a0 + mod2 - a2;
                        ull b1m3 = b1 + mod2 - b3;
                        a[i0] = a0p2 + a1p3;
                        a[i1] = a0m2 + b1m3;
                        a[i2] = a0p2 + mod2*2 - a1p3;
                        a[i3] = a0m2 + mod2*2 - b1m3;
                        offset += len;
                    }
                    r1 = r1 * wp[l].val() % mod;
                    r2 = r1 * r1 % mod;
                    r3 = r1 * r2 % mod;
                    imr1 = im * r1 % mod;
                    imr3 = im * r3 % mod;
                }
                len <<= 2;
                l += 2;
            }
        }
    }
    void ntt(vector<mint> &a) {
        if ((int)a.size() <= 1) return;
        fft4(a, 63-countl_zero(a.size()));
    }
    void intt(vector<mint> &a, bool stop = false) {
        if ((int)a.size() <= 1) return;
        ifft4(a, 63-countl_zero(a.size()));
        if (stop) return ;
        mint iv = mint(a.size()).inv();
        for (auto &x : a) x *= iv;
    }
    vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
        int l = a.size() + b.size() - 1;
        if (min<int>(a.size(), b.size()) <= 40){
            vector<mint> s(l);
            for (int i = 0; i < (int)a.size(); i++) for (int j = 0; j < (int)b.size(); j++) s[i + j] += a[i] * b[j];
            return s;
        }
        int k = 2, M = 4;
        while (M < l) M <<= 1, ++k;
        set_ws();
        vector<mint> s(M);
        for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];
        fft4(s, k);
        if (a.size() == b.size() && a == b) {
            for (int i = 0; i < M; ++i) s[i] *= s[i];
        }
        else {
            vector<mint> t(M);
            for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];
            fft4(t, k);
            for (int i = 0; i < M; ++i) s[i] *= t[i];
        }
        ifft4(s, k);
        s.resize(l);
        mint invm = mint(M).inv();
        for (int i = 0; i < l; ++i) s[i] *= invm;
        return s;
    }
};


} // namespace noya2