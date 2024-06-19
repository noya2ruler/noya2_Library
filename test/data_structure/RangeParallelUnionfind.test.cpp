#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"

#include"../../template/template.hpp"
#include"../../data_structure/range_parallel_dsu.hpp"

#include"../../utility/modint.hpp"
using mint = modint998244353;

int main(){
    int n, q; in(n,q);
    vector<mint> as(n); in(as);
    range_parallel_dsu d(n);
    mint ans = 0;
    while (q--){
        int k, a, b; in(k,a,b);
        for (auto [u, v, l] : d.merge_range(a,b,k)){
            ans += as[u] * as[v];
            as[l] = as[u] + as[v];
        }
        out(ans);
    }
}