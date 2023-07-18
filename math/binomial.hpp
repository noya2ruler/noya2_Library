#pragma once

namespace noya2 {

template<typename mint>
struct binomial {
    binomial(int len = 300000){ extend(len); }
    static mint fact(int n){
        if (n < 0) return 0;
        while (n >= (int)_fact.size()) extend();
        return _fact[n];
    }
    static mint ifact(int n){
        if (n < 0) return 0;
        while (n >= (int)_fact.size()) extend();
        return _ifact[n];
    }
    static mint inv(int n){
        return ifact(n) * fact(n-1);
    }
    static mint C(int n, int r){
        if (!(0 <= r && r <= n)) return 0;
        return fact(n) * ifact(r) * ifact(n-r);
    }
    static mint P(int n, int r){
        if (!(0 <= r && r <= n)) return 0;
        return fact(n) * ifact(n-r);
    }
    inline mint operator()(int n, int r) { return C(n, r); }
    template<class... Cnts> static mint M(const Cnts&... cnts){
        return multinomial(0,1,cnts...);
    }
  private:
    static mint multinomial(const int& sum, const mint& div_prod){
        if (sum < 0) return 0;
        return fact(sum) * div_prod;
    }
    template<class... Tail> static mint multinomial(const int& sum, const mint& div_prod, const int& n1, const Tail&... tail){
        if (n1 < 0) return 0;
        return multinomial(sum+n1,div_prod*ifact(n1),tail...);
    }
    static vector<mint> _fact, _ifact;
    static void extend(int len = -1){
        if (_fact.empty()){
            _fact = _ifact = {1,1};
        }
        int siz = _fact.size();
        if (len == -1) len = siz * 2;
        len = min<int>(len, mint::mod()-1);
        if (len < siz) return ;
        _fact.resize(len+1), _ifact.resize(len+1);
        for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1] * i;
        _ifact[len] = _fact[len].inv();
        for (int i = len; i > siz; i--) _ifact[i-1] = _ifact[i] * i;
    }
};
template<typename T>
std::vector<T>binomial<T>::_fact = vector<T>(2,T(1));
template<typename T>
std::vector<T>binomial<T>::_ifact = vector<T>(2,T(1));

} // namespace noya2