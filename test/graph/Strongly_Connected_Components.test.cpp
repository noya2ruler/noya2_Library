#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include"../../template/template.hpp"
#include"../../graph/scc.hpp"

int main(){
    int n, m; in(n,m);
    scc_graph g(n);
    rep(i,m){
        int u, v; in(u,v);
        g.add_edge(u,v);
    }
    auto ans = g.scc();
    out(ans.size());
    for (auto &v : ans){
        out(v.size(),v);
    }
}