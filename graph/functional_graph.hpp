#pragma once

#include <vector>
#include <cassert>
#include <ranges>
#include <utility>

namespace noya2 {

struct functional_graph {
    int n;
    std::vector<int> f;
    // down[v] is length_of_cycle + euler_tour_time starting root of v
    // sub[v] is subtree_size of v "- 1"
    std::vector<int> down, sub;
    std::vector<int> depth_or_cycleposition, root_or_leader;
    functional_graph (const std::vector<int> &_f) : n(_f.size()), f(_f), sub(n, 0), depth_or_cycleposition(n, 0), root_or_leader(n) {
        std::vector<int> deg(n, 0);
        for (int v = 0; v < n; v++){
            assert(0 <= f[v] && f[v] < n);
            deg[f[v]]++;
            root_or_leader[v] = v;
        }
        std::vector<int> ord; ord.reserve(n);
        for (int v = 0; v < n; v++){
            if (deg[v] == 0){
                ord.emplace_back(v);
            }
        }
        for (int i = 0; i < (int)(ord.size()); i++){
            int v = ord[i];
            sub[f[v]] += sub[v] + 1;
            if (--deg[f[v]] == 0){
                ord.emplace_back(f[v]);
            }
        }
        down = sub;
        for (int v = 0; v < n; v++){
            if (deg[v] == 0) continue;
            int start = v, length = 0;
            do {
                v = f[v];
                length++;
            } while(v != start);
            do {
                down[v] += length;
                v = f[v];
            } while(v != start);
        }
        for (int v : ord | std::views::reverse){
            int p = f[v];
            down[v] = std::exchange(down[p], down[p] - down[v] - 1);
            depth_or_cycleposition[v] = depth_or_cycleposition[p] + 1;
            root_or_leader[v] = root_or_leader[p];
        }
        for (int v = 0; v < n; v++){
            if (deg[v] == 0) continue;
            int start = v, pos = 0;
            do {
                depth_or_cycleposition[v] = ~pos;
                root_or_leader[v] = ~start;
                v = f[v];
                pos++;
            } while(v != start);
        }
    }
    // nearest cycle point
    int root(int v) const {
        return (root_or_leader[v] < 0 ? v : root_or_leader[v]);
    }
    // component leader
    int leader(int v) const {
        return ~root_or_leader[root(v)];
    }
    bool reachable(int from, int to) const {
        if (leader(from) != leader(to)) return false;
        if (on_cycle(to)) return true;
        if (root(from) != root(to)) return false;
        return down[to] <= down[from] && down[from]+sub[from] <= down[to]+sub[to];
    }
    bool on_cycle(int v) const {
        return (root_or_leader[v] < 0);
    }
    int depth(int v) const {
        return (depth_or_cycleposition[v] < 0 ? 0 : depth_or_cycleposition[v]);
    }
    int cycle_length(int v) const {
        return down[root(v)];
    }
    int dist(int from, int to) const {
        if (!reachable(from, to)) return -1;
        if (!on_cycle(to)){
            return depth(from) - depth(to);
        }
        int ret = depth(from);
        from = root(from);
        int pos_from = ~depth_or_cycleposition[from];
        int pos_to = ~depth_or_cycleposition[to];
        ret += pos_to - pos_from;
        if (pos_from > pos_to){
            ret += down[from]; // += cycle length
        }
        return ret;
    }
    bool on_simple_path(int via, int from, int to) const {
        if (!reachable(from, via) || !reachable(via, to)) return false;
        if (!on_cycle(via)){
            return true;
        }
        from = root(from);
        return (dist(from, via) + dist(via, to) == dist(from, to));
    }
    int operator[](int idx) const {
        return f[idx];
    }
    // subrange cycle(int leader?)
};

} // namespace noya2