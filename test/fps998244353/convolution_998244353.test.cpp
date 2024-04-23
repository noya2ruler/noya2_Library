#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include"../../template/template.hpp"
#include"../../fps998244353/fps998244353.hpp"

using mint = modint998244353;
using fps = fps998244353;

int main(){
    int n, m; in(n,m);
    fps f(n), g(m); in(f,g);
    out(f*g);
}