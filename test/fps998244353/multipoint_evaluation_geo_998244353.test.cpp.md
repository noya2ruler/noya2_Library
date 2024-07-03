---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps998244353/fps998244353.hpp
    title: fps998244353/fps998244353.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/multipoint_evaluation.hpp
    title: fps998244353/multipoint_evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: fps998244353/ntt998244353.hpp
    title: fps998244353/ntt998244353.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence
    links:
    - https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence
  bundledCode: "#line 1 \"test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"fps998244353/multipoint_evaluation.hpp\"\
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
    \ 2 \"fps998244353/ntt998244353.hpp\"\n\n#line 4 \"fps998244353/ntt998244353.hpp\"\
    \n\n#line 7 \"fps998244353/ntt998244353.hpp\"\n\nnamespace noya2 {\n\nnamespace\
    \ internal {\n\nconstexpr int FFT_MAX = 23;\nconstexpr unsigned FFT_ROOTS[FFT_MAX\
    \ + 1] = {1U, 998244352U, 911660635U, 372528824U, 929031873U, 452798380U, 922799308U,\
    \ 781712469U, 476477967U, 166035806U, 258648936U, 584193783U, 63912897U, 350007156U,\
    \ 666702199U, 968855178U, 629671588U, 24514907U, 996173970U, 363395222U, 565042129U,\
    \ 733596141U, 267099868U, 15311432U};\nconstexpr unsigned INV_FFT_ROOTS[FFT_MAX\
    \ + 1] = {1U, 998244352U, 86583718U, 509520358U, 337190230U, 87557064U, 609441965U,\
    \ 135236158U, 304459705U, 685443576U, 381598368U, 335559352U, 129292727U, 358024708U,\
    \ 814576206U, 708402881U, 283043518U, 3707709U, 121392023U, 704923114U, 950391366U,\
    \ 428961804U, 382752275U, 469870224U};\nconstexpr unsigned FFT_RATIOS[FFT_MAX]\
    \ = {911660635U, 509520358U, 369330050U, 332049552U, 983190778U, 123842337U, 238493703U,\
    \ 975955924U, 603855026U, 856644456U, 131300601U, 842657263U, 730768835U, 942482514U,\
    \ 806263778U, 151565301U, 510815449U, 503497456U, 743006876U, 741047443U, 56250497U,\
    \ 867605899U};\nconstexpr unsigned INV_FFT_RATIOS[FFT_MAX] = {86583718U, 372528824U,\
    \ 373294451U, 645684063U, 112220581U, 692852209U, 155456985U, 797128860U, 90816748U,\
    \ 860285882U, 927414960U, 354738543U, 109331171U, 293255632U, 535113200U, 308540755U,\
    \ 121186627U, 608385704U, 438932459U, 359477183U, 824071951U, 103369235U};\n\n\
    } // namespace noya2::internal\n\nstruct ntt998244353 {\n    using mint = modint998244353;\n\
    \    static constexpr unsigned MO = modint998244353::mod();\n    static constexpr\
    \ unsigned MO2 = MO * 2;\n    static void ntt(mint *as, int n){\n        int m\
    \ = n;\n        if (m >>= 1){\n            for (int i = 0; i < m; i++){\n    \
    \            const unsigned x = as[i + m].val();\n                as[i + m] =\
    \ mint::raw(as[i].val() + MO - x);\n                as[i] = mint::raw(as[i].val()\
    \ + x);\n            }\n        }\n        if (m >>= 1){\n            mint prod\
    \ = mint::raw(1);\n            for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)){\n\
    \                for (int i = i0; i < i0 + m; i++){\n                    const\
    \ unsigned x = (prod * as[i + m]).val();\n                    as[i + m] = mint::raw(as[i].val()\
    \ + MO - x);\n                    as[i] = mint::raw(as[i].val() + x);\n      \
    \          }\n                prod *= mint::raw(internal::FFT_RATIOS[__builtin_ctz(++h)]);\n\
    \            }\n        }\n        for (; m; ){\n            if (m >>= 1){\n \
    \               mint prod = mint::raw(1);\n                for (int h = 0, i0\
    \ = 0; i0 < n; i0 += (m << 1)){\n                    for (int i = i0; i < i0 +\
    \ m; i++){\n                        const unsigned x = (prod * as[i + m]).val();\n\
    \                        as[i + m] = mint::raw(as[i].val() + MO - x);\n      \
    \                  as[i] = mint::raw(as[i].val() + x);\n                    }\n\
    \                    prod *= mint::raw(internal::FFT_RATIOS[__builtin_ctz(++h)]);\n\
    \                }\n            }\n            if (m >>= 1){\n               \
    \ mint prod = mint::raw(1);\n                for (int h = 0, i0 = 0; i0 < n; i0\
    \ += (m << 1)) {\n                    for (int i = i0; i < i0 + m; i++) {\n  \
    \                      const unsigned x = (prod * as[i + m]).val();\n        \
    \                as[i] = mint::raw((as[i].val() >= MO2) ? (as[i].val() - MO2)\
    \ : as[i].val());\n                        as[i + m] = mint::raw(as[i].val() +\
    \ MO - x);\n                        as[i] = mint::raw(as[i].val() + x);\n    \
    \                }\n                    prod *= mint::raw(internal::FFT_RATIOS[__builtin_ctz(++h)]);\n\
    \                }\n            }\n        }\n        for (int i = 0; i < n; i++){\n\
    \            as[i] = mint::raw((as[i].val() >= MO2) ? as[i].val() - MO2 : as[i].val());\n\
    \            as[i] = mint::raw((as[i].val() >= MO) ? as[i].val() - MO : as[i].val());\n\
    \        }\n    }\n    static void intt(mint *as, int n){\n        int m = 1;\n\
    \        if (m < (n >> 1)){\n            mint prod = mint::raw(1);\n         \
    \   for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)){\n                for (int\
    \ i = i0; i < i0 + m; i++){\n                    const unsigned long long y =\
    \ as[i].val() + MO - as[i + m].val();\n                    as[i] = mint::raw(as[i].val()\
    \ + as[i + m].val());\n                    as[i + m] = mint::raw(prod.val() *\
    \ y % MO);\n                }\n                prod *= mint::raw(internal::INV_FFT_RATIOS[__builtin_ctz(++h)]);\n\
    \            }\n            m <<= 1;\n        }\n        for (; m < (n >> 1);\
    \ m <<= 1){\n            mint prod = mint::raw(1);\n            for (int h = 0,\
    \ i0 = 0; i0 < n; i0 += (m << 1)) {\n                for (int i = i0; i < i0 +\
    \ (m >> 1); ++i) {\n                    const unsigned long long y = as[i].val()\
    \ + MO2 - as[i + m].val();\n                    as[i] = mint::raw(as[i].val()\
    \ + as[i + m].val());\n                    as[i] = mint::raw((as[i].val() >= MO2)\
    \ ? (as[i].val() - MO2) : as[i].val());\n                    as[i + m] = mint::raw(prod.val()\
    \ * y % MO);\n                }\n                for (int i = i0 + (m >> 1); i\
    \ < i0 + m; ++i) {\n                    const unsigned long long y = as[i].val()\
    \ + MO - as[i + m].val();\n                    as[i] = mint::raw(as[i].val() +\
    \ as[i + m].val());\n                    as[i + m] = mint::raw(prod.val() * y\
    \ % MO);\n                }\n                prod *= mint::raw(internal::INV_FFT_RATIOS[__builtin_ctz(++h)]);\n\
    \            }\n        }\n        if (m < n){\n            for (int i = 0; i\
    \ < m; i++){\n                const unsigned y = as[i].val() + MO2 - as[i + m].val();\n\
    \                as[i] = mint::raw(as[i].val() + as[i + m].val());\n         \
    \       as[i + m] = mint::raw(y);\n            }\n        }\n        for (int\
    \ i = 0; i < n; i++){\n            as[i] = mint::raw((as[i].val() >= MO2) ? as[i].val()\
    \ - MO2 : as[i].val());\n            as[i] = mint::raw((as[i].val() >= MO) ? as[i].val()\
    \ - MO : as[i].val());\n        }\n    }\n    void ntt(std::vector<mint> &as){\n\
    \        ntt(as.data(), as.size());\n    }\n    void intt(std::vector<mint> &as){\n\
    \        intt(as.data(), as.size());\n    }\n    void intt_div(std::vector<mint>\
    \ &as){\n        intt(as);\n        int n = as.size();\n        const mint inv_n\
    \ = mint::raw(n).inv();\n        for (int i = 0; i < n; i++){\n            as[i]\
    \ *= inv_n;\n        }\n    }\n    std::vector<mint> multiply(std::vector<mint>\
    \ as, std::vector<mint> bs){\n        if (as.empty() || bs.empty()) return {};\n\
    \        const int len = as.size() + bs.size() - 1u;\n        if (std::min(as.size(),\
    \ bs.size()) <= 40u){\n            std::vector<mint> s(len);\n            for\
    \ (int i = 0; i < (int)(as.size()); i++){\n                for (int j = 0; j <\
    \ (int)(bs.size()); j++){\n                    s[i + j] += as[i] * bs[j];\n  \
    \              }\n            }\n            return s;\n        }\n        int\
    \ n = 1;\n        for (; n < len; n <<= 1) {}\n        if (as.size() == bs.size()\
    \ && as == bs){\n            as.resize(n);\n            ntt(as);\n           \
    \ for (int i = 0; i < n; i++){\n                as[i] *= as[i];\n            }\n\
    \        }\n        else {\n            as.resize(n);\n            ntt(as);\n\
    \            bs.resize(n);\n            ntt(bs);\n            for (int i = 0;\
    \ i < n; i++){\n                as[i] *= bs[i];\n            }\n        }\n  \
    \      intt_div(as);\n        as.resize(len);\n        return as;\n    }\n};\n\
    \n} // namespace noya2\n#line 2 \"math/binomial.hpp\"\n\n#line 4 \"math/binomial.hpp\"\
    \nnamespace noya2 {\n\ntemplate<typename mint>\nstruct binomial {\n    binomial(int\
    \ len = 300000){ extend(len); }\n    static mint fact(int n){\n        if (n <\
    \ 0) return 0;\n        while (n >= (int)_fact.size()) extend();\n        return\
    \ _fact[n];\n    }\n    static mint ifact(int n){\n        if (n < 0) return 0;\n\
    \        while (n >= (int)_fact.size()) extend();\n        return _ifact[n];\n\
    \    }\n    static mint inv(int n){\n        return ifact(n) * fact(n-1);\n  \
    \  }\n    static mint C(int n, int r){\n        if (!(0 <= r && r <= n)) return\
    \ 0;\n        return fact(n) * ifact(r) * ifact(n-r);\n    }\n    static mint\
    \ P(int n, int r){\n        if (!(0 <= r && r <= n)) return 0;\n        return\
    \ fact(n) * ifact(n-r);\n    }\n    inline mint operator()(int n, int r) { return\
    \ C(n, r); }\n    template<class... Cnts>\n    static mint M(const Cnts&... cnts){\n\
    \        return multinomial(0,1,cnts...);\n    }\n    static void initialize(int\
    \ len = 2){\n        _fact.clear();\n        _ifact.clear();\n        extend(len);\n\
    \    }\n  private:\n    static mint multinomial(const int& sum, const mint& div_prod){\n\
    \        if (sum < 0) return 0;\n        return fact(sum) * div_prod;\n    }\n\
    \    template<class... Tail>\n    static mint multinomial(const int& sum, const\
    \ mint& div_prod, const int& n1, const Tail&... tail){\n        if (n1 < 0) return\
    \ 0;\n        return multinomial(sum+n1,div_prod*ifact(n1),tail...);\n    }\n\
    \    static inline std::vector<mint> _fact, _ifact;\n    static void extend(int\
    \ len = -1){\n        if (_fact.empty()){\n            _fact = _ifact = {1,1};\n\
    \        }\n        int siz = _fact.size();\n        if (len == -1) len = siz\
    \ * 2;\n        len = (int)min<long long>(len, mint::mod() - 1);\n        if (len\
    \ < siz) return ;\n        _fact.resize(len+1), _ifact.resize(len+1);\n      \
    \  for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1] * i;\n        _ifact[len]\
    \ = _fact[len].inv();\n        for (int i = len; i > siz; i--) _ifact[i-1] = _ifact[i]\
    \ * i;\n    }\n};\n\n} // namespace noya2\n#line 7 \"fps998244353/fps998244353.hpp\"\
    \n\nnamespace noya2 {\n\n// Formal Power Series for modint998244353\nstruct fps998244353\
    \ : std::vector<modint998244353> {\n    using mint = modint998244353;\n    using\
    \ std::vector<mint>::vector;\n    using std::vector<mint>::operator=;\n    using\
    \ fps = fps998244353;\n    static inline ntt998244353 ntt_;\n    static inline\
    \ binomial<mint> bnm;\n\n    fps998244353 (const std::vector<mint> &init){\n \
    \       (*this) = init;\n    }\n\n    void shrink(){\n        while(!(this->empty())\
    \ && this->back().val() == 0){\n            this->pop_back();\n        }\n   \
    \ }\n\n    fps &operator*= (const mint &r){\n        for (auto &x : *this) x *=\
    \ r;\n        return *this;\n    }\n    fps &operator/= (const mint &r){\n   \
    \     (*this) *= r.inv();\n        return *this;\n    }\n\n    fps &operator<<=\
    \ (const int &d){\n        this->insert(this->begin(), d, mint(0));\n        return\
    \ *this;\n    }\n    fps &operator>>= (const int &d){\n        if ((int)(this->size())\
    \ <= d) this->clear();\n        else this->erase(this->begin(),this->begin() +\
    \ d);\n        return *this;\n    }\n\n    fps &operator+= (const fps &r){\n \
    \       if (this->size() < r.size()) this->resize(r.size());\n        for (int\
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
    \    for (int i = 0; i < siz*2; i++) f[i] *= g[i];\n            ntt_.intt(f);\n\
    \            f.erase(f.begin(),f.begin()+siz);\n            f.resize(siz*2);\n\
    \            f.ntt();\n            for (int i = 0; i < siz*2; i++) f[i] *= g[i];\n\
    \            f.intt();\n            mint siz2_inv = mint(siz*2).inv(); siz2_inv\
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
    \    }\n    // NOT /= len\n    void intt(){\n        ntt_.intt(*this);\n    }\n\
    \    // already /= len\n    void intt_div(){\n        return ntt_.intt_div(*this);\n\
    \    }\n    fps quotient(fps r) const {\n        r.shrink();\n        const int\
    \ n = this->size(), m = r.size();\n        if (n < m){\n            return fps();\n\
    \        }\n        fps quo(*this);\n        const int sz = n - m + 1;\n     \
    \   std::reverse(quo.begin(), quo.end());\n        std::reverse(r.begin(), r.end());\n\
    \        quo.resize(sz);\n        quo *= r.inv(sz);\n        quo.resize(sz);\n\
    \        std::reverse(quo.begin(), quo.end());\n        return quo;\n    }\n \
    \   fps remainder(fps r) const {\n        r.shrink();\n        const int n = this->size(),\
    \ m = r.size();\n        if (n < m){\n            return fps(*this);\n       \
    \ }\n        fps rem(*this);\n        rem -= quotient(r) * r;\n        rem.resize(m-1);\n\
    \        rem.shrink();\n        return rem;\n    }\n    std::pair<fps,fps> remquo(fps\
    \ r) const {\n        r.shrink();\n        fps quo = quotient(r);\n        fps\
    \ rem(*this);\n        rem -= quo * r;\n        rem.shrink();\n        return\
    \ {rem, quo};\n    }\n};\n\n} // namespace noya2\n#line 4 \"fps998244353/multipoint_evaluation.hpp\"\
    \n\nnamespace noya2 {\n\nstd::vector<modint998244353> multipoint_evaluation(fps998244353\
    \ f, const std::vector<modint998244353> &xs){\n    const int n = xs.size();\n\
    \    int sz = 1;\n    while(sz < n) sz <<= 1;\n    std::vector<fps998244353> g(sz+sz,{1});\n\
    \    for(int i = 0; i < n; i++) g[i+sz] = {-xs[i],1};\n    for(int i = sz; i-->1;)\
    \ g[i] = g[i<<1] * g[i<<1|1];\n    g[1] = f.remainder(g[1]);\n    for(int i =\
    \ 2; i < sz+n; i++) g[i] = g[i>>1].remainder(g[i]);\n    std::vector<modint998244353>\
    \ res(n);\n    for(int i = 0; i < n; i++) res[i] = (g[i+sz].empty() ? modint998244353()\
    \ : g[i+sz][0]);\n    return res;\n}\n\nstd::vector<modint998244353> multipoint_evaluation_geo(const\
    \ fps998244353 &f, modint998244353 a, modint998244353 r, int m){\n    using mint\
    \ = modint998244353;\n    int n = f.size();\n    if (r.val() == 0){\n        std::vector<mint>\
    \ ans(m);\n        repp(i,1,m) ans[i] = f[0];\n        ans[0] = f.eval(a);\n \
    \       return ans;\n    }\n    fps998244353 p(n);\n    mint aprd = 1;\n    mint\
    \ ir = r.inv();\n    mint irpp = 1, irp = 1;\n    for (int i = 0; i < n; i++){\n\
    \        p[n-1-i] = aprd * f[i] * irpp;\n        irpp *= irp;\n        irp *=\
    \ ir;\n        aprd *= a;\n    }\n    fps998244353 q(n+m-1);\n    mint rpp = 1,\
    \ rp = 1;\n    for (int i = 0; i < n+m-1; i++){\n        q[i] = rpp;\n       \
    \ rpp *= rp;\n        rp *= r;\n    }\n    p *= q;\n    std::vector<mint> ans(m);\n\
    \    irpp = 1, irp = 1;\n    for (int i = 0; i < m; i++){\n        ans[i] = p[n-1+i]\
    \ * irpp;\n        irpp *= irp;\n        irp *= ir;\n    }\n    return ans;\n\
    }\n\n} // namespace noya2\n#line 5 \"test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp\"\
    \n\nusing mint = modint998244353;\nusing fps = fps998244353;\n\nint main(){\n\
    \    int n, m, a, r; in(n,m,a,r);\n    fps f(n); in(f);\n    out(multipoint_evaluation_geo(f,a,r,m));\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../fps998244353/multipoint_evaluation.hpp\"\
    \n\nusing mint = modint998244353;\nusing fps = fps998244353;\n\nint main(){\n\
    \    int n, m, a, r; in(n,m,a,r);\n    fps f(n); in(f);\n    out(multipoint_evaluation_geo(f,a,r,m));\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - fps998244353/multipoint_evaluation.hpp
  - fps998244353/fps998244353.hpp
  - utility/modint.hpp
  - math/prime.hpp
  - fps998244353/ntt998244353.hpp
  - math/binomial.hpp
  isVerificationFile: true
  path: test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp
  requiredBy: []
  timestamp: '2024-07-03 11:54:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp
layout: document
redirect_from:
- /verify/test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp
- /verify/test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp.html
title: test/fps998244353/multipoint_evaluation_geo_998244353.test.cpp
---
