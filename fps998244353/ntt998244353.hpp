#pragma once

#include "modint998244353.hpp"

#include <cassert>
#include <vector>

namespace noya2 {

namespace internal {

constexpr int FFT_MAX = 23;
constexpr unsigned FFT_ROOTS[FFT_MAX + 1] = {1U, 998244352U, 911660635U, 372528824U, 929031873U, 452798380U, 922799308U, 781712469U, 476477967U, 166035806U, 258648936U, 584193783U, 63912897U, 350007156U, 666702199U, 968855178U, 629671588U, 24514907U, 996173970U, 363395222U, 565042129U, 733596141U, 267099868U, 15311432U};
constexpr unsigned INV_FFT_ROOTS[FFT_MAX + 1] = {1U, 998244352U, 86583718U, 509520358U, 337190230U, 87557064U, 609441965U, 135236158U, 304459705U, 685443576U, 381598368U, 335559352U, 129292727U, 358024708U, 814576206U, 708402881U, 283043518U, 3707709U, 121392023U, 704923114U, 950391366U, 428961804U, 382752275U, 469870224U};
constexpr unsigned FFT_RATIOS[FFT_MAX] = {911660635U, 509520358U, 369330050U, 332049552U, 983190778U, 123842337U, 238493703U, 975955924U, 603855026U, 856644456U, 131300601U, 842657263U, 730768835U, 942482514U, 806263778U, 151565301U, 510815449U, 503497456U, 743006876U, 741047443U, 56250497U, 867605899U};
constexpr unsigned INV_FFT_RATIOS[FFT_MAX] = {86583718U, 372528824U, 373294451U, 645684063U, 112220581U, 692852209U, 155456985U, 797128860U, 90816748U, 860285882U, 927414960U, 354738543U, 109331171U, 293255632U, 535113200U, 308540755U, 121186627U, 608385704U, 438932459U, 359477183U, 824071951U, 103369235U};

} // namespace noya2::internal

struct ntt998244353 {
    using mint = modint998244353;
    static constexpr unsigned MO = modint998244353::mod();
    static constexpr unsigned MO2 = MO * 2;
    static void ntt(mint *as, int n){
        int m = n;
        if (m >>= 1){
            for (int i = 0; i < m; i++){
                const unsigned x = as[i + m]._v;
                as[i + m]._v = as[i]._v + MO - x;
                as[i]._v += x;
            }
        }
        if (m >>= 1){
            mint prod = 1;
            for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)){
                for (int i = i0; i < i0 + m; i++){
                    const unsigned x = (prod * as[i + m])._v;
                    as[i + m]._v = as[i]._v + MO - x;
                    as[i]._v += x;
                }
                prod *= mint::raw(internal::FFT_RATIOS[__builtin_ctz(++h)]);
            }
        }
        for (; m; ){
            if (m >>= 1){
                mint prod = 1;
                for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)){
                    for (int i = i0; i < i0 + m; i++){
                        const unsigned x = (prod * as[i + m])._v;
                        as[i + m]._v = as[i]._v + MO - x;
                        as[i]._v += x;
                    }
                    prod *= mint::raw(internal::FFT_RATIOS[__builtin_ctz(++h)]);
                }
            }
            if (m >>= 1){
                mint prod = 1;
                for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)){
                    for (int i = i0; i < i0 + m; i++){
                        const unsigned x = (prod * as[i + m])._v;
                        as[i]._v = (as[i]._v >= MO2 ? as[i]._v - MO2 : as[i]._v);
                        as[i + m]._v = as[i]._v + MO - x;
                        as[i]._v += x;
                    }
                    prod *= mint::raw(internal::FFT_RATIOS[__builtin_ctz(++h)]);
                }
            }
        }
        for (int i = 0; i < n; i++){
            as[i]._v = (as[i]._v >= MO2 ? as[i]._v - MO2 : as[i]._v);
            as[i]._v = (as[i]._v >= MO ? as[i]._v - MO : as[i]._v);
        }
    }
    static void intt(mint *as, int n){
        int m = 1;
        if (m < (n >> 1)){
            mint prod = 1;
            for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)){
                for (int i = i0; i < i0 + m; i++){
                    const unsigned long long y = as[i]._v + MO - as[i + m]._v;
                    as[i]._v += as[i + m]._v;
                    as[i + m]._v = prod._v * y % MO;
                }
                prod *= mint::raw(internal::INV_FFT_RATIOS[__builtin_ctz(++h)]);
            }
            m <<= 1;
        }
        for (; m < (n >> 1); m <<= 1){
            mint prod = 1;
            for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)){
                for (int i = i0; i < i0 + (m >> 1); i++){
                    const unsigned long long y = as[i]._v + MO2 - as[i + m]._v;
                    as[i]._v += as[i + m]._v;
                    as[i]._v = (as[i]._v >= MO2 ? as[i]._v - MO2 : as[i]._v);
                    as[i + m]._v = prod._v * y % MO;
                }
                for (int i = i0 + (m >> 1); i < i0 + m; i++){
                    const unsigned long long y = as[i]._v + MO - as[i + m]._v;
                    as[i]._v += as[i + m]._v;
                    as[i + m]._v = prod._v * y % MO;
                }
                prod *= mint::raw(internal::INV_FFT_RATIOS[__builtin_ctz(++h)]);
            }
        }
        if (m < n){
            for (int i = 0; i < m; i++){
                const unsigned y = as[i]._v + MO2 - as[i + m]._v;
                as[i]._v += as[i + m]._v;
                as[i + m]._v = y;
            }
        }
        for (int i = 0; i < n; i++){
            as[i]._v = (as[i]._v >= MO2 ? as[i]._v - MO2 : as[i]._v);
            as[i]._v = (as[i]._v >= MO ? as[i]._v - MO : as[i]._v);
        }
    }
    static void ntt(std::vector<mint> &as){
        ntt(as.data(), as.size());
    }
    static void intt(std::vector<mint> &as){
        intt(as.data(), as.size());
    }
    static void intt_div(std::vector<mint> &as){
        intt(as);
        int n = as.size();
        const mint inv_n = mint::raw(n).inv();
        for (int i = 0; i < n; i++){
            as[i] *= inv_n;
        }
    }
    static std::vector<mint> multiply(std::vector<mint> as, std::vector<mint> bs){
        if (as.empty() || bs.empty()) return {};
        const int len = as.size() + bs.size() - 1u;
        if (std::min(as.size(), bs.size()) <= 40u){
            std::vector<mint> s(len);
            for (int i = 0; i < (int)(as.size()); i++){
                for (int j = 0; j < (int)(bs.size()); j++){
                    s[i + j] += as[i] * bs[j];
                }
            }
            return s;
        }
        int n = 1;
        for (; n < len; n <<= 1) {}
        if (as.size() == bs.size() && as == bs){
            as.resize(n);
            ntt(as);
            for (int i = 0; i < n; i++){
                as[i] *= as[i];
            }
        }
        else {
            as.resize(n);
            ntt(as);
            bs.resize(n);
            ntt(bs);
            for (int i = 0; i < n; i++){
                as[i] *= bs[i];
            }
        }
        intt_div(as);
        as.resize(len);
        return as;
    }
    static void ntt_doubling(std::vector<mint> &as){
        auto bs = as;
        intt(bs);
        mint e = mint::raw(internal::FFT_ROOTS[std::countr_zero(as.size()) + 1]);
        mint iv = mint::raw(as.size()).inv();
        for (auto &x : bs){
            x *= iv;
            iv *= e;
        }
        ntt(bs);
        as.insert(as.end(), bs.begin(), bs.end());
    }
    static void ntt_pick_parity(std::vector<mint> &f, int odd){
        int n = f.size() / 2;
        mint i2 = mint::raw((mint::mod() + 1) >> 1);
        if (odd == 0){
            for (int i = 0; i < n; i++){
                f[i] = (f[i * 2] + f[i * 2 + 1]) * i2;
            }
            f.resize(n);
            return ;
        }
        mint ie = mint::raw(internal::INV_FFT_ROOTS[std::countr_zero(f.size())]);
        std::vector<mint> es = {i2};
        while ((int)(es.size()) != n){
            std::vector<mint> nes(es.size() * 2u);
            for (int i = 0; i < (int)(es.size()); i++){
                nes[i * 2 + 0] = es[i];
                nes[i * 2 + 1] = es[i] * ie;
            }
            ie *= ie;
            std::swap(es, nes);
        }
        for (int i = 0; i < n; i++){
            f[i] = (f[i * 2] - f[i * 2 + 1]) * es[i];
        }
        f.resize(n);
    }
};

} // namespace noya2