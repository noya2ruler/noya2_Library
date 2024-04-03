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
  bundledCode: "#line 2 \"data_structure/simple_queue.hpp\"\n\n#include<vector>\n\n\
    namespace noya2::internal {\n\ntemplate <class T>\nstruct simple_queue {\n   \
    \ std::vector<T> payload;\n    int pos = 0;\n    void reserve(int n) { payload.reserve(n);\
    \ }\n    int size() const { return int(payload.size()) - pos; }\n    bool empty()\
    \ const { return pos == int(payload.size()); }\n    void push(const T& t) { payload.push_back(t);\
    \ }\n    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n} // namespace noya2::internal\n"
  code: "#pragma once\n\n#include<vector>\n\nnamespace noya2::internal {\n\ntemplate\
    \ <class T>\nstruct simple_queue {\n    std::vector<T> payload;\n    int pos =\
    \ 0;\n    void reserve(int n) { payload.reserve(n); }\n    int size() const {\
    \ return int(payload.size()) - pos; }\n    bool empty() const { return pos ==\
    \ int(payload.size()); }\n    void push(const T& t) { payload.push_back(t); }\n\
    \    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n} // namespace noya2::internal"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/simple_queue.hpp
  requiredBy: []
  timestamp: '2024-04-03 14:15:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/simple_queue.hpp
layout: document
redirect_from:
- /library/data_structure/simple_queue.hpp
- /library/data_structure/simple_queue.hpp.html
title: data_structure/simple_queue.hpp
---
