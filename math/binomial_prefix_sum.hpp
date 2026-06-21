#pragma once

#include"math/binomial.hpp"
#include"misc/mo_algorithm.hpp"

namespace noya2 {

template<typename mint>
struct binomial_prefix_sum {
    int m;
    std::vector<mint> table;
    binomial<mint> binom;
    binomial_prefix_sum() {}
    binomial_prefix_sum(int nmax){
        m = sqrt(nmax) + 1;
        table.resize(m * m);
        // 0 <= i, j < m
        // table[i * m + j] = sum_{k in [0, j * m + m)} binom{i * m + m}{k}
        for (int i = 0; i < m; i++){
            mint sum = 0;
            int n = i * m + m;
            int j = 0;
            for (int k = 0; k <= n; k++){
                sum += binom(n, k);
                if ((k + 1) % m == 0){
                    assert(k + 1 == j * m + m);
                    table[i * m + j] = sum;
                    j++;
                }
            }
            // for ( ; j < m; j++){
            //     table[i * m + j] = sum;
            // }
        }
    }
    // sum_{i in [0, k)} binom{n}{i}
    mint operator()(int n, int k){
        if (k <= 0){
            return 0;
        }
        if (k >= n+1){
            return mint(2).pow(n);
        }
        if (k < m){
            mint ans = 0;
            for (int i = 0; i < k; i++){
                ans += binom(n, i);
            }
            return ans;
        }
        // n >= k >= m
        int i = (n - m) / m;
        int j = (k - m) / m;
        mint ans = table[i * m + j];
        int nn = i * m + m, kk = j * m + m;
        while (nn < n){
            ans *= 2;
            ans -= binom(nn, kk - 1);
            nn++;
        }
        while (kk < k){
            ans += binom(n, kk);
            kk++;
        }
        return ans;
    }
};

// for nks[i] = {n, k}, ret[i] = \sum_{i in [0, k)} binom{n}{i}
template<typename mint>
std::vector<mint> multipoint_binomial_prefix_sum(std::vector<std::pair<int, int>> nks){
    int q = nks.size();
    int mx = 0;
    for (auto [n, k] : nks){
        if (mx < n) mx = n;
    }
    mo_algorithm mo(mx + 1, q);
    binomial<mint> binom;
    for (auto [n, k] : nks){
        mo.insert(std::clamp(k, 0, n + 1), n);
    }
    int n = 0, k = 0;
    mint cur = 0;
    auto addl = [&](int kk){
        cur -= binom(n, --k);
    };
    auto dell = [&](int kk){
        cur += binom(n, k++);
    };
    const mint i2 = mint(2).inv();
    auto delr = [&](int){
        cur += binom(n - 1, k - 1);
        cur *= i2;
        n--;
    };
    auto addr = [&](int){
        cur *= 2;
        cur -= binom(n, k - 1);
        n++;
    };
    vector<mint> ans(q);
    auto rem = [&](int i){
        ans[i] = cur;
    };
    mo.run(addl, addr, dell, delr, rem);
    return ans;
}

} // namespace noya2