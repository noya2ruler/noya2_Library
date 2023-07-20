#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include"template/template.hpp"
#include"graph/Graph_core.hpp"

int main(){
    int n, m, s, t; in(n,m,s,t);
    usefulGraph g(n);
    g.input(m,0,false);
    auto dist = g.dijkstra(s);
    if (dist[t] == linf){
        out(-1);
        return 0;
    }
    auto ans = g.reconstruct(s,t,dist);
    out(dist[t],ans.size()-1);
    rep(i,ans.size()-1) out(ans[i],ans[i+1]);
}