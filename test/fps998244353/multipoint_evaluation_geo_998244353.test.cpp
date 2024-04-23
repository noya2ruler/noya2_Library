#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"

#include"../../template/template.hpp"
#include"../../fps998244353/multipoint_evaluation.hpp"

using mint = modint998244353;
using fps = fps998244353;

int main(){
    int n, m, a, r; in(n,m,a,r);
    fps f(n); in(f);
    out(multipoint_evaluation_geo(f,a,r,m));
}