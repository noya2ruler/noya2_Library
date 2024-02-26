---
title: 全部載せ木
documentation_of: //tree/heavy_light_decomposition.hpp
---

# `hld_tree`

## (constructor)

```cpp
hld_tree (); // ... (1)
hld_tree (int n, int root = 0); // ... (2)
hld_tree (simple_tree g, int root = 0) // ... (3)
```

### 概要

`hld_tree` オブジェクトを次に示す通りの要素で初期化し、構築する。

### 効果

- (1) : デフォルトコンストラクタ。なにもしない。特に、意味のある木を構築しない。
- (2) : 頂点数が `n` の、`root` を根とする根付き木を、辺がない状態で構築する。辺は `add_edge` によって追加する。
- (3) : 木構造が `g` であり、`root` を根とする根付き木を構築する。

### 計算量

- (1) : $\Theta (1)$
- (2) : $\Theta (n)$
- (3) : $\Theta (n)$ (ここで $n$ は木構造 `g` の頂点数)

### 備考

- (1) はグローバルに `hld_tree` を置いておくときに使える。`main` 内部で初期化を行うが、グローバルに置いた関数で木の操作を行うときなど。

```cpp
hld_tree g;

int op(int v){
    return g.depth(v);
}

int main(){
    int n; cin >> n;
    g = hld_tree(n); // g を (2) の方法で初期化
    cout << op(0) << endl;
}
```

- (3) は木構造 `simple_tree` を得ている場合にそのまま `hld_tree` にするためのコンストラクタである。`hld_tree::compressed_tree` は `simple_tree` を継承しているが、`hld_tree` の機能を持っていない。そのような場合に `add_edge` を経由せずに簡単に `hld_tree` を構築するための機能である。