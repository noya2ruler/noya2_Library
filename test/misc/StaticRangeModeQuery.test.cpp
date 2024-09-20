#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"

#include"../../template/template.hpp"
#include"../../misc/static_range_mode_query.hpp"
#include"../../data_structure/compress.hpp"

int main(){
    int n, q; in(n,q);
    vector<int> a(n); in(a);
    compress<int> cp(a);
    rep(i,n){
        a[i] = cp.id(a[i]);
    }
    static_range_mode_query srmq(a);
    while (q--){
        int l, r; in(l,r);
        auto [id, ma] = srmq.prod(l,r);
        id = cp.raw(id);
        out(id,ma);
    }
}