#pragma once

#include <vector>
#include <cassert>
#include <algorithm>

namespace noya2 {

// f mapsto F
// F(S) = sum[T subset S] f(T)
//      = f(S) o ...
template<typename T, class Op = std::plus<T>>
void bitwise_zeta_transform(std::vector<T> &a){
    uint32_t sz = a.size();
    assert(std::has_single_bit(sz));
    Op op{};
    for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){
        for (uint32_t u = 0; u < sz; u += (p2 << 1)){
            for (uint32_t d = 0; d < p2; d++){
                a[d ^ u ^ p2] = op(a[d ^ u ^ p2], a[d ^ u]);
            }
        }
    }
}


// inverse transform of zeta : F mapsto f
template<typename T, class Opinv = std::minus<T>>
void bitwise_mobius_transform(std::vector<T> &a){
    uint32_t sz = a.size();
    assert(std::has_single_bit(sz));
    Opinv opinv{};
    for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){
        for (uint32_t u = 0; u < sz; u += (p2 << 1)){
            for (uint32_t d = 0; d < p2; d++){
                a[d ^ u ^ p2] = opinv(a[d ^ u ^ p2], a[d ^ u]);
            }
        }
    }
}

template<typename T>
std::vector<T> bitwise_or_convolution(std::vector<T> a, std::vector<T> b){
    assert(a.size() == b.size());
    uint32_t sz = a.size();
    bitwise_zeta_transform<T, std::plus<T>>(a);
    bitwise_zeta_transform<T, std::plus<T>>(b);
    for (uint32_t i = 0; i < sz; i++){
        a[i] *= b[i];
    }
    bitwise_mobius_transform<T, std::minus<T>>(a);
    return a;
}

template<typename T>
std::vector<T> bitwise_and_convolution(std::vector<T> a, std::vector<T> b){
    assert(a.size() == b.size());
    uint32_t sz = a.size();
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    bitwise_zeta_transform<T, std::plus<T>>(a);
    bitwise_zeta_transform<T, std::plus<T>>(b);
    for (uint32_t i = 0; i < sz; i++){
        a[i] *= b[i];
    }
    bitwise_mobius_transform<T, std::minus<T>>(a);
    std::reverse(a.begin(), a.end());
    return a;
}

template<typename T>
void hadamard_transform(std::vector<T> &a){
    uint32_t sz = a.size();
    assert(std::has_single_bit(sz));
    for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){
        for (uint32_t u = 0; u < sz; u += (p2 << 1)){
            for (uint32_t d = 0; d < p2; d++){
                T s = a[d ^ u], t = a[d ^ u ^ p2];
                a[d ^ u] = s + t;
                a[d ^ u ^ p2] = s - t;
            }
        }
    }
}

template<typename T>
std::vector<T> bitwise_xor_convolution(std::vector<T> a, std::vector<T> b){
    assert(a.size() == b.size());
    uint32_t sz = a.size();
    hadamard_transform(a);
    hadamard_transform(b);
    T iv = T(1) / T(sz);
    for (uint32_t i = 0; i < sz; i++){
        a[i] *= b[i] * iv;
    }
    hadamard_transform(a);
    return a;
}

template<typename T, int LOG>
std::vector<T> subset_convolution(const std::vector<T> &a, const std::vector<T> &b){
    assert(a.size() == b.size());
    using fps = std::array<T, LOG + 1>;
    constexpr int s = LOG;
    uint32_t sz = a.size();
    auto bitwise_or_zeta_transform = [&]<typename is_zeta>(std::vector<fps> &c, is_zeta z){
        for (uint32_t p2 = 1; p2 < sz; p2 <<= 1){
            for (uint32_t u = 0; u < sz; u += (p2 << 1)){
                for (uint32_t d = 0; d < p2; d++){
                    for (int i = 0; i <= s; i++){
                        if constexpr (is_zeta::value){
                            c[d ^ u ^ p2][i] += c[d ^ u][i];
                        }
                        else {
                            c[d ^ u ^ p2][i] -= c[d ^ u][i];
                        }
                    }
                }
            }
        }
    };
    auto lift = [&](const std::vector<T> &c){
        std::vector<fps> C(sz, fps{});
        for (uint32_t i = 0; i < sz; i++){
            C[i][std::popcount(i)] = c[i];
        }
        return C;
    };
    auto A = lift(a), B = lift(b);
    bitwise_or_zeta_transform(A, std::true_type{});
    bitwise_or_zeta_transform(B, std::true_type{});
    for (uint32_t i = 0; i < sz; i++){
        fps c = {};
        for (int x = 0; x <= s; x++){
            for (int y = 0; y <= s - x; y++){
                c[x + y] += A[i][x] * B[i][y];
            }
        }
        std::swap(A[i], c);
    }
    bitwise_or_zeta_transform(A, std::false_type{});
    std::vector<T> ab(sz);
    for (uint32_t i = 0; i < sz; i++){
        ab[i] = A[i][std::popcount(i)];
    }
    return ab;
}

} // namespace noya2