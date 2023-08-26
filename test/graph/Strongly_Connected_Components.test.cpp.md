---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/graph/Strongly_Connected_Components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#line 2 \"template/template.hpp\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"graph/scc.hpp\"\
    \n\n#line 4 \"graph/scc.hpp\"\n\nnamespace noya2{\n\ntemplate <class E> struct\
    \ csr {\n    std::vector<int> start;\n    std::vector<E> elist;\n    explicit\
    \ csr(int n, const std::vector<std::pair<int, E>>& edges)\n        : start(n +\
    \ 1), elist(edges.size()) {\n        for (auto e : edges) {\n            start[e.first\
    \ + 1]++;\n        }\n        for (int i = 1; i <= n; i++) {\n            start[i]\
    \ += start[i - 1];\n        }\n        auto counter = start;\n        for (auto\
    \ e : edges) {\n            elist[counter[e.first]++] = e.second;\n        }\n\
    \    }\n};\n\nstruct scc_graph {\n  public:\n    explicit scc_graph(int n) : _n(n)\
    \ {}\n\n    int num_vertices() { return _n; }\n\n    void add_edge(int from, int\
    \ to) { edges.push_back({from, {to}}); }\n\n    // @return pair of (# of scc,\
    \ scc id)\n    std::pair<int, std::vector<int>> scc_ids() {\n        auto g =\
    \ csr<edge>(_n, edges);\n        int now_ord = 0, group_num = 0;\n        std::vector<int>\
    \ visited, low(_n), ord(_n, -1), ids(_n);\n        visited.reserve(_n);\n    \
    \    auto dfs = [&](auto self, int v) -> void {\n            low[v] = ord[v] =\
    \ now_ord++;\n            visited.push_back(v);\n            for (int i = g.start[v];\
    \ i < g.start[v + 1]; i++) {\n                auto to = g.elist[i].to;\n     \
    \           if (ord[to] == -1) {\n                    self(self, to);\n      \
    \              low[v] = std::min(low[v], low[to]);\n                } else {\n\
    \                    low[v] = std::min(low[v], ord[to]);\n                }\n\
    \            }\n            if (low[v] == ord[v]) {\n                while (true)\
    \ {\n                    int u = visited.back();\n                    visited.pop_back();\n\
    \                    ord[u] = _n;\n                    ids[u] = group_num;\n \
    \                   if (u == v) break;\n                }\n                group_num++;\n\
    \            }\n        };\n        for (int i = 0; i < _n; i++) {\n         \
    \   if (ord[i] == -1) dfs(dfs, i);\n        }\n        for (auto& x : ids) {\n\
    \            x = group_num - 1 - x;\n        }\n        return {group_num, ids};\n\
    \    }\n\n    std::vector<std::vector<int>> scc() {\n        auto ids = scc_ids();\n\
    \        int group_num = ids.first;\n        std::vector<int> counts(group_num);\n\
    \        for (auto x : ids.second) counts[x]++;\n        std::vector<std::vector<int>>\
    \ groups(ids.first);\n        for (int i = 0; i < group_num; i++) {\n        \
    \    groups[i].reserve(counts[i]);\n        }\n        for (int i = 0; i < _n;\
    \ i++) {\n            groups[ids.second[i]].push_back(i);\n        }\n       \
    \ return groups;\n    }\n\n  private:\n    int _n;\n    struct edge {\n      \
    \  int to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n};\n\n} // namespace\
    \ noya2\n#line 5 \"test/graph/Strongly_Connected_Components.test.cpp\"\n\nint\
    \ main(){\n    int n, m; in(n,m);\n    scc_graph g(n);\n    rep(i,m){\n      \
    \  int u, v; in(u,v);\n        g.add_edge(u,v);\n    }\n    auto ans = g.scc();\n\
    \    out(ans.size());\n    for (auto &v : ans){\n        out(v.size(),v);\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include\"../../template/template.hpp\"\
    \n#include\"../../graph/scc.hpp\"\n\nint main(){\n    int n, m; in(n,m);\n   \
    \ scc_graph g(n);\n    rep(i,m){\n        int u, v; in(u,v);\n        g.add_edge(u,v);\n\
    \    }\n    auto ans = g.scc();\n    out(ans.size());\n    for (auto &v : ans){\n\
    \        out(v.size(),v);\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - graph/scc.hpp
  isVerificationFile: true
  path: test/graph/Strongly_Connected_Components.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 17:35:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Strongly_Connected_Components.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Strongly_Connected_Components.test.cpp
- /verify/test/graph/Strongly_Connected_Components.test.cpp.html
title: test/graph/Strongly_Connected_Components.test.cpp
---
