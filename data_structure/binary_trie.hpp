#pragma once

#include"../template/template.hpp"

namespace noya2 {

template<typename T, int LOG>
struct binary_trie {
    struct node {
        node *p;
        array<node*,2> ch;
        int leaf, sz;
        node () : p(nullptr), ch({nullptr,nullptr}), leaf(0), sz(0) {}
    };
    binary_trie () : lazy(0) {}
    int size(node *v){
        if (v == nullptr) return 0;
        return v->sz;
    }
    int size(){
        return size(root);
    }
    void insert(T x){
        x ^= lazy;
        node *v = root;
        for (int i = LOG-1; i >= 0; i--){
            int j = x >> i & 1;
            if (v->ch[j] == nullptr){
                v->ch[j] = new node();
                v->ch[j]->p = v;
            }
            v = v->ch[j];
        }
        v->leaf = 1;
        update(v);
        for (int i = 0; i < LOG; i++){
            v = v->p;
            update(v);
        }
    }
    void erase(T x){
        x ^= lazy;
        node *v = root;
        for (int i = LOG-1; i >= 0; i--){
            int j = x >> i & 1;
            if (v->ch[j] == nullptr) return ;
            v = v->ch[j];
        }
        v->leaf = 0;
        update(v);
        for (int i = 0; i < LOG; i++){
            node *p = v->p;
            if (size(v) == 0){
                (v == p->ch[0] ? p->ch[0] : p->ch[1]) = nullptr;
                delete v;
            }
            v = p;
            update(v);
        }
    }
    int count(T x){
        node *v = root;
        int res = 0;
        for (int i = LOG-1; i >= 0; i--){
            int j = lazy >> i & 1;
            if (x >> i & 1){
                res += size(v->ch[j]);
                v = v->ch[j^1];
            }
            else {
                v = v->ch[j];
            }
            if (v == nullptr) break;
        }
        return res;
    }
    T get(int k){
        if (k < 0 || k >= size()) return -1;
        node *v = root;
        T ans = 0;
        for (int i = LOG-1; i >= 0; i--){
            int j = lazy >> i & 1;
            if (k < size(v->ch[j])){
                v = v->ch[j];
            }
            else {
                k -= size(v->ch[j]);
                v = v->ch[j^1];
                ans |= T(1) << i;
            }
        }
        return ans;
    }
    T mex(){
        if ((T)size() == (T(1)<<LOG)) return T(1)<<LOG;
        node *v = root;
        T ans = 0;
        for (int i = LOG-1; i >= 0; i--){
            int j = lazy >> i & 1;
            if ((T)size(v->ch[j]) < (T(1)<<i)){
                v = v->ch[j];
            }
            else {
                v = v->ch[j^1];
                ans |= T(1) << i;
            }
            if (v == nullptr) break;
        }
        return ans;
    }
    T xor_all(T x){ return lazy ^= x; }
    vector<T> enumerate(){
        vector<T> ans; ans.reserve(size());
        auto dfs = [&](auto sfs, int i, T x, node *v) -> void {
            if (i == -1){
                ans.emplace_back(x^lazy);
                return ;
            }
            if (v->ch[0] != nullptr){
                sfs(sfs,i-1,x,v->ch[0]);
            }
            if (v->ch[1] != nullptr){
                sfs(sfs,i-1,x|(T(1)<<i),v->ch[1]);
            }
        };
        dfs(dfs,LOG-1,0,root);
        return ans;
    }
  private:
    T lazy;
    node *root = new node();
    void update(node *v){
        v->sz = v->leaf + size(v->ch[0]) + size(v->ch[1]);
    }
};

} // namespace noya2