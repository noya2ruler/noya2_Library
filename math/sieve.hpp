#pragma once

#include"../template/template.hpp"

namespace noya2{

struct Sieve {
    vector<int> primes, factor, mu;
    Sieve (int N = 1024){
        build(N);
    }
    void request(int N){
        int len = n_max();
        if (len >= N) return ;
        while (len < N) len <<= 1;
        build(len);
    }
    int n_max(){ return factor.size()-1; }
  private:
    void build (int N){
        primes.clear();
        factor.resize(N+1); fill(factor.begin(),factor.end(),0);
        mu.resize(N+1); fill(mu.begin(),mu.end(),1);

        for(int n = 2; n <= N; n++) {
            if (factor[n] == 0){
                primes.push_back(n);
                factor[n] = n;
                mu[n] = -1;
            }
            for (int p : primes){
                if(n * p > N || p > factor[n]) break;
                factor[n * p] = p;
                mu[n * p] = p == factor[n] ? 0 : -mu[n];
            }
        }
    }
} sieve;

int mobius_sieve(int n){
    assert(1 <= n && n <= sieve.n_max());
    return sieve.mu[n];
}
bool is_prime_sieve(int n){
    if (n <= 2) return n == 2;
    assert(n <= sieve.n_max());
    return sieve.factor[n] == n;
}

vector<pair<int,int>> prime_factorization_sieve(int n){
    assert(1 <= n && n <= sieve.n_max());
    vector<int> facts;
    while (n > 1){
        int p = sieve.factor[n];
        facts.push_back(p);
        n /= p;
    }
    vector<pair<int,int>> pes;
    int siz = facts.size();
    for (int l = 0, r = 0; l < siz; l = r){
        while (r < siz && facts[r] == facts[l]) r++;
        pes.emplace_back(facts[l],r-l);
    }
    return pes;
}

vector<int> divisor_enumeration_sieve(int n){
    auto pes = prime_factorization_sieve(n);
    vector<int> divs = {1};
    for (auto [p, e] : pes){
        vector<int> nxt; nxt.reserve(divs.size() * (e+1));
        for (auto x : divs){
            for (int tt = 0; tt <= e; tt++){
                nxt.push_back(x);
                x *= p;
            }
        }
        swap(divs,nxt);
    }
    return divs;
}

} // namespace noya2