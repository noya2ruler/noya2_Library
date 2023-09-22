#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"

#include"../../template/template.hpp"
#include"../../data_structure/vector2d.hpp"

int main(){
    int n, m; in(n,m);
    vector2d<pii> g(n,m*2);
    rep(i,m){
        int u, v; in(u,v);
        g.add(u,pii(v,i));
        g.add(v,pii(u,i));
    }
    vector<bool> used(m,false), visited(n,false);
    queue<int> que;
    int sv = -1, tv = -1, eid = -1;
    rep(i,n){
        if (visited[i]) continue;
        que.push(i);
        visited[i] = true;
        while (!que.empty()){
            int p = que.front(); que.pop();
            for (auto [q, e] : g[p]){
                if (used[e]) continue;
                if (visited[q]){
                    sv = p, tv = q, eid = e;
                    continue;
                }
                used[e] = true;
                visited[q] = true;
                que.push(q);
            }
        }
    }
    if (sv == -1){
        cout << -1 << endl;
        return 0;
    }
    fill(all(visited),false);
    vector<int> vs, es;
    bool done = false;
    auto dfs = [&](auto sfs, int v) -> void {
        if (done) return ;
        vs.push_back(v);
        visited[v] = true;
        if (v == tv){
            done = true;
            return ;
        }
        for (auto [u, e] : g[v]){
            if (e == eid) continue;
            if (visited[u]) continue;
            es.push_back(e);
            sfs(sfs,u);
            if (done) return ;
            es.pop_back();
        }
        vs.pop_back();
    };
    dfs(dfs,sv);
    es.push_back(eid);
    out(vs.size());
    out(vs);
    out(es);
}