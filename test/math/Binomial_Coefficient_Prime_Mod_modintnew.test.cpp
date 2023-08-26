#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include"../../template/template.hpp"
#include"../../utility/modint_new.hpp"
#include"../../math/binomial.hpp"

int main(){
    int t, m; in(t,m);
    modint::set_mod(m);
    while (t--){
        int n, k; in(n,k);
        out(binomial<modint>::C(n,k).val());
    }
}