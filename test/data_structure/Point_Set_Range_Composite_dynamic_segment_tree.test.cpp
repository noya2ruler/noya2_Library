#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include"../../template/template.hpp"
#include"../../data_structure/dynamic_segment_tree.hpp"
#include"../../utility/modint.hpp"
using mint = modint998244353;
using pmm = pair<mint,mint>;

pmm op(pmm a, pmm b){
    return pmm(a.first*b.first,a.second*b.first+b.second);
}
pmm e(){
    return pmm(1,0);
}

int main(){
    int n, q; in(n,q);
    dynamic_segtree<pmm,op,e> seg(n);
    rep(i,n){
        mint a, b; in(a,b);
        seg.set(i,pmm(a,b));
    }
    while (q--){
        int t; in(t);
        if (t == 0){
            int p, c, d; in(p,c,d);
            seg.set(p,pmm(c,d));
        }
        if (t == 1){
            int l, r, x; in(l,r,x);
            auto [a, b] = seg.prod(l,r);
            out(a*x+b);
        }
    }
}