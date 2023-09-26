#pragma once

#include<vector>
#include<ranges>

namespace noya2{

template<class E>
struct vector2d {
    vector2d (int n_ = 0, int m_ = 0) : n(n_), m(m_), inner_element_id(0) {
        es.resize(m);
        start.resize(m,0);
        if (m == 0) build();
    }
    void add(int from, E e){
        es[inner_element_id] = e, start[inner_element_id] = from;
        if (++inner_element_id == m) build();
    }
    const auto operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]); }
    std::vector<int> start;
  private:
    void build(){
        std::vector<E> nes(m);
        std::vector<int> nstart(n+1,0);
        for (int i = 0; i < m; i++) nstart[start[i]+1]++;
        for (int i = 0; i < n; i++) nstart[i+1] += nstart[i];
        auto geta = nstart;
        for (int i = 0; i < m; i++) nes[geta[start[i]]++] = es[i];
        std::swap(nes,es); std::swap(nstart,start);
    }
    int n, m, inner_element_id;
    std::vector<E> es;
};

} // namespace noya2