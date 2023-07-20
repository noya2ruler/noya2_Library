#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include"../../template/template.hpp"
#include"../../tree/Tree_core.hpp"

int main(){
    int n, q; in(n,q);
    usefulTree g(n);
    rep(i,n-1){
        int p; in(p);
        g.add_edge(i+1,p);
    }
    g.build();
    while (q--){
        int u, v; in(u,v);
        out(g.lca(u,v));
    }
}