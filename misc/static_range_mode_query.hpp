#pragma once

#include <vector>
#include <utility>
#include <cassert>

namespace noya2 {

struct static_range_mode_query {
    const int w = 320;
    std::vector<int> a;
    std::vector<std::vector<int>> ids;
    std::vector<std::vector<std::pair<int,int>>> pre;
    std::vector<int> pos;
    std::vector<int> buf;
    // a[i] in [0, n), n = a.size()
    static_range_mode_query (const std::vector<int> _a) : a(_a), ids(_a.size()) {
        int n = a.size(), sz = n / w;
        pos.resize(n);
        ids.resize(n);
        for (int i = 0; i < n; i++){
            assert(0 <= a[i] && a[i] < n);
            pos[i] = ids[a[i]].size();
            ids[a[i]].emplace_back(i);
        }
        pre.resize((sz+1),std::vector<std::pair<int,int>>(sz+1));
        for (int l = 0; l < sz; l++){
            std::vector<int> cnt(n,0);
            int ma = -1, id = -1;
            for (int r = l+1; r <= sz; r++){
                for (int i = (r-1)*w; i < r*w; i++){
                    if (++cnt[a[i]] > ma){
                        ma = cnt[a[i]];
                        id = a[i];
                    }
                }
                pre[l][r] = {id, ma};
            }
        }
        buf.resize(n, 0);
    }
    std::pair<int,int> prod_naive(int l, int r){
        int ma = -1, id = -1;
        for (int i = l; i < r; i++){
            if (++buf[a[i]] > ma){
                ma = buf[a[i]];
                id = a[i];
            }
        }
        for (int i = l; i < r; i++){
            --buf[a[i]];
        }
        return {id, ma};
    }
    std::pair<int,int> prod(int l, int r){
        assert(0 <= l && l < r && r <= (int)(a.size()));
        // li = ceil(l / w), ri = floor(r / w)
        int li = (l + w - 1) / w, ri = r / w;
        if (li >= ri){
            return prod_naive(l, r);
        }
        auto [id, ma] = pre[li][ri];
        for (int i = l; i < li*w; i++){
            int p = pos[i] + ma;
            if (p >= (int)(ids[a[i]].size())) continue;
            if (ids[a[i]][p] < r){
                ma++;
                id = a[i];
                i--;
            }
        }
        for (int i = ri*w; i < r; i++){
            int p = pos[i] - ma;
            if (p < 0) continue;
            if (ids[a[i]][p] >= l){
                ma++;
                id = a[i];
                i--;
            }
        }
        return {id, ma};
    }
};

} // namespace noya2