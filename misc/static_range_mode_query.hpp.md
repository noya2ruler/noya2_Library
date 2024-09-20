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
  bundledCode: "#line 2 \"misc/static_range_mode_query.hpp\"\n\n#include <vector>\n\
    #include <utility>\n#include <cassert>\n\nnamespace noya2 {\n\nstruct static_range_mode_query\
    \ {\n    const int w = 320;\n    std::vector<int> a;\n    std::vector<std::vector<int>>\
    \ ids;\n    std::vector<std::vector<std::pair<int,int>>> pre;\n    std::vector<int>\
    \ pos;\n    std::vector<int> buf;\n    // a[i] in [0, n), n = a.size()\n    static_range_mode_query\
    \ (const std::vector<int> _a) : a(_a), ids(_a.size()) {\n        int n = a.size(),\
    \ sz = n / w;\n        pos.resize(n);\n        ids.resize(n);\n        for (int\
    \ i = 0; i < n; i++){\n            assert(0 <= a[i] && a[i] < n);\n          \
    \  pos[i] = ids[a[i]].size();\n            ids[a[i]].emplace_back(i);\n      \
    \  }\n        pre.resize((sz+1),std::vector<std::pair<int,int>>(sz+1));\n    \
    \    for (int l = 0; l < sz; l++){\n            std::vector<int> cnt(n,0);\n \
    \           int ma = -1, id = -1;\n            for (int r = l+1; r <= sz; r++){\n\
    \                for (int i = (r-1)*w; i < r*w; i++){\n                    if\
    \ (++cnt[a[i]] > ma){\n                        ma = cnt[a[i]];\n             \
    \           id = a[i];\n                    }\n                }\n           \
    \     pre[l][r] = {id, ma};\n            }\n        }\n        buf.resize(n, 0);\n\
    \    }\n    std::pair<int,int> prod_naive(int l, int r){\n        int ma = -1,\
    \ id = -1;\n        for (int i = l; i < r; i++){\n            if (++buf[a[i]]\
    \ > ma){\n                ma = buf[a[i]];\n                id = a[i];\n      \
    \      }\n        }\n        for (int i = l; i < r; i++){\n            --buf[a[i]];\n\
    \        }\n        return {id, ma};\n    }\n    std::pair<int,int> prod(int l,\
    \ int r){\n        assert(0 <= l && l < r && r <= (int)(a.size()));\n        //\
    \ li = ceil(l / w), ri = floor(r / w)\n        int li = (l + w - 1) / w, ri =\
    \ r / w;\n        if (li >= ri){\n            return prod_naive(l, r);\n     \
    \   }\n        auto [id, ma] = pre[li][ri];\n        for (int i = l; i < li*w;\
    \ i++){\n            int p = pos[i] + ma;\n            if (p >= (int)(ids[a[i]].size()))\
    \ continue;\n            if (ids[a[i]][p] < r){\n                ma++;\n     \
    \           id = a[i];\n                i--;\n            }\n        }\n     \
    \   for (int i = ri*w; i < r; i++){\n            int p = pos[i] - ma;\n      \
    \      if (p < 0) continue;\n            if (ids[a[i]][p] >= l){\n           \
    \     ma++;\n                id = a[i];\n                i--;\n            }\n\
    \        }\n        return {id, ma};\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    \nnamespace noya2 {\n\nstruct static_range_mode_query {\n    const int w = 320;\n\
    \    std::vector<int> a;\n    std::vector<std::vector<int>> ids;\n    std::vector<std::vector<std::pair<int,int>>>\
    \ pre;\n    std::vector<int> pos;\n    std::vector<int> buf;\n    // a[i] in [0,\
    \ n), n = a.size()\n    static_range_mode_query (const std::vector<int> _a) :\
    \ a(_a), ids(_a.size()) {\n        int n = a.size(), sz = n / w;\n        pos.resize(n);\n\
    \        ids.resize(n);\n        for (int i = 0; i < n; i++){\n            assert(0\
    \ <= a[i] && a[i] < n);\n            pos[i] = ids[a[i]].size();\n            ids[a[i]].emplace_back(i);\n\
    \        }\n        pre.resize((sz+1),std::vector<std::pair<int,int>>(sz+1));\n\
    \        for (int l = 0; l < sz; l++){\n            std::vector<int> cnt(n,0);\n\
    \            int ma = -1, id = -1;\n            for (int r = l+1; r <= sz; r++){\n\
    \                for (int i = (r-1)*w; i < r*w; i++){\n                    if\
    \ (++cnt[a[i]] > ma){\n                        ma = cnt[a[i]];\n             \
    \           id = a[i];\n                    }\n                }\n           \
    \     pre[l][r] = {id, ma};\n            }\n        }\n        buf.resize(n, 0);\n\
    \    }\n    std::pair<int,int> prod_naive(int l, int r){\n        int ma = -1,\
    \ id = -1;\n        for (int i = l; i < r; i++){\n            if (++buf[a[i]]\
    \ > ma){\n                ma = buf[a[i]];\n                id = a[i];\n      \
    \      }\n        }\n        for (int i = l; i < r; i++){\n            --buf[a[i]];\n\
    \        }\n        return {id, ma};\n    }\n    std::pair<int,int> prod(int l,\
    \ int r){\n        assert(0 <= l && l < r && r <= (int)(a.size()));\n        //\
    \ li = ceil(l / w), ri = floor(r / w)\n        int li = (l + w - 1) / w, ri =\
    \ r / w;\n        if (li >= ri){\n            return prod_naive(l, r);\n     \
    \   }\n        auto [id, ma] = pre[li][ri];\n        for (int i = l; i < li*w;\
    \ i++){\n            int p = pos[i] + ma;\n            if (p >= (int)(ids[a[i]].size()))\
    \ continue;\n            if (ids[a[i]][p] < r){\n                ma++;\n     \
    \           id = a[i];\n                i--;\n            }\n        }\n     \
    \   for (int i = ri*w; i < r; i++){\n            int p = pos[i] - ma;\n      \
    \      if (p < 0) continue;\n            if (ids[a[i]][p] >= l){\n           \
    \     ma++;\n                id = a[i];\n                i--;\n            }\n\
    \        }\n        return {id, ma};\n    }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/static_range_mode_query.hpp
  requiredBy: []
  timestamp: '2024-09-20 13:52:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/static_range_mode_query.hpp
layout: document
redirect_from:
- /library/misc/static_range_mode_query.hpp
- /library/misc/static_range_mode_query.hpp.html
title: misc/static_range_mode_query.hpp
---
