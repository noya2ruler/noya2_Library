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
  bundledCode: "#line 2 \"potentialized_dsu/potentialized_dsu.hpp\"\n\n#include<vector>\n\
    #include<cassert>\n\nnamespace noya2{\n\ntemplate<class G, G (*op)(G, G), G(*e)(),\
    \ G(*inv)(G)> struct potentialized_dsu {\n    potentialized_dsu (int _n = 0) :\
    \ n(_n), parent_or_size(_n,-1), potential_(_n,e()) {}\n    int merge(int a, int\
    \ b, G d){ // b is d higher than a, p(b) - p(a) = d\n        assert(0 <= a &&\
    \ a < n);\n        assert(0 <= b && b < n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y){\n            if (diff(a,b) == d) return x;\n           \
    \ else return -1;\n        }\n        d = op(op(potential(a),d),inv(potential(b)));\n\
    \        if (-parent_or_size[x] < -parent_or_size[y]){\n            d = inv(d);\n\
    \            std::swap(x, y);\n        }\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        potential_[y] = d;\n        return x;\n\
    \    }\n    bool same(int a, int b) {\n        assert(0 <= a && a < n);\n    \
    \    assert(0 <= b && b < n);\n        return leader(a) == leader(b);\n    }\n\
    \    int leader(int a){\n        assert(0 <= a && a < n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        int l = leader(parent_or_size[a]);\n        potential_[a]\
    \ = op(potential_[a],potential_[parent_or_size[a]]);\n        return parent_or_size[a]\
    \ = l;\n    }\n    int size(int a){\n        assert(0 <= a && a < n);\n      \
    \  return -parent_or_size[leader(a)];\n    }\n    G potential(int a){\n      \
    \  assert(0 <= a && a < n);\n        leader(a);\n        return potential_[a];\n\
    \    }\n    G diff(int a, int b){\n        assert(0 <= a && a < n);\n        assert(0\
    \ <= b && b < n);\n        return op(inv(potential(a)),potential(b));\n    }\n\
    \  private:\n    int n;\n    std::vector<int> parent_or_size;\n    std::vector<G>\
    \ potential_;\n};\n\nlong long plus_op(long long a, long long b){ return a + b;\
    \ }\nlong long plus_e(){ return 0LL; }\nlong long plus_inv(long long a){ return\
    \ -a; }\nusing potentialized_dsu_plus = potentialized_dsu<long long,plus_op,plus_e,plus_inv>;\n\
    \n} // namespace noya2\n"
  code: "#pragma once\n\n#include<vector>\n#include<cassert>\n\nnamespace noya2{\n\
    \ntemplate<class G, G (*op)(G, G), G(*e)(), G(*inv)(G)> struct potentialized_dsu\
    \ {\n    potentialized_dsu (int _n = 0) : n(_n), parent_or_size(_n,-1), potential_(_n,e())\
    \ {}\n    int merge(int a, int b, G d){ // b is d higher than a, p(b) - p(a) =\
    \ d\n        assert(0 <= a && a < n);\n        assert(0 <= b && b < n);\n    \
    \    int x = leader(a), y = leader(b);\n        if (x == y){\n            if (diff(a,b)\
    \ == d) return x;\n            else return -1;\n        }\n        d = op(op(potential(a),d),inv(potential(b)));\n\
    \        if (-parent_or_size[x] < -parent_or_size[y]){\n            d = inv(d);\n\
    \            std::swap(x, y);\n        }\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        potential_[y] = d;\n        return x;\n\
    \    }\n    bool same(int a, int b) {\n        assert(0 <= a && a < n);\n    \
    \    assert(0 <= b && b < n);\n        return leader(a) == leader(b);\n    }\n\
    \    int leader(int a){\n        assert(0 <= a && a < n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        int l = leader(parent_or_size[a]);\n        potential_[a]\
    \ = op(potential_[a],potential_[parent_or_size[a]]);\n        return parent_or_size[a]\
    \ = l;\n    }\n    int size(int a){\n        assert(0 <= a && a < n);\n      \
    \  return -parent_or_size[leader(a)];\n    }\n    G potential(int a){\n      \
    \  assert(0 <= a && a < n);\n        leader(a);\n        return potential_[a];\n\
    \    }\n    G diff(int a, int b){\n        assert(0 <= a && a < n);\n        assert(0\
    \ <= b && b < n);\n        return op(inv(potential(a)),potential(b));\n    }\n\
    \  private:\n    int n;\n    std::vector<int> parent_or_size;\n    std::vector<G>\
    \ potential_;\n};\n\nlong long plus_op(long long a, long long b){ return a + b;\
    \ }\nlong long plus_e(){ return 0LL; }\nlong long plus_inv(long long a){ return\
    \ -a; }\nusing potentialized_dsu_plus = potentialized_dsu<long long,plus_op,plus_e,plus_inv>;\n\
    \n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: potentialized_dsu/potentialized_dsu.hpp
  requiredBy: []
  timestamp: '2022-12-22 16:57:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: potentialized_dsu/potentialized_dsu.hpp
layout: document
redirect_from:
- /library/potentialized_dsu/potentialized_dsu.hpp
- /library/potentialized_dsu/potentialized_dsu.hpp.html
title: potentialized_dsu/potentialized_dsu.hpp
---
