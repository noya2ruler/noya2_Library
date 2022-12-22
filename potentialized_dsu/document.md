# 抽象化ポテンシャル付き Disjoint Set Union / potentialized_dsu

## potentialized_dsu

可換群 $(S,\oplus : S\times S\to S)$ を考えます。

Disjoint Set Union (UnionFind) は $G$ を $N$ 頂点 $0$ 辺の無向グラフからはじめ、次のクエリを処理するデータ構造でした。

- `1 u v` : 辺 $(u,v)$ を追加する。
- `2 u v` : $2$ 頂点 $u,v$ が連結かどうか判定する。

ここに、頂点集合 $V=\lbrace 1,2,\dots ,N \rbrace$ に対しポテンシャルを定める写像 $\phi : V\to S$ を考えます。辺の追加クエリではポテンシャルに関する条件も同時に与えられます。はじめは条件はありません。

- `1 u v s` : 辺 $(u,v)$ を追加する。さらに、 $\phi(u)\oplus s=\phi (v)$ を条件に追加する。 すべての条件を満たすように $\phi$ を変更する。そのような $\phi$ が存在しないとき、それを報告し、追加した条件を削除する。

さて、すべての条件を満たすような $\phi$ は一般に複数考えられますが、$s\in S, v\in V$ をひとつとって $\phi(v)=s$ という条件を加えて課せば、 $v$ の連結成分を $C$ として $u\in C$ に対して $\phi(u)$ の値は $1$ 通りに定まります。そこで、内部的に各連結成分ごとに代表となる頂点を $1$ つ持ち、その頂点の $\phi$ の値が単位元 $e$ となるようにしています。これによって $\phi$ は一意に定まります。また、辺の追加により連結成分がマージされる時、新たな代表元は元の連結成分の代表元のうちどちらかになります。


### コンストラクタ

```
potentialized_dsu<S, op, e, inv> d(int n);
```

- 可換群の型 <code>S</code>
- $\oplus : S\times S\to S$ を計算する関数 <code>S op(S a, S b)</code>
- 単位元 $e$ を返す関数 <code>S e()</code>
- $a\in S$ に対し逆元 $a^{-1}$ を返す `S inv(S a)`

を定義する必要があります。

- $n$ 頂点 $0$ 辺の無向グラフを作ります。はじめ、 $\phi(x)=e$ です。
- デフォルトでは <code>n = 0</code> です。
  
#### 制約

- $0\le n\le 10^8$

#### 計算量
- $\mathrm{O}(n)$

### merge

```
int d.merge(int a, int b, S d)
```

- 辺 $(a,b)$ を追加します。
- $a,b$ が既に連結だった場合、 $\phi(a)\oplus s=\phi(b)$ を満たすならその連結成分の代表となる頂点の番号を、満たさないなら `-1` を返します。
- 非連結だった場合 $\phi(a)\oplus s=\phi (b)$ を条件に追加します。すべての条件を満たすように $\phi$ を変更します。このときすべての条件を満たす $\phi$ が存在することが保証されます。新たに代表となった頂点の番号を返します。
  
#### 制約

- $0\le a,b\lt n$

#### 計算量

- ならし $\mathrm{O}(\alpha(n))$

### same

```
bool d.same(int a, int b)
```

- 頂点 $a, b$ が連結かどうかを返します。
  
#### 制約

- $0\le a,b\lt n$

#### 計算量

- ならし $\mathrm{O}(\alpha(n))$

### leader

```
int d.leader(int a)
```

- 頂点 $a$ が属する連結成分の代表となる頂点の番号を返します。
  
#### 制約

- $0\le a\lt n$

#### 計算量

- ならし $\mathrm{O}(\alpha(n))$

### size

```
int d.size(int a)
```

- 頂点 $a$ が属する連結成分のサイズを返します。
  
#### 制約

- $0\le a\lt n$

#### 計算量

- ならし $\mathrm{O}(\alpha(n))$

### diff

```
S d.diff(int a, int b)
```

- $\phi(a)^{-1}\oplus\phi(b)$ を返します。
  
#### 制約

- $0\le a,b\lt n$

#### 計算量

- ならし $\mathrm{O}(\alpha(n))$

### potential

```
S d.potential(int a)
```

- `diff(leader(a),a)` を返します。
  
#### 制約

- $0\le a\lt n$

#### 計算量

- ならし $\mathrm{O}(\alpha(n))$

### 使用例

AC code of https://atcoder.jp/contests/abc087/tasks/arc090_b

submission https://atcoder.jp/contests/abc087/submissions/37440307

``` cpp
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#include<potentialized_dsu>

ll op(ll a, ll b){ return a + b; }
ll e(){ return 0; }
ll inv(ll a){ return -a; }

int main(){
    int n, m; cin >> n >> m;
    potentialized_dsu<ll,op,e,inv> d(n);
    bool ok = true;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        ll x; cin >> x;
        if (d.merge(u,v,x) == -1) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
}

```