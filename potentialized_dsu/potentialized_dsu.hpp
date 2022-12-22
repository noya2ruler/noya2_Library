#pragma once

#include<vector>
#include<cassert>

namespace noya2{

template<class G, G (*op)(G, G), G(*e)(), G(*inv)(G)> struct potentialized_dsu {
    potentialized_dsu (int _n = 0) : n(_n), parent_or_size(_n,-1), potential_(_n,e()) {}
    int merge(int a, int b, G d){ // b is d higher than a, p(b) - p(a) = d
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        int x = leader(a), y = leader(b);
        if (x == y){
            if (diff(a,b) == d) return x;
            else return -1;
        }
        d = op(op(potential(a),d),inv(potential(b)));
        if (-parent_or_size[x] < -parent_or_size[y]){
            d = inv(d);
            std::swap(x, y);
        }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        potential_[y] = d;
        return x;
    }
    bool same(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        return leader(a) == leader(b);
    }
    int leader(int a){
        assert(0 <= a && a < n);
        if (parent_or_size[a] < 0) return a;
        int l = leader(parent_or_size[a]);
        potential_[a] = op(potential_[a],potential_[parent_or_size[a]]);
        return parent_or_size[a] = l;
    }
    int size(int a){
        assert(0 <= a && a < n);
        return -parent_or_size[leader(a)];
    }
    G potential(int a){
        assert(0 <= a && a < n);
        leader(a);
        return potential_[a];
    }
    G diff(int a, int b){
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        return op(inv(potential(a)),potential(b));
    }
  private:
    int n;
    std::vector<int> parent_or_size;
    std::vector<G> potential_;
};

long long plus_op(long long a, long long b){ return a + b; }
long long plus_e(){ return 0LL; }
long long plus_inv(long long a){ return -a; }
using potentialized_dsu_plus = potentialized_dsu<long long,plus_op,plus_e,plus_inv>;

} // namespace noya2