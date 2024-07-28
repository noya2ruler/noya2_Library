#pragma once

#include <vector>
#include <algorithm>

namespace noya2{

template<typename T>
struct compress {
    std::vector<T> raws;
    compress () {}
    compress (const vector<T> &_raws) : raws(_raws){ build(); }
    void build(){
        std::sort(raws.begin(), raws.end());
        raws.erase(std::unique(raws.begin(), raws.end()), raws.end());
    }
    int id(const T &raw){ return lb(raw); }
    T raw(const int &id){ return raws[id]; }
    void add(const T &raw){ raws.emplace_back(raw); }
    void reserve(size_t sz){ raws.reserve(sz); }
    size_t size(){ return raws.size(); }
    int lb(const T &raw){ return lower_bound(all(raws),raw) - raws.begin(); }
    int ub(const T &raw){ return upper_bound(all(raws),raw) - raws.begin(); }
    bool contains(const T &raw){
        int jd = lb(raw);
        if (jd < (int)size()) return raws[jd] == raw;
        return false;
    }
    int contains_id(const T &raw){
        int jd = lb(raw);
        if (jd < (int)size() && raws[jd] == raw) return jd;
        return -1;
    }
};

} // namespace noya2