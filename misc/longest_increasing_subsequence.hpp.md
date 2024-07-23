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
  bundledCode: "#line 2 \"misc/longest_increasing_subsequence.hpp\"\n\n#include <vector>\n\
    #include <algorithm>\n#include <limits>\n\nnamespace noya2 {\n\ntemplate<typename\
    \ T>\nstd::vector<int> longest_increasing_subsequence_ids(const std::vector<T>\
    \ &a){\n    if (a.empty()) return {};\n    int n = a.size();\n    const T Tinf\
    \ = std::numeric_limits<T>::max();\n    std::vector<T> dp(n, Tinf);\n    std::vector<int>\
    \ pre(n), ids(n);\n    for (int i = 0; i < n; i++){\n        int pos = std::lower_bound(dp.begin(),\
    \ dp.end(), a[i]) - dp.begin();\n        dp[pos] = a[i];\n        ids[pos] = i;\n\
    \        pre[i] = (pos == 0 ? -1 : ids[pos-1]);\n    }\n    int len = std::lower_bound(dp.begin(),\
    \ dp.end(), Tinf) - dp.begin();\n    ids.resize(len);\n    int cid = ids[len-1];\n\
    \    for (int i = len-1; i >= 0; i--){\n        ids[i] = cid;\n        cid = pre[cid];\n\
    \    }\n    return ids;\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n#include <limits>\n\
    \nnamespace noya2 {\n\ntemplate<typename T>\nstd::vector<int> longest_increasing_subsequence_ids(const\
    \ std::vector<T> &a){\n    if (a.empty()) return {};\n    int n = a.size();\n\
    \    const T Tinf = std::numeric_limits<T>::max();\n    std::vector<T> dp(n, Tinf);\n\
    \    std::vector<int> pre(n), ids(n);\n    for (int i = 0; i < n; i++){\n    \
    \    int pos = std::lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();\n  \
    \      dp[pos] = a[i];\n        ids[pos] = i;\n        pre[i] = (pos == 0 ? -1\
    \ : ids[pos-1]);\n    }\n    int len = std::lower_bound(dp.begin(), dp.end(),\
    \ Tinf) - dp.begin();\n    ids.resize(len);\n    int cid = ids[len-1];\n    for\
    \ (int i = len-1; i >= 0; i--){\n        ids[i] = cid;\n        cid = pre[cid];\n\
    \    }\n    return ids;\n}\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2024-07-23 14:29:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/misc/longest_increasing_subsequence.hpp
- /library/misc/longest_increasing_subsequence.hpp.html
title: misc/longest_increasing_subsequence.hpp
---
