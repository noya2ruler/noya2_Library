---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj1068_segtree2d.test.cpp
    title: test/data_structure/aoj1068_segtree2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree_2d.hpp\"\n\n#include<vector>\n\
    \nnamespace noya2{\n\ntemplate<class S, S(*op)(S, S), S(*e)()>\nstruct segtree_2d\
    \ {\n    int h, w;\n    segtree_2d (int h_ = 1, int w_ = 0) : segtree_2d(std::vector<std::vector<S>>(h_,vector<S>(w_,e())))\
    \ {}\n    segtree_2d (const std::vector<std::vector<S>> &vec){\n        assert(!vec.empty());\n\
    \        //h = bit_ceil(vec.size()), w = bit_ceil(vec[0].size());\n        h =\
    \ 1; while (h < (int)(vec.size())) h <<= 1; w = 1; while (w < (int)(vec[0].size()))\
    \ w <<= 1;\n        d.assign(h*w*4,e());\n        for (int i = 0; i < (int)(vec.size());\
    \ i++) for (int j = 0; j < (int)(vec[i].size()); j++) d[id(i+h,j+w)] = vec[i][j];\n\
    \        build();\n    }\n    void build(){\n        for (int i = 0; i < h; i++)\
    \ for (int j = w-1; j > 0; j--) update_y(i+h,j);\n        for (int i = h-1; i\
    \ > 0; i--) for (int j = 1; j < 2*w; j++) update_x(i,j);\n    }\n    void assign(int\
    \ p, int q, S v){\n        d[id(p+h,q+w)] = v;\n    }\n    void set(int p, int\
    \ q, S v){\n        p += h, q += w;\n        d[id(p,q)] = v;\n        for (int\
    \ j = q>>1; j > 0; j >>= 1) update_y(p,j);\n        for ( ; q > 0; q >>= 1) for\
    \ (int i = p>>1; i > 0; i >>= 1) update_x(i,q);\n    }\n    S prod(int lp, int\
    \ rp, int lq, int rq){\n        if (lp >= rp || lq >= rq) return e();\n      \
    \  S res = e();\n        lp += h, rp += h, lq += w, rq += w;\n        for ( ;\
    \ lp < rp; lp >>= 1, rp >>= 1){\n            if (lp & 1) res = op(res,inner_prod(lp++,lq,rq));\n\
    \            if (rp & 1) res = op(res,inner_prod(--rp,lq,rq));\n        }\n  \
    \      return res;\n    }\n    S get(int p, int q){\n        p += h, q += w;\n\
    \        return d[id(p,q)];\n    }\n    int id(int p, int q){ return p * 2 * w\
    \ + q; }\n    void update_x(int p, int q){ d[id(p,q)] = op(d[id(2*p,q)],d[id(2*p+1,q)]);\
    \ }\n    void update_y(int p, int q){ d[id(p,q)] = op(d[id(p,2*q)],d[id(p,2*q+1)]);\
    \ }\n    S inner_prod(int p, int lq, int rq){\n        S res = e();\n        for\
    \ ( ; lq < rq; lq >>= 1, rq >>= 1){\n            if (lq & 1) res = op(res,d[id(p,lq++)]);\n\
    \            if (rq & 1) res = op(res,d[id(p,--rq)]);\n        }\n        return\
    \ res;\n    }\n    std::vector<S> d;\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<vector>\n\nnamespace noya2{\n\ntemplate<class S,\
    \ S(*op)(S, S), S(*e)()>\nstruct segtree_2d {\n    int h, w;\n    segtree_2d (int\
    \ h_ = 1, int w_ = 0) : segtree_2d(std::vector<std::vector<S>>(h_,vector<S>(w_,e())))\
    \ {}\n    segtree_2d (const std::vector<std::vector<S>> &vec){\n        assert(!vec.empty());\n\
    \        //h = bit_ceil(vec.size()), w = bit_ceil(vec[0].size());\n        h =\
    \ 1; while (h < (int)(vec.size())) h <<= 1; w = 1; while (w < (int)(vec[0].size()))\
    \ w <<= 1;\n        d.assign(h*w*4,e());\n        for (int i = 0; i < (int)(vec.size());\
    \ i++) for (int j = 0; j < (int)(vec[i].size()); j++) d[id(i+h,j+w)] = vec[i][j];\n\
    \        build();\n    }\n    void build(){\n        for (int i = 0; i < h; i++)\
    \ for (int j = w-1; j > 0; j--) update_y(i+h,j);\n        for (int i = h-1; i\
    \ > 0; i--) for (int j = 1; j < 2*w; j++) update_x(i,j);\n    }\n    void assign(int\
    \ p, int q, S v){\n        d[id(p+h,q+w)] = v;\n    }\n    void set(int p, int\
    \ q, S v){\n        p += h, q += w;\n        d[id(p,q)] = v;\n        for (int\
    \ j = q>>1; j > 0; j >>= 1) update_y(p,j);\n        for ( ; q > 0; q >>= 1) for\
    \ (int i = p>>1; i > 0; i >>= 1) update_x(i,q);\n    }\n    S prod(int lp, int\
    \ rp, int lq, int rq){\n        if (lp >= rp || lq >= rq) return e();\n      \
    \  S res = e();\n        lp += h, rp += h, lq += w, rq += w;\n        for ( ;\
    \ lp < rp; lp >>= 1, rp >>= 1){\n            if (lp & 1) res = op(res,inner_prod(lp++,lq,rq));\n\
    \            if (rp & 1) res = op(res,inner_prod(--rp,lq,rq));\n        }\n  \
    \      return res;\n    }\n    S get(int p, int q){\n        p += h, q += w;\n\
    \        return d[id(p,q)];\n    }\n    int id(int p, int q){ return p * 2 * w\
    \ + q; }\n    void update_x(int p, int q){ d[id(p,q)] = op(d[id(2*p,q)],d[id(2*p+1,q)]);\
    \ }\n    void update_y(int p, int q){ d[id(p,q)] = op(d[id(p,2*q)],d[id(p,2*q+1)]);\
    \ }\n    S inner_prod(int p, int lq, int rq){\n        S res = e();\n        for\
    \ ( ; lq < rq; lq >>= 1, rq >>= 1){\n            if (lq & 1) res = op(res,d[id(p,lq++)]);\n\
    \            if (rq & 1) res = op(res,d[id(p,--rq)]);\n        }\n        return\
    \ res;\n    }\n    std::vector<S> d;\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree_2d.hpp
  requiredBy: []
  timestamp: '2023-09-01 19:27:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/aoj1068_segtree2d.test.cpp
documentation_of: data_structure/segment_tree_2d.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree_2d.hpp
- /library/data_structure/segment_tree_2d.hpp.html
title: data_structure/segment_tree_2d.hpp
---
