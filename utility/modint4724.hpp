#pragma once

#include "modint.hpp"

namespace noya2 {

template<>
struct static_modint<-4724> {
    static constexpr unsigned long long mod(){
        return m;
    }
    static constexpr unsigned long long cal_mod(unsigned long long x){
        unsigned long long xu = x >> 47;
        unsigned long long xd = x & MASK47;
        unsigned long long res = (xu << 24) + xd - xu;
        if (res >= m) res -= m;
        return res;
    }
    constexpr static_modint() : _v(0) {}
    constexpr static_modint(long long x){
        if (x < 0){
            _v = cal_mod(-x);
            if (_v != 0){
                _v = m - _v;
            }
        }
        else {
            _v = cal_mod(x);
        }
    }
    constexpr static_modint(unsigned long long x){
        _v = cal_mod(x);
    }
    template<std::signed_integral T>
    constexpr static_modint(T x) : static_modint((long long)x) {}
    template<std::unsigned_integral T>
    constexpr static_modint(T x) : static_modint((unsigned long long)x) {}
    
    using modint4724 = static_modint;
    constexpr modint4724 &operator+=(const modint4724 &p){
        _v += p._v;
        if (_v >= m) _v -= m;
        return *this;
    }
    constexpr modint4724 &operator-=(const modint4724 &p){
        _v += m - p._v;
        if (_v >= m) _v -= m;
        return *this;
    }
    constexpr modint4724 &operator*=(const modint4724 &p){
        unsigned long long a = _v, b = p._v;
        unsigned long long au = a >> 24, ad = a & MASK24;
        unsigned long long bu = b >> 24, bd = b & MASK24;
        unsigned long long X = (au + ad) * (bu + bd);
        unsigned long long Y = ad * bd;
        unsigned long long Z = au * bu;
        unsigned long long A = X - Y + Z, B = Y + m4 - 2*Z;
        unsigned long long Au = A >> 23, Ad = A & MASK23;
        _v = cal_mod(((Au + Ad) << 24) + B + m - Au);
        return *this;
    }
    constexpr modint4724 &operator/=(const modint4724 &p){
        *this *= p.inv();
        return *this;
    }
    friend constexpr modint4724 operator+(const modint4724 &lhs, const modint4724 &rhs){
        return modint4724(lhs) += rhs;
    }
    friend constexpr modint4724 operator-(const modint4724 &lhs, const modint4724 &rhs){
        return modint4724(lhs) -= rhs;
    }
    friend constexpr modint4724 operator*(const modint4724 &lhs, const modint4724 &rhs){
        return modint4724(lhs) *= rhs;
    }
    friend constexpr modint4724 operator/(const modint4724 &lhs, const modint4724 &rhs){
        return modint4724(lhs) /= rhs;
    }
    constexpr modint4724 operator+() const {
        return *this;
    }
    constexpr modint4724 operator-() const {
        return modint4724() - *this;
    }
    constexpr modint4724 inv() const {
        long long a = _v, b = m, u = 1, v = 0;
        while (b > 0){
            long long t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return modint4724(u);
    }
    constexpr modint4724 pow(long long n) const {
        modint4724 ret(1ULL), mul(_v);
        while (n != 0){
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::istream &operator>>(std::istream &is, modint4724 &p){
        unsigned long long x;
        is >> x;
        p = modint4724(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const modint4724 &p){
        return os << p._v;
    }
    constexpr unsigned long long val() const {
        return _v;
    }
    constexpr auto operator<=>(const modint4724 &) const = default;

  private:
    unsigned long long _v;
    static constexpr unsigned long long m = (1ULL << 47) - (1ULL << 24) + 1;
    static constexpr unsigned long long m4 = m << 2;
    static constexpr unsigned long long MASK23 = (1ULL << 23) - 1;
    static constexpr unsigned long long MASK24 = (1ULL << 24) - 1;
    static constexpr unsigned long long MASK47 = (1ULL << 47) - 1;
};
using modint4724 = static_modint<-4724>;

} // namespace noya2