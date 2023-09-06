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
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/data_structure/Static_Range_Inversions_Query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#line 4 \"data_structure/compress.hpp\"\n\nnamespace noya2{\n\ntemplate<typename\
    \ T> struct compress {\n    vector<T> raws;\n    compress(const vector<T> &raws_\
    \ = {}) : raws(raws_){ build(); }\n    int id(const T &raw){ return lb(raw); }\n\
    \    T raw(const int &id){ return raws[id]; }\n    void build(){ uniq(raws); }\n\
    \    void add(const T &raw){ raws.push_back(raw); }\n    size_t size(){ return\
    \ raws.size(); }\n    int lb(const T &raw){ return lower_bound(all(raws),raw)\
    \ - raws.begin(); }\n    int ub(const T &raw){ return upper_bound(all(raws),raw)\
    \ - raws.begin(); }\n    bool contains(const T &raw){\n        int jd = lb(raw);\n\
    \        if (jd < (int)size()) return raws[jd] == raw;\n        return false;\n\
    \    }\n    int contains_id(const T &raw){\n        int jd = lb(raw);\n      \
    \  if (jd < (int)size() && raws[jd] == raw) return jd;\n        return -1;\n \
    \   }\n};\n\n} // namespace noya2\n#line 2 \"data_structure/binary_indexed_tree.hpp\"\
    \n\n#line 2 \"misc/monoids.hpp\"\n\n#line 4 \"misc/monoids.hpp\"\n\nnamespace\
    \ noya2{\n\ntemplate<typename T>\nstruct Max_monoid {\n    using value_type =\
    \ T;\n    static constexpr T op(const T &a, const T &b){ return max(a,b); }\n\
    \    static constexpr T e(){ return std::numeric_limits<T>::min(); }\n    static\
    \ constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename T>\nstruct\
    \ Min_monoid {\n    using value_type = T;\n    static constexpr T op(const T &a,\
    \ const T &b){ return min(a,b); }\n    static constexpr T e(){ return std::numeric_limits<T>::max();\
    \ }\n    static constexpr T inv(const T &a){ return e(); }\n};\ntemplate<typename\
    \ T>\nstruct Plus_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a + b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return -a; }\n};\ntemplate<typename\
    \ T>\nstruct Xor_group {\n    using value_type = T;\n    static constexpr T op(const\
    \ T &a, const T &b){ return a ^ b; }\n    static constexpr T e(){ return T(0);\
    \ }\n    static constexpr T inv(const T &a){ return a; }\n};\n    \n} // namespace\
    \ noya2\n#line 5 \"data_structure/binary_indexed_tree.hpp\"\n\nnamespace noya2{\n\
    \ntemplate <class G> struct BinaryIndexedTree {\n    using T = typename G::value_type;\n\
    \    BinaryIndexedTree(int n_ = 0) : n(n_), d(std::vector<T>(n_ + 1, G::e()))\
    \ {}\n    void add(int i, T val) {\n        for (int x = i+1; x <= n; x += x &\
    \ -x) {\n            d[x] = G::op(d[x],val);\n        }\n    }\n    T prod(int\
    \ l, int r = -1) {\n        if (r == -1) return prefix_prod(l);\n        return\
    \ G::op(G::inv(prefix_prod(l)),prefix_prod(r));\n    }\n    T get(int i){\n  \
    \      return prod(i,i+1);\n    }\n    void set(int i, T val){\n        add(i,G::op(G::inv(get(i)),val));\n\
    \    }\n  private:\n    int n;\n    std::vector<T> d;\n    T prefix_prod(int i)\
    \ {\n        assert(0 <= i && i <= n);\n        T ret = G::e();\n        for (int\
    \ x = i; x > 0; x -= x & -x) {\n            ret = G::op(ret,d[x]);\n        }\n\
    \        return ret;\n    }\n};\ntemplate<typename T> using BIT_Plus = BinaryIndexedTree<Plus_group<T>>;\n\
    template<typename T> using BIT_Xor = BinaryIndexedTree<Xor_group<T>>;\n\n} //\
    \ namespace noya2\n#line 2 \"misc/mo_algorithm.hpp\"\n\n/*\n\nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
    \n*/\n\n#line 10 \"misc/mo_algorithm.hpp\"\n\nnamespace noya2{\n\nstruct Mo {\n\
    \    int width;\n    std::vector<int> left, right, order;\n\n    Mo(int N = 1,\
    \ int Q = 1): order(Q) {\n        width = std::max<int>(1, 1.0 * N / std::max<double>(1.0,\
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
    \            rem(idx);\n        }\n    }\n};\n\n}\n#line 7 \"test/data_structure/Static_Range_Inversions_Query.test.cpp\"\
    \n\nint main(){\n    int n, q; in(n,q);\n    vector<int> a(n); in(a);\n    compress<int>\
    \ cp(a);\n    rep(i,n) a[i] = cp.id(a[i]);\n    Mo mo(n,q);\n    rep(i,q){\n \
    \       int l, r; in(l,r);\n        mo.insert(l,r);\n    }\n    BIT_Plus<ll> bit(n);\n\
    \    ll cur = 0;\n    auto addl = [&](int i){\n        cur += bit.prod(0,a[i]);\n\
    \        bit.add(a[i],1);\n    };\n    auto addr = [&](int i){\n        cur +=\
    \ bit.prod(a[i]+1,n);\n        bit.add(a[i],1);\n    };\n    auto dell = [&](int\
    \ i){\n        cur -= bit.prod(0,a[i]);\n        bit.add(a[i],-1);\n    };\n \
    \   auto delr = [&](int i){\n        cur -= bit.prod(a[i]+1,n);\n        bit.add(a[i],-1);\n\
    \    };\n    vector<ll> ans(q,0);\n    auto ask = [&](int i){\n        ans[i]\
    \ = cur;\n    };\n    mo.run(addl,addr,dell,delr,ask);\n    rep(i,q) out(ans[i]);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../data_structure/compress.hpp\"\
    \n#include\"../../data_structure/binary_indexed_tree.hpp\"\n#include\"../../misc/mo_algorithm.hpp\"\
    \n\nint main(){\n    int n, q; in(n,q);\n    vector<int> a(n); in(a);\n    compress<int>\
    \ cp(a);\n    rep(i,n) a[i] = cp.id(a[i]);\n    Mo mo(n,q);\n    rep(i,q){\n \
    \       int l, r; in(l,r);\n        mo.insert(l,r);\n    }\n    BIT_Plus<ll> bit(n);\n\
    \    ll cur = 0;\n    auto addl = [&](int i){\n        cur += bit.prod(0,a[i]);\n\
    \        bit.add(a[i],1);\n    };\n    auto addr = [&](int i){\n        cur +=\
    \ bit.prod(a[i]+1,n);\n        bit.add(a[i],1);\n    };\n    auto dell = [&](int\
    \ i){\n        cur -= bit.prod(0,a[i]);\n        bit.add(a[i],-1);\n    };\n \
    \   auto delr = [&](int i){\n        cur -= bit.prod(a[i]+1,n);\n        bit.add(a[i],-1);\n\
    \    };\n    vector<ll> ans(q,0);\n    auto ask = [&](int i){\n        ans[i]\
    \ = cur;\n    };\n    mo.run(addl,addr,dell,delr,ask);\n    rep(i,q) out(ans[i]);\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/compress.hpp
  - data_structure/binary_indexed_tree.hpp
  - misc/monoids.hpp
  - misc/mo_algorithm.hpp
  isVerificationFile: true
  path: test/data_structure/Static_Range_Inversions_Query.test.cpp
  requiredBy: []
  timestamp: '2023-09-01 21:00:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Static_Range_Inversions_Query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Static_Range_Inversions_Query.test.cpp
- /verify/test/data_structure/Static_Range_Inversions_Query.test.cpp.html
title: test/data_structure/Static_Range_Inversions_Query.test.cpp
---
