#define PROBLEM "https://judge.yosupo.jp/problem/aho_corasick"

#include"../../template/template.hpp"
#include"../../string/aho_corasick.hpp"

int main(){
    int n; in(n);
    aho_corasick aho(1e6);
    vector<int> vs(n);
    rep(i,n){
        string s; in(s);
        vs[i] = aho.insert(s);
    }
    aho.build();
    int sz = aho.size();
    out(sz);
    repp(v,1,sz){
        out(aho[v].par,aho[v].link);
    }
    out(vs);
}