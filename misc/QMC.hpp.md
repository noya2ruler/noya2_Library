---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://i05nagai.github.io/memorandum/math/sobol_sequence.html
    - https://yoshiiz.blog.fc2.com/blog-entry-199.html
  bundledCode: "#line 2 \"misc/QMC.hpp\"\n\n/*\n\n\u5B9F\u88C5\u306E\u53C2\u8003\u306B\
    \u3057\u305F\uFF1A\nhttps://i05nagai.github.io/memorandum/math/sobol_sequence.html\n\
    \nsobol<32> sb({0,1});\nll id = 0;\nll x = sb.get(++id);\n\n\u306A\u3069\u306E\
    \u3088\u3046\u306B\u3057\u3066\u4F7F\u3046\u3002\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\u306B\u306F\u65E2\u7D04\u591A\u9805\u5F0F\u3092\u6295\u3052\u308B\
    \u3002\n5\u6B21\u4EE5\u4E0B\u306E\u65E2\u7D04\u591A\u9805\u5F0F\u4E00\u89A7\uFF1A\
    \nhttps://yoshiiz.blog.fc2.com/blog-entry-199.html\n\n*/\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,n) for (int i = 0; i < (int)(n);\
    \ i++)\n#define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n#define all(v)\
    \ v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\nusing ull\
    \ = unsigned long long;\n\nusing namespace std;\n\nnamespace noya2{\n\n/*\u3000\
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\ntemplate <typename\
    \ T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n\
    \    return true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n \
    \   if (a >= b) return false;\n    a = b;\n    return true;\n}\n\ntemplate<class\
    \ T>istream &operator>>(istream &is, vector<T> &v){\n    for (auto &e : v) is\
    \ >> e;\n    return is;\n}\n\nvoid fast_io(){\n    cin.tie(0); ios::sync_with_stdio(0);\
    \ cout << fixed << setprecision(15);\n}\n\nconst int iinf = 1'000'000'007;\nconst\
    \ ll linf = 2e18;\n#line 19 \"misc/QMC.hpp\"\n\nnamespace noya2{\n\nrandom_device\
    \ rd;\nmt19937_64 mt_for_sobol(rd());\n\ntemplate<int bk>\nstruct sobol{\n   \
    \ vector<ll> ms, vs;\n    sobol (const vector<ll> &f){\n        int s = f.size()\
    \ - 1;\n        ms.resize(bk);\n        for (int i = 0; i < s; i++){\n       \
    \     ms[i] = 2 * (mt_for_sobol() % (1LL << i)) + 1;\n        }\n        for (int\
    \ j = s; j < bk; j++){\n            ms[j] = ms[j-s];\n            for (int i =\
    \ 1; i <= s; i++){\n                ms[j] ^= (f[i] << i) * ms[j-i];\n        \
    \    }\n        }\n        vs.resize(bk);\n        for (int i = 0; i < bk; i++){\n\
    \            vs[i] = ms[i] << (bk-1-i);\n        }\n    }\n    ll get(ll id){\n\
    \        ll res = 0;\n        for (int i = 0; i < bk; i++){\n            res ^=\
    \ (id >> i & 1) * vs[i];\n        }\n        return res;\n    }\n    ld getld(ll\
    \ id, ld lo, ld hi){\n        return lo + (hi - lo) * ld(get(id)) / d;\n    }\n\
    \    static constexpr ld d = 1LL<<bk;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n/*\n\n\u5B9F\u88C5\u306E\u53C2\u8003\u306B\u3057\u305F\uFF1A\
    \nhttps://i05nagai.github.io/memorandum/math/sobol_sequence.html\n\nsobol<32>\
    \ sb({0,1});\nll id = 0;\nll x = sb.get(++id);\n\n\u306A\u3069\u306E\u3088\u3046\
    \u306B\u3057\u3066\u4F7F\u3046\u3002\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u306B\u306F\u65E2\u7D04\u591A\u9805\u5F0F\u3092\u6295\u3052\u308B\u3002\n5\u6B21\
    \u4EE5\u4E0B\u306E\u65E2\u7D04\u591A\u9805\u5F0F\u4E00\u89A7\uFF1A\nhttps://yoshiiz.blog.fc2.com/blog-entry-199.html\n\
    \n*/\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\nrandom_device\
    \ rd;\nmt19937_64 mt_for_sobol(rd());\n\ntemplate<int bk>\nstruct sobol{\n   \
    \ vector<ll> ms, vs;\n    sobol (const vector<ll> &f){\n        int s = f.size()\
    \ - 1;\n        ms.resize(bk);\n        for (int i = 0; i < s; i++){\n       \
    \     ms[i] = 2 * (mt_for_sobol() % (1LL << i)) + 1;\n        }\n        for (int\
    \ j = s; j < bk; j++){\n            ms[j] = ms[j-s];\n            for (int i =\
    \ 1; i <= s; i++){\n                ms[j] ^= (f[i] << i) * ms[j-i];\n        \
    \    }\n        }\n        vs.resize(bk);\n        for (int i = 0; i < bk; i++){\n\
    \            vs[i] = ms[i] << (bk-1-i);\n        }\n    }\n    ll get(ll id){\n\
    \        ll res = 0;\n        for (int i = 0; i < bk; i++){\n            res ^=\
    \ (id >> i & 1) * vs[i];\n        }\n        return res;\n    }\n    ld getld(ll\
    \ id, ld lo, ld hi){\n        return lo + (hi - lo) * ld(get(id)) / d;\n    }\n\
    \    static constexpr ld d = 1LL<<bk;\n};\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: misc/QMC.hpp
  requiredBy: []
  timestamp: '2023-06-12 11:44:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/QMC.hpp
layout: document
redirect_from:
- /library/misc/QMC.hpp
- /library/misc/QMC.hpp.html
title: misc/QMC.hpp
---
