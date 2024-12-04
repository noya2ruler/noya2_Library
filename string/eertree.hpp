#pragma once

#include <vector>
#include <tuple>
#include <iostream>
#include <array>

namespace noya2 {

template<int sigma = 26>
struct eertree {
    static_assert(sigma <= 256);
    using child = std::array<int,sigma>;
    static constexpr child makeleaf(){
        child ret = {};
        ret.fill(-1);
        return ret;
    }
    static constexpr child leaf = makeleaf();
    struct node {
        int suffix_link;
        int length;
        child ch;
        explicit node (int _suffix_link, int _length) : suffix_link(_suffix_link), length(_length), ch(leaf) {}
    };
    int cursor = 1;
    std::vector<node> nodes;
    std::vector<uint8_t> str;
    int find_suffix(int pos, int cur){
        while (cur >= 0){
            int len = nodes[cur].length;
            int sop = pos - len - 1;
            if (sop >= 0 && str[sop] == str[pos]) return cur;
            cur = nodes[cur].suffix_link;
        }
        return 0;
    }
    eertree (){
        nodes = {node(-1,-1),node(0,0)};
    }
    // if 'a' is added, call add_char(0)
    // current cursor, parent of child_tree, parent of suffix_tree
    std::tuple<int,int,int> add_char(int c){
        int pos = str.size();
        str.emplace_back(c);
        cursor = find_suffix(pos, cursor);
        // add child to str(cursor)
        int ch = nodes[cursor].ch[c];
        // already exists
        if (ch != -1){
            auto ret = std::make_tuple(ch, cursor, nodes[ch].suffix_link);
            cursor = ch;
            return ret;
        }
        // new node
        const int ncursor = nodes.size();
        const int nlength = nodes[cursor].length + 2;
        const int npar = find_suffix(pos, nodes[cursor].suffix_link);
        int nsuffix_link = nodes[npar].ch[c];
        // c is new char
        if (nsuffix_link == -1){
            nsuffix_link = 1;
        }
        nodes[cursor].ch[c] = ncursor;
        nodes.emplace_back(nsuffix_link, nlength);
        auto ret = std::make_tuple(ncursor, cursor, nsuffix_link);
        cursor = ncursor;
        return ret;
    }
    node operator[](int idx) const {
        return nodes[idx];
    }
};


} // namespace noya2