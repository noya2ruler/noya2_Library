#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include"../../template/template.hpp"
#include"../../tree/heavy_light_decomposition.hpp"
#include"../../utility/modint.hpp"
#include"../../data_structure/segment_tree.hpp"

using mint = modint998244353;
using ar = std::array<mint,3>;

ar op(ar a, ar b){
    return {a[0] * b[0], b[0] * a[1] + b[1], a[0] * b[2] + a[2]};
}
ar e(){
    return {1, 0, 0};
}
ar flip(ar a){
    std::swap(a[1],a[2]);
    return a;
}

int main(){
    int n, q; cin >> n >> q;
    std::vector<std::pair<int, int>> ab(n);
    for (int i = 0; i < n; i++){
        cin >> ab[i].first >> ab[i].second;
    }
    hld_tree g(n);
    g.input_edges<0>();
    segtree<ar,op,e> seg([&]{
        std::vector<ar> a(n);
        for (int u = 0; u < n; u++){
            a[g.index(u)] = {ab[u].first, ab[u].second, ab[u].second};
        }
        return a;
    }());
    while (q--){
        int t; cin >> t;
        if (t == 0){
            int p, c, d; cin >> p >> c >> d;
            seg.set(g.index(p), {c, d, d});
        }
        if (t == 1){
            int u, v, x; cin >> u >> v >> x;
            ar sml = e(), smr = e();
            g.path_query(u, v, [&](int l, int r){
                if (l < r){
                    smr = op(seg.prod(l, r), smr);
                }
                else {
                    sml = op(sml, flip(seg.prod(r, l)));
                }
            });
            auto [a, b, revb] = op(sml, smr);
            mint ans = a * x + b;
            cout << ans.val() << '\n';
        }
    }
}