#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include"../../template/template.hpp"
#include"../../math/factorize.hpp"

int main(){
    int q; in(q);
    while (q--){
        ll n; in(n);
        yn(is_prime(n));
    }
}