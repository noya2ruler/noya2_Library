#define PROBLEM "https://yukicoder.me/problems/no/1976"

#include "../../template/template.hpp"
#include "../../tree/rerootingdp.hpp"

int main() {
    int n; in(n);
    vector<vector<pii>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; in(u, v); u--, v--;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, ~i);
    }
    auto op = [&](pii a, pii b){
        return pii(max({a.first, b.first, a.second + b.second}), max(a.second, b.second));
    };
    pii e(0,0);
    auto pute = [&](pii x, int){
        return pii(max(x.first, x.second + 1), x.second + 1);
    };
    auto putv = [&](pii e, int){
        return e;
    };
    auto dp = rerootingdp<pii,pii>(op,e,pute,putv,g);
    int ans = n;
    for (int u = 0; u < n; u++) {
        for (auto [v, eid] : g[u]) {
            int x = dp(u, v).first;
            int y = dp(v, u).first;
            ans = min(ans, max({x, y, (x + 1) / 2 + (y + 1) / 2 + 1}));
        }
    }
    out(ans);
}