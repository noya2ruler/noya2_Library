---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/run_enumerate.hpp
    title: string/run_enumerate.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/RunEnumerate.test.cpp
    title: test/string/RunEnumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/Z_Algorithm.test.cpp
    title: test/string/Z_Algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <numeric>\n#include <string>\n#include <vector>\n\n// atcoder/string\n\
    \nnamespace noya2 {\n\n// Reference:\n// D. Gusfield,\n// Algorithms on Strings,\
    \ Trees, and Sequences: Computer Science and\n// Computational Biology\ntemplate\
    \ <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {\n    int n\
    \ = int(s.size());\n    if (n == 0) return {};\n    std::vector<int> z(n);\n \
    \   z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int& k = z[i];\n\
    \        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n       \
    \ while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i + z[i])\
    \ j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    #include <string>\n#include <vector>\n\n// atcoder/string\n\nnamespace noya2 {\n\
    \n// Reference:\n// D. Gusfield,\n// Algorithms on Strings, Trees, and Sequences:\
    \ Computer Science and\n// Computational Biology\ntemplate <class T> std::vector<int>\
    \ z_algorithm(const std::vector<T>& s) {\n    int n = int(s.size());\n    if (n\
    \ == 0) return {};\n    std::vector<int> z(n);\n    z[0] = 0;\n    for (int i\
    \ = 1, j = 0; i < n; i++) {\n        int& k = z[i];\n        k = (j + z[j] <=\
    \ i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n        while (i + k < n && s[k]\
    \ == s[i + k]) k++;\n        if (j + z[j] < i + z[i]) j = i;\n    }\n    z[0]\
    \ = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const std::string& s)\
    \ {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy:
  - string/run_enumerate.hpp
  timestamp: '2024-07-16 15:04:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/RunEnumerate.test.cpp
  - test/string/Z_Algorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
