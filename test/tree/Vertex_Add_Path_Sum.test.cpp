#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include"../../template/template.hpp"
#include"../../data_structure/fenwick_tree.hpp"
#include"../../tree/heavy_light_decomposition.hpp"

int main(){
    int n, q; in(n,q);
    vector<ll> a(n); in(a);
    hld_tree g(n);
    g.input(0);
    fenwick_tree<ll> fen(n);
    rep(v,n) fen.add(g.index(v),a[v]);
    while (q--){
        int t; in(t);
        if (t == 0){
            int p, x; in(p,x);
            fen.add(g.index(p),x);
        }
        else {
            int u, v; in(u,v);
            ll ans = 0;
            auto prod = [&](int l, int r){
                ans += fen.sum(l,r);
            };
            g.path_query(u,v,true,prod);
            out(ans);
        }
    }
}