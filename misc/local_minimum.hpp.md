---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/local_minimum.hpp\"\n\n#include<cassert>\n\n#line 2\
    \ \"template/utils.hpp\"\n\n#include <cmath>\n#include <vector>\n#include <algorithm>\n\
    \nnamespace noya2{\n\nunsigned long long inner_binary_gcd(unsigned long long a,\
    \ unsigned long long b){\n    if (a == 0 || b == 0) return a + b;\n    int n =\
    \ __builtin_ctzll(a); a >>= n;\n    int m = __builtin_ctzll(b); b >>= m;\n   \
    \ while (a != b) {\n        int mm = __builtin_ctzll(a - b);\n        bool f =\
    \ a > b;\n        unsigned long long c = f ? a : b;\n        b = f ? b : a;\n\
    \        a = (c - b) >> mm;\n    }\n    return a << std::min(n, m);\n}\n\ntemplate<typename\
    \ T> T gcd_fast(T a, T b){ return static_cast<T>(inner_binary_gcd(std::abs(a),std::abs(b)));\
    \ }\n\nlong long sqrt_fast(long long n) {\n    if (n <= 0) return 0;\n    long\
    \ long x = sqrt(n);\n    while ((x + 1) * (x + 1) <= n) x++;\n    while (x * x\
    \ > n) x--;\n    return x;\n}\n\ntemplate<typename T> T floor_div(const T n, const\
    \ T d) {\n    assert(d != 0);\n    return n / d - static_cast<T>((n ^ d) < 0 &&\
    \ n % d != 0);\n}\n\ntemplate<typename T> T ceil_div(const T n, const T d) {\n\
    \    assert(d != 0);\n    return n / d + static_cast<T>((n ^ d) >= 0 && n % d\
    \ != 0);\n}\n\ntemplate<typename T> void uniq(std::vector<T> &v){\n    std::sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n}\n\ntemplate <typename T, typename\
    \ U> inline bool chmin(T &x, U y) { return (y < x) ? (x = y, true) : false; }\n\
    \ntemplate <typename T, typename U> inline bool chmax(T &x, U y) { return (x <\
    \ y) ? (x = y, true) : false; }\n\ntemplate<typename T> inline bool range(T l,\
    \ T x, T r){ return l <= x && x < r; }\n\n} // namespace noya2\n#line 6 \"misc/local_minimum.hpp\"\
    \n\nnamespace noya2 {\n\n// find x in (l, r) s.t. f(l) >= f(x) <= f(r)\n// condition\
    \ : f(l) >= f(m) <= f(r)\ntemplate<typename Idx>\nIdx local_minimum(Idx l, Idx\
    \ m, Idx r, auto f){\n    assert(l < m && m < r); // invariable\n    auto fl =\
    \ f(l), fm = f(m), fr = f(r);\n    assert(fl >= fm && fm <= fr); // invariable\n\
    \    while (r - l > 2){\n        Idx lp = floor_div<Idx>(l + m, 2);\n        Idx\
    \ rp = ceil_div<Idx>(m + r, 2);\n        auto flp = f(lp), frp = f(rp);\n    \
    \    if (flp < fm){\n            r = m;\n            m = lp;\n            fr =\
    \ fm;\n            fm = flp;\n        }\n        else if (fm > frp){\n       \
    \     l = m;\n            m = rp;\n            fl = fm;\n            fm = frp;\n\
    \        }\n        else {\n            l = lp;\n            fl = flp;\n     \
    \       r = rp;\n            fr = frp;\n        }\n    }\n    return m;\n}\n\n\
    } // namespace noya2\n"
  code: "#pragma once\n\n#include<cassert>\n\n#include\"template/utils.hpp\"\n\nnamespace\
    \ noya2 {\n\n// find x in (l, r) s.t. f(l) >= f(x) <= f(r)\n// condition : f(l)\
    \ >= f(m) <= f(r)\ntemplate<typename Idx>\nIdx local_minimum(Idx l, Idx m, Idx\
    \ r, auto f){\n    assert(l < m && m < r); // invariable\n    auto fl = f(l),\
    \ fm = f(m), fr = f(r);\n    assert(fl >= fm && fm <= fr); // invariable\n   \
    \ while (r - l > 2){\n        Idx lp = floor_div<Idx>(l + m, 2);\n        Idx\
    \ rp = ceil_div<Idx>(m + r, 2);\n        auto flp = f(lp), frp = f(rp);\n    \
    \    if (flp < fm){\n            r = m;\n            m = lp;\n            fr =\
    \ fm;\n            fm = flp;\n        }\n        else if (fm > frp){\n       \
    \     l = m;\n            m = rp;\n            fl = fm;\n            fm = frp;\n\
    \        }\n        else {\n            l = lp;\n            fl = flp;\n     \
    \       r = rp;\n            fr = frp;\n        }\n    }\n    return m;\n}\n\n\
    } // namespace noya2"
  dependsOn:
  - template/utils.hpp
  isVerificationFile: false
  path: misc/local_minimum.hpp
  requiredBy: []
  timestamp: '2024-12-17 20:59:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/local_minimum.hpp
layout: document
redirect_from:
- /library/misc/local_minimum.hpp
- /library/misc/local_minimum.hpp.html
title: misc/local_minimum.hpp
---
