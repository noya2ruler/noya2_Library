---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
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
    path: test/tree/aoj_0489.test.cpp
    title: test/tree/aoj_0489.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/pakencamp-2022-day1/submissions/43052952
  bundledCode: "#line 2 \"tree/Mo_on_Tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"misc/mo_algorithm.hpp\"\n\n/*\n\
    \nusage : https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp\n\
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
    \            rem(idx);\n        }\n    }\n};\n\n}\n#line 5 \"tree/Mo_on_Tree.hpp\"\
    \n\n/*\n\nMoTree_edge is verified with : https://atcoder.jp/contests/pakencamp-2022-day1/submissions/43052952\n\
    \n*/\n\nnamespace noya2{\n\ntemplate<class T>\nstruct MoTree_edge {\n    int n;\n\
    \    vector<vector<pair<int,T>>> es;\n    MoTree_edge (int _n) : n(_n) {\n   \
    \     es.resize(n);\n    }\n    void add_edge(int u, int v, T w){\n        es[u].emplace_back(v,w);\n\
    \        es[v].emplace_back(u,w);\n    }\n    vector<int> in;\n    vector<pair<int,T>>\
    \ vals;\n    Mo mo;\n    void build(int q){\n        int tnow = 0;\n        auto\
    \ dfs = [&](auto dfs, int v, int f) -> void {\n            in[v] = tnow++;\n \
    \           for (auto [u, w] : es[v]){\n                if (u == f) continue;\n\
    \                vals.emplace_back(u,w);\n                dfs(dfs,u,v);\n    \
    \            vals.emplace_back(u,w);\n                tnow++;\n            }\n\
    \        };\n        in.resize(n);\n        dfs(dfs,0,-1);\n        mo = Mo(2*n-2,q);\n\
    \    }\n    void insert(int u, int v){\n        u = in[u], v = in[v];\n      \
    \  if (u > v) swap(u,v);\n        mo.insert(u,v);\n    }\n    template<typename\
    \ ADD, typename DEL, typename REM>\n    void run(const ADD &add, const DEL &del,\
    \ const REM &rem){\n        vector<bool> contain(n,false);\n        auto change\
    \ = [&](int i){\n            int id = vals[i].first;\n            if (contain[id]){\n\
    \                del(vals[i].second);\n                contain[id] = false;\n\
    \            }\n            else {\n                add(vals[i].second);\n   \
    \             contain[id] = true;\n            }\n        };\n        mo.run(change,change,change,change,rem);\n\
    \    }\n};\n\n\ntemplate<class T>\nstruct MoTree_vertex {\n    int n;\n    vector<vector<int>>\
    \ es;\n    vector<T> b;\n    MoTree_vertex (int _n, vector<T> _b) : n(_n), b(_b)\
    \ {\n        es.resize(n);\n    }\n    void add_edge(int u, int v){\n        es[u].emplace_back(v);\n\
    \        es[v].emplace_back(u);\n    }\n    vector<int> in;\n    vector<pair<int,T>>\
    \ vals;\n    vector<int> lcas;\n    Mo mo;\n    void build(int q){\n        vals.reserve(2*n-2);\n\
    \        lcas.reserve(q);\n        int tnow = 0;\n        auto dfs = [&](auto\
    \ dfs, int v, int f) -> void {\n            in[v] = tnow++;\n            for (auto\
    \ u : es[v]){\n                if (u == f) continue;\n                vals.emplace_back(u,b[u]);\n\
    \                dfs(dfs,u,v);\n                vals.emplace_back(u,b[u]);\n \
    \               tnow++;\n            }\n        };\n        in.resize(n);\n  \
    \      dfs(dfs,0,-1);\n        mo = Mo(2*n-2,q);\n    }\n    \n    void insert(int\
    \ u, int v, int lca){\n        u = in[u], v = in[v];\n        if (u > v) swap(u,v);\n\
    \        mo.insert(u,v);\n        lcas.push_back(lca);\n    }\n    template<typename\
    \ ADD, typename DEL, typename REM>\n    void run(const ADD &add, const DEL &del,\
    \ const REM &rem){\n        vector<bool> contain(n,false);\n        auto change\
    \ = [&](int i){\n            int id = vals[i].first;\n            if (contain[id]){\n\
    \                del(vals[i].second);\n                contain[id] = false;\n\
    \            }\n            else {\n                add(vals[i].second);\n   \
    \             contain[id] = true;\n            }\n        };\n        auto rem_add_lca\
    \ = [&](int i){\n            add(b[lcas[i]]);\n            rem(i);\n         \
    \   del(b[lcas[i]]);\n        };\n        mo.run(change,change,change,change,rem_add_lca);\n\
    \    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../misc/mo_algorithm.hpp\"\
    \n\n/*\n\nMoTree_edge is verified with : https://atcoder.jp/contests/pakencamp-2022-day1/submissions/43052952\n\
    \n*/\n\nnamespace noya2{\n\ntemplate<class T>\nstruct MoTree_edge {\n    int n;\n\
    \    vector<vector<pair<int,T>>> es;\n    MoTree_edge (int _n) : n(_n) {\n   \
    \     es.resize(n);\n    }\n    void add_edge(int u, int v, T w){\n        es[u].emplace_back(v,w);\n\
    \        es[v].emplace_back(u,w);\n    }\n    vector<int> in;\n    vector<pair<int,T>>\
    \ vals;\n    Mo mo;\n    void build(int q){\n        int tnow = 0;\n        auto\
    \ dfs = [&](auto dfs, int v, int f) -> void {\n            in[v] = tnow++;\n \
    \           for (auto [u, w] : es[v]){\n                if (u == f) continue;\n\
    \                vals.emplace_back(u,w);\n                dfs(dfs,u,v);\n    \
    \            vals.emplace_back(u,w);\n                tnow++;\n            }\n\
    \        };\n        in.resize(n);\n        dfs(dfs,0,-1);\n        mo = Mo(2*n-2,q);\n\
    \    }\n    void insert(int u, int v){\n        u = in[u], v = in[v];\n      \
    \  if (u > v) swap(u,v);\n        mo.insert(u,v);\n    }\n    template<typename\
    \ ADD, typename DEL, typename REM>\n    void run(const ADD &add, const DEL &del,\
    \ const REM &rem){\n        vector<bool> contain(n,false);\n        auto change\
    \ = [&](int i){\n            int id = vals[i].first;\n            if (contain[id]){\n\
    \                del(vals[i].second);\n                contain[id] = false;\n\
    \            }\n            else {\n                add(vals[i].second);\n   \
    \             contain[id] = true;\n            }\n        };\n        mo.run(change,change,change,change,rem);\n\
    \    }\n};\n\n\ntemplate<class T>\nstruct MoTree_vertex {\n    int n;\n    vector<vector<int>>\
    \ es;\n    vector<T> b;\n    MoTree_vertex (int _n, vector<T> _b) : n(_n), b(_b)\
    \ {\n        es.resize(n);\n    }\n    void add_edge(int u, int v){\n        es[u].emplace_back(v);\n\
    \        es[v].emplace_back(u);\n    }\n    vector<int> in;\n    vector<pair<int,T>>\
    \ vals;\n    vector<int> lcas;\n    Mo mo;\n    void build(int q){\n        vals.reserve(2*n-2);\n\
    \        lcas.reserve(q);\n        int tnow = 0;\n        auto dfs = [&](auto\
    \ dfs, int v, int f) -> void {\n            in[v] = tnow++;\n            for (auto\
    \ u : es[v]){\n                if (u == f) continue;\n                vals.emplace_back(u,b[u]);\n\
    \                dfs(dfs,u,v);\n                vals.emplace_back(u,b[u]);\n \
    \               tnow++;\n            }\n        };\n        in.resize(n);\n  \
    \      dfs(dfs,0,-1);\n        mo = Mo(2*n-2,q);\n    }\n    \n    void insert(int\
    \ u, int v, int lca){\n        u = in[u], v = in[v];\n        if (u > v) swap(u,v);\n\
    \        mo.insert(u,v);\n        lcas.push_back(lca);\n    }\n    template<typename\
    \ ADD, typename DEL, typename REM>\n    void run(const ADD &add, const DEL &del,\
    \ const REM &rem){\n        vector<bool> contain(n,false);\n        auto change\
    \ = [&](int i){\n            int id = vals[i].first;\n            if (contain[id]){\n\
    \                del(vals[i].second);\n                contain[id] = false;\n\
    \            }\n            else {\n                add(vals[i].second);\n   \
    \             contain[id] = true;\n            }\n        };\n        auto rem_add_lca\
    \ = [&](int i){\n            add(b[lcas[i]]);\n            rem(i);\n         \
    \   del(b[lcas[i]]);\n        };\n        mo.run(change,change,change,change,rem_add_lca);\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - misc/mo_algorithm.hpp
  isVerificationFile: false
  path: tree/Mo_on_Tree.hpp
  requiredBy: []
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/aoj_0489.test.cpp
documentation_of: tree/Mo_on_Tree.hpp
layout: document
title: Mo on Tree
---

## 概要

木上の Mo's algorithm を扱います。

静的な列のいくつかの区間に対するクエリには Mo's algorithm が有効でした。これを静的な木のいくつかの単純パスに対するクエリに応用します。

このライブラリは、木上のクエリを列上のクエリに変換し、列上の Mo's algorithm と同様のインターフェースで扱えるようにしたものです。

しかし、このライブラリが扱える範囲は、列上の Mo's algorithm が扱えるものよりも狭いです。列上の Mo's algorithm は区間に含まれる値を集合より強く **列** として解釈したときの計算を行うことができます。一方、このライブラリが扱う木上の Mo's algorithm は、パスに含まれる値を一般には列としてではなく **集合** として解釈してもできる計算しか行うことができません。

例えば、次の問題 列A, 木A をみてください。

> 問題 列A 
>
> 逆元を持つ $d$ 次正方行列の列 $A=(A_1,A_2,\dots ,A_N)$ が与えられます。
> クエリが $Q$ 個与えられます。クエリでは列のある区間 $[l,r]$ が与えられるので、行列積 $A_l A_{l+1} \dots A_{r}$ を計算してください。
>
> 問題 木A
>
> $N$ 頂点の木が与えられます。各辺には逆元を持つ $d$ 次正方行列が定まっています。
> クエリが $Q$ 個与えられます。クエリでは木のある単純パス $u,v$ が与えられるので、 $u$ から $v$ に向かうときに通る辺に定まっている行列を順に掛け合わせていったものを計算してください。

列A は列上の Mo's algorithm で解くことができます。しかし、木A はこのライブラリの木上の Mo's algorithm では解くことができません。後述する工夫が必要です。

一方、次の問題　列B, 木B はどうでしょうか。

> 問題 列B
>
> 整数の列 $A=(A_1,A_2,\dots ,A_N)$ が与えられます。
> クエリが $Q$ 個与えられます。クエリでは列のある区間 $[l,r]$ が与えられるので、 $A_l A_{l+1} \dots A_{r}$ の種類数を計算してください。
>
> 問題 木A
>
> $N$ 頂点の木が与えられます。各辺には整数が定まっています。
> クエリが $Q$ 個与えられます。クエリでは木のある単純パス $u,v$ が与えられるので、 $u$ から $v$ に向かうときに通る辺に定まっている整数の種類数を計算してください。

列B はやはり列上の Mo's algorithm で解くことができます。また、木B はこのライブラリで解くことができます。

Aの問題は演算の順番が決まっていて、順番が異なれば計算結果(行列積)が異なり得るものでした。このため、木A はこのライブラリをそのまま用いることはできず、工夫が必要になります。
一方、Bの問題は演算の順番は決まっておらず、どの順番で計算しても計算結果(種類数)は異ならないのでした。このため木B はこのライブラリをそのまま用いて解くことができます。

---

木の **辺** に重みがある場合と木の **頂点** に重みがある場合で多少実装が異なるので、分けて説明します。

$N$ は扱う木の頂点数とします。木の頂点番号や添字は、特に断らない限り 0_indexed です。

## 辺に重みがある場合

変換には次の手順を行います。

1. 木のオイラーツアーを行い、訪れた **頂点** の列 $V=(v_0,v_1,\dots ,v_{2N-2})$ を作る。
2. 辺の列 $E=(e_0,e_1,\dots ,e_{2N-3})$ を $e_i=(v_i,v_{i+1})$ として定める。
3. $u,v$ パスに対するクエリは、 $V$ のすべての $u,v$ を含む極小な区間を $[l,r]$ として、 $E$ への区間クエリ $[l,r)$ として解釈する。
4. 変換した区間に同じ辺が $k$ 個含まれるとき、パスにはその辺は $k\bmod 2$ 個含まれることになる。

ここで、列上の Mo's algorithm では列の左右が区別できたのに対し、この変換ではパスの向きが失われていることに注意してください。このため、列上の Mo's algorithm が `add_left`, `add_right`, `del_left`, `del_right` を要求したのに対し、木上の Mo's algorithm は左右を区別せず `add`, `del` を要求します。そして、内部では区間に含まれる辺の集合を管理しながら、区間の伸縮に応じて `add` あるいは `del` を呼び出すようにしています。

`add` と `del` が逆元(元に戻す操作)の関係になっている場合は、演算が結合的であるならば、パスに含まれる辺は列として扱うことができます(交換則を満たす必要はありません)。ただし、パスの向きによって答えが変わる場合、このライブラリを素直に扱うことはできません。

しかし、演算の結合順序を逆向きにしたものを用意して $2$ 回アルゴリズムを実行し、どちらで正しい答えが得られるかを適切に判断すれば、解決できます。

演算の結合順序を逆向きにするとは、つまり列への追加 $A\ \overset{\mathrm{add}}\longleftarrow a$ を $A\circ a$ から $a\circ A$ に変更するということです。


### `MoTree_edge<T>(int n)`

コンストラクタです。 $n$ 頂点の木を作る準備をします。辺の重みを保持する型を `T` とします。

### `void add_edge(int u, int v, T w)`

辺 $(u,v)$ を追加します。辺の重みは $w$ です。

### `void build(int q)`

$q$ クエリあるとし、前処理としてオイラーツアーを行います。

### `void insert(int u, int v)`

$u,v$ パスへのクエリを追加します。

### `void run(add, del, rem)`

辺の重み集合への $w$ の追加および削除を行うラムダ式 `add(T w)`, `del(T w)` と、 $i$ 番目に追加したクエリの答えを記録するラムダ式 `rem(int i)` を引数に取り、すべてのクエリを処理します。長さ $2N-2$ の列に対する Mo's algorithm の計算量になっていることに注意してください。

---

## 頂点に重みがある場合

頂点に重みがある場合は少し複雑になります。基本的なアイデアは、辺に重みがある場合に帰着することです。

まず、適当に根をとって木を根付き木にします。そして、根以外の頂点 $v$ に対しては、重みを $v$ の親との間の辺にあるものとします。

そして、パス $(u,v)$ に対するクエリは、 $u,v$ の LCA となる頂点の重みを先ほど帰着した辺に重みがある場合のパスクエリに加えたものとします。

辺に重みがある場合と比べて、重みの集合への追加削除を行う順番がパスに含まれる頂点の順になっていないことに注意してください。

パスに現れる順番で重みを考えたい場合は、辺に重みがある場合と同様の工夫により結合順序を両方用意し、さらにパスを LCA で分割してアルゴリズムを適用し、最後に結果を合わせることができれば良いことになります。結果を合わせることが必ずしも効率的にはできない可能性があります。(例えば、木Bの問題をこの方法で解くには、マージした集合の要素の種類数をマージ前の種類数のみから得る必要がありますが、これは一般には不可能です)


### `MoTree_vertex<T>(int n, vector<T> b)`

コンストラクタです。 $n$ 頂点の木を作る準備をします。頂点の重みを保持する型を `T` とし、頂点 `i` の重みが `b[i]` であるような列を受け取ります。

### `void add_edge(int u, int v)`

辺 $(u,v)$ を追加します。

### `void build(int q)`

$q$ クエリあるとし、前処理としてオイラーツアーを行います。

### `void insert(int u, int v, int lca)`

$u,v$ パスへのクエリを追加します。ただし、木の根を頂点 $0$ としたときの頂点 $u,v$ の LCA を $lca$ とします。

### `void run(add, del, rem)`

頂点の重み集合への $w$ の追加および削除を行うラムダ式 `add(T w)`, `del(T w)` と、 $i$ 番目に追加したクエリの答えを記録するラムダ式 `rem(int i)` を引数に取り、すべてのクエリを処理します。長さ $2N-2$ の列に対する Mo's algorithm の計算量になっていることに注意してください。