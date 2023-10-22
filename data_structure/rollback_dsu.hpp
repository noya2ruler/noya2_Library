#pragma once

#include"../template/template.hpp"

namespace noya2 {

struct rollback_dsu {
    rollback_dsu (int n_ = 0) : n(n_), par_or_siz(n_,-1) {};
    int leader(int v){
        assert(0 <= v && v < n);
        if (par_or_siz[v] < 0) return v;
        return leader(par_or_siz[v]);
    }
    bool same(int u, int v){
        return leader(u) == leader(v);
    }
    int merge(int u, int v){
        u = leader(u);
        v = leader(v);
        logs.push(make_pair(u,par_or_siz[u]));
        logs.push(make_pair(v,par_or_siz[v]));
        if (u == v) return u;
        if (-par_or_siz[u] < -par_or_siz[v]) swap(u,v);
        par_or_siz[u] += par_or_siz[v];
        par_or_siz[v] = u;
        return u;
    }
    int size(int v){
        return -par_or_siz[leader(v)];
    }
    void rollback(){
        par_or_siz[logs.top().first] = logs.top().second; logs.pop();
        par_or_siz[logs.top().first] = logs.top().second; logs.pop();
    }
  private:
    int n;
    vector<int> par_or_siz;
    stack<pair<int,int>> logs;
};

} // namespace noya2