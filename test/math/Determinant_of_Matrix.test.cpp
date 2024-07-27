#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include"template/template.hpp"

#include"../../math/matrix.hpp"
#include"../../utility/modint.hpp"
using mint = modint998244353;

int main(){
    int n; in(n);
    matrix<mint> mat(n,n);
    rep(i,n) rep(j,n){
        ll x; in(x);
        mat[i][j] = x;
    }
    out(determinant(mat));
}