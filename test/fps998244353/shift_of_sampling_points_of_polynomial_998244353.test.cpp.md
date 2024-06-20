---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/ntt.hpp
    title: fps/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/fps998244353.hpp
    title: fps998244353/fps998244353.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/sample_point_shift.hpp
    title: fps998244353/sample_point_shift.hpp
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: math/binomial.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial
    links:
    - https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial
  bundledCode: "#line 1 \"test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial\"\
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
    \ YES() : NO(); }\n\n} // namespace noya2\n#line 1 \"template/utils.hpp\"\nnamespace\
    \ noya2{\n\nunsigned long long inner_binary_gcd(unsigned long long a, unsigned\
    \ long long b){\n    if (a == 0 || b == 0) return a + b;\n    int n = __builtin_ctzll(a);\
    \ a >>= n;\n    int m = __builtin_ctzll(b); b >>= m;\n    while (a != b) {\n \
    \       int mm = __builtin_ctzll(a - b);\n        bool f = a > b;\n        unsigned\
    \ long long c = f ? a : b;\n        b = f ? b : a;\n        a = (c - b) >> mm;\n\
    \    }\n    return a << min(n, m);\n}\n\ntemplate<typename T> T gcd_fast(T a,\
    \ T b){ return static_cast<T>(inner_binary_gcd(abs(a),abs(b))); }\n\nlong long\
    \ sqrt_fast(long long n) {\n    if (n <= 0) return 0;\n    long long x = sqrt(n);\n\
    \    while ((x + 1) * (x + 1) <= n) x++;\n    while (x * x > n) x--;\n    return\
    \ x;\n}\n\ntemplate<typename T> T floor_div(const T n, const T d) {\n    assert(d\
    \ != 0);\n    return n / d - static_cast<T>((n ^ d) < 0 && n % d != 0);\n}\n\n\
    template<typename T> T ceil_div(const T n, const T d) {\n    assert(d != 0);\n\
    \    return n / d + static_cast<T>((n ^ d) >= 0 && n % d != 0);\n}\n\ntemplate<typename\
    \ T> void uniq(vector<T> &v){\n    sort(v.begin(),v.end());\n    v.erase(unique(v.begin(),v.end()),v.end());\n\
    }\n\ntemplate <typename T, typename U> inline bool chmin(T &x, U y) { return (y\
    \ < x) ? (x = y, true) : false; }\n\ntemplate <typename T, typename U> inline\
    \ bool chmax(T &x, U y) { return (x < y) ? (x = y, true) : false; }\n\ntemplate<typename\
    \ T> inline bool range(T l, T x, T r){ return l <= x && x < r; }\n\n} // namespace\
    \ noya2\n#line 8 \"template/template.hpp\"\n\n#define rep(i,n) for (int i = 0;\
    \ i < (int)(n); i++)\n#define repp(i,m,n) for (int i = (m); i < (int)(n); i++)\n\
    #define reb(i,n) for (int i = (int)(n-1); i >= 0; i--)\n#define all(v) (v).begin(),(v).end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\n\
    using ull = unsigned long long;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\n\
    using pil = pair<int,ll>;\nusing pli = pair<ll,int>;\n\nnamespace noya2{\n\n/*\u3000\
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"fps998244353/sample_point_shift.hpp\"\
    \n\n#line 2 \"fps998244353/fps998244353.hpp\"\n\n#line 2 \"utility/modint.hpp\"\
    \n\n#line 2 \"math/prime.hpp\"\n\n#line 4 \"math/prime.hpp\"\nnamespace noya2\
    \ {\n\nconstexpr long long safe_mod(long long x, long long m) {\n    x %= m;\n\
    \    if (x < 0) x += m;\n    return x;\n}\n\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\nconstexpr\
    \ bool is_prime_constexpr(int n) {\n    if (n <= 1) return false;\n    if (n ==\
    \ 2 || n == 7 || n == 61) return true;\n    if (n % 2 == 0) return false;\n  \
    \  long long d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    constexpr long long\
    \ bases[3] = {2, 7, 61};\n    for (long long a : bases) {\n        long long t\
    \ = d;\n        long long y = pow_mod_constexpr(a, t, n);\n        while (t !=\
    \ n - 1 && y != 1 && y != n - 1) {\n            y = y * y % n;\n            t\
    \ <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\ntemplate <int n> constexpr bool\
    \ is_prime_flag = is_prime_constexpr(n);\n\nconstexpr std::pair<long long, long\
    \ long> inv_gcd(long long a, long long b) {\n    a = safe_mod(a, b);\n    if (a\
    \ == 0) return {b, 0};\n    long long s = b, t = a;\n    long long m0 = 0, m1\
    \ = 1;\n    while (t) {\n        long long u = s / t;\n        s -= t * u;\n \
    \       m0 -= m1 * u; \n        auto tmp = s;\n        s = t;\n        t = tmp;\n\
    \        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0)\
    \ m0 += b / s;\n    return {s, m0};\n}\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int\
    \ x = (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long\
    \ long)(i)*i <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++]\
    \ = i;\n            while (x % i == 0) {\n                x /= i;\n          \
    \  }\n        }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n  \
    \  for (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i\
    \ < cnt; i++) {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) ==\
    \ 1) {\n                ok = false;\n                break;\n            }\n \
    \       }\n        if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int\
    \ primitive_root_flag = primitive_root_constexpr(m);\n\n} // namespace noya2\n\
    #line 4 \"utility/modint.hpp\"\n\nnamespace noya2{\n\nstruct barrett {\n    unsigned\
    \ int _m;\n    unsigned long long im;\n    explicit barrett(unsigned int m) :\
    \ _m(m), im((unsigned long long)(-1) / m + 1) {}\n    unsigned int umod() const\
    \ { return _m; }\n    unsigned int mul(unsigned int a, unsigned int b) const {\n\
    \        unsigned long long z = a;\n        z *= b;\n        unsigned long long\
    \ x = (unsigned long long)((__uint128_t(z) * im) >> 64);\n        unsigned int\
    \ v = (unsigned int)(z - x * _m);\n        if (_m <= v) v += _m;\n        return\
    \ v;\n    }\n};\n\ntemplate <int m>\nstruct static_modint {\n    using mint =\
    \ static_modint;\n  public:\n    static constexpr int mod() { return m; }\n  \
    \  static mint raw(int v) {\n        mint x;\n        x._v = v;\n        return\
    \ x;\n    }\n    constexpr static_modint() : _v(0) {}\n    template<signed_integral\
    \ T>\n    constexpr static_modint(T v){\n        long long x = (long long)(v %\
    \ (long long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned\
    \ int)(x);\n    }\n    template<unsigned_integral T>\n    constexpr static_modint(T\
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
    \ {\n        ull z = _v;\n        z *= rhs._v;\n        _v = (uint)(z % umod());\n\
    \        return *this;\n    }\n    constexpr mint& operator/=(const mint& rhs)\
    \ { return *this = *this * rhs.inv(); }\n    constexpr mint operator+() const\
    \ { return *this; }\n    constexpr mint operator-() const { return mint() - *this;\
    \ }\n    constexpr mint pow(ll n) const {\n        assert(0 <= n);\n        mint\
    \ x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n   \
    \         x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n\
    \    constexpr mint inv() const {\n        if (prime) {\n            assert(_v);\n\
    \            return pow(umod() - 2);\n        } else {\n            auto eg =\
    \ inv_gcd(_v, m);\n            assert(eg.first == 1);\n            return eg.second;\n\
    \        }\n    }\n    friend constexpr mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend constexpr\
    \ mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend constexpr mint operator*(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) *= rhs;\n    }\n    friend constexpr mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend constexpr bool operator==(const mint& lhs, const mint& rhs) {\n     \
    \   return lhs._v == rhs._v;\n    }\n    friend constexpr bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr\
    \ unsigned int umod() { return m; }\n    static constexpr bool prime = is_prime_flag<m>;\n\
    };\n\n\ntemplate <int id> struct dynamic_modint {\n    using mint = dynamic_modint;\n\
    \  public:\n    static int mod() { return (int)(bt.umod()); }\n    static void\
    \ set_mod(int m) {\n        assert(1 <= m);\n        bt = barrett(m);\n    }\n\
    \    static mint raw(int v) {\n        mint x;\n        x._v = v;\n        return\
    \ x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template<signed_integral T>\n\
    \    dynamic_modint(T v){\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template<unsigned_integral T>\n    dynamic_modint(T v){\n        _v = (unsigned\
    \ int)(v % umod());\n    }\n    uint val() const { return _v; }\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
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
    };\n\n} // namespace noya2\n#line 4 \"fps998244353/fps998244353.hpp\"\n\n#line\
    \ 2 \"fps/ntt.hpp\"\n\n#line 5 \"fps/ntt.hpp\"\n\nnamespace noya2{\n\ntemplate<Modint\
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
    \ *= invm;\n        return s;\n    }\n};\n\n\n} // namespace noya2\n#line 2 \"\
    math/binomial.hpp\"\n\n#line 4 \"math/binomial.hpp\"\nnamespace noya2 {\n\ntemplate<typename\
    \ mint>\nstruct binomial {\n    binomial(int len = 300000){ extend(len); }\n \
    \   static mint fact(int n){\n        if (n < 0) return 0;\n        while (n >=\
    \ (int)_fact.size()) extend();\n        return _fact[n];\n    }\n    static mint\
    \ ifact(int n){\n        if (n < 0) return 0;\n        while (n >= (int)_fact.size())\
    \ extend();\n        return _ifact[n];\n    }\n    static mint inv(int n){\n \
    \       return ifact(n) * fact(n-1);\n    }\n    static mint C(int n, int r){\n\
    \        if (!(0 <= r && r <= n)) return 0;\n        return fact(n) * ifact(r)\
    \ * ifact(n-r);\n    }\n    static mint P(int n, int r){\n        if (!(0 <= r\
    \ && r <= n)) return 0;\n        return fact(n) * ifact(n-r);\n    }\n    inline\
    \ mint operator()(int n, int r) { return C(n, r); }\n    template<class... Cnts>\
    \ static mint M(const Cnts&... cnts){\n        return multinomial(0,1,cnts...);\n\
    \    }\n  private:\n    static mint multinomial(const int& sum, const mint& div_prod){\n\
    \        if (sum < 0) return 0;\n        return fact(sum) * div_prod;\n    }\n\
    \    template<class... Tail> static mint multinomial(const int& sum, const mint&\
    \ div_prod, const int& n1, const Tail&... tail){\n        if (n1 < 0) return 0;\n\
    \        return multinomial(sum+n1,div_prod*ifact(n1),tail...);\n    }\n    static\
    \ vector<mint> _fact, _ifact;\n    static void extend(int len = -1){\n       \
    \ if (_fact.empty()){\n            _fact = _ifact = {1,1};\n        }\n      \
    \  int siz = _fact.size();\n        if (len == -1) len = siz * 2;\n        len\
    \ = min<int>(len, mint::mod()-1);\n        if (len < siz) return ;\n        _fact.resize(len+1),\
    \ _ifact.resize(len+1);\n        for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1]\
    \ * i;\n        _ifact[len] = _fact[len].inv();\n        for (int i = len; i >\
    \ siz; i--) _ifact[i-1] = _ifact[i] * i;\n    }\n};\ntemplate<typename T>\nstd::vector<T>binomial<T>::_fact\
    \ = vector<T>(2,T(1));\ntemplate<typename T>\nstd::vector<T>binomial<T>::_ifact\
    \ = vector<T>(2,T(1));\n\n} // namespace noya2\n#line 7 \"fps998244353/fps998244353.hpp\"\
    \n\nnamespace noya2 {\n\n// Formal Power Series for modint998244353\nstruct fps998244353\
    \ : std::vector<modint998244353> {\n    using mint = modint998244353;\n    using\
    \ std::vector<mint>::vector;\n    using std::vector<mint>::operator=;\n    using\
    \ fps = fps998244353;\n    static inline NTT<mint> ntt_;\n    static inline binomial<mint>\
    \ bnm;\n\n    fps998244353 (const std::vector<mint> &init){\n        (*this) =\
    \ init;\n    }\n\n    void shrink(){\n        while(!(this->empty()) && this->back().val()\
    \ == 0){\n            this->pop_back();\n        }\n    }\n\n    fps &operator*=\
    \ (const mint &r){\n        for (auto &x : *this) x *= r;\n        return *this;\n\
    \    }\n    fps &operator/= (const mint &r){\n        (*this) *= r.inv();\n  \
    \      return *this;\n    }\n\n    fps &operator<<= (const int &d){\n        this->insert(this->begin(),\
    \ d, mint(0));\n        return *this;\n    }\n    fps &operator>>= (const int\
    \ &d){\n        if ((int)(this->size()) <= d) this->clear();\n        else this->erase(this->begin(),this->begin()\
    \ + d);\n        return *this;\n    }\n\n    fps &operator+= (const fps &r){\n\
    \        if (this->size() < r.size()) this->resize(r.size());\n        for (int\
    \ i = 0; auto x : r){\n            (*this)[i++] += x;\n        }\n        return\
    \ *this;\n    }\n    fps &operator-= (const fps &r){\n        if (this->size()\
    \ < r.size()) this->resize(r.size());\n        for (int i = 0; auto x : r){\n\
    \            (*this)[i++] -= x;\n        }\n        return *this;\n    }\n   \
    \ fps &operator*= (const fps &r){\n        if (this->empty() || r.empty()){\n\
    \            this->clear();\n            return *this;\n        }\n        (*this)\
    \ = ntt_.multiply(*this, r);\n        return *this;\n    }\n\n    fps operator*\
    \ (const mint &r) const { return fps(*this) *= r; }\n    fps operator/ (const\
    \ mint &r) const { return fps(*this) /= r; }\n    fps operator<< (const int &d)\
    \ const { return fps(*this) <<= d; }\n    fps operator>> (const int &d) const\
    \ { return fps(*this) >>= d; }\n\n    fps operator+ (const fps &r) const { return\
    \ fps(*this) += r; }\n    fps operator- (const fps &r) const { return fps(*this)\
    \ -= r; }\n    fps operator* (const fps &r) const { return fps(*this) *= r; }\n\
    \n    fps operator+ () const { return *this; }\n    fps operator- () const {\n\
    \        fps ret(*this);\n        for (auto &x : ret) x = -x;\n        return\
    \ ret;\n    }\n\n    mint eval(const mint &x) const {\n        mint res(0), w(1);\n\
    \        for (auto a : *this){\n            res += a * w;\n            w *= x;\n\
    \        }\n        return res;\n    }\n\n    [[nodiscard(\"Do not change but\
    \ return changed object.\")]]\n    fps pre(std::size_t sz) const {\n        fps\
    \ ret(this->begin(), this->begin() + std::min(this->size(), sz));\n        if\
    \ (ret.size() < sz) ret.resize(sz);\n        return ret;\n    }\n    [[nodiscard(\"\
    Do not change but return changed object.\")]]\n    fps rev() const {\n       \
    \ fps ret(*this);\n        std::reverse(ret.begin(), ret.end());\n        return\
    \ ret;\n    }\n    [[nodiscard(\"Do not change but return changed object.\")]]\n\
    \    fps diff() const {\n        if (this->empty()){\n            return fps();\n\
    \        }\n        fps ret(this->begin() + 1, this->end());\n        for (int\
    \ i = 1; auto &x : ret){\n            x *= i++;\n        }\n        return ret;\n\
    \    }\n    [[nodiscard(\"Do not change but return changed object.\")]]\n    fps\
    \ integral() const {\n        if (this->empty()){\n            return fps();\n\
    \        }\n        fps ret(1, mint(0));\n        ret.insert(ret.end(), this->begin(),\
    \ this->end());\n        for (int i = 0; auto &x : ret){\n            x *= bnm.inv(i++);\
    \ // inv(0) = 0\n        }\n        return ret;\n    }\n    [[nodiscard(\"Do not\
    \ change but return changed object.\")]]\n    fps inv(int d = -1) const {\n  \
    \      const int n = this->size();\n        if (d == -1) d = n;\n        fps res\
    \ = {(*this)[0].inv()};\n        for (int siz = 1; siz < d; siz <<= 1){\n    \
    \        fps f(this->begin(),this->begin()+min(n,siz*2)), g(res);\n          \
    \  f.resize(siz*2), g.resize(siz*2);\n            f.ntt(), g.ntt();\n        \
    \    for (int i = 0; i < siz*2; i++) f[i] *= g[i];\n            ntt_.intt(f,true);\n\
    \            f.erase(f.begin(),f.begin()+siz);\n            f.resize(siz*2);\n\
    \            f.ntt();\n            for (int i = 0; i < siz*2; i++) f[i] *= g[i];\n\
    \            f.intt(true);\n            mint siz2_inv = mint(siz*2).inv(); siz2_inv\
    \ *= -siz2_inv;\n            for (int i = 0; i < siz; i++) f[i] *= siz2_inv;\n\
    \            res.insert(res.end(),f.begin(),f.begin()+siz);\n        }\n     \
    \   res.resize(d);\n        return res;\n    }\n    [[nodiscard(\"Do not change\
    \ but return changed object.\")]]\n    fps log(int d = -1) const {\n        assert(this->empty()\
    \ == false && (*this)[0].val() == 1u);\n        if (d == -1) d = this->size();\n\
    \        return (this->diff() * this->inv(d)).pre(d - 1).integral();\n    }\n\
    \    [[nodiscard(\"Do not change but return changed object.\")]]\n    fps exp(int\
    \ d = -1) const {\n        const int n = this->size();\n        if (d == -1) d\
    \ = n;\n        assert(n == 0 || (*this)[0].val() == 0u);\n        if (n <= 1){\n\
    \            fps ret(1,1);\n            ret.resize(d);\n            return ret;\n\
    \        }\n        // n >= 2\n        fps f = {mint(1), (*this)[1]}, ret = f;\n\
    \        for (int sz = 2; sz < d; sz <<= 1){\n            f.insert(f.end(), this->begin()+std::min(n,sz),\
    \ this->begin()+std::min(n,sz*2));\n            f.resize(sz*2);\n            ret\
    \ *= f - ret.log(sz*2);\n            ret.resize(sz*2);\n        }\n        ret.resize(d);\n\
    \        return ret;\n    }\n    [[nodiscard(\"Do not change but return changed\
    \ object.\")]]\n    fps pow(long long k, int d = -1) const {\n        const int\
    \ n = this->size();\n        if (d == -1) d = n;\n        if (k == 0){\n     \
    \       fps ret(d, mint(0));\n            if (d >= 1) ret[0] = 1;\n          \
    \  return ret;\n        }\n        // Find left-most nonzero term.\n        for\
    \ (int i = 0; i < n; i++){\n            if ((*this)[i].val() != 0u){\n       \
    \         mint iv = (*this)[i].inv();\n                fps ret = ((((*this) *\
    \ iv) >> i).log(d) * mint(k)).exp(d);\n                ret *= (*this)[i].pow(k);\n\
    \                ret = (ret << (i * k)).pre(d);\n                return ret;\n\
    \            }\n            if ((i + 1) * k >= d) break;\n        }\n        return\
    \ fps(d, mint(0));\n    }\n\n    void ntt(){\n        return ntt_.ntt(*this);\n\
    \    }\n    // already /= len\n    void intt(bool stop = false){\n        return\
    \ ntt_.intt(*this, stop);\n    }\n    fps quotient(fps r) const {\n        r.shrink();\n\
    \        const int n = this->size(), m = r.size();\n        if (n < m){\n    \
    \        return fps();\n        }\n        fps quo(*this);\n        const int\
    \ sz = n - m + 1;\n        std::reverse(quo.begin(), quo.end());\n        std::reverse(r.begin(),\
    \ r.end());\n        quo.resize(sz);\n        quo *= r.inv(sz);\n        quo.resize(sz);\n\
    \        std::reverse(quo.begin(), quo.end());\n        return quo;\n    }\n \
    \   fps remainder(fps r) const {\n        r.shrink();\n        const int n = this->size(),\
    \ m = r.size();\n        if (n < m){\n            return fps(*this);\n       \
    \ }\n        fps rem(*this);\n        rem -= quotient(r) * r;\n        rem.resize(m-1);\n\
    \        rem.shrink();\n        return rem;\n    }\n    std::pair<fps,fps> remquo(fps\
    \ r) const {\n        r.shrink();\n        fps quo = quotient(r);\n        fps\
    \ rem(*this);\n        rem -= quo * r;\n        rem.shrink();\n        return\
    \ {rem, quo};\n    }\n};\n\n} // namespace noya2\n#line 4 \"fps998244353/sample_point_shift.hpp\"\
    \n\nnamespace noya2 {\n\nstd::vector<modint998244353> sample_point_shift(fps998244353\
    \ y, modint998244353 t, int m){\n    long long T = t.val();\n    int k = (int)(y.size())\
    \ - 1;\n    if (T <= k){\n        std::vector<modint998244353> ret(m);\n     \
    \   int ptr = 0;\n        for (long long i = T; i <= k && ptr < m; i++){\n   \
    \         ret[ptr++] = y[i];\n        }\n        if (k+1 < T+m){\n           \
    \ auto suf = sample_point_shift(y,k+1,m-ptr);\n            for (int i = k+1; i\
    \ < T+m; i++){\n                ret[ptr++] = suf[i-(k+1)];\n            }\n  \
    \      }\n        return ret;\n    }\n    if (T+m > modint998244353::mod()){\n\
    \        auto pref = sample_point_shift(y,T,modint998244353::mod()-T);\n     \
    \   auto suf  = sample_point_shift(y,0,m-(int)(pref.size()));\n        copy(suf.begin(),suf.end(),back_inserter(pref));\n\
    \        return pref;\n    }\n    binomial<modint998244353> bnm;\n    fps998244353\
    \ d(k+1);\n    for (int i = 0; i <= k; i++){\n        d[i] = bnm.ifact(i) * bnm.ifact(k-i)\
    \ * y[i];\n        if ((k-i)&1) d[i] = -d[i];\n    }\n    std::vector<modint998244353>\
    \ fact(m+k+1); fact[0] = 1;\n    for (int i = 0; i < m+k; i++) fact[i+1] = fact[i]\
    \ * (T-k+i);\n    fps998244353 h(m+k); h[m+k-1] = fact[m+k].inv();\n    for (int\
    \ i = m+k-1; i >= 1; i--) h[i-1] = h[i] * (T-k+i);\n    for (int i = 0; i < m+k;\
    \ i++) h[i] *= fact[i];\n    auto dh = d * h;\n    std::vector<modint998244353>\
    \ ret(m);\n    modint998244353 cur = T;\n    for (int i = 1; i <= k; i++) cur\
    \ *= T-i;\n    for (int i = 0; i < m; i++){\n        ret[i] = cur * dh[k+i];\n\
    \        cur *= T+i+1;\n        cur *= h[i];\n    }\n    return ret;\n}\n\n} //\
    \ namespace noya2\n#line 5 \"test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp\"\
    \n\nint main(){\n    int n, m, c; in(n,m,c);\n    fps998244353 f(n); in(f);\n\
    \    out(sample_point_shift(f,c,m));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../fps998244353/sample_point_shift.hpp\"\
    \n\nint main(){\n    int n, m, c; in(n,m,c);\n    fps998244353 f(n); in(f);\n\
    \    out(sample_point_shift(f,c,m));\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - fps998244353/sample_point_shift.hpp
  - fps998244353/fps998244353.hpp
  - utility/modint.hpp
  - math/prime.hpp
  - fps/ntt.hpp
  - math/binomial.hpp
  isVerificationFile: true
  path: test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
  requiredBy: []
  timestamp: '2024-06-20 19:16:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
layout: document
redirect_from:
- /verify/test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
- /verify/test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp.html
title: test/fps998244353/shift_of_sampling_points_of_polynomial_998244353.test.cpp
---
