#pragma once

#include <vector>
#include <array>
#include <string>

namespace noya2 {

template<int sigma = 26, char start = 'a'>
struct aho_corasick {
    using child = std::array<int,sigma>;
    static constexpr child makeleaf(){
        child ret = {};
        ret.fill(-1);
        return ret;
    }
    static constexpr child leaf = makeleaf();
    struct node {
        int par, link, exist, match;
        char c;
        child ch;
        node () {}
        node (int _par, int _link, int _exist, int _match, char _c, child _ch) : 
            par(_par), link(_link), exist(_exist), match(_match), c(_c), ch(_ch) {}
        int operator[](char nxt) const {
            return ch[nxt - start];
        }
    };
    std::vector<node> vs;
    aho_corasick (int len = 0) {
        vs.reserve(len);
        vs.emplace_back(-1, 0, 0, 0, ' ', leaf);
    }
    int insert(const std::string &s){
        int v = 0;
        for (auto c : s){
            if (vs[v][c] == -1){
                v = add_leaf(v, c);
            }
            else {
                v = vs[v][c];
            }
        }
        vs[v].exist += 1;
        return v;
    }
    int nxt(int v, char c){
        if (vs[v][c] != -1) return vs[v][c];
        if (v == 0) return 0;
        return nxt(vs[v].link, c);
    }
    void build(){
        std::vector<int> que = {0};
        for (int i = 0; i < std::ssize(que); i++){
            int v = que[i];
            vs[v].link = (v == 0 || vs[v].par == 0 ? 0 : nxt(vs[vs[v].par].link, vs[v].c));
            vs[v].match = vs[v].exist + vs[vs[v].link].match;
            for (int cid = 0; cid < sigma; cid++){
                if (vs[v].ch[cid] != -1){
                    que.emplace_back(vs[v].ch[cid]);
                }
            }
        }
    }
    node operator[](int v) const {
        return vs[v];
    }
    size_t size() const {
        return vs.size();
    }
    int add_leaf(int par, char c){
        int v = vs.size();
        vs.emplace_back(par, -1, 0, 0, c, leaf);
        vs[par].ch[c - start] = v;
        return v;
    }
};

} // namespace noya2