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
    path: data_structure/lazy_segment_tree.hpp
    title: data_structure/lazy_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.hpp
    title: data_structure/li_chao_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: fps/formal_power_series.hpp
    title: fps/formal_power_series.hpp
  - icon: ':warning:'
    path: fps/fps_arbitrary.hpp
    title: fps/fps_arbitrary.hpp
  - icon: ':warning:'
    path: fps/fps_atcoder.hpp
    title: fps/fps_atcoder.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_ntt.hpp
    title: fps/fps_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt.hpp
    title: fps/ntt.hpp
  - icon: ':warning:'
    path: fps/relaxed_convolution.hpp
    title: fps/relaxed_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: geometry/base_ld.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/partition_by_circle.hpp
    title: geometry/partition_by_circle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/Graph_core.hpp
    title: graph/Graph_core.hpp
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
  - icon: ':warning:'
    path: misc/QMC.hpp
    title: misc/QMC.hpp
  - icon: ':warning:'
    path: misc/inversion.hpp
    title: misc/inversion.hpp
  - icon: ':warning:'
    path: misc/mex.hpp
    title: misc/mex.hpp
  - icon: ':heavy_check_mark:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
  - icon: ':warning:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':warning:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/Mo_on_Tree.hpp
    title: Mo on Tree
  - icon: ':heavy_check_mark:'
    path: tree/RerootingDP.hpp
    title: Rerooting DP
  - icon: ':heavy_check_mark:'
    path: tree/Tree_core.hpp
    title: tree/Tree_core.hpp
  - icon: ':warning:'
    path: utility/modint61.hpp
    title: utility/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint_new.hpp
    title: utility/modint_new.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Line_Add_Get_Min.test.cpp
    title: test/data_structure/Line_Add_Get_Min.test.cpp
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
    path: test/data_structure/Segment_Add_Get_Min.test.cpp
    title: test/data_structure/Segment_Add_Get_Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_RMQ.test.cpp
    title: test/data_structure/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Unionfind.test.cpp
    title: test/data_structure/Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/convolution.test.cpp
    title: test/fps/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/aoj1198.test.cpp
    title: test/geometry/aoj1198.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Shortest_Path.test.cpp
    title: test/graph/Shortest_Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Strongly_Connected_Components.test.cpp
    title: test/graph/Strongly_Connected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Determinant_of_Matrix.test.cpp
    title: test/math/Determinant_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Lowest_Common_Ancestor.test.cpp
    title: test/tree/Lowest_Common_Ancestor.test.cpp
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
  bundledCode: "#line 1 \"template/inout_old.hpp\"\nnamespace noya2 {\n\ntemplate\
    \ <typename T, typename U>\nostream &operator<<(ostream &os, const pair<T, U>\
    \ &p){\n    os << p.first << \" \" << p.second;\n    return os;\n}\ntemplate <typename\
    \ T, typename U>\nistream &operator>>(istream &is, pair<T, U> &p){\n    is >>\
    \ p.first >> p.second;\n    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v){\n    int s = (int)v.size();\n    for (int i = 0; i\
    \ < s; i++) os << (i ? \" \" : \"\") << v[i];\n    return os;\n}\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (auto &x : v) is\
    \ >> x;\n    return is;\n}\n\nvoid in() {}\ntemplate <typename T, class... U>\n\
    void in(T &t, U &...u){\n    cin >> t;\n    in(u...);\n}\n\nvoid out() { cout\
    \ << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\nvoid out(const\
    \ T &t, const U &...u){\n    cout << t;\n    if (sizeof...(u)) cout << sep;\n\
    \    out(u...);\n}\n\ntemplate<typename T>\nvoid out(const vector<vector<T>> &vv){\n\
    \    int s = (int)vv.size();\n    for (int i = 0; i < s; i++) out(vv[i]);\n}\n\
    \nstruct IoSetup {\n    IoSetup(){\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n\
    \    }\n} iosetup_noya2;\n\n} // namespace noya2\n"
  code: "namespace noya2 {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p){\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v){\n    int\
    \ s = (int)v.size();\n    for (int i = 0; i < s; i++) os << (i ? \" \" : \"\"\
    ) << v[i];\n    return os;\n}\ntemplate <typename T>\nistream &operator>>(istream\
    \ &is, vector<T> &v){\n    for (auto &x : v) is >> x;\n    return is;\n}\n\nvoid\
    \ in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...u){\n    cin\
    \ >> t;\n    in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...u){\n    cout\
    \ << t;\n    if (sizeof...(u)) cout << sep;\n    out(u...);\n}\n\ntemplate<typename\
    \ T>\nvoid out(const vector<vector<T>> &vv){\n    int s = (int)vv.size();\n  \
    \  for (int i = 0; i < s; i++) out(vv[i]);\n}\n\nstruct IoSetup {\n    IoSetup(){\n\
    \        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout\
    \ << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n \
    \   }\n} iosetup_noya2;\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: template/inout_old.hpp
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
  - misc/mex.hpp
  - misc/rng.hpp
  - misc/mo_algorithm.hpp
  - template/template.hpp
  - graph/Graph_core.hpp
  - utility/modint61.hpp
  - utility/modint_new.hpp
  - geometry/base_ld.hpp
  - geometry/partition_by_circle.hpp
  - math/matrix.hpp
  - math/prime.hpp
  - fps/fps_arbitrary.hpp
  - fps/fps_ntt.hpp
  - fps/relaxed_convolution.hpp
  - fps/formal_power_series.hpp
  - fps/fps_atcoder.hpp
  - fps/ntt.hpp
  timestamp: '2023-08-26 05:21:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
  - test/math/Binomial_Coefficient_Prime_Mod_modintnew.test.cpp
  - test/fps/convolution.test.cpp
documentation_of: template/inout_old.hpp
layout: document
redirect_from:
- /library/template/inout_old.hpp
- /library/template/inout_old.hpp.html
title: template/inout_old.hpp
---
