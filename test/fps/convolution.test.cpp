#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include"../../template/template.hpp"
#include"../../fps/fps_ntt.hpp"
using mint = modint998244353;
using fps = FPS_ntt<mint>;

int main(){
    int n, m; in(n,m);
    fps f(n), g(m); in(f,g);
    out(f*g);
}