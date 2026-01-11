---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  - icon: ':heavy_check_mark:'
    path: misc/static_range_mode_query.hpp
    title: misc/static_range_mode_query.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_mode_query
    links:
    - https://judge.yosupo.jp/problem/static_range_mode_query
  bundledCode: "#line 1 \"test/misc/StaticRangeModeQuery.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_mode_query\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"misc/static_range_mode_query.hpp\"\
    \n\n#line 6 \"misc/static_range_mode_query.hpp\"\n\nnamespace noya2 {\n\nstruct\
    \ static_range_mode_query {\n    const int w = 320;\n    std::vector<int> a;\n\
    \    std::vector<std::vector<int>> ids;\n    std::vector<std::vector<std::pair<int,int>>>\
    \ pre;\n    std::vector<int> pos;\n    std::vector<int> buf;\n    // a[i] in [0,\
    \ n), n = a.size()\n    static_range_mode_query (const std::vector<int> _a) :\
    \ a(_a), ids(_a.size()) {\n        int n = a.size(), sz = n / w;\n        pos.resize(n);\n\
    \        ids.resize(n);\n        for (int i = 0; i < n; i++){\n            assert(0\
    \ <= a[i] && a[i] < n);\n            pos[i] = ids[a[i]].size();\n            ids[a[i]].emplace_back(i);\n\
    \        }\n        pre.resize((sz+1),std::vector<std::pair<int,int>>(sz+1));\n\
    \        for (int l = 0; l < sz; l++){\n            std::vector<int> cnt(n,0);\n\
    \            int ma = -1, id = -1;\n            for (int r = l+1; r <= sz; r++){\n\
    \                for (int i = (r-1)*w; i < r*w; i++){\n                    if\
    \ (++cnt[a[i]] > ma){\n                        ma = cnt[a[i]];\n             \
    \           id = a[i];\n                    }\n                }\n           \
    \     pre[l][r] = {id, ma};\n            }\n        }\n        buf.resize(n, 0);\n\
    \    }\n    std::pair<int,int> prod_naive(int l, int r){\n        int ma = -1,\
    \ id = -1;\n        for (int i = l; i < r; i++){\n            if (++buf[a[i]]\
    \ > ma){\n                ma = buf[a[i]];\n                id = a[i];\n      \
    \      }\n        }\n        for (int i = l; i < r; i++){\n            --buf[a[i]];\n\
    \        }\n        return {id, ma};\n    }\n    std::pair<int,int> prod(int l,\
    \ int r){\n        assert(0 <= l && l < r && r <= (int)(a.size()));\n        //\
    \ li = ceil(l / w), ri = floor(r / w)\n        int li = (l + w - 1) / w, ri =\
    \ r / w;\n        if (li >= ri){\n            return prod_naive(l, r);\n     \
    \   }\n        auto [id, ma] = pre[li][ri];\n        for (int i = l; i < li*w;\
    \ i++){\n            int p = pos[i] + ma;\n            if (p >= (int)(ids[a[i]].size()))\
    \ continue;\n            if (ids[a[i]][p] < r){\n                ma++;\n     \
    \           id = a[i];\n                i--;\n            }\n        }\n     \
    \   for (int i = ri*w; i < r; i++){\n            int p = pos[i] - ma;\n      \
    \      if (p < 0) continue;\n            if (ids[a[i]][p] >= l){\n           \
    \     ma++;\n                id = a[i];\n                i--;\n            }\n\
    \        }\n        return {id, ma};\n    }\n};\n\n} // namespace noya2\n#line\
    \ 2 \"data_structure/compress.hpp\"\n\n#line 5 \"data_structure/compress.hpp\"\
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
    \ noya2\n#line 6 \"test/misc/StaticRangeModeQuery.test.cpp\"\n\nint main(){\n\
    \    int n, q; in(n,q);\n    vector<int> a(n); in(a);\n    compress<int> cp(a);\n\
    \    rep(i,n){\n        a[i] = cp.id(a[i]);\n    }\n    static_range_mode_query\
    \ srmq(a);\n    while (q--){\n        int l, r; in(l,r);\n        auto [id, ma]\
    \ = srmq.prod(l,r);\n        id = cp.raw(id);\n        out(id,ma);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../misc/static_range_mode_query.hpp\"\
    \n#include\"../../data_structure/compress.hpp\"\n\nint main(){\n    int n, q;\
    \ in(n,q);\n    vector<int> a(n); in(a);\n    compress<int> cp(a);\n    rep(i,n){\n\
    \        a[i] = cp.id(a[i]);\n    }\n    static_range_mode_query srmq(a);\n  \
    \  while (q--){\n        int l, r; in(l,r);\n        auto [id, ma] = srmq.prod(l,r);\n\
    \        id = cp.raw(id);\n        out(id,ma);\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - misc/static_range_mode_query.hpp
  - data_structure/compress.hpp
  isVerificationFile: true
  path: test/misc/StaticRangeModeQuery.test.cpp
  requiredBy: []
  timestamp: '2024-09-20 13:54:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/StaticRangeModeQuery.test.cpp
layout: document
redirect_from:
- /verify/test/misc/StaticRangeModeQuery.test.cpp
- /verify/test/misc/StaticRangeModeQuery.test.cpp.html
title: test/misc/StaticRangeModeQuery.test.cpp
---
