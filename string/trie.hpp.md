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
  bundledCode: "#line 2 \"string/trie.hpp\"\n\n#include <array>\n#include <vector>\n\
    #include <string>\n\nnamespace noya2 {\n\n// ALPHABET = {'a','b',...,'a'+sigma-1}\n\
    template<int sigma = 26, char start = 'a'>\nstruct trie {\n    using child = std::array<int,sigma>;\n\
    \    static constexpr child makeleaf(){\n        child ret = {};\n        ret.fill(-1);\n\
    \        return ret;\n    }\n    static constexpr child leaf = makeleaf();\n \
    \   struct node {\n        int par;\n        child ch;\n        int exist; //\
    \ trie includes {exist} strings which end with this node\n        int size; //\
    \ trie includes {size} strings which exist under(or itself) this node\n      \
    \  int operator[](const char &c) const {\n            int a = c - start;\n   \
    \         return this->ch[a];\n        }\n        int &operator[](const char &c){\n\
    \            int a = c - start;\n            return this->ch[a];\n        }\n\
    \    };\n    static constexpr node nullnode{-2,leaf,0,0};\n    std::vector<node>\
    \ nodes;\n    trie () : nodes(1,node{-1,leaf,0,0}) {}\n    void insert(const std::string\
    \ &s){\n        int cur = 0;\n        for (const char c : s){\n            if\
    \ (nodes[cur][c] == -1){\n                nodes[cur][c] = add_leaf(cur);\n   \
    \         }\n            cur = nodes[cur][c];\n        }\n        nodes[cur].exist\
    \ += 1;\n        while (cur != -1){\n            update(cur);\n            cur\
    \ = nodes[cur].par;\n        }\n    }\n    void erase(const std::string &s){\n\
    \        int cur = 0;\n        for (const char c : s){\n            if (nodes[cur][c]\
    \ == -1){\n                // not found\n                return ;\n          \
    \  }\n            cur = nodes[cur][c];\n        }\n        nodes[cur].exist -=\
    \ 1;\n        while (cur != -1){\n            update(cur);\n            cur =\
    \ nodes[cur].par;\n        }\n    }\n    int size(int nid) const {\n        if\
    \ (nid == -1) return 0;\n        return nodes[nid].size;\n    }\n    node operator[](int\
    \ nid){\n        // assert(0 <= nid && nid < (int)(nodes.size()));\n        return\
    \ nodes[nid];\n    }\n    int find(const std::string &s){\n        int cur = 0;\n\
    \        for (const char c : s){\n            if (nodes[cur][c] == -1){\n    \
    \            // not found\n                return -1;\n            }\n       \
    \     cur = nodes[cur][c];\n        }\n        return cur;\n    }\n    bool contains(const\
    \ std::string &s){\n        return find(s) != -1;\n    }\n  private:\n    int\
    \ add_leaf(int par){\n        int index = nodes.size();\n        nodes.push_back(node{par,leaf,0,0});\n\
    \        return index;\n    }\n    void update(int nid){\n        int res = nodes[nid].exist;\n\
    \        for (int cid : nodes[nid].ch){\n            res += size(cid);\n     \
    \   }\n        nodes[nid].size = res;\n    }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <array>\n#include <vector>\n#include <string>\n\n\
    namespace noya2 {\n\n// ALPHABET = {'a','b',...,'a'+sigma-1}\ntemplate<int sigma\
    \ = 26, char start = 'a'>\nstruct trie {\n    using child = std::array<int,sigma>;\n\
    \    static constexpr child makeleaf(){\n        child ret = {};\n        ret.fill(-1);\n\
    \        return ret;\n    }\n    static constexpr child leaf = makeleaf();\n \
    \   struct node {\n        int par;\n        child ch;\n        int exist; //\
    \ trie includes {exist} strings which end with this node\n        int size; //\
    \ trie includes {size} strings which exist under(or itself) this node\n      \
    \  int operator[](const char &c) const {\n            int a = c - start;\n   \
    \         return this->ch[a];\n        }\n        int &operator[](const char &c){\n\
    \            int a = c - start;\n            return this->ch[a];\n        }\n\
    \    };\n    static constexpr node nullnode{-2,leaf,0,0};\n    std::vector<node>\
    \ nodes;\n    trie () : nodes(1,node{-1,leaf,0,0}) {}\n    void insert(const std::string\
    \ &s){\n        int cur = 0;\n        for (const char c : s){\n            if\
    \ (nodes[cur][c] == -1){\n                nodes[cur][c] = add_leaf(cur);\n   \
    \         }\n            cur = nodes[cur][c];\n        }\n        nodes[cur].exist\
    \ += 1;\n        while (cur != -1){\n            update(cur);\n            cur\
    \ = nodes[cur].par;\n        }\n    }\n    void erase(const std::string &s){\n\
    \        int cur = 0;\n        for (const char c : s){\n            if (nodes[cur][c]\
    \ == -1){\n                // not found\n                return ;\n          \
    \  }\n            cur = nodes[cur][c];\n        }\n        nodes[cur].exist -=\
    \ 1;\n        while (cur != -1){\n            update(cur);\n            cur =\
    \ nodes[cur].par;\n        }\n    }\n    int size(int nid) const {\n        if\
    \ (nid == -1) return 0;\n        return nodes[nid].size;\n    }\n    node operator[](int\
    \ nid){\n        // assert(0 <= nid && nid < (int)(nodes.size()));\n        return\
    \ nodes[nid];\n    }\n    int find(const std::string &s){\n        int cur = 0;\n\
    \        for (const char c : s){\n            if (nodes[cur][c] == -1){\n    \
    \            // not found\n                return -1;\n            }\n       \
    \     cur = nodes[cur][c];\n        }\n        return cur;\n    }\n    bool contains(const\
    \ std::string &s){\n        return find(s) != -1;\n    }\n  private:\n    int\
    \ add_leaf(int par){\n        int index = nodes.size();\n        nodes.push_back(node{par,leaf,0,0});\n\
    \        return index;\n    }\n    void update(int nid){\n        int res = nodes[nid].exist;\n\
    \        for (int cid : nodes[nid].ch){\n            res += size(cid);\n     \
    \   }\n        nodes[nid].size = res;\n    }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2025-02-15 20:53:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
