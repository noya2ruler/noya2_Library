#pragma once

#include <vector>
#include <tuple>
#include <ranges>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cstdint>

#include"string/z_algorithm.hpp"

namespace noya2 {

std::vector<std::tuple<int,int,int>> run_enumerate(std::string s){
    std::unordered_map<uint64_t,int> periods;
    auto update = [&](int t, int l, int r){
        uint64_t h = ((uint64_t)(l) << 32) | r;
        if (!periods.contains(h) || periods[h] > t){
            periods[h] = t;
        }
    };
    auto dfs = [&](auto sfs, int l, int r) -> void {
        if (r - l == 1) return ;
        int m = (l + r) / 2;
        std::string sl(s.begin() + l, s.begin() + m);
        std::string sr(s.begin() + m, s.begin() + r);
        std::string rev = sl; std::ranges::reverse(rev);
        // L
        {
            auto zl = z_algorithm(rev);
            auto zr = z_algorithm(sr + sl);
            // [i, m) is period
            for (int i = l; i < m; i++){
                int lextend = (i == l ? 0 : zl[m - i]);
                int rextend = zr[r - m + i - l];
                if (rextend == m - i){
                    rextend += zr[m - i];
                    if (rextend > r - m){
                        rextend = r - m;
                    }
                }
                if (lextend + rextend >= m - i){
                    if (i - lextend == l && l > 0) continue;
                    if (m + rextend == r && r < (int)(s.size())) continue;
                    update(m - i, i - lextend, m + rextend);
                }
            }
        }
        std::ranges::reverse_copy(sr, std::back_inserter(rev));
        // R
        {
            // [m, i) is period
            auto zl = z_algorithm(rev);
            auto zr = z_algorithm(sr);
            for (int i = m+1; i <= r; i++){
                int lextend = zl[m - l + r - i];
                if (lextend == i - m){
                    lextend += zl[i - m];
                    if (lextend > m - l){
                        lextend = m - l;
                    }
                }
                int rextend = (i == r ? 0 : zr[i - m]);
                if (lextend + rextend >= i - m){
                    if (m - lextend == l && l > 0) continue;
                    if (i + rextend == r && r < (int)(s.size())) continue;
                    update(i - m, m - lextend, i + rextend);
                }
            }
        }
        sfs(sfs, l, m);
        sfs(sfs, m, r);
    };
    dfs(dfs,0,s.size());
    std::vector<std::tuple<int,int,int>> ret; ret.reserve(periods.size());
    for (auto [lr, t] : periods){
        int r = lr & UINT32_MAX;
        int l = lr >> 32;
        ret.emplace_back(t, l, r);
    }
    std::ranges::sort(ret);
    return ret;
}

} // namespace noya2