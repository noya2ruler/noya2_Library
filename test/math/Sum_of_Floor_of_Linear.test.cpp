#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include"../../template/template.hpp"
#include"../../math/floor_sum.hpp"

void solve(){
    ll n, m, a, b; in(n,m,a,b);
    out(floor_sum(n,m,a,b));
}

int main(){
    int t; in(t);
    while (t--) solve();
}