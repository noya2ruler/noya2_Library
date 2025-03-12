#pragma once

#include <vector>
#include <queue>
#include <cassert>
#include <bit>
#include <concepts>

namespace noya2 {

// root is vertex 0, par[i] < i
// bool comp(int u, int v), comp(u, v) ? [u, ...] < [v, ...] : [u, ...] >= [v, ...]
// void merge(int u, int v), [p, ...] ++ [v, ...]  -- merge(p, v) -->  [p, ......]
template<bool get_order = true>
std::conditional_t<get_order, std::vector<int>, void> O1onTree(int n, const std::vector<int> &par, auto comp, auto merge){
    if (n == 1){
        if constexpr (get_order){
            return {0};
        }
        else {
            return ;
        }
    }
    assert(ssize(par) == n);
    for (int i = 0; i < n; i++){
        assert(par[i] < i);
    }
    // dsu without weighted union heuristic
    std::vector<int> uf(n, -1);
    // leader is the highest vertex among the connected component
    auto leader = [&](int a){
        auto dfs = [&](auto sfs, int v){
            if (uf[v] < 0) return v;
            return uf[v] = sfs(sfs,uf[v]);
        };
        return dfs(dfs,a);
    };
    // updatable priority_queue using segtree
    int sz = std::bit_ceil<uint32_t>(n);
    std::vector<int> seg(sz);
    std::vector<bool> done(sz, true);
    auto op = [&](int a, int b){
        if (done[b]) return a;
        if (done[a]) return b;
        return comp(a, b) ? a : b;
    };
    // definition of op is updated
    auto update = [&](int i){
        i += sz;
        i >>= 1;
        // segtree leaf i always contains i
        seg[i] = op(i * 2 - sz, i * 2 + 1 - sz);
        while (i > 1){
            i >>= 1;
            seg[i] = op(seg[i * 2], seg[i * 2 + 1]);
        }
    };
    for (int i = 1; i < n; i++){
        done[i] = false;
    }
    for (int i = sz - 1; i >= sz / 2; i--){
        seg[i] = op(i * 2 - sz, i * 2 + 1 - sz);
    }
    for (int i = sz / 2 - 1; i >= 1; i--){
        seg[i] = op(seg[i * 2], seg[i * 2 + 1]);
    }
    std::vector<int> poped_time(n);
    poped_time[0] = 0;
    for (int i = 1; i < n; i++){
        int c = seg[1];
        int p = leader(par[c]);
        done[c] = true;
        merge(p, c);
        uf[c] = p;
        update(c);
        update(p);
        poped_time[c] = i;
    }
    if constexpr (!get_order){
        return ;
    }
    // topological sort of vertex by comparison of poped_time
    std::vector<std::vector<int>> childs(n);
    for (int v = 1; v < n; v++){
        childs[par[v]].emplace_back(v);
    }
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> tvs;
    auto val = [&](int v) -> long long {
        return ((long long)(poped_time[v]) << 32) | v;
    };
    tvs.push(0);
    std::vector<int> order; order.reserve(n);
    const long long mask = (1LL << 32) - 1;
    while (!tvs.empty()){
        int v = tvs.top() & mask; tvs.pop();
        order.emplace_back(v);
        for (int c : childs[v]){
            tvs.push(val(c));
        }
    }
    if constexpr (get_order){
        return order;
    }
}

// root is vertex 0, par[i] < i
template<typename T, bool get_order = true>
requires requires (T x, T y){
    x < y;
    {T::op(x, y)} -> std::same_as<T>;
}
std::conditional_t<get_order, std::vector<int>, T> O1onTree(int n, const std::vector<int> &par, std::vector<T> a){
    assert(ssize(par) == n);
    for (int i = 0; i < n; i++){
        assert(par[i] < i);
    }
    std::vector<int> uf(n, -1);
    auto leader = [&](int aa){
        auto dfs = [&](auto sfs, int v){
            if (uf[v] < 0) return v;
            return uf[v] = sfs(sfs,uf[v]);
        };
        return dfs(dfs,aa);
    };
    using dat = std::pair<T, long long>;
    std::priority_queue<dat, std::vector<dat>, std::greater<dat>> pque;
    for (int i = 1; i < n; i++){
        pque.push({a[i], i});
    }
    const long long mask = (1LL << 32) - 1;
    const int time_max = (1 << 30);
    std::vector<int> latest(n,0);
    std::vector<int> poped_time(n);
    poped_time[0] = 0;
    int idx = 1;
    while (!pque.empty()){
        auto [xc, tc] = pque.top(); pque.pop();
        if (latest[tc & mask] > (tc >> 32)) continue;
        int c = (tc & mask);
        latest[c] = time_max;
        int p = leader(par[c]);
        uf[c] = p;
        a[p] = T::op(a[p], xc);
        if (p != 0){
            latest[p]++;
            pque.push({a[p], ((long long)(latest[p]) << 32) | p});
        }
        poped_time[c] = idx++;
    }
    if constexpr (!get_order){
        return a[0];
    }
    std::vector<std::vector<int>> childs(n);
    for (int v = 1; v < n; v++){
        childs[par[v]].emplace_back(v);
    }
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> tvs;
    auto val = [&](int v) -> long long {
        return ((long long)(poped_time[v]) << 32) | v;
    };
    tvs.push(0);
    std::vector<int> order; order.reserve(n);
    while (!tvs.empty()){
        int v = tvs.top() & mask; tvs.pop();
        order.emplace_back(v);
        for (int c : childs[v]){
            tvs.push(val(c));
        }
    }
    if constexpr (get_order){
        return order;
    }
}

} // namespace noya2