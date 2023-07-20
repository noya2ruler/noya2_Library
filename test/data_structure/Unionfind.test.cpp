#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include"../../template/template.hpp"
#include"../../data_structure/dsu.hpp"

int main(){
    int n, q; in(n,q);
    dsu d(n);
    while (q--){
        int t, u, v; in(t,u,v);
        if (t == 0){
            d.merge(u,v);
        }
        else {
            out(d.same(u,v) ? 1 : 0);
        }
    }
}