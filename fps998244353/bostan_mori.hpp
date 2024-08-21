#pragma once

#include"fps998244353.hpp"

namespace noya2 {

modint998244353 bostan_mori(fps998244353 p, fps998244353 q, long long k){
    using mint = modint998244353;
    assert(!q.empty() && q[0] != 0);
    if (k < 0){
        return 0;
    }
    int n = std::bit_ceil(std::max(p.size(), q.size()));
    int h = std::countr_zero((unsigned int)(n));
    p.resize(n * 2, 0);
    q.resize(n * 2, 0);
    mint ie = mint::raw(internal::INV_FFT_ROOTS[h + 1]);
    mint i2 = mint::raw((mint::mod() + 1) >> 1);
    fps998244353 es(n, i2);
    for (int i = h - 1; i >= 0; i--){
        for (int j = 0; j < n; j++){
            if (j >> i & 1){
                es[j] *= ie;
            }
        }
        ie *= ie;
    }
    p.ntt();
    q.ntt();

    while (k){
        for (int i = 0; i < n; i++){
            p[i * 2] *= q[i * 2 + 1];
            p[i * 2 + 1] *= q[i * 2];
            q[i * 2] = q[i * 2 + 1] = q[i * 2] * q[i * 2 + 1];
        }
        p.ntt_pick_parity(k & 1);
        q.ntt_pick_parity(0);
        k >>= 1;
        if (k == 0) break;
        p.ntt_doubling();
        q.ntt_doubling();
    }
    mint sp = 0, sq = 0;
    for (int i = 0; i < n; i++){
        sp += p[i];
        sq += q[i];
    }
    return sp / sq;
}

modint998244353 kth_term_linear(fps998244353 a, fps998244353 c, long long k){
    assert(a.size() + 1uz == c.size());
    size_t d = a.size();
    a *= c;
    a.resize(d);
    return bostan_mori(a, c, k);
}

fps998244353 bostan_mori(fps998244353 f, const fps998244353 &g, long long L, long long R){
    assert(0 <= L && L <= R);
    
    int n = f.size(), m = g.size() - 1;
    if (n == 0) return fps998244353(R - L);
    if (L == R) return fps998244353{};

    assert(g[0].val() != 0u);
    auto g0_inv = g[0].inv();

    if (n > R){
        n = (int)R;
        f.resize(n);
    }

    if (m == 0){
        fps998244353 ans(R - L);
        for (long long i = 0; i < n - L; i++){
            ans[i] = f[i + L] * g0_inv;
        }
        return ans;
    }

    // bit_ceil(R) = 2^K
    int K = 64 - std::countl_zero((unsigned long long)(R - 1));

    if (K == 0){
        // L = 0, R = 1
        return fps998244353{f[0] * g0_inv};
    }

    std::vector q(K, fps998244353(m + 1));
    for (int i = 0; i <= m; i++){
        q[0][i] = g[i] * g0_inv;
    }

    std::vector<long long> d_min(K + 1), d_max(K + 1);
    d_min[0] = std::max(L - n + 1, 0LL);
    d_max[0] = R - 1;
    

    for (int k = 1; k <= K - 1; k++){
        auto q_pos(q[k - 1]);
        for (int i = 1; i <= m; i += 2){
            q[k - 1][i] = -q[k - 1][i];
        }
        auto qk_dbl = q_pos * q[k - 1];
        for (int i = 0; i <= m; i++){
            q[k][i] = qk_dbl[i * 2];
        }
        auto tmp = d_min[k - 1] - 1 - m;
        d_min[k] = (tmp >= 0LL ? tmp/2 + 1 : 0LL);
        d_max[k] = d_max[k - 1] / 2;
    }

    for (int i = 1; i <= m; i += 2){
        q[K - 1][i] = -q[K - 1][i];
    }
    
    const auto inv2 = binomial<modint998244353>::inv(2);
    modint998244353 inv2_pow[31];
    inv2_pow[0] = modint998244353::raw(1);
    for (int i = 0; i < 30; i++){
        inv2_pow[i + 1] = inv2_pow[i] * inv2;
    }

    fps998244353 p{1};
    for (int k = K-1; k >= 0; k--){
        int B = 64 - std::countl_zero((unsigned long long)(m + std::max(2 * d_max[k + 1] - d_min[k], 0LL)));
        int W = 1 << B;

        fps998244353 p_dbl(W);
        for (int i = 0; i < (int)(p.size()); i++){
            p_dbl[i * 2] = p[i];
        }

        q[k].resize(W);

        p_dbl.ntt();
        q[k].ntt();
        for (int i = 0; i < W; i++){
            p_dbl[i] *= q[k][i];
        }
        p_dbl.intt();

        p.resize(d_max[k] - d_min[k] + 1);
        int i_min = (int)(std::max(-(d_min[k] - 2 * d_min[k + 1]), 0LL));
        int i_max = (int)(std::min<long long>(d_max[k] - d_min[k], (p_dbl).size() - 1 - (d_min[k] - 2 * d_min[k + 1])));
        for (int i = i_min; i <= i_max; i++){
            p[i] = p_dbl[i + d_min[k] - 2 * d_min[k + 1]] * inv2_pow[B];
        }
    }

    int B = 64 - std::countl_zero((unsigned long long)(n - 1 + d_max[0] - L));
    int W = 1 << B;

    f.resize(W);
    p.resize(W);

    f.ntt();
    p.ntt();
    for (int i = 0; i < W; i++){
        f[i] *= p[i];
    }
    f.intt();

    g0_inv *= inv2_pow[B];
    fps998244353 ans(R - L);
    for (long long i = 0; i < R - L; i++){
        ans[i] = f[i + L - d_min[0]] * g0_inv;
    }

    return ans;
}

} // namespace noya2