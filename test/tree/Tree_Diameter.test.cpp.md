---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../tree/Tree_core.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\"\
    ../../template/template.hpp\"\n\n#include\"../../tree/Tree_core.hpp\"\n\nint main(){\n\
    \    int n; cin >> n;\n    vector<ll> w(n-1);\n    naiveTree g(n);\n    rep(i,n-1){\n\
    \        int u, v; cin >> u >> v >> w[i];\n        g.add_edge(u,v,i);\n    }\n\
    \    vector<ll> dist(n,linf);\n    dist[0] = 0;\n    queue<int> que;\n    que.push(0);\n\
    \    ll ma1 = 0, p1 = 0;\n    while (!que.empty()){\n        int p = que.front();\
    \ que.pop();\n        for (auto &[q, id] : g(p)){\n            if (chmin(dist[q],dist[p]+w[id])){\n\
    \                que.push(q);\n                if (chmax(ma1,dist[q])) p1 = q;\n\
    \            }\n        }\n    }\n    dist.assign(n,linf);\n    dist[p1] = 0;\n\
    \    que.push(p1);\n    ll ma2 = 0, p2 = p1;\n    while (!que.empty()){\n    \
    \    int p = que.front(); que.pop();\n        for (auto &[q, id] : g(p)){\n  \
    \          if (chmin(dist[q],dist[p]+w[id])){\n                que.push(q);\n\
    \                if (chmax(ma2,dist[q])) p2 = q;\n            }\n        }\n \
    \   }\n    int p = p2;\n    vector<int> vs = {p};\n    while (p != p1){\n    \
    \    for (auto &q : g[p]){\n            if (dist[p] > dist[q]){\n            \
    \    p = q;\n                break;\n            }\n        }\n        vs.emplace_back(p);\n\
    \    }\n    cout << ma2 << \" \" << vs.size() << endl;\n    rep(i,vs.size()) cout\
    \ << vs[i] << \" \\n\"[i+1 == vs.size()];\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/tree/Tree_Diameter.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/Tree_Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Tree_Diameter.test.cpp
- /verify/test/tree/Tree_Diameter.test.cpp.html
title: test/tree/Tree_Diameter.test.cpp
---
