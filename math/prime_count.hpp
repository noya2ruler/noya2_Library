#pragma once

#include <vector>
#include <cmath>

namespace noya2 {

// ref : https://judge.yosupo.jp/submission/182619

// #{p : prime | p <= n}. n <= 10^13
long long prime_count(long long n){
    struct S {
        int rough;
        long long large;
        int id;
    };
    if (n <= 1) return 0;
    const int v = static_cast<int>(sqrtl(n));
    int pc = 0;
    std::vector<int> smalls(v + 1);
    for (int i = 2; i <= v; i++){
        smalls[i] = (i + 1) / 2;
    }
    std::vector<int> skip(v + 1, false);
    std::vector<S> z((v + 1) / 2);
    for (int i = 0; i < (v + 1) / 2; i++){
        z[i] = {2 * i + 1, (n / (2 * i + 1) + 1) / 2, i};
    }
    for (int p = 3; p <= v; p++){
        if (smalls[p] <= smalls[p - 1]) continue;
        const int q = p * p;
        pc++;
        if (1LL * q * q > n) break;
        skip[p] = true;
        for (int i = q; i <= v; i += 2 * p){
            skip[i] = true;
        }
        int ns = 0;
        for (auto e : z){
            if (skip[e.rough]) continue;
            long long d = 1LL * e.rough * p;
            e.large += pc - (d <= v ? z[smalls[d] - pc].large : smalls[n / d]);
            e.id = ns;
            z[ns++] = e;
        }
        z.resize(ns);
        for (int j = v / p; j >= p; --j){
            const int c = smalls[j] - pc, e = std::min(j * p + p, v + 1);
            for (int i = j * p; i < e; i++){
                smalls[i] -= c;
            }
        }
    }
    long long ans = z[0].large;
    z.erase(z.begin());
    for (auto &[rough, large, k] : z){
        const long long m = n / rough;
        k--;
        ans -= large - (pc + k);
        for (auto [p, _, l] : z){
            if (l >= k || p * p > m) break;
            ans += smalls[m / p] - (pc + l);
        }
    }
    return ans;
}

} // namespace noya2