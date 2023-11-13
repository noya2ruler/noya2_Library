#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja"

#include"../../template/template.hpp"
#include"../../data_structure/potentialized_dsu.hpp"

int main(){
    int n, q; in(n,q);
    potentialized_dsu<Plus_group<ll>> d(n);
    while (q--){
        int t; in(t);
        if (t == 0){
            int u, v; in(u,v);
            ll w; in(w);
            d.merge(u,v,w);
        }
        else {
            int u, v; in(u,v);
            if (d.same(u,v)){
                out(d.diff(u,v));
            }
            else {
                out('?');
            }
        }
    }
}