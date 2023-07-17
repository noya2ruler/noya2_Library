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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/Mo_on_Tree.hpp
    title: tree/Mo_on_Tree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp
  bundledCode: "#line 2 \"misc/mo_algorithm.hpp\"\n\n/*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
    \n*/\n\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 10 \"misc/mo_algorithm.hpp\"\n\n\
    namespace noya2{\n\nstruct Mo {\n    int width;\n    std::vector<int> left, right,\
    \ order;\n\n    Mo(int N = 1, int Q = 1): order(Q) {\n        width = std::max<int>(1,\
    \ 1.0 * N / std::max<double>(1.0, std::sqrt(Q * 2.0 / 3.0)));\n        std::iota(begin(order),\
    \ end(order), 0);\n    }\n\n    void insert(int l, int r) { /* [l, r) */\n   \
    \     left.emplace_back(l);\n        right.emplace_back(r);\n    }\n\n    template\
    \ <typename AL, typename AR, typename DL, typename DR, typename REM>\n    void\
    \ run(const AL& add_left, const AR& add_right, const DL& delete_left,\n      \
    \  const DR& delete_right, const REM& rem) {\n        assert(left.size() == order.size());\n\
    \        sort(begin(order), end(order), [&](int a, int b) {\n            int ablock\
    \ = left[a] / width, bblock = left[b] / width;\n            if (ablock != bblock)\
    \ return ablock < bblock;\n            if (ablock & 1) return right[a] < right[b];\n\
    \            return right[a] > right[b];\n            });\n        int nl = 0,\
    \ nr = 0;\n        for (auto idx : order) {\n            while (nl > left[idx])\
    \ add_left(--nl);\n            while (nr < right[idx]) add_right(nr++);\n    \
    \        while (nl < left[idx]) delete_left(nl++);\n            while (nr > right[idx])\
    \ delete_right(--nr);\n            rem(idx);\n        }\n    }\n};\n\n}\n"
  code: "#pragma once\n\n/*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
    \n*/\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\nstruct Mo\
    \ {\n    int width;\n    std::vector<int> left, right, order;\n\n    Mo(int N\
    \ = 1, int Q = 1): order(Q) {\n        width = std::max<int>(1, 1.0 * N / std::max<double>(1.0,\
    \ std::sqrt(Q * 2.0 / 3.0)));\n        std::iota(begin(order), end(order), 0);\n\
    \    }\n\n    void insert(int l, int r) { /* [l, r) */\n        left.emplace_back(l);\n\
    \        right.emplace_back(r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename DL, typename DR, typename REM>\n    void run(const AL& add_left,\
    \ const AR& add_right, const DL& delete_left,\n        const DR& delete_right,\
    \ const REM& rem) {\n        assert(left.size() == order.size());\n        sort(begin(order),\
    \ end(order), [&](int a, int b) {\n            int ablock = left[a] / width, bblock\
    \ = left[b] / width;\n            if (ablock != bblock) return ablock < bblock;\n\
    \            if (ablock & 1) return right[a] < right[b];\n            return right[a]\
    \ > right[b];\n            });\n        int nl = 0, nr = 0;\n        for (auto\
    \ idx : order) {\n            while (nl > left[idx]) add_left(--nl);\n       \
    \     while (nr < right[idx]) add_right(nr++);\n            while (nl < left[idx])\
    \ delete_left(nl++);\n            while (nr > right[idx]) delete_right(--nr);\n\
    \            rem(idx);\n        }\n    }\n};\n\n}\n"
  dependsOn:
  - template/template.hpp
  - template/inout.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: misc/mo_algorithm.hpp
  requiredBy:
  - tree/Mo_on_Tree.hpp
  timestamp: '2023-07-17 20:36:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/mo_algorithm.hpp
layout: document
redirect_from:
- /library/misc/mo_algorithm.hpp
- /library/misc/mo_algorithm.hpp.html
title: misc/mo_algorithm.hpp
---
