---
title: Heavy Light Decomposition
documentation_of: //tree/heavy_light_decomposition.hpp
---

# Heavy Light Decomposition

HLD のライブラリです。時空間にかなり気を遣って実装していますが、一般的な実装では通らないがこのライブラリを使うと通るような問題はないかもしれません。HLD 自体にあまり関係のないメンバ関数については書いていません（標準入力からの木の入力、CSR の構築など）。

## (constructor)

```cpp
hld_tree (); // (1)
hld_tree (int n, int root = 0); // (2)
hld_tree (const std::vector<int> &par); // (3)
hld_tree (std::vector<int> &&par); // (4)
```

- (1) : デフォルトコンストラクタ。 $0$ 頂点の木として機能するわけではない。
- (2) : 根を `root` とする、 `n` 頂点の根付き木を宣言する。辺の追加は後述する `add_edge` で行う。
  - `n >= 1`
- (3),(4) : 親配列を `par` とする `par.size()` 頂点の根付き木を構築する。
  - `par[0] == -1` : 根の頂点番号は `0` である。
  - `par[i] < i` : 親の頂点番号は、自身の頂点番号より小さい。

### 備考

- (1) : `hld tree g; g = hld_tree(n);` などとして代入されることを想定している。
- (2) : コンストラクタ内では構築は行われない。`add_edge(int u, int v)` を合計 $n-1$ 回呼び出すことで構築する。明示的な構築のタイミングの指示を行うことはなく、最後の辺が追加されたタイミングで構築が行われる。**構築が行われるまで、** `add_edge` **以外のいかなるメンバ関数も呼び出してはならない。**

## `add_edge`

```cpp
void add_edge(int u, int v);
```

- 頂点 `u, v` を結ぶ（無向）辺を追加する。
  - $n-1$ 回呼び出された後、グラフは木をなす。
  - $n$ 回以上呼び出されない。

### 計算量

- $n-1$ 回目の呼び出しは $O(n)$ 時間。
- それ以外は定数時間。

### 備考

- $n-1$ 回目の呼び出しの際に構築を行う。例外として $n=1$ のときは呼び出しは行われないのでコンストラクタ (2) 内で `build_from_parents()` が呼び出される。そうでないときは `build_from_edges()` を呼び出す。


## `leader`

```cpp
int leader(int v) const ;
```

- 頂点 `v` を含む heavy-path に含まれる最も浅い頂点の番号を返す。

### 計算量

- 定数時間

## `la`

```cpp
int la(int v, int d) const ;
```

- 頂点 `v` から `d` だけ親を辿った先の頂点の番号を返す。`d` が頂点 `v` の深さを超える場合は `-1` を返す。
  - `d >= 0`

### 計算量

- $O(\log n)$ 時間

## `lca`

```cpp
int lca(int u, int v) const ;
```

- 頂点 `u, v` の最小共通祖先の頂点番号を返す。

### 計算量

- $O(\log n)$ 時間

## `dist`

```cpp
int dist(int u, int v) const ;
```

- 頂点 `u, v` の距離を求める。距離は `u - v` 単純パスに含まれる辺の個数とも言い換えられる。

### 計算量

- $O(\log n)$ 時間
- 返り値を $d$ として $O(d)$ とも評価できる。

## `jump`

```cpp
int jump(int from, int to, int d) const ;
```

- 頂点 `from` から頂点 `to` に向かう方向に `d` 回辺を辿った先の頂点の番号を返す。`d` が頂点 `from, to` の距離を超える場合は `-1` を返す。
  - `d >= 0`

### 計算量

- $O(\log n)$ 時間

## `parent`

```cpp
int parent(int v) const ;
```

- 頂点 `v` の親の頂点番号を返す。 `v` が根のときは `-1` を返す。

### 計算量

- 定数時間

## `index`

```cpp
int index(int vertex) const ; // (1)
int index_edge(int vertex1, int vertex2) const ; // (2)
```

