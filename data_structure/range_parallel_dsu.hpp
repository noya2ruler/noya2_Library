#pragma once

#include"data_structure/dsu.hpp"

namespace noya2 {

struct range_parallel_dsu : dsu {
    using dsu::operator=;
    int n;
    std::vector<dsu> ds;
    range_parallel_dsu (int _n0) : n(_n0) {
        int msb = 31 - countl_zero((unsigned int)(n));
        ds.resize(msb, dsu(n));
        (*this) = dsu(n);
    }
    // for k = 0, 1, ... ,d-1
    // merge(i+k,j+k)
    std::vector<std::tuple<int,int,int>> merge_range(int i, int j, int d){
        assert(i + d <= n);
        assert(j + d <= n);
        if (d == 0) return {};
        int msb = std::bit_width((unsigned int)(d)) - 1;
        std::vector<std::tuple<int,int,int>> connected;
        inner_merge(i, j, msb, connected);
        inner_merge(i + d - (1<<msb), j + d - (1<<msb), msb, connected);
        return connected;
    }
  private:
    // d = 2^k
    void inner_merge(int i, int j, int k, std::vector<std::tuple<int,int,int>> &connected){
        // k >= 0
        if (k == 0){
            i = this->leader(i);
            j = this->leader(j);
            if (i == j) return ;
            int l = this->merge(i, j);
            connected.emplace_back(i, j, l);
        }
        else {
            k--;
            if (ds[k].same(i, j)) return ;
            ds[k].merge(i, j);
            inner_merge(i, j, k, connected);
            inner_merge(i + (1<<k), j + (1<<k), k, connected);
        }
    }
};

} // namespace noya2