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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/random_tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ YES() : NO(); }\n\n} // namespace noya2\n#line 1 \"template/utils.hpp\"\nnamespace\
    \ noya2{\n\nunsigned long long inner_binary_gcd(unsigned long long a, unsigned\
    \ long long b){\n    if (a == 0 || b == 0) return a + b;\n    int n = __builtin_ctzll(a);\
    \ a >>= n;\n    int m = __builtin_ctzll(b); b >>= m;\n    while (a != b) {\n \
    \       int mm = __builtin_ctzll(a - b);\n        bool f = a > b;\n        unsigned\
    \ long long c = f ? a : b;\n        b = f ? b : a;\n        a = (c - b) >> mm;\n\
    \    }\n    return a << min(n, m);\n}\n\ntemplate<typename T> T gcd_fast(T a,\
    \ T b){ return static_cast<T>(inner_binary_gcd(abs(a),abs(b))); }\n\nlong long\
    \ sqrt_fast(long long n) {\n    if (n <= 0) return 0;\n    long long x = sqrt(n);\n\
    \    while ((x + 1) * (x + 1) <= n) x++;\n    while (x * x > n) x--;\n    return\
    \ x;\n}\n\ntemplate<typename T> T floor_div(const T n, const T d) {\n    assert(d\
    \ != 0);\n    return n / d - static_cast<T>((n ^ d) < 0 && n % d != 0);\n}\n\n\
    template<typename T> T ceil_div(const T n, const T d) {\n    assert(d != 0);\n\
    \    return n / d + static_cast<T>((n ^ d) >= 0 && n % d != 0);\n}\n\ntemplate<typename\
    \ T> void uniq(vector<T> &v){\n    sort(v.begin(),v.end());\n    v.erase(unique(v.begin(),v.end()),v.end());\n\
    }\n\ntemplate <typename T, typename U> inline bool chmin(T &x, U y) { return (y\
    \ < x) ? (x = y, true) : false; }\n\ntemplate <typename T, typename U> inline\
    \ bool chmax(T &x, U y) { return (x < y) ? (x = y, true) : false; }\n\ntemplate<typename\
    \ T> inline bool range(T l, T x, T r){ return l <= x && x < r; }\n\n} // namespace\
    \ noya2\n#line 8 \"template/template.hpp\"\n\n#define rep(i,n) for (int i = 0;\
    \ i < (int)(n); i++)\n#define repp(i,m,n) for (int i = (m); i < (int)(n); i++)\n\
    #define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n#define all(v) (v).begin(),(v).end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\n\
    using ull = unsigned long long;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\n\
    using pil = pair<int,ll>;\nusing pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000\
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"misc/random_tree.hpp\"\
    \n\nnamespace noya2 {\n\n// input: [c \\in [0, n)] * (n-2), n >= 3\nvector<vector<int>>\
    \ pruefer_code(const vector<int>& code) {\n    int n = code.size() + 2;\n    assert(n\
    \ > 2);\n    vector<vector<int>> g(n);\n    vector<int> deg(n, 1);\n    int e\
    \ = 0;\n    for (auto& x : code) deg[x]++;\n    set<int> ps;\n    for (int j =\
    \ 0; j < n; j++) {\n        if (deg[j] == 1) ps.insert(j);\n    }\n    for (auto&\
    \ i : code) {\n        if (ps.empty()) break;\n        int j = *begin(ps);\n \
    \       ps.erase(j);\n        g[i].push_back(j);\n        g[j].push_back(i);\n\
    \        if (deg[i] == 1) ps.erase(i);\n        deg[i]--, deg[j]--;\n        if\
    \ (deg[i] == 1) ps.insert(i);\n        e++;\n    }\n    int u = -1, v = -1;\n\
    \    for (int i = 0; i < n; i++) {\n        if (deg[i] == 1) (u == -1 ? u : v)\
    \ = i;\n    }\n    assert(u != -1 and v != -1);\n    g[u].push_back(v);\n    g[v].push_back(u);\n\
    \    e++;\n    assert(e == n - 1);\n    return g;\n}\n\nvector<vector<int>> random_tree(int\
    \ n) {\n    if (n <= 2) {\n        vector<vector<int>> g(n);\n        if (n ==\
    \ 2) {\n            g[0].push_back(1);\n            g[1].push_back(0);\n     \
    \   }\n        return g;\n    }\n    vector<int> pruefer(n - 2);\n    for (auto&\
    \ x : pruefer) x = rnd.next(n);\n    return pruefer_code(pruefer);\n}\n\n} //\
    \ namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2 {\n\
    \n// input: [c \\in [0, n)] * (n-2), n >= 3\nvector<vector<int>> pruefer_code(const\
    \ vector<int>& code) {\n    int n = code.size() + 2;\n    assert(n > 2);\n   \
    \ vector<vector<int>> g(n);\n    vector<int> deg(n, 1);\n    int e = 0;\n    for\
    \ (auto& x : code) deg[x]++;\n    set<int> ps;\n    for (int j = 0; j < n; j++)\
    \ {\n        if (deg[j] == 1) ps.insert(j);\n    }\n    for (auto& i : code) {\n\
    \        if (ps.empty()) break;\n        int j = *begin(ps);\n        ps.erase(j);\n\
    \        g[i].push_back(j);\n        g[j].push_back(i);\n        if (deg[i] ==\
    \ 1) ps.erase(i);\n        deg[i]--, deg[j]--;\n        if (deg[i] == 1) ps.insert(i);\n\
    \        e++;\n    }\n    int u = -1, v = -1;\n    for (int i = 0; i < n; i++)\
    \ {\n        if (deg[i] == 1) (u == -1 ? u : v) = i;\n    }\n    assert(u != -1\
    \ and v != -1);\n    g[u].push_back(v);\n    g[v].push_back(u);\n    e++;\n  \
    \  assert(e == n - 1);\n    return g;\n}\n\nvector<vector<int>> random_tree(int\
    \ n) {\n    if (n <= 2) {\n        vector<vector<int>> g(n);\n        if (n ==\
    \ 2) {\n            g[0].push_back(1);\n            g[1].push_back(0);\n     \
    \   }\n        return g;\n    }\n    vector<int> pruefer(n - 2);\n    for (auto&\
    \ x : pruefer) x = rnd.next(n);\n    return pruefer_code(pruefer);\n}\n\n} //\
    \ namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: misc/random_tree.hpp
  requiredBy: []
  timestamp: '2024-02-09 20:15:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/random_tree.hpp
layout: document
redirect_from:
- /library/misc/random_tree.hpp
- /library/misc/random_tree.hpp.html
title: misc/random_tree.hpp
---