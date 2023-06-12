#pragma once

#include<bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)
#define all(v) v.begin(),v.end()

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

namespace noya2{

/*　~ (. _________ . /)　*/

}

using namespace noya2;

template <typename T> bool chmin(T &a, const T &b) {
    if (a <= b) return false;
    a = b;
    return true;
}
template <typename T> bool chmax(T &a, const T &b) {
    if (a >= b) return false;
    a = b;
    return true;
}

template<class T>istream &operator>>(istream &is, vector<T> &v){
    for (auto &e : v) is >> e;
    return is;
}

void fast_io(){
    cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(15);
}

const int iinf = 1'000'000'007;
const ll linf = 2e18;