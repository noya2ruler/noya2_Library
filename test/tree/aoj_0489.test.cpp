#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0489"

#include"../../template/template.hpp"
#include"../../tree/Mo_on_Tree.hpp"
#include"../../tree/Tree_core.hpp"
#include"../../data_structure/segment_tree.hpp"

const int geta = 1'000'000;
const int mx = geta*2+10;

int op(int a, int b){
    return a + b;
}
int e(){
    return 0;
}

using ar = array<int,3>;

int main(){
    int n, m; in(n,m);
    vector<int> a(n); in(a);
    vector<ar> querys;
    vector<pii> es(n-1); in(es);
    {   
        int pre = n+1;
        while (m--){
            int t; in(t);
            if (t == 1){
                int u, w; in(u,w);
                es.emplace_back(u,pre++);
                a.emplace_back(w);
            }
            if (t == 2){
                int u, v, k; in(u,v,k); u--, v--, k--;
                querys.push_back({u,v,k});
            }
        }
        n = es.size()+1;
        m = querys.size();
    }
    MoTree_vertex<int> mo(n,a);
    usefulTree g(n);
    for (auto &[u, v] : es){
        u--, v--;
        mo.add_edge(u,v);
        g.add_edge(u,v);
    }
    mo.build(querys.size());
    g.build();
    for (auto [u, v, k] : querys){
        mo.insert(u,v,g.lca(u,v));
    }
    segtree<int,op,e> seg(mx);
    vector<int> ans(querys.size());
    auto get = [&](int k){
        auto f = [&](int cnt){
            return cnt <= k;
        };
        return seg.max_right(0,f) - geta;
    };
    auto add = [&](int v){
        v += geta;
        seg.set(v,seg.get(v)+1);
    };
    auto del = [&](int v){
        v += geta;
        seg.set(v,seg.get(v)-1);
    };
    auto ask = [&](int i){
        ans[i] = get(querys[i][2]);
    };
    mo.run(add,del,ask);
    for (auto z : ans) out(z);
}