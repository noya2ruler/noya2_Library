#pragma once

#include"../template/template.hpp"

namespace noya2{

template<typename T> struct compress {
    vector<T> raws;
    compress(const vector<T> &raws_ = {}) : raws(raws_){ build(); }
    int id(const T &raw){ return lower_bound(all(raws),raw) - raws.begin(); }
    T raw(const int &id){ return raws[id]; }
    void build(){ uniq(raws); }
    void add(const T &raw){ raws.push_back(raw); }
    size_t size(){ return raws.size(); }
    int lb(const T &raw){ return lower_bound(all(raws),raw) - raws.begin(); }
    int ub(const T &raw){ return upper_bound(all(raws),raw) - raws.begin(); }
};

} // namespace noya2