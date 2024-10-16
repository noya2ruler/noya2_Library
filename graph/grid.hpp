#pragma once

#include <vector>
#include <utility>
#include <ranges>

namespace noya2 {

struct grid {
    int h, w;
    grid (int _h = 0, int _w = 0) : h(_h), w(_w) {}
    int idx(int x, int y) const {
        return x * w + y;
    }
    std::pair<int,int> pos(int id) const {
        return {id / w, id % w};
    }
    bool operator()(int x, int y) const {
        return 0 <= x && x < h && 0 <= y && y < w;
    }
    bool operator()(int id) const {
        return operator()(id / w, id % w);
    }
    static constexpr std::array<std::pair<int,int>, 4> dxys = {std::pair<int,int>{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    auto adj4(int x, int y) const {
        return dxys | std::views::transform([x, y](std::pair<int,int> dxy){
            return std::pair<int,int>(dxy.first + x, dxy.second + y);
        }) | std::views::filter([this](std::pair<int,int> xy){
            return operator()(xy.first, xy.second);
        });
    }
    auto adj4(int id) const {
        return adj4(id / w, id % w) | std::ranges::views::transform([this](std::pair<int,int> xy){
            return idx(xy.first, xy.second);
        });
    }
};

} // namespace noya2