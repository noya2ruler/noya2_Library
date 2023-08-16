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
  - icon: ':warning:'
    path: misc/QMC.hpp
    title: misc/QMC.hpp
  - icon: ':warning:'
    path: misc/inversion.hpp
    title: misc/inversion.hpp
  - icon: ':heavy_check_mark:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
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
  bundledCode: '#line 1 "template/const.hpp"

    namespace noya2{


    const int iinf = 1''000''000''007;

    const long long linf = 2''000''000''000''000''000''000LL;

    const long long mod998 =  998244353;

    const long long mod107 = 1000000007;

    const long double pi = 3.14159265358979323;

    const vector<int> dx = {0,1,0,-1,1,1,-1,-1};

    const vector<int> dy = {1,0,-1,0,1,-1,-1,1};

    const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const string alp = "abcdefghijklmnopqrstuvwxyz";

    const string NUM = "0123456789";


    void yes(){ cout << "Yes\n"; }

    void no(){ cout << "No\n"; }

    void YES(){ cout << "YES\n"; }

    void NO(){ cout << "NO\n"; }

    void yn(bool t){ t ? yes() : no(); }

    void YN(bool t){ t ? YES() : NO(); }


    } // namespace noya2

    '
  code: 'namespace noya2{


    const int iinf = 1''000''000''007;

    const long long linf = 2''000''000''000''000''000''000LL;

    const long long mod998 =  998244353;

    const long long mod107 = 1000000007;

    const long double pi = 3.14159265358979323;

    const vector<int> dx = {0,1,0,-1,1,1,-1,-1};

    const vector<int> dy = {1,0,-1,0,1,-1,-1,1};

    const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const string alp = "abcdefghijklmnopqrstuvwxyz";

    const string NUM = "0123456789";


    void yes(){ cout << "Yes\n"; }

    void no(){ cout << "No\n"; }

    void YES(){ cout << "YES\n"; }

    void NO(){ cout << "NO\n"; }

    void yn(bool t){ t ? yes() : no(); }

    void YN(bool t){ t ? YES() : NO(); }


    } // namespace noya2'
  dependsOn: []
  isVerificationFile: false
  path: template/const.hpp
  requiredBy:
  - data_structure/lazy_segment_tree.hpp
  - data_structure/fenwick_tree.hpp
  - data_structure/dsu.hpp
  - data_structure/sparse_table.hpp
  - data_structure/li_chao_tree.hpp
  - math/matrix.hpp
  - template/template.hpp
  - string/rolling_hash.hpp
  - utility/modint61.hpp
  - tree/Tree_core.hpp
  - tree/RerootingDP.hpp
  - tree/Mo_on_Tree.hpp
  - misc/mo_algorithm.hpp
  - misc/inversion.hpp
  - misc/QMC.hpp
  - geometry/base_ld.hpp
  - geometry/partition_by_circle.hpp
  - graph/Graph_core.hpp
  timestamp: '2023-07-17 20:27:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/data_structure/Segment_Add_Get_Min.test.cpp
  - test/data_structure/Unionfind.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Line_Add_Get_Min.test.cpp
  - test/data_structure/Static_RMQ.test.cpp
  - test/data_structure/PointAddRangeSum.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/math/Determinant_of_Matrix.test.cpp
  - test/tree/aoj_0489.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/Tree_Diameter.test.cpp
  - test/tree/Rerooting_DP.test.cpp
  - test/tree/Lowest_Common_Ancestor.test.cpp
  - test/geometry/aoj1198.test.cpp
  - test/graph/Shortest_Path.test.cpp
  - test/graph/Strongly_Connected_Components.test.cpp
documentation_of: template/const.hpp
layout: document
redirect_from:
- /library/template/const.hpp
- /library/template/const.hpp.html
title: template/const.hpp
---
