#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include"../../template/template.hpp"

#include"../../data_structure/sparce_table.hpp"

int op(int a, int b){
    return min(a,b);
}

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n); cin >> a;
    SparseTable<int,op> spt(a);
    while (q--){
        int l, r; cin >> l >> r;
        cout << spt.get(l,r) << '\n';
    }
}