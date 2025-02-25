---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.hpp
    title: data_structure/binary_indexed_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_tree.hpp
    title: data_structure/range_tree.hpp
  - icon: ':heavy_check_mark:'
    path: misc/concepts.hpp
    title: misc/concepts.hpp
  - icon: ':heavy_check_mark:'
    path: misc/monoids.hpp
    title: misc/monoids.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/data_structure/Point_Add_Rectangle_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/range_tree.hpp\"\
    \n\n#line 2 \"data_structure/compress.hpp\"\n\n#line 5 \"data_structure/compress.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<typename T>\nstruct compress {\n    std::vector<T>\
    \ raws;\n    compress () {}\n    compress (const vector<T> &_raws) : raws(_raws){\
    \ build(); }\n    void build(){\n        std::sort(raws.begin(), raws.end());\n\
    \        raws.erase(std::unique(raws.begin(), raws.end()), raws.end());\n    }\n\
    \    int id(const T &raw){ return lb(raw); }\n    T raw(const int &id){ return\
    \ raws[id]; }\n    void add(const T &raw){ raws.emplace_back(raw); }\n    void\
    \ reserve(size_t sz){ raws.reserve(sz); }\n    size_t size(){ return raws.size();\
    \ }\n    int lb(const T &raw){ return lower_bound(all(raws),raw) - raws.begin();\
    \ }\n    int ub(const T &raw){ return upper_bound(all(raws),raw) - raws.begin();\
    \ }\n    bool contains(const T &raw){\n        int jd = lb(raw);\n        if (jd\
    \ < (int)size()) return raws[jd] == raw;\n        return false;\n    }\n    int\
    \ contains_id(const T &raw){\n        int jd = lb(raw);\n        if (jd < (int)size()\
    \ && raws[jd] == raw) return jd;\n        return -1;\n    }\n};\n\n} // namespace\
    \ noya2\n#line 5 \"data_structure/range_tree.hpp\"\n\nnamespace noya2 {\n\ntemplate<class\
    \ M, template<class MM> class data_structure, typename Idx = ll>\nstruct range_tree\
    \ {\n    using DS = data_structure<M>;\n    using T = typename M::value_type;\n\
    \    void join(Idx x, Idx y){ ps.emplace_back(x,y); }\n    void build(){\n   \
    \     for (auto &[x, y] : ps) xs.add(x);\n        xs.build();\n        //siz =\
    \ bit_ceil(xs.size());\n        siz = 1; while (siz < (int)(xs.size())) siz <<=\
    \ 1;\n        ys.resize(siz*2);\n        for (auto &[x, y] : ps){\n          \
    \  int xid = xs.id(x) + siz;\n            ys[xid].add(y);\n            while (xid\
    \ > 1){\n                xid >>= 1;\n                ys[xid].add(y);\n       \
    \     }\n        }\n        for (int i = 0; i < 2*siz; i++){\n            ys[i].build();\n\
    \            ds.emplace_back(ys[i].size());\n        }\n    }\n    void set(Idx\
    \ p, Idx q, T val){\n        int i = xs.id(p) + siz;\n        ds[i].set(ys[i].id(q),val);\n\
    \        while (i > 1){\n            i >>= 1;\n            T lr = M::e();\n  \
    \          int i0 = ys[2*i+0].contains_id(q), i1 = ys[2*i+1].contains_id(q);\n\
    \            if (i0 != -1) lr = M::op(lr, ds[2*i+0].get(i0));\n            if\
    \ (i1 != -1) lr = M::op(lr, ds[2*i+1].get(i1));\n            ds[i].set(ys[i].id(q),lr);\n\
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
    };\n\n} // namespace noya2\n#line 2 \"data_structure/binary_indexed_tree.hpp\"\
    \n\n#line 2 \"misc/concepts.hpp\"\n\n#include<concepts>\n\nnamespace noya2 {\n\
    \ntemplate<class monoid>\nconcept Monoid = requires {\n    typename monoid::value_type;\n\
    \    {monoid::op(declval<typename monoid::value_type>(),declval<typename monoid::value_type>())}\
    \ -> std::same_as<typename monoid::value_type>;\n    {monoid::e()} -> std::same_as<typename\
    \ monoid::value_type>;\n};\n\ntemplate<class group>\nconcept Group = requires\
    \ {\n    requires Monoid<group>;\n    {group::inv(declval<typename group::value_type>())}\
    \ -> std::same_as<typename group::value_type>;\n};\n\n} // namespace noya2\n#line\
    \ 5 \"data_structure/binary_indexed_tree.hpp\"\n\nnamespace noya2{\n\ntemplate\
    \ <Group G>\nstruct binary_indexed_tree {\n    using T = typename G::value_type;\n\
    \    binary_indexed_tree (int _n = 0) : n(_n), d(_n + 1, G::e()) {}\n    void\
    \ add(int i, T val) {\n        for (int x = i+1; x <= n; x += x & -x) {\n    \
    \        d[x] = G::op(d[x],val);\n        }\n    }\n    T prod(int r){\n     \
    \   return prefix_prod(r);\n    }\n    T prod(int l, int r) {\n        return\
    \ G::op(G::inv(prefix_prod(l)),prefix_prod(r));\n    }\n    T get(int i){\n  \
    \      return prod(i,i+1);\n    }\n    void set(int i, T val){\n        add(i,G::op(G::inv(get(i)),val));\n\
    \    }\n  private:\n    int n;\n    std::vector<T> d;\n    T prefix_prod(int i)\
    \ {\n        assert(0 <= i && i <= n);\n        T ret = G::e();\n        for (int\
    \ x = i; x > 0; x -= x & -x) {\n            ret = G::op(ret,d[x]);\n        }\n\
    \        return ret;\n    }\n};\n\n} // namespace noya2\n#line 2 \"misc/monoids.hpp\"\
    \n\n#line 4 \"misc/monoids.hpp\"\n\nnamespace noya2{\n\ntemplate<typename T>\n\
    struct max_monoid {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return max(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::min();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct min_monoid {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return min(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::max();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct plus_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a + b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return -a; }\n};\ntemplate<typename\
    \ T>\nstruct xor_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a ^ b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return a; }\n};\n\ntemplate<class\
    \ S, auto _op, auto _e>\nstruct monoid {\n    using value_type = S;\n    static\
    \ constexpr value_type op(value_type a, value_type b){\n        return _op(a,\
    \ b);\n    }\n    static constexpr value_type e(){\n        return _e();\n   \
    \ }\n};\n  \n} // namespace noya2\n#line 7 \"test/data_structure/Point_Add_Rectangle_Sum.test.cpp\"\
    \n\nint main(){\n    int n, q; in(n,q);\n    vector<array<int,5>> queries(n+q);\n\
    \    range_tree<plus_group<ll>,binary_indexed_tree,int> rt;\n    rep(i,n+q){\n\
    \        if (i < n){\n            int x, y, w; in(x,y,w);\n            queries[i]\
    \ = {0,x,y,w,0};\n            rt.join(x,y);\n            continue;\n        }\n\
    \        int t; in(t);\n        if (t == 0){\n            int x, y, w; in(x,y,w);\n\
    \            queries[i] = {t,x,y,w,0};\n            rt.join(x,y);\n        }\n\
    \        if (t == 1){\n            int l, d, r, u; in(l,d,r,u);\n            queries[i]\
    \ = {t,l,d,r,u};\n        }\n    }\n    rt.build();\n    rep(i,n+q){\n       \
    \ if (queries[i][0] == 0){\n            auto [t, x, y, w, o] = queries[i];\n \
    \           rt.set(x,y,rt.get(x,y)+w);\n        }\n        if (queries[i][0] ==\
    \ 1){\n            auto [t, l, d, r, u] = queries[i];\n            out(rt.prod(l,r,d,u));\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../data_structure/range_tree.hpp\"\
    \n#include\"../../data_structure/binary_indexed_tree.hpp\"\n#include\"../../misc/monoids.hpp\"\
    \n\nint main(){\n    int n, q; in(n,q);\n    vector<array<int,5>> queries(n+q);\n\
    \    range_tree<plus_group<ll>,binary_indexed_tree,int> rt;\n    rep(i,n+q){\n\
    \        if (i < n){\n            int x, y, w; in(x,y,w);\n            queries[i]\
    \ = {0,x,y,w,0};\n            rt.join(x,y);\n            continue;\n        }\n\
    \        int t; in(t);\n        if (t == 0){\n            int x, y, w; in(x,y,w);\n\
    \            queries[i] = {t,x,y,w,0};\n            rt.join(x,y);\n        }\n\
    \        if (t == 1){\n            int l, d, r, u; in(l,d,r,u);\n            queries[i]\
    \ = {t,l,d,r,u};\n        }\n    }\n    rt.build();\n    rep(i,n+q){\n       \
    \ if (queries[i][0] == 0){\n            auto [t, x, y, w, o] = queries[i];\n \
    \           rt.set(x,y,rt.get(x,y)+w);\n        }\n        if (queries[i][0] ==\
    \ 1){\n            auto [t, l, d, r, u] = queries[i];\n            out(rt.prod(l,r,d,u));\n\
    \        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/range_tree.hpp
  - data_structure/compress.hpp
  - data_structure/binary_indexed_tree.hpp
  - misc/concepts.hpp
  - misc/monoids.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  requiredBy: []
  timestamp: '2025-02-22 20:23:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Add_Rectangle_Sum.test.cpp
- /verify/test/data_structure/Point_Add_Rectangle_Sum.test.cpp.html
title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
---
