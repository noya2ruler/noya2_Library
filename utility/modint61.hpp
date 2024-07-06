#pragma once

#include "modint.hpp"

namespace noya2 {

template<>
struct static_modint<-61> {
    static constexpr unsigned long long mod(){
        return m;
    }
    static constexpr unsigned long long cal_mod(unsigned long long x){
        unsigned long long xu = x >> 61;
        unsigned long long xd = x & MASK61;
        unsigned long long res = xu + xd;
        if (res >= m) res -= m;
        return res;
    }
    constexpr static_modint() : _v(0) {}
    constexpr static_modint(long long x){
        while (x < 0) x += m;
        while (x >= (long long)m) x -= m;
        _v = x;
    }
    constexpr static_modint(unsigned long long x){
        while (x >= m) x -= m;
        _v = x;
    }
    using modint61 = static_modint;
    constexpr modint61 &operator+=(const modint61 &p){
        _v += p._v;
        if (_v >= m) _v -= m;
        return *this;
    }
    constexpr modint61 &operator-=(const modint61 &p){
        _v += m - p._v;
        if (_v >= m) _v -= m;
        return *this;
    }
    constexpr modint61 &operator*=(const modint61 &p){
        unsigned long long a = _v, b = p._v;
        unsigned long long au = a >> 31, ad = a & MASK31;
        unsigned long long bu = b >> 31, bd = b & MASK31;
        unsigned long long mid = ad * bu + au * bd;
        unsigned long long midu = mid >> 30, midd = mid & MASK30;
        _v = cal_mod(au * bu * 2 + midu + (midd << 31) + ad * bd);
        return *this;
    }
    constexpr modint61 &operator/=(const modint61 &p){
        *this *= p.inv();
        return *this;
    }
    friend constexpr modint61 operator+(const modint61 &lhs, const modint61 &rhs){
        return modint61(lhs) += rhs;
    }
    friend constexpr modint61 operator-(const modint61 &lhs, const modint61 &rhs){
        return modint61(lhs) -= rhs;
    }
    friend constexpr modint61 operator*(const modint61 &lhs, const modint61 &rhs){
        return modint61(lhs) *= rhs;
    }
    friend constexpr modint61 operator/(const modint61 &lhs, const modint61 &rhs){
        return modint61(lhs) /= rhs;
    }
    constexpr modint61 operator+() const {
        return *this;
    }
    constexpr modint61 operator-() const {
        return modint61() - *this;
    }
    constexpr modint61 inv() const {
        unsigned long long a = _v, b = m, u = 1, v = 0;
        while (b > 0){
            unsigned long long t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return modint61(u);
    }
    constexpr modint61 pow(long long n) const {
        modint61 ret(1ULL), mul(_v);
        while (n != 0){
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const modint61 &p){
        return os << p._v;
    }
    constexpr unsigned long long val() const {
        return _v;
    }
    constexpr auto operator<=>(const modint61 &) const = default;
    
  private:
    unsigned long long _v;
    static constexpr unsigned long long m = (1ULL << 61) - 1;
    static constexpr unsigned long long MASK30 = (1ULL << 30) - 1;
    static constexpr unsigned long long MASK31 = (1ULL << 31) - 1;
    static constexpr unsigned long long MASK61 = (1ULL << 61) - 1;
};
using modint61 = static_modint<-61>;

} // namespace noya2