#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include"../../template/template.hpp"
#include"../../math/prime_count.hpp"

int main(){
    ll n; in(n);
    out(prime_count(n));
}