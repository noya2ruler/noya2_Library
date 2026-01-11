---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
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
    path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
    title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/range_tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#line 5 \"data_structure/compress.hpp\"\n\nnamespace noya2{\n\ntemplate<typename\
    \ T>\nstruct compress {\n    std::vector<T> raws;\n    compress () {}\n    compress\
    \ (const vector<T> &_raws) : raws(_raws){ build(); }\n    void build(){\n    \
    \    std::sort(raws.begin(), raws.end());\n        raws.erase(std::unique(raws.begin(),\
    \ raws.end()), raws.end());\n    }\n    int id(const T &raw){ return lb(raw);\
    \ }\n    T raw(const int &id){ return raws[id]; }\n    void add(const T &raw){\
    \ raws.emplace_back(raw); }\n    void reserve(size_t sz){ raws.reserve(sz); }\n\
    \    size_t size(){ return raws.size(); }\n    int lb(const T &raw){ return lower_bound(all(raws),raw)\
    \ - raws.begin(); }\n    int ub(const T &raw){ return upper_bound(all(raws),raw)\
    \ - raws.begin(); }\n    bool contains(const T &raw){\n        int jd = lb(raw);\n\
    \        if (jd < (int)size()) return raws[jd] == raw;\n        return false;\n\
    \    }\n    int contains_id(const T &raw){\n        int jd = lb(raw);\n      \
    \  if (jd < (int)size() && raws[jd] == raw) return jd;\n        return -1;\n \
    \   }\n};\n\n} // namespace noya2\n#line 5 \"data_structure/range_tree.hpp\"\n\
    \nnamespace noya2 {\n\ntemplate<class M, template<class MM> class data_structure,\
    \ typename Idx = ll>\nstruct range_tree {\n    using DS = data_structure<M>;\n\
    \    using T = typename M::value_type;\n    void join(Idx x, Idx y){ ps.emplace_back(x,y);\
    \ }\n    void build(){\n        for (auto &[x, y] : ps) xs.add(x);\n        xs.build();\n\
    \        //siz = bit_ceil(xs.size());\n        siz = 1; while (siz < (int)(xs.size()))\
    \ siz <<= 1;\n        ys.resize(siz*2);\n        for (auto &[x, y] : ps){\n  \
    \          int xid = xs.id(x) + siz;\n            ys[xid].add(y);\n          \
    \  while (xid > 1){\n                xid >>= 1;\n                ys[xid].add(y);\n\
    \            }\n        }\n        for (int i = 0; i < 2*siz; i++){\n        \
    \    ys[i].build();\n            ds.emplace_back(ys[i].size());\n        }\n \
    \   }\n    void set(Idx p, Idx q, T val){\n        int i = xs.id(p) + siz;\n \
    \       ds[i].set(ys[i].id(q),val);\n        while (i > 1){\n            i >>=\
    \ 1;\n            T lr = M::e();\n            int i0 = ys[2*i+0].contains_id(q),\
    \ i1 = ys[2*i+1].contains_id(q);\n            if (i0 != -1) lr = M::op(lr, ds[2*i+0].get(i0));\n\
    \            if (i1 != -1) lr = M::op(lr, ds[2*i+1].get(i1));\n            ds[i].set(ys[i].id(q),lr);\n\
    \        }\n    }\n    T get(Idx p, Idx q){\n        int ip = xs.contains_id(p);\n\
    \        if (ip == -1) return M::e();\n        int i = ip + siz;\n        int\
    \ iq = ys[i].contains_id(q);\n        if (iq == -1) return M::e();\n        return\
    \ ds[i].get(iq);\n    }\n    T prod(Idx lp, Idx rp, Idx lq, Idx rq){\n       \
    \ T res = M::e();\n        int li = xs.lb(lp), ri = xs.lb(rp);\n        for (li\
    \ += siz, ri += siz; li < ri; li >>= 1, ri >>= 1){\n            if (li & 1) res\
    \ = M::op(res,ds[li].prod(ys[li].lb(lq),ys[li].lb(rq))), ++li;\n            if\
    \ (ri & 1) --ri, res = M::op(res,ds[ri].prod(ys[ri].lb(lq),ys[ri].lb(rq)));\n\
    \        }\n        return res;\n    }\n    int siz;\n    vector<pair<Idx,Idx>>\
    \ ps;\n    compress<Idx> xs;\n    vector<compress<Idx>> ys;\n    vector<DS> ds;\n\
    };\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../data_structure/compress.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<class M, template<class MM> class data_structure,\
    \ typename Idx = ll>\nstruct range_tree {\n    using DS = data_structure<M>;\n\
    \    using T = typename M::value_type;\n    void join(Idx x, Idx y){ ps.emplace_back(x,y);\
    \ }\n    void build(){\n        for (auto &[x, y] : ps) xs.add(x);\n        xs.build();\n\
    \        //siz = bit_ceil(xs.size());\n        siz = 1; while (siz < (int)(xs.size()))\
    \ siz <<= 1;\n        ys.resize(siz*2);\n        for (auto &[x, y] : ps){\n  \
    \          int xid = xs.id(x) + siz;\n            ys[xid].add(y);\n          \
    \  while (xid > 1){\n                xid >>= 1;\n                ys[xid].add(y);\n\
    \            }\n        }\n        for (int i = 0; i < 2*siz; i++){\n        \
    \    ys[i].build();\n            ds.emplace_back(ys[i].size());\n        }\n \
    \   }\n    void set(Idx p, Idx q, T val){\n        int i = xs.id(p) + siz;\n \
    \       ds[i].set(ys[i].id(q),val);\n        while (i > 1){\n            i >>=\
    \ 1;\n            T lr = M::e();\n            int i0 = ys[2*i+0].contains_id(q),\
    \ i1 = ys[2*i+1].contains_id(q);\n            if (i0 != -1) lr = M::op(lr, ds[2*i+0].get(i0));\n\
    \            if (i1 != -1) lr = M::op(lr, ds[2*i+1].get(i1));\n            ds[i].set(ys[i].id(q),lr);\n\
    \        }\n    }\n    T get(Idx p, Idx q){\n        int ip = xs.contains_id(p);\n\
    \        if (ip == -1) return M::e();\n        int i = ip + siz;\n        int\
    \ iq = ys[i].contains_id(q);\n        if (iq == -1) return M::e();\n        return\
    \ ds[i].get(iq);\n    }\n    T prod(Idx lp, Idx rp, Idx lq, Idx rq){\n       \
    \ T res = M::e();\n        int li = xs.lb(lp), ri = xs.lb(rp);\n        for (li\
    \ += siz, ri += siz; li < ri; li >>= 1, ri >>= 1){\n            if (li & 1) res\
    \ = M::op(res,ds[li].prod(ys[li].lb(lq),ys[li].lb(rq))), ++li;\n            if\
    \ (ri & 1) --ri, res = M::op(res,ds[ri].prod(ys[ri].lb(lq),ys[ri].lb(rq)));\n\
    \        }\n        return res;\n    }\n    int siz;\n    vector<pair<Idx,Idx>>\
    \ ps;\n    compress<Idx> xs;\n    vector<compress<Idx>> ys;\n    vector<DS> ds;\n\
    };\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/compress.hpp
  isVerificationFile: false
  path: data_structure/range_tree.hpp
  requiredBy: []
  timestamp: '2024-07-28 17:15:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
documentation_of: data_structure/range_tree.hpp
layout: document
redirect_from:
- /library/data_structure/range_tree.hpp
- /library/data_structure/range_tree.hpp.html
title: data_structure/range_tree.hpp
---
