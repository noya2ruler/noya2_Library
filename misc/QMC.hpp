#pragma once

/*

実装の参考にした：
https://i05nagai.github.io/memorandum/math/sobol_sequence.html

sobol<32> sb({0,1});
ll id = 0;
ll x = sb.get(++id);

などのようにして使う。コンストラクタには既約多項式を投げる。
5次以下の既約多項式一覧：
https://yoshiiz.blog.fc2.com/blog-entry-199.html

*/

#include"../template/template.hpp"

namespace noya2{

random_device rd;
mt19937_64 mt_for_sobol(rd());

template<int bk>
struct sobol{
    vector<ll> ms, vs;
    sobol (const vector<ll> &f){
        int s = f.size() - 1;
        ms.resize(bk);
        for (int i = 0; i < s; i++){
            ms[i] = 2 * (mt_for_sobol() % (1LL << i)) + 1;
        }
        for (int j = s; j < bk; j++){
            ms[j] = ms[j-s];
            for (int i = 1; i <= s; i++){
                ms[j] ^= (f[i] << i) * ms[j-i];
            }
        }
        vs.resize(bk);
        for (int i = 0; i < bk; i++){
            vs[i] = ms[i] << (bk-1-i);
        }
    }
    ll get(ll id){
        ll res = 0;
        for (int i = 0; i < bk; i++){
            res ^= (id >> i & 1) * vs[i];
        }
        return res;
    }
    ld getld(ll id, ld lo, ld hi){
        return lo + (hi - lo) * ld(get(id)) / d;
    }
    static constexpr ld d = 1LL<<bk;
};

} // namespace noya2