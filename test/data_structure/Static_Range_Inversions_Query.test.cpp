#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include"../../template/template.hpp"
#include"../../data_structure/compress.hpp"
#include"../../data_structure/binary_indexed_tree.hpp"
#include"../../misc/mo_algorithm.hpp"
#include"../../misc/monoids.hpp"

int main(){
    int n, q; in(n,q);
    vector<int> a(n); in(a);
    compress<int> cp(a);
    rep(i,n) a[i] = cp.id(a[i]);
    Mo mo(n,q);
    rep(i,q){
        int l, r; in(l,r);
        mo.insert(l,r);
    }
    binary_indexed_tree<plus_group<ll>> bit(n);
    ll cur = 0;
    auto addl = [&](int i){
        cur += bit.prod(0,a[i]);
        bit.add(a[i],1);
    };
    auto addr = [&](int i){
        cur += bit.prod(a[i]+1,n);
        bit.add(a[i],1);
    };
    auto dell = [&](int i){
        cur -= bit.prod(0,a[i]);
        bit.add(a[i],-1);
    };
    auto delr = [&](int i){
        cur -= bit.prod(a[i]+1,n);
        bit.add(a[i],-1);
    };
    vector<ll> ans(q,0);
    auto ask = [&](int i){
        ans[i] = cur;
    };
    mo.run(addl,addr,dell,delr,ask);
    rep(i,q) out(ans[i]);
}