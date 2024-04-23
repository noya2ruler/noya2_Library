#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include"../../template/template.hpp"
#include"../../fps998244353/fps998244353.hpp"

int main(){
    int n, m; in(n,m);
    fps998244353 f(n), g(m); in(f,g);
    auto [rem, quo] = f.remquo(g);
    out(quo.size(),rem.size());
    out(quo);
    out(rem);
}