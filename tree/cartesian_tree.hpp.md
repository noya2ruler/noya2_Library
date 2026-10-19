---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/CartesianTree.test.cpp
    title: test/tree/CartesianTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/cartesian_tree.hpp\"\n\n#include <vector>\n#include\
    \ <functional>\n#include <stack>\n#include <utility>\n#include <cassert>\n\nnamespace\
    \ noya2 {\n\n// {root, par}, par[root] == root\ntemplate<typename T, class comp\
    \ = std::less<T>>\nstd::pair<int, std::vector<int>> cartesian_tree(std::vector<T>\
    \ a){\n    comp cp;\n    int n = a.size();\n    assert(n >= 1);\n    std::stack<int,\
    \ std::vector<int>> st;\n    st.push(0);\n    std::vector<int> par(n);\n    for\
    \ (int i = 1; i < n; i++){\n        if (cp(a[st.top()], a[i])){\n            par[i]\
    \ = st.top();\n            st.push(i);\n            continue;\n        }\n   \
    \     int ch = -1;\n        while (!st.empty() && !cp(a[st.top()],a[i])){\n  \
    \          ch = st.top(); st.pop();\n        }\n        par[ch] = i;\n       \
    \ if (!st.empty()){\n            par[i] = st.top();\n        }\n        st.push(i);\n\
    \    }\n    while (st.size() > 1u) st.pop();\n    par[st.top()] = st.top();\n\
    \    return {st.top(), par};\n}\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <functional>\n#include <stack>\n\
    #include <utility>\n#include <cassert>\n\nnamespace noya2 {\n\n// {root, par},\
    \ par[root] == root\ntemplate<typename T, class comp = std::less<T>>\nstd::pair<int,\
    \ std::vector<int>> cartesian_tree(std::vector<T> a){\n    comp cp;\n    int n\
    \ = a.size();\n    assert(n >= 1);\n    std::stack<int, std::vector<int>> st;\n\
    \    st.push(0);\n    std::vector<int> par(n);\n    for (int i = 1; i < n; i++){\n\
    \        if (cp(a[st.top()], a[i])){\n            par[i] = st.top();\n       \
    \     st.push(i);\n            continue;\n        }\n        int ch = -1;\n  \
    \      while (!st.empty() && !cp(a[st.top()],a[i])){\n            ch = st.top();\
    \ st.pop();\n        }\n        par[ch] = i;\n        if (!st.empty()){\n    \
    \        par[i] = st.top();\n        }\n        st.push(i);\n    }\n    while\
    \ (st.size() > 1u) st.pop();\n    par[st.top()] = st.top();\n    return {st.top(),\
    \ par};\n}\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2025-03-22 13:12:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/CartesianTree.test.cpp
documentation_of: tree/cartesian_tree.hpp
layout: document
redirect_from:
- /library/tree/cartesian_tree.hpp
- /library/tree/cartesian_tree.hpp.html
title: tree/cartesian_tree.hpp
---
