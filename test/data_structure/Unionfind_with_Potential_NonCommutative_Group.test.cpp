#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"

#include"../../template/template.hpp"

#include"data_structure/potentialized_dsu.hpp"
#include"math/matrix.hpp"
#include"utility/modint.hpp"
using mint = modint998244353;
using mat = matrix<mint,2>;

struct G {
    using value_type = mat;
    static mat op(mat a, mat b){
        return a * b;
    }
    static mat e(){
        return mat::e();
    }
    static mat inv(mat a){
        return mat(array<mint,4uz>{a[1][1],-a[0][1],-a[1][0],a[0][0]});
    }
};

int main(){
    int n, q; in(n,q);
    potentialized_dsu<G> d(n);
    while (q--){
        int t; in(t);
        if (t == 0){
            int u, v; in(u,v);
            mat x; in(x);
            int l = d.merge(u,v,x);
            out(l == -1 ? 0 : 1);
        }
        if (t == 1){
            int u, v; in(u,v);
            if (d.same(u,v)){
                mat x = d.diff(u,v);
                out(x[0][0],x[0][1],x[1][0],x[1][1]);
            }
            else {
                out(-1);
            }
        }
    }
}