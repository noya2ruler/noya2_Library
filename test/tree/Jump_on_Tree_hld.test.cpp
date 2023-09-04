#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include"../../template/template.hpp"
#include"../../tree/tree_query.hpp"

int main(){
    int n, q; in(n,q);
    Tree g(n);
    g.input(0);
    while (q--){
        int u, v, k; in(u,v,k);
        out(g.jump(u,v,k));
    }
}