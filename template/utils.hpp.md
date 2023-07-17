---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sparce_table.hpp
    title: data_structure/sparce_table.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: geometry/base_ld.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/partition_by_circle.hpp
    title: geometry/partition_by_circle.hpp
  - icon: ':warning:'
    path: misc/QMC.hpp
    title: misc/QMC.hpp
  - icon: ':warning:'
    path: misc/inversion.hpp
    title: misc/inversion.hpp
  - icon: ':warning:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: tree/Mo_on_Tree.hpp
    title: tree/Mo_on_Tree.hpp
  - icon: ':heavy_check_mark:'
    path: tree/RerootingDP.hpp
    title: Rerooting DP
  - icon: ':heavy_check_mark:'
    path: tree/Tree_core.hpp
    title: tree/Tree_core.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/PointAddRangeSum.test.cpp
    title: test/data_structure/PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_RMQ.test.cpp
    title: test/data_structure/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/aoj1198.test.cpp
    title: test/geometry/aoj1198.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rerooting_DP.test.cpp
    title: test/tree/Rerooting_DP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Diameter.test.cpp
    title: test/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/utils.hpp\"\nnamespace noya2{\n\nunsigned long\
    \ long inner_binary_gcd(unsigned long long a, unsigned long long b){\n    if (a\
    \ == 0 || b == 0) return a + b;\n    int n = __builtin_ctzll(a);\n    int m =\
    \ __builtin_ctzll(b);\n    a >>= n;\n    b >>= m;\n    while (a != b) {\n    \
    \    int m = __builtin_ctzll(a - b);\n        bool f = a > b;\n        unsigned\
    \ long long c = f ? a : b;\n        b = f ? b : a;\n        a = (c - b) >> m;\n\
    \    }\n    return a << min(n, m);\n}\n\ntemplate<typename T>\nT gcd_fast(T a,\
    \ T b){\n    return static_cast<T>(inner_binary_gcd(abs(a),abs(b)));\n}\n\ntemplate<typename\
    \ T>\nT floor_div(const T n, const T d) {\n    assert(d != 0);\n    return n /\
    \ d - static_cast<T>((n ^ d) < 0 && n % d != 0);\n}\n\ntemplate<typename T>\n\
    T ceil_div(const T n, const T d) {\n    assert(d != 0);\n    return n / d + static_cast<T>((n\
    \ ^ d) >= 0 && n % d != 0);\n}\n\ntemplate<typename T> void uniq(vector<T> &v){\n\
    \    sort(all(v));\n    v.erase(unique(all(v)),v.end());\n}\n\ntemplate <typename\
    \ T, typename U>\ninline bool chmin(T &x, U y) {\n    return (y < x) ? (x = y,\
    \ true) : false;\n}\n\ntemplate <typename T, typename U>\ninline bool chmax(T\
    \ &x, U y) {\n    return (x < y) ? (x = y, true) : false;\n}\n\ntemplate<typename\
    \ T>\ninline bool range(T l, T x, T r){\n    return l <= x && x < r;\n}\n\n} //\
    \ namespace noya2\n"
  code: "namespace noya2{\n\nunsigned long long inner_binary_gcd(unsigned long long\
    \ a, unsigned long long b){\n    if (a == 0 || b == 0) return a + b;\n    int\
    \ n = __builtin_ctzll(a);\n    int m = __builtin_ctzll(b);\n    a >>= n;\n   \
    \ b >>= m;\n    while (a != b) {\n        int m = __builtin_ctzll(a - b);\n  \
    \      bool f = a > b;\n        unsigned long long c = f ? a : b;\n        b =\
    \ f ? b : a;\n        a = (c - b) >> m;\n    }\n    return a << min(n, m);\n}\n\
    \ntemplate<typename T>\nT gcd_fast(T a, T b){\n    return static_cast<T>(inner_binary_gcd(abs(a),abs(b)));\n\
    }\n\ntemplate<typename T>\nT floor_div(const T n, const T d) {\n    assert(d !=\
    \ 0);\n    return n / d - static_cast<T>((n ^ d) < 0 && n % d != 0);\n}\n\ntemplate<typename\
    \ T>\nT ceil_div(const T n, const T d) {\n    assert(d != 0);\n    return n /\
    \ d + static_cast<T>((n ^ d) >= 0 && n % d != 0);\n}\n\ntemplate<typename T> void\
    \ uniq(vector<T> &v){\n    sort(all(v));\n    v.erase(unique(all(v)),v.end());\n\
    }\n\ntemplate <typename T, typename U>\ninline bool chmin(T &x, U y) {\n    return\
    \ (y < x) ? (x = y, true) : false;\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool chmax(T &x, U y) {\n    return (x < y) ? (x = y, true) : false;\n}\n\n\
    template<typename T>\ninline bool range(T l, T x, T r){\n    return l <= x &&\
    \ x < r;\n}\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: template/utils.hpp
  requiredBy:
  - geometry/base_ld.hpp
  - geometry/partition_by_circle.hpp
  - tree/Mo_on_Tree.hpp
  - tree/RerootingDP.hpp
  - tree/Tree_core.hpp
  - template/template.hpp
  - data_structure/fenwick_tree.hpp
  - data_structure/dsu.hpp
  - data_structure/sparce_table.hpp
  - misc/inversion.hpp
  - misc/QMC.hpp
  - misc/mo_algorithm.hpp
  timestamp: '2023-07-17 20:36:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/aoj1198.test.cpp
  - test/tree/Rerooting_DP.test.cpp
  - test/tree/Tree_Diameter.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/data_structure/PointAddRangeSum.test.cpp
  - test/data_structure/Static_RMQ.test.cpp
documentation_of: template/utils.hpp
layout: document
redirect_from:
- /library/template/utils.hpp
- /library/template/utils.hpp.html
title: template/utils.hpp
---
