#pragma once

#include"template/template.hpp"

namespace noya2{

template<typename T>
struct LiChaoTree {
    static const T ymax = 3e18;
    struct Line {
        T a, b;
        Line (T _a = 0, T _b = ymax) : a(_a), b(_b) {}
        T get(T x){return a * x + b;}
    };
    LiChaoTree (const vector<T> &_xs){
        xs = _xs;
        sort(xs.begin(),xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
        int _n = xs.size();
        n = 1;
        while (n < _n) n *= 2;
        xs.resize(n);
        for (int i = _n; i < n; i++) xs[i] = xs[_n-1];
        seg.resize(n*2-1);
    }
    void line_add(T a, T b){ inner_line_add(Line(a,b),0,0,n);}
    void segment_add(T a, T b, T l, T r){
        int sl = lower_bound(xs.begin(),xs.end(),l) - xs.begin();
        int sr = lower_bound(xs.begin(),xs.end(),r) - xs.begin();
        inner_segment_add(sl,sr,Line(a,b),0,0,n);
    }
    T get(T x){
        int s = lower_bound(xs.begin(),xs.end(),x) - xs.begin();
        s += n-1;
        T res = ymax;
        res = min(res,seg[s].get(x));
        while (s > 0){
            s = (s-1) / 2;
            res = min(res,seg[s].get(x));
        }
        return res;
    }
  private:
    int n;
    vector<T> xs;
    vector<Line> seg;
    void inner_line_add(Line L, int i, int l, int r){
        T la = L.get(xs[l]);
        T lb = seg[i].get(xs[l]);
        T ra = L.get(xs[r-1]);
        T rb = seg[i].get(xs[r-1]);
        if (la >= lb && ra >= rb) return ;
        if (la <= lb && ra <= rb) {
            seg[i] = L;
            return ;
        }
        int m = (l + r) / 2;
        T ma = L.get(xs[m]);
        T mb = seg[i].get(xs[m]);
        if (ma < mb){
            swap(L,seg[i]);
            swap(la,lb);
            swap(ra,rb);
        }
        if (la < lb) inner_line_add(L,2*i+1,l,m);
        if (ra < rb) inner_line_add(L,2*i+2,m,r);
    }
    void inner_segment_add(int L, int R, Line S, int i, int l, int r){
        if (r <= L || R <= l) return ;
        if (L <= l && r <= R) inner_line_add(S,i,l,r);
        else {
            int m = (l + r) / 2;
            inner_segment_add(L,R,S,2*i+1,l,m);
            inner_segment_add(L,R,S,2*i+2,m,r);
        }
    }
};

} // namespace noya2