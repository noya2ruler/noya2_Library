#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include"../../template/template.hpp"
#include"../../fps998244353/sample_point_shift.hpp"

int main(){
    int n, m, c; in(n,m,c);
    fps998244353 f(n); in(f);
    out(sample_point_shift(f,c,m));
}