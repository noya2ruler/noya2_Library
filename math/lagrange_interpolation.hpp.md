---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: math/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Lagrange interpolation
    links: []
  bundledCode: "#line 2 \"math/lagrange_interpolation.hpp\"\n\n#line 2 \"math/binomial.hpp\"\
    \n\n#include<vector>\nnamespace noya2 {\n\ntemplate<typename mint>\nstruct binomial\
    \ {\n    binomial(int len = 300000){ extend(len); }\n    static mint fact(int\
    \ n){\n        if (n < 0) return 0;\n        while (n >= (int)_fact.size()) extend();\n\
    \        return _fact[n];\n    }\n    static mint ifact(int n){\n        if (n\
    \ < 0) return 0;\n        while (n >= (int)_fact.size()) extend();\n        return\
    \ _ifact[n];\n    }\n    static mint inv(int n){\n        return ifact(n) * fact(n-1);\n\
    \    }\n    static mint C(int n, int r){\n        if (!(0 <= r && r <= n)) return\
    \ 0;\n        return fact(n) * ifact(r) * ifact(n-r);\n    }\n    static mint\
    \ P(int n, int r){\n        if (!(0 <= r && r <= n)) return 0;\n        return\
    \ fact(n) * ifact(n-r);\n    }\n    inline mint operator()(int n, int r) { return\
    \ C(n, r); }\n    template<class... Cnts> static mint M(const Cnts&... cnts){\n\
    \        return multinomial(0,1,cnts...);\n    }\n  private:\n    static mint\
    \ multinomial(const int& sum, const mint& div_prod){\n        if (sum < 0) return\
    \ 0;\n        return fact(sum) * div_prod;\n    }\n    template<class... Tail>\
    \ static mint multinomial(const int& sum, const mint& div_prod, const int& n1,\
    \ const Tail&... tail){\n        if (n1 < 0) return 0;\n        return multinomial(sum+n1,div_prod*ifact(n1),tail...);\n\
    \    }\n    static inline std::vector<mint> _fact, _ifact;\n    static void extend(int\
    \ len = -1){\n        if (_fact.empty()){\n            _fact = _ifact = {1,1};\n\
    \        }\n        int siz = _fact.size();\n        if (len == -1) len = siz\
    \ * 2;\n        len = (int)min<long long>(len, mint::mod() - 1);\n        if (len\
    \ < siz) return ;\n        _fact.resize(len+1), _ifact.resize(len+1);\n      \
    \  for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1] * i;\n        _ifact[len]\
    \ = _fact[len].inv();\n        for (int i = len; i > siz; i--) _ifact[i-1] = _ifact[i]\
    \ * i;\n    }\n    static void initialize(int len = 2){\n        _fact.clear();\n\
    \        _ifact.clear();\n        extend(len);\n    }\n};\n\n} // namespace noya2\n\
    #line 4 \"math/lagrange_interpolation.hpp\"\n\nnamespace noya2 {\n\n/**\n * @brief\
    \ Lagrange interpolation\n * @note y is at most n-degree polynomial of x\n * \n\
    \ * @tparam mint (use noya2::binomial<mint>::ifact(int))\n * @param y value of\
    \ y(0), y(1), ... y(n)\n * @param x specific value of x\n * @return mint y(x)\n\
    \ */\ntemplate<typename mint>\nmint lagrange_interpolation(const std::vector<mint>\
    \ &y, mint x){\n    if (x.val() < y.size()){\n        return y[x.val()];\n   \
    \ }\n    int n = y.size() - 1;\n    std::vector<mint> lui(n+1,1), rui(n+1,1);\n\
    \    mint a = x;\n    for (int i = 0; i < n; i++){\n        lui[i+1] = lui[i]\
    \ * a;\n        a -= 1;\n    }\n    for (int i = n-1; i >= 0; i--){\n        rui[i]\
    \ = rui[i+1] * a;\n        a += 1;\n    }\n    mint ans = 0;\n    binomial<mint>\
    \ bnm;\n    for (int i = 0; i <= n; i++){\n        mint tmp = y[i] * lui[i] *\
    \ rui[i] * bnm.ifact(i) * bnm.ifact(n-i);\n        ans += ((n-i) & 1) ? -tmp :\
    \ tmp;\n    }\n    return ans;\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"binomial.hpp\"\n\nnamespace noya2 {\n\n/**\n *\
    \ @brief Lagrange interpolation\n * @note y is at most n-degree polynomial of\
    \ x\n * \n * @tparam mint (use noya2::binomial<mint>::ifact(int))\n * @param y\
    \ value of y(0), y(1), ... y(n)\n * @param x specific value of x\n * @return mint\
    \ y(x)\n */\ntemplate<typename mint>\nmint lagrange_interpolation(const std::vector<mint>\
    \ &y, mint x){\n    if (x.val() < y.size()){\n        return y[x.val()];\n   \
    \ }\n    int n = y.size() - 1;\n    std::vector<mint> lui(n+1,1), rui(n+1,1);\n\
    \    mint a = x;\n    for (int i = 0; i < n; i++){\n        lui[i+1] = lui[i]\
    \ * a;\n        a -= 1;\n    }\n    for (int i = n-1; i >= 0; i--){\n        rui[i]\
    \ = rui[i+1] * a;\n        a += 1;\n    }\n    mint ans = 0;\n    binomial<mint>\
    \ bnm;\n    for (int i = 0; i <= n; i++){\n        mint tmp = y[i] * lui[i] *\
    \ rui[i] * bnm.ifact(i) * bnm.ifact(n-i);\n        ans += ((n-i) & 1) ? -tmp :\
    \ tmp;\n    }\n    return ans;\n}\n\n} // namespace noya2"
  dependsOn:
  - math/binomial.hpp
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2024-07-03 01:34:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/math/lagrange_interpolation.hpp
- /library/math/lagrange_interpolation.hpp.html
title: Lagrange interpolation
---
