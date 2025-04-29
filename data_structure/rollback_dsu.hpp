#pragma once

#include <vector>
#include <stack>
#include <utility>
#include <cassert>

namespace noya2 {

struct rollback_dsu {
    rollback_dsu (int _n = 0) : n(_n), cc(_n), par_or_siz(_n,-1) {}
    int leader(int v) const {
        assert(0 <= v && v < n);
        if (par_or_siz[v] < 0) return v;
        return leader(par_or_siz[v]);
    }
    bool same(int u, int v) const {
        return leader(u) == leader(v);
    }
    int merge(int u, int v){
        u = leader(u);
        v = leader(v);
        logs.push(make_pair(u,par_or_siz[u]));
        logs.push(make_pair(v,par_or_siz[v]));
        logs.push(make_pair(cc, -1));
        if (u == v) return u;
        if (-par_or_siz[u] < -par_or_siz[v]) std::swap(u,v);
        par_or_siz[u] += par_or_siz[v];
        par_or_siz[v] = u;
        cc--;
        return u;
    }
    int size(int v) const {
        return -par_or_siz[leader(v)];
    }
    int group_count() const {
        return cc;
    }
    void rollback(){
        cc = logs.top().first; logs.pop();
        par_or_siz[logs.top().first] = logs.top().second; logs.pop();
        par_or_siz[logs.top().first] = logs.top().second; logs.pop();
    }
  private:
    int n, cc;
    std::vector<int> par_or_siz;
    std::stack<std::pair<int,int>> logs;
};

} // namespace noya2