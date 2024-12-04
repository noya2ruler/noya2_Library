#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include"../../template/template.hpp"
#include"../../string/run_enumerate.hpp"

int main(){
    string s; in(s);
    auto ans = run_enumerate(s);
    out(ans.size());
    for (auto [t, l, r] : ans){
        out(t,l,r);
    }
}