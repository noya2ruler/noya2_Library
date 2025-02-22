#pragma once

#include<limits>

namespace noya2{

template<typename T>
struct max_monoid {
    using value_type = T;
    static constexpr T op(const T &a, const T &b){ return max(a,b); }
    static constexpr T e(){ return std::numeric_limits<T>::min(); }
    static constexpr T inv(const T &a){ return e(); }
};
template<typename T>
struct min_monoid {
    using value_type = T;
    static constexpr T op(const T &a, const T &b){ return min(a,b); }
    static constexpr T e(){ return std::numeric_limits<T>::max(); }
    static constexpr T inv(const T &a){ return e(); }
};
template<typename T>
struct plus_group {
    using value_type = T;
    static constexpr T op(const T &a, const T &b){ return a + b; }
    static constexpr T e(){ return T(0); }
    static constexpr T inv(const T &a){ return -a; }
};
template<typename T>
struct xor_group {
    using value_type = T;
    static constexpr T op(const T &a, const T &b){ return a ^ b; }
    static constexpr T e(){ return T(0); }
    static constexpr T inv(const T &a){ return a; }
};

template<class S, auto _op, auto _e>
struct monoid {
    using value_type = S;
    static constexpr value_type op(value_type a, value_type b){
        return _op(a, b);
    }
    static constexpr value_type e(){
        return _e();
    }
};
  
} // namespace noya2
