---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/RunEnumerate.test.cpp
    title: test/string/RunEnumerate.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/run_enumerate.hpp\"\n\n#include <vector>\n#include\
    \ <tuple>\n#include <ranges>\n#include <algorithm>\n#include <unordered_map>\n\
    #include <string>\n#include <cstdint>\n\n#line 2 \"string/z_algorithm.hpp\"\n\n\
    #line 4 \"string/z_algorithm.hpp\"\n#include <cassert>\n#include <numeric>\n#line\
    \ 8 \"string/z_algorithm.hpp\"\n\n// atcoder/string\n\nnamespace noya2 {\n\n//\
    \ Reference:\n// D. Gusfield,\n// Algorithms on Strings, Trees, and Sequences:\
    \ Computer Science and\n// Computational Biology\ntemplate <class T> std::vector<int>\
    \ z_algorithm(const std::vector<T>& s) {\n    int n = int(s.size());\n    if (n\
    \ == 0) return {};\n    std::vector<int> z(n);\n    z[0] = 0;\n    for (int i\
    \ = 1, j = 0; i < n; i++) {\n        int& k = z[i];\n        k = (j + z[j] <=\
    \ i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n        while (i + k < n && s[k]\
    \ == s[i + k]) k++;\n        if (j + z[j] < i + z[i]) j = i;\n    }\n    z[0]\
    \ = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const std::string& s)\
    \ {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n} // namespace noya2\n#line 12 \"string/run_enumerate.hpp\"\n\nnamespace\
    \ noya2 {\n\nstd::vector<std::tuple<int,int,int>> run_enumerate(std::string s){\n\
    \    std::unordered_map<uint64_t,int> periods;\n    auto update = [&](int t, int\
    \ l, int r){\n        uint64_t h = ((uint64_t)(l) << 32) | r;\n        if (!periods.contains(h)\
    \ || periods[h] > t){\n            periods[h] = t;\n        }\n    };\n    auto\
    \ dfs = [&](auto sfs, int l, int r) -> void {\n        if (r - l == 1) return\
    \ ;\n        int m = (l + r) / 2;\n        std::string sl(s.begin() + l, s.begin()\
    \ + m);\n        std::string sr(s.begin() + m, s.begin() + r);\n        std::string\
    \ rev = sl; std::ranges::reverse(rev);\n        // L\n        {\n            auto\
    \ zl = z_algorithm(rev);\n            auto zr = z_algorithm(sr + sl);\n      \
    \      // [i, m) is period\n            for (int i = l; i < m; i++){\n       \
    \         int lextend = (i == l ? 0 : zl[m - i]);\n                int rextend\
    \ = zr[r - m + i - l];\n                if (rextend == m - i){\n             \
    \       rextend += zr[m - i];\n                    if (rextend > r - m){\n   \
    \                     rextend = r - m;\n                    }\n              \
    \  }\n                if (lextend + rextend >= m - i){\n                    if\
    \ (i - lextend == l && l > 0) continue;\n                    if (m + rextend ==\
    \ r && r < (int)(s.size())) continue;\n                    update(m - i, i - lextend,\
    \ m + rextend);\n                }\n            }\n        }\n        std::ranges::reverse_copy(sr,\
    \ std::back_inserter(rev));\n        // R\n        {\n            // [m, i) is\
    \ period\n            auto zl = z_algorithm(rev);\n            auto zr = z_algorithm(sr);\n\
    \            for (int i = m+1; i <= r; i++){\n                int lextend = zl[m\
    \ - l + r - i];\n                if (lextend == i - m){\n                    lextend\
    \ += zl[i - m];\n                    if (lextend > m - l){\n                 \
    \       lextend = m - l;\n                    }\n                }\n         \
    \       int rextend = (i == r ? 0 : zr[i - m]);\n                if (lextend +\
    \ rextend >= i - m){\n                    if (m - lextend == l && l > 0) continue;\n\
    \                    if (i + rextend == r && r < (int)(s.size())) continue;\n\
    \                    update(i - m, m - lextend, i + rextend);\n              \
    \  }\n            }\n        }\n        sfs(sfs, l, m);\n        sfs(sfs, m, r);\n\
    \    };\n    dfs(dfs,0,s.size());\n    std::vector<std::tuple<int,int,int>> ret;\
    \ ret.reserve(periods.size());\n    for (auto [lr, t] : periods){\n        int\
    \ r = lr & UINT32_MAX;\n        int l = lr >> 32;\n        ret.emplace_back(t,\
    \ l, r);\n    }\n    std::ranges::sort(ret);\n    return ret;\n}\n\n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <tuple>\n#include <ranges>\n\
    #include <algorithm>\n#include <unordered_map>\n#include <string>\n#include <cstdint>\n\
    \n#include\"string/z_algorithm.hpp\"\n\nnamespace noya2 {\n\nstd::vector<std::tuple<int,int,int>>\
    \ run_enumerate(std::string s){\n    std::unordered_map<uint64_t,int> periods;\n\
    \    auto update = [&](int t, int l, int r){\n        uint64_t h = ((uint64_t)(l)\
    \ << 32) | r;\n        if (!periods.contains(h) || periods[h] > t){\n        \
    \    periods[h] = t;\n        }\n    };\n    auto dfs = [&](auto sfs, int l, int\
    \ r) -> void {\n        if (r - l == 1) return ;\n        int m = (l + r) / 2;\n\
    \        std::string sl(s.begin() + l, s.begin() + m);\n        std::string sr(s.begin()\
    \ + m, s.begin() + r);\n        std::string rev = sl; std::ranges::reverse(rev);\n\
    \        // L\n        {\n            auto zl = z_algorithm(rev);\n          \
    \  auto zr = z_algorithm(sr + sl);\n            // [i, m) is period\n        \
    \    for (int i = l; i < m; i++){\n                int lextend = (i == l ? 0 :\
    \ zl[m - i]);\n                int rextend = zr[r - m + i - l];\n            \
    \    if (rextend == m - i){\n                    rextend += zr[m - i];\n     \
    \               if (rextend > r - m){\n                        rextend = r - m;\n\
    \                    }\n                }\n                if (lextend + rextend\
    \ >= m - i){\n                    if (i - lextend == l && l > 0) continue;\n \
    \                   if (m + rextend == r && r < (int)(s.size())) continue;\n \
    \                   update(m - i, i - lextend, m + rextend);\n               \
    \ }\n            }\n        }\n        std::ranges::reverse_copy(sr, std::back_inserter(rev));\n\
    \        // R\n        {\n            // [m, i) is period\n            auto zl\
    \ = z_algorithm(rev);\n            auto zr = z_algorithm(sr);\n            for\
    \ (int i = m+1; i <= r; i++){\n                int lextend = zl[m - l + r - i];\n\
    \                if (lextend == i - m){\n                    lextend += zl[i -\
    \ m];\n                    if (lextend > m - l){\n                        lextend\
    \ = m - l;\n                    }\n                }\n                int rextend\
    \ = (i == r ? 0 : zr[i - m]);\n                if (lextend + rextend >= i - m){\n\
    \                    if (m - lextend == l && l > 0) continue;\n              \
    \      if (i + rextend == r && r < (int)(s.size())) continue;\n              \
    \      update(i - m, m - lextend, i + rextend);\n                }\n         \
    \   }\n        }\n        sfs(sfs, l, m);\n        sfs(sfs, m, r);\n    };\n \
    \   dfs(dfs,0,s.size());\n    std::vector<std::tuple<int,int,int>> ret; ret.reserve(periods.size());\n\
    \    for (auto [lr, t] : periods){\n        int r = lr & UINT32_MAX;\n       \
    \ int l = lr >> 32;\n        ret.emplace_back(t, l, r);\n    }\n    std::ranges::sort(ret);\n\
    \    return ret;\n}\n\n} // namespace noya2"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: false
  path: string/run_enumerate.hpp
  requiredBy: []
  timestamp: '2024-12-04 14:23:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/RunEnumerate.test.cpp
documentation_of: string/run_enumerate.hpp
layout: document
redirect_from:
- /library/string/run_enumerate.hpp
- /library/string/run_enumerate.hpp.html
title: string/run_enumerate.hpp
---
