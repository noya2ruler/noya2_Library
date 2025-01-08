---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  - icon: ':heavy_check_mark:'
    path: graph/cycle_detection.hpp
    title: graph/cycle_detection.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/graph/CycleDetectionDirected.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"graph/cycle_detection.hpp\"\n\
    \n#include <optional>\n#line 7 \"graph/cycle_detection.hpp\"\n\n#line 2 \"data_structure/csr.hpp\"\
    \n\n#line 4 \"data_structure/csr.hpp\"\n#include<ranges>\n#line 7 \"data_structure/csr.hpp\"\
    \n\nnamespace noya2::internal {\n\ntemplate<class E>\nstruct csr {\n    csr ()\
    \ {}\n    csr (int _n) : n(_n) {}\n    csr (int _n, int m) : n(_n){\n        start.reserve(m);\n\
    \        elist.reserve(m);\n    }\n    // ACL style constructor (do not have to\
    \ call build)\n    csr (int _n, const std::vector<std::pair<int,E>> &idx_elem)\
    \ : n(_n), start(_n + 2), elist(idx_elem.size()) {\n        for (auto &[i, e]\
    \ : idx_elem){\n            start[i + 2]++;\n        }\n        for (int i = 1;\
    \ i < n; i++){\n            start[i + 2] += start[i + 1];\n        }\n       \
    \ for (auto &[i, e] : idx_elem){\n            elist[start[i + 1]++] = e;\n   \
    \     }\n        prepared = true;\n    }\n    int add(int idx, E elem){\n    \
    \    int eid = start.size();\n        start.emplace_back(idx);\n        elist.emplace_back(elem);\n\
    \        return eid;\n    }\n    void build(){\n        if (prepared) return ;\n\
    \        int m = start.size();\n        std::vector<E> nelist(m);\n        std::vector<int>\
    \ nstart(n + 2, 0);\n        for (int i = 0; i < m; i++){\n            nstart[start[i]\
    \ + 2]++;\n        }\n        for (int i = 1; i < n; i++){\n            nstart[i\
    \ + 2] += nstart[i + 1];\n        }\n        for (int i = 0; i < m; i++){\n  \
    \          nelist[nstart[start[i] + 1]++] = elist[i];\n        }\n        swap(elist,nelist);\n\
    \        swap(start,nstart);\n        prepared = true;\n    }\n    const auto\
    \ operator[](int idx) const {\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    auto operator[](int idx){\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    const auto operator()(int idx, int l, int r) const {\n        return\
    \ std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    auto operator()(int idx, int l, int r){\n        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    size_t size() const {\n        return n;\n    }\n    int n;\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    bool prepared = false;\n};\n\n} // namespace\
    \ noya2::internal\n#line 9 \"graph/cycle_detection.hpp\"\n\nnamespace noya2 {\n\
    \nstd::optional<std::vector<int>> cycle_detection_directed(int n, const std::vector<std::pair<int,int>>\
    \ &es){\n    internal::csr<std::pair<int,int>> g(n,es.size());\n    for (int i\
    \ = 0; auto [u, v] : es){\n        g.add(u,std::pair<int,int>(v, i));\n      \
    \  i++;\n    }\n    g.build();\n    std::vector<bool> seen(n,false), done(n,false);\n\
    \    std::vector<int> cycle;\n    // -1:over,-2:done\n    auto dfs = [&](auto\
    \ sfs, int v, int pid) -> int {\n        if (seen[v]) return v;\n        if (done[v])\
    \ return -1;\n        seen[v] = true;\n        for (auto &[to, eid] : g[v]) if\
    \ (eid != pid){\n            int nxt = sfs(sfs, to, eid);\n            if (nxt\
    \ != -1){\n                if (nxt == -2) return -2;\n                cycle.emplace_back(eid);\n\
    \                if (nxt == v) return -2;\n                return nxt;\n     \
    \       }\n        }\n        seen[v] = false;\n        done[v] = true;\n    \
    \    return -1;\n    };\n    for (int i = 0; i < n; i++){\n        if (dfs(dfs,\
    \ i, -1) == -2){\n            std::reverse(cycle.begin(), cycle.end());\n    \
    \        return cycle;\n        }\n    }\n    return std::nullopt;\n}\n\n} //\
    \ namespace noya2\n#line 5 \"test/graph/CycleDetectionDirected.test.cpp\"\n\n\
    int main(){\n    int n, m; in(n,m);\n    vector<pii> es(m); in(es);\n    auto\
    \ res = cycle_detection_directed(n,es);\n    if (!res){\n        out(-1);\n  \
    \  }\n    else {\n        auto cycle = res.value();\n        out(cycle.size());\n\
    \        for (auto i : cycle){\n            out(i);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\"\
    ../../template/template.hpp\"\n#include\"../../graph/cycle_detection.hpp\"\n\n\
    int main(){\n    int n, m; in(n,m);\n    vector<pii> es(m); in(es);\n    auto\
    \ res = cycle_detection_directed(n,es);\n    if (!res){\n        out(-1);\n  \
    \  }\n    else {\n        auto cycle = res.value();\n        out(cycle.size());\n\
    \        for (auto i : cycle){\n            out(i);\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - graph/cycle_detection.hpp
  - data_structure/csr.hpp
  isVerificationFile: true
  path: test/graph/CycleDetectionDirected.test.cpp
  requiredBy: []
  timestamp: '2024-10-30 04:43:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/CycleDetectionDirected.test.cpp
layout: document
redirect_from:
- /verify/test/graph/CycleDetectionDirected.test.cpp
- /verify/test/graph/CycleDetectionDirected.test.cpp.html
title: test/graph/CycleDetectionDirected.test.cpp
---