- (1) : パス分解したときの頂点 `vertex` の位置を返す。
- (2) : パス分解したときの頂点 `vertex1, vertex2` を結ぶ辺の位置を返す。その辺の子側の端点に関する `index` に一致する。
  - 頂点 `vertex1, vertex2` を結ぶ辺が存在する。

### 計算量

- 定数時間

### 備考

- (1) : たとえば `segtree seg` で頂点重みのパスクエリを処理するには、頂点 `v` の値は `seg` の位置 `index(v)` に置く。
  - `seg.set(index(v), X[v]);`
- (2) : たとえば `segtree seg` で辺重みのパスクエリを処理するには、辺 `e = (u, v)` の値は `seg` の位置 `index(u, v)` に置く。
  - `seg.set(index(u, v), X[e]);`

## `subtree_size`

```cpp
int subtree_size(int v) const ;
```

- 頂点 `v` を根とする部分木の大きさ（含まれる頂点数）を返す。

### 計算量

- 定数時間

## `subtree_l`

```cpp
int subtree_l(int v) const ;
```

- パス分解した時に、頂点 `v` を根とする部分木に対応する閉開区間の左端の位置を返す。

### 計算量

- 定数時間

## `subtree_r`

```cpp
int subtree_r(int v) const ;
```

- パス分解した時に、頂点 `v` を根とする部分木に対応する閉開区間の右端の位置を返す。

### 計算量

- 定数時間

### 備考

- たとえば `segtree seg` で頂点重みの部分木クエリを処理するには、頂点 `v` を根とする部分木の答えを `seg.prod(subtree_l(v), subtree_r(v))` で取得する。

## `is_in_subtree`

```cpp
bool is_in_subtree(int r, int v) const ;
```

- 頂点 `r` を根とする部分木に頂点 `v` が含まれるかどうかを判定する。特に、 `r == v` のときは `true` を返す。

### 計算量

- 定数時間

## `dist_table`

```cpp
std::vector<int> dist_table(int s) const ;
```

- 頂点 `s` からの各頂点への距離を格納した長さ `n` の配列を返す。

### 計算量

- $O(n)$ 時間

### 備考

- 深さの配列は `dist_table(root)` で得ることができる。なお、本ライブラリには、頂点を受け取って深さを返す関数は存在しない。

## `diameter`

```cpp
std::tuple<int, int, int> diameter() const ;
```

- 木の直径 `d` と直径の両端点のひとつ `v1, v2` をタプル `{d, v1, v2}` として返す。

### 計算量

- $O(n)$ 時間

## `path`

```cpp
std::vector<int> path(int from, int to) const ;
```

- 頂点 `from` から頂点 `to` へ向かうパスに含まれる頂点を順に格納した配列を返す。

### 計算量

- パスに含まれる頂点数を $c$ として $O(c)$ 時間。

### 備考

- 実装では `std::vector<int>` の `reserve` を行うために `dist(from, to)` を呼び出している。この部分にかかる計算量は $O(c)$ である。

## `path_query`

```cpp
template<bool vertex = true>
void path_query(int u, int v, auto f) const ;
```

- `u - v` 単純パスを区間に分解し、区間を処理する関数 `void f(int l, int r)` を呼び出す。
- `vertex == true` のときは、すべての**頂点**が含まれるように区間をとる。
- `vertex == false` のときは、すべての**辺**が含まれるように区間をとる。
  - すべての辺は、その子側の端点が対応することになっている。したがって、パスに含まれる `lca(u,v)` を除いた頂点がすべて含まれる。
- 呼び出しの詳細な規定は備考を確認のこと。

### 計算量

- `f` の呼び出しを除けば $O(\log n)$ 時間。また、 `f` の呼び出し回数は $O(\log n)$ 回である。

### 備考

