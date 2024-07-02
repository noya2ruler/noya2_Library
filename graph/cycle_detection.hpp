#pragma once

#include <optional>
#include <vector>
#include <utility>
#include <algorithm>

#include"data_structure/csr.hpp"

namespace noya2 {

std::optional<std::vector<int>> cycle_detection_directed(int n, const std::vector<std::pair<int,int>> &es){
    internal::csr<std::pair<int,int>> g(n,es.size());
    for (int i = 0; auto [u, v] : es){
        g.add(u,std::pair<int,int>(v, i));
        i++;
    }
    g.build();
    std::vector<bool> seen(n,false), done(n,false);
    std::vector<int> cycle;
    // -1:over,-2:done
    auto dfs = [&](auto sfs, int v, int pid) -> int {
        if (seen[v]) return v;
        if (done[v]) return -1;
        seen[v] = true;
        for (auto &[to, eid] : g[v]) if (eid != pid){
            int nxt = sfs(sfs, to, eid);
            if (nxt != -1){
                if (nxt == -2) return -2;
                cycle.emplace_back(eid);
                if (nxt == v) return -2;
                return nxt;
            }
        }
        seen[v] = false;
        done[v] = true;
        return -1;
    };
    for (int i = 0; i < n; i++){
        if (dfs(dfs, i, -1) == -2){
            std::reverse(cycle.begin(), cycle.end());
            return cycle;
        }
    }
    return std::nullopt;
}

} // namespace noya2