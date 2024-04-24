#pragma once

#include"data_structure/dsu.hpp"

namespace noya2 {

struct range_parallel_dsu {
    int n;
    std::vector<dsu> ds;
    range_parallel_dsu (int _n) : n(_n) {
        int msb = 31 - countl_zero((unsigned int)(n));
        ds.resize(msb+1,dsu(n));
    }
    // for k = 0, 1, ... ,d-1
    // merge(i+k,j+k)
    void merge(int i, int j, int d){
        assert(i + d <= n);
        assert(j + d <= n);
        if (d == 0) return ;
        int k2 = std::bit_floor((unsigned int)(d));
        int msb = 31 - countl_zero((unsigned int)(k2));
        inner_merge(i, j, msb);
        inner_merge(i + d - k2, j + d - k2, msb);
    }
    int same(int i, int j){
        return ds[0].same(i, j);
    }
    int size(int i){
        return ds[0].size(i);
    }
    int leader(int i){
        return ds[0].leader(i);
    }
  private:
    // d = 2^k
    void inner_merge(int i, int j, int k){
        // k >= 0
        if (ds[k].same(i, j)) return ;
        ds[k].merge(i,j);
        if (k >= 1){
            inner_merge(i, j, k-1);
            inner_merge(i + (1<<(k-1)), j + (1<<(k-1)), k-1);
        }
    }
};

} // namespace noya2