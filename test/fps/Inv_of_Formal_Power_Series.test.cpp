#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include"../../template/template.hpp"
#include"../../fps/fps_ntt.hpp"
using mint = modint998244353;
using fps = FPS_ntt<mint>;

int main(){
    int n; in(n);
    fps f(n); in(f);
    out(f.inv(n));
}