---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/BitwiseAndConvolution.test.cpp
    title: test/math/BitwiseAndConvolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/BitwiseXorConvolution.test.cpp
    title: test/math/BitwiseXorConvolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/SubsetConvolution.test.cpp
    title: test/math/SubsetConvolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/bitwise_convolution.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n\nnamespace noya2 {\n\n// f mapsto F\n// F(S)\
    \ = sum[T subset S] f(T)\n//      = f(S) o ...\ntemplate<typename T, class Op\
    \ = std::plus<T>>\nvoid bitwise_zeta_transform(std::vector<T> &a){\n    uint32_t\
    \ sz = a.size();\n    assert(std::has_single_bit(sz));\n    Op op{};\n    for\
    \ (uint32_t p2 = 1; p2 < sz; p2 <<= 1){\n        for (uint32_t u = 0; u < sz;\
    \ u += (p2 << 1)){\n            for (uint32_t d = 0; d < p2; d++){\n         \
    \       a[d ^ u ^ p2] = op(a[d ^ u ^ p2], a[d ^ u]);\n            }\n        }\n\
    \    }\n}\n\n\n// inverse transform of zeta : F mapsto f\ntemplate<typename T,\
    \ class Opinv = std::minus<T>>\nvoid bitwise_mobius_transform(std::vector<T> &a){\n\
    \    uint32_t sz = a.size();\n    assert(std::has_single_bit(sz));\n    Opinv\
    \ opinv{};\n    for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){\n        for (uint32_t\
    \ u = 0; u < sz; u += (p2 << 1)){\n            for (uint32_t d = 0; d < p2; d++){\n\
    \                a[d ^ u ^ p2] = opinv(a[d ^ u ^ p2], a[d ^ u]);\n           \
    \ }\n        }\n    }\n}\n\ntemplate<typename T>\nstd::vector<T> bitwise_or_convolution(std::vector<T>\
    \ a, std::vector<T> b){\n    assert(a.size() == b.size());\n    uint32_t sz =\
    \ a.size();\n    bitwise_zeta_transform<T, std::plus<T>>(a);\n    bitwise_zeta_transform<T,\
    \ std::plus<T>>(b);\n    for (uint32_t i = 0; i < sz; i++){\n        a[i] *= b[i];\n\
    \    }\n    bitwise_mobius_transform<T, std::minus<T>>(a);\n    return a;\n}\n\
    \ntemplate<typename T>\nstd::vector<T> bitwise_and_convolution(std::vector<T>\
    \ a, std::vector<T> b){\n    assert(a.size() == b.size());\n    uint32_t sz =\
    \ a.size();\n    std::reverse(a.begin(), a.end());\n    std::reverse(b.begin(),\
    \ b.end());\n    bitwise_zeta_transform<T, std::plus<T>>(a);\n    bitwise_zeta_transform<T,\
    \ std::plus<T>>(b);\n    for (uint32_t i = 0; i < sz; i++){\n        a[i] *= b[i];\n\
    \    }\n    bitwise_mobius_transform<T, std::minus<T>>(a);\n    std::reverse(a.begin(),\
    \ a.end());\n    return a;\n}\n\ntemplate<typename T>\nvoid hadamard_transform(std::vector<T>\
    \ &a){\n    uint32_t sz = a.size();\n    assert(std::has_single_bit(sz));\n  \
    \  for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){\n        for (uint32_t u = 0; u <\
    \ sz; u += (p2 << 1)){\n            for (uint32_t d = 0; d < p2; d++){\n     \
    \           T s = a[d ^ u], t = a[d ^ u ^ p2];\n                a[d ^ u] = s +\
    \ t;\n                a[d ^ u ^ p2] = s - t;\n            }\n        }\n    }\n\
    }\n\ntemplate<typename T>\nstd::vector<T> bitwise_xor_convolution(std::vector<T>\
    \ a, std::vector<T> b){\n    assert(a.size() == b.size());\n    uint32_t sz =\
    \ a.size();\n    hadamard_transform(a);\n    hadamard_transform(b);\n    T iv\
    \ = T(1) / T(sz);\n    for (uint32_t i = 0; i < sz; i++){\n        a[i] *= b[i]\
    \ * iv;\n    }\n    hadamard_transform(a);\n    return a;\n}\n\ntemplate<typename\
    \ T, int LOG>\nstd::vector<T> subset_convolution(const std::vector<T> &a, const\
    \ std::vector<T> &b){\n    assert(a.size() == b.size());\n    using fps = std::array<T,\
    \ LOG + 1>;\n    constexpr int s = LOG;\n    uint32_t sz = a.size();\n    auto\
    \ bitwise_or_zeta_transform = [&]<typename is_zeta>(std::vector<fps> &c, is_zeta\
    \ z){\n        for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){\n            for (uint32_t\
    \ u = 0; u < sz; u += (p2 << 1)){\n                for (uint32_t d = 0; d < p2;\
    \ d++){\n                    for (int i = 0; i <= s; i++){\n                 \
    \       if constexpr (is_zeta::value){\n                            c[d ^ u ^\
    \ p2][i] += c[d ^ u][i];\n                        }\n                        else\
    \ {\n                            c[d ^ u ^ p2][i] -= c[d ^ u][i];\n          \
    \              }\n                    }\n                }\n            }\n  \
    \      }\n    };\n    auto lift = [&](const std::vector<T> &c){\n        std::vector<fps>\
    \ C(sz, fps{});\n        for (uint32_t i = 0; i < sz; i++){\n            C[i][std::popcount(i)]\
    \ = c[i];\n        }\n        return C;\n    };\n    auto A = lift(a), B = lift(b);\n\
    \    bitwise_or_zeta_transform(A, std::true_type{});\n    bitwise_or_zeta_transform(B,\
    \ std::true_type{});\n    for (uint32_t i = 0; i < sz; i++){\n        fps c =\
    \ {};\n        for (int x = 0; x <= s; x++){\n            for (int y = 0; y <=\
    \ s - x; y++){\n                c[x + y] += A[i][x] * B[i][y];\n            }\n\
    \        }\n        std::swap(A[i], c);\n    }\n    bitwise_or_zeta_transform(A,\
    \ std::false_type{});\n    std::vector<T> ab(sz);\n    for (uint32_t i = 0; i\
    \ < sz; i++){\n        ab[i] = A[i][std::popcount(i)];\n    }\n    return ab;\n\
    }\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\
    \nnamespace noya2 {\n\n// f mapsto F\n// F(S) = sum[T subset S] f(T)\n//     \
    \ = f(S) o ...\ntemplate<typename T, class Op = std::plus<T>>\nvoid bitwise_zeta_transform(std::vector<T>\
    \ &a){\n    uint32_t sz = a.size();\n    assert(std::has_single_bit(sz));\n  \
    \  Op op{};\n    for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){\n        for (uint32_t\
    \ u = 0; u < sz; u += (p2 << 1)){\n            for (uint32_t d = 0; d < p2; d++){\n\
    \                a[d ^ u ^ p2] = op(a[d ^ u ^ p2], a[d ^ u]);\n            }\n\
    \        }\n    }\n}\n\n\n// inverse transform of zeta : F mapsto f\ntemplate<typename\
    \ T, class Opinv = std::minus<T>>\nvoid bitwise_mobius_transform(std::vector<T>\
    \ &a){\n    uint32_t sz = a.size();\n    assert(std::has_single_bit(sz));\n  \
    \  Opinv opinv{};\n    for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){\n        for\
    \ (uint32_t u = 0; u < sz; u += (p2 << 1)){\n            for (uint32_t d = 0;\
    \ d < p2; d++){\n                a[d ^ u ^ p2] = opinv(a[d ^ u ^ p2], a[d ^ u]);\n\
    \            }\n        }\n    }\n}\n\ntemplate<typename T>\nstd::vector<T> bitwise_or_convolution(std::vector<T>\
    \ a, std::vector<T> b){\n    assert(a.size() == b.size());\n    uint32_t sz =\
    \ a.size();\n    bitwise_zeta_transform<T, std::plus<T>>(a);\n    bitwise_zeta_transform<T,\
    \ std::plus<T>>(b);\n    for (uint32_t i = 0; i < sz; i++){\n        a[i] *= b[i];\n\
    \    }\n    bitwise_mobius_transform<T, std::minus<T>>(a);\n    return a;\n}\n\
    \ntemplate<typename T>\nstd::vector<T> bitwise_and_convolution(std::vector<T>\
    \ a, std::vector<T> b){\n    assert(a.size() == b.size());\n    uint32_t sz =\
    \ a.size();\n    std::reverse(a.begin(), a.end());\n    std::reverse(b.begin(),\
    \ b.end());\n    bitwise_zeta_transform<T, std::plus<T>>(a);\n    bitwise_zeta_transform<T,\
    \ std::plus<T>>(b);\n    for (uint32_t i = 0; i < sz; i++){\n        a[i] *= b[i];\n\
    \    }\n    bitwise_mobius_transform<T, std::minus<T>>(a);\n    std::reverse(a.begin(),\
    \ a.end());\n    return a;\n}\n\ntemplate<typename T>\nvoid hadamard_transform(std::vector<T>\
    \ &a){\n    uint32_t sz = a.size();\n    assert(std::has_single_bit(sz));\n  \
    \  for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){\n        for (uint32_t u = 0; u <\
    \ sz; u += (p2 << 1)){\n            for (uint32_t d = 0; d < p2; d++){\n     \
    \           T s = a[d ^ u], t = a[d ^ u ^ p2];\n                a[d ^ u] = s +\
    \ t;\n                a[d ^ u ^ p2] = s - t;\n            }\n        }\n    }\n\
    }\n\ntemplate<typename T>\nstd::vector<T> bitwise_xor_convolution(std::vector<T>\
    \ a, std::vector<T> b){\n    assert(a.size() == b.size());\n    uint32_t sz =\
    \ a.size();\n    hadamard_transform(a);\n    hadamard_transform(b);\n    T iv\
    \ = T(1) / T(sz);\n    for (uint32_t i = 0; i < sz; i++){\n        a[i] *= b[i]\
    \ * iv;\n    }\n    hadamard_transform(a);\n    return a;\n}\n\ntemplate<typename\
    \ T, int LOG>\nstd::vector<T> subset_convolution(const std::vector<T> &a, const\
    \ std::vector<T> &b){\n    assert(a.size() == b.size());\n    using fps = std::array<T,\
    \ LOG + 1>;\n    constexpr int s = LOG;\n    uint32_t sz = a.size();\n    auto\
    \ bitwise_or_zeta_transform = [&]<typename is_zeta>(std::vector<fps> &c, is_zeta\
    \ z){\n        for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){\n            for (uint32_t\
    \ u = 0; u < sz; u += (p2 << 1)){\n                for (uint32_t d = 0; d < p2;\
    \ d++){\n                    for (int i = 0; i <= s; i++){\n                 \
    \       if constexpr (is_zeta::value){\n                            c[d ^ u ^\
    \ p2][i] += c[d ^ u][i];\n                        }\n                        else\
    \ {\n                            c[d ^ u ^ p2][i] -= c[d ^ u][i];\n          \
    \              }\n                    }\n                }\n            }\n  \
    \      }\n    };\n    auto lift = [&](const std::vector<T> &c){\n        std::vector<fps>\
    \ C(sz, fps{});\n        for (uint32_t i = 0; i < sz; i++){\n            C[i][std::popcount(i)]\
    \ = c[i];\n        }\n        return C;\n    };\n    auto A = lift(a), B = lift(b);\n\
    \    bitwise_or_zeta_transform(A, std::true_type{});\n    bitwise_or_zeta_transform(B,\
    \ std::true_type{});\n    for (uint32_t i = 0; i < sz; i++){\n        fps c =\
    \ {};\n        for (int x = 0; x <= s; x++){\n            for (int y = 0; y <=\
    \ s - x; y++){\n                c[x + y] += A[i][x] * B[i][y];\n            }\n\
    \        }\n        std::swap(A[i], c);\n    }\n    bitwise_or_zeta_transform(A,\
    \ std::false_type{});\n    std::vector<T> ab(sz);\n    for (uint32_t i = 0; i\
    \ < sz; i++){\n        ab[i] = A[i][std::popcount(i)];\n    }\n    return ab;\n\
    }\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: math/bitwise_convolution.hpp
  requiredBy: []
  timestamp: '2025-04-26 02:07:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/SubsetConvolution.test.cpp
  - test/math/BitwiseAndConvolution.test.cpp
  - test/math/BitwiseXorConvolution.test.cpp
documentation_of: math/bitwise_convolution.hpp
layout: document
redirect_from:
- /library/math/bitwise_convolution.hpp
- /library/math/bitwise_convolution.hpp.html
title: math/bitwise_convolution.hpp
---
