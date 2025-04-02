---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/prime.hpp
    title: math/prime.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/FrequencyTableofTreeDistance.test.cpp
    title: test/tree/FrequencyTableofTreeDistance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/modint4724.hpp\"\n\n#line 2 \"utility/modint.hpp\"\
    \n\n#include <iostream>\n\n#line 2 \"math/prime.hpp\"\n\n#include<utility>\nnamespace\
    \ noya2 {\n\nconstexpr long long safe_mod(long long x, long long m) {\n    x %=\
    \ m;\n    if (x < 0) x += m;\n    return x;\n}\n\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\nconstexpr\
    \ bool is_prime_constexpr(int n) {\n    if (n <= 1) return false;\n    if (n ==\
    \ 2 || n == 7 || n == 61) return true;\n    if (n % 2 == 0) return false;\n  \
    \  long long d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    constexpr long long\
    \ bases[3] = {2, 7, 61};\n    for (long long a : bases) {\n        long long t\
    \ = d;\n        long long y = pow_mod_constexpr(a, t, n);\n        while (t !=\
    \ n - 1 && y != 1 && y != n - 1) {\n            y = y * y % n;\n            t\
    \ <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\ntemplate <int n> constexpr bool\
    \ is_prime_flag = is_prime_constexpr(n);\n\nconstexpr std::pair<long long, long\
    \ long> inv_gcd(long long a, long long b) {\n    a = safe_mod(a, b);\n    if (a\
    \ == 0) return {b, 0};\n    long long s = b, t = a;\n    long long m0 = 0, m1\
    \ = 1;\n    while (t) {\n        long long u = s / t;\n        s -= t * u;\n \
    \       m0 -= m1 * u; \n        auto tmp = s;\n        s = t;\n        t = tmp;\n\
    \        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0)\
    \ m0 += b / s;\n    return {s, m0};\n}\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int\
    \ x = (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long\
    \ long)(i)*i <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++]\
    \ = i;\n            while (x % i == 0) {\n                x /= i;\n          \
    \  }\n        }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n  \
    \  for (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i\
    \ < cnt; i++) {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) ==\
    \ 1) {\n                ok = false;\n                break;\n            }\n \
    \       }\n        if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int\
    \ primitive_root_flag = primitive_root_constexpr(m);\n\n} // namespace noya2\n\
    #line 6 \"utility/modint.hpp\"\n\nnamespace noya2{\n\nstruct barrett {\n    unsigned\
    \ int _m;\n    unsigned long long im;\n    explicit barrett(unsigned int m) :\
    \ _m(m), im((unsigned long long)(-1) / m + 1) {}\n    unsigned int umod() const\
    \ { return _m; }\n    unsigned int mul(unsigned int a, unsigned int b) const {\n\
    \        unsigned long long z = a;\n        z *= b;\n        unsigned long long\
    \ x = (unsigned long long)((__uint128_t(z) * im) >> 64);\n        unsigned int\
    \ v = (unsigned int)(z - x * _m);\n        if (_m <= v) v += _m;\n        return\
    \ v;\n    }\n};\n\ntemplate <int m>\nstruct static_modint {\n    using mint =\
    \ static_modint;\n  public:\n    static constexpr int mod() { return m; }\n  \
    \  static mint raw(int v) {\n        mint x;\n        x._v = v;\n        return\
    \ x;\n    }\n    constexpr static_modint() : _v(0) {}\n    template<std::signed_integral\
    \ T>\n    constexpr static_modint(T v){\n        long long x = (long long)(v %\
    \ (long long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned\
    \ int)(x);\n    }\n    template<std::unsigned_integral T>\n    constexpr static_modint(T\
    \ v){\n        _v = (unsigned int)(v % umod());\n    }\n    constexpr unsigned\
    \ int val() const { return _v; }\n    mint& operator++() {\n        _v++;\n  \
    \      if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n    constexpr mint&\
    \ operator+=(const mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod())\
    \ _v -= umod();\n        return *this;\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n\
    \        return *this;\n    }\n    constexpr mint& operator*=(const mint& rhs)\
    \ {\n        unsigned long long z = _v;\n        z *= rhs._v;\n        _v = (unsigned\
    \ int)(z % umod());\n        return *this;\n    }\n    constexpr mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inv(); }\n    constexpr mint operator+()\
    \ const { return *this; }\n    constexpr mint operator-() const { return mint()\
    \ - *this; }\n    constexpr mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    constexpr mint inv() const {\n        if (prime) {\n \
    \           assert(_v);\n            return pow(umod() - 2);\n        } else {\n\
    \            auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n \
    \           return eg.second;\n        }\n    }\n    friend constexpr mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n   \
    \ friend constexpr mint operator-(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) -= rhs;\n    }\n    friend constexpr mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend constexpr mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend constexpr bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend constexpr bool operator!=(const mint& lhs, const mint& rhs) {\n     \
    \   return lhs._v != rhs._v;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint& p) {\n        return os << p.val();\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &a) {\n        long long t; is >> t;\n  \
    \      a = mint(t);\n        return (is);\n    }\n\n  private:\n    unsigned int\
    \ _v;\n    static constexpr unsigned int umod() { return m; }\n    static constexpr\
    \ bool prime = is_prime_flag<m>;\n};\n\n\ntemplate <int id> struct dynamic_modint\
    \ {\n    using mint = dynamic_modint;\n  public:\n    static int mod() { return\
    \ (int)(bt.umod()); }\n    static void set_mod(int m) {\n        assert(1 <= m);\n\
    \        bt = barrett(m);\n    }\n    static mint raw(int v) {\n        mint x;\n\
    \        x._v = v;\n        return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n\
    \    template<std::signed_integral T>\n    dynamic_modint(T v){\n        long\
    \ long x = (long long)(v % (long long)(umod()));\n        if (x < 0) x += umod();\n\
    \        _v = (unsigned int)(x);\n    }\n    template<std::unsigned_integral T>\n\
    \    dynamic_modint(T v){\n        _v = (unsigned int)(v % umod());\n    }\n \
    \   unsigned int val() const { return _v; }\n    mint& operator++() {\n      \
    \  _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n    }\n  \
    \  mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n  \
    \      return *this;\n    }\n    mint operator++(int) {\n        mint result =\
    \ *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n     \
    \   if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v >= umod()) _v -=\
    \ umod();\n        return *this;\n    }\n    mint& operator*=(const mint& rhs)\
    \ {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n    mint&\
    \ operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n    mint\
    \ operator+() const { return *this; }\n    mint operator-() const { return mint()\
    \ - *this; }\n    mint pow(long long n) const {\n        assert(0 <= n);\n   \
    \     mint x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *=\
    \ x;\n            x *= x;\n            n >>= 1;\n        }\n        return r;\n\
    \    }\n    mint inv() const {\n        auto eg = noya2::inv_gcd(_v, mod());\n\
    \        assert(eg.first == 1);\n        return eg.second;\n    }\n    friend\
    \ mint operator+(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static barrett\
    \ bt;\n    static unsigned int umod() { return bt.umod(); }\n};\ntemplate <int\
    \ id> noya2::barrett dynamic_modint<id>::bt(998244353);\n\nusing modint998244353\
    \ = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n\ntemplate<typename T>\nconcept Modint = requires\
    \ (T &a){\n    T::mod();\n    a.inv();\n    a.val();\n    a.pow(declval<int>());\n\
    };\n\n} // namespace noya2\n#line 4 \"utility/modint4724.hpp\"\n\nnamespace noya2\
    \ {\n\ntemplate<>\nstruct static_modint<-4724> {\n    static constexpr unsigned\
    \ long long mod(){\n        return m;\n    }\n    static constexpr unsigned long\
    \ long cal_mod(unsigned long long x){\n        unsigned long long xu = x >> 47;\n\
    \        unsigned long long xd = x & MASK47;\n        unsigned long long res =\
    \ (xu << 24) + xd - xu;\n        if (res >= m) res -= m;\n        return res;\n\
    \    }\n    constexpr static_modint() : _v(0) {}\n    constexpr static_modint(long\
    \ long x){\n        if (x < 0){\n            _v = cal_mod(-x);\n            if\
    \ (_v != 0){\n                _v = m - _v;\n            }\n        }\n       \
    \ else {\n            _v = cal_mod(x);\n        }\n    }\n    constexpr static_modint(unsigned\
    \ long long x){\n        _v = cal_mod(x);\n    }\n    template<std::signed_integral\
    \ T>\n    constexpr static_modint(T x) : static_modint((long long)x) {}\n    template<std::unsigned_integral\
    \ T>\n    constexpr static_modint(T x) : static_modint((unsigned long long)x)\
    \ {}\n    \n    using modint4724 = static_modint;\n    constexpr modint4724 &operator+=(const\
    \ modint4724 &p){\n        _v += p._v;\n        if (_v >= m) _v -= m;\n      \
    \  return *this;\n    }\n    constexpr modint4724 &operator-=(const modint4724\
    \ &p){\n        _v += m - p._v;\n        if (_v >= m) _v -= m;\n        return\
    \ *this;\n    }\n    constexpr modint4724 &operator*=(const modint4724 &p){\n\
    \        unsigned long long a = _v, b = p._v;\n        unsigned long long au =\
    \ a >> 24, ad = a & MASK24;\n        unsigned long long bu = b >> 24, bd = b &\
    \ MASK24;\n        unsigned long long X = (au + ad) * (bu + bd);\n        unsigned\
    \ long long Y = ad * bd;\n        unsigned long long Z = au * bu;\n        unsigned\
    \ long long A = X - Y + Z, B = Y + m4 - 2*Z;\n        unsigned long long Au =\
    \ A >> 23, Ad = A & MASK23;\n        _v = cal_mod(((Au + Ad) << 24) + B + m -\
    \ Au);\n        return *this;\n    }\n    constexpr modint4724 &operator/=(const\
    \ modint4724 &p){\n        *this *= p.inv();\n        return *this;\n    }\n \
    \   friend constexpr modint4724 operator+(const modint4724 &lhs, const modint4724\
    \ &rhs){\n        return modint4724(lhs) += rhs;\n    }\n    friend constexpr\
    \ modint4724 operator-(const modint4724 &lhs, const modint4724 &rhs){\n      \
    \  return modint4724(lhs) -= rhs;\n    }\n    friend constexpr modint4724 operator*(const\
    \ modint4724 &lhs, const modint4724 &rhs){\n        return modint4724(lhs) *=\
    \ rhs;\n    }\n    friend constexpr modint4724 operator/(const modint4724 &lhs,\
    \ const modint4724 &rhs){\n        return modint4724(lhs) /= rhs;\n    }\n   \
    \ constexpr modint4724 operator+() const {\n        return *this;\n    }\n   \
    \ constexpr modint4724 operator-() const {\n        return modint4724() - *this;\n\
    \    }\n    constexpr modint4724 inv() const {\n        long long a = _v, b =\
    \ m, u = 1, v = 0;\n        while (b > 0){\n            long long t = a / b;\n\
    \            std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n\
    \        }\n        return modint4724(u);\n    }\n    constexpr modint4724 pow(long\
    \ long n) const {\n        modint4724 ret(1ULL), mul(_v);\n        while (n !=\
    \ 0){\n            if (n & 1) ret *= mul;\n            mul *= mul;\n         \
    \   n >>= 1;\n        }\n        return ret;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, modint4724 &p){\n        unsigned long long x;\n        is >> x;\n    \
    \    p = modint4724(x);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const modint4724 &p){\n        return os << p._v;\n    }\n    constexpr\
    \ unsigned long long val() const {\n        return _v;\n    }\n    constexpr auto\
    \ operator<=>(const modint4724 &) const = default;\n\n  private:\n    unsigned\
    \ long long _v;\n    static constexpr unsigned long long m = (1ULL << 47) - (1ULL\
    \ << 24) + 1;\n    static constexpr unsigned long long m4 = m << 2;\n    static\
    \ constexpr unsigned long long MASK23 = (1ULL << 23) - 1;\n    static constexpr\
    \ unsigned long long MASK24 = (1ULL << 24) - 1;\n    static constexpr unsigned\
    \ long long MASK47 = (1ULL << 47) - 1;\n};\nusing modint4724 = static_modint<-4724>;\n\
    \n} // namespace noya2\n"
  code: "#pragma once\n\n#include \"modint.hpp\"\n\nnamespace noya2 {\n\ntemplate<>\n\
    struct static_modint<-4724> {\n    static constexpr unsigned long long mod(){\n\
    \        return m;\n    }\n    static constexpr unsigned long long cal_mod(unsigned\
    \ long long x){\n        unsigned long long xu = x >> 47;\n        unsigned long\
    \ long xd = x & MASK47;\n        unsigned long long res = (xu << 24) + xd - xu;\n\
    \        if (res >= m) res -= m;\n        return res;\n    }\n    constexpr static_modint()\
    \ : _v(0) {}\n    constexpr static_modint(long long x){\n        if (x < 0){\n\
    \            _v = cal_mod(-x);\n            if (_v != 0){\n                _v\
    \ = m - _v;\n            }\n        }\n        else {\n            _v = cal_mod(x);\n\
    \        }\n    }\n    constexpr static_modint(unsigned long long x){\n      \
    \  _v = cal_mod(x);\n    }\n    template<std::signed_integral T>\n    constexpr\
    \ static_modint(T x) : static_modint((long long)x) {}\n    template<std::unsigned_integral\
    \ T>\n    constexpr static_modint(T x) : static_modint((unsigned long long)x)\
    \ {}\n    \n    using modint4724 = static_modint;\n    constexpr modint4724 &operator+=(const\
    \ modint4724 &p){\n        _v += p._v;\n        if (_v >= m) _v -= m;\n      \
    \  return *this;\n    }\n    constexpr modint4724 &operator-=(const modint4724\
    \ &p){\n        _v += m - p._v;\n        if (_v >= m) _v -= m;\n        return\
    \ *this;\n    }\n    constexpr modint4724 &operator*=(const modint4724 &p){\n\
    \        unsigned long long a = _v, b = p._v;\n        unsigned long long au =\
    \ a >> 24, ad = a & MASK24;\n        unsigned long long bu = b >> 24, bd = b &\
    \ MASK24;\n        unsigned long long X = (au + ad) * (bu + bd);\n        unsigned\
    \ long long Y = ad * bd;\n        unsigned long long Z = au * bu;\n        unsigned\
    \ long long A = X - Y + Z, B = Y + m4 - 2*Z;\n        unsigned long long Au =\
    \ A >> 23, Ad = A & MASK23;\n        _v = cal_mod(((Au + Ad) << 24) + B + m -\
    \ Au);\n        return *this;\n    }\n    constexpr modint4724 &operator/=(const\
    \ modint4724 &p){\n        *this *= p.inv();\n        return *this;\n    }\n \
    \   friend constexpr modint4724 operator+(const modint4724 &lhs, const modint4724\
    \ &rhs){\n        return modint4724(lhs) += rhs;\n    }\n    friend constexpr\
    \ modint4724 operator-(const modint4724 &lhs, const modint4724 &rhs){\n      \
    \  return modint4724(lhs) -= rhs;\n    }\n    friend constexpr modint4724 operator*(const\
    \ modint4724 &lhs, const modint4724 &rhs){\n        return modint4724(lhs) *=\
    \ rhs;\n    }\n    friend constexpr modint4724 operator/(const modint4724 &lhs,\
    \ const modint4724 &rhs){\n        return modint4724(lhs) /= rhs;\n    }\n   \
    \ constexpr modint4724 operator+() const {\n        return *this;\n    }\n   \
    \ constexpr modint4724 operator-() const {\n        return modint4724() - *this;\n\
    \    }\n    constexpr modint4724 inv() const {\n        long long a = _v, b =\
    \ m, u = 1, v = 0;\n        while (b > 0){\n            long long t = a / b;\n\
    \            std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n\
    \        }\n        return modint4724(u);\n    }\n    constexpr modint4724 pow(long\
    \ long n) const {\n        modint4724 ret(1ULL), mul(_v);\n        while (n !=\
    \ 0){\n            if (n & 1) ret *= mul;\n            mul *= mul;\n         \
    \   n >>= 1;\n        }\n        return ret;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, modint4724 &p){\n        unsigned long long x;\n        is >> x;\n    \
    \    p = modint4724(x);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const modint4724 &p){\n        return os << p._v;\n    }\n    constexpr\
    \ unsigned long long val() const {\n        return _v;\n    }\n    constexpr auto\
    \ operator<=>(const modint4724 &) const = default;\n\n  private:\n    unsigned\
    \ long long _v;\n    static constexpr unsigned long long m = (1ULL << 47) - (1ULL\
    \ << 24) + 1;\n    static constexpr unsigned long long m4 = m << 2;\n    static\
    \ constexpr unsigned long long MASK23 = (1ULL << 23) - 1;\n    static constexpr\
    \ unsigned long long MASK24 = (1ULL << 24) - 1;\n    static constexpr unsigned\
    \ long long MASK47 = (1ULL << 47) - 1;\n};\nusing modint4724 = static_modint<-4724>;\n\
    \n} // namespace noya2"
  dependsOn:
  - utility/modint.hpp
  - math/prime.hpp
  isVerificationFile: false
  path: utility/modint4724.hpp
  requiredBy: []
  timestamp: '2025-02-26 00:46:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/FrequencyTableofTreeDistance.test.cpp
documentation_of: utility/modint4724.hpp
layout: document
redirect_from:
- /library/utility/modint4724.hpp
- /library/utility/modint4724.hpp.html
title: utility/modint4724.hpp
---
