#define PROBLEM "https://judge.yosupo.jp/problem/counting_eulerian_circuits"

#include"../../template/template.hpp"
#include"../../math/euler_circuit_counting.hpp"
#include"../../utility/modint.hpp"
using mint = modint998244353;

int main(){
    int n, m; in(n,m);
    vector<tuple<int,int,ll>> es(m);
    rep(i,m){
        int u, v; in(u,v);
        es[i] = {u,v,1};
    }
    out(euler_circuit_counting<mint>(n,es));
}