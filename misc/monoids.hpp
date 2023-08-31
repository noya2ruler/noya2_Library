#pragma once

#include<limits>

namespace noya2{

template<typename T>
struct Max_monoid {
    using value_type = T;
    static constexpr T op(const T &a, const T &b){ return max(a,b); }
    static constexpr T e(){ return std::numeric_limits<T>::min(); }
    static constexpr T inv(const T &a){ return e(); }
};
template<typename T>
struct Min_monoid {
    using value_type = T;
    static constexpr T op(const T &a, const T &b){ return min(a,b); }
    static constexpr T e(){ return std::numeric_limits<T>::max(); }
    static constexpr T inv(const T &a){ return e(); }
};
template<typename T>
struct Plus_group {
    using value_type = T;
    static constexpr T op(const T &a, const T &b){ return a + b; }
    static constexpr T e(){ return T(0); }
    static constexpr T inv(const T &a){ return -a; }
};
template<typename T>
struct Xor_group {
    using value_type = T;
    static constexpr T op(const T &a, const T &b){ return a ^ b; }
    static constexpr T e(){ return T(0); }
    static constexpr T inv(const T &a){ return a; }
};
    
} // namespace noya2
