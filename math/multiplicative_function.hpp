#pragma once

#include <vector>
#include <cmath>
#include <cassert>

namespace noya2 {

std::vector<int> prime_enumerate(int N){
    std::vector<bool> psieve(N / 3 + 1, true);
    int qe = psieve.size();
    for (int p = 5, d = 4, i = 1, sqn = std::sqrt(N); p <= sqn; p += d = 6 - d, i++){
        if (!psieve[i]) continue;
        for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p; q < qe; q += r = s - r){
            psieve[q] = false;
        }
    }
    std::vector<int> ret = {2, 3};
    for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++){
        if (psieve[i]) ret.emplace_back(p);
    }
    while (!ret.empty() && ret.back() > N) ret.pop_back();
    return ret;
}

struct mf_prefix_sum {
    long long M, sq, s;
    std::vector<int> p;
    int ps;
    mf_prefix_sum(long long m) : M(m) {
        assert(m <= 1e15);
        sq = std::sqrt(M);
        while (sq * sq > M) sq--;
        while ((sq + 1) * (sq + 1) <= M) sq++;
        if (m != 0){
            long long hls = quo(M, sq);
            while (hls != 1 && quo(M, hls - 1) == sq) hls--;
            s = hls + sq;
        }
        p = prime_enumerate(sq);
        ps = p.size();
    }
    // calc : sum[2 <= prime <= M/i] f(prime)
    // T f(int prime) : f(prime)
    // T sum(long long r) : sum[2 <= x <= r] f(x)
    // T mul(int prime, T s) : sum[x in R] f(prime * x), for s = sum[x in R] f(x), R = { x <= M/i | lpf(x) >= prime }
    template<typename T>
    std::vector<T> table(auto f, auto sum, auto mul) const {
        if (M == 0) return {};
        long long hls = s - sq;
        std::vector<T> hl(hls);
        for (int i = 1; i < hls; i++){
            hl[i] = sum(quo(M, i));
        }
        std::vector<T> hs(sq + 1);
        for (int i = 1; i <= sq; i++){
            hs[i] = sum(i);
        }
        T psum = {};
        for (auto &x : p){
            long long x2 = (long long)(x) * x;
            long long imax = std::min<long long>(hls, quo(M, x2) + 1);
            for (long long i = 1, ix = x; i < imax; i++, ix += x){
                hl[i] -= mul(x, (ix < hls ? hl[ix] : hs[quo(M, ix)]) - psum);
            }
            for (int n = sq; n >= x2; n--){
                hs[n] -= mul(x, hs[quo(n, x)] - psum);
            }
            psum += f(x);
        }
        hl.reserve(sq * 2 + 10);
        for (int i = hs.size(); --i; ) hl.push_back(hs[i]);
        assert((int)(hl.size()) == s);
        return hl;
    }
    // calc : sum[1 <= x <= M] f(x), f is multiplicative
    // T f(int prime, int e) : f(prime ^ e)
    template<typename T>
    T run(auto f, const std::vector<T> &Fprime) const {
        if (M == 0) return {};
        assert((int)(Fprime.size()) == s);
        T ans = Fprime[idx(M)] + 1; // + 1 : f(1)
        auto dfs = [&](auto sfs, int i, int c, long long prod, T cur) -> void {
            ans += cur * f(p[i], c + 1);
            long long lim = quo(M, prod);
            if (lim >= 1LL * p[i] * p[i]){
                sfs(sfs, i, c + 1, p[i] * prod, cur);
            }
            cur *= f(p[i], c);
            ans += cur * (Fprime[idx(lim)] - Fprime[idx(p[i])]);
            int j = i + 1;
            for (; j < ps && p[j] < (1 << 21) && 1LL * p[j] * p[j] * p[j] <= lim; j++){
                sfs(sfs, j, 1, prod * p[j], cur);
            }
            for (; j < ps && 1LL * p[j] * p[j] <= lim; j++){
                T sm = f(p[j], 2);
                int id1 = idx(quo(lim, p[j])), id2 = idx(p[j]);
                sm += f(p[j], 1) * (Fprime[id1] - Fprime[id2]);
                ans += cur * sm;
            }
        };
        for (int i = 0; i < ps; i++){
            dfs(dfs, i, 1, p[i], 1);
        }
        return ans;
    }
    long long quo(long long n, long long d) const { return n / d; }
    long long idx(long long n) const { return n <= sq ? s - n : quo(M, n); }
    long long val(long long i) const { return i >= s - sq ? s - i : quo(M, i); }
};

} // namespace noya2