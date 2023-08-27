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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ntt_new.hpp: line\
    \ -1: no such header\n"
  code: "#pragma once\n\n#include\"ntt_new.hpp\"\n\nnamespace noya2{\n\ntemplate<Modint\
    \ T>\nstruct RelaxedConvolution {\n    RelaxedConvolution (int n) : f(n), g(n),\
    \ h(2*n-1), q(0) {}\n    uint join(T fq, T gq){\n        f[q] = fq, g[q] = gq;\n\
    \        int lsb = countr_zero(q+2);\n        q_special = (q+2 == (1u<<lsb));\n\
    \        update(lsb);\n        return q;\n    }\n    const T operator[](int idx)\
    \ const { return h[idx]; }\n  private:\n    void update(int lsb){\n        task(lsb);\n\
    \        rep(t,lsb+1){\n            uint w = 1u<<t;\n            T iv = T(2*w).inv();\n\
    \            if (t <= 5){\n                rep(i,w) rep(j,w) h[q+i+j] += f[q+1-w+i]\
    \ * g[w-1+j];\n            }\n            else {\n                vector<T> fg(2*w);\n\
    \                rep(i,2*w) fg[i] = f_ffted[t][2*(q+1-w)+i] * g_ffted[t][2*(w-1)+i];\n\
    \                ntt.ifft4(fg,t+1);\n                rep(i,2*w-1) h[q+i] += fg[i]\
    \ * iv;\n            }\n            if (q_special && t == lsb-1) break;\n    \
    \        if (t <= 5){\n                rep(i,w) rep(j,w) h[q+i+j] += f[w-1+i]\
    \ * g[q+1-w+j];\n            }\n            else {\n                vector<T>\
    \ fg(2*w);\n                rep(i,2*w) fg[i] = f_ffted[t][2*(w-1)+i] * g_ffted[t][2*(q+1-w)+i];\n\
    \                ntt.ifft4(fg,t+1);\n                rep(i,2*w-1) h[q+i] += fg[i]\
    \ * iv;\n            }\n        }\n        q++;\n    }\n    void task(int lsb){\n\
    \        if (q_special){\n            int siz = (lsb <= 5 ? 0 : (int)(f.size()))\
    \ * 2;\n            f_ffted.emplace_back(vector<T>(siz));\n            g_ffted.emplace_back(vector<T>(siz));\n\
    \        }\n        rep(t,lsb+1){\n            if (q_special && t == lsb) break;\n\
    \            if (t <= 5) continue;\n            uint w = 1u<<t;\n            rep(i,w){\n\
    \                f_ffted[t][2*(q+1-w)+i] = f[q+1-w+i];\n                g_ffted[t][2*(q+1-w)+i]\
    \ = g[q+1-w+i];\n            }\n            ntt.fft4(f_ffted[t],t+1,2*(q+1-w));\n\
    \            ntt.fft4(g_ffted[t],t+1,2*(q+1-w));\n            if (q_special &&\
    \ t == lsb-1) break;\n        }\n    }\n    vector<T> f, g, h;\n    vector<vector<T>>\
    \ f_ffted, g_ffted;\n    uint q;\n    bool q_special;\n    NTT<T> ntt;\n};\n\n\
    } // namesapce noya2"
  dependsOn: []
  isVerificationFile: false
  path: fps/relaxed_convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/relaxed_convolution.hpp
layout: document
redirect_from:
- /library/fps/relaxed_convolution.hpp
- /library/fps/relaxed_convolution.hpp.html
title: fps/relaxed_convolution.hpp
---
