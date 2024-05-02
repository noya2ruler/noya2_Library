#pragma once

#include"../template/template.hpp"

namespace noya2{

template<class S, S (*op)(S, S)>
struct SparseTable{
    vector<vector<S>> table;
    SparseTable () {}
    SparseTable (const vector<S> &vec){
        int n = vec.size(), n2 = 0;
        while ((1<<n2) < n) n2++;
        table.resize(n2+1);
        for (int i = 0; i <= n2; i++){
            table[i].resize(n);
            if (i == 0){
                for (int j = 0; j < n; j++){
                    table[i][j] = vec[j];
                }
            }
            else {
                for (int j = 0; j < n; j++){
                    if (j + (1 << (i-1)) < n) table[i][j] = op(table[i-1][j],table[i-1][j + (1 << (i-1))]);
                    else table[i][j] = table[i-1][j];
                }
            }
        }
    }
    // 単位元を要求しないので if (l >= r) return e() みたいなことをしていない、注意すること！！
    S get(int l, int r){
        assert(r - l > 0);
        int lgs = 31 - __builtin_clz((unsigned int)(r-l));
        return op(table[lgs][l], table[lgs][r - (1 << lgs)]);
    }
};

} // namespace noya2