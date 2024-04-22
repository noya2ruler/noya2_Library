---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_modint.hpp
    title: fps/fps_modint.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_ntt.hpp
    title: fps/fps_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/multipoint_evaluation.hpp
    title: fps/multipoint_evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt.hpp
    title: fps/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/relaxed_convolution.hpp
    title: fps/relaxed_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sample_point_shift.hpp
    title: fps/sample_point_shift.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
    title: test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Convolution1000000007.test.cpp
    title: test/fps/Convolution1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Inv_of_Formal_Power_Series.test.cpp
    title: test/fps/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
    title: test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
    title: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/convolution.test.cpp
    title: test/fps/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/convolution_relaxed_convolution.test.cpp
    title: test/fps/convolution_relaxed_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Determinant_of_Matrix.test.cpp
    title: test/math/Determinant_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Gcd_Convolution.test.cpp
    title: test/math/Gcd_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Lcm_Convolution.test.cpp
    title: test/math/Lcm_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/modint.hpp\"\n\n#line 2 \"math/prime.hpp\"\n\n#include<utility>\n\
    namespace noya2 {\n\nconstexpr long long safe_mod(long long x, long long m) {\n\
    \    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\nconstexpr long long\
    \ pow_mod_constexpr(long long x, long long n, int m) {\n    if (m == 1) return\
    \ 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned long long r = 1;\n\
    \    unsigned long long y = safe_mod(x, m);\n    while (n) {\n        if (n &\
    \ 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n \
    \   return r;\n}\n\nconstexpr bool is_prime_constexpr(int n) {\n    if (n <= 1)\
    \ return false;\n    if (n == 2 || n == 7 || n == 61) return true;\n    if (n\
    \ % 2 == 0) return false;\n    long long d = n - 1;\n    while (d % 2 == 0) d\
    \ /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for (long long a\
    \ : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime_flag = is_prime_constexpr(n);\n\nconstexpr\
    \ std::pair<long long, long long> inv_gcd(long long a, long long b) {\n    a =\
    \ safe_mod(a, b);\n    if (a == 0) return {b, 0};\n    long long s = b, t = a;\n\
    \    long long m0 = 0, m1 = 1;\n    while (t) {\n        long long u = s / t;\n\
    \        s -= t * u;\n        m0 -= m1 * u; \n        auto tmp = s;\n        s\
    \ = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n\
    \    }\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\nconstexpr int\
    \ primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m == 167772161)\
    \ return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721) return\
    \ 11;\n    if (m == 998244353) return 3;\n    int divs[20] = {};\n    divs[0]\
    \ = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /=\
    \ 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x % i\
    \ == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0) {\n  \
    \              x /= i;\n            }\n        }\n    }\n    if (x > 1) {\n  \
    \      divs[cnt++] = x;\n    }\n    for (int g = 2;; g++) {\n        bool ok =\
    \ true;\n        for (int i = 0; i < cnt; i++) {\n            if (pow_mod_constexpr(g,\
    \ (m - 1) / divs[i], m) == 1) {\n                ok = false;\n               \
    \ break;\n            }\n        }\n        if (ok) return g;\n    }\n}\ntemplate\
    \ <int m> constexpr int primitive_root_flag = primitive_root_constexpr(m);\n\n\
    } // namespace noya2\n#line 4 \"utility/modint.hpp\"\n\nnamespace noya2{\n\nstruct\
    \ barrett {\n    uint _m;\n    ull  im;\n    explicit barrett(uint m) : _m(m),\
    \ im((ull)(-1) / m + 1) {}\n    uint umod() const { return _m; }\n    uint mul(uint\
    \ a, uint b) const {\n        ull z = a;\n        z *= b;\n        ull x = ull((__uint128_t(z)\
    \ * im) >> 64);\n        uint v = (uint)(z - x * _m);\n        if (_m <= v) v\
    \ += _m;\n        return v;\n    }\n};\n\ntemplate <int m>\nstruct static_modint\
    \ {\n    using mint = static_modint;\n  public:\n    static constexpr int mod()\
    \ { return m; }\n    static mint raw(int v) {\n        mint x;\n        x._v =\
    \ v;\n        return x;\n    }\n    constexpr static_modint() : _v(0) {}\n   \
    \ template<signed_integral T>\n    constexpr static_modint(T v){\n        ll x\
    \ = (ll)(v % (ll)(umod()));\n        if (x < 0) x += umod();\n        _v = (uint)(x);\n\
    \    }\n    template<unsigned_integral T>\n    constexpr static_modint(T v){\n\
    \        _v = (uint)(v % umod());\n    }\n    constexpr unsigned int val() const\
    \ { return _v; }\n    mint& operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n    constexpr mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    constexpr mint& operator-=(const mint& rhs)\
    \ {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return\
    \ *this;\n    }\n    constexpr mint& operator*=(const mint& rhs) {\n        ull\
    \ z = _v;\n        z *= rhs._v;\n        _v = (uint)(z % umod());\n        return\
    \ *this;\n    }\n    constexpr mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n    constexpr mint operator+() const { return *this;\
    \ }\n    constexpr mint operator-() const { return mint() - *this; }\n    constexpr\
    \ mint pow(ll n) const {\n        assert(0 <= n);\n        mint x = *this, r =\
    \ 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    constexpr mint\
    \ inv() const {\n        if (prime) {\n            assert(_v);\n            return\
    \ pow(umod() - 2);\n        } else {\n            auto eg = inv_gcd(_v, m);\n\
    \            assert(eg.first == 1);\n            return eg.second;\n        }\n\
    \    }\n    friend constexpr mint operator+(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) += rhs;\n    }\n    friend constexpr mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend constexpr mint operator*(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) *= rhs;\n    }\n    friend constexpr mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend constexpr bool operator==(const mint& lhs, const mint& rhs) {\n     \
    \   return lhs._v == rhs._v;\n    }\n    friend constexpr bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr\
    \ unsigned int umod() { return m; }\n    static constexpr bool prime = is_prime_flag<m>;\n\
    };\n\n\ntemplate <int id> struct dynamic_modint {\n    using mint = dynamic_modint;\n\
    \  public:\n    static int mod() { return (int)(bt.umod()); }\n    static void\
    \ set_mod(int m) {\n        assert(1 <= m);\n        bt = barrett(m);\n    }\n\
    \    static mint raw(int v) {\n        mint x;\n        x._v = v;\n        return\
    \ x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template<signed_integral T>\n\
    \    dynamic_modint(T v){\n        ll x = (ll)(v % (ll)(mod()));\n        if (x\
    \ < 0) x += mod();\n        _v = (uint)(x);\n    }\n    template<unsigned_integral\
    \ T>\n    dynamic_modint(T v){\n        _v = (uint)(v % mod());\n    }\n    uint\
    \ val() const { return _v; }\n    mint& operator++() {\n        _v++;\n      \
    \  if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v += mod() - rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint& rhs) {\n        _v = bt.mul(_v,\
    \ rhs._v);\n        return *this;\n    }\n    mint& operator/=(const mint& rhs)\
    \ { return *this = *this * rhs.inv(); }\n    mint operator+() const { return *this;\
    \ }\n    mint operator-() const { return mint() - *this; }\n    mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n \
    \       while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n   \
    \         n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ {\n        auto eg = noya2::inv_gcd(_v, mod());\n        assert(eg.first ==\
    \ 1);\n        return eg.second;\n    }\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend\
    \ mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend bool operator==(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ == rhs._v;\n    }\n    friend bool operator!=(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v != rhs._v;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint& p) {\n        return os << p.val();\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &a) {\n        long long t; is >> t;\n  \
    \      a = mint(t);\n        return (is);\n    }\n\n  private:\n    unsigned int\
    \ _v;\n    static barrett bt;\n    static unsigned int umod() { return bt.umod();\
    \ }\n};\ntemplate <int id> noya2::barrett dynamic_modint<id>::bt(998244353);\n\
    \nusing modint998244353 = static_modint<998244353>;\nusing modint1000000007 =\
    \ static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\ntemplate<typename\
    \ T>\nconcept Modint = requires (T &a){\n    T::mod();\n    a.inv();\n    a.val();\n\
    \    a.pow(declval<int>());\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../math/prime.hpp\"\n\nnamespace noya2{\n\nstruct\
    \ barrett {\n    uint _m;\n    ull  im;\n    explicit barrett(uint m) : _m(m),\
    \ im((ull)(-1) / m + 1) {}\n    uint umod() const { return _m; }\n    uint mul(uint\
    \ a, uint b) const {\n        ull z = a;\n        z *= b;\n        ull x = ull((__uint128_t(z)\
    \ * im) >> 64);\n        uint v = (uint)(z - x * _m);\n        if (_m <= v) v\
    \ += _m;\n        return v;\n    }\n};\n\ntemplate <int m>\nstruct static_modint\
    \ {\n    using mint = static_modint;\n  public:\n    static constexpr int mod()\
    \ { return m; }\n    static mint raw(int v) {\n        mint x;\n        x._v =\
    \ v;\n        return x;\n    }\n    constexpr static_modint() : _v(0) {}\n   \
    \ template<signed_integral T>\n    constexpr static_modint(T v){\n        ll x\
    \ = (ll)(v % (ll)(umod()));\n        if (x < 0) x += umod();\n        _v = (uint)(x);\n\
    \    }\n    template<unsigned_integral T>\n    constexpr static_modint(T v){\n\
    \        _v = (uint)(v % umod());\n    }\n    constexpr unsigned int val() const\
    \ { return _v; }\n    mint& operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n    constexpr mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    constexpr mint& operator-=(const mint& rhs)\
    \ {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return\
    \ *this;\n    }\n    constexpr mint& operator*=(const mint& rhs) {\n        ull\
    \ z = _v;\n        z *= rhs._v;\n        _v = (uint)(z % umod());\n        return\
    \ *this;\n    }\n    constexpr mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n    constexpr mint operator+() const { return *this;\
    \ }\n    constexpr mint operator-() const { return mint() - *this; }\n    constexpr\
    \ mint pow(ll n) const {\n        assert(0 <= n);\n        mint x = *this, r =\
    \ 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    constexpr mint\
    \ inv() const {\n        if (prime) {\n            assert(_v);\n            return\
    \ pow(umod() - 2);\n        } else {\n            auto eg = inv_gcd(_v, m);\n\
    \            assert(eg.first == 1);\n            return eg.second;\n        }\n\
    \    }\n    friend constexpr mint operator+(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) += rhs;\n    }\n    friend constexpr mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend constexpr mint operator*(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) *= rhs;\n    }\n    friend constexpr mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend constexpr bool operator==(const mint& lhs, const mint& rhs) {\n     \
    \   return lhs._v == rhs._v;\n    }\n    friend constexpr bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr\
    \ unsigned int umod() { return m; }\n    static constexpr bool prime = is_prime_flag<m>;\n\
    };\n\n\ntemplate <int id> struct dynamic_modint {\n    using mint = dynamic_modint;\n\
    \  public:\n    static int mod() { return (int)(bt.umod()); }\n    static void\
    \ set_mod(int m) {\n        assert(1 <= m);\n        bt = barrett(m);\n    }\n\
    \    static mint raw(int v) {\n        mint x;\n        x._v = v;\n        return\
    \ x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template<signed_integral T>\n\
    \    dynamic_modint(T v){\n        ll x = (ll)(v % (ll)(mod()));\n        if (x\
    \ < 0) x += mod();\n        _v = (uint)(x);\n    }\n    template<unsigned_integral\
    \ T>\n    dynamic_modint(T v){\n        _v = (uint)(v % mod());\n    }\n    uint\
    \ val() const { return _v; }\n    mint& operator++() {\n        _v++;\n      \
    \  if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v += mod() - rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint& rhs) {\n        _v = bt.mul(_v,\
    \ rhs._v);\n        return *this;\n    }\n    mint& operator/=(const mint& rhs)\
    \ { return *this = *this * rhs.inv(); }\n    mint operator+() const { return *this;\
    \ }\n    mint operator-() const { return mint() - *this; }\n    mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n \
    \       while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n   \
    \         n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ {\n        auto eg = noya2::inv_gcd(_v, mod());\n        assert(eg.first ==\
    \ 1);\n        return eg.second;\n    }\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend\
    \ mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend bool operator==(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ == rhs._v;\n    }\n    friend bool operator!=(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v != rhs._v;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint& p) {\n        return os << p.val();\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &a) {\n        long long t; is >> t;\n  \
    \      a = mint(t);\n        return (is);\n    }\n\n  private:\n    unsigned int\
    \ _v;\n    static barrett bt;\n    static unsigned int umod() { return bt.umod();\
    \ }\n};\ntemplate <int id> noya2::barrett dynamic_modint<id>::bt(998244353);\n\
    \nusing modint998244353 = static_modint<998244353>;\nusing modint1000000007 =\
    \ static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\ntemplate<typename\
    \ T>\nconcept Modint = requires (T &a){\n    T::mod();\n    a.inv();\n    a.val();\n\
    \    a.pow(declval<int>());\n};\n\n} // namespace noya2"
  dependsOn:
  - math/prime.hpp
  isVerificationFile: false
  path: utility/modint.hpp
  requiredBy:
  - fps/fps_modint.hpp
  - fps/relaxed_convolution.hpp
  - fps/ntt.hpp
  - fps/fps_ntt.hpp
  - fps/multipoint_evaluation.hpp
  - fps/sample_point_shift.hpp
  timestamp: '2024-04-22 12:03:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/convolution.test.cpp
  - test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
  - test/fps/convolution_relaxed_convolution.test.cpp
  - test/fps/Inv_of_Formal_Power_Series.test.cpp
  - test/fps/Convolution1000000007.test.cpp
  - test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/math/Lcm_Convolution.test.cpp
  - test/math/Determinant_of_Matrix.test.cpp
  - test/math/Gcd_Convolution.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
documentation_of: utility/modint.hpp
layout: document
redirect_from:
- /library/utility/modint.hpp
- /library/utility/modint.hpp.html
title: utility/modint.hpp
---
