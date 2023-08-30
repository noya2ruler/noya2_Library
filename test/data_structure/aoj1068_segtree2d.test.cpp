#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"

#include"../../template/template.hpp"
#include"../../data_structure/segment_tree_2d.hpp"

int op(int a, int b){
    return min(a,b);
}
int e(){
    return numeric_limits<int>::max();
}

void solve(int h, int w, int q){
    vector<vector<int>> a(h,vector<int>(w)); in(a);
    segtree_2d<int,op,e> seg(a);
    while (q--){
        int lx, rx, ly, ry; in(lx,ly,rx,ry); rx++, ry++;
        out(seg.prod(lx,rx,ly,ry));
    }
}

int main(){
    while(true){
        int h, w, q; in(h,w,q);
        if (h == 0) break;
        solve(h,w,q);
    }
}