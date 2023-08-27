#pragma once

#include"ntt_new.hpp"

namespace noya2{

template<Modint T>
struct RelaxedConvolution {
    RelaxedConvolution (int n) : f(n), g(n), h(2*n-1), q(0) {}
    uint join(T fq, T gq){
        f[q] = fq, g[q] = gq;
        int lsb = countr_zero(q+2);
        q_special = (q+2 == (1u<<lsb));
        update(lsb);
        return q;
    }
    const T operator[](int idx) const { return h[idx]; }
  private:
    void update(int lsb){
        task(lsb);
        rep(t,lsb+1){
            uint w = 1u<<t;
            T iv = T(2*w).inv();
            if (t <= 5){
                rep(i,w) rep(j,w) h[q+i+j] += f[q+1-w+i] * g[w-1+j];
            }
            else {
                vector<T> fg(2*w);
                rep(i,2*w) fg[i] = f_ffted[t][2*(q+1-w)+i] * g_ffted[t][2*(w-1)+i];
                ntt.ifft4(fg,t+1);
                rep(i,2*w-1) h[q+i] += fg[i] * iv;
            }
            if (q_special && t == lsb-1) break;
            if (t <= 5){
                rep(i,w) rep(j,w) h[q+i+j] += f[w-1+i] * g[q+1-w+j];
            }
            else {
                vector<T> fg(2*w);
                rep(i,2*w) fg[i] = f_ffted[t][2*(w-1)+i] * g_ffted[t][2*(q+1-w)+i];
                ntt.ifft4(fg,t+1);
                rep(i,2*w-1) h[q+i] += fg[i] * iv;
            }
        }
        q++;
    }
    void task(int lsb){
        if (q_special){
            int siz = (lsb <= 5 ? 0 : (int)(f.size())) * 2;
            f_ffted.emplace_back(vector<T>(siz));
            g_ffted.emplace_back(vector<T>(siz));
        }
        rep(t,lsb+1){
            if (q_special && t == lsb) break;
            if (t <= 5) continue;
            uint w = 1u<<t;
            rep(i,w){
                f_ffted[t][2*(q+1-w)+i] = f[q+1-w+i];
                g_ffted[t][2*(q+1-w)+i] = g[q+1-w+i];
            }
            ntt.fft4(f_ffted[t],t+1,2*(q+1-w));
            ntt.fft4(g_ffted[t],t+1,2*(q+1-w));
            if (q_special && t == lsb-1) break;
        }
    }
    vector<T> f, g, h;
    vector<vector<T>> f_ffted, g_ffted;
    uint q;
    bool q_special;
    NTT<T> ntt;
};

} // namesapce noya2