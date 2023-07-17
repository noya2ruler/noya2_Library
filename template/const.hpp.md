---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
  - icon: ':warning:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':x:'
    path: data_structure/sparce_table.hpp
    title: data_structure/sparce_table.hpp
  - icon: ':x:'
    path: geometry/base_ld.hpp
    title: geometry/base_ld.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: tree/Mo_on_Tree.hpp
    title: tree/Mo_on_Tree.hpp
  - icon: ':x:'
    path: tree/RerootingDP.hpp
    title: Rerooting DP
  - icon: ':x:'
    path: tree/Tree_core.hpp
    title: tree/Tree_core.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':x:'
    path: test/data_structure/Static_RMQ.test.cpp
    title: test/data_structure/Static_RMQ.test.cpp
  - icon: ':x:'
    path: test/geometry/aoj1198.test.cpp
    title: test/geometry/aoj1198.test.cpp
  - icon: ':x:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':x:'
    path: test/tree/Rerooting_DP.test.cpp
    title: test/tree/Rerooting_DP.test.cpp
  - icon: ':x:'
    path: test/tree/Tree_Diameter.test.cpp
    title: test/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  timestamp: '2023-07-17 20:27:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/geometry/aoj1198.test.cpp
  - test/tree/Rerooting_DP.test.cpp
  - test/tree/Tree_Diameter.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/data_structure/Static_RMQ.test.cpp
documentation_of: template/const.hpp
layout: document
redirect_from:
- /library/template/const.hpp
- /library/template/const.hpp.html
title: template/const.hpp
---
