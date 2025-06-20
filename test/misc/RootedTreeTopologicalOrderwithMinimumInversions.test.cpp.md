---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/O1onTree.hpp
    title: misc/O1onTree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions
  bundledCode: "#line 1 \"test/misc/RootedTreeTopologicalOrderwithMinimumInversions.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"misc/O1onTree.hpp\"\n\n#line\
    \ 6 \"misc/O1onTree.hpp\"\n#include <bit>\n#include <concepts>\n\nnamespace noya2\
    \ {\n\n// root is vertex 0, par[i] < i\n// bool comp(int u, int v), comp(u, v)\
    \ ? [u, ...] < [v, ...] : [u, ...] >= [v, ...]\n// void merge(int u, int v), [p,\
    \ ...] ++ [v, ...]  -- merge(p, v) -->  [p, ......]\ntemplate<bool get_order =\
    \ true>\nstd::conditional_t<get_order, std::vector<int>, void> O1onTree(int n,\
    \ const std::vector<int> &par, auto comp, auto merge){\n    if (n == 1){\n   \
    \     if constexpr (get_order){\n            return {0};\n        }\n        else\
    \ {\n            return ;\n        }\n    }\n    assert(ssize(par) == n);\n  \
    \  for (int i = 0; i < n; i++){\n        assert(par[i] < i);\n    }\n    // dsu\
    \ without weighted union heuristic\n    std::vector<int> uf(n, -1);\n    // leader\
    \ is the highest vertex among the connected component\n    auto leader = [&](int\
    \ a){\n        auto dfs = [&](auto sfs, int v){\n            if (uf[v] < 0) return\
    \ v;\n            return uf[v] = sfs(sfs,uf[v]);\n        };\n        return dfs(dfs,a);\n\
    \    };\n    // updatable priority_queue using segtree\n    int sz = std::bit_ceil<uint32_t>(n);\n\
    \    std::vector<int> seg(sz);\n    std::vector<bool> done(sz, true);\n    auto\
    \ op = [&](int a, int b){\n        if (done[b]) return a;\n        if (done[a])\
    \ return b;\n        return comp(a, b) ? a : b;\n    };\n    // definition of\
    \ op is updated\n    auto update = [&](int i){\n        i += sz;\n        i >>=\
    \ 1;\n        // segtree leaf i always contains i\n        seg[i] = op(i * 2 -\
    \ sz, i * 2 + 1 - sz);\n        while (i > 1){\n            i >>= 1;\n       \
    \     seg[i] = op(seg[i * 2], seg[i * 2 + 1]);\n        }\n    };\n    for (int\
    \ i = 1; i < n; i++){\n        done[i] = false;\n    }\n    for (int i = sz -\
    \ 1; i >= sz / 2; i--){\n        seg[i] = op(i * 2 - sz, i * 2 + 1 - sz);\n  \
    \  }\n    for (int i = sz / 2 - 1; i >= 1; i--){\n        seg[i] = op(seg[i *\
    \ 2], seg[i * 2 + 1]);\n    }\n    std::vector<int> poped_time(n);\n    poped_time[0]\
    \ = 0;\n    for (int i = 1; i < n; i++){\n        int c = seg[1];\n        int\
    \ p = leader(par[c]);\n        done[c] = true;\n        merge(p, c);\n       \
    \ uf[c] = p;\n        update(c);\n        update(p);\n        poped_time[c] =\
    \ i;\n    }\n    if constexpr (!get_order){\n        return ;\n    }\n    // topological\
    \ sort of vertex by comparison of poped_time\n    std::vector<std::vector<int>>\
    \ childs(n);\n    for (int v = 1; v < n; v++){\n        childs[par[v]].emplace_back(v);\n\
    \    }\n    std::priority_queue<long long, std::vector<long long>, std::greater<long\
    \ long>> tvs;\n    auto val = [&](int v) -> long long {\n        return ((long\
    \ long)(poped_time[v]) << 32) | v;\n    };\n    tvs.push(0);\n    std::vector<int>\
    \ order; order.reserve(n);\n    const long long mask = (1LL << 32) - 1;\n    while\
    \ (!tvs.empty()){\n        int v = tvs.top() & mask; tvs.pop();\n        order.emplace_back(v);\n\
    \        for (int c : childs[v]){\n            tvs.push(val(c));\n        }\n\
    \    }\n    if constexpr (get_order){\n        return order;\n    }\n}\n\n// root\
    \ is vertex 0, par[i] < i\ntemplate<typename T, bool get_order = true>\nrequires\
    \ requires (T x, T y){\n    x < y;\n    {T::op(x, y)} -> std::same_as<T>;\n}\n\
    std::conditional_t<get_order, std::vector<int>, T> O1onTree(int n, const std::vector<int>\
    \ &par, std::vector<T> a){\n    assert(ssize(par) == n);\n    for (int i = 0;\
    \ i < n; i++){\n        assert(par[i] < i);\n    }\n    std::vector<int> uf(n,\
    \ -1);\n    auto leader = [&](int aa){\n        auto dfs = [&](auto sfs, int v){\n\
    \            if (uf[v] < 0) return v;\n            return uf[v] = sfs(sfs,uf[v]);\n\
    \        };\n        return dfs(dfs,aa);\n    };\n    using dat = std::pair<T,\
    \ long long>;\n    std::priority_queue<dat, std::vector<dat>, std::greater<dat>>\
    \ pque;\n    for (int i = 1; i < n; i++){\n        pque.push({a[i], i});\n   \
    \ }\n    const long long mask = (1LL << 32) - 1;\n    const int time_max = (1\
    \ << 30);\n    std::vector<int> latest(n,0);\n    std::vector<int> poped_time(n);\n\
    \    poped_time[0] = 0;\n    int idx = 1;\n    while (!pque.empty()){\n      \
    \  auto [xc, tc] = pque.top(); pque.pop();\n        if (latest[tc & mask] > (tc\
    \ >> 32)) continue;\n        int c = (tc & mask);\n        latest[c] = time_max;\n\
    \        int p = leader(par[c]);\n        uf[c] = p;\n        a[p] = T::op(a[p],\
    \ xc);\n        if (p != 0){\n            latest[p]++;\n            pque.push({a[p],\
    \ ((long long)(latest[p]) << 32) | p});\n        }\n        poped_time[c] = idx++;\n\
    \    }\n    if constexpr (!get_order){\n        return a[0];\n    }\n    std::vector<std::vector<int>>\
    \ childs(n);\n    for (int v = 1; v < n; v++){\n        childs[par[v]].emplace_back(v);\n\
    \    }\n    std::priority_queue<long long, std::vector<long long>, std::greater<long\
    \ long>> tvs;\n    auto val = [&](int v) -> long long {\n        return ((long\
    \ long)(poped_time[v]) << 32) | v;\n    };\n    tvs.push(0);\n    std::vector<int>\
    \ order; order.reserve(n);\n    while (!tvs.empty()){\n        int v = tvs.top()\
    \ & mask; tvs.pop();\n        order.emplace_back(v);\n        for (int c : childs[v]){\n\
    \            tvs.push(val(c));\n        }\n    }\n    if constexpr (get_order){\n\
    \        return order;\n    }\n}\n\n} // namespace noya2\n#line 5 \"test/misc/RootedTreeTopologicalOrderwithMinimumInversions.test.cpp\"\
    \n\nstruct mono {\n    ll c, d;\n    static constexpr mono op(mono a, mono b){\n\
    \        return {a.c + b.c, a.d + b.d};\n    }\n    friend bool operator<(mono\
    \ a, mono b){\n        if (b.c == 0 && b.d == 0) return false;\n        if (a.c\
    \ == 0 && a.d == 0) return true;\n        return a.d * b.c < a.c * b.d;\n    }\n\
    };\n\nint main(){\n    int n; in(n);\n    vector<int> par(n);\n    par[0] = -1;\n\
    \    repp(i,1,n){\n        in(par[i]);\n    }\n    vector<ll> c(n), d(n); in(c,d);\n\
    \    vector<mono> ds(n);\n    rep(i,n){\n        ds[i] = {c[i], d[i]};\n    }\n\
    \    auto ord = O1onTree<mono, true>(n, par, ds);\n    ll ans = 0;\n    ll dsum\
    \ = 0;\n    for (int i : ord){\n        ans += dsum * c[i];\n        dsum += d[i];\n\
    \    }\n    out(ans);\n    out(ord);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../misc/O1onTree.hpp\"\
    \n\nstruct mono {\n    ll c, d;\n    static constexpr mono op(mono a, mono b){\n\
    \        return {a.c + b.c, a.d + b.d};\n    }\n    friend bool operator<(mono\
    \ a, mono b){\n        if (b.c == 0 && b.d == 0) return false;\n        if (a.c\
    \ == 0 && a.d == 0) return true;\n        return a.d * b.c < a.c * b.d;\n    }\n\
    };\n\nint main(){\n    int n; in(n);\n    vector<int> par(n);\n    par[0] = -1;\n\
    \    repp(i,1,n){\n        in(par[i]);\n    }\n    vector<ll> c(n), d(n); in(c,d);\n\
    \    vector<mono> ds(n);\n    rep(i,n){\n        ds[i] = {c[i], d[i]};\n    }\n\
    \    auto ord = O1onTree<mono, true>(n, par, ds);\n    ll ans = 0;\n    ll dsum\
    \ = 0;\n    for (int i : ord){\n        ans += dsum * c[i];\n        dsum += d[i];\n\
    \    }\n    out(ans);\n    out(ord);\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - misc/O1onTree.hpp
  isVerificationFile: true
  path: test/misc/RootedTreeTopologicalOrderwithMinimumInversions.test.cpp
  requiredBy: []
  timestamp: '2025-03-12 22:52:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/RootedTreeTopologicalOrderwithMinimumInversions.test.cpp
layout: document
redirect_from:
- /verify/test/misc/RootedTreeTopologicalOrderwithMinimumInversions.test.cpp
- /verify/test/misc/RootedTreeTopologicalOrderwithMinimumInversions.test.cpp.html
title: test/misc/RootedTreeTopologicalOrderwithMinimumInversions.test.cpp
---
