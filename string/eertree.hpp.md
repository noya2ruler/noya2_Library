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
  bundledCode: "#line 2 \"string/eertree.hpp\"\n\n#include <vector>\n#include <tuple>\n\
    #include <iostream>\n#include <array>\n\nnamespace noya2 {\n\ntemplate<int sigma\
    \ = 26>\nstruct eertree {\n    static_assert(sigma <= 256);\n    using child =\
    \ std::array<int,sigma>;\n    static constexpr child makeleaf(){\n        child\
    \ ret = {};\n        ret.fill(-1);\n        return ret;\n    }\n    static constexpr\
    \ child leaf = makeleaf();\n    struct node {\n        int suffix_link;\n    \
    \    int length;\n        child ch;\n        explicit node (int _suffix_link,\
    \ int _length) : suffix_link(_suffix_link), length(_length), ch(leaf) {}\n   \
    \     friend ostream &operator<<(ostream &os, const node &p){\n            return\
    \ os << \"suffix link : \" << p.suffix_link << \" length : \" << p.length;\n \
    \       }\n    };\n    int cursor = 1;\n    std::vector<node> nodes;\n    std::vector<uint8_t>\
    \ str;\n    int find_suffix(int pos, int cur){\n        while (cur >= 0){\n  \
    \          int len = nodes[cur].length;\n            int sop = pos - len - 1;\n\
    \            if (sop >= 0 && str[sop] == str[pos]) return cur;\n            cur\
    \ = nodes[cur].suffix_link;\n        }\n        return 0;\n    }\n    eertree\
    \ (){\n        nodes = {node(-1,-1),node(0,0)};\n    }\n    // if 'a' is added,\
    \ call add_char(0)\n    // current cursor, parent of child_tree, parent of suffix_tree\n\
    \    std::tuple<int,int,int> add_char(int c){\n        int pos = str.size();\n\
    \        str.emplace_back(c);\n        cursor = find_suffix(pos, cursor);\n  \
    \      // add child to str(cursor)\n        int ch = nodes[cursor].ch[c];\n  \
    \      // already exists\n        if (ch != -1){\n            auto ret = std::make_tuple(ch,\
    \ cursor, nodes[ch].suffix_link);\n            cursor = ch;\n            return\
    \ ret;\n        }\n        // new node\n        const int ncursor = nodes.size();\n\
    \        const int nlength = nodes[cursor].length + 2;\n        const int npar\
    \ = find_suffix(pos, nodes[cursor].suffix_link);\n        int nsuffix_link = nodes[npar].ch[c];\n\
    \        // c is new char\n        if (nsuffix_link == -1){\n            nsuffix_link\
    \ = 1;\n        }\n        nodes[cursor].ch[c] = ncursor;\n        nodes.emplace_back(nsuffix_link,\
    \ nlength);\n        auto ret = make_tuple(ncursor, cursor, nsuffix_link);\n \
    \       cursor = ncursor;\n        return ret;\n    }\n    node operator[](int\
    \ idx) const {\n        return nodes[idx];\n    }\n};\n\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <tuple>\n#include <iostream>\n\
    #include <array>\n\nnamespace noya2 {\n\ntemplate<int sigma = 26>\nstruct eertree\
    \ {\n    static_assert(sigma <= 256);\n    using child = std::array<int,sigma>;\n\
    \    static constexpr child makeleaf(){\n        child ret = {};\n        ret.fill(-1);\n\
    \        return ret;\n    }\n    static constexpr child leaf = makeleaf();\n \
    \   struct node {\n        int suffix_link;\n        int length;\n        child\
    \ ch;\n        explicit node (int _suffix_link, int _length) : suffix_link(_suffix_link),\
    \ length(_length), ch(leaf) {}\n        friend ostream &operator<<(ostream &os,\
    \ const node &p){\n            return os << \"suffix link : \" << p.suffix_link\
    \ << \" length : \" << p.length;\n        }\n    };\n    int cursor = 1;\n   \
    \ std::vector<node> nodes;\n    std::vector<uint8_t> str;\n    int find_suffix(int\
    \ pos, int cur){\n        while (cur >= 0){\n            int len = nodes[cur].length;\n\
    \            int sop = pos - len - 1;\n            if (sop >= 0 && str[sop] ==\
    \ str[pos]) return cur;\n            cur = nodes[cur].suffix_link;\n        }\n\
    \        return 0;\n    }\n    eertree (){\n        nodes = {node(-1,-1),node(0,0)};\n\
    \    }\n    // if 'a' is added, call add_char(0)\n    // current cursor, parent\
    \ of child_tree, parent of suffix_tree\n    std::tuple<int,int,int> add_char(int\
    \ c){\n        int pos = str.size();\n        str.emplace_back(c);\n        cursor\
    \ = find_suffix(pos, cursor);\n        // add child to str(cursor)\n        int\
    \ ch = nodes[cursor].ch[c];\n        // already exists\n        if (ch != -1){\n\
    \            auto ret = std::make_tuple(ch, cursor, nodes[ch].suffix_link);\n\
    \            cursor = ch;\n            return ret;\n        }\n        // new\
    \ node\n        const int ncursor = nodes.size();\n        const int nlength =\
    \ nodes[cursor].length + 2;\n        const int npar = find_suffix(pos, nodes[cursor].suffix_link);\n\
    \        int nsuffix_link = nodes[npar].ch[c];\n        // c is new char\n   \
    \     if (nsuffix_link == -1){\n            nsuffix_link = 1;\n        }\n   \
    \     nodes[cursor].ch[c] = ncursor;\n        nodes.emplace_back(nsuffix_link,\
    \ nlength);\n        auto ret = make_tuple(ncursor, cursor, nsuffix_link);\n \
    \       cursor = ncursor;\n        return ret;\n    }\n    node operator[](int\
    \ idx) const {\n        return nodes[idx];\n    }\n};\n\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: string/eertree.hpp
  requiredBy: []
  timestamp: '2024-12-04 14:23:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/eertree.hpp
layout: document
redirect_from:
- /library/string/eertree.hpp
- /library/string/eertree.hpp.html
title: string/eertree.hpp
---
