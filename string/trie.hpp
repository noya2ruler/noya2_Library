#pragma once

#include <array>
#include <vector>
#include <string>

namespace noya2 {

// ALPHABET = {'a','b',...,'a'+sigma-1}
template<int sigma = 26>
struct trie {
    using child = std::array<int,sigma>;
    static constexpr child makeleaf(){
        child ret = {};
        ret.fill(-1);
        return ret;
    }
    static constexpr child leaf = makeleaf();
    struct node {
        int par;
        child ch;
        int exist; // trie includes {exist} strings which end with this node
        int size; // trie includes {size} strings which exist under(or itself) this node
        int operator[](const char &c) const {
            int a = c - 'a';
            return this->ch[a];
        }
        int &operator[](const char &c){
            int a = c - 'a';
            return this->ch[a];
        }
    };
    static constexpr node nullnode{-2,leaf,0,0};
    std::vector<node> nodes;
    trie () : nodes(1,node{-1,leaf,0,0}) {}
    void insert(const std::string &s){
        int cur = 0;
        for (const char c : s){
            if (nodes[cur][c] == -1){
                nodes[cur][c] = add_leaf(cur);
            }
            cur = nodes[cur][c];
        }
        nodes[cur].exist += 1;
        while (cur != -1){
            update(cur);
            cur = nodes[cur].par;
        }
    }
    void erase(const std::string &s){
        int cur = 0;
        for (const char c : s){
            if (nodes[cur][c] == -1){
                // not found
                return ;
            }
            cur = nodes[cur][c];
        }
        nodes[cur].exist -= 1;
        while (cur != -1){
            update(cur);
            cur = nodes[cur].par;
        }
    }
    int size(int nid) const {
        if (nid == -1) return 0;
        return nodes[nid].size;
    }
    node operator[](int nid){
        // assert(0 <= nid && nid < (int)(nodes.size()));
        return nodes[nid];
    }
    int find(const std::string &s){
        int cur = 0;
        for (const char c : s){
            if (nodes[cur][c] == -1){
                // not found
                return -1;
            }
            cur = nodes[cur][c];
        }
        return cur;
    }
    bool contains(const std::string &s){
        return find(s) != -1;
    }
  private:
    int add_leaf(int par){
        int index = nodes.size();
        nodes.push_back(node{par,leaf,0,0});
        return index;
    }
    void update(int nid){
        int res = nodes[nid].exist;
        for (int cid : nodes[nid].ch){
            res += size(cid);
        }
        nodes[nid].size = res;
    }
};

} // namespace noya2