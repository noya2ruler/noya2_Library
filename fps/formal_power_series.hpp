#pragma once

#include"../template/template.hpp"

namespace noya2{

template<typename T>
concept Field = requires (T a, T b){
    a + b; a - b; a / b; a * b;
    T(0); T(1);
};

template<class Info>
concept Fps_Info = requires {
    typename Info::value_type;
    requires Field<typename Info::value_type>;
    {Info::multiply(declval<vector<typename Info::value_type>>(),declval<vector<typename Info::value_type>>())} -> convertible_to<vector<typename Info::value_type>>;
    {Info::inv(declval<vector<typename Info::value_type>>(),declval<int>())} -> convertible_to<vector<typename Info::value_type>>;
    {Info::integral(declval<vector<typename Info::value_type>>())} -> convertible_to<vector<typename Info::value_type>>;
};

template<Fps_Info Info>
struct FormalPowerSeries : vector<typename Info::value_type> {
    using T = typename Info::value_type;
    using vector<T>::vector;
    using vector<T>::operator=;
    using FPS = FormalPowerSeries;
    FormalPowerSeries (const vector<T> &init_ = {}){ (*this) = init_; }
    void shrink(){ while (!(*this).empty() && (*this).back() == T(0)) (*this).pop_back(); }
    FPS &operator+=(const T &r){
        if ((*this).empty()) (*this).resize(1);
        (*this)[0] += r;
        return *this;
    }
    FPS &operator-=(const T &r){
        if ((*this).empty()) (*this).resize(1);
        (*this)[0] -= r;
        return *this;
    }
    FPS &operator*=(const T &r){
        for (auto &x : *this) x *= r;
        return *this;
    }
    FPS &operator/=(const T &r){
        (*this) *= T(1)/r;
        return *this;
    }
    FPS &operator<<=(const int &d){
        (*this).insert((*this).begin(),d,T(0));
        return *this;
    }
    FPS &operator>>=(const int &d){
        if ((int)(*this).size() <= d) (*this).clear();
        else (*this).erase((*this).begin(),(*this).begin()+d);
        return *this;
    }
    FPS &operator+=(const FPS &r){
        if ((*this).size() < r.size()) (*this).resize(r.size());
        for (int i = 0; i < (int)(r.size()); i++) (*this)[i] += r[i];
        return *this;
    }
    FPS &operator-=(const FPS &r){
        if ((*this).size() < r.size()) (*this).resize(r.size());
        for (int i = 0; i < (int)(r.size()); i++) (*this)[i] -= r[i];
        return *this;
    }
    FPS &operator*=(const FPS &r){
        if ((*this).empty() || r.empty()){
            (*this).clear();
            return *this;
        }
        (*this) = Info::multiply(*this,r);
        return *this;
    }
    FPS operator+(const T &r) const { return FPS(*this) += r; }
    FPS operator-(const T &r) const { return FPS(*this) -= r; }
    FPS operator*(const T &r) const { return FPS(*this) *= r; }
    FPS operator/(const T &r) const { return FPS(*this) /= r; }
    FPS operator<<(const int &d) const { return FPS(*this) <<= d; }
    FPS operator>>(const int &d) const { return FPS(*this) >>= d; }
    FPS operator+(const FPS &r) const { return FPS(*this) += r; }
    FPS operator-(const FPS &r) const { return FPS(*this) -= r; }
    FPS operator*(const FPS &r) const { return FPS(*this) *= r; }
    FPS operator+() const { return *this; }
    FPS operator-() const {
        FPS res(*this);
        for (auto &x : res) x = -x;
        return res;
    }
    T eval(const T &x) const {
        T res = T(0), w = T(1);
        for (auto &e : *this) res += e * w, w *= x;
        return res;
    }
    static FPS dot(const FPS &lhs, const FPS &rhs){
        FPS res(min(lhs.size(),rhs.size()));
        for (int i = 0; i < (int)res.size(); i++) res[i] = lhs[i] * rhs[i];
        return res;
    }
    FPS pre(int siz) const {
        FPS ret((*this).begin(), (*this).begin() + min((int)this->size(), siz));
        if ((int)ret.size() < siz) ret.resize(siz);
        return ret;
    }
    FPS rev() const {
        FPS ret(*this);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    FPS diff() const {
        const int n = (int)this->size();
        FPS ret(max(0, n - 1));
        T one(1), coeff(1);
        for (int i = 1; i < n; i++) {
            ret[i - 1] = (*this)[i] * coeff;
            coeff += one;
        }
        return ret;
    }
    FPS integral() const {
        FPS ret = Info::integral(*this);
        return ret;
    }
    FPS inv(int d = -1) const {
        FPS ret = Info::inv(*this,d);
        return ret;
    }
    FPS exp(int d = -1) const {
        const int n = (*this).size();
        if (d == -1) d = n;
        FPS f = {T(1)+(*this)[0],(*this)[1]}, res = {1,(n > 1 ? (*this)[1] : 0)};
        for (int sz = 2; sz < d; sz <<= 1){
            f.insert(f.end(),(*this).begin()+min(n,sz),(*this).begin()+min(n,sz*2));
            if ((int)f.size() < sz*2) f.resize(sz*2);
            res = res * (f - res.log(2*sz));
            res.resize(sz*2);
        }
        res.resize(d);
        return res;
    }
    FPS log(int d = -1) const {
        assert(!(*this).empty() && (*this)[0] == T(1));
        if (d == -1) d = (*this).size();
        return (this->diff() * this->inv(d)).pre(d - 1).integral();
    }
};

} // namespace noya2