#pragma once

#include"../template/template.hpp"

template<class E>
struct simple_graph {
    simple_graph (int n_ = 0, int m_ = -1) : n(n_), m(m_) {
        if (m >= 0){
            es.reserve(m);
            start.reserve(m);
        }
    }
    int add_edge(int from, E e){
        int eid = start.size();
        es.emplace_back(e);
        start.emplace_back(from);
        if (eid+1 == m) build();
        return eid;
    }
    void build(){
        if (m == -2) return ;
        m = start.size();
        vector<E> nes(m);
        vector<int> nstart(n+2,0);
        for (int i = 0; i < m; i++) nstart[start[i]+2]++;
        for (int i = 1; i < n; i++) nstart[i+2] += nstart[i+1];
        for (int i = 0; i < m; i++) nes[nstart[start[i]+1]++] = es[i];
        swap(es,nes);
        swap(start,nstart);
        m = -2;
    }
    const auto operator[](int idx) const { return std::ranges::subrange(es.begin()+start[idx],es.begin()+start[idx+1]); }
  private:
    int n, m;
    vector<E> es;
    vector<int> start;
};