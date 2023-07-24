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
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_RMQ.test.cpp
    title: test/data_structure/Static_RMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_table.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout.hpp\"\
    \nnamespace noya2 {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
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
    \   }\n} iosetup_noya2;\n\n} // namespace noya2\n#line 1 \"template/const.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"data_structure/sparse_table.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<class S, S (*op)(S, S)>\nstruct SparseTable{\n\
    \    vector<vector<S>> table;\n    SparseTable (const vector<S> &vec){\n     \
    \   int n = vec.size(), n2 = 0;\n        while ((1<<n2) < n) n2++;\n        table.resize(n2+1);\n\
    \        for (int i = 0; i <= n2; i++){\n            table[i].resize(n);\n   \
    \         if (i == 0){\n                for (int j = 0; j < n; j++){\n       \
    \             table[i][j] = vec[j];\n                }\n            }\n      \
    \      else {\n                for (int j = 0; j < n; j++){\n                \
    \    if (j + (1 << (i-1)) < n) table[i][j] = op(table[i-1][j],table[i-1][j + (1\
    \ << (i-1))]);\n                    else table[i][j] = table[i-1][j];\n      \
    \          }\n            }\n        }\n    }\n    // \u5358\u4F4D\u5143\u3092\
    \u8981\u6C42\u3057\u306A\u3044\u306E\u3067 if (l >= r) return e() \u307F\u305F\
    \u3044\u306A\u3053\u3068\u3092\u3057\u3066\u3044\u306A\u3044\u3001\u6CE8\u610F\
    \u3059\u308B\u3053\u3068\uFF01\uFF01\n    S get(int l, int r){\n        assert(r\
    \ - l > 0);\n        int lgs = 31 - __builtin_clz((unsigned int)(r-l));\n    \
    \    return op(table[lgs][l], table[lgs][r - (1 << lgs)]);\n    }\n};\n\n} //\
    \ namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\
    \ntemplate<class S, S (*op)(S, S)>\nstruct SparseTable{\n    vector<vector<S>>\
    \ table;\n    SparseTable (const vector<S> &vec){\n        int n = vec.size(),\
    \ n2 = 0;\n        while ((1<<n2) < n) n2++;\n        table.resize(n2+1);\n  \
    \      for (int i = 0; i <= n2; i++){\n            table[i].resize(n);\n     \
    \       if (i == 0){\n                for (int j = 0; j < n; j++){\n         \
    \           table[i][j] = vec[j];\n                }\n            }\n        \
    \    else {\n                for (int j = 0; j < n; j++){\n                  \
    \  if (j + (1 << (i-1)) < n) table[i][j] = op(table[i-1][j],table[i-1][j + (1\
    \ << (i-1))]);\n                    else table[i][j] = table[i-1][j];\n      \
    \          }\n            }\n        }\n    }\n    // \u5358\u4F4D\u5143\u3092\
    \u8981\u6C42\u3057\u306A\u3044\u306E\u3067 if (l >= r) return e() \u307F\u305F\
    \u3044\u306A\u3053\u3068\u3092\u3057\u3066\u3044\u306A\u3044\u3001\u6CE8\u610F\
    \u3059\u308B\u3053\u3068\uFF01\uFF01\n    S get(int l, int r){\n        assert(r\
    \ - l > 0);\n        int lgs = 31 - __builtin_clz((unsigned int)(r-l));\n    \
    \    return op(table[lgs][l], table[lgs][r - (1 << lgs)]);\n    }\n};\n\n} //\
    \ namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2023-07-23 17:25:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Static_RMQ.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---
