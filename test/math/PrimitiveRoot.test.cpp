#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include"../../template/template.hpp"
#include"../../math/prime_64bit.hpp"

void solve(){
    ll p; in(p);
    out(internal64bit::primitive_root_ll(p));
}

int main(){
    int q; in(q);
    while (q--){
        solve();
    }
}