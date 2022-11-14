# 競プロのお勉強で得た知見たち

## データ構造

## アルゴリズム

### 葉から順に頂点を削除していくタイプの走査をBFSの逆順でするやつ

根から

## 典型

### 最大値の最大値(最小値の最小値)

#### 例題 1

> 長さ $N$ の正整数列 $A$ が与えられる。 $\displaystyle\max _{i\neq j}\gcd (A_i,A_j)$ を求めよ。
> 
> $N\le 10^5, A_i\le 10^5$
> 
> 出典 : [SSRSさんのツイート](https://twitter.com/ssrs_cp/status/1522647820167434241?s=21&t=qi6eevuz2v0kYyrzy94Z3Q)

<details><summary>略解</summary>

$\displaystyle\gcd (A_i,A_j)=\max _{d|A_i\land d|A_j} d$ であるから、 $\displaystyle\max _{i\neq j}\max _{d|A_i\land d|A_j} d$ を求めれば良い。これは次のように表せる。
$$\max _{\exists i,j(i\neq j) \mathrm{s.t.}(d|A_i\land d|A_j)} d$$
つまり、
- ある異なる $2$ つの配列の要素が存在してその最大公約数であるような数のうち最大のもの

を

- ある異なる $2$ つの配列の要素が存在してその公約数であるような数のうち最大のもの

と言い換える。
```cpp
int n; vector<int> a(n); // input
vector<int> cnt(1000001,0); // a[i] : number of multiples of i
rep(i,n) for (int d : divisor of a[i]) cnt[d]++;
int ans = 1;
rep(i,1000001) if (cnt[i] >= 2) chmax(ans,i);
out(ans); // output
```
</details>

#### 例題 2

出典を一部改題(赤字パート)


> 長さ $N$ の非負整数列 $A$ と正整数 $k$ が与えられる。 $\displaystyle\max _{i\neq j}\lbrace ij-k(A_i|A_j)\rbrace$ を求めよ。
> 
> $N\le 10^5,$ <font color="Red">$A_i\lt 2^{18},k\le 10^9$</font>
>
> 出典 : [Codeforces Round #735 (Div. 2) - B](https://codeforces.com/contest/1554/problem/B)

<details><summary>略解</summary>

非負整数を集合ともみることにして、 $x\& y=x$ のことを $x\subset y$ とかく。 $\displaystyle a|b=\min _{a\subset c \land b\subset c} c$ に注目して、例題 1 と同様に言い換える。ただし $(a|b)$ の係数が負なので、最大化が最小化に言い換えられていることに注意。

非負整数 $c$ に対して集合 $S(c)$ とスコア $f(c)$ を次のように定める。

- $S(c)=\lbrace i\ |\ A_i\subset c \rbrace$
- $f(c)=\begin{cases}
    -10^{18}\ & (\# S(c) \le 1) \\
    S(c) の要素のうち大きい方 2 つの積 & (\# S(c) \ge 2)
\end{cases}$

$c=0,1,\dots ,2^{18}-1$ について $f(c)$ を求めればその最大値が答えである。最も大きい $2$ つを保持する構造は半環になるので、 $f(c)$ の列挙は高速ゼータ変換でできる。

</details>

### 区間にXORすると区間が高々 $\mathrm{O}(\log \text{区間長})$　個に分割される

## その他

### `string` を `char` の列で初期化する

```cpp
int n = 5; char c = 'c';
string s(n,c); // s = "ccccc"
```

[](
    /<details><summary></summary></details>
)