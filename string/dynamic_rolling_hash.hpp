#pragma once

#include <vector>
#include <string>
#include <random>
#include <cassert>

namespace noya2 {

struct dynamic_rolling_hash {
    dynamic_rolling_hash (const std::string &s = ""){
        build(s);
    }
    unsigned long long get(int l, int r){
        assert(0 <= l && l <= r && r <= n);
        return cal_mod(prefix_sum(r) + POSITIVISER - mul_mod(prefix_sum(l), pow_base[r - l]));
    }
    void update(int p, char nexc){
        assert(0 <= p && p < n);
        long long d = nexc - str[p];
        if (d < 0) d += MOD;
        change(p, d);
        str[p] = nexc;
    }
    static unsigned long long get_hash(const std::string &s){
        int len = s.size();
        set_base();
        extend_pow_base(len);
        unsigned long long res = 0;
        for (int i = 0; i < len; i++){
            res = cal_mod(mul_mod(res, BASE) + s[i]);
        }
        return res;
    }
  private:
    static constexpr unsigned long long MASK30 = (1ULL << 30) - 1;
    static constexpr unsigned long long MASK31 = (1ULL << 31) - 1;
    static constexpr unsigned long long MASK61 = (1ULL << 61) - 1;
    static constexpr unsigned long long MOD = (1ULL << 61) - 1;
    static constexpr unsigned long long POSITIVISER = MOD * 4;
    static inline unsigned long long BASE = 0;
    static inline std::vector<unsigned long long> pow_base = std::vector<unsigned long long>(1,1ULL);
    static unsigned long long mul_mod(unsigned long long a, unsigned long long b){
        unsigned long long au = a >> 31, ad = a & MASK31;
        unsigned long long bu = b >> 31, bd = b & MASK31;
        unsigned long long mid = ad * bu + au * bd;
        unsigned long long midu = mid >> 30, midd = mid & MASK30;
        return (au * bu * 2 + midu + (midd << 31) + ad * bd);
    }
    static unsigned long long cal_mod(unsigned long long x){
        unsigned long long xu = x >> 61;
        unsigned long long xd = x & MASK61;
        unsigned long long res = xu + xd;
        if (res >= MOD) res -= MOD;
        return res;
    }
    static void set_base(){
        if (BASE == 0){
            BASE = (1ULL << 31) + (std::random_device()() & MASK31);
        }
    }
    static void extend_pow_base(int len){
        int nlen = pow_base.size();
        if (nlen > len) return ;
        pow_base.resize(len+1);
        for (int i = nlen; i <= len; i++){
            pow_base[i] = cal_mod(mul_mod(pow_base[i-1], BASE));
        }
    }
    void change(int p, unsigned long long add){
        p++;
        while (p <= n){
            inner_hash[p - 1] = cal_mod(inner_hash[p - 1] + add);
            add = cal_mod(mul_mod(add, pow_base[p & -p]));
            p += p & -p;
        }
    }
    unsigned long long prefix_sum(int r){
        int tr = r;
        unsigned long long s = 0;
        while (r > 0){
            s = cal_mod(mul_mod(inner_hash[r - 1], pow_base[tr - r]) + s);
            r -= r & -r;
        }
        return s;
    }
    int n;
    std::string str;
    std::vector<unsigned long long> inner_hash;
    void build(const std::string &s){
        set_base();
        str = s;
        n = s.size();
        extend_pow_base(n);
        inner_hash.resize(n, 0);
        for (int i = 0; i < n; i++){
            change(i, (unsigned long long)(s[i]));
        }
    }
};

using droriha = dynamic_rolling_hash;

} // namespace noya2