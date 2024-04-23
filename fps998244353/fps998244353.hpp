#pragma once

#include"../utility/modint.hpp"

#include"../fps/ntt.hpp"
#include"../math/binomial.hpp"

namespace noya2 {

// Formal Power Series for modint998244353
struct fps998244353 : std::vector<modint998244353> {
    using mint = modint998244353;
    using std::vector<mint>::vector;
    using std::vector<mint>::operator=;
    using fps = fps998244353;
    static inline NTT<mint> ntt_;
    static inline binomial<mint> bnm;

    fps998244353 (const std::vector<mint> &init){
        (*this) = init;
    }

    void shrink(){
        while(!(this->empty()) && this->back().val() == 0){
            this->pop_back();
        }
    }

    fps &operator*= (const mint &r){
        for (auto &x : *this) x *= r;
        return *this;
    }
    fps &operator/= (const mint &r){
        (*this) *= r.inv();
        return *this;
    }

    fps &operator<<= (const int &d){
        this->insert(this->begin(), d, mint(0));
        return *this;
    }
    fps &operator>>= (const int &d){
        if ((int)(this->size()) <= d) this->clear();
        else this->erase(this->begin(),this->begin() + d);
        return *this;
    }

    fps &operator+= (const fps &r){
        if (this->size() < r.size()) this->resize(r.size());
        for (int i = 0; auto x : r){
            (*this)[i++] += x;
        }
        return *this;
    }
    fps &operator-= (const fps &r){
        if (this->size() < r.size()) this->resize(r.size());
        for (int i = 0; auto x : r){
            (*this)[i++] -= x;
        }
        return *this;
    }
    fps &operator*= (const fps &r){
        if (this->empty() || r.empty()){
            this->clear();
            return *this;
        }
        (*this) = ntt_.multiply(*this, r);
        return *this;
    }

    fps operator* (const mint &r) const { return fps(*this) *= r; }
    fps operator/ (const mint &r) const { return fps(*this) /= r; }
    fps operator<< (const int &d) const { return fps(*this) <<= d; }
    fps operator>> (const int &d) const { return fps(*this) >>= d; }

    fps operator+ (const fps &r) const { return fps(*this) += r; }
    fps operator- (const fps &r) const { return fps(*this) -= r; }
    fps operator* (const fps &r) const { return fps(*this) *= r; }

    fps operator+ () const { return *this; }
    fps operator- () const {
        fps ret(*this);
        for (auto &x : ret) x = -x;
        return ret;
    }

    mint eval(const mint &x) const {
        mint res(0), w(1);
        for (auto a : *this){
            res += a * w;
            w *= x;
        }
        return res;
    }

    [[nodiscard("Do not change but return changed object.")]]
    fps pre(std::size_t sz) const {
        fps ret(this->begin(), this->begin() + std::min(this->size(), sz));
        if (ret.size() < sz) ret.resize(sz);
        return ret;
    }
    [[nodiscard("Do not change but return changed object.")]]
    fps rev() const {
        fps ret(*this);
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
    [[nodiscard("Do not change but return changed object.")]]
    fps diff() const {
        if (this->empty()){
            return fps();
        }
        fps ret(this->begin() + 1, this->end());
        for (int i = 1; auto &x : ret){
            x *= i++;
        }
        return ret;
    }
    [[nodiscard("Do not change but return changed object.")]]
    fps integral() const {
        if (this->empty()){
            return fps();
        }
        fps ret(1, mint(0));
        ret.insert(ret.end(), this->begin(), this->end());
        for (int i = 0; auto &x : ret){
            x *= bnm.inv(i++); // inv(0) = 0
        }
        return ret;
    }
    [[nodiscard("Do not change but return changed object.")]]
    fps inv(int d = -1) const {
        const int n = this->size();
        if (d == -1) d = n;
        fps res = {(*this)[0].inv()};
        for (int siz = 1; siz < d; siz <<= 1){
            fps f(this->begin(),this->begin()+min(n,siz*2)), g(res);
            f.resize(siz*2), g.resize(siz*2);
            f.ntt(), g.ntt();
            for (int i = 0; i < siz*2; i++) f[i] *= g[i];
            ntt_.intt(f,true);
            f.erase(f.begin(),f.begin()+siz);
            f.resize(siz*2);
            f.ntt();
            for (int i = 0; i < siz*2; i++) f[i] *= g[i];
            f.intt(true);
            mint siz2_inv = mint(siz*2).inv(); siz2_inv *= -siz2_inv;
            for (int i = 0; i < siz; i++) f[i] *= siz2_inv;
            res.insert(res.end(),f.begin(),f.begin()+siz);
        }
        res.resize(d);
        return res;
    }
    [[nodiscard("Do not change but return changed object.")]]
    fps log(int d = -1) const {
        assert(this->empty() == false && (*this)[0].val() == 1u);
        if (d == -1) d = this->size();
        return (this->diff() * this->inv(d)).pre(d - 1).integral();
    }
    [[nodiscard("Do not change but return changed object.")]]
    fps exp(int d = -1) const {
        const int n = this->size();
        if (d == -1) d = n;
        assert(n == 0 || (*this)[0].val() == 0u);
        if (n <= 1){
            fps ret(1,1);
            ret.resize(d);
            return ret;
        }
        // n >= 2
        fps f = {mint(1), (*this)[1]}, ret = f;
        for (int sz = 2; sz < d; sz <<= 1){
            f.insert(f.end(), this->begin()+std::min(n,sz), this->begin()+std::min(n,sz*2));
            f.resize(sz*2);
            ret *= f - ret.log(sz*2);
            ret.resize(sz*2);
        }
        ret.resize(d);
        return ret;
    }
    [[nodiscard("Do not change but return changed object.")]]
    fps pow(long long k, int d = -1) const {
        const int n = this->size();
        if (d == -1) d = n;
        if (k == 0){
            fps ret(d, mint(0));
            if (d >= 1) ret[0] = 1;
            return ret;
        }
        // Find left-most nonzero term.
        for (int i = 0; i < n; i++){
            if ((*this)[i].val() != 0u){
                mint iv = (*this)[i].inv();
                fps ret = ((((*this) * iv) >> i).log(d) * mint(k)).exp(d);
                ret *= (*this)[i].pow(k);
                ret = (ret << (i * k)).pre(d);
                return ret;
            }
            if ((i + 1) * k >= d) break;
        }
        return fps(d, mint(0));
    }

    void ntt(){
        return ntt_.ntt(*this);
    }
    // already /= len
    void intt(bool stop = false){
        return ntt_.intt(*this, stop);
    }
    fps quotient(fps r) const {
        r.shrink();
        const int n = this->size(), m = r.size();
        if (n < m){
            return fps();
        }
        fps quo(*this);
        const int sz = n - m + 1;
        std::reverse(quo.begin(), quo.end());
        std::reverse(r.begin(), r.end());
        quo.resize(sz);
        quo *= r.inv(sz);
        quo.resize(sz);
        std::reverse(quo.begin(), quo.end());
        return quo;
    }
    fps remainder(fps r) const {
        r.shrink();
        const int n = this->size(), m = r.size();
        if (n < m){
            return fps(*this);
        }
        fps rem(*this);
        rem -= quotient(r) * r;
        rem.resize(m-1);
        rem.shrink();
        return rem;
    }
    std::pair<fps,fps> remquo(fps r) const {
        r.shrink();
        fps quo = quotient(r);
        fps rem(*this);
        rem -= quo * r;
        rem.shrink();
        return {rem, quo};
    }
};

} // namespace noya2