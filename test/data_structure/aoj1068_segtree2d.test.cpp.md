---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_2d.hpp
    title: data_structure/segment_tree_2d.hpp
  - icon: ':question:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':question:'
    path: template/inout_old.hpp
    title: template/inout_old.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
  bundledCode: "#line 1 \"test/data_structure/aoj1068_segtree2d.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\n\
    \n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/segment_tree_2d.hpp\"\
    \n\n#line 4 \"data_structure/segment_tree_2d.hpp\"\n\nnamespace noya2{\n\ntemplate<class\
    \ S, S(*op)(S, S), S(*e)()>\nstruct segtree_2d {\n    int h, w;\n    segtree_2d\
    \ (int h_ = 1, int w_ = 0) : segtree_2d(std::vector<std::vector<S>>(h_,vector<S>(w_,e())))\
    \ {}\n    segtree_2d (const std::vector<std::vector<S>> &vec){\n        assert(!vec.empty());\n\
    \        //h = bit_ceil(vec.size()), w = bit_ceil(vec[0].size());\n        h =\
    \ 1; while (h < (int)(vec.size())) h <<= 1; w = 1; while (w < (int)(vec[0].size()))\
    \ w <<= 1;\n        d.assign(h*w*4,e());\n        for (int i = 0; i < (int)(vec.size());\
    \ i++) for (int j = 0; j < (int)(vec[i].size()); j++) d[id(i+h,j+w)] = vec[i][j];\n\
    \        build();\n    }\n    void build(){\n        for (int i = 0; i < h; i++)\
    \ for (int j = w-1; j > 0; j--) update_y(i+h,j);\n        for (int i = h-1; i\
    \ > 0; i--) for (int j = 1; j < 2*w; j++) update_x(i,j);\n    }\n    void assign(int\
    \ p, int q, S v){\n        d[id(p+h,q+w)] = v;\n    }\n    void set(int p, int\
    \ q, S v){\n        p += h, q += w;\n        d[id(p,q)] = v;\n        for (int\
    \ j = q>>1; j > 0; j >>= 1) update_y(p,j);\n        for ( ; q > 0; q >>= 1) for\
    \ (int i = p>>1; i > 0; i >>= 1) update_x(i,q);\n    }\n    S prod(int lp, int\
    \ rp, int lq, int rq){\n        if (lp >= rp || lq >= rq) return e();\n      \
    \  S res = e();\n        lp += h, rp += h, lq += w, rq += w;\n        for ( ;\
    \ lp < rp; lp >>= 1, rp >>= 1){\n            if (lp & 1) res = op(res,inner_prod(lp++,lq,rq));\n\
    \            if (rp & 1) res = op(res,inner_prod(--rp,lq,rq));\n        }\n  \
    \      return res;\n    }\n    S get(int p, int q){\n        p += h, q += w;\n\
    \        return d[id(p,q)];\n    }\n    int id(int p, int q){ return p * 2 * w\
    \ + q; }\n    void update_x(int p, int q){ d[id(p,q)] = op(d[id(2*p,q)],d[id(2*p+1,q)]);\
    \ }\n    void update_y(int p, int q){ d[id(p,q)] = op(d[id(p,2*q)],d[id(p,2*q+1)]);\
    \ }\n    S inner_prod(int p, int lq, int rq){\n        S res = e();\n        for\
    \ ( ; lq < rq; lq >>= 1, rq >>= 1){\n            if (lq & 1) res = op(res,d[id(p,lq++)]);\n\
    \            if (rq & 1) res = op(res,d[id(p,--rq)]);\n        }\n        return\
    \ res;\n    }\n    std::vector<S> d;\n};\n\n} // namespace noya2\n#line 5 \"test/data_structure/aoj1068_segtree2d.test.cpp\"\
    \n\nint op(int a, int b){\n    return min(a,b);\n}\nint e(){\n    return numeric_limits<int>::max();\n\
    }\n\nvoid solve(int h, int w, int q){\n    vector<vector<int>> a(h,vector<int>(w));\
    \ in(a);\n    segtree_2d<int,op,e> seg(a);\n    while (q--){\n        int lx,\
    \ rx, ly, ry; in(lx,ly,rx,ry); rx++, ry++;\n        out(seg.prod(lx,rx,ly,ry));\n\
    \    }\n}\n\nint main(){\n    while(true){\n        int h, w, q; in(h,w,q);\n\
    \        if (h == 0) break;\n        solve(h,w,q);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../data_structure/segment_tree_2d.hpp\"\
    \n\nint op(int a, int b){\n    return min(a,b);\n}\nint e(){\n    return numeric_limits<int>::max();\n\
    }\n\nvoid solve(int h, int w, int q){\n    vector<vector<int>> a(h,vector<int>(w));\
    \ in(a);\n    segtree_2d<int,op,e> seg(a);\n    while (q--){\n        int lx,\
    \ rx, ly, ry; in(lx,ly,rx,ry); rx++, ry++;\n        out(seg.prod(lx,rx,ly,ry));\n\
    \    }\n}\n\nint main(){\n    while(true){\n        int h, w, q; in(h,w,q);\n\
    \        if (h == 0) break;\n        solve(h,w,q);\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/segment_tree_2d.hpp
  isVerificationFile: true
  path: test/data_structure/aoj1068_segtree2d.test.cpp
  requiredBy: []
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/aoj1068_segtree2d.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/aoj1068_segtree2d.test.cpp
- /verify/test/data_structure/aoj1068_segtree2d.test.cpp.html
title: test/data_structure/aoj1068_segtree2d.test.cpp
---
