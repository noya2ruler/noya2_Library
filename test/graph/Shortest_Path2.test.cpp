#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include"../../template/template.hpp"
#include"../../graph/graph_query.hpp"

int main(){
    int n, m, s, t; in(n,m,s,t);
    graph<ll> g(n,m);
    rep(i,m){
        int u, v; in(u,v);
        ll c; in(c);
        g.add_edge(u,v,c);
    }
    auto dist = g.dijkstra(s);
    if (dist[t] == g.dist_inf){
        out(-1);
        return 0;
    }
    auto ans = g.reconstruct(s,t,dist);
    out(dist[t],ans.size()-1);
    rep(i,ans.size()-1) out(ans[i],ans[i+1]);
}