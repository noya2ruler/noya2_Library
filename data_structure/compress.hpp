#pragma once

#include<vector>
#include<algorithm>

namespace noya2{

template<typename T> struct compress {
    std::vector<T> raws;
    compress(const std::vector<T> &raws_) : raws(raws_){
        std::sort(raws.begin(),raws.end());
        raws.erase(std::unique(rows.begin(),rows.end()),rows.end());
    }
    int id(T raw){ return std::lower_bound(raws.begin(),raws.end(),raw) - raws.begin(); }
    T raw(int id){ return raws[id]; }
};

} // namespace noya2