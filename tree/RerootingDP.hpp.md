---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':x:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/Rerooting_DP.test.cpp
    title: test/tree/Rerooting_DP.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/RerootingDP.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout.hpp\"\
    \nnamespace noya2 {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int\
    \ s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") <<\
    \ v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in()\
    \ {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...u) {\n  cin >> t;\n\
    \  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class...\
    \ U, char sep = ' '>\nvoid out(const T &t, const U &...u) {\n  cout << t;\n  if\
    \ (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nstruct IoSetup {\n  IoSetup()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetup_noya2;\n\
    \n}  // namespace noya2\n#line 1 \"template/const.hpp\"\nnamespace noya2{\n\n\
    const int iinf = 1'000'000'007;\nconst long long linf = 2'000'000'000'000'000'000LL;\n\
    const long long mod998 =  998244353;\nconst long long mod107 = 1000000007;\nconst\
    \ long double pi = 3.14159265358979323;\nconst vector<int> dx = {0,1,0,-1,1,1,-1,-1};\n\
    const vector<int> dy = {1,0,-1,0,1,-1,-1,1};\nconst string ALP = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ;\nconst string alp = \"abcdefghijklmnopqrstuvwxyz\";\nconst string NUM = \"0123456789\"\
    ;\n\nvoid yes(){ cout << \"Yes\\n\"; }\nvoid no(){ cout << \"No\\n\"; }\nvoid\
    \ YES(){ cout << \"YES\\n\"; }\nvoid NO(){ cout << \"NO\\n\"; }\nvoid yn(bool\
    \ t){ t ? yes() : no(); }\nvoid YN(bool t){ t ? YES() : NO(); }\n\n} // namespace\
    \ noya2\n#line 1 \"template/utils.hpp\"\nnamespace noya2{\n\null inner_binary_gcd(ull\
    \ a, ull b){\n    if (a == 0 || b == 0) return a + b;\n    int n = __builtin_ctzll(a);\n\
    \    int m = __builtin_ctzll(b);\n    a >>= n;\n    b >>= m;\n    while (a !=\
    \ b) {\n        int m = __builtin_ctzll(a - b);\n        bool f = a > b;\n   \
    \     ull c = f ? a : b;\n        b = f ? b : a;\n        a = (c - b) >> m;\n\
    \    }\n    return a << min(n, m);\n}\n\ntemplate<typename T>\nT gcd_fast(T a,\
    \ T b){\n    return static_cast<T>(inner_binary_gcd(static_cast<ull>(abs(a)),static_cast<ull>(abs(b))));\n\
    }\n\ntemplate<typename T>\nT floor_div(const T n, const T d) {\n    assert(d !=\
    \ 0);\n    return n / d - static_cast<T>((n ^ d) < 0 && n % d != 0);\n}\n\ntemplate<typename\
    \ T>\nT ceil_div(const T n, const T d) {\n    assert(d != 0);\n    return n /\
    \ d + static_cast<T>((n ^ d) >= 0 && n % d != 0);\n}\n\ntemplate<typename T> void\
    \ uniq(vector<T> &v){\n    sort(all(v));\n    v.erase(unique(all(v)),v.end());\n\
    }\n\ntemplate <typename T, typename U>\ninline bool chmin(T &x, U y) {\n    return\
    \ (y < x) ? (x = y, true) : false;\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool chmax(T &x, U y) {\n    return (x < y) ? (x = y, true) : false;\n}\n\n\
    template<typename T>\ninline bool range(T l, T x, T r){\n    return l <= x &&\
    \ x < r;\n}\n\n} // namespace noya2\n#line 8 \"template/template.hpp\"\n\n#define\
    \ rep(i,n) for (int i = 0; i < (int)(n); i++)\n#define repp(i,m,n) for (int i\
    \ = (m); i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1); i >= 0;\
    \ i--)\n#define all(v) (v).begin(),(v).end()\n\nusing ll = long long;\nusing ld\
    \ = long double;\nusing uint = unsigned int;\nusing ull = unsigned long long;\n\
    using pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pil = pair<int,ll>;\n\
    using pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000\
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"tree/RerootingDP.hpp\"\n\nnamespace\
    \ noya2 {\n\ntemplate <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V,\
    \ int), V (*put_vertex)(E, int)>\nstruct RerootingDP {\n    struct edge {\n  \
    \      int to, idx, xdi;\n    };\n    RerootingDP(int _n = 0) : n(_n) {\n    \
    \    es.resize(n);\n    }\n    void add_edge(int u, int v, int idx1, int idx2)\
    \ {\n        es[u].push_back({v, idx1, idx2});\n        es[v].push_back({u, idx2,\
    \ idx1});\n    }\n    vector<V> build(int v = 0) {\n        root = v;\n      \
    \  outs.resize(n);\n        subdp.resize(n);\n        in.resize(n), up.resize(n);\n\
    \        int tnow = 0;\n        dfs(root, -1, tnow);\n        return subdp;\n\
    \    }\n    vector<V> reroot() {\n        reverse_edge.resize(n);\n        reverse_edge[root]\
    \ = e();\n        reverse_dp.resize(n);\n        answers.resize(n);\n        bfs(root);\n\
    \        return answers;\n    }\n    V get(int r, int v) {\n        if (r == v)\
    \ return answers[r];\n        if (!(in[v] < in[r] && up[r] <= up[v])) return subdp[v];\n\
    \        int le = 0, ri = outs[v].size();\n        while (ri - le > 1) {\n   \
    \         int md = (le + ri) / 2;\n            if (in[es[v][md].to] <= in[r])\n\
    \                le = md;\n            else\n                ri = md;\n      \
    \  }\n        return reverse_dp[es[v][le].to];\n    }\n    const vector<edge>\
    \ &operator[](int idx) const {\n        return es[idx];\n    }\n\n  private:\n\
    \    int n, root;\n    vector<vector<edge>> es;\n    vector<vector<E>> outs;\n\
    \    vector<E> reverse_edge;\n    vector<V> subdp, reverse_dp, answers;\n    vector<int>\
    \ in, up;\n    void dfs(int v, int p, int &t) {\n        E val = e();\n      \
    \  in[v] = t++;\n        for (auto &u : es[v]) {\n            if (u.to == p &&\
    \ u.to != es[v].back().to) swap(u, es[v].back());\n            if (u.to == p)\
    \ continue;\n            dfs(u.to, v, t);\n            E nval = put_edge(subdp[u.to],\
    \ u.idx);\n            outs[v].emplace_back(nval);\n            val = merge(val,\
    \ nval);\n        }\n        subdp[v] = put_vertex(val, v);\n        up[v] = t;\n\
    \    }\n    void bfs(int v) {\n        int siz = outs[v].size();\n        vector<E>\
    \ lui(siz + 1), rui(siz + 1);\n        lui[0] = e(), rui[siz] = e();\n       \
    \ for (int i = 0; i < siz; i++) lui[i + 1] = merge(lui[i], outs[v][i]);\n    \
    \    for (int i = siz - 1; i >= 0; i--) rui[i] = merge(outs[v][i], rui[i + 1]);\n\
    \        for (int i = 0; i < siz; i++) {\n            reverse_dp[es[v][i].to]\
    \ = put_vertex(merge(merge(lui[i], rui[i + 1]), reverse_edge[v]), v);\n      \
    \      reverse_edge[es[v][i].to] = put_edge(reverse_dp[es[v][i].to], es[v][i].xdi);\n\
    \            bfs(es[v][i].to);\n        }\n        answers[v] = put_vertex(merge(lui[siz],\
    \ reverse_edge[v]), v);\n    }\n};\n\n}  // namespace noya2\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace noya2\
    \ {\n\ntemplate <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V,\
    \ int), V (*put_vertex)(E, int)>\nstruct RerootingDP {\n    struct edge {\n  \
    \      int to, idx, xdi;\n    };\n    RerootingDP(int _n = 0) : n(_n) {\n    \
    \    es.resize(n);\n    }\n    void add_edge(int u, int v, int idx1, int idx2)\
    \ {\n        es[u].push_back({v, idx1, idx2});\n        es[v].push_back({u, idx2,\
    \ idx1});\n    }\n    vector<V> build(int v = 0) {\n        root = v;\n      \
    \  outs.resize(n);\n        subdp.resize(n);\n        in.resize(n), up.resize(n);\n\
    \        int tnow = 0;\n        dfs(root, -1, tnow);\n        return subdp;\n\
    \    }\n    vector<V> reroot() {\n        reverse_edge.resize(n);\n        reverse_edge[root]\
    \ = e();\n        reverse_dp.resize(n);\n        answers.resize(n);\n        bfs(root);\n\
    \        return answers;\n    }\n    V get(int r, int v) {\n        if (r == v)\
    \ return answers[r];\n        if (!(in[v] < in[r] && up[r] <= up[v])) return subdp[v];\n\
    \        int le = 0, ri = outs[v].size();\n        while (ri - le > 1) {\n   \
    \         int md = (le + ri) / 2;\n            if (in[es[v][md].to] <= in[r])\n\
    \                le = md;\n            else\n                ri = md;\n      \
    \  }\n        return reverse_dp[es[v][le].to];\n    }\n    const vector<edge>\
    \ &operator[](int idx) const {\n        return es[idx];\n    }\n\n  private:\n\
    \    int n, root;\n    vector<vector<edge>> es;\n    vector<vector<E>> outs;\n\
    \    vector<E> reverse_edge;\n    vector<V> subdp, reverse_dp, answers;\n    vector<int>\
    \ in, up;\n    void dfs(int v, int p, int &t) {\n        E val = e();\n      \
    \  in[v] = t++;\n        for (auto &u : es[v]) {\n            if (u.to == p &&\
    \ u.to != es[v].back().to) swap(u, es[v].back());\n            if (u.to == p)\
    \ continue;\n            dfs(u.to, v, t);\n            E nval = put_edge(subdp[u.to],\
    \ u.idx);\n            outs[v].emplace_back(nval);\n            val = merge(val,\
    \ nval);\n        }\n        subdp[v] = put_vertex(val, v);\n        up[v] = t;\n\
    \    }\n    void bfs(int v) {\n        int siz = outs[v].size();\n        vector<E>\
    \ lui(siz + 1), rui(siz + 1);\n        lui[0] = e(), rui[siz] = e();\n       \
    \ for (int i = 0; i < siz; i++) lui[i + 1] = merge(lui[i], outs[v][i]);\n    \
    \    for (int i = siz - 1; i >= 0; i--) rui[i] = merge(outs[v][i], rui[i + 1]);\n\
    \        for (int i = 0; i < siz; i++) {\n            reverse_dp[es[v][i].to]\
    \ = put_vertex(merge(merge(lui[i], rui[i + 1]), reverse_edge[v]), v);\n      \
    \      reverse_edge[es[v][i].to] = put_edge(reverse_dp[es[v][i].to], es[v][i].xdi);\n\
    \            bfs(es[v][i].to);\n        }\n        answers[v] = put_vertex(merge(lui[siz],\
    \ reverse_edge[v]), v);\n    }\n};\n\n}  // namespace noya2\n"
  dependsOn:
  - template/template.hpp
  - template/inout.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: tree/RerootingDP.hpp
  requiredBy: []
  timestamp: '2023-07-17 20:29:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/Rerooting_DP.test.cpp
documentation_of: tree/RerootingDP.hpp
layout: document
title: Rerooting DP
---

## RerootingDP

木に対して全方位木DPを行います。次の問題を解きます。

> 頂点 $0,1,\dots,n-1$ からなる $n$ 頂点の木 $T$ が与えられます。
> 有向グラフ $G=(\mathbb{V},\mathbb{E})$ は以下を満たします。
> - $\mathbb{V}=\lbrace 0,1,\dots, n-1 \rbrace$ である。
> - $\mathbb{E}\subset \mathbb{V}\times \mathbb{V}$ である。辺 $(a,b)$ は頂点 $a$ から頂点 $b$ への**有向辺**。 $T$ において頂点 $a,b$ の間に辺が張られているとき, またそのときに限り $(a,b),(b,a)\in \mathbb{E}$ である。
> 
> また、各有向辺には整数値の番号が割り当てられていて、 $\mathrm{idx}:\mathbb{E}\to \mathbb{Z}$ によって定められます。ここで $\mathbb{E}_\mathrm{idx}=\lbrace \mathrm{idx}(e)\ \mid\ e\in \mathbb{E} \rbrace$ としておきます。
> 
> **可換**モノイド $(E,\oplus : E\times E\to E,e\in E)$ と集合 $V$ および $\mathrm{put \_ edge}:V\times \mathbb{E}_\mathrm{idx}\to E,\ \mathrm{put \_ vertex}:E\times \mathbb{V}\to V$ が与えられます。次の擬似コードに従って計算される値 <code>dfs(0,0), dfs(1,1),...,dfs(n-1,n-1)</code> を求めてください。ただし、頂点 $r$ を根と見たときの頂点 $v$ の子の頂点の集合を $\mathrm{child}(r,v)$ とします。
>```
>V dfs(vertex r, vertex v){
>    E prod = e();
>    for ( (v, c) in E, c in child(r,v) ){
>        prod = merge(prod, put_edge(dfs(r,c),idx(v,c)));
>    }
>    return put_vertex(prod, v);
>}
>```

この問題を時間計算量 $\mathrm{O}(n)$ で解くことができます。

また、このライブラリはオラクルとして <code>merge, e, put_edge, put_vertex</code> を使用しますが、これらが定数時間で動くものと仮定したときの計算量を記述します。オラクル内部の計算量が $\mathrm{O}(f(n))$ である場合はすべての計算量が $\mathrm{O}(f(n))$ 倍となります。

### コンストラクタ

```
RerootingDP<E, V, merge, e, put_edge, put_vertex> g(int n);
```

- 可換モノイドの型 <code>E</code>
- DPの値の型 <code>V</code>
- $\oplus : E\times E\to E$ を計算する関数 <code>E merge(E a, E b)</code>
- $e$ を返す関数 <code>E e()</code>
- 辺番号 $i$ の辺を付加する関数 <code>E put_edge(V x, int i)</code>
- 頂点番号 $v$ の頂点を付加する関数 <code>V put_vertex(E x, int v)</code>

を定義する必要があります。

- 頂点数 <code>n</code> の木を作る準備をします。<code>n</code> 頂点 $0$ 辺のグラフを作ります。
- デフォルトでは <code>n = 0</code> です。
  
#### 制約

- $0\le n\le 10^8$

#### 計算量
- $\mathrm{O}(n)$

### add_edge

```
void g.add_edge(int u, int v, int idx1, int idx2)
```

- 頂点 <code>u</code> から頂点 <code>v</code> への辺番号が <code>idx1</code> である辺を追加します。
- 頂点 <code>v</code> から頂点 <code>u</code> への辺番号が <code>idx2</code> である辺を追加します。
  
#### 制約

- $0\le u,v\lt n$
- ちょうど $n-1$ 回 <code>add_edge</code> を呼んでできるグラフは連結（どの $2$ 頂点間にもパスが存在する）であり、その後 <code>add_edge</code> は呼ばれない。

#### 計算量

- ならし $\mathrm{O}(1)$

### build

```
vector<V> g.build(int r)
```

- 長さ $n$ の配列 <code>subdp</code> を返します。<code>subdp[v]</code> は上述した問題における <code>dfs(r,r)</code> を計算する過程で `dfs` が返す値 `dfs(r,v)` です。
- 頂点 `r` を根とする木DPのすべての結果を取得することができます。
  
#### 制約

- <code>build</code> を呼ぶ前にちょうど $n-1$ 回 <code>add_edge</code> を呼んでいる。
- <code>build</code> は $1$ 回までしか呼ばれない。

#### 計算量

- $\mathrm{O}(n)$

### reroot

```
vector<V> g.reroot()
```

- 長さ $n$ の配列 <code>answers</code> を返します。<code>answers[v]</code> は上述した問題における <code>dfs(v,v)</code> です。
  
#### 制約

- <code>reroot</code> を呼ぶ前にちょうど $1$ 回 <code>bulid</code> を呼んでいる。
- <code>reroot</code> は $1$ 回までしか呼ばれない。

#### 計算量

- $\mathrm{O}(n)$
  
### get

```
V get g.get(int r, int v)
```

- 上述した問題における <code>dfs(r,r)</code> を計算する過程で `dfs` が返す値 `dfs(r,v)` を返します。
- 頂点 `r` を根とする木DPをしたときの頂点 `v` の部分木に対するDPの値を得ることができます。

#### 制約

- `get` を呼ぶ前にちょうど $1$ 回 `reroot` を呼んでいる。

#### 計算量

- $\mathrm{O}(\log n)$
  
### 使用例

AC code of https://atcoder.jp/contests/dp/tasks/dp_v

submission https://atcoder.jp/contests/dp/submissions/36003936

``` cpp
#include<bits/stdc++.h>
#include<atcoder/modint>
using namespace std;
using mint = atcoder::modint;

#include"RerootingDP"

mint merge(mint a, mint b){
    return a * b;
}
mint e(){
    return mint(1);
}
mint put_edge(mint v, int i){
    return v + 1;
}
mint put_vertex(mint e, int v){
    return e;
}

int main(){
    int n, m; cin >> n >> m;
    mint::set_mod(m);
    RerootingDP<mint,mint,merge,e,put_edge,put_vertex> g(n);
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g.add_edge(u-1,v-1,i,i);
    }
    g.build();
    for (auto ans : g.reroot()) cout << ans.val() << endl;
}
```

## 設計の意図

全方位木DPはすべての部分木 $t$ に対する答え $dp(t)$ を高速に求めるアルゴリズムで、 $t$ に含まれるさらに小さい部分木 $s$ に対する答え $dp(s)$ から $dp(t)$ を計算していきます。 $r$ を全体の根としたときの木DPの値を求める際、$v$ の部分木を有向辺 $(par(v),v)$ に対応させると理解しやすい、という話があります。（ $par(v)$ は $r$ を根としたときの $v$ の親です。 $v=r$ のときは $par(v)$ は仮想的な頂点であり、有向辺 $(par(v),v)$ は仮想的な辺です。 ）これに基づいて、有向辺 $(u,v)$ に対応する答えを $f(u,v)$ と書くことにしましょう。 $u=-1$ のときは仮想的な有向辺を考えており、対応する部分木は $v$ を根とする根付き木です。さて、このライブラリの設計では、

$$
f(u,v)=\bigoplus_{c\in \mathrm{child}(u,v)}f(v,c)
$$

のような遷移式では考慮されない「辺の重み」を取り入れるため、補助的な関数 $g(u,v)$ を定義しています。 $g(u,v)$ は $(u,v)$ に対応する部分木に辺 $(u,v)$ を付加するが頂点 $u$ はまだ付加しないみたいな（雰囲気で感じ取ってください）部分木もどきに対する答えっぽいもの（雰囲気で感じ取ってください）です。要点は次のとおりです。

- 部分木に辺を付加すると、部分木もどきになる。( $\mathrm{put \\_ edge}$ )
- 部分木もどきをマージして頂点を付加すると、部分木になる。( $\mathrm{put \\_ vertex}$ )
- $\displaystyle f(u,v)=\mathrm{put \_ vertex}\left(\bigoplus_{c\in \mathrm{child}(u,v)} \mathrm{put \_ edge}(f(v,c),\mathrm{idx}(v,c)) ,\ v\right)$

ライブラリ内で辺に重み <code>E e</code> 、頂点に重み <code>V v</code> を持つような設計もあり得ると思ったのですが、できるだけライブラリの外側で問題依存パートを扱いたいのと、 <code>put_vertex</code> には単位元のようなものを要求しないため初期値の設定に困ったので、頂点・辺番号を引数に渡す関数を要求するライブラリの設計にしました。

(追記) 全方位木DPが扱える根付き木は全域木だけではなく、$3n-2$ 個ある全ての根付き部分木である。その全ての部分木に対応するDPの結果を返す `get` を実装した。