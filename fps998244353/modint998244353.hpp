#pragma once

#include <cassert>

#include "../utility/modint.hpp"

namespace noya2 {

template <>
struct static_modint<998244353> {
    using mint = static_modint;
  public:
    static constexpr int mod() { return 998244353; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }
    constexpr static_modint() : _v(0) {}
    template<std::signed_integral T>
    constexpr static_modint(T v){
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template<std::unsigned_integral T>
    constexpr static_modint(T v){
        _v = (unsigned int)(v % umod());
    }
    constexpr unsigned int val() const { return _v; }
    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }
    constexpr mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    constexpr mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    constexpr mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    constexpr mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    constexpr mint operator+() const { return *this; }
    constexpr mint operator-() const { return mint() - *this; }
    constexpr mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    constexpr mint inv() const {
        assert(_v);
        return pow(umod() - 2);
    }
    friend constexpr mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend constexpr mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend constexpr mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend constexpr mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend constexpr bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend constexpr bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint& p) {
        return os << p.val();
    }
    friend std::istream &operator>>(std::istream &is, mint &a) {
        long long t; is >> t;
        a = mint(t);
        return (is);
    }

    unsigned int _v;
    static constexpr int primitive_root_constexpr_v = 3;
  private:
    static constexpr unsigned int umod() { return 998244353u; }
    static constexpr bool prime = true;
};

} // namespace noya2