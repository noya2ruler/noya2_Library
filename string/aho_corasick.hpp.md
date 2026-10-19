---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/AhoCorasick.test.cpp
    title: test/string/AhoCorasick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/aho_corasick.hpp\"\n\n#include <vector>\n#include\
    \ <array>\n#include <string>\n\nnamespace noya2 {\n\ntemplate<int sigma = 26,\
    \ char start = 'a'>\nstruct aho_corasick {\n    using child = std::array<int,sigma>;\n\
    \    static constexpr child makeleaf(){\n        child ret = {};\n        ret.fill(-1);\n\
    \        return ret;\n    }\n    static constexpr child leaf = makeleaf();\n \
    \   struct node {\n        int par, link, exist, match;\n        char c;\n   \
    \     child ch;\n        node () {}\n        node (int _par, int _link, int _exist,\
    \ int _match, char _c, child _ch) : \n            par(_par), link(_link), exist(_exist),\
    \ match(_match), c(_c), ch(_ch) {}\n        int operator[](char nxt) const {\n\
    \            return ch[nxt - start];\n        }\n    };\n    std::vector<node>\
    \ vs;\n    aho_corasick (int len = 0) {\n        vs.reserve(len);\n        vs.emplace_back(-1,\
    \ 0, 0, 0, ' ', leaf);\n    }\n    int insert(const std::string &s){\n       \
    \ int v = 0;\n        for (auto c : s){\n            if (vs[v][c] == -1){\n  \
    \              v = add_leaf(v, c);\n            }\n            else {\n      \
    \          v = vs[v][c];\n            }\n        }\n        vs[v].exist += 1;\n\
    \        return v;\n    }\n    int nxt(int v, char c){\n        if (vs[v][c] !=\
    \ -1) return vs[v][c];\n        if (v == 0) return 0;\n        return nxt(vs[v].link,\
    \ c);\n    }\n    void build(){\n        std::vector<int> que = {0};\n       \
    \ for (int i = 0; i < std::ssize(que); i++){\n            int v = que[i];\n  \
    \          vs[v].link = (v == 0 || vs[v].par == 0 ? 0 : nxt(vs[vs[v].par].link,\
    \ vs[v].c));\n            vs[v].match = vs[v].exist + vs[vs[v].link].match;\n\
    \            for (int cid = 0; cid < sigma; cid++){\n                if (vs[v].ch[cid]\
    \ != -1){\n                    que.emplace_back(vs[v].ch[cid]);\n            \
    \    }\n            }\n        }\n    }\n    node operator[](int v) const {\n\
    \        return vs[v];\n    }\n    size_t size() const {\n        return vs.size();\n\
    \    }\n    int add_leaf(int par, char c){\n        int v = vs.size();\n     \
    \   vs.emplace_back(par, -1, 0, 0, c, leaf);\n        vs[par].ch[c - start] =\
    \ v;\n        return v;\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <array>\n#include <string>\n\n\
    namespace noya2 {\n\ntemplate<int sigma = 26, char start = 'a'>\nstruct aho_corasick\
    \ {\n    using child = std::array<int,sigma>;\n    static constexpr child makeleaf(){\n\
    \        child ret = {};\n        ret.fill(-1);\n        return ret;\n    }\n\
    \    static constexpr child leaf = makeleaf();\n    struct node {\n        int\
    \ par, link, exist, match;\n        char c;\n        child ch;\n        node ()\
    \ {}\n        node (int _par, int _link, int _exist, int _match, char _c, child\
    \ _ch) : \n            par(_par), link(_link), exist(_exist), match(_match), c(_c),\
    \ ch(_ch) {}\n        int operator[](char nxt) const {\n            return ch[nxt\
    \ - start];\n        }\n    };\n    std::vector<node> vs;\n    aho_corasick (int\
    \ len = 0) {\n        vs.reserve(len);\n        vs.emplace_back(-1, 0, 0, 0, '\
    \ ', leaf);\n    }\n    int insert(const std::string &s){\n        int v = 0;\n\
    \        for (auto c : s){\n            if (vs[v][c] == -1){\n               \
    \ v = add_leaf(v, c);\n            }\n            else {\n                v =\
    \ vs[v][c];\n            }\n        }\n        vs[v].exist += 1;\n        return\
    \ v;\n    }\n    int nxt(int v, char c){\n        if (vs[v][c] != -1) return vs[v][c];\n\
    \        if (v == 0) return 0;\n        return nxt(vs[v].link, c);\n    }\n  \
    \  void build(){\n        std::vector<int> que = {0};\n        for (int i = 0;\
    \ i < std::ssize(que); i++){\n            int v = que[i];\n            vs[v].link\
    \ = (v == 0 || vs[v].par == 0 ? 0 : nxt(vs[vs[v].par].link, vs[v].c));\n     \
    \       vs[v].match = vs[v].exist + vs[vs[v].link].match;\n            for (int\
    \ cid = 0; cid < sigma; cid++){\n                if (vs[v].ch[cid] != -1){\n \
    \                   que.emplace_back(vs[v].ch[cid]);\n                }\n    \
    \        }\n        }\n    }\n    node operator[](int v) const {\n        return\
    \ vs[v];\n    }\n    size_t size() const {\n        return vs.size();\n    }\n\
    \    int add_leaf(int par, char c){\n        int v = vs.size();\n        vs.emplace_back(par,\
    \ -1, 0, 0, c, leaf);\n        vs[par].ch[c - start] = v;\n        return v;\n\
    \    }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2025-09-18 15:38:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/AhoCorasick.test.cpp
documentation_of: string/aho_corasick.hpp
layout: document
redirect_from:
- /library/string/aho_corasick.hpp
- /library/string/aho_corasick.hpp.html
title: string/aho_corasick.hpp
---
