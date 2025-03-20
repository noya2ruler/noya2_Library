#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include"../../template/template.hpp"
#include"../../tree/cartesian_tree.hpp"

int main(){
    int n; in(n);
    vector<int> a(n); in(a);
    auto [root, par] = cartesian_tree(a);
    out(par);
}