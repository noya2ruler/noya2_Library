#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include"../../template/template.hpp"
#include"../../data_structure/lazy_segment_tree.hpp"
#include"../../utility/modint.hpp"

using mint = modint998244353;
using pmm = pair<mint,mint>;

pmm op(pmm a, pmm b){
    return pmm(a.first+b.first,a.second+b.second);
}
pmm e(){
    return pmm(0,0);
}
pmm mapping(pmm f, pmm x){
    return pmm(x.first*f.first + x.second*f.second, x.second);
}
pmm composition(pmm f, pmm g){
    return pmm(f.first*g.first,f.first*g.second+f.second);
}
pmm ideal(){
    return pmm(1,0);
}

int main(){
    int n, q; in(n,q);
    lazy_segtree<pmm,op,e,pmm,mapping,composition,ideal> seg([&]{
        vector<pmm> a(n);
        rep(i,n){
            ll x; in(x);
            a[i] = pmm(x,1);
        }
        return a;
    }());
    while (q--){
        int t; in(t);
        if (t == 0){
            int l, r, b, c; in(l,r,b,c);
            seg.apply(l,r,pmm(b,c));
        }
        else {
            int l, r; in(l,r);
            out(seg.prod(l,r).first.val());
        }
    }
}