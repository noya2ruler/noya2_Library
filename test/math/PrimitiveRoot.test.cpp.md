---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_64bit.hpp
    title: math/prime_64bit.hpp
  - icon: ':heavy_check_mark:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout_old.hpp
    title: template/inout_old.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utils.hpp
    title: template/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primitive_root
    links:
    - https://judge.yosupo.jp/problem/primitive_root
  bundledCode: "#line 1 \"test/math/PrimitiveRoot.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\
    \n\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
    #line 1 \"template/inout_old.hpp\"\nnamespace noya2 {\n\ntemplate <typename T,\
    \ typename U>\nostream &operator<<(ostream &os, const pair<T, U> &p){\n    os\
    \ << p.first << \" \" << p.second;\n    return os;\n}\ntemplate <typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &p){\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ const vector<T> &v){\n    int s = (int)v.size();\n    for (int i = 0; i < s;\
    \ i++) os << (i ? \" \" : \"\") << v[i];\n    return os;\n}\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (auto &x : v) is\
    \ >> x;\n    return is;\n}\n\nvoid in() {}\ntemplate <typename T, class... U>\n\
    void in(T &t, U &...u){\n    cin >> t;\n    in(u...);\n}\n\nvoid out() { cout\
    \ << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\nvoid out(const\
    \ T &t, const U &...u){\n    cout << t;\n    if (sizeof...(u)) cout << sep;\n\
    \    out(u...);\n}\n\ntemplate<typename T>\nvoid out(const vector<vector<T>> &vv){\n\
    \    int s = (int)vv.size();\n    for (int i = 0; i < s; i++) out(vv[i]);\n}\n\
    \nstruct IoSetup {\n    IoSetup(){\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n\
    \    }\n} iosetup_noya2;\n\n} // namespace noya2\n#line 1 \"template/const.hpp\"\
    \nnamespace noya2{\n\nconst int iinf = 1'000'000'007;\nconst long long linf =\
    \ 2'000'000'000'000'000'000LL;\nconst long long mod998 =  998244353;\nconst long\
    \ long mod107 = 1000000007;\nconst long double pi = 3.14159265358979323;\nconst\
    \ vector<int> dx = {0,1,0,-1,1,1,-1,-1};\nconst vector<int> dy = {1,0,-1,0,1,-1,-1,1};\n\
    const string ALP = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\nconst string alp = \"abcdefghijklmnopqrstuvwxyz\"\
    ;\nconst string NUM = \"0123456789\";\n\nvoid yes(){ cout << \"Yes\\n\"; }\nvoid\
    \ no(){ cout << \"No\\n\"; }\nvoid YES(){ cout << \"YES\\n\"; }\nvoid NO(){ cout\
    \ << \"NO\\n\"; }\nvoid yn(bool t){ t ? yes() : no(); }\nvoid YN(bool t){ t ?\
    \ YES() : NO(); }\n\n} // namespace noya2\n#line 2 \"template/utils.hpp\"\n\n\
    #line 6 \"template/utils.hpp\"\n\nnamespace noya2{\n\nunsigned long long inner_binary_gcd(unsigned\
    \ long long a, unsigned long long b){\n    if (a == 0 || b == 0) return a + b;\n\
    \    int n = __builtin_ctzll(a); a >>= n;\n    int m = __builtin_ctzll(b); b >>=\
    \ m;\n    while (a != b) {\n        int mm = __builtin_ctzll(a - b);\n       \
    \ bool f = a > b;\n        unsigned long long c = f ? a : b;\n        b = f ?\
    \ b : a;\n        a = (c - b) >> mm;\n    }\n    return a << std::min(n, m);\n\
    }\n\ntemplate<typename T> T gcd_fast(T a, T b){ return static_cast<T>(inner_binary_gcd(std::abs(a),std::abs(b)));\
    \ }\n\nlong long sqrt_fast(long long n) {\n    if (n <= 0) return 0;\n    long\
    \ long x = sqrt(n);\n    while ((x + 1) * (x + 1) <= n) x++;\n    while (x * x\
    \ > n) x--;\n    return x;\n}\n\ntemplate<typename T> T floor_div(const T n, const\
    \ T d) {\n    assert(d != 0);\n    return n / d - static_cast<T>((n ^ d) < 0 &&\
    \ n % d != 0);\n}\n\ntemplate<typename T> T ceil_div(const T n, const T d) {\n\
    \    assert(d != 0);\n    return n / d + static_cast<T>((n ^ d) >= 0 && n % d\
    \ != 0);\n}\n\ntemplate<typename T> void uniq(std::vector<T> &v){\n    std::sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n}\n\ntemplate <typename T, typename\
    \ U> inline bool chmin(T &x, U y) { return (y < x) ? (x = y, true) : false; }\n\
    \ntemplate <typename T, typename U> inline bool chmax(T &x, U y) { return (x <\
    \ y) ? (x = y, true) : false; }\n\ntemplate<typename T> inline bool range(T l,\
    \ T x, T r){ return l <= x && x < r; }\n\n} // namespace noya2\n#line 8 \"template/template.hpp\"\
    \n\n#define rep(i,n) for (int i = 0; i < (int)(n); i++)\n#define repp(i,m,n) for\
    \ (int i = (m); i < (int)(n); i++)\n#define reb(i,n) for (int i = (int)(n-1);\
    \ i >= 0; i--)\n#define all(v) (v).begin(),(v).end()\n\nusing ll = long long;\n\
    using ld = long double;\nusing uint = unsigned int;\nusing ull = unsigned long\
    \ long;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pil = pair<int,ll>;\n\
    using pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000~ (. _________ . /)\u3000\
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"math/prime_64bit.hpp\"\n\n#include\
    \ <type_traits>\n#line 2 \"math/factorize.hpp\"\n\n#line 6 \"math/factorize.hpp\"\
    \n#include <initializer_list>\n#line 10 \"math/factorize.hpp\"\n\nnamespace fast_factorize\
    \ {\n\n/*\n    See : https://judge.yosupo.jp/submission/189742\n*/\n\n// ----\
    \ gcd ----\n\nuint64_t gcd_stein_impl( uint64_t x, uint64_t y ) {\n    if( x ==\
    \ y ) { return x; }\n    const uint64_t a = y - x;\n    const uint64_t b = x -\
    \ y;\n    const int n = __builtin_ctzll( b );\n    const uint64_t s = x < y ?\
    \ a : b;\n    const uint64_t t = x < y ? x : y;\n    return gcd_stein_impl( s\
    \ >> n, t );\n}\n\nuint64_t gcd_stein( uint64_t x, uint64_t y ) {\n    if( x ==\
    \ 0 ) { return y; }\n    if( y == 0 ) { return x; }\n    const int n = __builtin_ctzll(\
    \ x );\n    const int m = __builtin_ctzll( y );\n    return gcd_stein_impl( x\
    \ >> n, y >> m ) << ( n < m ? n : m );\n}\n\n// ---- is_prime ----\n\nuint64_t\
    \ mod_pow( uint64_t x, uint64_t y, uint64_t mod ) {\n    uint64_t ret = 1;\n \
    \   uint64_t acc = x;\n    for( ; y; y >>= 1 ) {\n        if( y & 1 ) {\n    \
    \        ret = __uint128_t(ret) * acc % mod;\n        }\n        acc = __uint128_t(acc)\
    \ * acc % mod;\n    }\n    return ret;\n}\n\nbool miller_rabin( uint64_t n, const\
    \ std::initializer_list<uint64_t>& as ) {\n    return std::all_of( as.begin(),\
    \ as.end(), [n]( uint64_t a ) {\n        if( n <= a ) { return true; }\n\n   \
    \     int e = __builtin_ctzll( n - 1 );\n        uint64_t z = mod_pow( a, ( n\
    \ - 1 ) >> e, n );\n        if( z == 1 || z == n - 1 ) { return true; }\n\n  \
    \      while( --e ) {\n            z = __uint128_t(z) * z % n;\n            if(\
    \ z == 1 ) { return false; }\n            if( z == n - 1 ) { return true; }\n\
    \        }\n\n        return false;\n    });\n}\n\nbool is_prime( uint64_t n )\
    \ {\n    if( n == 2 ) { return true; }\n    if( n % 2 == 0 ) { return false; }\n\
    \    if( n < 4759123141 ) { return miller_rabin( n, { 2, 7, 61 } ); }\n    return\
    \ miller_rabin( n, { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 } );\n}\n\
    \n// ---- Montgomery ----\n\nclass Montgomery {\n    uint64_t mod;\n    uint64_t\
    \ R;\npublic:\n    Montgomery( uint64_t n ) : mod(n), R(n) {\n       for( size_t\
    \ i = 0; i < 5; ++i ) {\n          R *= 2 - mod * R;\n       }\n    }\n\n    uint64_t\
    \ fma( uint64_t a, uint64_t b, uint64_t c ) const {\n        const __uint128_t\
    \ d = __uint128_t(a) * b;\n        const uint64_t    e = c + mod + ( d >> 64 );\n\
    \        const uint64_t    f = uint64_t(d) * R;\n        const uint64_t    g =\
    \ ( __uint128_t(f) * mod ) >> 64;\n        return e - g;\n    }\n\n    uint64_t\
    \ mul( uint64_t a, uint64_t b ) const {\n        return fma( a, b, 0 );\n    }\n\
    };\n\n// ---- Pollard's rho algorithm ----\n\nuint64_t pollard_rho( uint64_t n\
    \ ) {\n    if( n % 2 == 0 ) { return 2; }\n    const Montgomery m( n );\n\n  \
    \  constexpr uint64_t C1 = 1;\n    constexpr uint64_t C2 = 2;\n    constexpr uint64_t\
    \ M = 512;\n\n    uint64_t Z1 = 1;\n    uint64_t Z2 = 2;\nretry:\n    uint64_t\
    \ z1 = Z1;\n    uint64_t z2 = Z2;\n    for( size_t k = M; ; k *= 2 ) {\n     \
    \   const uint64_t x1 = z1 + n;\n        const uint64_t x2 = z2 + n;\n       \
    \ for( size_t j = 0; j < k; j += M ) {\n            const uint64_t y1 = z1;\n\
    \            const uint64_t y2 = z2;\n\n            uint64_t q1 = 1;\n       \
    \     uint64_t q2 = 2;\n            z1 = m.fma( z1, z1, C1 );\n            z2\
    \ = m.fma( z2, z2, C2 );\n            for( size_t i = 0; i < M; ++i ) {\n    \
    \            const uint64_t t1 = x1 - z1;\n                const uint64_t t2 =\
    \ x2 - z2;\n                z1 = m.fma( z1, z1, C1 );\n                z2 = m.fma(\
    \ z2, z2, C2 );\n                q1 = m.mul( q1, t1 );\n                q2 = m.mul(\
    \ q2, t2 );\n            }\n            q1 = m.mul( q1, x1 - z1 );\n         \
    \   q2 = m.mul( q2, x2 - z2 );\n\n            const uint64_t q3 = m.mul( q1, q2\
    \ );\n            const uint64_t g3 = gcd_stein( n, q3 );\n            if( g3\
    \ == 1 ) { continue; }\n            if( g3 != n ) { return g3; }\n\n         \
    \   const uint64_t g1 = gcd_stein( n, q1 );\n            const uint64_t g2 = gcd_stein(\
    \ n, q2 );\n\n            const uint64_t C = g1 != 1 ? C1 : C2;\n            const\
    \ uint64_t x = g1 != 1 ? x1 : x2;\n            uint64_t       z = g1 != 1 ? y1\
    \ : y2;\n            uint64_t       g = g1 != 1 ? g1 : g2;\n\n            if(\
    \ g == n ) {\n                do {\n                    z = m.fma( z, z, C );\n\
    \                    g = gcd_stein( n, x - z );\n                } while( g ==\
    \ 1 );\n            }\n            if( g != n ) {\n                return g;\n\
    \            }\n\n            Z1 += 2;\n            Z2 += 2;\n            goto\
    \ retry;\n        }\n    }\n}\n\nvoid factorize_impl( uint64_t n, std::vector<uint64_t>&\
    \ ret ) {\n    if( n <= 1 ) { return; }\n    if( is_prime( n ) ) { ret.push_back(\
    \ n ); return; }\n\n    const uint64_t p = pollard_rho( n );\n\n    factorize_impl(\
    \ p, ret );\n    factorize_impl( n / p, ret );\n}\n\nstd::vector<uint64_t> factorize(\
    \ uint64_t n ) {\n    std::vector<uint64_t> ret;\n    factorize_impl( n, ret );\n\
    \    std::sort( ret.begin(), ret.end() );\n    return ret;\n}\n\n} // namespace\
    \ fast_factorize\n\nnamespace noya2 {\n\nstd::vector<std::pair<long long, int>>\
    \ factorize(long long n){\n    std::vector<std::pair<long long, int>> ans;\n \
    \   auto ps = fast_factorize::factorize(n);\n    int sz = ps.size();\n    for\
    \ (int l = 0, r = 0; l < sz; l = r){\n        while (r < sz && ps[l] == ps[r])\
    \ r++;\n        ans.emplace_back(ps[l], r-l);\n    }\n    return ans;\n}\n\nstd::vector<long\
    \ long> divisors(long long n){\n    auto ps = fast_factorize::factorize(n);\n\
    \    int sz = ps.size();\n    std::vector<long long> ans = {1};\n    for (int\
    \ l = 0, r = 0; l < sz; l = r){\n        while (r < sz && ps[l] == ps[r]) r++;\n\
    \        int e = r - l;\n        int len = ans.size();\n        ans.reserve(len*(e+1));\n\
    \        long long mul = ps[l];\n        while (true){\n            for (int i\
    \ = 0; i < len; i++){\n                ans.emplace_back(ans[i]*mul);\n       \
    \     }\n            if (--e == 0) break;\n            mul *= ps[l];\n       \
    \ }\n    }\n    return ans;\n}\n\nstd::vector<long long> divisors(const std::vector<std::pair<long\
    \ long, int>> &pes){\n    std::vector<long long> ans = {1};\n    for (auto [p,\
    \ e] : pes){\n        int len = ans.size();\n        ans.reserve(len*(e+1));\n\
    \        long long mul = p;\n        while (true){\n            for (int i = 0;\
    \ i < len; i++){\n                ans.emplace_back(ans[i]*mul);\n            }\n\
    \            if (--e == 0) break;\n            mul *= p;\n        }\n    }\n \
    \   return ans;\n}\n\n} // namespace noya2\n#line 7 \"math/prime_64bit.hpp\"\n\
    \nnamespace noya2::internal64bit {\n\ntemplate<typename T>\nconstexpr T safe_mod(T\
    \ a, T p){\n    a %= p;\n    if constexpr (std::is_signed_v<T> || std::is_same_v<T,\
    \ __int128_t>){\n        if (a < 0) a += p;\n    }\n    return a;\n}\n\ntemplate<typename\
    \ T, typename U>\nconstexpr T pow_mod_constexpr(T x, U n, T p){\n    if (p ==\
    \ 1) return 0;\n    x = safe_mod(x, p);\n    T ret = 1;\n    while (n != 0){\n\
    \        if (n % 2 == 1){\n            ret = U(ret) * x % p;\n        }\n    \
    \    x = U(x) * x % p;\n        n /= 2;\n    }\n    return ret;\n}\n\n// return\
    \ {g, y}\n//   g = gcd(x, p), y * x == 1 (mod p/g)\ntemplate<typename T>\nconstexpr\
    \ std::pair<T, T> inv_gcd(T x, T p){\n    x = safe_mod(x, p);\n    if (x == 0)\
    \ return {p, 0};\n    T s = p, t = x;\n    T m0 = 0, m1 = 1;\n    while (t !=\
    \ 0){\n        T q = s / t;\n        s -= t * q;\n        m0 -= m1 * q;\n    \
    \    std::swap(s, t);\n        std::swap(m0, m1);\n    }\n    if (m0 < 0) m0 +=\
    \ p / s;\n    return {s, m0};\n}\n\n// p must be prime\nlong long primitive_root_ll(long\
    \ long p){\n    if (p == 2) return 1;\n    auto fs = fast_factorize::factorize(p\
    \ - 1);\n    fs.erase(std::unique(fs.begin(), fs.end()), fs.end());\n    for (long\
    \ long g = 2; ; g++){\n        bool ok = true;\n        for (auto &f : fs){\n\
    \            if (pow_mod_constexpr<long long, __int128_t>(g, (p - 1) / f, p) ==\
    \ 1){\n                ok = false;\n                break;\n            }\n  \
    \      }\n        if (ok) return g;\n    }\n    exit(1);\n}\n\n} // namespace\
    \ noya2\n#line 5 \"test/math/PrimitiveRoot.test.cpp\"\n\nvoid solve(){\n    ll\
    \ p; in(p);\n    out(internal64bit::primitive_root_ll(p));\n}\n\nint main(){\n\
    \    int q; in(q);\n    while (q--){\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\n\n#include\"\
    ../../template/template.hpp\"\n#include\"../../math/prime_64bit.hpp\"\n\nvoid\
    \ solve(){\n    ll p; in(p);\n    out(internal64bit::primitive_root_ll(p));\n\
    }\n\nint main(){\n    int q; in(q);\n    while (q--){\n        solve();\n    }\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - math/prime_64bit.hpp
  - math/factorize.hpp
  isVerificationFile: true
  path: test/math/PrimitiveRoot.test.cpp
  requiredBy: []
  timestamp: '2024-07-03 00:54:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/PrimitiveRoot.test.cpp
layout: document
redirect_from:
- /verify/test/math/PrimitiveRoot.test.cpp
- /verify/test/math/PrimitiveRoot.test.cpp.html
title: test/math/PrimitiveRoot.test.cpp
---
