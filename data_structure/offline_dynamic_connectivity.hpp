#pragma once

#include"../data_structure/rollback_dsu.hpp"

#include <vector>
#include <utility>
#include <cassert>

namespace noya2 {

struct offline_dynamic_connectivity : rollback_dsu {
    using rollback_dsu::operator=;
    offline_dynamic_connectivity () {}
    offline_dynamic_connectivity (int _n, unsigned int t_max, size_t reserve_edge = 0) : n(_n) {
        sz = bit_ceil(t_max);
        ids.resize(sz*2);
        *this = rollback_dsu(n);
        edges.reserve(reserve_edge);
        inner_clock = -1;
    }
    // for time interval [l, r), connect u, v
    void add_edge(int l, int r, int u, int v){
        assert(0 <= l && l <= r && r <= sz);
        assert(0 <= u && u < n && 0 <= v && v < n);
        l += sz, r += sz;
        int edge_id = edges.size();
        while (l < r){
            if (l & 1) ids[l++].push_back(edge_id);
            if (r & 1) ids[--r].push_back(edge_id);
            l >>= 1, r >>= 1;
        }
        edges.emplace_back(u,v);
    }
    void build(){
        inner_clock = 1;
        while (true){
            add_block(inner_clock);
            if (inner_clock == sz) break;
            inner_clock <<= 1;
        }
    }
    // leap to time t, change this dsu
    void set(int t){
        assert(0 <= t && t < sz && inner_clock != -1);
        t += sz;
        if (inner_clock == t) return ;
        int k = 32 - countl_zero((unsigned int)(inner_clock ^ t));
        for (int i = 0; i < k; i++){
            del_block(inner_clock);
            inner_clock >>= 1;
        }
        for (int i = k-1; i >= 0; i--){
            inner_clock <<= 1;
            if (t >> i & 1) inner_clock++;
            add_block(inner_clock);
        }
        inner_clock = t;
    }
  private:
    void add_block(int i){
        for (auto &id : ids[i]){
            this->merge(edges[id].first,edges[id].second);
        }
    }
    void del_block(int i){
        int ctr = ids[i].size();
        while (ctr--) this->rollback();
    }
    int n, sz, inner_clock;
    std::vector<std::vector<int>> ids;
    std::vector<std::pair<int,int>> edges;
};

} // namespace noya2