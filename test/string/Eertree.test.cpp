#define PROBLEM "https://judge.yosupo.jp/problem/eertree"

#include"../../template/template.hpp"
#include"../../string/eertree.hpp"

int main(){
    string s; in(s);
    int n = s.size();
    eertree et;
    vector<pii> pss;
    vector<int> vs; vs.reserve(n);
    int ma = 1;
    for (auto c : s){
        auto [v, cp, sp] = et.add_char(c - 'a');
        if (ma < v){
            pss.emplace_back(cp-1,sp-1);
            ma = v;
        }
        vs.emplace_back(v-1);
    }
    out(pss.size());
    for (auto &ps : pss) out(ps);
    out(vs);
}