#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include"../../template/template.hpp"
#include"../../tree/heavy_light_decomposition.hpp"

int main(){
    int n, q; in(n,q);
    hld_tree g(n);
    g.input_parents<0>();
    while (q--){
        int u, v; in(u,v);
        out(g.lca(u,v));
    }
}