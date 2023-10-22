#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include"../../template/template.hpp"
#include"../../math/gcd_convolution.hpp"
#include"utility/modint.hpp"
using mint = modint998244353;

int main(){
    int n; in(n);
    vector<mint> a(n+1), b(n+1);
    rep(i,n) in(a[i+1]);
    rep(j,n) in(b[j+1]);
    auto ab = gcd_convolution(a,b);
    rep(i,n){
        if (i != 0) cout << ' ';
        cout << ab[i+1];
    }
    cout << '\n';
}