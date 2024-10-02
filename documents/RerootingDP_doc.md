---
title: Rerooting DP
documentation_of: //tree/rerootingdp.hpp
---

## RerootingDP

木に対して全方位木DPを行います。次の問題を解きます。

> 頂点 $0,1,\dots,n-1$ からなる $n$ 頂点の木 $T$ が与えられます。木の辺は双方向に有向辺が張られていると考え、辺には識別番号がついているものとします。**ただし、実装の簡単のため、辺の識別番号を `i` とするとき逆辺にの識別番号は `~i` であるとします。**
> 
> 木の入力を受け取る C++ 疑似コード を以下に示します。
> ```cpp
> int n; std::cin >> n;
> std::vector<std::vector<std::pair<int, int>>> g(n);
> for (int i = 0; i < n-1; i++){
>     int u, v; std::cin >> u >> v;
>     g[u].emplace_back(v, i);
>     g[v].emplace_back(u, ~i);
> }
> ```
>
> 計算対象のデータの値の集合を $V$ 、マージのための中間データの値の集合を $E$ とします。また、頂点番号の集合を $\mathbb{V}$ 、識別番号の集合を $\mathbb{I}$ とします。
> 
> **可換**モノイド $(E,\text{op} : E\times E\to E,e\in E)$ と集合 $V$ および $\mathrm{put \_ edge}:V\times \mathbb{I}\to E,\ \mathrm{put \_ vertex}:E\times \mathbb{V}\to V$ が与えられます。次の C++ 擬似コードに従って計算される値 <code>dfs(0, 0), dfs(1, 1),...,dfs(n-1, n-1)</code> を求めてください。
> ```cpp
> V dfs(int r, int v, int parv = -1){
>     E prod = e;
>     for (auto [c, i] : g[v]){
>         if (c == parv) continue;
>         prod = op(prod, put_edge(dfs(r, c, v), i));
>     }
>     return put_vertex(prod, v);
> }
> ```

この問題を時間計算量 $\mathrm{O}(n)$ で解くことができます。

また、このライブラリはオラクルとして `op, put_edge, put_vertex` を使用しますが、これらが定数時間で動くものと仮定したときの計算量を記述します。オラクル内部の計算量が $\mathrm{O}(f(n))$ である場合はすべての計算量が $\mathrm{O}(f(n))$ 倍となります。

### 関数

```
auto dp = rerootingdp<V, E>(op, e, put_edge, put_vertex, g, root = 0);
```

- 計算対象のデータの値の型 `V`
- 中間データの値の型（可換モノイドの型）`E`
- $\text{op} : E\times E\to E$ を計算する関数 `E op(E a, E b)`
- モノイドの単位元である型 `E` の値 `e`
- 識別番号 $i$ の辺を付加する関数 `E put_edge(V x, int i)`
- 頂点番号 $v$ の頂点を付加する関数 `V put_vertex(E x, int v)`
- 木を有向グラフで表した二次元配列 `std::vector<std::vector<std::pair<int, int>>> g`
- 木を根付き木にするときの根 `int root = 0` （デフォルトで $0$ ）

を定義する必要があります。

正確な言い方ではないですが、 `op, put_edge, put_vertex` は関数のように振る舞うことができれば良いです。具体的には、次のようなものを指定できます。

- グローバルに定義した関数（関数ポインタ）
- ラムダ式
- 関数オブジェクト（ `operator()` を実装している ）

#### 制約

- $1\le n\le 10^8$ ( assert が入っているわけではありません)

#### 計算量
- $\mathrm{O}(n)$

### 返り値

返り値の型は `rerootingdp<V, E>` 内で定義される `dp` です。 `auto` で受け取ってください。

`dp` は木DPの結果を返す関数オブジェクトとして機能します。`dp(r, v)` として、疑似コード中の `dfs(r, r)` を計算する過程で `dfs(r, v, parv)` として返る値を得ることができます。

```cpp
auto dp = rerootingdp<V, E>(op, e, put_edge, put_vertex, g);
V dprv = dp(r, v);
```

すなわち、 `dp` は $r$ を根としたときの部分木 $v$ の木DPの値を返す関数です。この関数は $v$ の次数を $d$ として $\mathrm{O}(\log d)$ 時間で動作します。ただし $r=v$ のときは $\Theta(1)$ 時間で動作します。

  
### 使用例

AC code of https://atcoder.jp/contests/dp/tasks/dp_v

submission https://atcoder.jp/contests/dp/submissions/58347464

``` cpp
#include<bits/stdc++.h>
#include<atcoder/modint>
#include"rerootingdp.hpp"

int main(){
    int n, m; std::cin >> n >> m;
    using mint = atcoder::modint;
    mint::set_mod(m);
    std::vector<std::vector<std::pair<int,int>>> g(n);
    for (int i = 0; i < n-1; i++){
        int u, v; std::cin >> u >> v; u--, v--;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, ~i);
    }
    auto op = [&](mint a, mint b){
        return a * b;
    };
    auto pute = [&](mint a, int){
        return a + 1;
    };
    auto putv = [&](mint a, int){
        return a;
    };
    auto dp = rerootingdp<mint,mint>(op,1,pute,putv,g);
    for (int v = 0; v < n; v++){
        std::cout << dp(v, v).val() << '\n';
    }
}
```

計算結果が木の形状のみに依存し、特に頂点や辺の重みを考慮しないものである場合、 `put_edge` や `put_vertex` の番号を表す引数は使用しないことになります。その場合でも引数として受け取るようにする必要がありますが、使わないことを明示する場合は、実装例のように型のみを書いて変数名を書かないという方法があります。

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