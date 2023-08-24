---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
  - icon: ':x:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':x:'
    path: data_structure/lazy_segment_tree.hpp
    title: data_structure/lazy_segment_tree.hpp
  - icon: ':x:'
    path: data_structure/li_chao_tree.hpp
    title: data_structure/li_chao_tree.hpp
  - icon: ':x:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':x:'
    path: geometry/base_ld.hpp
    title: geometry/base_ld.hpp
  - icon: ':x:'
    path: geometry/partition_by_circle.hpp
    title: geometry/partition_by_circle.hpp
  - icon: ':x:'
    path: graph/Graph_core.hpp
    title: graph/Graph_core.hpp
  - icon: ':x:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':warning:'
    path: misc/QMC.hpp
    title: misc/QMC.hpp
  - icon: ':warning:'
    path: misc/inversion.hpp
    title: misc/inversion.hpp
  - icon: ':x:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
  - icon: ':warning:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':warning:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: tree/Mo_on_Tree.hpp
    title: Mo on Tree
  - icon: ':x:'
    path: tree/RerootingDP.hpp
    title: Rerooting DP
  - icon: ':x:'
    path: tree/Tree_core.hpp
    title: tree/Tree_core.hpp
  - icon: ':warning:'
    path: utility/modint61.hpp
    title: utility/modint61.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/Line_Add_Get_Min.test.cpp
    title: test/data_structure/Line_Add_Get_Min.test.cpp
  - icon: ':x:'
    path: test/data_structure/PointAddRangeSum.test.cpp
    title: test/data_structure/PointAddRangeSum.test.cpp
  - icon: ':x:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':x:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':x:'
    path: test/data_structure/Segment_Add_Get_Min.test.cpp
    title: test/data_structure/Segment_Add_Get_Min.test.cpp
  - icon: ':x:'
    path: test/data_structure/Static_RMQ.test.cpp
    title: test/data_structure/Static_RMQ.test.cpp
  - icon: ':x:'
    path: test/data_structure/Unionfind.test.cpp
    title: test/data_structure/Unionfind.test.cpp
  - icon: ':x:'
    path: test/geometry/aoj1198.test.cpp
    title: test/geometry/aoj1198.test.cpp
  - icon: ':x:'
    path: test/graph/Shortest_Path.test.cpp
    title: test/graph/Shortest_Path.test.cpp
  - icon: ':x:'
    path: test/graph/Strongly_Connected_Components.test.cpp
    title: test/graph/Strongly_Connected_Components.test.cpp
  - icon: ':x:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':x:'
    path: test/math/Determinant_of_Matrix.test.cpp
    title: test/math/Determinant_of_Matrix.test.cpp
  - icon: ':x:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':x:'
    path: test/tree/Lowest_Common_Ancestor.test.cpp
    title: test/tree/Lowest_Common_Ancestor.test.cpp
  - icon: ':x:'
    path: test/tree/Rerooting_DP.test.cpp
    title: test/tree/Rerooting_DP.test.cpp
  - icon: ':x:'
    path: test/tree/Tree_Diameter.test.cpp
    title: test/tree/Tree_Diameter.test.cpp
  - icon: ':x:'
    path: test/tree/aoj_0489.test.cpp
    title: test/tree/aoj_0489.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/inout.hpp\"\nnamespace noya2 {\n\ntemplate<typename\
    \ T> concept Scanable  = requires (ifstream &is, T &a){ is >> a; };\ntemplate<typename\
    \ T> concept Printable = requires (ofstream &os, T &a){ os << a; };\n\ntemplate\
    \ <typename Scanable> istream &operator>>(istream &is, vector<Scanable> &v);\n\
    template <typename Printable> ostream &operator<<(ostream &os, const vector<Printable>\
    \ &v);\n\ntemplate <typename T, typename U>\nrequires Scanable<T> && Scanable<U>\n\
    istream &operator>>(istream &is, pair<T, U> &p){\n    is >> p.first >> p.second;\n\
    \    return is;\n}\ntemplate <typename T, typename U>\nrequires Printable<T> &&\
    \ Printable<U>\nostream &operator<<(ostream &os, const pair<T, U> &p){\n    os\
    \ << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate <typename Scanable>\n\
    istream &operator>>(istream &is, vector<Scanable> &v){\n    for (auto &x : v)\
    \ is >> x;\n    return is;\n}\ntemplate <typename Printable>\nostream &operator<<(ostream\
    \ &os, const vector<Printable> &v){\n    int s = (int)v.size();\n    for (int\
    \ i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n    return os;\n}\n\n\
    void in() {}\ntemplate <typename Scanable, class... U>\nvoid in(Scanable &t, U\
    \ &...u){\n    cin >> t;\n    in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\n\
    template <typename Printable, class... U, char sep = ' '>\nvoid out(const Printable\
    \ &t, const U &...u){\n    cout << t;\n    if (sizeof...(u)) cout << sep;\n  \
    \  out(u...);\n}\ntemplate<typename Printable>\nvoid out(const vector<vector<Printable>>\
    \ &vv){\n    int s = (int)vv.size();\n    for (int i = 0; i < s; i++) out(vv[i]);\n\
    }\n\nstruct IoSetup {\n    IoSetup(){\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n\
    \    }\n} iosetup_noya2;\n\n} // namespace noya2\n"
  code: "namespace noya2 {\n\ntemplate<typename T> concept Scanable  = requires (ifstream\
    \ &is, T &a){ is >> a; };\ntemplate<typename T> concept Printable = requires (ofstream\
    \ &os, T &a){ os << a; };\n\ntemplate <typename Scanable> istream &operator>>(istream\
    \ &is, vector<Scanable> &v);\ntemplate <typename Printable> ostream &operator<<(ostream\
    \ &os, const vector<Printable> &v);\n\ntemplate <typename T, typename U>\nrequires\
    \ Scanable<T> && Scanable<U>\nistream &operator>>(istream &is, pair<T, U> &p){\n\
    \    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename T, typename\
    \ U>\nrequires Printable<T> && Printable<U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p){\n    os << p.first << \" \" << p.second;\n    return os;\n\
    }\n\ntemplate <typename Scanable>\nistream &operator>>(istream &is, vector<Scanable>\
    \ &v){\n    for (auto &x : v) is >> x;\n    return is;\n}\ntemplate <typename\
    \ Printable>\nostream &operator<<(ostream &os, const vector<Printable> &v){\n\
    \    int s = (int)v.size();\n    for (int i = 0; i < s; i++) os << (i ? \" \"\
    \ : \"\") << v[i];\n    return os;\n}\n\nvoid in() {}\ntemplate <typename Scanable,\
    \ class... U>\nvoid in(Scanable &t, U &...u){\n    cin >> t;\n    in(u...);\n\
    }\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename Printable, class... U,\
    \ char sep = ' '>\nvoid out(const Printable &t, const U &...u){\n    cout << t;\n\
    \    if (sizeof...(u)) cout << sep;\n    out(u...);\n}\ntemplate<typename Printable>\n\
    void out(const vector<vector<Printable>> &vv){\n    int s = (int)vv.size();\n\
    \    for (int i = 0; i < s; i++) out(vv[i]);\n}\n\nstruct IoSetup {\n    IoSetup(){\n\
    \        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout\
    \ << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n \
    \   }\n} iosetup_noya2;\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: template/inout.hpp
  requiredBy:
  - data_structure/sparse_table.hpp
  - data_structure/lazy_segment_tree.hpp
  - data_structure/dsu.hpp
  - data_structure/fenwick_tree.hpp
  - data_structure/li_chao_tree.hpp
  - tree/Mo_on_Tree.hpp
  - tree/RerootingDP.hpp
  - tree/Tree_core.hpp
  - string/rolling_hash.hpp
  - misc/inversion.hpp
  - misc/QMC.hpp
  - misc/rng.hpp
  - misc/mo_algorithm.hpp
  - template/template.hpp
  - graph/Graph_core.hpp
  - utility/modint61.hpp
  - geometry/base_ld.hpp
  - geometry/partition_by_circle.hpp
  - math/matrix.hpp
  timestamp: '2023-08-24 20:23:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/data_structure/Segment_Add_Get_Min.test.cpp
  - test/data_structure/Line_Add_Get_Min.test.cpp
  - test/data_structure/PointAddRangeSum.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Unionfind.test.cpp
  - test/data_structure/Static_RMQ.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/tree/Tree_Diameter.test.cpp
  - test/tree/Rerooting_DP.test.cpp
  - test/tree/aoj_0489.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/Lowest_Common_Ancestor.test.cpp
  - test/graph/Strongly_Connected_Components.test.cpp
  - test/graph/Shortest_Path.test.cpp
  - test/geometry/aoj1198.test.cpp
  - test/math/Determinant_of_Matrix.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
documentation_of: template/inout.hpp
layout: document
redirect_from:
- /library/template/inout.hpp
- /library/template/inout.hpp.html
title: template/inout.hpp
---
