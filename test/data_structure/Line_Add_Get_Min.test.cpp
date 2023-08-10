#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include"template/template.hpp"

#include"../../data_structure/li_chao_tree.hpp"

int main(){
    int n, q; in(n,q);
    vector<array<ll,3>> querys(n+q);
    vector<ll> xs;
    rep(i,n+q){
        if (i < n){
            ll a, b; in(a,b);
            querys[i] = {0,a,b};
            continue;
        }
        int t; in(t);
        if (t == 0){
            ll a, b; in(a,b);
            querys[i] = {t,a,b};
        }
        else {
            ll x; in(x);
            querys[i] = {t,x,0};
            xs.emplace_back(x);
        }
    }
    LiChaoTree<ll> lct(xs);
    rep(i,n+q){
        if (querys[i][0] == 0){
            lct.line_add(querys[i][1],querys[i][2]);
        }
        else {
            out(lct.get(querys[i][1]));
        }
    }
}