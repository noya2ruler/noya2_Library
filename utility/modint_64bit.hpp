#pragma once

#include <iostream>

namespace noya2{

/*

see : https://nyaannyaan.github.io/library/modint/arbitrary-montgomery-modint.hpp

*/

template <typename Int, typename UInt, typename Long, typename ULong, int id>
struct ArbitraryLazyMontgomeryModIntBase {
    using mint = ArbitraryLazyMontgomeryModIntBase;

    inline static UInt _mod;
    inline static UInt r;
    inline static UInt n2;
    static constexpr int bit_length = sizeof(UInt) * 8;

    static UInt get_r(){
        UInt ret = _mod;
        while (_mod * ret != 1) ret *= UInt(2) - _mod * ret;
        return ret;
    }
    static void set_mod(UInt m){
        assert(m < (UInt(1u) << (bit_length - 2)));
        assert((m & 1) == 1);
        _mod = m, n2 = -ULong(m) % m, r = get_r();
    }
    UInt a;

    ArbitraryLazyMontgomeryModIntBase() : a(0) {}
    ArbitraryLazyMontgomeryModIntBase(const Long &b) : a(reduce(ULong(b % _mod + _mod) * n2)) {}

    static UInt reduce(const ULong &b){
        return (b + ULong(UInt(b) * UInt(-r)) * _mod) >> bit_length;
    }

    mint &operator+=(const mint &b){
        if (Int(a += b.a - 2 * _mod) < 0) a += 2 * _mod;
        return *this;
    }
    mint &operator-=(const mint &b){
        if (Int(a -= b.a) < 0) a += 2 * _mod;
        return *this;
    }
    mint &operator*=(const mint &b){
        a = reduce(ULong(a) * b.a);
        return *this;
    }
    mint &operator/=(const mint &b){
        *this *= b.inv();
        return *this;
    }

    mint operator+(const mint &b) const { return mint(*this) += b; }
    mint operator-(const mint &b) const { return mint(*this) -= b; }
    mint operator*(const mint &b) const { return mint(*this) *= b; }
    mint operator/(const mint &b) const { return mint(*this) /= b; }

    bool operator==(const mint &b) const {
        return (a >= _mod ? a - _mod : a) == (b.a >= _mod ? b.a - _mod : b.a);
    }
    bool operator!=(const mint &b) const {
        return (a >= _mod ? a - _mod : a) != (b.a >= _mod ? b.a - _mod : b.a);
    }
    mint operator-() const { return mint(0) - mint(*this); }
    mint operator+() const { return mint(*this); }

    mint pow(ULong n) const {
        mint ret(1), mul(*this);
        while (n > 0){
            if (n & 1) ret *= mul;
            mul *= mul, n >>= 1;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const mint &b){
        return os << b.val();
    }

    friend std::istream &operator>>(std::istream &is, mint &b){
        Long t;
        is >> t;
        b = ArbitraryLazyMontgomeryModIntBase(t);
        return (is);
    }

    mint inv() const {
        Int x = val(), y = mod(), u = 1, v = 0;
        while (y > 0){
            Int t = x / y;
            std::swap(x -= t * y, y);
            std::swap(u -= t * v, v);
        }
        return mint{u};
    }

    UInt val() const {
        UInt ret = reduce(a);
        return ret >= _mod ? ret - _mod : ret;
    }

    static UInt mod() { return _mod; }
};

// id に適当な乱数を割り当てて使う
template <int id>
using ArbitraryLazyMontgomeryModInt = ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned long long, id>;
template <int id>
using ArbitraryLazyMontgomeryModInt64bit = ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t, __uint128_t, id>;

template<int id>
using modint64bit = ArbitraryLazyMontgomeryModInt64bit<id>;

} // namespace noya2