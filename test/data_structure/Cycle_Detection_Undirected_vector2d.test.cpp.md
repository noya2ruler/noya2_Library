---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/vector2d.hpp
    title: 2-dimentional vector
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection_undirected
    links:
    - https://judge.yosupo.jp/problem/cycle_detection_undirected
  bundledCode: "#line 1 \"test/data_structure/Cycle_Detection_Undirected_vector2d.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/vector2d.hpp\"\
    \n\n#line 4 \"data_structure/vector2d.hpp\"\n#include<ranges>\n\nnamespace noya2{\n\
    \ntemplate<class E>\nstruct vector2d {\n    vector2d (int n_ = 0, int m_ = 0)\
    \ : n(n_), m(m_), inner_element_id(0) {\n        es.resize(m);\n        start.resize(m,0);\n\
    \        if (m == 0) build();\n    }\n    void add(int from, E e){\n        es[inner_element_id]\
    \ = e, start[inner_element_id] = from;\n        if (++inner_element_id == m) build();\n\
    \    }\n    const auto operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);\
    \ }\n    std::vector<int> start;\n  private:\n    void build(){\n        std::vector<E>\
    \ nes(m);\n        std::vector<int> nstart(n+1,0);\n        for (int i = 0; i\
    \ < m; i++) nstart[start[i]+1]++;\n        for (int i = 0; i < n; i++) nstart[i+1]\
    \ += nstart[i];\n        auto geta = nstart;\n        for (int i = 0; i < m; i++)\
    \ nes[geta[start[i]]++] = es[i];\n        std::swap(nes,es); std::swap(nstart,start);\n\
    \    }\n    int n, m, inner_element_id;\n    std::vector<E> es;\n};\n\n} // namespace\
    \ noya2\n#line 5 \"test/data_structure/Cycle_Detection_Undirected_vector2d.test.cpp\"\
    \n\nint main(){\n    int n, m; in(n,m);\n    vector2d<pii> g(n,m*2);\n    rep(i,m){\n\
    \        int u, v; in(u,v);\n        g.add(u,pii(v,i));\n        g.add(v,pii(u,i));\n\
    \    }\n    vector<bool> used(m,false), visited(n,false);\n    queue<int> que;\n\
    \    int sv = -1, tv = -1, eid = -1;\n    rep(i,n){\n        if (visited[i]) continue;\n\
    \        que.push(i);\n        visited[i] = true;\n        while (!que.empty()){\n\
    \            int p = que.front(); que.pop();\n            for (auto [q, e] : g[p]){\n\
    \                if (used[e]) continue;\n                if (visited[q]){\n  \
    \                  sv = p, tv = q, eid = e;\n                    continue;\n \
    \               }\n                used[e] = true;\n                visited[q]\
    \ = true;\n                que.push(q);\n            }\n        }\n    }\n   \
    \ if (sv == -1){\n        cout << -1 << endl;\n        return 0;\n    }\n    fill(all(visited),false);\n\
    \    vector<int> vs, es;\n    bool done = false;\n    auto dfs = [&](auto sfs,\
    \ int v) -> void {\n        if (done) return ;\n        vs.push_back(v);\n   \
    \     visited[v] = true;\n        if (v == tv){\n            done = true;\n  \
    \          return ;\n        }\n        for (auto [u, e] : g[v]){\n          \
    \  if (e == eid) continue;\n            if (visited[u]) continue;\n          \
    \  es.push_back(e);\n            sfs(sfs,u);\n            if (done) return ;\n\
    \            es.pop_back();\n        }\n        vs.pop_back();\n    };\n    dfs(dfs,sv);\n\
    \    es.push_back(eid);\n    out(vs.size());\n    out(vs);\n    out(es);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../data_structure/vector2d.hpp\"\
    \n\nint main(){\n    int n, m; in(n,m);\n    vector2d<pii> g(n,m*2);\n    rep(i,m){\n\
    \        int u, v; in(u,v);\n        g.add(u,pii(v,i));\n        g.add(v,pii(u,i));\n\
    \    }\n    vector<bool> used(m,false), visited(n,false);\n    queue<int> que;\n\
    \    int sv = -1, tv = -1, eid = -1;\n    rep(i,n){\n        if (visited[i]) continue;\n\
    \        que.push(i);\n        visited[i] = true;\n        while (!que.empty()){\n\
    \            int p = que.front(); que.pop();\n            for (auto [q, e] : g[p]){\n\
    \                if (used[e]) continue;\n                if (visited[q]){\n  \
    \                  sv = p, tv = q, eid = e;\n                    continue;\n \
    \               }\n                used[e] = true;\n                visited[q]\
    \ = true;\n                que.push(q);\n            }\n        }\n    }\n   \
    \ if (sv == -1){\n        cout << -1 << endl;\n        return 0;\n    }\n    fill(all(visited),false);\n\
    \    vector<int> vs, es;\n    bool done = false;\n    auto dfs = [&](auto sfs,\
    \ int v) -> void {\n        if (done) return ;\n        vs.push_back(v);\n   \
    \     visited[v] = true;\n        if (v == tv){\n            done = true;\n  \
    \          return ;\n        }\n        for (auto [u, e] : g[v]){\n          \
    \  if (e == eid) continue;\n            if (visited[u]) continue;\n          \
    \  es.push_back(e);\n            sfs(sfs,u);\n            if (done) return ;\n\
    \            es.pop_back();\n        }\n        vs.pop_back();\n    };\n    dfs(dfs,sv);\n\
    \    es.push_back(eid);\n    out(vs.size());\n    out(vs);\n    out(es);\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/vector2d.hpp
  isVerificationFile: true
  path: test/data_structure/Cycle_Detection_Undirected_vector2d.test.cpp
  requiredBy: []
  timestamp: '2023-09-26 16:23:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Cycle_Detection_Undirected_vector2d.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Cycle_Detection_Undirected_vector2d.test.cpp
- /verify/test/data_structure/Cycle_Detection_Undirected_vector2d.test.cpp.html
title: test/data_structure/Cycle_Detection_Undirected_vector2d.test.cpp
---
