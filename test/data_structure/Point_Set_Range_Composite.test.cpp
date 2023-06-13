#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include"../../template/template.hpp"

#include"../../data_structure/segment_tree.hpp"
#include"../../utility/modint.hpp"

using mint = modint998244353;
using pmm = pair<mint,mint>;

pmm op(pmm a, pmm b){
    return pmm(a.first*b.first,b.first*a.second+b.second);
}
pmm e(){
    return pmm(1,0);
}

int main(){
    int n, q; cin >> n >> q;
    segtree<pmm,op,e> seg(n);
    rep(i,n){
        int a, b; cin >> a >> b;
        seg.set(i,pmm(a,b));
    }
    while (q--){
        int t; cin >> t;
        if (t == 0){
            int p, c, d; cin >> p >> c >> d;
            seg.set(p,pmm(c,d));
        }
        if (t == 1){
            int l, r, x; cin >> l >> r >> x;
            pmm f = seg.prod(l,r);
            printf("%u\n",(f.first*x+f.second).val());
        }
    }
}