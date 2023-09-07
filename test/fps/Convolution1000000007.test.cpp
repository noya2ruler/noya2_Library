#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include"../../template/template.hpp"
#include"../../fps/fps_modint.hpp"
using mint = modint1000000007;
using fps = FPS_modint<mint>;

int main(){
    int n, m; in(n,m);
    fps f(n), g(m); in(f,g);
    out(f*g);
}