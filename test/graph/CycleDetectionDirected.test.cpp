#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include"../../template/template.hpp"
#include"../../graph/cycle_detection.hpp"

int main(){
    int n, m; in(n,m);
    vector<pii> es(m); in(es);
    auto res = cycle_detection_directed(n,es);
    if (!res){
        out(-1);
        return 0;
    }
    auto cycle = res.value();
    out(cycle.size());
    for (auto i : cycle){
        out(i);
    }
}