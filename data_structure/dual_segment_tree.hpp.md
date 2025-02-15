---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ebi-fly13.github.io/Library/data_structure/dual_segtree.hpp
  bundledCode: "#line 2 \"data_structure/dual_segment_tree.hpp\"\n\n// https://ebi-fly13.github.io/Library/data_structure/dual_segtree.hpp\n\
    \n#include <bit>\n#include <cassert>\n#include <ranges>\n#include <vector>\n\n\
    namespace noya2 {\n\ntemplate <class F, auto composition, auto id>\nstruct dual_segtree\
    \ {\n  private:\n    void all_apply(int i, F f) {\n        d[i] = composition(f,\
    \ d[i]);\n    }\n\n    void push(int i) {\n        assert(i < sz);\n        all_apply(2\
    \ * i, d[i]);\n        all_apply(2 * i + 1, d[i]);\n        d[i] = id();\n   \
    \ }\n\n  public:\n    dual_segtree(int _n) : dual_segtree(std::vector<F>(_n, id()))\
    \ {}\n\n    dual_segtree(const std::vector<F> &a) : n(a.size()), sz(std::bit_ceil(a.size()))\
    \ {\n        lg2 = std::countr_zero<unsigned int>(sz);\n        d.assign(2 * sz,\
    \ id());\n        for (int i : std::views::iota(sz, sz + n)) {\n            d[i]\
    \ = a[i - sz];\n        }\n    }\n\n    void apply(int l, int r, F f) {\n    \
    \    assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n\n    \
    \    l += sz;\n        r += sz;\n\n        for (int i : std::views::iota(1, lg2\
    \ + 1) | std::views::reverse) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        while (l < r) {\n            if (l & 1) all_apply(l++, f);\n       \
    \     if (r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n    }\n\n    F get(int p) {\n        assert(0 <= p && p < n);\n  \
    \      p += sz;\n        for (int i : std::views::iota(1, lg2 + 1) | std::views::reverse)\
    \ {\n            push(p >> i);\n        }\n        return d[p];\n    }\n\n  private:\n\
    \    int n, sz, lg2;\n    std::vector<F> d;\n};\n\n}  // namespace noya2\n"
  code: "#pragma once\n\n// https://ebi-fly13.github.io/Library/data_structure/dual_segtree.hpp\n\
    \n#include <bit>\n#include <cassert>\n#include <ranges>\n#include <vector>\n\n\
    namespace noya2 {\n\ntemplate <class F, auto composition, auto id>\nstruct dual_segtree\
    \ {\n  private:\n    void all_apply(int i, F f) {\n        d[i] = composition(f,\
    \ d[i]);\n    }\n\n    void push(int i) {\n        assert(i < sz);\n        all_apply(2\
    \ * i, d[i]);\n        all_apply(2 * i + 1, d[i]);\n        d[i] = id();\n   \
    \ }\n\n  public:\n    dual_segtree(int _n) : dual_segtree(std::vector<F>(_n, id()))\
    \ {}\n\n    dual_segtree(const std::vector<F> &a) : n(a.size()), sz(std::bit_ceil(a.size()))\
    \ {\n        lg2 = std::countr_zero<unsigned int>(sz);\n        d.assign(2 * sz,\
    \ id());\n        for (int i : std::views::iota(sz, sz + n)) {\n            d[i]\
    \ = a[i - sz];\n        }\n    }\n\n    void apply(int l, int r, F f) {\n    \
    \    assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n\n    \
    \    l += sz;\n        r += sz;\n\n        for (int i : std::views::iota(1, lg2\
    \ + 1) | std::views::reverse) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        while (l < r) {\n            if (l & 1) all_apply(l++, f);\n       \
    \     if (r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n    }\n\n    F get(int p) {\n        assert(0 <= p && p < n);\n  \
    \      p += sz;\n        for (int i : std::views::iota(1, lg2 + 1) | std::views::reverse)\
    \ {\n            push(p >> i);\n        }\n        return d[p];\n    }\n\n  private:\n\
    \    int n, sz, lg2;\n    std::vector<F> d;\n};\n\n}  // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2025-02-15 20:53:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/dual_segment_tree.hpp
- /library/data_structure/dual_segment_tree.hpp.html
title: data_structure/dual_segment_tree.hpp
---
