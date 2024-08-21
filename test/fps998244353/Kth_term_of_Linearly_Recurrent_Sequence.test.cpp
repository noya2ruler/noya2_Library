#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include"../../template/template.hpp"
#include"../../fps998244353/bostan_mori.hpp"

int main(){
    int d; in(d);
    ll k; in(k);
    fps998244353 a(d), c(d); in(a, c);
    c.insert(c.begin(), -1);
    out(kth_term_linear(a, c, k));
}