#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include"template/template.hpp"

#include"../../data_structure/li_chao_tree.hpp"

int main(){
    int n, q; in(n,q);
    vector<array<ll,5>> querys(n+q);
    vector<ll> xs;
    rep(i,n+q){
        if (i < n){
            ll a, b, l, r; in(l,r,a,b);
            querys[i] = {0,a,b,l,r};
            continue;
        }
        int t; in(t);
        if (t == 0){
            ll a, b, l, r; in(l,r,a,b);
            querys[i] = {0,a,b,l,r};
        }
        else {
            ll x; in(x);
            querys[i] = {t,x,0,0,0};
            xs.emplace_back(x);
        }
    }
    LiChaoTree<ll> lct(xs);
    rep(i,n+q){
        auto [t,a,b,l,r] = querys[i];
        if (t == 0){
            lct.segment_add(a,b,l,r);
        }
        else {
            ll ans = lct.get(a);
            if (ans == lct.ymax){
                out("INFINITY");
            }
            else {
                out(ans);
            }
        }
    }
}