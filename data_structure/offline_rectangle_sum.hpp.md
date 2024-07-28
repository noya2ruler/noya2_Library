---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.hpp
    title: data_structure/binary_indexed_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  - icon: ':heavy_check_mark:'
    path: misc/concepts.hpp
    title: misc/concepts.hpp
  - icon: ':heavy_check_mark:'
    path: misc/monoids.hpp
    title: misc/monoids.hpp
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
    path: test/data_structure/Rectangle_Sum.test.cpp
    title: test/data_structure/Rectangle_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/offline_rectangle_sum.hpp\"\n\n#line 2 \"\
    data_structure/binary_indexed_tree.hpp\"\n\n#line 2 \"template/template.hpp\"\n\
    using namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout_old.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"misc/concepts.hpp\"\n\n#include<concepts>\n\
    \nnamespace noya2 {\n\ntemplate<class monoid>\nconcept Monoid = requires {\n \
    \   typename monoid::value_type;\n    {monoid::op(declval<typename monoid::value_type>(),declval<typename\
    \ monoid::value_type>())} -> std::same_as<typename monoid::value_type>;\n    {monoid::e()}\
    \ -> std::same_as<typename monoid::value_type>;\n};\n\ntemplate<class group>\n\
    concept Group = requires {\n    requires Monoid<group>;\n    {group::inv(declval<typename\
    \ group::value_type>())} -> std::same_as<typename group::value_type>;\n};\n\n\
    } // namespace noya2\n#line 5 \"data_structure/binary_indexed_tree.hpp\"\n\nnamespace\
    \ noya2{\n\ntemplate <Group G>\nstruct binary_indexed_tree {\n    using T = typename\
    \ G::value_type;\n    binary_indexed_tree (int _n = 0) : n(_n), d(_n + 1, G::e())\
    \ {}\n    void add(int i, T val) {\n        for (int x = i+1; x <= n; x += x &\
    \ -x) {\n            d[x] = G::op(d[x],val);\n        }\n    }\n    T prod(int\
    \ r){\n        return prefix_prod(r);\n    }\n    T prod(int l, int r) {\n   \
    \     return G::op(G::inv(prefix_prod(l)),prefix_prod(r));\n    }\n    T get(int\
    \ i){\n        return prod(i,i+1);\n    }\n    void set(int i, T val){\n     \
    \   add(i,G::op(G::inv(get(i)),val));\n    }\n  private:\n    int n;\n    std::vector<T>\
    \ d;\n    T prefix_prod(int i) {\n        assert(0 <= i && i <= n);\n        T\
    \ ret = G::e();\n        for (int x = i; x > 0; x -= x & -x) {\n            ret\
    \ = G::op(ret,d[x]);\n        }\n        return ret;\n    }\n};\n\n} // namespace\
    \ noya2\n#line 2 \"data_structure/csr.hpp\"\n\n#line 4 \"data_structure/csr.hpp\"\
    \n#include<ranges>\n#line 7 \"data_structure/csr.hpp\"\n\nnamespace noya2::internal\
    \ {\n\ntemplate<class E>\nstruct csr {\n    csr () {}\n    csr (int _n) : n(_n)\
    \ {}\n    csr (int _n, int m) : n(_n){\n        start.reserve(m);\n        elist.reserve(m);\n\
    \    }\n    // ACL style constructor (do not have to call build)\n    csr (int\
    \ _n, const std::vector<std::pair<int,E>> &idx_elem) : n(_n), start(_n + 2), elist(idx_elem.size())\
    \ {\n        for (auto &[i, e] : idx_elem){\n            start[i + 2]++;\n   \
    \     }\n        for (int i = 1; i < n; i++){\n            start[i + 2] += start[i\
    \ + 1];\n        }\n        for (auto &[i, e] : idx_elem){\n            elist[start[i\
    \ + 1]++] = e;\n        }\n        prepared = true;\n    }\n    int add(int idx,\
    \ E elem){\n        int eid = start.size();\n        start.emplace_back(idx);\n\
    \        elist.emplace_back(elem);\n        return eid;\n    }\n    void build(){\n\
    \        if (prepared) return ;\n        int m = start.size();\n        std::vector<E>\
    \ nelist(m);\n        std::vector<int> nstart(n + 2, 0);\n        for (int i =\
    \ 0; i < m; i++){\n            nstart[start[i] + 2]++;\n        }\n        for\
    \ (int i = 1; i < n; i++){\n            nstart[i + 2] += nstart[i + 1];\n    \
    \    }\n        for (int i = 0; i < m; i++){\n            nelist[nstart[start[i]\
    \ + 1]++] = elist[i];\n        }\n        swap(elist,nelist);\n        swap(start,nstart);\n\
    \        prepared = true;\n    }\n    const auto operator[](int idx) const {\n\
    \        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    auto operator[](int idx){\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    const auto operator()(int idx, int l, int r) const {\n        return\
    \ std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    auto operator()(int idx, int l, int r){\n        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    int n;\n    std::vector<int> start;\n    std::vector<E> elist;\n \
    \   bool prepared = false;\n};\n\n} // namespace noya2::internal\n#line 2 \"misc/monoids.hpp\"\
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
    \ }\n    static constexpr T inv(const T &a){ return a; }\n};\n    \n} // namespace\
    \ noya2\n#line 6 \"data_structure/offline_rectangle_sum.hpp\"\n\nnamespace noya2\
    \ {\n\ntemplate<Group G = plus_group<ll>>\nstruct offline_rectangle_sum {\n  \
    \  using T = typename G::value_type;\n    int h, w, query_id;\n    internal::csr<pair<int,T>>\
    \ elems;\n    internal::csr<tuple<int,int,int>> queries;\n    offline_rectangle_sum\
    \ () {}\n    offline_rectangle_sum (int h_, int w_) : h(h_), w(w_), query_id(0),\
    \ elems(h_), queries(h_+1) {}\n    offline_rectangle_sum (int h_, int w_, int\
    \ m) : h(h_), w(w_), query_id(0), elems(h_,m), queries(h_+1) {}\n    offline_rectangle_sum\
    \ (int h_, int w_, int m, int q) : h(h_), w(w_), query_id(0), elems(h_,m), queries(h_+1,q*2)\
    \ {}\n    void add_elem(int x, int y, T e){\n        elems.add(x,pair<int,T>(y,e));\n\
    \    }\n    void add_query(int lx, int rx, int ly, int ry){\n        queries.add(lx,tuple<int,int,int>(ly,ry,-1-query_id));\n\
    \        queries.add(rx,tuple<int,int,int>(ly,ry,query_id));\n        query_id++;\n\
    \    }\n    vector<T> run(){\n        elems.build();\n        queries.build();\n\
    \        binary_indexed_tree<G> fen(w);\n        vector<T> ans(query_id,G::e());\n\
    \        for (int x = 0; ; x++){\n            for (auto [ly, ry, qid] : queries[x]){\n\
    \                if (qid >= 0){\n                    ans[qid] = G::op(ans[qid],fen.prod(ly,ry));\n\
    \                }\n                else {\n                    ans[-1-qid] =\
    \ G::op(ans[-1-qid],G::inv(fen.prod(ly,ry)));\n                }\n           \
    \ }\n            if (x == h) break;\n            for (auto [y, e] : elems[x]){\n\
    \                fen.add(y,e);\n            }\n        }\n        return ans;\n\
    \    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../data_structure/binary_indexed_tree.hpp\"\n#include\"\
    ../data_structure/csr.hpp\"\n#include\"../misc/monoids.hpp\"\n\nnamespace noya2\
    \ {\n\ntemplate<Group G = plus_group<ll>>\nstruct offline_rectangle_sum {\n  \
    \  using T = typename G::value_type;\n    int h, w, query_id;\n    internal::csr<pair<int,T>>\
    \ elems;\n    internal::csr<tuple<int,int,int>> queries;\n    offline_rectangle_sum\
    \ () {}\n    offline_rectangle_sum (int h_, int w_) : h(h_), w(w_), query_id(0),\
    \ elems(h_), queries(h_+1) {}\n    offline_rectangle_sum (int h_, int w_, int\
    \ m) : h(h_), w(w_), query_id(0), elems(h_,m), queries(h_+1) {}\n    offline_rectangle_sum\
    \ (int h_, int w_, int m, int q) : h(h_), w(w_), query_id(0), elems(h_,m), queries(h_+1,q*2)\
    \ {}\n    void add_elem(int x, int y, T e){\n        elems.add(x,pair<int,T>(y,e));\n\
    \    }\n    void add_query(int lx, int rx, int ly, int ry){\n        queries.add(lx,tuple<int,int,int>(ly,ry,-1-query_id));\n\
    \        queries.add(rx,tuple<int,int,int>(ly,ry,query_id));\n        query_id++;\n\
    \    }\n    vector<T> run(){\n        elems.build();\n        queries.build();\n\
    \        binary_indexed_tree<G> fen(w);\n        vector<T> ans(query_id,G::e());\n\
    \        for (int x = 0; ; x++){\n            for (auto [ly, ry, qid] : queries[x]){\n\
    \                if (qid >= 0){\n                    ans[qid] = G::op(ans[qid],fen.prod(ly,ry));\n\
    \                }\n                else {\n                    ans[-1-qid] =\
    \ G::op(ans[-1-qid],G::inv(fen.prod(ly,ry)));\n                }\n           \
    \ }\n            if (x == h) break;\n            for (auto [y, e] : elems[x]){\n\
    \                fen.add(y,e);\n            }\n        }\n        return ans;\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn:
  - data_structure/binary_indexed_tree.hpp
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - misc/concepts.hpp
  - data_structure/csr.hpp
  - misc/monoids.hpp
  isVerificationFile: false
  path: data_structure/offline_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2024-07-28 17:05:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Rectangle_Sum.test.cpp
documentation_of: data_structure/offline_rectangle_sum.hpp
layout: document
redirect_from:
- /library/data_structure/offline_rectangle_sum.hpp
- /library/data_structure/offline_rectangle_sum.hpp.html
title: data_structure/offline_rectangle_sum.hpp
---
