#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include"template/template.hpp"
#include"graph/graph_query.hpp"

int main(){
    int n, m, s, t; in(n,m,s,t);
    auto g = graph<ll>::input<false>(n, m, 0);
    auto dist = g.dijkstra(s);
    if (dist[t] == g.dist_inf){
        out(-1);
        return 0;
    }
    auto ans = g.reconstruct(s,t,dist);
    out(dist[t],ans.size()-1);
    rep(i,ans.size()-1) out(ans[i],ans[i+1]);
}