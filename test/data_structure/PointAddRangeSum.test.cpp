#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include"../../template/template.hpp"
#include"../../data_structure/fenwick_tree.hpp"

int main(){
    int n, q; in(n,q);
    vector<ll> a(n); in(a);
    fenwick_tree<ll> fen(n);
    rep(i,n) fen.add(i,a[i]);
    while (q--){
        int t; in(t);
        if (t == 0){
            int p, x; in(p,x);
            fen.add(p,x);
        }
        if (t == 1){
            int l, r; in(l,r);
            out(fen.sum(l,r));
        }
    }
}