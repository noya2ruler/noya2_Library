---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../tree/rerootingdp.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1976\"\n\n#include \"\
    ../../template/template.hpp\"\n#include \"../../tree/rerootingdp.hpp\"\n\nint\
    \ main() {\n    int n; in(n);\n    vector<vector<pii>> g(n);\n    for (int i =\
    \ 0; i < n - 1; i++) {\n        int u, v; in(u, v); u--, v--;\n        g[u].emplace_back(v,\
    \ i);\n        g[v].emplace_back(u, ~i);\n    }\n    auto op = [&](pii a, pii\
    \ b){\n        return pii(max({a.first, b.first, a.second + b.second}), max(a.second,\
    \ b.second));\n    };\n    pii e(0,0);\n    auto pute = [&](pii x, int){\n   \
    \     return pii(max(x.first, x.second + 1), x.second + 1);\n    };\n    auto\
    \ putv = [&](pii e, int){\n        return e;\n    };\n    auto dp = rerootingdp<pii,pii>(op,e,pute,putv,g);\n\
    \    int ans = n;\n    for (int u = 0; u < n; u++) {\n        for (auto [v, eid]\
    \ : g[u]) {\n            int x = dp(u, v).first;\n            int y = dp(v, u).first;\n\
    \            ans = min(ans, max({x, y, (x + 1) / 2 + (y + 1) / 2 + 1}));\n   \
    \     }\n    }\n    out(ans);\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/tree/Rerooting_DP.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/Rerooting_DP.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Rerooting_DP.test.cpp
- /verify/test/tree/Rerooting_DP.test.cpp.html
title: test/tree/Rerooting_DP.test.cpp
---
