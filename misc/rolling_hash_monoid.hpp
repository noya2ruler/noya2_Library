#pragma once

#include"utility/modint61.hpp"

namespace noya2 {

struct roriha_group {
    struct value_type {
        modint61 h, base_pow;
    };
    static constexpr value_type op(value_type a, value_type b){
        return {a.h + a.base_pow * b.h, a.base_pow * b.base_pow};
    }
    static constexpr value_type e(){
        return {0LL, 1LL};
    }
    static constexpr value_type inv(value_type a){
        auto iv = a.base_pow.inv();
        return {-a.h * iv, iv};
    }
};

} // namespace noya2