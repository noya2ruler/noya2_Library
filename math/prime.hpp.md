---
data:
  _extendedDependsOn: []
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
  - icon: ':heavy_check_mark:'
    path: fps998244353/fps998244353.hpp
    title: fps998244353/fps998244353.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/multipoint_evaluation.hpp
    title: fps998244353/multipoint_evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/sample_point_shift.hpp
    title: fps998244353/sample_point_shift.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
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
    path: test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
    title: test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
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
  bundledCode: "#line 2 \"math/prime.hpp\"\n\n#include<utility>\nnamespace noya2 {\n\
    \nconstexpr long long safe_mod(long long x, long long m) {\n    x %= m;\n    if\
    \ (x < 0) x += m;\n    return x;\n}\n\nconstexpr long long pow_mod_constexpr(long\
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
    \ primitive_root_flag = primitive_root_constexpr(m);\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<utility>\nnamespace noya2 {\n\nconstexpr long long\
    \ safe_mod(long long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n\
    \    return x;\n}\n\nconstexpr long long pow_mod_constexpr(long long x, long long\
    \ n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n\
    \    unsigned long long r = 1;\n    unsigned long long y = safe_mod(x, m);\n \
    \   while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n\
    \        n >>= 1;\n    }\n    return r;\n}\n\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
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
    } // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy:
  - fps998244353/fps998244353.hpp
  - fps998244353/multipoint_evaluation.hpp
  - fps998244353/sample_point_shift.hpp
  - fps/fps_modint.hpp
  - fps/relaxed_convolution.hpp
  - fps/ntt.hpp
  - fps/fps_ntt.hpp
  - fps/multipoint_evaluation.hpp
  - fps/sample_point_shift.hpp
  - utility/modint.hpp
  timestamp: '2024-04-22 12:03:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps998244353/multipoint_evaluation_998244353.test.cpp
  - test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
  - test/fps998244353/convolution_998244353.test.cpp
  - test/fps998244353/Division_of_Polynomials_998244353.test.cpp
  - test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp
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
documentation_of: math/prime.hpp
layout: document
redirect_from:
- /library/math/prime.hpp
- /library/math/prime.hpp.html
title: math/prime.hpp
---
