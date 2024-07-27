---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_ntt.hpp
    title: fps/fps_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sample_point_shift.hpp
    title: fps/sample_point_shift.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/fps998244353.hpp
    title: fps998244353/fps998244353.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/multipoint_evaluation.hpp
    title: fps998244353/multipoint_evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/polynomial_taylor_shift.hpp
    title: fps998244353/polynomial_taylor_shift.hpp
  - icon: ':warning:'
    path: fps998244353/product_1_minus_x_pow_a.hpp
    title: fps998244353/product_1_minus_x_pow_a.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/sample_point_shift.hpp
    title: fps998244353/sample_point_shift.hpp
  - icon: ':heavy_check_mark:'
    path: math/euler_circuit_counting.hpp
    title: math/euler_circuit_counting.hpp
  - icon: ':warning:'
    path: math/lagrange_interpolation.hpp
    title: Lagrange interpolation
  _extendedVerifiedWith:
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
    path: test/fps998244353/Division_of_Polynomials_998244353.test.cpp
    title: test/fps998244353/Division_of_Polynomials_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps998244353/convolution_998244353.test.cpp
    title: test/fps998244353/convolution_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps998244353/multipoint_evaluation_998244353.test.cpp
    title: test/fps998244353/multipoint_evaluation_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp
    title: test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps998244353/polynomial_taylor_shift_998244353.test.cpp
    title: test/fps998244353/polynomial_taylor_shift_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
    title: test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/CountingEulerianCircuits.test.cpp
    title: test/math/CountingEulerianCircuits.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/binomial.hpp\"\n\n#include<vector>\nnamespace noya2\
    \ {\n\ntemplate<typename mint>\nstruct binomial {\n    binomial(int len = 300000){\
    \ extend(len); }\n    static mint fact(int n){\n        if (n < 0) return 0;\n\
    \        while (n >= (int)_fact.size()) extend();\n        return _fact[n];\n\
    \    }\n    static mint ifact(int n){\n        if (n < 0) return 0;\n        while\
    \ (n >= (int)_fact.size()) extend();\n        return _ifact[n];\n    }\n    static\
    \ mint inv(int n){\n        return ifact(n) * fact(n-1);\n    }\n    static mint\
    \ C(int n, int r){\n        if (!(0 <= r && r <= n)) return 0;\n        return\
    \ fact(n) * ifact(r) * ifact(n-r);\n    }\n    static mint P(int n, int r){\n\
    \        if (!(0 <= r && r <= n)) return 0;\n        return fact(n) * ifact(n-r);\n\
    \    }\n    inline mint operator()(int n, int r) { return C(n, r); }\n    template<class...\
    \ Cnts>\n    static mint M(const Cnts&... cnts){\n        return multinomial(0,1,cnts...);\n\
    \    }\n    static void initialize(int len = 2){\n        _fact.clear();\n   \
    \     _ifact.clear();\n        extend(len);\n    }\n  private:\n    static mint\
    \ multinomial(const int& sum, const mint& div_prod){\n        if (sum < 0) return\
    \ 0;\n        return fact(sum) * div_prod;\n    }\n    template<class... Tail>\n\
    \    static mint multinomial(const int& sum, const mint& div_prod, const int&\
    \ n1, const Tail&... tail){\n        if (n1 < 0) return 0;\n        return multinomial(sum+n1,div_prod*ifact(n1),tail...);\n\
    \    }\n    static inline std::vector<mint> _fact, _ifact;\n    static void extend(int\
    \ len = -1){\n        if (_fact.empty()){\n            _fact = _ifact = {1,1};\n\
    \        }\n        int siz = _fact.size();\n        if (len == -1) len = siz\
    \ * 2;\n        len = (int)min<long long>(len, mint::mod() - 1);\n        if (len\
    \ < siz) return ;\n        _fact.resize(len+1), _ifact.resize(len+1);\n      \
    \  for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1] * i;\n        _ifact[len]\
    \ = _fact[len].inv();\n        for (int i = len; i > siz; i--) _ifact[i-1] = _ifact[i]\
    \ * i;\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<vector>\nnamespace noya2 {\n\ntemplate<typename\
    \ mint>\nstruct binomial {\n    binomial(int len = 300000){ extend(len); }\n \
    \   static mint fact(int n){\n        if (n < 0) return 0;\n        while (n >=\
    \ (int)_fact.size()) extend();\n        return _fact[n];\n    }\n    static mint\
    \ ifact(int n){\n        if (n < 0) return 0;\n        while (n >= (int)_fact.size())\
    \ extend();\n        return _ifact[n];\n    }\n    static mint inv(int n){\n \
    \       return ifact(n) * fact(n-1);\n    }\n    static mint C(int n, int r){\n\
    \        if (!(0 <= r && r <= n)) return 0;\n        return fact(n) * ifact(r)\
    \ * ifact(n-r);\n    }\n    static mint P(int n, int r){\n        if (!(0 <= r\
    \ && r <= n)) return 0;\n        return fact(n) * ifact(n-r);\n    }\n    inline\
    \ mint operator()(int n, int r) { return C(n, r); }\n    template<class... Cnts>\n\
    \    static mint M(const Cnts&... cnts){\n        return multinomial(0,1,cnts...);\n\
    \    }\n    static void initialize(int len = 2){\n        _fact.clear();\n   \
    \     _ifact.clear();\n        extend(len);\n    }\n  private:\n    static mint\
    \ multinomial(const int& sum, const mint& div_prod){\n        if (sum < 0) return\
    \ 0;\n        return fact(sum) * div_prod;\n    }\n    template<class... Tail>\n\
    \    static mint multinomial(const int& sum, const mint& div_prod, const int&\
    \ n1, const Tail&... tail){\n        if (n1 < 0) return 0;\n        return multinomial(sum+n1,div_prod*ifact(n1),tail...);\n\
    \    }\n    static inline std::vector<mint> _fact, _ifact;\n    static void extend(int\
    \ len = -1){\n        if (_fact.empty()){\n            _fact = _ifact = {1,1};\n\
    \        }\n        int siz = _fact.size();\n        if (len == -1) len = siz\
    \ * 2;\n        len = (int)min<long long>(len, mint::mod() - 1);\n        if (len\
    \ < siz) return ;\n        _fact.resize(len+1), _ifact.resize(len+1);\n      \
    \  for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1] * i;\n        _ifact[len]\
    \ = _fact[len].inv();\n        for (int i = len; i > siz; i--) _ifact[i-1] = _ifact[i]\
    \ * i;\n    }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy:
  - math/lagrange_interpolation.hpp
  - math/euler_circuit_counting.hpp
  - fps/fps_ntt.hpp
  - fps/sample_point_shift.hpp
  - fps998244353/polynomial_taylor_shift.hpp
  - fps998244353/multipoint_evaluation.hpp
  - fps998244353/product_1_minus_x_pow_a.hpp
  - fps998244353/fps998244353.hpp
  - fps998244353/sample_point_shift.hpp
  timestamp: '2024-07-03 11:54:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/math/CountingEulerianCircuits.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
  - test/fps/convolution.test.cpp
  - test/fps/Inv_of_Formal_Power_Series.test.cpp
  - test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
  - test/fps998244353/multipoint_evaluation_998244353.test.cpp
  - test/fps998244353/polynomial_taylor_shift_998244353.test.cpp
  - test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp
  - test/fps998244353/Division_of_Polynomials_998244353.test.cpp
  - test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
  - test/fps998244353/convolution_998244353.test.cpp
documentation_of: math/binomial.hpp
layout: document
redirect_from:
- /library/math/binomial.hpp
- /library/math/binomial.hpp.html
title: math/binomial.hpp
---
