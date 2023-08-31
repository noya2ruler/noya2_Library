#pragma once

#include"../template/template.hpp"
#include"../data_structure/compress.hpp"

namespace noya2 {

template<class M, template<class MM> class data_structure, typename Idx = ll>
struct range_tree {
    using DS = data_structure<M>;
    using T = typename M::value_type;
    void join(Idx x, Idx y){ ps.emplace_back(x,y); }
    void build(){
        for (auto &[x, y] : ps) xs.add(x);
        xs.build();
        //siz = bit_ceil(xs.size());
        siz = 1; while (siz < (int)(xs.size())) siz <<= 1;
        ys.resize(siz*2);
        for (auto &[x, y] : ps){
            int xid = xs.id(x) + siz;
            ys[xid].add(y);
            while (xid > 1){
                xid >>= 1;
                ys[xid].add(y);
            }
        }
        for (int i = 0; i < 2*siz; i++){
            ys[i].build();
            ds.emplace_back(ys[i].size());
        }
    }
    void set(Idx p, Idx q, T val){
        int i = xs.id(p) + siz;
        ds[i].set(ys[i].id(q),val);
        while (i > 1){
            i >>= 1;
            T lr = M::e();
            int i0 = ys[2*i+0].contains_id(q), i1 = ys[2*i+1].contains_id(q);
            if (i0 != -1) lr = M::op(lr, ds[2*i+0].get(i0));
            if (i1 != -1) lr = M::op(lr, ds[2*i+1].get(i1));
            ds[i].set(ys[i].id(q),lr);
        }
    }
    T get(Idx p, Idx q){
        int ip = xs.contains_id(p);
        if (ip == -1) return M::e();
        int i = ip + siz;
        int iq = ys[i].contains_id(q);
        if (iq == -1) return M::e();
        return ds[i].get(iq);
    }
    T prod(Idx lp, Idx rp, Idx lq, Idx rq){
        T res = M::e();
        int li = xs.lb(lp), ri = xs.lb(rp);
        for (li += siz, ri += siz; li < ri; li >>= 1, ri >>= 1){
            if (li & 1) res = M::op(res,ds[li].prod(ys[li].lb(lq),ys[li].lb(rq))), ++li;
            if (ri & 1) --ri, res = M::op(res,ds[ri].prod(ys[ri].lb(lq),ys[ri].lb(rq)));
        }
        return res;
    }
    int siz;
    vector<pair<Idx,Idx>> ps;
    compress<Idx> xs;
    vector<compress<Idx>> ys;
    vector<DS> ds;
};

} // namespace noya2