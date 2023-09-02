#pragma once

#include"../template/template.hpp"
#include"../utility/modint_new.hpp"

namespace noya2{

template<Modint mint>
struct NTT {
    static constexpr uint mod = mint::mod();
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
    void fft2(vector<mint> &a, int k, int l = -1){
        if (k <= 0 || a.empty()) return ;
        if (l == -1) l = 0;
        for (int t = 1, v = 1<<(k-1), wi = k; v > 0; t <<= 1, v >>= 1, wi -= 1){
            mint ww = 1;
            int pl = 1<<wi;
            for (int j = 0; j < v; j++, ww *= wm[wi]){
                int j0 = l+j, j1 = j0+v;
                for (int i = 0; i < t; i++, j0 += pl, j1 += pl){
                    mint a1 = a[j1];
                    a[j1] = (a[j0] - a1) * ww;
                    a[j0] += a1;
                }
            }
        }
    }
    void ifft2(vector<mint> &a, int k, int l = -1){
        if (k <= 0 || a.empty()) return ;
        if (l == -1) l = 0;
        for (int v = 1, t = 1<<(k-1), wi = 1; t > 0; v <<= 1, t >>= 1, wi += 1){
            mint ww = 1;
            int pl = 1<<wi;
            for (int j = 0; j < v; j++, ww *= wp[wi]){
                int j0 = l+j, j1 = j0+v;
                for (int i = 0; i < t; i++, j0 += pl, j1 += pl){
                    mint a1 = a[j1] * ww;
                    a[j1] = a[j0] - a1;
                    a[j0] += a1;
                }
            }
        }
    }
    void fft4(vector<mint> &a, int k, int l = -1){
        if (k <= 0 || a.empty()) return ;
        if (l == -1) l = 0;
        if (k == 1){
            mint a1 = a[l+1];
            a[l+1] = a[l] - a1;
            a[l] += a1;
            return ;
        }
        if (k & 1){
            int v = 1 << (k - 1);
            mint ww = 1;
            for (int i = 0; i < v; i++, ww *= wm[k]){
                mint aiv = a[l+i+v];
                a[l+i+v] = (a[l+i] - aiv) * ww;
                a[l+i]   = a[l+i] + aiv;
            }
        }
        mint im = wm[2];
        for (int t = 1 << (k & 1), v = 1 << (k - 2 - (k & 1)), wi = k - (k & 1); v > 0; t <<= 2, v >>= 2, wi -= 2){
            mint ww = 1, xx = 1;
            int pl = 1 << wi;
            for (int j = 0; j < v; j++, ww *= wm[wi], xx = ww * ww){
                int j0 = l+j, j1 = j0 + v, j2 = j1 + v, j3 = j2 + v;
                for (int i = 0; i < t; i++, j0 += pl, j1 += pl, j2 += pl, j3 += pl){
                    mint a0 = a[j0], a1 = a[j1], a2 = a[j2], a3 = a[j3];
                    mint a0p2 = a0 + a2, a0m2 = (a0 - a2) * ww;
                    mint a1p3 = a1 + a3, a1m3 = (a1 - a3) * im * ww;
                    a[j0] = a0p2 + a1p3, a[j2] = (a0p2 - a1p3) * xx;
                    a[j1] = a0m2 + a1m3, a[j3] = (a0m2 - a1m3) * xx;
                }
            }
        }
    }
    void ifft4(vector<mint> &a, int k, int l = -1){
        if (k <= 0 || a.empty()) return ;
        if (l == -1) l = 0;
        if (k == 1){
            mint a1 = a[l+1];
            a[l+1] = a[l] - a1;
            a[l+0] += a1;
            return ;
        }
        mint im = wp[2];
        for (int v = 1, t = 1 << (k - 2), wi = 2; t > 0; v <<= 2, t >>= 2, wi += 2){
            mint ww = 1, xx = 1;
            int pl = 1 << wi;
            for (int j = 0; j < v; j++, ww *= wp[wi], xx = ww * ww){
                int j0 = l+j, j1 = j0 + v, j2 = j1 + v, j3 = j2 + v;
                for (int i = 0; i < t; i++, j0 += pl, j1 += pl, j2 += pl, j3 += pl){
                    mint a0 = a[j0], a1 = a[j1] * ww, a2 = a[j2] * xx, a3 = a[j3] * ww * xx;
                    mint a0p2 = a0 + a2, a0m2 = a0 - a2;
                    mint a1p3 = a1 + a3, a1m3 = (a1 - a3) * im;
                    a[j0] = a0p2 + a1p3, a[j2] = a0p2 - a1p3;
                    a[j1] = a0m2 + a1m3, a[j3] = a0m2 - a1m3;
                }
            }
        }
        if (k & 1){
            int v = 1 << (k - 1);
            mint ww = 1;
            for (int i = 0; i < v; i++, ww *= wp[k]){
                mint aiv = a[l+i+v] * ww;
                a[l+i+v] = a[l+i] - aiv;
                a[l+i] += aiv;
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