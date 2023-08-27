#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include"../../template/template.hpp"
#include"../../fps/fps_ntt.hpp"
using mint = modint998244353;

int main(){
    int n, m; in(n,m);
    fps<mint> f(n), g(m); in(f,g);
    out(f*g);
}