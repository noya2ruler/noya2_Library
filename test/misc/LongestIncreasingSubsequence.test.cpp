#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include"../../template/template.hpp"
#include"../../misc/longest_increasing_subsequence.hpp"

int main(){
    int n; in(n);
    vector<int> a(n); in(a);
    auto ans = longest_increasing_subsequence_ids(a);
    out(ans.size());
    out(ans);
}