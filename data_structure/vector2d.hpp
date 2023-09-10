#pragma once

#include<vector>
#include<ranges>

namespace noya2{

template<class E>
struct vector2d {
    vector2d (int n_ = 0, int m_ = -1) : n(n_), m(m_) {
        if (m == -1) m = n-1;
        es.resize(m);
        start.resize(m,0);
        if (m == 0) build();
    }
    void add(int from, E e){
        static int id = 0;
        es[id] = e, start[id] = from;
        if (++id == m) build();
    }
    const auto operator[](int idx){ return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]); }
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
    int n, m;
    std::vector<E> es;
    std::vector<int> start;
};

} // namespace noya2