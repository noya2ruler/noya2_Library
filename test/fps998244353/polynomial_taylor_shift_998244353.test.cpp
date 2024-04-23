#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include"../../template/template.hpp"
#include"../../fps998244353/polynomial_taylor_shift.hpp"

int main(){
    int n, c; in(n,c);
    fps998244353 f(n); in(f);
    out(polynomial_taylor_shift(f,c));
}