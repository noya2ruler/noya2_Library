#pragma once

#include<vector>
#include<ranges>
#include<cassert>
#include<utility>

namespace noya2 {

template<class E>
struct csr {
    csr (int n_ = 0, int m_ = -1) : n(n_), m(m_) {
        if (m >= 0){
            es.reserve(m);
            start.reserve(m);
        }
        if (m == 0){
            build();
        }
    }
    int add(int idx, E elem){
        int eid = start.size();
        es.emplace_back(elem);
        start.emplace_back(idx);
        if (eid+1 == m) build();
        return eid;
    }
    void build(){
        if (m == -2) return ;
        m = start.size();
        std::vector<E> nes(m);
        std::vector<int> nstart(n+2,0);
        for (int i = 0; i < m; i++) nstart[start[i]+2]++;
        for (int i = 1; i < n; i++) nstart[i+2] += nstart[i+1];
        for (int i = 0; i < m; i++) nes[nstart[start[i]+1]++] = es[i];
        swap(es,nes);
        swap(start,nstart);
        m = -2;
    }
    const auto operator[](int idx) const {
        assert(m == -2);
        return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]);
    }
  private:
    int n, m;
    std::vector<E> es;
    std::vector<int> start;
};

} // namespace noya2