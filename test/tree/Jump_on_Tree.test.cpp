#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include"../../template/template.hpp"

#include"../../tree/Tree_core.hpp"

int main(){
    int n, q; cin >> n >> q;
    usefulTree g(n);
    g.input(0);
    g.build();
    while (q--){
        int u, v, d; cin >> u >> v >> d;
        cout << g.jump(u,v,d) << '\n';
    }
}