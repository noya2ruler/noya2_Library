#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include"../../template/template.hpp"
#include"../../data_structure/range_tree.hpp"
#include"../../data_structure/binary_indexed_tree.hpp"

int main(){
    int n, q; in(n,q);
    vector<array<int,5>> queries(n+q);
    range_tree<Plus_group<ll>,BinaryIndexedTree,int> rt;
    rep(i,n+q){
        if (i < n){
            int x, y, w; in(x,y,w);
            queries[i] = {0,x,y,w,0};
            rt.join(x,y);
            continue;
        }
        int t; in(t);
        if (t == 0){
            int x, y, w; in(x,y,w);
            queries[i] = {t,x,y,w,0};
            rt.join(x,y);
        }
        if (t == 1){
            int l, d, r, u; in(l,d,r,u);
            queries[i] = {t,l,d,r,u};
        }
    }
    rt.build();
    rep(i,n+q){
        if (queries[i][0] == 0){
            auto [t, x, y, w, o] = queries[i];
            rt.set(x,y,rt.get(x,y)+w);
        }
        if (queries[i][0] == 1){
            auto [t, l, d, r, u] = queries[i];
            out(rt.prod(l,r,d,u));
        }
    }
}