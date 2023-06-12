#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include"../../template/template.hpp"

#include"../../tree/Tree_core.hpp"

int main(){
    int n; cin >> n;
    vector<ll> w(n-1);
    naiveTree g(n);
    rep(i,n-1){
        int u, v; cin >> u >> v >> w[i];
        g.add_edge(u,v,i);
    }
    vector<ll> dist(n,linf);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    ll ma1 = 0, p1 = 0;
    while (!que.empty()){
        int p = que.front(); que.pop();
        for (auto &[q, id] : g(p)){
            if (chmin(dist[q],dist[p]+w[id])){
                que.push(q);
                if (chmax(ma1,dist[q])) p1 = q;
            }
        }
    }
    dist.assign(n,linf);
    dist[p1] = 0;
    que.push(p1);
    ll ma2 = 0, p2 = p1;
    while (!que.empty()){
        int p = que.front(); que.pop();
        for (auto &[q, id] : g(p)){
            if (chmin(dist[q],dist[p]+w[id])){
                que.push(q);
                if (chmax(ma2,dist[q])) p2 = q;
            }
        }
    }
    int p = p2;
    vector<int> vs = {p};
    while (p != p1){
        for (auto &q : g[p]){
            if (dist[p] > dist[q]){
                p = q;
                break;
            }
        }
        vs.emplace_back(p);
    }
    cout << ma2 << " " << vs.size() << endl;
    rep(i,vs.size()) cout << vs[i] << " \n"[i+1 == vs.size()];
}