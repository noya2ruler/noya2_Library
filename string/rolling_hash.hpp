#pragma once

#include"../template/template.hpp"

namespace noya2{

struct RollingHash {
    using ull = unsigned long long;
    RollingHash(const string &s = ""){ build(s);}
    ull get(int l, int r){ 
        assert(0 <= l && l <= r && r <= n);
        return cal_mod(inner_hash[r] + POSITIVISER - mul_mod(inner_hash[l], pow_base[r-l]));
    }
    static ull get_hash(const string &s){
        int len = s.size();
        set_hash();
        extend_pow_base(len);
        ull res = 0;
        for (int i = 0; i < len; i++) res = cal_mod(mul_mod(res,BASE) + s[i]);
        return res;
    }
    template<class... Hash_Lengths> static ull concat(const Hash_Lengths&... hash_length){
        return inner_concat(0ULL,hash_length...);
    }
  private:
    static ull inner_concat(const ull& temp){
        return temp;
    }
    template<class... Tail> static ull inner_concat(const ull& temp, const ull& hash, const int& len, const Tail&... tail){
        return inner_concat(cal_mod(cal_mod(mul_mod(temp,pow_base[len]))+hash),tail...);
    }
    static constexpr ull MASK30 = (1ULL << 30) - 1;
    static constexpr ull MASK31 = (1ULL << 31) - 1;
    static constexpr ull MASK61 = (1ULL << 61) - 1;
    static constexpr ull MOD = (1ULL << 61) - 1;
    static constexpr ull POSITIVISER = MOD * 4;
    static ull BASE;
    static vector<ull> pow_base;
    static ull mul_mod(ull a, ull b){
        ull au = a >> 31, ad = a & MASK31;
        ull bu = b >> 31, bd = b & MASK31;
        ull mid = ad * bu + au * bd;
        ull midu = mid >> 30, midd = mid & MASK30;
        return (au * bu * 2 + midu + (midd << 31) + ad * bd);
    }
    static ull cal_mod(ull x){
        ull xu = x >> 61;
        ull xd = x & MASK61;
        ull res = xu + xd;
        if (res >= MOD) res -= MOD;
        return res;
    }
    static void set_hash(){
        if (BASE == 0) BASE = (1UL<<31) + (random_device()() & MASK31);
    }
    static void extend_pow_base(int len){
        int nlen = pow_base.size();
        if (nlen > len) return ;
        pow_base.resize(len+1);
        for (int i = nlen; i <= len; i++){
            pow_base[i] = cal_mod(mul_mod(pow_base[i-1],BASE));
        }
    }
    string str;
    int n;
    vector<ull> inner_hash;
    void build(const string &s){
        set_hash();
        str = s;
        n = s.size();
        extend_pow_base(n);
        inner_hash.resize(n+1);
        inner_hash[0] = 0;
        for (int i = 0; i < n; i++) inner_hash[i+1] = cal_mod(mul_mod(inner_hash[i],BASE) + s[i]);
    }
};
using ull = unsigned long long;
ull RollingHash::BASE = 0;
vector<ull> RollingHash::pow_base = vector<ull>(1,1);
using roriha = RollingHash;

} // namespace noya2