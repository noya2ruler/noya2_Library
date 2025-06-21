---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
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
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_modint.hpp
    title: fps/fps_modint.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_ntt.hpp
    title: fps/fps_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/relaxed_convolution.hpp
    title: fps/relaxed_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/Convolution1000000007.test.cpp
    title: test/fps/Convolution1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Inv_of_Formal_Power_Series.test.cpp
    title: test/fps/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
    title: test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
    title: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/convolution.test.cpp
    title: test/fps/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/convolution_relaxed_convolution.test.cpp
    title: test/fps/convolution_relaxed_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/ntt.hpp\"\n\n#line 2 \"template/template.hpp\"\nusing\
    \ namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout_old.hpp\"\
    \nnamespace noya2 {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p){\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v){\n    int\
    \ s = (int)v.size();\n    for (int i = 0; i < s; i++) os << (i ? \" \" : \"\"\
    ) << v[i];\n    return os;\n}\ntemplate <typename T>\nistream &operator>>(istream\
    \ &is, vector<T> &v){\n    for (auto &x : v) is >> x;\n    return is;\n}\n\nvoid\
    \ in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...u){\n    cin\
    \ >> t;\n    in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...u){\n    cout\
    \ << t;\n    if (sizeof...(u)) cout << sep;\n    out(u...);\n}\n\ntemplate<typename\
    \ T>\nvoid out(const vector<vector<T>> &vv){\n    int s = (int)vv.size();\n  \
    \  for (int i = 0; i < s; i++) out(vv[i]);\n}\n\nstruct IoSetup {\n    IoSetup(){\n\
    \        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout\
    \ << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n \
    \   }\n} iosetup_noya2;\n\n} // namespace noya2\n#line 1 \"template/const.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"utility/modint.hpp\"\n\n#line\
    \ 4 \"utility/modint.hpp\"\n\n#line 2 \"math/prime.hpp\"\n\n#line 4 \"math/prime.hpp\"\
    \nnamespace noya2 {\n\nconstexpr long long safe_mod(long long x, long long m)\
    \ {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\nconstexpr long long\
    \ pow_mod_constexpr(long long x, long long n, int m) {\n    if (m == 1) return\
    \ 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned long long r = 1;\n\
    \    unsigned long long y = safe_mod(x, m);\n    while (n) {\n        if (n &\
    \ 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n \
    \   return r;\n}\n\nconstexpr bool is_prime_constexpr(int n) {\n    if (n <= 1)\
    \ return false;\n    if (n == 2 || n == 7 || n == 61) return true;\n    if (n\
    \ % 2 == 0) return false;\n    long long d = n - 1;\n    while (d % 2 == 0) d\
    \ /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for (long long a\
    \ : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime_flag = is_prime_constexpr(n);\n\nconstexpr\
    \ std::pair<long long, long long> inv_gcd(long long a, long long b) {\n    a =\
    \ safe_mod(a, b);\n    if (a == 0) return {b, 0};\n    long long s = b, t = a;\n\
    \    long long m0 = 0, m1 = 1;\n    while (t) {\n        long long u = s / t;\n\
    \        s -= t * u;\n        m0 -= m1 * u; \n        auto tmp = s;\n        s\
    \ = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n\
    \    }\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\nconstexpr int\
    \ primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m == 167772161)\
    \ return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721) return\
    \ 11;\n    if (m == 998244353) return 3;\n    int divs[20] = {};\n    divs[0]\
    \ = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /=\
    \ 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x % i\
    \ == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0) {\n  \
    \              x /= i;\n            }\n        }\n    }\n    if (x > 1) {\n  \
    \      divs[cnt++] = x;\n    }\n    for (int g = 2;; g++) {\n        bool ok =\
    \ true;\n        for (int i = 0; i < cnt; i++) {\n            if (pow_mod_constexpr(g,\
    \ (m - 1) / divs[i], m) == 1) {\n                ok = false;\n               \
    \ break;\n            }\n        }\n        if (ok) return g;\n    }\n}\ntemplate\
    \ <int m> constexpr int primitive_root_flag = primitive_root_constexpr(m);\n\n\
    } // namespace noya2\n#line 6 \"utility/modint.hpp\"\n\nnamespace noya2{\n\nstruct\
    \ barrett {\n    unsigned int _m;\n    unsigned long long im;\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n    unsigned int umod()\
    \ const { return _m; }\n    unsigned int mul(unsigned int a, unsigned int b) const\
    \ {\n        unsigned long long z = a;\n        z *= b;\n        unsigned long\
    \ long x = (unsigned long long)((__uint128_t(z) * im) >> 64);\n        unsigned\
    \ int v = (unsigned int)(z - x * _m);\n        if (_m <= v) v += _m;\n       \
    \ return v;\n    }\n};\n\ntemplate <int m>\nstruct static_modint {\n    using\
    \ mint = static_modint;\n  public:\n    static constexpr int mod() { return m;\
    \ }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n      \
    \  return x;\n    }\n    constexpr static_modint() : _v(0) {}\n    template<std::signed_integral\
    \ T>\n    constexpr static_modint(T v){\n        long long x = (long long)(v %\
    \ (long long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned\
    \ int)(x);\n    }\n    template<std::unsigned_integral T>\n    constexpr static_modint(T\
    \ v){\n        _v = (unsigned int)(v % umod());\n    }\n    constexpr unsigned\
    \ int val() const { return _v; }\n    mint& operator++() {\n        _v++;\n  \
    \      if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n    constexpr mint&\
    \ operator+=(const mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod())\
    \ _v -= umod();\n        return *this;\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n\
    \        return *this;\n    }\n    constexpr mint& operator*=(const mint& rhs)\
    \ {\n        unsigned long long z = _v;\n        z *= rhs._v;\n        _v = (unsigned\
    \ int)(z % umod());\n        return *this;\n    }\n    constexpr mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inv(); }\n    constexpr mint operator+()\
    \ const { return *this; }\n    constexpr mint operator-() const { return mint()\
    \ - *this; }\n    constexpr mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    constexpr mint inv() const {\n        if (prime) {\n \
    \           assert(_v);\n            return pow(umod() - 2);\n        } else {\n\
    \            auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n \
    \           return eg.second;\n        }\n    }\n    friend constexpr mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n   \
    \ friend constexpr mint operator-(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) -= rhs;\n    }\n    friend constexpr mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend constexpr mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend constexpr bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend constexpr bool operator!=(const mint& lhs, const mint& rhs) {\n     \
    \   return lhs._v != rhs._v;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint& p) {\n        return os << p.val();\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &a) {\n        long long t; is >> t;\n  \
    \      a = mint(t);\n        return (is);\n    }\n\n  private:\n    unsigned int\
    \ _v;\n    static constexpr unsigned int umod() { return m; }\n    static constexpr\
    \ bool prime = is_prime_flag<m>;\n};\n\n\ntemplate <int id> struct dynamic_modint\
    \ {\n    using mint = dynamic_modint;\n  public:\n    static int mod() { return\
    \ (int)(bt.umod()); }\n    static void set_mod(int m) {\n        assert(1 <= m);\n\
    \        bt = barrett(m);\n    }\n    static mint raw(int v) {\n        mint x;\n\
    \        x._v = v;\n        return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n\
    \    template<std::signed_integral T>\n    dynamic_modint(T v){\n        long\
    \ long x = (long long)(v % (long long)(umod()));\n        if (x < 0) x += umod();\n\
    \        _v = (unsigned int)(x);\n    }\n    template<std::unsigned_integral T>\n\
    \    dynamic_modint(T v){\n        _v = (unsigned int)(v % umod());\n    }\n \
    \   unsigned int val() const { return _v; }\n    mint& operator++() {\n      \
    \  _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n    }\n  \
    \  mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n  \
    \      return *this;\n    }\n    mint operator++(int) {\n        mint result =\
    \ *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n     \
    \   if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v >= umod()) _v -=\
    \ umod();\n        return *this;\n    }\n    mint& operator*=(const mint& rhs)\
    \ {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n    mint&\
    \ operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n    mint\
    \ operator+() const { return *this; }\n    mint operator-() const { return mint()\
    \ - *this; }\n    mint pow(long long n) const {\n        assert(0 <= n);\n   \
    \     mint x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *=\
    \ x;\n            x *= x;\n            n >>= 1;\n        }\n        return r;\n\
    \    }\n    mint inv() const {\n        auto eg = noya2::inv_gcd(_v, mod());\n\
    \        assert(eg.first == 1);\n        return eg.second;\n    }\n    friend\
    \ mint operator+(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static barrett\
    \ bt;\n    static unsigned int umod() { return bt.umod(); }\n};\ntemplate <int\
    \ id> noya2::barrett dynamic_modint<id>::bt(998244353);\n\nusing modint998244353\
    \ = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n\ntemplate<typename T>\nconcept Modint = requires\
    \ (T &a){\n    T::mod();\n    a.inv();\n    a.val();\n    a.pow(declval<int>());\n\
    };\n\n} // namespace noya2\n#line 5 \"fps/ntt.hpp\"\n\nnamespace noya2{\n\ntemplate<Modint\
    \ mint>\nstruct NTT {\n    static constexpr uint mod = mint::mod();\n    static\
    \ constexpr ull mod2 = (ull)mod * mod;\n    static constexpr uint pr  = primitive_root_constexpr(mod);\n\
    \    static constexpr int level = countr_zero(mod-1);\n    mint wp[level+1], wm[level+1];\n\
    \    void set_ws(){\n        mint r = mint(pr).pow((mod-1) >> level);\n      \
    \  wp[level] = r, wm[level] = r.inv();\n        for (int i = level-1; i >= 0;\
    \ i--){\n            wp[i] = wp[i+1] * wp[i+1];\n            wm[i] = wm[i+1] *\
    \ wm[i+1];\n        }\n    }\n    NTT () { set_ws(); }\n    void fft4(vector<mint>\
    \ &a, int k, int s = 0){\n        uint im = wm[2].val();\n        uint n = 1<<k;\n\
    \        uint len = n;\n        int l = k;\n        while (len > 1){\n       \
    \     if (l == 1){\n                for (int i = 0; i < (1<<(k-1)); i++){\n  \
    \                  int i0 = s + i*2, i1 = i0+1;\n                    a[i0] +=\
    \ a[i1];\n                    a[i1]  = a[i0] - a[i1] * 2;\n                }\n\
    \                len >>= 1;\n                l -= 1;\n            }\n        \
    \    else {\n                int len4 = len/4;\n                int nlen = n/len;\n\
    \                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;\n         \
    \       for (int i = 0; i < len4; i++){\n                    int offset = 0;\n\
    \                    for (int j = 0; j < nlen; j++){\n                       \
    \ int i0 = s + i + offset, i1 = i0 + len4, i2 = i1 + len4, i3 = i2 + len4;\n \
    \                       uint a0 = a[i0].val();\n                        uint a1\
    \ = a[i1].val();\n                        uint a2 = a[i2].val();\n           \
    \             uint a3 = a[i3].val();\n                        uint a0p2 = a0 +\
    \ a2;\n                        uint a1p3 = a1 + a3;\n                        ull\
    \ b0m2 = (a0 + mod - a2) * r1;\n                        ull b1m3 = (a1 + mod -\
    \ a3) * imr1;\n                        ull c0m2 = (a0 + mod - a2) * r3;\n    \
    \                    ull c1m3 = (a1 + mod - a3) * imr3;\n                    \
    \    a[i0] = a0p2 + a1p3;\n                        a[i1] = b0m2 + b1m3;\n    \
    \                    a[i2] = (a0p2 + mod*2 - a1p3) * r2;\n                   \
    \     a[i3] = c0m2 + mod2*2 - c1m3;\n                        offset += len;\n\
    \                    }\n                    r1 = r1 * wm[l].val() % mod;\n   \
    \                 r2 = r1 * r1 % mod;\n                    r3 = r1 * r2 % mod;\n\
    \                    imr1 = im * r1 % mod;\n                    imr3 = im * r3\
    \ % mod;\n                }\n                len >>= 2;\n                l -=\
    \ 2;\n            }\n        }\n    }\n    void ifft4(vector<mint> &a, int k,\
    \ int s = 0){\n        uint im = wp[2].val();\n        uint n = 1<<k;\n      \
    \  uint len = (k & 1 ? 2 : 4);\n        int l = (k & 1 ? 1 : 2);\n        while\
    \ (len <= n){\n            if (l == 1){\n                for (int i = 0; i < (1<<(k-1));\
    \ i++){\n                    int i0 = s + i*2, i1 = i0+1;\n                  \
    \  a[i0] += a[i1];\n                    a[i1]  = a[i0] - a[i1] * 2;\n        \
    \        }\n                len <<= 2;\n                l += 2;\n            }\n\
    \            else {\n                int len4 = len/4;\n                int nlen\
    \ = n/len;\n                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;\n\
    \                for (int i = 0; i < len4; i++){\n                    int offset\
    \ = 0;\n                    for (int j = 0; j < nlen; j++){\n                \
    \        int i0 = s + i + offset, i1 = i0 + len4, i2 = i1 + len4, i3 = i2 + len4;\n\
    \                        ull a0 = a[i0].val();\n                        ull a1\
    \ = a[i1].val() * r1;\n                        ull a2 = a[i2].val() * r2;\n  \
    \                      ull a3 = a[i3].val() * r3;\n                        ull\
    \ b1 = a[i1].val() * imr1;\n                        ull b3 = a[i3].val() * imr3;\n\
    \                        ull a0p2 = a0 + a2;\n                        ull a1p3\
    \ = a1 + a3;\n                        ull a0m2 = a0 + mod2 - a2;\n           \
    \             ull b1m3 = b1 + mod2 - b3;\n                        a[i0] = a0p2\
    \ + a1p3;\n                        a[i1] = a0m2 + b1m3;\n                    \
    \    a[i2] = a0p2 + mod2*2 - a1p3;\n                        a[i3] = a0m2 + mod2*2\
    \ - b1m3;\n                        offset += len;\n                    }\n   \
    \                 r1 = r1 * wp[l].val() % mod;\n                    r2 = r1 *\
    \ r1 % mod;\n                    r3 = r1 * r2 % mod;\n                    imr1\
    \ = im * r1 % mod;\n                    imr3 = im * r3 % mod;\n              \
    \  }\n                len <<= 2;\n                l += 2;\n            }\n   \
    \     }\n    }\n    void ntt(vector<mint> &a) {\n        if ((int)a.size() <=\
    \ 1) return;\n        assert(has_single_bit(a.size()));\n        fft4(a, countr_zero(a.size()));\n\
    \    }\n    void intt(vector<mint> &a, bool stop = false) {\n        if ((int)a.size()\
    \ <= 1) return;\n        assert(has_single_bit(a.size()));\n        ifft4(a, countr_zero(a.size()));\n\
    \        if (stop) return ;\n        mint iv = mint(a.size()).inv();\n       \
    \ for (auto &x : a) x *= iv;\n    }\n    vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n        int l = a.size() + b.size() - 1;\n   \
    \     if (min<int>(a.size(), b.size()) <= 40){\n            vector<mint> s(l);\n\
    \            for (int i = 0; i < (int)a.size(); i++) for (int j = 0; j < (int)b.size();\
    \ j++) s[i + j] += a[i] * b[j];\n            return s;\n        }\n        int\
    \ k = 2, M = 4;\n        while (M < l) M <<= 1, ++k;\n        set_ws();\n    \
    \    vector<mint> s(M);\n        for (int i = 0; i < (int)a.size(); ++i) s[i]\
    \ = a[i];\n        fft4(s, k);\n        if (a.size() == b.size() && a == b) {\n\
    \            for (int i = 0; i < M; ++i) s[i] *= s[i];\n        }\n        else\
    \ {\n            vector<mint> t(M);\n            for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = b[i];\n            fft4(t, k);\n            for (int i = 0; i <\
    \ M; ++i) s[i] *= t[i];\n        }\n        ifft4(s, k);\n        s.resize(l);\n\
    \        mint invm = mint(M).inv();\n        for (int i = 0; i < l; ++i) s[i]\
    \ *= invm;\n        return s;\n    }\n};\n\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../utility/modint.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<Modint mint>\nstruct NTT {\n    static constexpr\
    \ uint mod = mint::mod();\n    static constexpr ull mod2 = (ull)mod * mod;\n \
    \   static constexpr uint pr  = primitive_root_constexpr(mod);\n    static constexpr\
    \ int level = countr_zero(mod-1);\n    mint wp[level+1], wm[level+1];\n    void\
    \ set_ws(){\n        mint r = mint(pr).pow((mod-1) >> level);\n        wp[level]\
    \ = r, wm[level] = r.inv();\n        for (int i = level-1; i >= 0; i--){\n   \
    \         wp[i] = wp[i+1] * wp[i+1];\n            wm[i] = wm[i+1] * wm[i+1];\n\
    \        }\n    }\n    NTT () { set_ws(); }\n    void fft4(vector<mint> &a, int\
    \ k, int s = 0){\n        uint im = wm[2].val();\n        uint n = 1<<k;\n   \
    \     uint len = n;\n        int l = k;\n        while (len > 1){\n          \
    \  if (l == 1){\n                for (int i = 0; i < (1<<(k-1)); i++){\n     \
    \               int i0 = s + i*2, i1 = i0+1;\n                    a[i0] += a[i1];\n\
    \                    a[i1]  = a[i0] - a[i1] * 2;\n                }\n        \
    \        len >>= 1;\n                l -= 1;\n            }\n            else\
    \ {\n                int len4 = len/4;\n                int nlen = n/len;\n  \
    \              ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;\n           \
    \     for (int i = 0; i < len4; i++){\n                    int offset = 0;\n \
    \                   for (int j = 0; j < nlen; j++){\n                        int\
    \ i0 = s + i + offset, i1 = i0 + len4, i2 = i1 + len4, i3 = i2 + len4;\n     \
    \                   uint a0 = a[i0].val();\n                        uint a1 =\
    \ a[i1].val();\n                        uint a2 = a[i2].val();\n             \
    \           uint a3 = a[i3].val();\n                        uint a0p2 = a0 + a2;\n\
    \                        uint a1p3 = a1 + a3;\n                        ull b0m2\
    \ = (a0 + mod - a2) * r1;\n                        ull b1m3 = (a1 + mod - a3)\
    \ * imr1;\n                        ull c0m2 = (a0 + mod - a2) * r3;\n        \
    \                ull c1m3 = (a1 + mod - a3) * imr3;\n                        a[i0]\
    \ = a0p2 + a1p3;\n                        a[i1] = b0m2 + b1m3;\n             \
    \           a[i2] = (a0p2 + mod*2 - a1p3) * r2;\n                        a[i3]\
    \ = c0m2 + mod2*2 - c1m3;\n                        offset += len;\n          \
    \          }\n                    r1 = r1 * wm[l].val() % mod;\n             \
    \       r2 = r1 * r1 % mod;\n                    r3 = r1 * r2 % mod;\n       \
    \             imr1 = im * r1 % mod;\n                    imr3 = im * r3 % mod;\n\
    \                }\n                len >>= 2;\n                l -= 2;\n    \
    \        }\n        }\n    }\n    void ifft4(vector<mint> &a, int k, int s = 0){\n\
    \        uint im = wp[2].val();\n        uint n = 1<<k;\n        uint len = (k\
    \ & 1 ? 2 : 4);\n        int l = (k & 1 ? 1 : 2);\n        while (len <= n){\n\
    \            if (l == 1){\n                for (int i = 0; i < (1<<(k-1)); i++){\n\
    \                    int i0 = s + i*2, i1 = i0+1;\n                    a[i0] +=\
    \ a[i1];\n                    a[i1]  = a[i0] - a[i1] * 2;\n                }\n\
    \                len <<= 2;\n                l += 2;\n            }\n        \
    \    else {\n                int len4 = len/4;\n                int nlen = n/len;\n\
    \                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;\n         \
    \       for (int i = 0; i < len4; i++){\n                    int offset = 0;\n\
    \                    for (int j = 0; j < nlen; j++){\n                       \
    \ int i0 = s + i + offset, i1 = i0 + len4, i2 = i1 + len4, i3 = i2 + len4;\n \
    \                       ull a0 = a[i0].val();\n                        ull a1\
    \ = a[i1].val() * r1;\n                        ull a2 = a[i2].val() * r2;\n  \
    \                      ull a3 = a[i3].val() * r3;\n                        ull\
    \ b1 = a[i1].val() * imr1;\n                        ull b3 = a[i3].val() * imr3;\n\
    \                        ull a0p2 = a0 + a2;\n                        ull a1p3\
    \ = a1 + a3;\n                        ull a0m2 = a0 + mod2 - a2;\n           \
    \             ull b1m3 = b1 + mod2 - b3;\n                        a[i0] = a0p2\
    \ + a1p3;\n                        a[i1] = a0m2 + b1m3;\n                    \
    \    a[i2] = a0p2 + mod2*2 - a1p3;\n                        a[i3] = a0m2 + mod2*2\
    \ - b1m3;\n                        offset += len;\n                    }\n   \
    \                 r1 = r1 * wp[l].val() % mod;\n                    r2 = r1 *\
    \ r1 % mod;\n                    r3 = r1 * r2 % mod;\n                    imr1\
    \ = im * r1 % mod;\n                    imr3 = im * r3 % mod;\n              \
    \  }\n                len <<= 2;\n                l += 2;\n            }\n   \
    \     }\n    }\n    void ntt(vector<mint> &a) {\n        if ((int)a.size() <=\
    \ 1) return;\n        assert(has_single_bit(a.size()));\n        fft4(a, countr_zero(a.size()));\n\
    \    }\n    void intt(vector<mint> &a, bool stop = false) {\n        if ((int)a.size()\
    \ <= 1) return;\n        assert(has_single_bit(a.size()));\n        ifft4(a, countr_zero(a.size()));\n\
    \        if (stop) return ;\n        mint iv = mint(a.size()).inv();\n       \
    \ for (auto &x : a) x *= iv;\n    }\n    vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n        int l = a.size() + b.size() - 1;\n   \
    \     if (min<int>(a.size(), b.size()) <= 40){\n            vector<mint> s(l);\n\
    \            for (int i = 0; i < (int)a.size(); i++) for (int j = 0; j < (int)b.size();\
    \ j++) s[i + j] += a[i] * b[j];\n            return s;\n        }\n        int\
    \ k = 2, M = 4;\n        while (M < l) M <<= 1, ++k;\n        set_ws();\n    \
    \    vector<mint> s(M);\n        for (int i = 0; i < (int)a.size(); ++i) s[i]\
    \ = a[i];\n        fft4(s, k);\n        if (a.size() == b.size() && a == b) {\n\
    \            for (int i = 0; i < M; ++i) s[i] *= s[i];\n        }\n        else\
    \ {\n            vector<mint> t(M);\n            for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = b[i];\n            fft4(t, k);\n            for (int i = 0; i <\
    \ M; ++i) s[i] *= t[i];\n        }\n        ifft4(s, k);\n        s.resize(l);\n\
    \        mint invm = mint(M).inv();\n        for (int i = 0; i < l; ++i) s[i]\
    \ *= invm;\n        return s;\n    }\n};\n\n\n} // namespace noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - utility/modint.hpp
  - math/prime.hpp
  isVerificationFile: false
  path: fps/ntt.hpp
  requiredBy:
  - fps/relaxed_convolution.hpp
  - fps/fps_modint.hpp
  - fps/fps_ntt.hpp
  timestamp: '2025-02-26 00:46:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/convolution.test.cpp
  - test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
  - test/fps/Inv_of_Formal_Power_Series.test.cpp
  - test/fps/Convolution1000000007.test.cpp
  - test/fps/convolution_relaxed_convolution.test.cpp
  - test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
documentation_of: fps/ntt.hpp
layout: document
redirect_from:
- /library/fps/ntt.hpp
- /library/fps/ntt.hpp.html
title: fps/ntt.hpp
---
