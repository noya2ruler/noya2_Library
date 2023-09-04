#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include"../../template/template.hpp"
#include"../../tree/tree_query_weighted.hpp"

int main(){
    int n; in(n);
    Tree_weighted g(n);
    g.input(0);
    auto [x, v1, v2] = g.diameter_weighted();
    vector<int> vs = g.path(v1,v2);
    out(x,vs.size());
    out(vs);
}