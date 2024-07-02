---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/modint/arbitrary-montgomery-modint.hpp
  bundledCode: "#line 2 \"utility/modint_64bit.hpp\"\n\n#include <iostream>\n\nnamespace\
    \ noya2{\n\n/*\n\nsee : https://nyaannyaan.github.io/library/modint/arbitrary-montgomery-modint.hpp\n\
    \n*/\n\ntemplate <typename Int, typename UInt, typename Long, typename ULong,\
    \ int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n    using mint = ArbitraryLazyMontgomeryModIntBase;\n\
    \n    inline static UInt _mod;\n    inline static UInt r;\n    inline static UInt\
    \ n2;\n    static constexpr int bit_length = sizeof(UInt) * 8;\n\n    static UInt\
    \ get_r(){\n        UInt ret = _mod;\n        while (_mod * ret != 1) ret *= UInt(2)\
    \ - _mod * ret;\n        return ret;\n    }\n    static void set_mod(UInt m){\n\
    \        assert(m < (UInt(1u) << (bit_length - 2)));\n        assert((m & 1) ==\
    \ 1);\n        _mod = m, n2 = -ULong(m) % m, r = get_r();\n    }\n    UInt a;\n\
    \n    ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n    ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b) : a(reduce(ULong(b % _mod + _mod) * n2)) {}\n\n    static UInt reduce(const\
    \ ULong &b){\n        return (b + ULong(UInt(b) * UInt(-r)) * _mod) >> bit_length;\n\
    \    }\n\n    mint &operator+=(const mint &b){\n        if (Int(a += b.a - 2 *\
    \ _mod) < 0) a += 2 * _mod;\n        return *this;\n    }\n    mint &operator-=(const\
    \ mint &b){\n        if (Int(a -= b.a) < 0) a += 2 * _mod;\n        return *this;\n\
    \    }\n    mint &operator*=(const mint &b){\n        a = reduce(ULong(a) * b.a);\n\
    \        return *this;\n    }\n    mint &operator/=(const mint &b){\n        *this\
    \ *= b.inv();\n        return *this;\n    }\n\n    mint operator+(const mint &b)\
    \ const { return mint(*this) += b; }\n    mint operator-(const mint &b) const\
    \ { return mint(*this) -= b; }\n    mint operator*(const mint &b) const { return\
    \ mint(*this) *= b; }\n    mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n\n    bool operator==(const mint &b) const {\n        return (a >=\
    \ _mod ? a - _mod : a) == (b.a >= _mod ? b.a - _mod : b.a);\n    }\n    bool operator!=(const\
    \ mint &b) const {\n        return (a >= _mod ? a - _mod : a) != (b.a >= _mod\
    \ ? b.a - _mod : b.a);\n    }\n    mint operator-() const { return mint(0) - mint(*this);\
    \ }\n    mint operator+() const { return mint(*this); }\n\n    mint pow(ULong\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0){\n     \
    \       if (n & 1) ret *= mul;\n            mul *= mul, n >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &b){\n        return os << b.val();\n    }\n\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &b){\n        Long t;\n        is >> t;\n\
    \        b = ArbitraryLazyMontgomeryModIntBase(t);\n        return (is);\n   \
    \ }\n\n    mint inv() const {\n        Int x = val(), y = mod(), u = 1, v = 0;\n\
    \        while (y > 0){\n            Int t = x / y;\n            std::swap(x -=\
    \ t * y, y);\n            std::swap(u -= t * v, v);\n        }\n        return\
    \ mint{u};\n    }\n\n    UInt val() const {\n        UInt ret = reduce(a);\n \
    \       return ret >= _mod ? ret - _mod : ret;\n    }\n\n    static UInt mod()\
    \ { return _mod; }\n};\n\n// id \u306B\u9069\u5F53\u306A\u4E71\u6570\u3092\u5272\
    \u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt\
    \ = ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit = ArbitraryLazyMontgomeryModIntBase<long\
    \ long, unsigned long long, __int128_t, __uint128_t, id>;\n\ntemplate<int id>\n\
    using modint64bit = ArbitraryLazyMontgomeryModInt64bit<id>;\n\n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include <iostream>\n\nnamespace noya2{\n\n/*\n\nsee : https://nyaannyaan.github.io/library/modint/arbitrary-montgomery-modint.hpp\n\
    \n*/\n\ntemplate <typename Int, typename UInt, typename Long, typename ULong,\
    \ int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n    using mint = ArbitraryLazyMontgomeryModIntBase;\n\
    \n    inline static UInt _mod;\n    inline static UInt r;\n    inline static UInt\
    \ n2;\n    static constexpr int bit_length = sizeof(UInt) * 8;\n\n    static UInt\
    \ get_r(){\n        UInt ret = _mod;\n        while (_mod * ret != 1) ret *= UInt(2)\
    \ - _mod * ret;\n        return ret;\n    }\n    static void set_mod(UInt m){\n\
    \        assert(m < (UInt(1u) << (bit_length - 2)));\n        assert((m & 1) ==\
    \ 1);\n        _mod = m, n2 = -ULong(m) % m, r = get_r();\n    }\n    UInt a;\n\
    \n    ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n    ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b) : a(reduce(ULong(b % _mod + _mod) * n2)) {}\n\n    static UInt reduce(const\
    \ ULong &b){\n        return (b + ULong(UInt(b) * UInt(-r)) * _mod) >> bit_length;\n\
    \    }\n\n    mint &operator+=(const mint &b){\n        if (Int(a += b.a - 2 *\
    \ _mod) < 0) a += 2 * _mod;\n        return *this;\n    }\n    mint &operator-=(const\
    \ mint &b){\n        if (Int(a -= b.a) < 0) a += 2 * _mod;\n        return *this;\n\
    \    }\n    mint &operator*=(const mint &b){\n        a = reduce(ULong(a) * b.a);\n\
    \        return *this;\n    }\n    mint &operator/=(const mint &b){\n        *this\
    \ *= b.inv();\n        return *this;\n    }\n\n    mint operator+(const mint &b)\
    \ const { return mint(*this) += b; }\n    mint operator-(const mint &b) const\
    \ { return mint(*this) -= b; }\n    mint operator*(const mint &b) const { return\
    \ mint(*this) *= b; }\n    mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n\n    bool operator==(const mint &b) const {\n        return (a >=\
    \ _mod ? a - _mod : a) == (b.a >= _mod ? b.a - _mod : b.a);\n    }\n    bool operator!=(const\
    \ mint &b) const {\n        return (a >= _mod ? a - _mod : a) != (b.a >= _mod\
    \ ? b.a - _mod : b.a);\n    }\n    mint operator-() const { return mint(0) - mint(*this);\
    \ }\n    mint operator+() const { return mint(*this); }\n\n    mint pow(ULong\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0){\n     \
    \       if (n & 1) ret *= mul;\n            mul *= mul, n >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &b){\n        return os << b.val();\n    }\n\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &b){\n        Long t;\n        is >> t;\n\
    \        b = ArbitraryLazyMontgomeryModIntBase(t);\n        return (is);\n   \
    \ }\n\n    mint inv() const {\n        Int x = val(), y = mod(), u = 1, v = 0;\n\
    \        while (y > 0){\n            Int t = x / y;\n            std::swap(x -=\
    \ t * y, y);\n            std::swap(u -= t * v, v);\n        }\n        return\
    \ mint{u};\n    }\n\n    UInt val() const {\n        UInt ret = reduce(a);\n \
    \       return ret >= _mod ? ret - _mod : ret;\n    }\n\n    static UInt mod()\
    \ { return _mod; }\n};\n\n// id \u306B\u9069\u5F53\u306A\u4E71\u6570\u3092\u5272\
    \u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt\
    \ = ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit = ArbitraryLazyMontgomeryModIntBase<long\
    \ long, unsigned long long, __int128_t, __uint128_t, id>;\n\ntemplate<int id>\n\
    using modint64bit = ArbitraryLazyMontgomeryModInt64bit<id>;\n\n} // namespace\
    \ noya2"
  dependsOn: []
  isVerificationFile: false
  path: utility/modint_64bit.hpp
  requiredBy: []
  timestamp: '2024-07-03 01:34:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/modint_64bit.hpp
layout: document
redirect_from:
- /library/utility/modint_64bit.hpp
- /library/utility/modint_64bit.hpp.html
title: utility/modint_64bit.hpp
---
