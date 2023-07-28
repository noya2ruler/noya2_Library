#pragma once

#include"../template/template.hpp"

namespace noya2{

template<typename T> struct Matrix{
    int rows, cols;
    vector<vector<T>> m;
    Matrix (int h = 0, int w = -1, T init = T(0)) : m(h,vector<T>((w == -1 ? h : w),init)){
        rows = h, cols = (w == -1 ? h : w);
    } 
    Matrix (vector<vector<T>> _init) : m(_init), rows(_init.size()), cols(_init.at(0).size()){}
    vector<T>& operator[](const int i) const {return m[i];}
    vector<T>& operator[](const int i) {return m[i];}
    Matrix &operator+= (const Matrix &r){
        assert(this->rows == r.rows && this->cols == r.cols);
        for (int i = 0; i < r.rows; ++i){
            for (int j = 0; j < r.cols; ++j){
                m[i][j] += r.m[i][j];
            }
        }
        return *this;
    }
    Matrix &operator-= (const Matrix &r){
        assert(this->rows == r.rows && this->cols == r.cols);
        for (int i = 0; i < r.rows; ++i){
            for (int j = 0; j < r.cols; ++j){
                m[i][j] -= r.m[i][j];
            }
        }
        return *this;
    }
    Matrix &operator*= (const Matrix &r){
        assert(this->cols == r.rows);
        Matrix res(rows, r.cols);
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < r.cols; ++j){
                for (int k = 0; k < r.rows; ++k){
                    res[i][j] += m[i][k] * r.m[k][j];
                }
            }
        }
        return *this = res;
    }
    Matrix operator+ (const Matrix &r) const {return Matrix(*this) += r;}
    Matrix operator- (const Matrix &r) const {return Matrix(*this) -= r;}
    Matrix operator* (const Matrix &r) const {return Matrix(*this) *= r;}
    bool operator== (const Matrix &r){
        if (rows != r.rows || cols != r.cols) return false;
        for (int i = 0; i < r.rows; ++i){
            for (int j = 0; j < r.cols; ++j){
                if (m[i][j] != r.m[i][j]) return false;
            }
        }
        return true;
    }
    Matrix& operator+=(const T &r){
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                m[i][j] += r;
            }
        }
        return *this;
    }
    Matrix& operator-=(const T &r){
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                m[i][j] -= r;
            }
        }
        return *this;
    }
    Matrix& operator*=(const T &r){
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                m[i][j] *= r;
            }
        }
        return *this;
    }
    Matrix& operator/=(const T &r){
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                m[i][j] /= r;
            }
        }
        return *this;
    }
    Matrix operator+ (const T &r) const {return Matrix(*this) += r;}
    Matrix operator- (const T &r) const {return Matrix(*this) -= r;}
    Matrix operator* (const T &r) const {return Matrix(*this) *= r;}
    Matrix operator/ (const T &r) const {return Matrix(*this) /= r;}
    Matrix e(){
        assert(this->rows == this->cols);
        Matrix res(this->rows, this->rows);
        for (int i = 0; i < rows; ++i) res[i][i] = 1;
        return res;
    }
    Matrix pow(long long n){
        assert(this->rows == this->cols);
        if (n == 0) return e();
        Matrix f = pow(n / 2);
        Matrix ans = f * f;
        if (n % 2 == 1) ans *= *this;
        return ans;
    }
    // for T = int, long long, double, long double
    void show(){
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                cout << m[i][j] << (j+1 == this->cols ? "\n" : " ");
            }
        }
    }
    T determinant() const {
        Matrix B(*this);
        assert(rows == cols);
        T ret = 1;
        for (int i = 0; i < rows; i++) {
            int idx = -1;
            for (int j = i; j < cols; j++) {
                if (B[j][i] != 0) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) return 0;
            if (i != idx) {
                ret *= T(-1);
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T inv = T(1) / B[i][i];
            for (int j = 0; j < cols; j++) {
                B[i][j] *= inv;
            }
            for (int j = i + 1; j < rows; j++) {
                T a = B[j][i];
                if (a == 0) continue;
                for (int k = i; k < cols; k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return ret;
    }
};

} // namespace noya2
