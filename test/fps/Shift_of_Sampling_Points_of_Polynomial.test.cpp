#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include"../../template/template.hpp"
#include"../../fps/sample_point_shift.hpp"
using mint = modint998244353;
using fps = FPS_ntt<mint>;

int main(){
    int n, m; in(n,m);
    mint c; in(c);
    fps y(n); in(y);
    out(sample_point_shift(y,c,m));
}