---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: data_structure/lazy_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: geometry/base_ld.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/partition_by_circle.hpp
    title: geometry/partition_by_circle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/Graph_core.hpp
    title: graph/Graph_core.hpp
  - icon: ':warning:'
    path: misc/QMC.hpp
    title: misc/QMC.hpp
  - icon: ':warning:'
    path: misc/inversion.hpp
    title: misc/inversion.hpp
  - icon: ':heavy_check_mark:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
  - icon: ':heavy_check_mark:'
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
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_RMQ.test.cpp
    title: test/data_structure/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Unionfind.test.cpp
    title: test/data_structure/Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/aoj1198.test.cpp
    title: test/geometry/aoj1198.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Shortest_Path.test.cpp
    title: test/graph/Shortest_Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rerooting_DP.test.cpp
    title: test/tree/Rerooting_DP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Diameter.test.cpp
    title: test/tree/Tree_Diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/aoj_0489.test.cpp
    title: test/tree/aoj_0489.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
    #line 1 \"template/inout.hpp\"\nnamespace noya2 {\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first\
    \ << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
    \  return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const\
    \ vector<T> &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os\
    \ << (i ? \" \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream\
    \ &operator>>(istream &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return\
    \ is;\n}\n\nvoid in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...u)\
    \ {\n  cin >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate\
    \ <typename T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...u)\
    \ {\n  cout << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nstruct\
    \ IoSetup {\n  IoSetup() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetup_noya2;\n\n}  // namespace noya2\n#line 1 \"template/const.hpp\"\
    \nnamespace noya2{\n\nconst int iinf = 1'000'000'007;\nconst long long linf =\
    \ 2'000'000'000'000'000'000LL;\nconst long long mod998 =  998244353;\nconst long\
    \ long mod107 = 1000000007;\nconst long double pi = 3.14159265358979323;\nconst\
    \ vector<int> dx = {0,1,0,-1,1,1,-1,-1};\nconst vector<int> dy = {1,0,-1,0,1,-1,-1,1};\n\
    const string ALP = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\nconst string alp = \"abcdefghijklmnopqrstuvwxyz\"\
    ;\nconst string NUM = \"0123456789\";\n\nvoid yes(){ cout << \"Yes\\n\"; }\nvoid\
    \ no(){ cout << \"No\\n\"; }\nvoid YES(){ cout << \"YES\\n\"; }\nvoid NO(){ cout\
    \ << \"NO\\n\"; }\nvoid yn(bool t){ t ? yes() : no(); }\nvoid YN(bool t){ t ?\
    \ YES() : NO(); }\n\n} // namespace noya2\n#line 1 \"template/utils.hpp\"\nnamespace\
    \ noya2{\n\nunsigned long long inner_binary_gcd(unsigned long long a, unsigned\
    \ long long b){\n    if (a == 0 || b == 0) return a + b;\n    int n = __builtin_ctzll(a);\n\
    \    int m = __builtin_ctzll(b);\n    a >>= n;\n    b >>= m;\n    while (a !=\
    \ b) {\n        int m = __builtin_ctzll(a - b);\n        bool f = a > b;\n   \
    \     unsigned long long c = f ? a : b;\n        b = f ? b : a;\n        a = (c\
    \ - b) >> m;\n    }\n    return a << min(n, m);\n}\n\ntemplate<typename T>\nT\
    \ gcd_fast(T a, T b){\n    return static_cast<T>(inner_binary_gcd(abs(a),abs(b)));\n\
    }\n\ntemplate<typename T>\nT floor_div(const T n, const T d) {\n    assert(d !=\
    \ 0);\n    return n / d - static_cast<T>((n ^ d) < 0 && n % d != 0);\n}\n\ntemplate<typename\
    \ T>\nT ceil_div(const T n, const T d) {\n    assert(d != 0);\n    return n /\
    \ d + static_cast<T>((n ^ d) >= 0 && n % d != 0);\n}\n\ntemplate<typename T> void\
    \ uniq(vector<T> &v){\n    sort(all(v));\n    v.erase(unique(all(v)),v.end());\n\
    }\n\ntemplate <typename T, typename U>\ninline bool chmin(T &x, U y) {\n    return\
    \ (y < x) ? (x = y, true) : false;\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool chmax(T &x, U y) {\n    return (x < y) ? (x = y, true) : false;\n}\n\n\
    template<typename T>\ninline bool range(T l, T x, T r){\n    return l <= x &&\
    \ x < r;\n}\n\n} // namespace noya2\n#line 8 \"template/template.hpp\"\n\n#define\
    \ rep(i,n) for (int i = 0; i < (int)(n); i++)\n#define repp(i,m,n) for (int i\
    \ = (m); i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1); i >= 0;\
    \ i--)\n#define all(v) (v).begin(),(v).end()\n\nusing ll = long long;\nusing ld\
    \ = long double;\nusing uint = unsigned int;\nusing ull = unsigned long long;\n\
    using pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pil = pair<int,ll>;\n\
    using pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000\
    */\n\n}\n\nusing namespace noya2;\n\n\n"
  code: "#pragma once\nusing namespace std;\n\n#include<bits/stdc++.h>\n#include\"\
    inout.hpp\"\n#include\"const.hpp\"\n#include\"utils.hpp\"\n\n#define rep(i,n)\
    \ for (int i = 0; i < (int)(n); i++)\n#define repp(i,m,n) for (int i = (m); i\
    \ < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n#define\
    \ all(v) (v).begin(),(v).end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using uint = unsigned int;\nusing ull = unsigned long long;\nusing pii = pair<int,int>;\n\
    using pll = pair<ll,ll>;\nusing pil = pair<int,ll>;\nusing pli = pair<ll,int>;\n\
    \nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace\
    \ noya2;\n\n\n"
  dependsOn:
  - template/inout.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - geometry/base_ld.hpp
  - geometry/partition_by_circle.hpp
  - tree/Mo_on_Tree.hpp
  - tree/RerootingDP.hpp
  - tree/Tree_core.hpp
  - graph/Graph_core.hpp
  - data_structure/fenwick_tree.hpp
  - data_structure/dsu.hpp
  - data_structure/lazy_segment_tree.hpp
  - data_structure/sparse_table.hpp
  - misc/inversion.hpp
  - misc/QMC.hpp
  - misc/mo_algorithm.hpp
  timestamp: '2023-07-17 20:36:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/geometry/aoj1198.test.cpp
  - test/tree/Rerooting_DP.test.cpp
  - test/tree/Tree_Diameter.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/aoj_0489.test.cpp
  - test/graph/Shortest_Path.test.cpp
  - test/data_structure/Unionfind.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/data_structure/PointAddRangeSum.test.cpp
  - test/data_structure/Static_RMQ.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
