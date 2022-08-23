#pragma once
#include "../kyopro/modint.hpp"

template<long long m>
struct NTT{
    using mint = modint<m>;
    NTT(){init();};
    static void FFT(vector<mint> &a){
        int n = a.size();
        int siz = 1;
        while (siz < n) siz <<= 1;
        a.resize(siz);
        fft(a,1);
    }
    static void IFFT(vector<mint> &a){
        int n = a.size();
        int siz = 1;
        while (siz < n) siz <<= 1;
        mint div = mint(siz).inv();
        a.resize(siz);
        fft(a,-1);
        for (auto &x : a) x *= div;
    }
    static void DFT(vector<mint> &a, int inv){fft(a,inv);}
    static vector<mint> multiply(vector<mint> a, vector<mint> b){
        int n = a.size() + b.size() - 1;
        int siz = 1;
        while (siz < n) siz <<= 1;
        a.resize(siz), b.resize(siz);
        FFT(a), FFT(b);
        for (int i = 0; i < siz; i++) a[i] *= b[i];
        IFFT(a);
        a.resize(n);
        return a;
    }
  private:
    static modint<m> g;
    static int limit;
    static vector<modint<m>>root, inv_root;
    static constexpr mint primitive_root(const long long &mo){
        if (mo == 2)         return mint(1);
        if (mo == 167772161) return mint(3);
        if (mo == 469762049) return mint(3);
        if (mo == 754974721) return mint(11);
        if (mo == 998244353) return mint(3);
        if (mo == 1224736769)return mint(3);
        return mint(); // atode kaku
    }
    static void init(){
        if (!root.empty()) return ;
        g = primitive_root(m);
        long long now = m-1;
        while ((now & 1) == 0) now >>= 1, limit++;
        root.resize(limit+1,1), inv_root.resize(limit+1,1);
        root[limit] = g.pow(now), inv_root[limit] /= root[limit];
        for(int i = limit-1; i >= 0; i--){
            root[i] = root[i+1] * root[i+1];
            inv_root[i] = inv_root[i+1] * inv_root[i+1];
        }
    }
    static int bits_msb(int v){
        v = v | (v >>  1);
        v = v | (v >>  2);
        v = v | (v >>  4);
        v = v | (v >>  8);
        v = v | (v >> 16);
        return v ^ (v >> 1);
    }
    static int pre(int v, int n){
        return v ^ (n - bits_msb(v));
    }
    static void fft(vector<mint> &a, int inv){
        init();
        int n = a.size();
        if (n == 1) return ;
        int d = 0;
        while ((n >> d & 1) == 0) d++;
        vector<int> idx(n);
        idx[n-1] = n-1;
        for (int i = n-2; i >= 0; i--) idx[i] = pre(idx[i+1],n);
        vector<mint> na = a;
        for (int i = 0; i < n; i++) a[i] = na[idx[i]];
        for (int i = 0; i < d; i++){
            int width = 1 << (i+1);
            vector<mint> gp(width/2,1);
            if (inv ==  1) for (int j = 0; j < width/2-1; j++) gp[j+1] = gp[j] * root[i+1];
            if (inv == -1) for (int j = 0; j < width/2-1; j++) gp[j+1] = gp[j] * inv_root[i+1];
            for (int j = 0; j < n; j += width){
                for (int k = 0; k < width/2; k++){
                    mint lhs = a[j+k], rhs = a[j+k+width/2] * gp[k];
                    a[j+k] = lhs + rhs;
                    a[j+k+width/2] = lhs - rhs;
                }
            }
        }
    }
};
template<long long m>
int NTT<m>::limit=0;
template<long long m>
vector<modint<m>>NTT<m>::root=vector<modint<m>>();
template<long long m>
vector<modint<m>>NTT<m>::inv_root=vector<modint<m>>();
template<long long m>
modint<m>NTT<m>::g=modint<m>();