#pragma once

#include<random>

#include"utility/modint61.hpp"

namespace noya2 {

struct roriha_group {
    struct value_type {
        modint61 h, base_pow, ibase_pow;
    };
    static constexpr value_type op(value_type a, value_type b){
        return {a.h + a.base_pow * b.h, a.base_pow * b.base_pow, a.ibase_pow * b.ibase_pow};
    }
    static constexpr value_type e(){
        return {0LL, 1LL, 1LL};
    }
    static constexpr value_type inv(value_type a){
        return {-a.h * a.ibase_pow, a.ibase_pow, a.base_pow};
    }
    template<typename T>
    static constexpr value_type val(T c){
        return {modint61(c), base, ibase};
    }
    static modint61 base, ibase;
    static void set_base(){
        std::random_device rd;
        std::mt19937_64 mt(rd());
        base = mt();
        ibase = base.inv();
    }
};
modint61 roriha_group::base = 1;
modint61 roriha_group::ibase = 1;

} // namespace noya2