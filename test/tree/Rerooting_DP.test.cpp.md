---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: tree/rerootingdp.hpp
    title: Rerooting DP
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1976
    links:
    - https://yukicoder.me/problems/no/1976
  bundledCode: "#line 1 \"test/tree/Rerooting_DP.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1976\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"tree/rerootingdp.hpp\"\n\n#line\
    \ 5 \"tree/rerootingdp.hpp\"\n#include <ranges>\n\nnamespace noya2 {\n\n// g[from]\
    \ contains outgoing edges (to, edgeid(from, to))\n// (E, op, e) is commutative\
    \ monoid\n// ~edgeid(from, to) == edgeid(to, from)\n// return calculator of dp(r,\
    \ v)\ntemplate<class V, class E>\nauto rerootingdp(auto op, E e, auto put_edge,\
    \ auto put_vertex, const std::vector<std::vector<std::pair<int, int>>> &g, int\
    \ root = 0){\n    struct dp {\n        // dp(r, v) : root is r, dp of subtree\
    \ v\n        // ans[v]  = dp(v, v)\n        // from[v] = dp(v, par(v))\n     \
    \   // to[v]   = dp(par(v), v)\n        // from[root] and to[root] is undefined\n\
    \        std::vector<V> ans, from, to;\n        std::vector<int> down, up;\n \
    \       std::vector<std::vector<int>> childs;\n        bool is_in_subtree(int\
    \ r, int v){\n            return down[r] < down[v] && up[v] <= up[r];\n      \
    \  }\n        V operator()(int r, int v){\n            if (r == v) return ans[v];\n\
    \            if (!is_in_subtree(v, r)) return to[v];\n            int le = 0,\
    \ ri = childs[v].size();\n            while (ri - le > 1){\n                int\
    \ md = (le + ri) / 2;\n                if (down[childs[v][md]] <= down[r]){\n\
    \                    le = md;\n                }\n                else {\n   \
    \                 ri = md;\n                }\n            }\n            return\
    \ from[childs[v][le]];\n        }\n    };\n    int n = g.size();\n    std::vector<E>\
    \ from(n, e), to(n, e);\n    std::vector<V> dp_to(n);\n    std::vector<std::vector<int>>\
    \ childs(n);\n    std::vector<int> down(n), up(n);\n    int t = 0;\n    auto dfs\
    \ = [&](auto sfs, int v, int f) -> void {\n        down[v] = t++;\n        childs[v].reserve(g[v].size());\n\
    \        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n    \
    \        childs[v].emplace_back(c);\n            sfs(sfs, c, v);\n           \
    \ dp_to[c] = put_vertex(to[c], c);\n            to[c] = put_edge(dp_to[c], eid);\n\
    \            to[v] = op(to[v], to[c]);\n        }\n        up[v] = t;\n    };\n\
    \    dfs(dfs, root, -1);\n    std::vector<V> dp_ans(n), dp_from(n);\n    std::vector<E>\
    \ inner(n);\n    auto bfs = [&](auto sfs, int v, int f) -> void {\n        int\
    \ sz = g[v].size();\n        inner[sz] = e;\n        int i = sz-1;\n        for\
    \ (auto [c, eid] : g[v] | std::views::reverse){\n            if (c == f) continue;\n\
    \            inner[i] = op(inner[i+1], to[c]);\n            i--;\n        }\n\
    \        dp_ans[v] = put_vertex(op(inner[++i], from[v]), v);\n        E rui =\
    \ e;\n        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n\
    \            dp_from[c] = put_vertex(op(op(rui, inner[++i]), from[v]), v);\n \
    \           from[c] = put_edge(dp_from[c], ~eid);\n            rui = op(rui, to[c]);\n\
    \        }\n        for (auto [c, eid] : g[v]){\n            if (c == f) continue;\n\
    \            sfs(sfs, c, v);\n        }\n    };\n    bfs(bfs, root, -1);\n   \
    \ return dp{dp_ans, dp_from, dp_to, down, up, childs};\n}\n\n}  // namespace noya2\n\
    #line 5 \"test/tree/Rerooting_DP.test.cpp\"\n\nint main() {\n    int n; in(n);\n\
    \    vector<vector<pii>> g(n);\n    for (int i = 0; i < n - 1; i++) {\n      \
    \  int u, v; in(u, v); u--, v--;\n        g[u].emplace_back(v, i);\n        g[v].emplace_back(u,\
    \ ~i);\n    }\n    auto op = [&](pii a, pii b){\n        return pii(max({a.first,\
    \ b.first, a.second + b.second}), max(a.second, b.second));\n    };\n    pii e(0,0);\n\
    \    auto pute = [&](pii x, int){\n        return pii(max(x.first, x.second +\
    \ 1), x.second + 1);\n    };\n    auto putv = [&](pii e, int){\n        return\
    \ e;\n    };\n    auto dp = rerootingdp<pii,pii>(op,e,pute,putv,g);\n    int ans\
    \ = n;\n    for (int u = 0; u < n; u++) {\n        for (auto [v, eid] : g[u])\
    \ {\n            int x = dp(u, v).first;\n            int y = dp(v, u).first;\n\
    \            ans = min(ans, max({x, y, (x + 1) / 2 + (y + 1) / 2 + 1}));\n   \
    \     }\n    }\n    out(ans);\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1976\"\n\n#include \"\
    ../../template/template.hpp\"\n#include \"../../tree/rerootingdp.hpp\"\n\nint\
    \ main() {\n    int n; in(n);\n    vector<vector<pii>> g(n);\n    for (int i =\
    \ 0; i < n - 1; i++) {\n        int u, v; in(u, v); u--, v--;\n        g[u].emplace_back(v,\
    \ i);\n        g[v].emplace_back(u, ~i);\n    }\n    auto op = [&](pii a, pii\
    \ b){\n        return pii(max({a.first, b.first, a.second + b.second}), max(a.second,\
    \ b.second));\n    };\n    pii e(0,0);\n    auto pute = [&](pii x, int){\n   \
    \     return pii(max(x.first, x.second + 1), x.second + 1);\n    };\n    auto\
    \ putv = [&](pii e, int){\n        return e;\n    };\n    auto dp = rerootingdp<pii,pii>(op,e,pute,putv,g);\n\
    \    int ans = n;\n    for (int u = 0; u < n; u++) {\n        for (auto [v, eid]\
    \ : g[u]) {\n            int x = dp(u, v).first;\n            int y = dp(v, u).first;\n\
    \            ans = min(ans, max({x, y, (x + 1) / 2 + (y + 1) / 2 + 1}));\n   \
    \     }\n    }\n    out(ans);\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - tree/rerootingdp.hpp
  isVerificationFile: true
  path: test/tree/Rerooting_DP.test.cpp
  requiredBy: []
  timestamp: '2024-10-02 20:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Rerooting_DP.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Rerooting_DP.test.cpp
- /verify/test/tree/Rerooting_DP.test.cpp.html
title: test/tree/Rerooting_DP.test.cpp
---
