#pragma once

#include<vector>

namespace noya2 {

using namespace std;

template<class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int), V (*put_vertex)(E, int)>
struct Rerooting {
    struct edge{
        int from, to, idx, rev_idx;
    };
    Rerooting (int _n = 0) : n(_n) { es.resize(n);}
    void add_edge(int u, int v, int idx1, int idx2){
        es[u].push_back({u,v,idx1,idx2});
        es[v].push_back({v,u,idx2,idx1});
    }
    V build(int v = 0){
        root = v;
        vis.resize(n,0);
        outs.resize(n);
        return dfs(root);
    }
    vector<V> reroot(){
        reverse_edge.resize(n);
        reverse_edge[root] = e();
        answers.resize(n);
        bfs(root);
        return answers;
    }
  private:
    int n, root;
    vector<vector<edge>> es;
    vector<int> vis;
    vector<vector<E>> outs;
    vector<E> reverse_edge;
    vector<V> answers;
    V dfs(int v){
        vis[v]++;
        E val = e();
        for (auto &p : es[v]){
            if (vis[p.to] > 0 && p.to != es[v].back().to) swap(p,es[v].back());
            if (vis[p.to] > 0) continue;
            E nval = put_edge(dfs(p.to),p.idx);
            outs[v].emplace_back(nval);
            val = merge(val,nval);
        }
        return put_vertex(val,v);
    }
    void bfs(int v){
        int siz = outs[v].size();
        vector<E> lui(siz+1), rui(siz+1);
        lui[0] = e(), rui[siz] = e();
        for (int i = 0; i < siz; i++) lui[i+1] = merge(lui[i],outs[v][i]);
        for (int i = siz-1; i >= 0; i--) rui[i] = merge(outs[v][i],rui[i+1]);
        for (int i = 0; i < siz; i++){
            reverse_edge[es[v][i].to] = put_edge(put_vertex(merge(merge(lui[i],rui[i+1]),reverse_edge[v]),v),es[v][i].rev_idx);
            bfs(es[v][i].to);
        }
        answers[v] = put_vertex(merge(lui[siz],reverse_edge[v]), v);
    }
};

} // namespace noya2
