#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include"../../template/template.hpp"
#include"../../data_structure/binary_trie.hpp"

int main(){
    binary_trie<int,31> bt;
    int q; in(q);
    while (q--){
        int t; in(t);
        int x; in(x);
        if (t == 0){
            bt.insert(x);
        }
        if (t == 1){
            bt.erase(x);
        }
        if (t == 2){
            bt.xor_all(x);
            out(bt.get(0));
            bt.xor_all(x);
        }
    }
}