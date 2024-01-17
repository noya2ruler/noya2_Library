#pragma once

#include"../math/matrix.hpp"

namespace noya2 {

template<typename T>
T directed_spanning_tree_counting(int n, vector<tuple<int,int,T>> es){
    Matrix<T> mat(n-1);
    for (auto [u, v, c] : es){
        if (u < n-1 && v < n-1){
            mat[u][v] -= c;
        }
        if (v < n-1){
            mat[v][v] += c;
        }
    }
    return mat.determinant();
}

template<typename T>
T undirected_spanning_tree_counting(int n, vector<tuple<int,int,T>> es){
    Matrix<T> mat(n-1);
    for (auto [u, v, c] : es){
        if (u < n-1 && v < n-1){
            mat[u][v] -= c;
            mat[v][u] -= c;
        }
        if (v < n-1){
            mat[v][v] += c;
        }
        if (u < n-1){
            mat[u][u] += c;
        }
    }
    return mat.determinant();
}

} // namespace noya2