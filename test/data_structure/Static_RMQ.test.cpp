#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include"../../template/template.hpp"

#include"../../data_structure/sparse_table.hpp"

int op(int a, int b){
    return min(a,b);
}

int main(){
    int n, q; in(n,q);
    vector<int> a(n); in(a);
    sparse_table<int,op> spt(a);
    while (q--){
        int l, r; cin >> l >> r;
        out(spt.prod(l,r));
    }
}