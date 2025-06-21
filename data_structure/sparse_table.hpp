#pragma once

#include <vector>
#include <cassert>

namespace noya2{

template<class S, S (*op)(S, S)>
struct sparse_table {
    std::vector<std::vector<S>> table;
    sparse_table () {}
    sparse_table (const std::vector<S> &vec){
        int n = vec.size(), n2 = 0;
        while ((1<<n2) <= n) n2++;
        table.resize(n2);
        table[0] = vec;
        for (int i = 0; i < n2-1; i++){
            int nsz = table[i].size() - (1 << i);
            table[i + 1].resize(nsz);
            for (int j = 0; j < nsz; j++){
                table[i + 1][j] = op(table[i][j], table[i][j + (1 << i)]);
            }
        }
    }
    // 単位元を要求しないので if (l >= r) return e() みたいなことをしていない、注意すること！！
    S prod(int l, int r) const {
        assert(0 <= l && l < r && r <= (int)(table[0].size()));
        int lgs = 31 - __builtin_clz((unsigned int)(r-l));
        return op(table[lgs][l], table[lgs][r - (1 << lgs)]);
    }
};

} // namespace noya2