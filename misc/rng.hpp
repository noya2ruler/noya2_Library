#pragma once

#include"../template/template.hpp"

namespace noya2 {

// [0, 2^64 - 1)
ull rng() {
  static ull _x = 88172645463325252UL;
  return _x ^= _x << 7, _x ^= _x >> 9;
}

// [l, r]
ll rng(ll l, ll r) {
  assert(l <= r);
  return l + rng() % ull(r - l + 1);
}

// [l, r)
ll randint(ll l, ll r) {
  assert(l < r);
  return l + rng() % ull(r - l);
}

} // namespace noya2
