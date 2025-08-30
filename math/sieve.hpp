#pragma once

#include <vector>
#include <cassert>
#include <utility>

namespace noya2{

struct prime_sieve {
    static std::vector<int> primes, factor, mu;
    prime_sieve (int n = 1024){
        build(n);
    }
    static void reserve(int n){
        int sz = size();
        if (sz == 0){
            build(n);
            return ;
        }
        if (n <= sz) return ;
        while (sz < n) sz <<= 1;
        build(sz);
    }
    // n in [1, size()] is available
    static int size(){
        return (int)factor.size() - 1;
    }
  private:
    static void build(int n){
        primes.clear();
        factor.assign(n + 1, 0);
        mu.assign(n + 1, 1);
        for (int x = 2; x <= n; x++){
            if (factor[x] == 0){
                primes.emplace_back(x);
                factor[x] = x;
                mu[x] = -1;
            }
            for (int p : primes){
                if (x * p > n || p > factor[x]) break;
                factor[x * p] = p;
                mu[x * p] = (p == factor[x] ? 0 : -mu[x]);
            }
        }
    }
} sieve;
std::vector<int> prime_sieve::primes;
std::vector<int> prime_sieve::factor;
std::vector<int> prime_sieve::mu;

void reserve_sieve(int n){
    sieve.reserve(n);
}

int mobius_sieve(int n){
    assert(1 <= n && n <= sieve.size());
    return sieve.mu[n];
}

bool is_prime_sieve(int n){
    if (n <= 2) return n == 2;
    assert(n <= sieve.size());
    return sieve.factor[n] == n;
}

// pair(prime, exponent)
std::vector<std::pair<int, int>> factorize_sieve(int n){
    assert(1 <= n && n <= sieve.size());
    std::vector<std::pair<int, int>> ret;
    int pre = 0;
    while (n > 1){
        int p = sieve.factor[n];
        if (pre != p){
            ret.emplace_back(p, 1);
        }
        else {
            ret.back().second += 1;
        }
        pre = p;
        n /= p;
    }
    return ret;
}

std::vector<int> divisors_sieve(int n){
    assert(1 <= n && n <= sieve.size());
    std::vector<int> ret = {1};
    int pre = 0, w = 1;
    while (n > 1){
        int p = sieve.factor[n];
        int sz = ret.size();
        if (pre != p){
            w = ret.size();
        }
        ret.reserve(sz + w);
        for (int i = 0; i < w; i++){
            ret.emplace_back(ret[sz - w + i] * p);
        }
        pre = p;
        n /= p;
    }
    return ret;
}

} // namespace noya2