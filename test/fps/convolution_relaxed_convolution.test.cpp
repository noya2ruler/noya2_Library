#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include"../../template/template.hpp"
#include"../../fps/relaxed_convolution.hpp"
using mint = modint998244353;

int main(){
    int n, m; in(n,m);
    vector<mint> a(n), b(m); in(a,b);
    RelaxedConvolution<mint> rc(n+m-1);
    vector<mint> ans(n+m-1);
    rep(i,n+m-1){
        mint fi = (i < n ? a[i] : mint(0));
        mint gi = (i < m ? b[i] : mint(0));
        rc.join(fi,gi);
        ans[i] = rc[i];
    }
    out(ans);
}