- `int l = lca(u, v)` とする。 `u - v` 単純パスは `u - ul` 上昇パスと `vl - v` 下降パスに分解される。`vertex == true` のときはいずれか一方のみが `l` を含み、 `false` のときはいずれも `l` を含まない。各パスを、パス分解したときの頂点列 `tour` （ euler tour 順）上の区間の非交和として表す。ただし上昇パスは向きが逆になる。
- 上昇パスが `path(u, ul) = tour(l1, r1] ++ tour(l2, r2] ++ ...` と分解するとする。ただし `l_ > r_` （逆向きの閉開区間）。これらの区間の中では、`1,2,...` の順に `f` が呼び出される。
- 下降パスが `path(vl, v) = tour[l1, r1) ++ tour[l2, r2) ++ ...` と分解するとする。ただし `l_ < r_` （順向きの閉開区間）。これらの区間の中では、`...,2,1` の順に `f` が呼び出される。
  
よくある使い方を示す。

#### 非可換クエリ

モノイド $(S,\oplus,e)$ が非可換のときを扱う。

列に向きがあるため、一般のモノイド $(S,\oplus,e)$ に対して、列を逆向きにするという作用を備えたモノイド $(S\times S, \oplus', (e,e))$ を扱うことにすると良い。ここで $\oplus'$ は

$$
\oplus'((a,a'),(b,b'))=(\oplus (a,b),\oplus (b',a'))
$$

で定められる。逆向きにする作用は $(a, b) \mapsto (b, a)$ である。

以下では `S,op,e` が $(S\times S, \oplus', (e,e))$ に、 `reversed` が逆向きにする作用に対応している。

`l, r` の大小関係で向きの判定を行い、左右からの累積を持っておくと良い。

```cpp
hld_tree g;
segtree<S,op,e> seg;
S sml = e(), smr = e();
auto f = [&](int l, int r){
    if (l < r){
        smr = op(seg.prod(l,r), smr);
    }
    else {
        sml = op(sml, reversed(seg.prod(r,l)));
    }
};
g.path_query(u, v, f);
S ans = op(sml, smr);
```

なお、順向きのものだけ取り出すには $(a,b)\mapsto a$ を適用すると良い。

#### 可換クエリ

簡単のためパス上の辺に書かれた整数の総和を扱うことにする。

可換なので、左右や逆向きの区別は必要ない。この場合でも `l > r` となるものが与えられることに注意せよ。

```cpp
hld_tree g;
fenwick_tree<int> fen;
int ans = 0;
auto f = [&](int l, int r){
    if (l > r) std::swap(l, r);
    ans += fen.sum(l, r);
};
g.path_query<false>(u, v, f);
// ans is calculated
```

なお、頂点重みにするには、単に `<false>` を `<true>` に書き換えればよい。あるいは `<false>` を消してしまっても良い（デフォルトで `vertex = true` である）。

## `compressed_tree`

```cpp
std::pair<std::vector<int>, std::vector<int>> compressed_tree(std::vector<int> vs) const ;
```

- `vs` に含まれる頂点たちが誘導する圧縮木（Compressed Tree）（補助木 Auxiliary Tree）を計算し、親配列と元の木との対応関係を表す配列のペアを返す。詳細は備考を確認のこと。
- ここでの圧縮木とは、`vs` に含まれる頂点を消さないという条件下で、元の木の次数 $1$ の頂点を取り除くことと次数 $2$ の頂点の縮約を繰り返して得られる新しい木のことである。ただし、計算された圧縮木の最も浅い頂点は縮約されないことがある。
- `vs` には重複があってもよい。
- `vs` が空のときは空配列の組を返す。

### 計算量

- `vs` の長さを $c$ として $O(c\log c)$ 時間。

### 備考

- 得られた圧縮木の頂点数を $k$ とする。圧縮木の頂点番号を $[0,k)$ に振り直す。返り値を `{par, mapping}` とすると
  - `par[0] == -1` : 圧縮木において根の頂点番号は `0` である。
  - 圧縮木において頂点 $i$ の親の頂点番号が `par[i]`。
  - 圧縮機における頂点 $i$ は、元の木の頂点 `mapping[i]` に対応する。
  
  また、頂点番号の大小関係は元の木での euler tour 順の大小関係と対応する。
  - `0 <= i < j < k` ならば `index(mapping[i]) < index(mapping[j])`
  
  したがって、親配列は `par[i] < i, par[0] == -1` を満たし、そのまま `hld_tree` のコンストラクタに投げることができる。

- `vs` の圧縮木に含まれる頂点は、 `vs` に含まれる任意の $2$ 点の LCA すべてに渡る。先に述べた手続きで得られる圧縮木は、LCA のうち最も浅い頂点を縮約することがある。たとえば $3$ 頂点の木で、葉でない唯一の頂点を根とし $2$ つの葉を `vs` とたケースでは、圧縮木には根は含まれないはずであるが、本関数は根を含める。これは、圧縮木を元の木と向きを同じくする根付き木として扱うためである。なお、最も浅い頂点以外の LCA が手続きで縮約されることはないことが証明される。

# 省メモリで爆速な HLD のための工夫

木の頂点数を $n$ とする。

## 本ライブラリの利点

- 使用メモリは `int` を $4n +$ 定数個
- 構築が（本質的に）非再帰
- $O(\log n)$ 時間で動作する関数が高速に動作する

## 本ライブラリの欠点

- 木の深さの取得が $\Omega(\log n)$ 時間
- 隣接リストを保持しない
- 親配列を保持せず、`parent` の取得に配列へのランダムアクセスが $3$ 回かかる

## 本ライブラリが目指したもの

非常に高速に動作する HLD を用いて、木の基本的なクエリを処理することを目指した。

多くの場合は例えば親の取得やパスの復元がボトルネックになることはない。必要な空間に対して線形の時間で取得するものは、高速にするメリットがあまりない（それでも、時空間に気を遣って実装してある）。一方、LCA, LA, jump, dist などは部分問題によく登場する割に、二分探索内でクエリを飛ばすなどして、呼び出しにかかる $\log$ が $2$ つ目の $\log$ になることも多い。したがって、そのようなクエリに対しては高速な実装を提供したい、という動機があった。

また、HLD の構築は、線形時空間にしては重い。`depth, sub_size, in_time, out_time, heavy_path_top, adjacent_list, euler_tour, ...` （変数名で意図がわかるようにしているつもり） 持っておいて損がないようなものはたくさんあるが、無駄が多い。Library Checker 上の実装やインターネット上に存在する実装を見ても、平均して $8n$ くらいの空間を使用しているようだ（要出典）。空間の重さは時間の重さに直結する。同等の計算回数で達成できるなら、空間を抑えた方がキャッシュが効きやすく、高速に動作する。配列へのランダムアクセスの回数を抑えることも効果的である。

## 非再帰 euler tour

根付き木 $T$ 上の euler tour を考える。根を $r$ とする。

euler tour で得る配列 `down` は、euler tour で頂点 `v` を訪れる時刻が `down[v]` であることを表す。教科書的な方法は以下の通り。子配列を `child[v]` とする。

```cpp
std::vector<std::vector<int>> child;
std::vector<int> down(n);
int t = 0;
auto dfs = [&](auto self, int v) -> void {
    down[v] = t++;
    for (int u : child[v]){
        self(self, u);
    }
};
dfs(dfs,r);
```

この方法は深さ $O(n)$ の再帰呼び出しが行われる上、二次元配列 `child` へのアクセスも含み、低速である。（それでも、通常は無視できるほど高速に動作する）

この方法は top-down に時刻を決定するため、再帰呼び出しを回避しやすい bottom-up への書き換えが難しい。

この問題を巧妙に解消しているのが次の実装である。 $T$ の親配列を `par` 、任意の topological order を `ord` とする。ここで topological order とは、任意の頂点がその親よりも後に現れるような、すべての頂点の順列である。また、 `std::exchange(int &a, int b)` は `a` に `b` を代入し、元の `a` を返す関数である。

```cpp
std::vector<int> down(n);
for (int v : ord | std::views::drop(1) | std::views::reverse){
    down[par[v]] += down[v] + 1;
}
for (int v : ord | std::views::drop(1)){
    down[v] = std::exchange(down[par[v]], down[par[v]] - down[v] - 1);
}
```

$1$ つ目の for 文の直後では、 `down` には部分木サイズ $-1$ が格納されている。これを、次のように読み替える： `v` から euler tour を始めたとき、最後に訪れる頂点の時刻が `down[v]` である。

$2$ つ目の for 文では、次の解釈に従って値を変更する： `par[v]` から euler tour を始めるとして、 `par[v]` の子のうち `v` には最後に潜るとし、`par[v]` から `v` を切り離す。最後の時刻を親から引き継ぎ、親の持つ最後の時刻から自身の部分木サイズを減じるのである。

結局は bottom-up に部分木サイズを求め、top-down に euler tour の時刻を求めているだけである。ただし、euler tour の順に頂点 `v` を訪れているわけではないことに注意せよ。

さて、よくある根付き木の入力として、親配列が `par[i] < i` を満たすように与えられることがある。このとき、 `ord` として $(0,1,\dots ,n-1)$ を取ることができ、 `par` へのアクセスがシーケンシャルになると同時に `ord` の保持の必要がなくなる。このときは非常に高速に動作する。

```cpp
std::vector<int> down(n);
for (int v = n - 1; v >= 1; v--){
    down[par[v]] += down[v] + 1;
}
for (int v = 1; v < n; v++){
    down[v] = std::exchange(down[par[v]], down[par[v]] - down[v] - 1);
}
```

## 辺配列から親配列と topological order を取得

辺が親へ向かう有向辺であるなら、葉から切り離していく要領で簡単に計算できる。問題になるのは、よくある木の入力として与えられるような、辺の端点に順序のない場合である。

教科書的な方法は、隣接リストを作り、再帰呼び出しを行なって euler tour する方法である。しかしこれは低速なので、別の方法を用いる。

有向辺のときと同様に次数を管理しながら実装できる。葉をキューに入れて実装するのが普通だが、キューに入る順番がそのまま topological order の逆順になるため、キューを配列で模倣して実装する。

辺配列を `std::vector<std::pair<int, int>> edges` とする。

```cpp
std::vector<int> deg(n), par(n), ord(n);
for (auto [u, v] : edges){
    deg[u]++;
    deg[v]++;
    par[u] ^= v;
    par[v] ^= u;
}
int back = 0;
for (int v = 0; v < n; v++){
    if (deg[v] == 1){
        ord[back++] = v;
    }
}
for (int front = 0; front < n-1; front++){
    int v = ord[front];
    par[par[v]] ^= v;
    if (--deg[par[v]] == 1){
        ord[back++] = par[v];
    }
}
int root = ord[n - 1];
par[root] = -1;
std::ranges::reverse(ord);
```

この実装は $n=1$ のときも正しく動作する。

重要な点は `par` を、隣接する頂点の番号の総 XOR にしていることである。葉を切り離していく際に `deg` に加えて `par` も更新することで、 `v` が葉になって以降は `par[v]` が親の番号となる。

この実装は木の根が後から定まるが、根を前もって決定したい場合はキューに最後まで入れないようにすれば良い。

また、 `edges` の保持は、現実的には全く必要ないこともわかる。辺 `u,v` の追加のタイミングで `deg[u],deg[v],par[u],par[v]` を書き換えれば良いし、その後必要になることはない。（辺配列は親配列から簡単に得ることができる。）

ここからさらに euler tour までしたい場合は、 `for (int front ...)`  の内部で部分木サイズまで計算することができ、追加の for 文は $1$ 回で済む。

## 省メモリのための戦略

本ライブラリは次の $4$ つの長さ $n$ の `std::vector<int>` を保持する。

- `down` : euler tour で頂点 `v` を訪れる時刻が `down[v]`
- `nxt` : 頂点 `v` を含む heavy path の最も浅い頂点が `nxt[v]` 、ただしそれが `v` 自身である場合は `v` の親が `~nxt[v]`
- `sub` : 頂点 `v` を根とする部分木サイズが `sub[v]`
- `tour` : `down` の逆順列、すなわち euler tour で時刻 `t` に訪れる頂点が `tour[t]`

HLD の主な目的を、パスクエリを処理すること、LCA を求めることとする。このときに必要なのは `down, nxt` のみである。

```cpp
int leader(int v){
    return nxt[v] < 0 ? v : nxt[v];
}
int lca(int u, int v){
    while (leader(u) != leader(v)){
        if (down[u] > down[v]) std::swap(u, v);
        v = ~nxt[leader(v)];
    }
    return down[u] < down[v] ? u : v;
}
void path_query(int u, int v, auto f){
    while (leader(u) != leader(v)){
        if (down[u] < down[v]){
            f(down[leader(v)], down[v] + 1);
            v = ~nxt[leader(v)];
        }
        else {
            f(down[u] + 1, down[leader(u)]);
            u = ~nxt[leader(u)];
        }
    }
    if (down[u] < down[v]){
        f(down[u], down[v] + 1);
    }
    else {
        f(down[u] + 1, down[v]);
    }
}
```

`down, nxt` のみで処理できる主なクエリは次のとおり。

- パスクエリ（ `u - v` パスの分解）： $O(\log n)$ 時間
- LCA クエリ： $O(\log n)$ 時間
- 距離クエリ： $O(\log n)$ 時間
- 深さクエリ： $O(\log n)$ 時間
- 親配列（木構造）の復元： $O(n)$ 時空間

これだけでも十分に見えるが、HLD の前計算（構築）はより多くの空間を必要とする。

親配列から HLD を行って `down, nxt` を得るには、追加で長さ $n$ の `std::vector<int>` が必要に見える。（相当な時間を費やしたが、追加の空間を $o(n)$ にする方法は思いつかなかった。）素直な方法では、追加で使用した配列は `sub` に相当するものを格納することになる。よって、はじめから保持しておき、より広いクエリに対処することにした。

`down, nxt, sub` で新たに処理できる主なクエリは次のとおり。

- 部分木クエリ（ `v` を根とする部分木の範囲の取得）：定数時間
- 部分木に含まれているかの判定クエリ：定数時間

辺配列からの構築を行う際には、さらに追加で長さ $n$ の `std::vector<int>` が必要に見える。追加で LA, jump クエリを処理することを考えると、 `down` の逆順列を持つのが都合が良い。そこで `tour` も保持することにした。

`down, nxt, sub, tour` で新たに処理できる主なクエリは次のとおり。

- LA クエリ： $O(\log n)$ 時間
- jump クエリ： $O(\log n)$ 時間
- 親クエリ： 定数時間
- パス復元クエリ： パスの長さの線形時間

教科書的な HLD の実装では親配列をそのまま保持することが多い（要出典）。親配列から HLD を行う場合はなおさらである。本ライブラリは親配列を保持しないが、次のように実装できる。

```cpp
int parent(int v){
    return nxt[v] < 0 ? ~nxt[v] : tour[down[v] - 1];
}
```

heavy path 上では `down` の値が連続していることに注目すると、正当性が確認できる。

## 爆速な LCA

本ライブラリの実装は次のとおり。

```cpp
int lca(int u, int v) const {
    int du = down[u], dv = down[v];
    if (du > dv){
        std::swap(du, dv);
        std::swap(u, v);
    }
    if (dv < du + sub[u]){
        return u;
    }
    while (du < dv){
        v = ~nxt[leader(v)];
        dv = down[v];
    }
    return v;
}
```

この実装の正当性の確認の前に、LCA クエリの基本的な処理方法について確認する。

`nxt2` を `nxt` のよくある定義に置き換えたバージョンとして次のように定義する。

- 頂点 `v` を含む heavy path の最も浅い頂点が `nxt2[v]`

`down, nxt2` に加えて親配列 `par` と深さ配列 `dep` を保持したときの教科書的な LCA の実装は次のとおり：

```cpp
int lca(int u, int v){
    while (nxt2[u] != nxt2[v]){
        if (down[u] > down[v]) std::swap(u, v);
        v = par[nxt2[v]];
    }
    return dep[u] < dep[v] ? u : v;
}
```

この実装は、アクセスしている配列の種類が多すぎる。

次の点に注目せよ。

- 同じ heavy path に含まれる頂点 `u, v` について、 `dep` の大小と `down` の大小は一致する
- `par` へのアクセスは、heavy path の最も浅い頂点のみから行われる

`nxt2` の情報を完全に保持しながら `par` へのアクセスに応えたものが本ライブラリの `nxt` である。 `nxt2[v]` は `leader(v)` として得ることができる。

ここまでの工夫で得られる実装が **省メモリのための戦略** に載せたものである。

さらに次の点に注目せよ。

- heavy path どうしもまた木構造を成す、この木を $H$ と書く
- heavy path 上では `down` の値が連続しており、 `down` は $H$ においても euler tour での時刻に関する大小関係を持つ
- 一方が他方の祖先であるときの答えは定数時間で計算できる
  - ので、以下はこの場合を考えない
- `u` が `v` の祖先である $\implies$ `down[u] <= down[v]`
  - この対偶が正当性を保証する

次の疑似コードによる最も基礎的な実装の正当性を確認せよ。

```
int lca(int u, int v){
    if u が v の祖先 : return u
    while v が u の祖先でない {
        v = par[v]
    }
    return v
}
```

これを模倣したものが本ライブラリの実装である。

実は、教科書的な実装において `swap` が発生するのは高々 $2$ 回である。`down[u] < down[v]` とすれば、まず `v` が `lca(u,v)` まで登り、次に `u` が `v` に代わって登っていただけだ。これを用いれば `if, swap` を取り除くことができ、`while` の内部はずっと単純になる。また、 `u` が登らなくて良くなったため、通常の実装と単純に比較して、約半分程度の計算で済むようになる。

その代わりに `sub` を必要とすることに注意せよ。はじめに祖先の判定を行わなかった場合、`v` は `lca(u,v)` を通り過ぎてしまう。

LCA クエリを処理するだけなら、 `nxt` を次の `nxt3` に置き換えれば良い。

- `nxt3[v] := ~nxt[leader(v)]`

なお、この工夫は heavy path の端点を失うため、パスクエリとは共存しない。

## 爆速な HLD

euler tour の時刻 `down` を非再帰で取得する方法を紹介した。本ライブラリでは、実装の都合上、少し異なる方法で行っている：

- 最後の時刻を保持し、最後に潜るとして子を切り離す

のではなく、

- 本来の時刻と次に潜る子の最初の時刻を保持し、最初に潜るとして子を切り離す

としている。

先に紹介したものは、子に潜る順番に制約がなかった。しかし、HLD では最もサイズの大きい部分木を持つ子にはじめに潜る必要がある[1]。よって、部分木サイズの最大値を保持する必要がある。

親配列 `nxt` から `down, nxt, sub, tour` を行うために for 文を $4$ 回まわしている。

1. 部分木サイズ `sub` と、子の部分木サイズの最大値 `down` の計算
2. 自身が親の heavy child であるかの判定
3. `sub` を用いた `down` と `nxt` の構築
4. `tour` を `down` の逆順列であるとして計算

辺配列からは for 文を $7$ 回まわしている。

1. 次数 `down` と隣接頂点の総 XOR `nxt` の計算
2. 次数 $1$ の頂点をキュー `tour` に入れる
3. 次数 $1$ の頂点を切り離しながら親配列 `nxt` と topological order `tour` を取得
4. 以降は親配列からの構築と同じ

ここにはもう少し工夫の余地があると思っているが、特に思いつかなかった。

[1]: 従来と同様の計算量解析を行うためには、自身の部分木サイズの半分以上の部分木サイズを持つ子がいた場合に、その子にはじめに潜る必要があるだけである。