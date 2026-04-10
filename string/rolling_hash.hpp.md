---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n\n#include<vector>\n#include<string>\n\
    #include<cassert>\n#include<ranges>\n#include<random>\n\nnamespace noya2 {\nstruct\
    \ rolling_hash {\n    using ull = unsigned long long;\n    rolling_hash(){}\n\
    \    rolling_hash(const std::string &s){\n        build(s | std::ranges::to<std::vector<char>>());\n\
    \    }\n    template<typename T>\n    rolling_hash(const std::vector<T> &s){\n\
    \        build(s);\n    }\n    static ull get_hash(const std::string &s){\n  \
    \      int len = s.size();\n        set_hash();\n        extend_pow_base(len);\n\
    \        ull res = 0;\n        for (int i = 0; i < len; i++){\n            res\
    \ = cal_mod(mul_mod(res, BASE) + s[i]);\n        }\n        return res;\n    }\n\
    \    template<typename T>\n    static ull get_hash(const std::vector<T> &s){\n\
    \        int len = s.size();\n        set_hash();\n        extend_pow_base(len);\n\
    \        ull res = 0;\n        for (int i = 0; i < len; i++){\n            res\
    \ = cal_mod(mul_mod(res, BASE) + s[i]);\n        }\n        return res;\n    }\n\
    \    ull prod(int l, int r){ \n        return cal_mod(inner_hash[r] + POSITIVISER\
    \ - mul_mod(inner_hash[l], pow_base[r - l]));\n    }\n    size_t size() const\
    \ { return inner_hash.size() - 1u; }\n    template<class... Hash_Lengths>\n  \
    \  static ull concat(const Hash_Lengths&... hash_length){\n        return inner_concat(0ULL,\
    \ hash_length...);\n    }\n  private:\n    static ull inner_concat(const ull&\
    \ temp){\n        return temp;\n    }\n    template<class... Tail> static ull\
    \ inner_concat(const ull& temp, const ull& hash, const int& len, const Tail&...\
    \ tail){\n        return inner_concat(cal_mod(cal_mod(mul_mod(temp, pow_base[len]))\
    \ + hash), tail...);\n    }\n    static constexpr ull MASK30 = (1ULL << 30) -\
    \ 1;\n    static constexpr ull MASK31 = (1ULL << 31) - 1;\n    static constexpr\
    \ ull MASK61 = (1ULL << 61) - 1;\n    static constexpr ull MOD = (1ULL << 61)\
    \ - 1;\n    static constexpr ull POSITIVISER = MOD * 4;\n    static ull BASE;\n\
    \    static std::vector<ull> pow_base;\n    static ull mul_mod(ull a, ull b){\n\
    \        ull au = a >> 31, ad = a & MASK31;\n        ull bu = b >> 31, bd = b\
    \ & MASK31;\n        ull mid = ad * bu + au * bd;\n        ull midu = mid >> 30,\
    \ midd = mid & MASK30;\n        return (au * bu * 2 + midu + (midd << 31) + ad\
    \ * bd);\n    }\n    static ull cal_mod(ull x){\n        ull xu = x >> 61;\n \
    \       ull xd = x & MASK61;\n        ull res = xu + xd;\n        if (res >= MOD)\
    \ res -= MOD;\n        return res;\n    }\n    static void set_hash(){\n     \
    \   if (BASE == 0) BASE = (1UL << 31) + (std::random_device()() & MASK31);\n \
    \   }\n    static void extend_pow_base(int len){\n        int nlen = pow_base.size();\n\
    \        if (nlen > len) return ;\n        pow_base.resize(len + 1);\n       \
    \ for (int i = nlen; i <= len; i++){\n            pow_base[i] = cal_mod(mul_mod(pow_base[i\
    \ - 1],BASE));\n        }\n    }\n    std::vector<ull> inner_hash;\n    template<typename\
    \ T>\n    void build(const std::vector<T> &s){\n        set_hash();\n        int\
    \ n = s.size();\n        inner_hash.resize(n + 1);\n        inner_hash[0] = 0;\n\
    \        for (int i = 0; i < n; i++){\n            inner_hash[i + 1] = cal_mod(mul_mod(inner_hash[i],\
    \ BASE) + s[i]);\n        }\n    }\n};\nunsigned long long rolling_hash::BASE\
    \ = 0;\nstd::vector<unsigned long long> rolling_hash::pow_base = {1};\nusing roriha\
    \ = rolling_hash;\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<vector>\n#include<string>\n#include<cassert>\n#include<ranges>\n\
    #include<random>\n\nnamespace noya2 {\nstruct rolling_hash {\n    using ull =\
    \ unsigned long long;\n    rolling_hash(){}\n    rolling_hash(const std::string\
    \ &s){\n        build(s | std::ranges::to<std::vector<char>>());\n    }\n    template<typename\
    \ T>\n    rolling_hash(const std::vector<T> &s){\n        build(s);\n    }\n \
    \   static ull get_hash(const std::string &s){\n        int len = s.size();\n\
    \        set_hash();\n        extend_pow_base(len);\n        ull res = 0;\n  \
    \      for (int i = 0; i < len; i++){\n            res = cal_mod(mul_mod(res,\
    \ BASE) + s[i]);\n        }\n        return res;\n    }\n    template<typename\
    \ T>\n    static ull get_hash(const std::vector<T> &s){\n        int len = s.size();\n\
    \        set_hash();\n        extend_pow_base(len);\n        ull res = 0;\n  \
    \      for (int i = 0; i < len; i++){\n            res = cal_mod(mul_mod(res,\
    \ BASE) + s[i]);\n        }\n        return res;\n    }\n    ull prod(int l, int\
    \ r){ \n        return cal_mod(inner_hash[r] + POSITIVISER - mul_mod(inner_hash[l],\
    \ pow_base[r - l]));\n    }\n    size_t size() const { return inner_hash.size()\
    \ - 1u; }\n    template<class... Hash_Lengths>\n    static ull concat(const Hash_Lengths&...\
    \ hash_length){\n        return inner_concat(0ULL, hash_length...);\n    }\n \
    \ private:\n    static ull inner_concat(const ull& temp){\n        return temp;\n\
    \    }\n    template<class... Tail> static ull inner_concat(const ull& temp, const\
    \ ull& hash, const int& len, const Tail&... tail){\n        return inner_concat(cal_mod(cal_mod(mul_mod(temp,\
    \ pow_base[len])) + hash), tail...);\n    }\n    static constexpr ull MASK30 =\
    \ (1ULL << 30) - 1;\n    static constexpr ull MASK31 = (1ULL << 31) - 1;\n   \
    \ static constexpr ull MASK61 = (1ULL << 61) - 1;\n    static constexpr ull MOD\
    \ = (1ULL << 61) - 1;\n    static constexpr ull POSITIVISER = MOD * 4;\n    static\
    \ ull BASE;\n    static std::vector<ull> pow_base;\n    static ull mul_mod(ull\
    \ a, ull b){\n        ull au = a >> 31, ad = a & MASK31;\n        ull bu = b >>\
    \ 31, bd = b & MASK31;\n        ull mid = ad * bu + au * bd;\n        ull midu\
    \ = mid >> 30, midd = mid & MASK30;\n        return (au * bu * 2 + midu + (midd\
    \ << 31) + ad * bd);\n    }\n    static ull cal_mod(ull x){\n        ull xu =\
    \ x >> 61;\n        ull xd = x & MASK61;\n        ull res = xu + xd;\n       \
    \ if (res >= MOD) res -= MOD;\n        return res;\n    }\n    static void set_hash(){\n\
    \        if (BASE == 0) BASE = (1UL << 31) + (std::random_device()() & MASK31);\n\
    \    }\n    static void extend_pow_base(int len){\n        int nlen = pow_base.size();\n\
    \        if (nlen > len) return ;\n        pow_base.resize(len + 1);\n       \
    \ for (int i = nlen; i <= len; i++){\n            pow_base[i] = cal_mod(mul_mod(pow_base[i\
    \ - 1],BASE));\n        }\n    }\n    std::vector<ull> inner_hash;\n    template<typename\
    \ T>\n    void build(const std::vector<T> &s){\n        set_hash();\n        int\
    \ n = s.size();\n        inner_hash.resize(n + 1);\n        inner_hash[0] = 0;\n\
    \        for (int i = 0; i < n; i++){\n            inner_hash[i + 1] = cal_mod(mul_mod(inner_hash[i],\
    \ BASE) + s[i]);\n        }\n    }\n};\nunsigned long long rolling_hash::BASE\
    \ = 0;\nstd::vector<unsigned long long> rolling_hash::pow_base = {1};\nusing roriha\
    \ = rolling_hash;\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2026-04-10 20:49:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
