#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include"../../template/template.hpp"
#include"../../data_structure/offline_rectangle_sum.hpp"

#include"data_structure/compress.hpp"

int main(){
    int n, q; in(n,q);
    compress<int> cpx, cpy;
    vector<tuple<int,int,ll>> a(n);
    rep(i,n){
        int x, y, w; in(x,y,w);
        a[i] = tuple<int,int,ll>(x,y,w);
        cpx.add(x);
        cpy.add(y);
    }
    vector<tuple<int,int,int,int>> queries(q);
    rep(i,q){
        int lx, ly, rx, ry; in(lx,ly,rx,ry);
        queries[i] = tuple<int,int,int,int>(lx,rx,ly,ry);
    }
    cpx.build();
    cpy.build();
    offline_rectangle_sum<> ors(cpx.size(),cpy.size(),n,q);
    for (auto [x, y, w] : a){
        x = cpx.id(x);
        y = cpy.id(y);
        ors.add_elem(x,y,w);
    }
    for (auto [lx, rx, ly, ry] : queries){
        lx = cpx.lb(lx);
        rx = cpx.lb(rx);
        ly = cpy.lb(ly);
        ry = cpy.lb(ry);
        ors.add_query(lx,rx,ly,ry);
    }
    for (auto ans : ors.run()){
        out(ans);
    }
}
