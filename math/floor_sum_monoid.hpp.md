---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/floor_sum_monoid.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ noya2 {\n\n// f(i) := floor(a * i + b / m)\n// y^{f(0)} x y^{f(1)-f(0)} x y^{f(2)-f(1)}\
    \ x ... x y^{f(n) - f(n-1)}\n// = y^{f(0)} prod[i in [0, n)] x y^{f(i+1)-f(i)}\n\
    template<class S, auto op, auto e, typename I = long long>\nS floor_sum_monoid(I\
    \ n, I m, I a, I b, S x, S y){\n    assert(n >= 0);\n    assert(m >= 1);\n   \
    \ assert(a >= 0);\n    assert(b >= 0);\n    auto pow_monoid = [](S v, I p) ->\
    \ S {\n        S ret = e();\n        while (p){\n            if (p & 1){\n   \
    \             ret = op(ret, v);\n            }\n            v = op(v, v);\n  \
    \          p >>= 1;\n        }\n        return ret;\n    };\n    S ret = pow_monoid(y,\
    \ b / m);\n    b %= m;\n    x = op(x, pow_monoid(y, a / m));\n    a %= m;\n  \
    \  I k = (a * n + b) / m;\n    if (k == 0){\n        return op(ret, pow_monoid(x,\
    \ n));\n    }\n    ret = op(ret, floor_sum_monoid<S,op,e>(k - 1, a, m, m - b +\
    \ a - 1, y, x));\n    return op(ret, op(y, pow_monoid(x, n - (m * k - b + a -\
    \ 1) / a)));\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <cassert>\n\nnamespace noya2 {\n\n// f(i) := floor(a\
    \ * i + b / m)\n// y^{f(0)} x y^{f(1)-f(0)} x y^{f(2)-f(1)} x ... x y^{f(n) -\
    \ f(n-1)}\n// = y^{f(0)} prod[i in [0, n)] x y^{f(i+1)-f(i)}\ntemplate<class S,\
    \ auto op, auto e, typename I = long long>\nS floor_sum_monoid(I n, I m, I a,\
    \ I b, S x, S y){\n    assert(n >= 0);\n    assert(m >= 1);\n    assert(a >= 0);\n\
    \    assert(b >= 0);\n    auto pow_monoid = [](S v, I p) -> S {\n        S ret\
    \ = e();\n        while (p){\n            if (p & 1){\n                ret = op(ret,\
    \ v);\n            }\n            v = op(v, v);\n            p >>= 1;\n      \
    \  }\n        return ret;\n    };\n    S ret = pow_monoid(y, b / m);\n    b %=\
    \ m;\n    x = op(x, pow_monoid(y, a / m));\n    a %= m;\n    I k = (a * n + b)\
    \ / m;\n    if (k == 0){\n        return op(ret, pow_monoid(x, n));\n    }\n \
    \   ret = op(ret, floor_sum_monoid<S,op,e>(k - 1, a, m, m - b + a - 1, y, x));\n\
    \    return op(ret, op(y, pow_monoid(x, n - (m * k - b + a - 1) / a)));\n}\n\n\
    } // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum_monoid.hpp
  requiredBy: []
  timestamp: '2025-11-14 03:21:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor_sum_monoid.hpp
layout: document
redirect_from:
- /library/math/floor_sum_monoid.hpp
- /library/math/floor_sum_monoid.hpp.html
title: math/floor_sum_monoid.hpp
---
