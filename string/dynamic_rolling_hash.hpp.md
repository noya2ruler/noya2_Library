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
  bundledCode: "#line 2 \"string/dynamic_rolling_hash.hpp\"\n\n#include <vector>\n\
    #include <string>\n#include <random>\n#include <cassert>\n\nnamespace noya2 {\n\
    \nstruct dynamic_rolling_hash {\n    dynamic_rolling_hash (const std::string &s\
    \ = \"\"){\n        build(s);\n    }\n    unsigned long long get(int l, int r){\n\
    \        assert(0 <= l && l <= r && r <= n);\n        return cal_mod(prefix_sum(r)\
    \ + POSITIVISER - mul_mod(prefix_sum(l), pow_base[r - l]));\n    }\n    void update(int\
    \ p, char nexc){\n        assert(0 <= p && p < n);\n        long long d = nexc\
    \ - str[p];\n        if (d < 0) d += MOD;\n        change(p, d);\n        str[p]\
    \ = nexc;\n    }\n    static unsigned long long get_hash(const std::string &s){\n\
    \        int len = s.size();\n        set_base();\n        extend_pow_base(len);\n\
    \        unsigned long long res = 0;\n        for (int i = 0; i < len; i++){\n\
    \            res = cal_mod(mul_mod(res, BASE) + s[i]);\n        }\n        return\
    \ res;\n    }\n  private:\n    static constexpr unsigned long long MASK30 = (1ULL\
    \ << 30) - 1;\n    static constexpr unsigned long long MASK31 = (1ULL << 31) -\
    \ 1;\n    static constexpr unsigned long long MASK61 = (1ULL << 61) - 1;\n   \
    \ static constexpr unsigned long long MOD = (1ULL << 61) - 1;\n    static constexpr\
    \ unsigned long long POSITIVISER = MOD * 4;\n    static inline unsigned long long\
    \ BASE = 0;\n    static inline std::vector<unsigned long long> pow_base = std::vector<unsigned\
    \ long long>(1,1ULL);\n    static unsigned long long mul_mod(unsigned long long\
    \ a, unsigned long long b){\n        unsigned long long au = a >> 31, ad = a &\
    \ MASK31;\n        unsigned long long bu = b >> 31, bd = b & MASK31;\n       \
    \ unsigned long long mid = ad * bu + au * bd;\n        unsigned long long midu\
    \ = mid >> 30, midd = mid & MASK30;\n        return (au * bu * 2 + midu + (midd\
    \ << 31) + ad * bd);\n    }\n    static unsigned long long cal_mod(unsigned long\
    \ long x){\n        unsigned long long xu = x >> 61;\n        unsigned long long\
    \ xd = x & MASK61;\n        unsigned long long res = xu + xd;\n        if (res\
    \ >= MOD) res -= MOD;\n        return res;\n    }\n    static void set_base(){\n\
    \        if (BASE == 0){\n            BASE = (1ULL << 31) + (std::random_device()()\
    \ & MASK31);\n        }\n    }\n    static void extend_pow_base(int len){\n  \
    \      int nlen = pow_base.size();\n        if (nlen > len) return ;\n       \
    \ pow_base.resize(len+1);\n        for (int i = nlen; i <= len; i++){\n      \
    \      pow_base[i] = cal_mod(mul_mod(pow_base[i-1], BASE));\n        }\n    }\n\
    \    void change(int p, unsigned long long add){\n        p++;\n        while\
    \ (p <= n){\n            inner_hash[p - 1] = cal_mod(inner_hash[p - 1] + add);\n\
    \            add = cal_mod(mul_mod(add, pow_base[p & -p]));\n            p +=\
    \ p & -p;\n        }\n    }\n    unsigned long long prefix_sum(int r){\n     \
    \   int tr = r;\n        unsigned long long s = 0;\n        while (r > 0){\n \
    \           s = cal_mod(mul_mod(inner_hash[r - 1], pow_base[tr - r]) + s);\n \
    \           r -= r & -r;\n        }\n        return s;\n    }\n    int n;\n  \
    \  std::string str;\n    std::vector<unsigned long long> inner_hash;\n    void\
    \ build(const std::string &s){\n        set_base();\n        str = s;\n      \
    \  n = s.size();\n        extend_pow_base(n);\n        inner_hash.resize(n, 0);\n\
    \        for (int i = 0; i < n; i++){\n            change(i, (unsigned long long)(s[i]));\n\
    \        }\n    }\n};\n\nusing droriha = dynamic_rolling_hash;\n\n} // namespace\
    \ noya2\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n#include <random>\n\
    #include <cassert>\n\nnamespace noya2 {\n\nstruct dynamic_rolling_hash {\n   \
    \ dynamic_rolling_hash (const std::string &s = \"\"){\n        build(s);\n   \
    \ }\n    unsigned long long get(int l, int r){\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        return cal_mod(prefix_sum(r) + POSITIVISER - mul_mod(prefix_sum(l),\
    \ pow_base[r - l]));\n    }\n    void update(int p, char nexc){\n        assert(0\
    \ <= p && p < n);\n        long long d = nexc - str[p];\n        if (d < 0) d\
    \ += MOD;\n        change(p, d);\n        str[p] = nexc;\n    }\n    static unsigned\
    \ long long get_hash(const std::string &s){\n        int len = s.size();\n   \
    \     set_base();\n        extend_pow_base(len);\n        unsigned long long res\
    \ = 0;\n        for (int i = 0; i < len; i++){\n            res = cal_mod(mul_mod(res,\
    \ BASE) + s[i]);\n        }\n        return res;\n    }\n  private:\n    static\
    \ constexpr unsigned long long MASK30 = (1ULL << 30) - 1;\n    static constexpr\
    \ unsigned long long MASK31 = (1ULL << 31) - 1;\n    static constexpr unsigned\
    \ long long MASK61 = (1ULL << 61) - 1;\n    static constexpr unsigned long long\
    \ MOD = (1ULL << 61) - 1;\n    static constexpr unsigned long long POSITIVISER\
    \ = MOD * 4;\n    static inline unsigned long long BASE = 0;\n    static inline\
    \ std::vector<unsigned long long> pow_base = std::vector<unsigned long long>(1,1ULL);\n\
    \    static unsigned long long mul_mod(unsigned long long a, unsigned long long\
    \ b){\n        unsigned long long au = a >> 31, ad = a & MASK31;\n        unsigned\
    \ long long bu = b >> 31, bd = b & MASK31;\n        unsigned long long mid = ad\
    \ * bu + au * bd;\n        unsigned long long midu = mid >> 30, midd = mid & MASK30;\n\
    \        return (au * bu * 2 + midu + (midd << 31) + ad * bd);\n    }\n    static\
    \ unsigned long long cal_mod(unsigned long long x){\n        unsigned long long\
    \ xu = x >> 61;\n        unsigned long long xd = x & MASK61;\n        unsigned\
    \ long long res = xu + xd;\n        if (res >= MOD) res -= MOD;\n        return\
    \ res;\n    }\n    static void set_base(){\n        if (BASE == 0){\n        \
    \    BASE = (1ULL << 31) + (std::random_device()() & MASK31);\n        }\n   \
    \ }\n    static void extend_pow_base(int len){\n        int nlen = pow_base.size();\n\
    \        if (nlen > len) return ;\n        pow_base.resize(len+1);\n        for\
    \ (int i = nlen; i <= len; i++){\n            pow_base[i] = cal_mod(mul_mod(pow_base[i-1],\
    \ BASE));\n        }\n    }\n    void change(int p, unsigned long long add){\n\
    \        p++;\n        while (p <= n){\n            inner_hash[p - 1] = cal_mod(inner_hash[p\
    \ - 1] + add);\n            add = cal_mod(mul_mod(add, pow_base[p & -p]));\n \
    \           p += p & -p;\n        }\n    }\n    unsigned long long prefix_sum(int\
    \ r){\n        int tr = r;\n        unsigned long long s = 0;\n        while (r\
    \ > 0){\n            s = cal_mod(mul_mod(inner_hash[r - 1], pow_base[tr - r])\
    \ + s);\n            r -= r & -r;\n        }\n        return s;\n    }\n    int\
    \ n;\n    std::string str;\n    std::vector<unsigned long long> inner_hash;\n\
    \    void build(const std::string &s){\n        set_base();\n        str = s;\n\
    \        n = s.size();\n        extend_pow_base(n);\n        inner_hash.resize(n,\
    \ 0);\n        for (int i = 0; i < n; i++){\n            change(i, (unsigned long\
    \ long)(s[i]));\n        }\n    }\n};\n\nusing droriha = dynamic_rolling_hash;\n\
    \n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: string/dynamic_rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-05-29 13:23:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/dynamic_rolling_hash.hpp
layout: document
redirect_from:
- /library/string/dynamic_rolling_hash.hpp
- /library/string/dynamic_rolling_hash.hpp.html
title: string/dynamic_rolling_hash.hpp
---
