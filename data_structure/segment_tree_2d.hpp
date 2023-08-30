#pragma once

#include<vector>

namespace noya2{

template<class S, S(*op)(S, S), S(*e)()>
struct segtree_2d {
    int h, w;
    segtree_2d (int h_ = 1, int w_ = 0) : segtree_2d(std::vector<std::vector<S>>(h_,vector<S>(w_,e()))) {}
    segtree_2d (const std::vector<std::vector<S>> &vec){
        assert(!vec.empty());
        h = bit_ceil(vec.size()), w = bit_ceil(vec[0].size());
        d.assign(h*w*4,e());
        for (int i = 0; i < (int)(vec.size()); i++) for (int j = 0; j < (int)(vec[i].size()); j++) d[id(i+h,j+w)] = vec[i][j];
        for (int i = 0; i < h; i++) for (int j = w-1; j > 0; j--) update_y(i+h,j);
        for (int i = h-1; i > 0; i--) for (int j = 1; j < 2*w; j++) update_x(i,j);
    }
    void assign(int p, int q, S v){
        d[id(p+h,q+w)] = v;
    }
    void set(int p, int q, S v){
        p += h, q += w;
        d[id(p,q)] = v;
        for (int j = q>>1; j > 0; j >>= 1) update_y(p,j);
        for ( ; q > 0; q >>= 1) for (int i = p>>1; i > 0; i >>= 1) update_x(i,q);
    }
    S prod(int lp, int rp, int lq, int rq){
        if (lp >= rp || lq >= rq) return e();
        S res = e();
        lp += h, rp += h, lq += w, rq += w;
        for ( ; lp < rp; lp >>= 1, rp >>= 1){
            if (lp & 1) res = op(res,inner_prod(lp++,lq,rq));
            if (rp & 1) res = op(res,inner_prod(--rp,lq,rq));
        }
        return res;
    }
    S get(int p, int q){
        p += h, q += w;
        return d[id(p,q)];
    }
    int id(int p, int q){ return p * 2 * w + q; }
    void update_x(int p, int q){ d[id(p,q)] = op(d[id(2*p,q)],d[id(2*p+1,q)]); }
    void update_y(int p, int q){ d[id(p,q)] = op(d[id(p,2*q)],d[id(p,2*q+1)]); }
    S inner_prod(int p, int lq, int rq){
        S res = e();
        for ( ; lq < rq; lq >>= 1, rq >>= 1){
            if (lq & 1) res = op(res,d[id(p,lq++)]);
            if (rq & 1) res = op(res,d[id(p,--rq)]);
        }
        return res;
    }
    std::vector<S> d;
};

} // namespace noya2