#pragma once

#include <vector>
#include <array>
#include <iostream>
#include <ranges>
#include <cassert>

namespace noya2 {

template<typename T, size_t hw = -1uz>
struct matrix {
    static constexpr int h = hw, w = hw;
    std::array<T, hw*hw> m;
    matrix () : m({}) {}
    matrix (const std::array<T, hw*hw> &_m) : m(_m) {}
    matrix (const std::array<std::array<T, hw>, hw> &_m){
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){
            m[idx(i,j)] = _m[i][j];
        }
    }
    matrix (const std::vector<std::vector<T>> &_m){
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){
            m[idx(i,j)] = _m[i][j];
        }
    }
    auto operator[](int i) const {
        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);
    }
    auto operator[](int i){
        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);
    }
    matrix &operator+= (const matrix &r){
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                m[idx(i,j)] += r.m[idx(i,j)];
            }
        }
        return *this;
    }
    matrix &operator-= (const matrix &r){
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                m[idx(i,j)] -= r.m[idx(i,j)];
            }
        }
        return *this;
    }
    matrix &operator*= (const matrix &r){
        matrix ret;
        for (int i = 0; i < h; i++){
            for (int k = 0; k < w; k++){
                for (int j = 0; j < r.w; j++){
                    ret.m[idx(i,j)] += m[idx(i,k)] * r.m[idx(k,j)];
                }
            }
        }
        return *this = ret;
    }
    matrix operator+ (const matrix &r) const { return matrix(*this) += r; }
    matrix operator- (const matrix &r) const { return matrix(*this) -= r; }
    matrix operator* (const matrix &r) const { return matrix(*this) *= r; }
    matrix& operator*=(const T &r){
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                m[idx(i,j)] *= r;
            }
        }
        return *this;
    }
    friend matrix operator* (const T &r, const matrix &mat){
        return matrix(mat) *= r;
    }
    friend matrix operator* (const matrix &mat, const T &r){
        return matrix(mat) *= r;
    }
    matrix pow(long long n){
        if (n == 0) return e();
        matrix f = pow(n / 2);
        matrix ret = f * f;
        if (n & 1) ret *= (*this);
        return ret;
    }
    int idx(int i, int j){
        return i * w + j;
    }
    static matrix e(){
        matrix ret;
        for (int i = 0; i < h; i++){
            ret[i][i] = T(1);
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const matrix &mat){
        for (int i = 0; i < mat.h; i++){
            if (i != 0) os << '\n';
            for (int j = 0; j < mat.w; j++){
                if (j != 0) os << ' ';
                os << mat[i][j];
            }
        }
        return os;
    }
    friend std::istream &operator>>(std::istream &is, matrix &mat){
        for (int i = 0; i < mat.h; i++){
            for (int j = 0; j < mat.w; j++){
                is >> mat[i][j];
            }
        }
        return is;
    }
    friend bool operator==(const matrix &a, const matrix &b){
        for (int i = 0; i < a.h; i++){
            for (int j = 0; j < a.w; j++){
                if (a[i][j] != b[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};

template<typename T>
struct matrix<T,-1uz> {
    int h, w;
    std::vector<T> m;
    matrix () {}
    matrix (int _h) : matrix(_h,_h) {}
    matrix (int _h, int _w) : h(_h), w(_w), m(_h*_w) {}
    matrix (int _h, int _w, const std::vector<T> &_m) : h(_h), w(_w), m(_m) {
        assert((int)_m.size() == _h*_w);
    }
    matrix (const std::vector<std::vector<T>> &_m){
        h = _m.size();
        assert(h >= 1);
        w = _m[0].size();
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){
            m[idx(i,j)] = _m[i][j];
        }
    }
    auto operator[](int i) const {
        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);
    }
    auto operator[](int i){
        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);
    }
    matrix &operator+= (const matrix &r){
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                m[idx(i,j)] += r.m[idx(i,j)];
            }
        }
        return *this;
    }
    matrix &operator-= (const matrix &r){
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                m[idx(i,j)] -= r.m[idx(i,j)];
            }
        }
        return *this;
    }
    matrix &operator*= (const matrix &r){
        matrix ret(h, r.w);
        for (int i = 0; i < h; i++){
            for (int k = 0; k < w; k++){
                for (int j = 0; j < r.w; j++){
                    ret.m[idx(i,j)] += m[idx(i,k)] * r.m[idx(k,j)];
                }
            }
        }
        return *this = ret;
    }
    matrix operator+ (const matrix &r) const { return matrix(*this) += r; }
    matrix operator- (const matrix &r) const { return matrix(*this) -= r; }
    matrix operator* (const matrix &r) const { return matrix(*this) *= r; }
    matrix& operator*=(const T &r){
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                m[idx(i,j)] *= r;
            }
        }
        return *this;
    }
    friend matrix operator* (const T &r, const matrix &mat){
        return matrix(mat) *= r;
    }
    friend matrix operator* (const matrix &mat, const T &r){
        return matrix(mat) *= r;
    }
    matrix pow(long long n){
        if (n == 0) return e(h);
        matrix f = pow(n / 2);
        matrix ret = f * f;
        if (n & 1) ret *= (*this);
        return ret;
    }
    int idx(int i, int j){
        return i * w + j;
    }
    static matrix e(int _h){
        auto ret = matrix(_h, _h);
        for (int i = 0; i < _h; i++){
            ret[i][i] = T(1);
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const matrix &mat){
        for (int i = 0; i < mat.h; i++){
            if (i != 0) os << '\n';
            for (int j = 0; j < mat.w; j++){
                if (j != 0) os << ' ';
                os << mat[i][j];
            }
        }
        return os;
    }
    friend std::istream &operator>>(std::istream &is, matrix &mat){
        for (int i = 0; i < mat.h; i++){
            for (int j = 0; j < mat.w; j++){
                is >> mat[i][j];
            }
        }
        return is;
    }
};

template<typename T, size_t _hw = -1uz>
T determinant(matrix<T, _hw> mat){
    int hw = mat.h;
    T ret = 1;
    for (int i = 0; i < hw; i++) {
        int idx = -1;
        for (int j = i; j < hw; j++) {
            if (mat[j][i] != 0) {
                idx = j;
                break;
            }
        }
        if (idx == -1) return 0;
        if (i != idx) {
            ret *= T(-1);
            for (int j = 0; j < hw; j++){
                std::swap(mat[i][j],mat[idx][j]);
            }
        }
        ret *= mat[i][i];
        T inv = T(1) / mat[i][i];
        for (int j = 0; j < hw; j++) {
            mat[i][j] *= inv;
        }
        for (int j = i + 1; j < hw; j++) {
            T a = mat[j][i];
            if (a == 0) continue;
            for (int k = i; k < hw; k++) {
                mat[j][k] -= mat[i][k] * a;
            }
        }
    }
    return ret;
}

} // namespace noya2