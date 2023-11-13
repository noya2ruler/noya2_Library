#pragma once

#include<concepts>

namespace noya2 {

template<class monoid>
concept Monoid = requires {
    typename monoid::value_type;
    {monoid::op(declval<typename monoid::value_type>(),declval<typename monoid::value_type>())} -> std::same_as<typename monoid::value_type>;
    {monoid::e()} -> std::same_as<typename monoid::value_type>;
};

template<class group>
concept Group = requires {
    requires Monoid<group>;
    {group::inv(declval<typename group::value_type>())} -> std::same_as<typename group::value_type>;
};

} // namespace noya2