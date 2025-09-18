---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/aho_corasick.hpp
    title: string/aho_corasick.hpp
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aho_corasick
    links:
    - https://judge.yosupo.jp/problem/aho_corasick
  bundledCode: "#line 1 \"test/string/AhoCorasick.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aho_corasick\"\
    \n\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
    #line 1 \"template/inout_old.hpp\"\nnamespace noya2 {\n\ntemplate <typename T,\
    \ typename U>\nostream &operator<<(ostream &os, const pair<T, U> &p){\n    os\
    \ << p.first << \" \" << p.second;\n    return os;\n}\ntemplate <typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &p){\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ const vector<T> &v){\n    int s = (int)v.size();\n    for (int i = 0; i < s;\
    \ i++) os << (i ? \" \" : \"\") << v[i];\n    return os;\n}\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (auto &x : v) is\
    \ >> x;\n    return is;\n}\n\nvoid in() {}\ntemplate <typename T, class... U>\n\
    void in(T &t, U &...u){\n    cin >> t;\n    in(u...);\n}\n\nvoid out() { cout\
    \ << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\nvoid out(const\
    \ T &t, const U &...u){\n    cout << t;\n    if (sizeof...(u)) cout << sep;\n\
    \    out(u...);\n}\n\ntemplate<typename T>\nvoid out(const vector<vector<T>> &vv){\n\
    \    int s = (int)vv.size();\n    for (int i = 0; i < s; i++) out(vv[i]);\n}\n\
    \nstruct IoSetup {\n    IoSetup(){\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n\
    \    }\n} iosetup_noya2;\n\n} // namespace noya2\n#line 1 \"template/const.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"string/aho_corasick.hpp\"\n\n\
    #line 6 \"string/aho_corasick.hpp\"\n\nnamespace noya2 {\n\ntemplate<int sigma\
    \ = 26, char start = 'a'>\nstruct aho_corasick {\n    using child = std::array<int,sigma>;\n\
    \    static constexpr child makeleaf(){\n        child ret = {};\n        ret.fill(-1);\n\
    \        return ret;\n    }\n    static constexpr child leaf = makeleaf();\n \
    \   struct node {\n        int par, link, exist, match;\n        char c;\n   \
    \     child ch;\n        node () {}\n        node (int _par, int _link, int _exist,\
    \ int _match, char _c, child _ch) : \n            par(_par), link(_link), exist(_exist),\
    \ match(_match), c(_c), ch(_ch) {}\n        int operator[](char nxt) const {\n\
    \            return ch[nxt - start];\n        }\n    };\n    std::vector<node>\
    \ vs;\n    aho_corasick (int len = 0) {\n        vs.reserve(len);\n        vs.emplace_back(-1,\
    \ 0, 0, 0, ' ', leaf);\n    }\n    int insert(const std::string &s){\n       \
    \ int v = 0;\n        for (auto c : s){\n            if (vs[v][c] == -1){\n  \
    \              v = add_leaf(v, c);\n            }\n            else {\n      \
    \          v = vs[v][c];\n            }\n        }\n        vs[v].exist += 1;\n\
    \        return v;\n    }\n    int nxt(int v, char c){\n        if (vs[v][c] !=\
    \ -1) return vs[v][c];\n        if (v == 0) return 0;\n        return nxt(vs[v].link,\
    \ c);\n    }\n    void build(){\n        std::vector<int> que = {0};\n       \
    \ for (int i = 0; i < std::ssize(que); i++){\n            int v = que[i];\n  \
    \          vs[v].link = (v == 0 || vs[v].par == 0 ? 0 : nxt(vs[vs[v].par].link,\
    \ vs[v].c));\n            vs[v].match = vs[v].exist + vs[vs[v].link].match;\n\
    \            for (int cid = 0; cid < sigma; cid++){\n                if (vs[v].ch[cid]\
    \ != -1){\n                    que.emplace_back(vs[v].ch[cid]);\n            \
    \    }\n            }\n        }\n    }\n    node operator[](int v) const {\n\
    \        return vs[v];\n    }\n    size_t size() const {\n        return vs.size();\n\
    \    }\n    int add_leaf(int par, char c){\n        int v = vs.size();\n     \
    \   vs.emplace_back(par, -1, 0, 0, c, leaf);\n        vs[par].ch[c - start] =\
    \ v;\n        return v;\n    }\n};\n\n} // namespace noya2\n#line 5 \"test/string/AhoCorasick.test.cpp\"\
    \n\nint main(){\n    int n; in(n);\n    aho_corasick aho(1e6);\n    vector<int>\
    \ vs(n);\n    rep(i,n){\n        string s; in(s);\n        vs[i] = aho.insert(s);\n\
    \    }\n    aho.build();\n    int sz = aho.size();\n    out(sz);\n    repp(v,1,sz){\n\
    \        out(aho[v].par,aho[v].link);\n    }\n    out(vs);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aho_corasick\"\n\n#include\"\
    ../../template/template.hpp\"\n#include\"../../string/aho_corasick.hpp\"\n\nint\
    \ main(){\n    int n; in(n);\n    aho_corasick aho(1e6);\n    vector<int> vs(n);\n\
    \    rep(i,n){\n        string s; in(s);\n        vs[i] = aho.insert(s);\n   \
    \ }\n    aho.build();\n    int sz = aho.size();\n    out(sz);\n    repp(v,1,sz){\n\
    \        out(aho[v].par,aho[v].link);\n    }\n    out(vs);\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - string/aho_corasick.hpp
  isVerificationFile: true
  path: test/string/AhoCorasick.test.cpp
  requiredBy: []
  timestamp: '2025-09-18 15:41:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/AhoCorasick.test.cpp
layout: document
redirect_from:
- /verify/test/string/AhoCorasick.test.cpp
- /verify/test/string/AhoCorasick.test.cpp.html
title: test/string/AhoCorasick.test.cpp
---
