#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include"../../template/template.hpp"
#include"../../math/bitwise_convolution.hpp"
#include"utility/modint.hpp"
using mint = modint998244353;

int main(){
    int n; in(n);
    vector<mint> a(1<<n), b(1<<n); in(a,b);
    out(bitwise_xor_convolution(a,b));
}