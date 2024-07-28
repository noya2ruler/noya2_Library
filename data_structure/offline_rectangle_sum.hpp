#pragma once

#include"../data_structure/binary_indexed_tree.hpp"
#include"../data_structure/csr.hpp"
#include"../misc/monoids.hpp"

namespace noya2 {

template<Group G = plus_group<ll>>
struct offline_rectangle_sum {
    using T = typename G::value_type;
    int h, w, query_id;
    internal::csr<pair<int,T>> elems;
    internal::csr<tuple<int,int,int>> queries;
    offline_rectangle_sum () {}
    offline_rectangle_sum (int h_, int w_) : h(h_), w(w_), query_id(0), elems(h_), queries(h_+1) {}
    offline_rectangle_sum (int h_, int w_, int m) : h(h_), w(w_), query_id(0), elems(h_,m), queries(h_+1) {}
    offline_rectangle_sum (int h_, int w_, int m, int q) : h(h_), w(w_), query_id(0), elems(h_,m), queries(h_+1,q*2) {}
    void add_elem(int x, int y, T e){
        elems.add(x,pair<int,T>(y,e));
    }
    void add_query(int lx, int rx, int ly, int ry){
        queries.add(lx,tuple<int,int,int>(ly,ry,-1-query_id));
        queries.add(rx,tuple<int,int,int>(ly,ry,query_id));
        query_id++;
    }
    vector<T> run(){
        elems.build();
        queries.build();
        BinaryIndexedTree<G> fen(w);
        vector<T> ans(query_id,G::e());
        for (int x = 0; ; x++){
            for (auto [ly, ry, qid] : queries[x]){
                if (qid >= 0){
                    ans[qid] = G::op(ans[qid],fen.prod(ly,ry));
                }
                else {
                    ans[-1-qid] = G::op(ans[-1-qid],G::inv(fen.prod(ly,ry)));
                }
            }
            if (x == h) break;
            for (auto [y, e] : elems[x]){
                fen.add(y,e);
            }
        }
        return ans;
    }
};

} // namespace noya2