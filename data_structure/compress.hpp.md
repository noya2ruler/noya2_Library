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
  bundledCode: "#line 2 \"data_structure/compress.hpp\"\n\n#include<vector>\n#include<algorithm>\n\
    \nnamespace noya2{\n\ntemplate<typename T> struct compress {\n    std::vector<T>\
    \ raws;\n    compress(const std::vector<T> &raws_) : raws(raws_){\n        std::sort(raws.begin(),raws.end());\n\
    \        raws.erase(std::unique(rows.begin(),rows.end()),rows.end());\n    }\n\
    \    int id(T raw){ return std::lower_bound(raws.begin(),raws.end(),raw) - raws.begin();\
    \ }\n    T raw(int id){ return raws[id]; }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<vector>\n#include<algorithm>\n\nnamespace noya2{\n\
    \ntemplate<typename T> struct compress {\n    std::vector<T> raws;\n    compress(const\
    \ std::vector<T> &raws_) : raws(raws_){\n        std::sort(raws.begin(),raws.end());\n\
    \        raws.erase(std::unique(rows.begin(),rows.end()),rows.end());\n    }\n\
    \    int id(T raw){ return std::lower_bound(raws.begin(),raws.end(),raw) - raws.begin();\
    \ }\n    T raw(int id){ return raws[id]; }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy: []
  timestamp: '2023-08-30 16:19:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/compress.hpp
layout: document
redirect_from:
- /library/data_structure/compress.hpp
- /library/data_structure/compress.hpp.html
title: data_structure/compress.hpp
---
