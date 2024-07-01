#pragma once

#include<vector>
#include<ranges>
#include<cassert>
#include<utility>

namespace noya2::internal {

template<class E>
struct csr {
    csr () {}
    csr (int _n) : n(_n) {}
    csr (int _n, int m) : n(_n){
        start.reserve(m);
        elist.reserve(m);
    }
    // ACL style constructor (do not have to call build)
    csr (int _n, const std::vector<std::pair<int,E>> &idx_elem) : n(_n), start(_n + 2), elist(idx_elem.size()) {
        for (auto &[i, e] : idx_elem){
            start[i + 2]++;
        }
        for (int i = 1; i < n; i++){
            start[i + 2] += start[i + 1];
        }
        for (auto &[i, e] : idx_elem){
            elist[start[i + 1]++] = e;
        }
        prepared = true;
    }
    int add(int idx, E elem){
        int eid = start.size();
        start.emplace_back(idx);
        elist.emplace_back(elem);
        return eid;
    }
    void build(){
        if (prepared) return ;
        int m = start.size();
        std::vector<E> nelist(m);
        std::vector<int> nstart(n + 2, 0);
        for (int i = 0; i < m; i++){
            nstart[start[i] + 2]++;
        }
        for (int i = 1; i < n; i++){
            nstart[i + 2] += nstart[i + 1];
        }
        for (int i = 0; i < m; i++){
            nelist[nstart[start[i] + 1]++] = elist[i];
        }
        swap(elist,nelist);
        swap(start,nstart);
        prepared = true;
    }
    const auto operator[](int idx) const {
        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);
    }
    auto operator[](int idx){
        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);
    }
    const auto operator()(int idx, int l, int r) const {
        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);
    }
    auto operator()(int idx, int l, int r){
        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);
    }
    int n;
    std::vector<int> start;
    std::vector<E> elist;
    bool prepared = false;
};

} // namespace noya2::internal