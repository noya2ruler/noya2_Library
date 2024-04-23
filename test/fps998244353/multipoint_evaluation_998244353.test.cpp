#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include"../../template/template.hpp"
#include"../../fps998244353/multipoint_evaluation.hpp"

using mint = modint998244353;
using fps = fps998244353;

int main(){
    int n, m; in(n,m);
    fps f(n); in(f);
    vector<mint> xs(m); in(xs);
    out(multipoint_evaluation(f,xs));
}