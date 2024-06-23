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
  bundledCode: "#line 2 \"misc/golden_section_search.hpp\"\n\n#include <utility>\n\
    #include <functional>\n#include <cassert>\n\nnamespace noya2 {\n\n// if GETMIN\
    \ = true (default)\n//   return {argmin, min} of f(x) s.t. x in [lx, rx] inclusive\n\
    template<typename T, bool GETMIN = true>\nstd::pair<long long, T> golden_section_search(const\
    \ std::function<T(long long)> &f, long long lx, long long rx){\n    assert(lx\
    \ <= rx);\n    long long a = lx - 1, x, b;\n    {\n        long long s = 1, t\
    \ = 2;\n        while (t < rx - lx + 2){\n            std::swap(s += t, t);\n\
    \        }\n        x = a + t - s;\n        b = a + t;\n    }\n    T fx = f(x),\
    \ fy;\n    while (a + b != 2 * x){\n        long long y = a + b - x;\n       \
    \ if (rx < y || (fy = f(y), GETMIN ? fx < fy : fx > fy)){\n            b = a;\n\
    \            a = y;\n        }\n        else {\n            a = x;\n         \
    \   x = y;\n            fx = fy;\n        }\n    }\n    return {x, fx};\n}\n\n\
    } // namespace noya2\n"
  code: "#pragma once\n\n#include <utility>\n#include <functional>\n#include <cassert>\n\
    \nnamespace noya2 {\n\n// if GETMIN = true (default)\n//   return {argmin, min}\
    \ of f(x) s.t. x in [lx, rx] inclusive\ntemplate<typename T, bool GETMIN = true>\n\
    std::pair<long long, T> golden_section_search(const std::function<T(long long)>\
    \ &f, long long lx, long long rx){\n    assert(lx <= rx);\n    long long a = lx\
    \ - 1, x, b;\n    {\n        long long s = 1, t = 2;\n        while (t < rx -\
    \ lx + 2){\n            std::swap(s += t, t);\n        }\n        x = a + t -\
    \ s;\n        b = a + t;\n    }\n    T fx = f(x), fy;\n    while (a + b != 2 *\
    \ x){\n        long long y = a + b - x;\n        if (rx < y || (fy = f(y), GETMIN\
    \ ? fx < fy : fx > fy)){\n            b = a;\n            a = y;\n        }\n\
    \        else {\n            a = x;\n            x = y;\n            fx = fy;\n\
    \        }\n    }\n    return {x, fx};\n}\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/golden_section_search.hpp
  requiredBy: []
  timestamp: '2024-06-24 01:00:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/golden_section_search.hpp
layout: document
redirect_from:
- /library/misc/golden_section_search.hpp
- /library/misc/golden_section_search.hpp.html
title: misc/golden_section_search.hpp
---
