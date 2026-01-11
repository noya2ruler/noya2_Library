---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.hpp
    title: data_structure/li_chao_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/data_structure/Line_Add_Get_Min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"test/data_structure/Line_Add_Get_Min.test.cpp\"\
    \n\n#line 2 \"data_structure/li_chao_tree.hpp\"\n\n#line 4 \"data_structure/li_chao_tree.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<typename T>\nstruct LiChaoTree {\n    static\
    \ constexpr T ymax = 3e18;\n    struct Line {\n        T a, b;\n        Line (T\
    \ _a = 0, T _b = ymax) : a(_a), b(_b) {}\n        T get(T x){return a * x + b;}\n\
    \    };\n    LiChaoTree (const vector<T> &_xs){\n        xs = _xs;\n        sort(xs.begin(),xs.end());\n\
    \        xs.erase(unique(xs.begin(),xs.end()),xs.end());\n        int _n = xs.size();\n\
    \        n = 1;\n        while (n < _n) n *= 2;\n        xs.resize(n);\n     \
    \   for (int i = _n; i < n; i++) xs[i] = xs[_n-1];\n        seg.resize(n*2-1);\n\
    \    }\n    void line_add(T a, T b){ inner_line_add(Line(a,b),0,0,n);}\n    void\
    \ segment_add(T a, T b, T l, T r){\n        int sl = lower_bound(xs.begin(),xs.end(),l)\
    \ - xs.begin();\n        int sr = lower_bound(xs.begin(),xs.end(),r) - xs.begin();\n\
    \        inner_segment_add(sl,sr,Line(a,b),0,0,n);\n    }\n    T get(T x){\n \
    \       int s = lower_bound(xs.begin(),xs.end(),x) - xs.begin();\n        s +=\
    \ n-1;\n        T res = ymax;\n        res = min(res,seg[s].get(x));\n       \
    \ while (s > 0){\n            s = (s-1) / 2;\n            res = min(res,seg[s].get(x));\n\
    \        }\n        return res;\n    }\n  private:\n    int n;\n    vector<T>\
    \ xs;\n    vector<Line> seg;\n    void inner_line_add(Line L, int i, int l, int\
    \ r){\n        T la = L.get(xs[l]);\n        T lb = seg[i].get(xs[l]);\n     \
    \   T ra = L.get(xs[r-1]);\n        T rb = seg[i].get(xs[r-1]);\n        if (la\
    \ >= lb && ra >= rb) return ;\n        if (la <= lb && ra <= rb) {\n         \
    \   seg[i] = L;\n            return ;\n        }\n        int m = (l + r) / 2;\n\
    \        T ma = L.get(xs[m]);\n        T mb = seg[i].get(xs[m]);\n        if (ma\
    \ < mb){\n            swap(L,seg[i]);\n            swap(la,lb);\n            swap(ra,rb);\n\
    \        }\n        if (la < lb) inner_line_add(L,2*i+1,l,m);\n        if (ra\
    \ < rb) inner_line_add(L,2*i+2,m,r);\n    }\n    void inner_segment_add(int L,\
    \ int R, Line S, int i, int l, int r){\n        if (r <= L || R <= l) return ;\n\
    \        if (L <= l && r <= R) inner_line_add(S,i,l,r);\n        else {\n    \
    \        int m = (l + r) / 2;\n            inner_segment_add(L,R,S,2*i+1,l,m);\n\
    \            inner_segment_add(L,R,S,2*i+2,m,r);\n        }\n    }\n};\n\n} //\
    \ namespace noya2\n#line 6 \"test/data_structure/Line_Add_Get_Min.test.cpp\"\n\
    \nint main(){\n    int n, q; in(n,q);\n    vector<array<ll,3>> querys(n+q);\n\
    \    vector<ll> xs;\n    rep(i,n+q){\n        if (i < n){\n            ll a, b;\
    \ in(a,b);\n            querys[i] = {0,a,b};\n            continue;\n        }\n\
    \        int t; in(t);\n        if (t == 0){\n            ll a, b; in(a,b);\n\
    \            querys[i] = {t,a,b};\n        }\n        else {\n            ll x;\
    \ in(x);\n            querys[i] = {t,x,0};\n            xs.emplace_back(x);\n\
    \        }\n    }\n    LiChaoTree<ll> lct(xs);\n    rep(i,n+q){\n        if (querys[i][0]\
    \ == 0){\n            lct.line_add(querys[i][1],querys[i][2]);\n        }\n  \
    \      else {\n            out(lct.get(querys[i][1]));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include\"template/template.hpp\"\n\n#include\"../../data_structure/li_chao_tree.hpp\"\
    \n\nint main(){\n    int n, q; in(n,q);\n    vector<array<ll,3>> querys(n+q);\n\
    \    vector<ll> xs;\n    rep(i,n+q){\n        if (i < n){\n            ll a, b;\
    \ in(a,b);\n            querys[i] = {0,a,b};\n            continue;\n        }\n\
    \        int t; in(t);\n        if (t == 0){\n            ll a, b; in(a,b);\n\
    \            querys[i] = {t,a,b};\n        }\n        else {\n            ll x;\
    \ in(x);\n            querys[i] = {t,x,0};\n            xs.emplace_back(x);\n\
    \        }\n    }\n    LiChaoTree<ll> lct(xs);\n    rep(i,n+q){\n        if (querys[i][0]\
    \ == 0){\n            lct.line_add(querys[i][1],querys[i][2]);\n        }\n  \
    \      else {\n            out(lct.get(querys[i][1]));\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/li_chao_tree.hpp
  isVerificationFile: true
  path: test/data_structure/Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Line_Add_Get_Min.test.cpp
- /verify/test/data_structure/Line_Add_Get_Min.test.cpp.html
title: test/data_structure/Line_Add_Get_Min.test.cpp
---
