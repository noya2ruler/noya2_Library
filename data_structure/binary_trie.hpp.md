---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout_old.hpp
    title: template/inout_old.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/SetXorMin.test.cpp
    title: test/data_structure/SetXorMin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/binary_trie.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout_old.hpp\"\
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
    \ YES() : NO(); }\n\n} // namespace noya2\n#line 2 \"template/utils.hpp\"\n\n\
    #line 6 \"template/utils.hpp\"\n\nnamespace noya2{\n\nunsigned long long inner_binary_gcd(unsigned\
    \ long long a, unsigned long long b){\n    if (a == 0 || b == 0) return a + b;\n\
    \    int n = __builtin_ctzll(a); a >>= n;\n    int m = __builtin_ctzll(b); b >>=\
    \ m;\n    while (a != b) {\n        int mm = __builtin_ctzll(a - b);\n       \
    \ bool f = a > b;\n        unsigned long long c = f ? a : b;\n        b = f ?\
    \ b : a;\n        a = (c - b) >> mm;\n    }\n    return a << std::min(n, m);\n\
    }\n\ntemplate<typename T> T gcd_fast(T a, T b){ return static_cast<T>(inner_binary_gcd(std::abs(a),std::abs(b)));\
    \ }\n\nlong long sqrt_fast(long long n) {\n    if (n <= 0) return 0;\n    long\
    \ long x = sqrt(n);\n    while ((x + 1) * (x + 1) <= n) x++;\n    while (x * x\
    \ > n) x--;\n    return x;\n}\n\ntemplate<typename T> T floor_div(const T n, const\
    \ T d) {\n    assert(d != 0);\n    return n / d - static_cast<T>((n ^ d) < 0 &&\
    \ n % d != 0);\n}\n\ntemplate<typename T> T ceil_div(const T n, const T d) {\n\
    \    assert(d != 0);\n    return n / d + static_cast<T>((n ^ d) >= 0 && n % d\
    \ != 0);\n}\n\ntemplate<typename T> void uniq(std::vector<T> &v){\n    std::sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n}\n\ntemplate <typename T, typename\
    \ U> inline bool chmin(T &x, U y) { return (y < x) ? (x = y, true) : false; }\n\
    \ntemplate <typename T, typename U> inline bool chmax(T &x, U y) { return (x <\
    \ y) ? (x = y, true) : false; }\n\ntemplate<typename T> inline bool range(T l,\
    \ T x, T r){ return l <= x && x < r; }\n\n} // namespace noya2\n#line 8 \"template/template.hpp\"\
    \n\n#define rep(i,n) for (int i = 0; i < (int)(n); i++)\n#define repp(i,m,n) for\
    \ (int i = (m); i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1);\
    \ i >= 0; i--)\n#define all(v) (v).begin(),(v).end()\n\nusing ll = long long;\n\
    using ld = long double;\nusing uint = unsigned int;\nusing ull = unsigned long\
    \ long;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pil = pair<int,ll>;\n\
    using pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000\
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"data_structure/binary_trie.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<typename T, int LOG>\nstruct binary_trie {\n\
    \    struct node {\n        node *p;\n        array<node*,2> ch;\n        int\
    \ leaf, sz;\n        node () : p(nullptr), ch({nullptr,nullptr}), leaf(0), sz(0)\
    \ {}\n    };\n    binary_trie () : lazy(0) {}\n    int size(node *v){\n      \
    \  if (v == nullptr) return 0;\n        return v->sz;\n    }\n    int size(){\n\
    \        return size(root);\n    }\n    void insert(T x){\n        x ^= lazy;\n\
    \        node *v = root;\n        for (int i = LOG-1; i >= 0; i--){\n        \
    \    int j = x >> i & 1;\n            if (v->ch[j] == nullptr){\n            \
    \    v->ch[j] = new node();\n                v->ch[j]->p = v;\n            }\n\
    \            v = v->ch[j];\n        }\n        v->leaf = 1;\n        update(v);\n\
    \        for (int i = 0; i < LOG; i++){\n            v = v->p;\n            update(v);\n\
    \        }\n    }\n    void erase(T x){\n        x ^= lazy;\n        node *v =\
    \ root;\n        for (int i = LOG-1; i >= 0; i--){\n            int j = x >> i\
    \ & 1;\n            if (v->ch[j] == nullptr) return ;\n            v = v->ch[j];\n\
    \        }\n        v->leaf = 0;\n        update(v);\n        for (int i = 0;\
    \ i < LOG; i++){\n            node *p = v->p;\n            if (size(v) == 0){\n\
    \                (v == p->ch[0] ? p->ch[0] : p->ch[1]) = nullptr;\n          \
    \      delete v;\n            }\n            v = p;\n            update(v);\n\
    \        }\n    }\n    int count(T x){\n        node *v = root;\n        int res\
    \ = 0;\n        for (int i = LOG-1; i >= 0; i--){\n            int j = lazy >>\
    \ i & 1;\n            if (x >> i & 1){\n                res += size(v->ch[j]);\n\
    \                v = v->ch[j^1];\n            }\n            else {\n        \
    \        v = v->ch[j];\n            }\n            if (v == nullptr) break;\n\
    \        }\n        return res;\n    }\n    T get(int k){\n        if (k < 0 ||\
    \ k >= size()) return -1;\n        node *v = root;\n        T ans = 0;\n     \
    \   for (int i = LOG-1; i >= 0; i--){\n            int j = lazy >> i & 1;\n  \
    \          if (k < size(v->ch[j])){\n                v = v->ch[j];\n         \
    \   }\n            else {\n                k -= size(v->ch[j]);\n            \
    \    v = v->ch[j^1];\n                ans |= T(1) << i;\n            }\n     \
    \   }\n        return ans;\n    }\n    T mex(){\n        if ((T)size() == (T(1)<<LOG))\
    \ return T(1)<<LOG;\n        node *v = root;\n        T ans = 0;\n        for\
    \ (int i = LOG-1; i >= 0; i--){\n            int j = lazy >> i & 1;\n        \
    \    if ((T)size(v->ch[j]) < (T(1)<<i)){\n                v = v->ch[j];\n    \
    \        }\n            else {\n                v = v->ch[j^1];\n            \
    \    ans |= T(1) << i;\n            }\n            if (v == nullptr) break;\n\
    \        }\n        return ans;\n    }\n    T xor_all(T x){ return lazy ^= x;\
    \ }\n    vector<T> enumerate(){\n        vector<T> ans; ans.reserve(size());\n\
    \        auto dfs = [&](auto sfs, int i, T x, node *v) -> void {\n           \
    \ if (i == -1){\n                ans.emplace_back(x^lazy);\n                return\
    \ ;\n            }\n            if (v->ch[0] != nullptr){\n                sfs(sfs,i-1,x,v->ch[0]);\n\
    \            }\n            if (v->ch[1] != nullptr){\n                sfs(sfs,i-1,x|(T(1)<<i),v->ch[1]);\n\
    \            }\n        };\n        dfs(dfs,LOG-1,0,root);\n        return ans;\n\
    \    }\n  private:\n    T lazy;\n    node *root = new node();\n    void update(node\
    \ *v){\n        v->sz = v->leaf + size(v->ch[0]) + size(v->ch[1]);\n    }\n};\n\
    \n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2 {\n\
    \ntemplate<typename T, int LOG>\nstruct binary_trie {\n    struct node {\n   \
    \     node *p;\n        array<node*,2> ch;\n        int leaf, sz;\n        node\
    \ () : p(nullptr), ch({nullptr,nullptr}), leaf(0), sz(0) {}\n    };\n    binary_trie\
    \ () : lazy(0) {}\n    int size(node *v){\n        if (v == nullptr) return 0;\n\
    \        return v->sz;\n    }\n    int size(){\n        return size(root);\n \
    \   }\n    void insert(T x){\n        x ^= lazy;\n        node *v = root;\n  \
    \      for (int i = LOG-1; i >= 0; i--){\n            int j = x >> i & 1;\n  \
    \          if (v->ch[j] == nullptr){\n                v->ch[j] = new node();\n\
    \                v->ch[j]->p = v;\n            }\n            v = v->ch[j];\n\
    \        }\n        v->leaf = 1;\n        update(v);\n        for (int i = 0;\
    \ i < LOG; i++){\n            v = v->p;\n            update(v);\n        }\n \
    \   }\n    void erase(T x){\n        x ^= lazy;\n        node *v = root;\n   \
    \     for (int i = LOG-1; i >= 0; i--){\n            int j = x >> i & 1;\n   \
    \         if (v->ch[j] == nullptr) return ;\n            v = v->ch[j];\n     \
    \   }\n        v->leaf = 0;\n        update(v);\n        for (int i = 0; i < LOG;\
    \ i++){\n            node *p = v->p;\n            if (size(v) == 0){\n       \
    \         (v == p->ch[0] ? p->ch[0] : p->ch[1]) = nullptr;\n                delete\
    \ v;\n            }\n            v = p;\n            update(v);\n        }\n \
    \   }\n    int count(T x){\n        node *v = root;\n        int res = 0;\n  \
    \      for (int i = LOG-1; i >= 0; i--){\n            int j = lazy >> i & 1;\n\
    \            if (x >> i & 1){\n                res += size(v->ch[j]);\n      \
    \          v = v->ch[j^1];\n            }\n            else {\n              \
    \  v = v->ch[j];\n            }\n            if (v == nullptr) break;\n      \
    \  }\n        return res;\n    }\n    T get(int k){\n        if (k < 0 || k >=\
    \ size()) return -1;\n        node *v = root;\n        T ans = 0;\n        for\
    \ (int i = LOG-1; i >= 0; i--){\n            int j = lazy >> i & 1;\n        \
    \    if (k < size(v->ch[j])){\n                v = v->ch[j];\n            }\n\
    \            else {\n                k -= size(v->ch[j]);\n                v =\
    \ v->ch[j^1];\n                ans |= T(1) << i;\n            }\n        }\n \
    \       return ans;\n    }\n    T mex(){\n        if ((T)size() == (T(1)<<LOG))\
    \ return T(1)<<LOG;\n        node *v = root;\n        T ans = 0;\n        for\
    \ (int i = LOG-1; i >= 0; i--){\n            int j = lazy >> i & 1;\n        \
    \    if ((T)size(v->ch[j]) < (T(1)<<i)){\n                v = v->ch[j];\n    \
    \        }\n            else {\n                v = v->ch[j^1];\n            \
    \    ans |= T(1) << i;\n            }\n            if (v == nullptr) break;\n\
    \        }\n        return ans;\n    }\n    T xor_all(T x){ return lazy ^= x;\
    \ }\n    vector<T> enumerate(){\n        vector<T> ans; ans.reserve(size());\n\
    \        auto dfs = [&](auto sfs, int i, T x, node *v) -> void {\n           \
    \ if (i == -1){\n                ans.emplace_back(x^lazy);\n                return\
    \ ;\n            }\n            if (v->ch[0] != nullptr){\n                sfs(sfs,i-1,x,v->ch[0]);\n\
    \            }\n            if (v->ch[1] != nullptr){\n                sfs(sfs,i-1,x|(T(1)<<i),v->ch[1]);\n\
    \            }\n        };\n        dfs(dfs,LOG-1,0,root);\n        return ans;\n\
    \    }\n  private:\n    T lazy;\n    node *root = new node();\n    void update(node\
    \ *v){\n        v->sz = v->leaf + size(v->ch[0]) + size(v->ch[1]);\n    }\n};\n\
    \n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2024-07-03 00:54:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/SetXorMin.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.hpp
- /library/data_structure/binary_trie.hpp.html
title: data_structure/binary_trie.hpp
---
