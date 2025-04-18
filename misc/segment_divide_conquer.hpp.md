---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/segment_divide_conquer.hpp\"\n\n#line 2 \"data_structure/csr.hpp\"\
    \n\n#include<vector>\n#include<ranges>\n#include<cassert>\n#include<utility>\n\
    \nnamespace noya2::internal {\n\ntemplate<class E>\nstruct csr {\n    csr () {}\n\
    \    csr (int _n) : n(_n) {}\n    csr (int _n, int m) : n(_n){\n        start.reserve(m);\n\
    \        elist.reserve(m);\n    }\n    // ACL style constructor (do not have to\
    \ call build)\n    csr (int _n, const std::vector<std::pair<int,E>> &idx_elem)\
    \ : n(_n), start(_n + 2), elist(idx_elem.size()) {\n        for (auto &[i, e]\
    \ : idx_elem){\n            start[i + 2]++;\n        }\n        for (int i = 1;\
    \ i < n; i++){\n            start[i + 2] += start[i + 1];\n        }\n       \
    \ for (auto &[i, e] : idx_elem){\n            elist[start[i + 1]++] = e;\n   \
    \     }\n        prepared = true;\n    }\n    int add(int idx, E elem){\n    \
    \    int eid = start.size();\n        start.emplace_back(idx);\n        elist.emplace_back(elem);\n\
    \        return eid;\n    }\n    void build(){\n        if (prepared) return ;\n\
    \        int m = start.size();\n        std::vector<E> nelist(m);\n        std::vector<int>\
    \ nstart(n + 2, 0);\n        for (int i = 0; i < m; i++){\n            nstart[start[i]\
    \ + 2]++;\n        }\n        for (int i = 1; i < n; i++){\n            nstart[i\
    \ + 2] += nstart[i + 1];\n        }\n        for (int i = 0; i < m; i++){\n  \
    \          nelist[nstart[start[i] + 1]++] = elist[i];\n        }\n        swap(elist,nelist);\n\
    \        swap(start,nstart);\n        prepared = true;\n    }\n    const auto\
    \ operator[](int idx) const {\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    auto operator[](int idx){\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    const auto operator()(int idx, int l, int r) const {\n        return\
    \ std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    auto operator()(int idx, int l, int r){\n        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    size_t size() const {\n        return n;\n    }\n    int n;\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    bool prepared = false;\n};\n\n} // namespace\
    \ noya2::internal\n#line 4 \"misc/segment_divide_conquer.hpp\"\n\nnamespace noya2\
    \ {\n\nstruct segment_divide_conquer {\n    int tmax, sz;\n    internal::csr<int>\
    \ events;\n    segment_divide_conquer (int _tmax) : tmax(_tmax){\n        sz =\
    \ std::bit_ceil<uint32_t>(tmax);\n        events = internal::csr<int>(sz*2);\n\
    \    }\n    void add_event(int tl, int tr, int id){\n        tl += sz, tr += sz;\n\
    \        while (tl < tr){\n            if (tl & 1){\n                events.add(tl++,\
    \ id);\n            }\n            if (tr & 1){\n                events.add(--tr,\
    \ id);\n            }\n            tl >>= 1;\n            tr >>= 1;\n        }\n\
    \    }\n    // void apply(int eventid);\n    // void rollback(int eventid);\n\
    \    // void query(int t);\n    void run(auto apply, auto rollback, auto query){\n\
    \        events.build();\n        auto dfs = [&](auto sfs, int p) -> void {\n\
    \            for (int id : events[p]){\n                apply(id);\n         \
    \   }\n            if (p >= sz){\n                p -= sz;\n                if\
    \ (p < tmax){\n                    query(p);\n                }\n            \
    \    p += sz;\n            }\n            else {\n                sfs(sfs, p *\
    \ 2);\n                sfs(sfs, p * 2 + 1);\n            }\n            for (int\
    \ id : events[p] | std::views::reverse){\n                rollback(id);\n    \
    \        }\n        };\n        dfs(dfs,1);\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"data_structure/csr.hpp\"\n\nnamespace noya2 {\n\
    \nstruct segment_divide_conquer {\n    int tmax, sz;\n    internal::csr<int> events;\n\
    \    segment_divide_conquer (int _tmax) : tmax(_tmax){\n        sz = std::bit_ceil<uint32_t>(tmax);\n\
    \        events = internal::csr<int>(sz*2);\n    }\n    void add_event(int tl,\
    \ int tr, int id){\n        tl += sz, tr += sz;\n        while (tl < tr){\n  \
    \          if (tl & 1){\n                events.add(tl++, id);\n            }\n\
    \            if (tr & 1){\n                events.add(--tr, id);\n           \
    \ }\n            tl >>= 1;\n            tr >>= 1;\n        }\n    }\n    // void\
    \ apply(int eventid);\n    // void rollback(int eventid);\n    // void query(int\
    \ t);\n    void run(auto apply, auto rollback, auto query){\n        events.build();\n\
    \        auto dfs = [&](auto sfs, int p) -> void {\n            for (int id :\
    \ events[p]){\n                apply(id);\n            }\n            if (p >=\
    \ sz){\n                p -= sz;\n                if (p < tmax){\n           \
    \         query(p);\n                }\n                p += sz;\n           \
    \ }\n            else {\n                sfs(sfs, p * 2);\n                sfs(sfs,\
    \ p * 2 + 1);\n            }\n            for (int id : events[p] | std::views::reverse){\n\
    \                rollback(id);\n            }\n        };\n        dfs(dfs,1);\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn:
  - data_structure/csr.hpp
  isVerificationFile: false
  path: misc/segment_divide_conquer.hpp
  requiredBy: []
  timestamp: '2025-04-19 07:18:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/segment_divide_conquer.hpp
layout: document
redirect_from:
- /library/misc/segment_divide_conquer.hpp
- /library/misc/segment_divide_conquer.hpp.html
title: misc/segment_divide_conquer.hpp
---
