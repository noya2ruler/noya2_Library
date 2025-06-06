#pragma once

// https://ebi-fly13.github.io/Library/data_structure/dual_segtree.hpp

#include <bit>
#include <cassert>
#include <ranges>
#include <vector>

namespace noya2 {

template <class F, auto composition, auto id>
struct dual_segtree {
  private:
    void all_apply(int i, F f) {
        d[i] = composition(f, d[i]);
    }

    void push(int i) {
        assert(i < sz);
        all_apply(2 * i, d[i]);
        all_apply(2 * i + 1, d[i]);
        d[i] = id();
    }

  public:
    dual_segtree(int _n) : dual_segtree(std::vector<F>(_n, id())) {}

    dual_segtree(const std::vector<F> &a) : n(a.size()), sz(std::bit_ceil(a.size())) {
        lg2 = std::countr_zero<unsigned int>(sz);
        d.assign(2 * sz, id());
        for (int i : std::views::iota(sz, sz + n)) {
            d[i] = a[i - sz];
        }
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return;

        l += sz;
        r += sz;

        for (int i : std::views::iota(1, lg2 + 1) | std::views::reverse) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        while (l < r) {
            if (l & 1) all_apply(l++, f);
            if (r & 1) all_apply(--r, f);
            l >>= 1;
            r >>= 1;
        }
    }

    F get(int p) {
        assert(0 <= p && p < n);
        p += sz;
        for (int i : std::views::iota(1, lg2 + 1) | std::views::reverse) {
            push(p >> i);
        }
        return d[p];
    }

    void set(int p, F f){
        assert(0 <= p && p < n);
        p += sz;
        for (int i : std::views::iota(1, lg2 + 1) | std::views::reverse) {
            push(p >> i);
        }
        d[p] = f;
    }

  private:
    int n, sz, lg2;
    std::vector<F> d;
};

}  // namespace noya2