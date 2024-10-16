---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/grid.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <ranges>\n\nnamespace noya2 {\n\nstruct grid {\n    int h, w;\n    grid\
    \ (int _h = 0, int _w = 0) : h(_h), w(_w) {}\n    int idx(int x, int y) const\
    \ {\n        return x * w + y;\n    }\n    std::pair<int,int> pos(int id) const\
    \ {\n        return {id / w, id % w};\n    }\n    bool operator()(int x, int y)\
    \ const {\n        return 0 <= x && x < h && 0 <= y && y < w;\n    }\n    bool\
    \ operator()(int id) const {\n        return operator()(id / w, id % w);\n   \
    \ }\n    static constexpr std::array<std::pair<int,int>, 4> dxys = {std::pair<int,int>{0,\
    \ 1}, {-1, 0}, {0, -1}, {1, 0}};\n    auto adj4(int x, int y) const {\n      \
    \  return dxys | std::views::transform([x, y](std::pair<int,int> dxy){\n     \
    \       return std::pair<int,int>(dxy.first + x, dxy.second + y);\n        })\
    \ | std::views::filter([this](std::pair<int,int> xy){\n            return operator()(xy.first,\
    \ xy.second);\n        });\n    }\n    auto adj4(int id) const {\n        return\
    \ adj4(id / w, id % w) | std::ranges::views::transform([this](std::pair<int,int>\
    \ xy){\n            return idx(xy.first, xy.second);\n        });\n    }\n};\n\
    \n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <ranges>\n\
    \nnamespace noya2 {\n\nstruct grid {\n    int h, w;\n    grid (int _h = 0, int\
    \ _w = 0) : h(_h), w(_w) {}\n    int idx(int x, int y) const {\n        return\
    \ x * w + y;\n    }\n    std::pair<int,int> pos(int id) const {\n        return\
    \ {id / w, id % w};\n    }\n    bool operator()(int x, int y) const {\n      \
    \  return 0 <= x && x < h && 0 <= y && y < w;\n    }\n    bool operator()(int\
    \ id) const {\n        return operator()(id / w, id % w);\n    }\n    static constexpr\
    \ std::array<std::pair<int,int>, 4> dxys = {std::pair<int,int>{0, 1}, {-1, 0},\
    \ {0, -1}, {1, 0}};\n    auto adj4(int x, int y) const {\n        return dxys\
    \ | std::views::transform([x, y](std::pair<int,int> dxy){\n            return\
    \ std::pair<int,int>(dxy.first + x, dxy.second + y);\n        }) | std::views::filter([this](std::pair<int,int>\
    \ xy){\n            return operator()(xy.first, xy.second);\n        });\n   \
    \ }\n    auto adj4(int id) const {\n        return adj4(id / w, id % w) | std::ranges::views::transform([this](std::pair<int,int>\
    \ xy){\n            return idx(xy.first, xy.second);\n        });\n    }\n};\n\
    \n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: graph/grid.hpp
  requiredBy: []
  timestamp: '2024-10-17 01:43:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/grid.hpp
layout: document
redirect_from:
- /library/graph/grid.hpp
- /library/graph/grid.hpp.html
title: graph/grid.hpp
---
