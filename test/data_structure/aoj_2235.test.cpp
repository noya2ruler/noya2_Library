#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235"

#include"../../template/template.hpp"
#include"../../data_structure/offline_dynamic_connectivity.hpp"

int main(){
    int n, q; in(n,q);
    offline_dynamic_connectivity d(n,q+2,q);
    vector<tuple<int,int,int>> query;
    map<pii,int> mp;
    int clock = 0;
    bool is_ask = true;
    while (q--){
        int t, u, v; in(t,u,v);
        if (t == 1){
            if (is_ask) clock++;
            mp[pii(u,v)] = clock;
            is_ask = false;
        }
        if (t == 2){
            if (is_ask) clock++;
            d.add_edge(mp[pii(u,v)],clock,u,v);
            mp.erase(pii(u,v));
            is_ask = false;
        }
        if (t == 3){
            if (!is_ask) clock++;
            query.push_back({clock,u,v});
            is_ask = true;
        }
    }
    for (auto [p, t] : mp){
        d.add_edge(t,clock+1,p.first,p.second);
    }
    d.build();
    for (auto [t, u, v] : query){
        d.set(t);
        YN(d.same(u,v));
    }
}