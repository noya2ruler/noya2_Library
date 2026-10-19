---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Floor_of_Linear.test.cpp
    title: test/math/Sum_of_Floor_of_Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/floor_sum.hpp\"\n\nnamespace noya2{\n\n// sum[ i in\
    \ [0,n) ] floor( (a * i + b) / m )\ntemplate<typename T>\nT floor_sum(T n, T m,\
    \ T a, T b){\n    assert(m >= 1);\n    if (n <= 0) return 0;\n    T ans = 0;\n\
    \    if (a < 0){\n        T da = a / m;\n        T ra = a - m * da;\n        if\
    \ (ra < 0) da--, ra += m;\n        ans += (n >> 1) * ((n-1)|1) * da;\n       \
    \ a = ra;\n    }\n    if (b < 0){\n        T db = b / m;\n        T rb = b - m\
    \ * db;\n        if (rb < 0) db--, rb += m;\n        ans += n * db;\n        b\
    \ = rb;\n    }\n    while (true){\n        T da = a / m;\n        ans += (n >>\
    \ 1) * ((n-1)|1) * da;\n        a -= da * m;\n        T db = b / m;\n        ans\
    \ += n * db;\n        b -= db * m;\n        T y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        T dy_max = y_max / m;\n        n = dy_max;\n        b =\
    \ y_max - dy_max * m;\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n\
    } // namespace noya2\n"
  code: "#pragma once\n\nnamespace noya2{\n\n// sum[ i in [0,n) ] floor( (a * i +\
    \ b) / m )\ntemplate<typename T>\nT floor_sum(T n, T m, T a, T b){\n    assert(m\
    \ >= 1);\n    if (n <= 0) return 0;\n    T ans = 0;\n    if (a < 0){\n       \
    \ T da = a / m;\n        T ra = a - m * da;\n        if (ra < 0) da--, ra += m;\n\
    \        ans += (n >> 1) * ((n-1)|1) * da;\n        a = ra;\n    }\n    if (b\
    \ < 0){\n        T db = b / m;\n        T rb = b - m * db;\n        if (rb < 0)\
    \ db--, rb += m;\n        ans += n * db;\n        b = rb;\n    }\n    while (true){\n\
    \        T da = a / m;\n        ans += (n >> 1) * ((n-1)|1) * da;\n        a -=\
    \ da * m;\n        T db = b / m;\n        ans += n * db;\n        b -= db * m;\n\
    \        T y_max = a * n + b;\n        if (y_max < m) break;\n        T dy_max\
    \ = y_max / m;\n        n = dy_max;\n        b = y_max - dy_max * m;\n       \
    \ std::swap(m, a);\n    }\n    return ans;\n}\n\n} // namespace noya2\n"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum.hpp
  requiredBy: []
  timestamp: '2023-10-17 23:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Sum_of_Floor_of_Linear.test.cpp
documentation_of: math/floor_sum.hpp
layout: document
redirect_from:
- /library/math/floor_sum.hpp
- /library/math/floor_sum.hpp.html
title: math/floor_sum.hpp
---
