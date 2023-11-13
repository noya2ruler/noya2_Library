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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/concepts.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../misc/monoids.hpp\"\
    \n#include\"../misc/concepts.hpp\"\n\nnamespace noya2 {\n\ntemplate<Group G>\n\
    struct potentialized_dsu {\n    using T = typename G::value_type;\n    potentialized_dsu\
    \ (int n_ = 0) : n(n_), parent_or_size(n_,-1) {\n        auto ee = G::e();\n \
    \       pot.resize(n,ee);\n    }\n    int merge(int u, int v, T d){\n        int\
    \ x = leader(u), y = leader(v);\n        if (x == y){\n            if (diff(u,v)\
    \ == d) return x;\n            else return -1;\n        }\n        d = G::op(G::op(potential(u),d),G::inv(potential(v)));\n\
    \        if (-parent_or_size[x] < -parent_or_size[y]){\n            d = G::inv(d);\n\
    \            swap(x,y);\n        }\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        pot[y] = d;\n        return x;\n    }\n\
    \    int leader(int v){\n        assert(0 <= v && v < n);\n        if (parent_or_size[v]\
    \ < 0) return v;\n        int l = leader(parent_or_size[v]);\n        pot[v] =\
    \ G::op(pot[v],pot[parent_or_size[v]]);\n        return parent_or_size[v] = l;\n\
    \    }\n    bool same(int u, int v){\n        return leader(u) == leader(v);\n\
    \    }\n    int size(int v){\n        return -parent_or_size[leader(v)];\n   \
    \ }\n    T potential(int v){\n        leader(v);\n        return pot[v];\n   \
    \ }\n    T diff(int u, int v){\n        return G::op(G::inv(potential(u)),potential(v));\n\
    \    }\n    int n;\n    vector<int> parent_or_size;\n    vector<T> pot;\n};\n\n\
    } // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/potentialized_dsu.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/potentialized_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/potentialized_dsu.hpp
- /library/data_structure/potentialized_dsu.hpp.html
title: data_structure/potentialized_dsu.hpp
---
