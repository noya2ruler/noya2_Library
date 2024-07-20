#pragma once

#include "suffix_array.hpp"

namespace noya2 {

struct suffix_array_search {
    int n;
    std::string s;
    std::vector<int> sa;
    suffix_array_search (const std::string &_s) : n(_s.size()), s(_s){
        sa = suffix_array(s);
    }
    std::pair<int,int> lower_upper_bound(const std::string &t){
        int l = 0, r = n;
        for (int i = 0; auto c : t){
            int nl = lower_bound(i, l, r, c);
            int nr = upper_bound(i, l, r, c);
            l = nl;
            r = nr;
            i++;
        }
        return {l, r};
    }
    // max i, s.t. t[0,i) is contained in s as substring
    int max_match(const std::string &t){
        int l = 0, r = n;
        int i = 0;
        for (auto c : t){
            int nl = lower_bound(i, l, r, c);
            int nr = upper_bound(i, l, r, c);
            if (nl == nr) break;
            l = nl;
            r = nr;
            i++;
        }
        return i;
    }
    // sum[i=0,1,...,n-1] lcp(s[i,n), t)
    long long sum_of_lcp(const std::string &t){
        int l = 0, r = n;
        long long ans = 0;
        for (int i = 0; auto c : t){
            int nl = lower_bound(i, l, r, c);
            int nr = upper_bound(i, l, r, c);
            ans += nr - nl;
            l = nl;
            r = nr;
            i++;
        }
        return ans;
    }
    int lower_bound(int i, int l, int r, char c){
        if (l == r) return l;
        if (is_lteq(c, sa[l] + i)) return l;
        while (r - l > 1){
            int m = (l + r) / 2;
            if (is_lteq(c, sa[m] + i)){
                r = m;
            }
            else {
                l = m;
            }
        }
        return r;
    }
    int upper_bound(int i, int l, int r, char c){
        if (l == r) return l;
        if (is_lt(c, sa[l] + i)) return l;
        while (r - l > 1){
            int m = (l + r) / 2;
            if (is_lt(c, sa[m] + i)){
                r = m;
            }
            else {
                l = m;
            }
        }
        return r;
    }
  private:
    bool is_lt(char compare, int pos){
        if (pos >= n) return false;
        return compare < s[pos];
    }
    bool is_lteq(char compare, int pos){
        if (pos >= n) return false;
        return compare <= s[pos];
    }
};

} // namespace noya2