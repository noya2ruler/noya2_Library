#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions"

#include"../../template/template.hpp"
#include"../../misc/O1onTree.hpp"

struct mono {
    ll c, d;
    static constexpr mono op(mono a, mono b){
        return {a.c + b.c, a.d + b.d};
    }
    friend bool operator<(mono a, mono b){
        if (b.c == 0 && b.d == 0) return false;
        if (a.c == 0 && a.d == 0) return true;
        return a.d * b.c < a.c * b.d;
    }
};

int main(){
    int n; in(n);
    vector<int> par(n);
    par[0] = -1;
    repp(i,1,n){
        in(par[i]);
    }
    vector<ll> c(n), d(n); in(c,d);
    vector<mono> ds(n);
    rep(i,n){
        ds[i] = {c[i], d[i]};
    }
    auto ord = O1onTree<mono, true>(n, par, ds);
    ll ans = 0;
    ll dsum = 0;
    for (int i : ord){
        ans += dsum * c[i];
        dsum += d[i];
    }
    out(ans);
    out(ord);
}