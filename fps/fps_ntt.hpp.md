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
  code: "#pragma once\n\n#include\"formal_power_series.hpp\"\n#include\"ntt_new.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<typename T>\nstruct fps_ntt{\n    static NTT<T>\
    \ ntt;\n    static vector<T> multiply(const vector<T> &a, const vector<T> &b){\n\
    \        return ntt.multiply(a,b);\n    }\n};\ntemplate<typename T> NTT<T> fps_ntt<T>::ntt;\n\
    template<typename T> using fps = FormalPowerSeries<T,fps_ntt<T>>;\n\n} // namespace\
    \ noya2\n\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/fps_ntt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps_ntt.hpp
layout: document
redirect_from:
- /library/fps/fps_ntt.hpp
- /library/fps/fps_ntt.hpp.html
title: fps/fps_ntt.hpp
---
