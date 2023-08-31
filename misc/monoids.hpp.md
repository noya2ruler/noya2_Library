---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data_structure/binary_indexed_tree.hpp
    title: data_structure/binary_indexed_tree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/monoids.hpp\"\n\n#include<limits>\n\nnamespace noya2{\n\
    \ntemplate<typename T>\nstruct Max_monoid {\n    using value_type = T;\n    static\
    \ constexpr T op(const T &a, const T &b){ return max(a,b); }\n    static constexpr\
    \ T e(){ return std::numeric_limits<T>::min(); }\n    static constexpr T inv(const\
    \ T &a){ return e(); }\n};\ntemplate<typename T>\nstruct Min_monoid {\n    using\
    \ value_type = T;\n    static constexpr T op(const T &a, const T &b){ return min(a,b);\
    \ }\n    static constexpr T e(){ return std::numeric_limits<T>::max(); }\n   \
    \ static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename T>\n\
    struct Plus_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a + b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return -a; }\n};\ntemplate<typename\
    \ T>\nstruct Xor_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a ^ b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return a; }\n};\n    \n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include<limits>\n\nnamespace noya2{\n\ntemplate<typename\
    \ T>\nstruct Max_monoid {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return max(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::min();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct Min_monoid {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return min(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::max();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct Plus_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a + b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return -a; }\n};\ntemplate<typename\
    \ T>\nstruct Xor_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a ^ b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return a; }\n};\n    \n} // namespace\
    \ noya2\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/monoids.hpp
  requiredBy:
  - data_structure/binary_indexed_tree.hpp
  timestamp: '2023-08-31 21:58:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/monoids.hpp
layout: document
redirect_from:
- /library/misc/monoids.hpp
- /library/misc/monoids.hpp.html
title: misc/monoids.hpp
---
