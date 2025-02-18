---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function.hpp
    title: math/multiplicative_function.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_multiplicative_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_multiplicative_function
  bundledCode: "#line 1 \"test/math/SumofMultiplicativeFunction.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_multiplicative_function\"\n\
    \n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
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
    \ {\n        unsigned long long z = _v;\n        z *= rhs._v;\n        _v = (uint)(z\
    \ % umod());\n        return *this;\n    }\n    constexpr mint& operator/=(const\
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
    \   uint val() const { return _v; }\n    mint& operator++() {\n        _v++;\n\
    \        if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v += mod() - rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint& rhs) {\n        _v = bt.mul(_v,\
    \ rhs._v);\n        return *this;\n    }\n    mint& operator/=(const mint& rhs)\
    \ { return *this = *this * rhs.inv(); }\n    mint operator+() const { return *this;\
    \ }\n    mint operator-() const { return mint() - *this; }\n    mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n \
    \       while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n   \
    \         n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ {\n        auto eg = noya2::inv_gcd(_v, mod());\n        assert(eg.first ==\
    \ 1);\n        return eg.second;\n    }\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend\
    \ mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend bool operator==(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ == rhs._v;\n    }\n    friend bool operator!=(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v != rhs._v;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint& p) {\n        return os << p.val();\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &a) {\n        long long t; is >> t;\n  \
    \      a = mint(t);\n        return (is);\n    }\n\n  private:\n    unsigned int\
    \ _v;\n    static barrett bt;\n    static unsigned int umod() { return bt.umod();\
    \ }\n};\ntemplate <int id> noya2::barrett dynamic_modint<id>::bt(998244353);\n\
    \nusing modint998244353 = static_modint<998244353>;\nusing modint1000000007 =\
    \ static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\ntemplate<typename\
    \ T>\nconcept Modint = requires (T &a){\n    T::mod();\n    a.inv();\n    a.val();\n\
    \    a.pow(declval<int>());\n};\n\n} // namespace noya2\n#line 5 \"test/math/SumofMultiplicativeFunction.test.cpp\"\
    \nusing mint = static_modint<469762049>;\nusing ar = array<mint,2>;\nar &operator+=(ar\
    \ &a, ar b){\n    a[0] += b[0];\n    a[1] += b[1];\n    return a;\n}\nar &operator-=(ar\
    \ &a, ar b){\n    a[0] -= b[0];\n    a[1] -= b[1];\n    return a;\n}\nar operator-(ar\
    \ a, ar b){\n    return a -= b;\n}\n\n#line 2 \"math/multiplicative_function.hpp\"\
    \n\n#line 6 \"math/multiplicative_function.hpp\"\n\nnamespace noya2 {\n\nstd::vector<int>\
    \ prime_enumerate(int N){\n    std::vector<bool> psieve(N / 3 + 1, true);\n  \
    \  int qe = psieve.size();\n    for (int p = 5, d = 4, i = 1, sqn = std::sqrt(N);\
    \ p <= sqn; p += d = 6 - d, i++){\n        if (!psieve[i]) continue;\n       \
    \ for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p; q < qe;\
    \ q += r = s - r){\n            psieve[q] = false;\n        }\n    }\n    std::vector<int>\
    \ ret = {2, 3};\n    for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++){\n\
    \        if (psieve[i]) ret.emplace_back(p);\n    }\n    while (!ret.empty() &&\
    \ ret.back() > N) ret.pop_back();\n    return ret;\n}\n\nstruct mf_prefix_sum\
    \ {\n    long long M, sq, s;\n    std::vector<int> p;\n    int ps;\n    mf_prefix_sum\
    \ () {}\n    mf_prefix_sum(long long m) : M(m) {\n        assert(m <= 1e15);\n\
    \        sq = std::sqrt(M);\n        while (sq * sq > M) sq--;\n        while\
    \ ((sq + 1) * (sq + 1) <= M) sq++;\n        if (m != 0){\n            long long\
    \ hls = quo(M, sq);\n            while (hls != 1 && quo(M, hls - 1) == sq) hls--;\n\
    \            s = hls + sq;\n        }\n        p = prime_enumerate(sq);\n    \
    \    ps = p.size();\n    }\n    // calc : sum[2 <= prime <= M/i] f(prime)\n  \
    \  // T f(int prime) : f(prime)\n    // T sum(long long r) : sum[2 <= x <= r]\
    \ f(x)\n    // T mul(int prime, T s) : sum[x in R] f(prime * x), for s = sum[x\
    \ in R] f(x), R = { x <= M/i | lpf(x) >= prime }\n    template<typename T>\n \
    \   std::vector<T> table(auto f, auto sum, auto mul) const {\n        if (M ==\
    \ 0) return {};\n        long long hls = s - sq;\n        std::vector<T> hl(hls);\n\
    \        for (int i = 1; i < hls; i++){\n            hl[i] = sum(quo(M, i));\n\
    \        }\n        std::vector<T> hs(sq + 1);\n        for (int i = 1; i <= sq;\
    \ i++){\n            hs[i] = sum(i);\n        }\n        T psum = {};\n      \
    \  for (auto &x : p){\n            long long x2 = (long long)(x) * x;\n      \
    \      long long imax = std::min<long long>(hls, quo(M, x2) + 1);\n          \
    \  for (long long i = 1, ix = x; i < imax; i++, ix += x){\n                hl[i]\
    \ -= mul(x, (ix < hls ? hl[ix] : hs[quo(M, ix)]) - psum);\n            }\n   \
    \         for (int n = sq; n >= x2; n--){\n                hs[n] -= mul(x, hs[quo(n,\
    \ x)] - psum);\n            }\n            psum += f(x);\n        }\n        hl.reserve(sq\
    \ * 2 + 10);\n        for (int i = hs.size(); --i; ) hl.push_back(hs[i]);\n  \
    \      assert((int)(hl.size()) == s);\n        return hl;\n    }\n    // calc\
    \ : sum[1 <= x <= M] f(x), f is multiplicative\n    // T f(int prime, int e) :\
    \ f(prime ^ e)\n    template<typename T>\n    T run(auto f, const std::vector<T>\
    \ &Fprime) const {\n        if (M == 0) return {};\n        assert((int)(Fprime.size())\
    \ == s);\n        T ans = Fprime[idx(M)] + 1; // + 1 : f(1)\n        auto dfs\
    \ = [&](auto sfs, int i, int c, long long prod, T cur) -> void {\n           \
    \ ans += cur * f(p[i], c + 1);\n            long long lim = quo(M, prod);\n  \
    \          if (lim >= 1LL * p[i] * p[i]){\n                sfs(sfs, i, c + 1,\
    \ p[i] * prod, cur);\n            }\n            cur *= f(p[i], c);\n        \
    \    ans += cur * (Fprime[idx(lim)] - Fprime[idx(p[i])]);\n            int j =\
    \ i + 1;\n            for (; j < ps && p[j] < (1 << 21) && 1LL * p[j] * p[j] *\
    \ p[j] <= lim; j++){\n                sfs(sfs, j, 1, prod * p[j], cur);\n    \
    \        }\n            for (; j < ps && 1LL * p[j] * p[j] <= lim; j++){\n   \
    \             T sm = f(p[j], 2);\n                int id1 = idx(quo(lim, p[j])),\
    \ id2 = idx(p[j]);\n                sm += f(p[j], 1) * (Fprime[id1] - Fprime[id2]);\n\
    \                ans += cur * sm;\n            }\n        };\n        for (int\
    \ i = 0; i < ps; i++){\n            dfs(dfs, i, 1, p[i], 1);\n        }\n    \
    \    return ans;\n    }\n    long long quo(long long n, long long d) const { return\
    \ n / d; }\n    long long idx(long long n) const { return n <= sq ? s - n : quo(M,\
    \ n); }\n    long long val(long long i) const { return i >= s - sq ? s - i : quo(M,\
    \ i); }\n};\n\n} // namespace noya2\n#line 22 \"test/math/SumofMultiplicativeFunction.test.cpp\"\
    \n\n\nvoid solve(){\n    ll n; in(n);\n    mint a, b; in(a,b);\n    mf_prefix_sum\
    \ mf(n);\n    mint i2 = mint(2).inv();\n    auto tbl = mf.table<ar>(\n       \
    \ [&](int p) -> ar {\n            return ar{a, b*p};\n        },\n        [&](ll\
    \ r) -> ar {\n            return ar{a*(r-1), b*(mint(r)*(r+1)*i2-1)};\n      \
    \  },\n        [&](int p, ar x) -> ar {\n            return ar{x[0], x[1] * p};\n\
    \        }\n    );\n    vector<mint> fprime(tbl.size());\n    rep(i,tbl.size()){\n\
    \        fprime[i] = tbl[i][0] + tbl[i][1];\n    }\n    mint ans = mf.run<mint>(\n\
    \        [&](int p, int e){\n            return a*e + b*p;\n        },\n     \
    \   fprime\n    );\n    out(ans);\n}\n\nint main(){\n    int t; in(t);\n    while\
    \ (t--){\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_multiplicative_function\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../utility/modint.hpp\"\
    \nusing mint = static_modint<469762049>;\nusing ar = array<mint,2>;\nar &operator+=(ar\
    \ &a, ar b){\n    a[0] += b[0];\n    a[1] += b[1];\n    return a;\n}\nar &operator-=(ar\
    \ &a, ar b){\n    a[0] -= b[0];\n    a[1] -= b[1];\n    return a;\n}\nar operator-(ar\
    \ a, ar b){\n    return a -= b;\n}\n\n#include\"../../math/multiplicative_function.hpp\"\
    \n\n\nvoid solve(){\n    ll n; in(n);\n    mint a, b; in(a,b);\n    mf_prefix_sum\
    \ mf(n);\n    mint i2 = mint(2).inv();\n    auto tbl = mf.table<ar>(\n       \
    \ [&](int p) -> ar {\n            return ar{a, b*p};\n        },\n        [&](ll\
    \ r) -> ar {\n            return ar{a*(r-1), b*(mint(r)*(r+1)*i2-1)};\n      \
    \  },\n        [&](int p, ar x) -> ar {\n            return ar{x[0], x[1] * p};\n\
    \        }\n    );\n    vector<mint> fprime(tbl.size());\n    rep(i,tbl.size()){\n\
    \        fprime[i] = tbl[i][0] + tbl[i][1];\n    }\n    mint ans = mf.run<mint>(\n\
    \        [&](int p, int e){\n            return a*e + b*p;\n        },\n     \
    \   fprime\n    );\n    out(ans);\n}\n\nint main(){\n    int t; in(t);\n    while\
    \ (t--){\n        solve();\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - utility/modint.hpp
  - math/prime.hpp
  - math/multiplicative_function.hpp
  isVerificationFile: true
  path: test/math/SumofMultiplicativeFunction.test.cpp
  requiredBy: []
  timestamp: '2025-02-18 22:43:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/SumofMultiplicativeFunction.test.cpp
layout: document
redirect_from:
- /verify/test/math/SumofMultiplicativeFunction.test.cpp
- /verify/test/math/SumofMultiplicativeFunction.test.cpp.html
title: test/math/SumofMultiplicativeFunction.test.cpp
---
