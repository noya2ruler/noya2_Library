---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/aoj_0489.test.cpp
    title: test/tree/aoj_0489.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree.hpp\"\n\nnamespace noya2{\n\n\
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {\n  public:\n    segtree()\
    \ : segtree(0) {}\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n \
    \   segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = 0;\n\
    \        size = 1;\n        while (size < _n) size <<= 1, log++;\n\n        d\
    \ = std::vector<S>(2 * size, e());\n        for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p &&\
    \ p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n\
    \        l += size;\n        r += size;\n\n        while (l < r) {\n         \
    \   if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n    template <bool\
    \ (*f)(S)> int max_right(int l) {\n        return max_right(l, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int max_right(int l, F f) {\n     \
    \   assert(0 <= l && l <= _n);\n        assert(f(e()));\n        if (l == _n)\
    \ return _n;\n        l += size;\n        S sm = e();\n        do {\n        \
    \    while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n      \
    \          while (l < size) {\n                    l = (2 * l);\n            \
    \        if (f(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, d[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    template <bool (*f)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return f(x); });\n    }\n    template <class F> int min_left(int r,\
    \ F f) {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n      \
    \  if (r == 0) return 0;\n        r += size;\n        S sm = e();\n        do\
    \ {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n       \
    \     if (!f(op(d[r], sm))) {\n                while (r < size) {\n          \
    \          r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n    \
    \                    sm = op(d[r], sm);\n                        r--;\n      \
    \              }\n                }\n                return r + 1 - size;\n  \
    \          }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n  private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n\
    } // namespace noya2\n"
  code: "#pragma once\n\nnamespace noya2{\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\
    \ struct segtree {\n  public:\n    segtree() : segtree(0) {}\n    segtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S>& v)\
    \ : _n(int(v.size())) {\n        log = 0;\n        size = 1;\n        while (size\
    \ < _n) size <<= 1, log++;\n\n        d = std::vector<S>(2 * size, e());\n   \
    \     for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ _n);\n        S sml = e(), smr = e();\n        l += size;\n        r += size;\n\
    \n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n   \
    \         if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n          \
    \  r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int l) {\n   \
    \     return max_right(l, [](S x) { return f(x); });\n    }\n    template <class\
    \ F> int max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n       \
    \ assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n     \
    \   S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n     \
    \       if (!f(op(sm, d[l]))) {\n                while (l < size) {\n        \
    \            l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n      \
    \                  sm = op(sm, d[l]);\n                        l++;\n        \
    \            }\n                }\n                return l - size;\n        \
    \    }\n            sm = op(sm, d[l]);\n            l++;\n        } while ((l\
    \ & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) {\n        assert(0 <= r && r <= _n);\n \
    \       assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n \
    \       S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n} // namespace noya2\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2023-06-14 02:12:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/tree/aoj_0489.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.hpp
- /library/data_structure/segment_tree.hpp.html
title: data_structure/segment_tree.hpp
---
