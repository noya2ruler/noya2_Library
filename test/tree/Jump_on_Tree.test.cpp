#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include"../../template/template.hpp"

#include"../../tree/heavy_light_decomposition.hpp"

int main(){
    int n, q; in(n,q);
    hld_tree g(n);
    g.input_edges<0>();
    while (q--){
        int u, v, d; in(u,v,d);
        out(g.jump(u,v,d));
    }
}