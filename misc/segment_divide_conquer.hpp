#pragma once

#include"data_structure/csr.hpp"

namespace noya2 {

struct segment_divide_conquer {
    int tmax, sz;
    internal::csr<int> events;
    segment_divide_conquer (int _tmax) : tmax(_tmax){
        sz = std::bit_ceil<uint32_t>(tmax);
        events = internal::csr<int>(sz*2);
    }
    void add_event(int tl, int tr, int id){
        tl += sz, tr += sz;
        while (tl < tr){
            if (tl & 1){
                events.add(tl++, id);
            }
            if (tr & 1){
                events.add(--tr, id);
            }
            tl >>= 1;
            tr >>= 1;
        }
    }
    // void apply(int eventid);
    // void rollback(int eventid);
    // void query(int t);
    void run(auto apply, auto rollback, auto query){
        events.build();
        auto dfs = [&](auto sfs, int p) -> void {
            for (int id : events[p]){
                apply(id);
            }
            if (p >= sz){
                p -= sz;
                if (p < tmax){
                    query(p);
                }
                p += sz;
            }
            else {
                sfs(sfs, p * 2);
                sfs(sfs, p * 2 + 1);
            }
            for (int id : events[p] | std::views::reverse){
                rollback(id);
            }
        };
        dfs(dfs,1);
    }
};

} // namespace noya2