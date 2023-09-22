---
title: 2-dimentional vector
documentation_of: //data_structure/vector2d.hpp
---

## 2 次元 vector

2 次元の `std::vector` を平坦にして 1 次元にするライブラリです。

AtCoderLibrary の `atcoder::internal::csr` にあるようなものをより一般的な状況で使えるように改良したもので、データ構造の内容としては全く同じ。

### コンストラクタ `vector2d<E> vec(int n, int m)`

保持する要素の型は `E` で一次元目の長さが `n`, **総要素数**が `m` である二次元 `vector` と見れるようなものを確保する（内部的には一次元で確保）。

### `void add(int i, E e)`

`vec[i].push_back(e)` と同じ挙動をすることが想定される。全ての要素の `add` が完了しない限り、配列への `vec[i][j]` などのアクセスはすべて未定義。

すべての要素の `add` が完了した、つまり、ちょうど `m` 回の　`add` が呼ばれたとき、処理直後に内部的に `build` が呼び出される。

### `void build()`

追加順で並んでいた要素を一次元目の要素の昇順になるように並べ替える。ただし、同じ一次元目の要素の持つものに関しては追加順と同じ順序になる。

この関数は一度しか呼び出されない。処理終了後、配列外参照を起こさないアクセス `vec[i][j]` に対しては期待通りの動作をする。詳しくは `operator[]` を参照せよ。

### `operator[]`

`std::vector<E>` への参照やコピーが返ってきて欲しいように思うかもしれないが、そうではなく、 `Range` が返ってくる。とはいえ、この `Range` にも `operator[]` が定義されていて、通常の二次元配列へのアクセスと同様に、たとえば `vec[i][j]` などとしてアクセスできる。取得、代入など、多分ほとんどのことが可能。
`vec[i].size()` として通常の意味での各配列の大きさを取得できるが、ループを回す際には範囲for文による解体が最も手っ取り早いと思われる。

### 使用例

```cpp
#include"data_structure/vector2d.hpp"
using namespace noya2;

#include<iostream>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    vector2d<int> a(n,q);
    while(q--){
        int u, v; cin >> u >> v;
        a.add(u,v);
    }
    for (int i = 0; i < n; i++){
        cout << i << " : a[" << i << "].size() = " << a[i].size() << ", a[" << i << "] = { ";
        for (int j = 0; auto v : a[i]){
            cout << v;
            if (++j != (int)a[i].size()) cout << ", ";
        }
        cout << " }\n";
    }
}
```

input:
```
3 5
1 2
2 4
0 3
0 2
1 5
```

output :

```
0 : a[0].size() = 2, a[0] = { 3, 2 }
1 : a[1].size() = 2, a[1] = { 2, 5 }
2 : a[2].size() = 1, a[2] = { 4 }
```

