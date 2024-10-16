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
  bundledCode: "#line 2 \"misc/clamper.hpp\"\n\n#include <algorithm>\n#include <limits>\n\
    \nnamespace noya2 {\n\ntemplate<typename T>\nstruct clamper {\n    static constexpr\
    \ T lim_l = std::numeric_limits<T>::min() / 3;\n    static constexpr T lim_r =\
    \ std::numeric_limits<T>::max() / 3;\n    // l <= r must be hold (not checked)\n\
    \    T a, l, r;\n    // identity\n    constexpr clamper () : a(0), l(lim_l), r(lim_r)\
    \ {}\n    // add only\n    constexpr clamper (T _a) : a(_a), l(lim_l), r(lim_r)\
    \ {}\n    // clamp only\n    constexpr clamper (T _l, T _r) : a(0), l(_l), r(_r)\
    \ {}\n    // add and clamp\n    constexpr clamper (T _a, T _l, T _r) : a(_a),\
    \ l(_l), r(_r) {}\n    static constexpr clamper add_chmax(T _a, T _l){\n     \
    \   return clamper(_a, _l, lim_r);\n    }\n    static constexpr clamper add_chmin(T\
    \ _a, T _r){\n        return clamper(_a, lim_l, _r);\n    }\n    static constexpr\
    \ clamper chmax(T _l){\n        return clamper(0, _l, lim_r);\n    }\n    static\
    \ constexpr clamper chmin(T _r){\n        return clamper(0, lim_l, _r);\n    }\n\
    \    constexpr T eval(T x) const {\n        return std::clamp(x + a, l, r);\n\
    \    }\n    // (f o g)(x) = f(g(x))\n    friend constexpr clamper composition(const\
    \ clamper &f, const clamper &g){\n        return clamper(f.a + g.a, f.eval(g.l),\
    \ f.eval(g.r));\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace noya2\
    \ {\n\ntemplate<typename T>\nstruct clamper {\n    static constexpr T lim_l =\
    \ std::numeric_limits<T>::min() / 3;\n    static constexpr T lim_r = std::numeric_limits<T>::max()\
    \ / 3;\n    // l <= r must be hold (not checked)\n    T a, l, r;\n    // identity\n\
    \    constexpr clamper () : a(0), l(lim_l), r(lim_r) {}\n    // add only\n   \
    \ constexpr clamper (T _a) : a(_a), l(lim_l), r(lim_r) {}\n    // clamp only\n\
    \    constexpr clamper (T _l, T _r) : a(0), l(_l), r(_r) {}\n    // add and clamp\n\
    \    constexpr clamper (T _a, T _l, T _r) : a(_a), l(_l), r(_r) {}\n    static\
    \ constexpr clamper add_chmax(T _a, T _l){\n        return clamper(_a, _l, lim_r);\n\
    \    }\n    static constexpr clamper add_chmin(T _a, T _r){\n        return clamper(_a,\
    \ lim_l, _r);\n    }\n    static constexpr clamper chmax(T _l){\n        return\
    \ clamper(0, _l, lim_r);\n    }\n    static constexpr clamper chmin(T _r){\n \
    \       return clamper(0, lim_l, _r);\n    }\n    constexpr T eval(T x) const\
    \ {\n        return std::clamp(x + a, l, r);\n    }\n    // (f o g)(x) = f(g(x))\n\
    \    friend constexpr clamper composition(const clamper &f, const clamper &g){\n\
    \        return clamper(f.a + g.a, f.eval(g.l), f.eval(g.r));\n    }\n};\n\n}\
    \ // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/clamper.hpp
  requiredBy: []
  timestamp: '2024-10-16 23:26:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/clamper.hpp
layout: document
redirect_from:
- /library/misc/clamper.hpp
- /library/misc/clamper.hpp.html
title: misc/clamper.hpp
---
