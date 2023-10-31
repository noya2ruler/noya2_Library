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
  bundledCode: "#line 2 \"misc/subset_sum.hpp\"\n\n#include<vector>\n#include<span>\n\
    #include<algorithm>\n#include<utility>\n\nnamespace noya2 {\n\nnamespace fast_subset_sum\
    \ {\n\ntemplate<typename T, size_t Extent>\nauto inner_subset_sum(std::span<T,Extent>\
    \ a, bool sorted = false){\n    std::vector<T> cur(1<<a.size());\n    cur[0] =\
    \ T(0);\n    unsigned int sz = 1;\n    for (auto &x : a){\n        for (unsigned\
    \ int s = 0; s < sz; s++){\n            cur[sz + s] = cur[s] + x;\n        }\n\
    \        if (sorted) std::inplace_merge(cur.begin(),cur.begin()+sz,cur.begin()+sz*2);\n\
    \        sz <<= 1;\n    }\n    return cur;\n}\n\ntemplate<typename T, size_t Extent>\n\
    auto inner_subset_sum_indexed(std::span<T,Extent> a, bool sorted = false){\n \
    \   std::vector<std::pair<T,unsigned int>> cur(1<<a.size());\n    cur[0] = {T(0),0u};\n\
    \    unsigned int sz = 1;\n    for (unsigned int i = 0; auto &x : a){\n      \
    \  for (unsigned int s = 0; s < sz; s++){\n            cur[sz + s].first = cur[s].first\
    \ + x;\n            cur[sz + s].second = cur[s].second | (1u << i);\n        }\n\
    \        if (sorted) std::inplace_merge(cur.begin(),cur.begin()+sz,cur.begin()+sz*2);\n\
    \        sz <<= 1;\n        i++;\n    }\n    return cur;\n}\n\n} // namespace\
    \ subset_sum\n\ntemplate<typename T>\nauto subset_sum(std::vector<T> a, bool sorted\
    \ = false){\n    return fast_subset_sum::inner_subset_sum(std::span{a},sorted);\n\
    }\n\ntemplate<typename T>\nauto subset_sum_indexed(std::vector<T> a, bool sorted\
    \ = false){\n    return fast_subset_sum::inner_subset_sum_indexed(std::span{a},sorted);\n\
    }\n\ntemplate<typename T>\nbool half_enumeration(std::vector<T> a, T target){\n\
    \    int n = a.size(), h = n/2;\n    auto le = fast_subset_sum::inner_subset_sum(std::span{a.begin(),a.begin()+h},true);\n\
    \    auto ri = fast_subset_sum::inner_subset_sum(std::span{a.begin()+h,a.end()},true);\n\
    \    int lsz = 1<<h, rsz = 1<<(n-h);\n    for (int l = 0, r = rsz-1; l < lsz;\
    \ l++){\n        while (r >= 0 && le[l] + ri[r] > target) r--;\n        if (r\
    \ < 0) break;\n        if (le[l] + ri[r] == target) return true;\n    }\n    return\
    \ false;\n}\n\ntemplate<typename T>\nlong long half_enumeration_indexed(std::vector<T>\
    \ a, T target){\n    int n = a.size(), h = n/2;\n    auto le = fast_subset_sum::inner_subset_sum_indexed(std::span{a.begin(),a.begin()+h},true);\n\
    \    auto ri = fast_subset_sum::inner_subset_sum_indexed(std::span{a.begin()+h,a.end()},true);\n\
    \    int lsz = 1<<h, rsz = 1<<(n-h);\n    for (int l = 0, r = rsz-1; l < lsz;\
    \ l++){\n        while (r >= 0 && le[l].first + ri[r].first > target) r--;\n \
    \       if (r < 0) break;\n        if (le[l].first + ri[r].first == target){\n\
    \            return ((long long)(ri[r].second) << h) | le[l].second;\n       \
    \ }\n    }\n    return -1;\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<vector>\n#include<span>\n#include<algorithm>\n#include<utility>\n\
    \nnamespace noya2 {\n\nnamespace fast_subset_sum {\n\ntemplate<typename T, size_t\
    \ Extent>\nauto inner_subset_sum(std::span<T,Extent> a, bool sorted = false){\n\
    \    std::vector<T> cur(1<<a.size());\n    cur[0] = T(0);\n    unsigned int sz\
    \ = 1;\n    for (auto &x : a){\n        for (unsigned int s = 0; s < sz; s++){\n\
    \            cur[sz + s] = cur[s] + x;\n        }\n        if (sorted) std::inplace_merge(cur.begin(),cur.begin()+sz,cur.begin()+sz*2);\n\
    \        sz <<= 1;\n    }\n    return cur;\n}\n\ntemplate<typename T, size_t Extent>\n\
    auto inner_subset_sum_indexed(std::span<T,Extent> a, bool sorted = false){\n \
    \   std::vector<std::pair<T,unsigned int>> cur(1<<a.size());\n    cur[0] = {T(0),0u};\n\
    \    unsigned int sz = 1;\n    for (unsigned int i = 0; auto &x : a){\n      \
    \  for (unsigned int s = 0; s < sz; s++){\n            cur[sz + s].first = cur[s].first\
    \ + x;\n            cur[sz + s].second = cur[s].second | (1u << i);\n        }\n\
    \        if (sorted) std::inplace_merge(cur.begin(),cur.begin()+sz,cur.begin()+sz*2);\n\
    \        sz <<= 1;\n        i++;\n    }\n    return cur;\n}\n\n} // namespace\
    \ subset_sum\n\ntemplate<typename T>\nauto subset_sum(std::vector<T> a, bool sorted\
    \ = false){\n    return fast_subset_sum::inner_subset_sum(std::span{a},sorted);\n\
    }\n\ntemplate<typename T>\nauto subset_sum_indexed(std::vector<T> a, bool sorted\
    \ = false){\n    return fast_subset_sum::inner_subset_sum_indexed(std::span{a},sorted);\n\
    }\n\ntemplate<typename T>\nbool half_enumeration(std::vector<T> a, T target){\n\
    \    int n = a.size(), h = n/2;\n    auto le = fast_subset_sum::inner_subset_sum(std::span{a.begin(),a.begin()+h},true);\n\
    \    auto ri = fast_subset_sum::inner_subset_sum(std::span{a.begin()+h,a.end()},true);\n\
    \    int lsz = 1<<h, rsz = 1<<(n-h);\n    for (int l = 0, r = rsz-1; l < lsz;\
    \ l++){\n        while (r >= 0 && le[l] + ri[r] > target) r--;\n        if (r\
    \ < 0) break;\n        if (le[l] + ri[r] == target) return true;\n    }\n    return\
    \ false;\n}\n\ntemplate<typename T>\nlong long half_enumeration_indexed(std::vector<T>\
    \ a, T target){\n    int n = a.size(), h = n/2;\n    auto le = fast_subset_sum::inner_subset_sum_indexed(std::span{a.begin(),a.begin()+h},true);\n\
    \    auto ri = fast_subset_sum::inner_subset_sum_indexed(std::span{a.begin()+h,a.end()},true);\n\
    \    int lsz = 1<<h, rsz = 1<<(n-h);\n    for (int l = 0, r = rsz-1; l < lsz;\
    \ l++){\n        while (r >= 0 && le[l].first + ri[r].first > target) r--;\n \
    \       if (r < 0) break;\n        if (le[l].first + ri[r].first == target){\n\
    \            return ((long long)(ri[r].second) << h) | le[l].second;\n       \
    \ }\n    }\n    return -1;\n}\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/subset_sum.hpp
  requiredBy: []
  timestamp: '2023-11-01 03:32:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/subset_sum.hpp
layout: document
redirect_from:
- /library/misc/subset_sum.hpp
- /library/misc/subset_sum.hpp.html
title: misc/subset_sum.hpp
---
