#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"

#include"../../template/template.hpp"
#include"../../utility/modint.hpp"
using mint = static_modint<469762049>;
using ar = array<mint,2>;
ar &operator+=(ar &a, ar b){
    a[0] += b[0];
    a[1] += b[1];
    return a;
}
ar &operator-=(ar &a, ar b){
    a[0] -= b[0];
    a[1] -= b[1];
    return a;
}
ar operator-(ar a, ar b){
    return a -= b;
}

#include"../../math/multiplicative_function.hpp"


void solve(){
    ll n; in(n);
    mint a, b; in(a,b);
    mf_prefix_sum mf(n);
    mint i2 = mint(2).inv();
    auto tbl = mf.table<ar>(
        [&](int p) -> ar {
            return ar{a, b*p};
        },
        [&](ll r) -> ar {
            return ar{a*(r-1), b*(mint(r)*(r+1)*i2-1)};
        },
        [&](int p, ar x) -> ar {
            return ar{x[0], x[1] * p};
        }
    );
    vector<mint> fprime(tbl.size());
    rep(i,tbl.size()){
        fprime[i] = tbl[i][0] + tbl[i][1];
    }
    mint ans = mf.run<mint>(
        [&](int p, int e){
            return a*e + b*p;
        },
        fprime
    );
    out(ans);
}

int main(){
    int t; in(t);
    while (t--){
        solve();
    }
}