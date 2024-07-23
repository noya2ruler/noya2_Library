#pragma once

#include <vector>
#include <algorithm>
#include <limits>

namespace noya2 {

template<typename T>
std::vector<int> longest_increasing_subsequence_ids(const std::vector<T> &a){
    if (a.empty()) return {};
    int n = a.size();
    const T Tinf = std::numeric_limits<T>::max();
    std::vector<T> dp(n, Tinf);
    std::vector<int> pre(n), ids(n);
    for (int i = 0; i < n; i++){
        int pos = std::lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[pos] = a[i];
        ids[pos] = i;
        pre[i] = (pos == 0 ? -1 : ids[pos-1]);
    }
    int len = std::lower_bound(dp.begin(), dp.end(), Tinf) - dp.begin();
    ids.resize(len);
    int cid = ids[len-1];
    for (int i = len-1; i >= 0; i--){
        ids[i] = cid;
        cid = pre[cid];
    }
    return ids;
}

} // namespace noya2