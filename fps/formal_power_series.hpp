#pragma once

#include"../template/template.hpp"

namespace noya2{

template<typename T>
concept Field = requires (T a, T b){
    a + b; a - b; a / b; a * b;
    T(0); T(1);
};

template<class Info, class value_type>
concept Fps_Info = requires {
    requires Field<value_type>;
    {Info::multiply(declval<vector<value_type>>(),declval<vector<value_type>>())} -> convertible_to<vector<value_type>>;
};

template<typename T, Fps_Info<T> Info>
struct FormalPowerSeries : vector<T> {
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
};

} // namespace noya2