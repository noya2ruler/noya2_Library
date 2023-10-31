#pragma once

#include<vector>
#include<span>
#include<algorithm>
#include<utility>

namespace noya2 {

namespace fast_subset_sum {

template<typename T, size_t Extent>
auto inner_subset_sum(std::span<T,Extent> a, bool sorted = false){
    std::vector<T> cur(1<<a.size());
    cur[0] = T(0);
    unsigned int sz = 1;
    for (auto &x : a){
        for (unsigned int s = 0; s < sz; s++){
            cur[sz + s] = cur[s] + x;
        }
        if (sorted) std::inplace_merge(cur.begin(),cur.begin()+sz,cur.begin()+sz*2);
        sz <<= 1;
    }
    return cur;
}

template<typename T, size_t Extent>
auto inner_subset_sum_indexed(std::span<T,Extent> a, bool sorted = false){
    std::vector<std::pair<T,unsigned int>> cur(1<<a.size());
    cur[0] = {T(0),0u};
    unsigned int sz = 1;
    for (unsigned int i = 0; auto &x : a){
        for (unsigned int s = 0; s < sz; s++){
            cur[sz + s].first = cur[s].first + x;
            cur[sz + s].second = cur[s].second | (1u << i);
        }
        if (sorted) std::inplace_merge(cur.begin(),cur.begin()+sz,cur.begin()+sz*2);
        sz <<= 1;
        i++;
    }
    return cur;
}

} // namespace subset_sum

template<typename T>
auto subset_sum(std::vector<T> a, bool sorted = false){
    return fast_subset_sum::inner_subset_sum(std::span{a},sorted);
}

template<typename T>
auto subset_sum_indexed(std::vector<T> a, bool sorted = false){
    return fast_subset_sum::inner_subset_sum_indexed(std::span{a},sorted);
}

template<typename T>
bool half_enumeration(std::vector<T> a, T target){
    int n = a.size(), h = n/2;
    auto le = fast_subset_sum::inner_subset_sum(std::span{a.begin(),a.begin()+h},true);
    auto ri = fast_subset_sum::inner_subset_sum(std::span{a.begin()+h,a.end()},true);
    int lsz = 1<<h, rsz = 1<<(n-h);
    for (int l = 0, r = rsz-1; l < lsz; l++){
        while (r >= 0 && le[l] + ri[r] > target) r--;
        if (r < 0) break;
        if (le[l] + ri[r] == target) return true;
    }
    return false;
}

template<typename T>
long long half_enumeration_indexed(std::vector<T> a, T target){
    int n = a.size(), h = n/2;
    auto le = fast_subset_sum::inner_subset_sum_indexed(std::span{a.begin(),a.begin()+h},true);
    auto ri = fast_subset_sum::inner_subset_sum_indexed(std::span{a.begin()+h,a.end()},true);
    int lsz = 1<<h, rsz = 1<<(n-h);
    for (int l = 0, r = rsz-1; l < lsz; l++){
        while (r >= 0 && le[l].first + ri[r].first > target) r--;
        if (r < 0) break;
        if (le[l].first + ri[r].first == target){
            return ((long long)(ri[r].second) << h) | le[l].second;
        }
    }
    return -1;
}

} // namespace noya2