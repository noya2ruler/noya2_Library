#pragma once

#include"../template/template.hpp"

namespace noya2{

template<typename T, int max_w>
struct Matrix_Square {
    array<T,max_w*max_w> m;
    inline static int w = max_w;
    static void set_w(int new_w){ w = new_w; }
    constexpr Matrix_Square (){ m = {}; }
    constexpr Matrix_Square (array<T,max_w*max_w> init) { m = init; }
    constexpr Matrix_Square (array<array<T,max_w>,max_w> init){
        for (int i = 0; i < w; i++){
            for (int j = 0; j < w; j++){
                m[id(i,j)] = init[i][j];
            }
        }
    }
    T &operator[](pair<int,int> idx) { return m[id(idx.first,idx.second)]; }
    T operator[](pair<int,int> idx) const { return m[id(idx.first,idx.second)]; }
    constexpr size_t size(){ return w; }
    using Matrix = Matrix_Square;
    constexpr Matrix &operator+= (const Matrix &r){
        for (int i = 0; i < w; ++i){
            for (int j = 0; j < w; ++j){
                m[id(i,j)] += r.m[id(i,j)];
            }
        }
        return *this;
    }
    constexpr Matrix &operator-= (const Matrix &r){
        for (int i = 0; i < w; ++i){
            for (int j = 0; j < w; ++j){
                m[id(i,j)] -= r.m[id(i,j)];
            }
        }
        return *this;
    }
    constexpr Matrix &operator*= (const Matrix &r){
        Matrix res = {};
        for (int i = 0; i < w; i++){
            for (int k = 0; k < w; k++){
                for (int j = 0; j < w; j++){
                    res.m[id(i,j)] += m[id(i,k)] * r.m[id(k,j)];
                }
            }
        }
        return *this = res;
    }
    constexpr Matrix operator+ (const Matrix &r) const {return Matrix(*this) += r;}
    constexpr Matrix operator- (const Matrix &r) const {return Matrix(*this) -= r;}
    constexpr Matrix operator* (const Matrix &r) const {return Matrix(*this) *= r;}
    constexpr bool operator== (const Matrix &r){
        for (int i = 0; i < w; ++i){
            for (int j = 0; j < w; ++j){
                if (m[id(i,j)] != r.m[id(i,j)]) return false;
            }
        }
        return true;
    }
    constexpr Matrix& operator*=(const T &r){
        for (int i = 0; i < w; ++i){
            for (int j = 0; j < w; ++j){
                m[id(i,j)] *= r;
            }
        }
        return *this;
    }
    constexpr Matrix& operator/=(const T &r){
        for (int i = 0; i < w; ++i){
            for (int j = 0; j < w; ++j){
                m[id(i,j)] /= r;
            }
        }
        return *this;
    }
    constexpr Matrix operator* (const T &r) const {return Matrix(*this) *= r;}
    constexpr Matrix operator/ (const T &r) const {return Matrix(*this) /= r;}
    friend constexpr Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
        return Matrix(lhs) += rhs;
    }
    friend constexpr Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
        return Matrix(lhs) -= rhs;
    }
    friend constexpr Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        return Matrix(lhs) *= rhs;
    }
    friend constexpr Matrix operator*(const Matrix& lhs, const T& r){
        return Matrix(lhs) *= r;
    }
    friend constexpr Matrix operator*(const T& l, const Matrix &rhs){
        return Matrix(rhs) *= l;
    }
    friend constexpr Matrix operator/(const Matrix& lhs, const T& r){
        return Matrix(lhs) /= r;
    }
    static constexpr Matrix e(){
        array<T,max_w*max_w> res = {};
        for (int i = 0; i < w; i++) res[id(i,i)] = T(1);
        return res;
    }
    constexpr Matrix pow(ll n) const {
        Matrix res = e(), x = *this;
        while (n){
            if (n&1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    constexpr T determinant() const {
        auto B = this->m;
        T ret = 1;
        for (int i = 0; i < w; i++) {
            int idx = -1;
            for (int j = i; j < w; j++) {
                if (B[id(j,i)] != 0) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) return 0;
            if (i != idx) {
                ret *= T(-1);
                for (int j = 0; j < w; j++) swap(B[id(i,j)],B[id(idx,j)]);
            }
            ret *= B[id(i,i)];
            T inv = T(1) / B[id(i,i)];
            for (int j = 0; j < w; j++) {
                B[id(i,j)] *= inv;
            }
            for (int j = i + 1; j < w; j++) {
                T a = B[id(j,i)];
                if (a == 0) continue;
                for (int k = i; k < w; k++) {
                    B[id(j,k)] -= B[id(i,k)] * a;
                }
            }
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const Matrix& p) {
        for (int i = 0; i < w; i++){
            if (i != 0) os << '\n';
            for (int j = 0; j < w; j++){
                if (j != 0) os << ' ';
                os << p.m[id(i,j)];
            }
        }
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Matrix &p) {
        for (int i = 0; i < w; i++){
            for (int j = 0; j < w; j++){
                is >> p.m[id(i,j)];
            }
        }
        return (is);
    }
  private:
    static constexpr int id(int i, int j){ return i*max_w+j; }
};

} // namespace noya2
