---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/math/Binomial_Coefficient_Prime_Mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\n\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"utility/modint.hpp\"\
    \n\n#line 2 \"math/prime.hpp\"\n\n#line 4 \"math/prime.hpp\"\n\nnamespace noya2\
    \ {\n\nconstexpr ll safe_mod(ll x, ll m) {\n    x %= m;\n    if (x < 0) x += m;\n\
    \    return x;\n}\n\nconstexpr ll pow_mod_constexpr(ll x, ll n, int m) {\n   \
    \ if (m == 1) return 0;\n    uint _m = (uint)(m);\n    ull r = 1;\n    ull y =\
    \ safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n   \
    \     y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\nconstexpr\
    \ bool is_prime_constexpr(int n) {\n    if (n <= 1) return false;\n    if (n ==\
    \ 2 || n == 7 || n == 61) return true;\n    if (n % 2 == 0) return false;\n  \
    \  ll d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    constexpr ll bases[3] =\
    \ {2, 7, 61};\n    for (ll a : bases) {\n        ll t = d;\n        ll y = pow_mod_constexpr(a,\
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
    \ 2;\n    for (int i = 3; (ll)(i)*i <= x; i += 2) {\n        if (x % i == 0) {\n\
    \            divs[cnt++] = i;\n            while (x % i == 0) {\n            \
    \    x /= i;\n            }\n        }\n    }\n    if (x > 1) {\n        divs[cnt++]\
    \ = x;\n    }\n    for (int g = 2;; g++) {\n        bool ok = true;\n        for\
    \ (int i = 0; i < cnt; i++) {\n            if (pow_mod_constexpr(g, (m - 1) /\
    \ divs[i], m) == 1) {\n                ok = false;\n                break;\n \
    \           }\n        }\n        if (ok) return g;\n    }\n}\ntemplate <int m>\
    \ constexpr int primitive_root_flag = primitive_root_constexpr(m);\n\n} // namespace\
    \ noya2\n#line 4 \"utility/modint.hpp\"\n\nnamespace noya2{\n\nstruct barrett\
    \ {\n    uint _m;\n    ull  im;\n    explicit barrett(uint m) : _m(m), im((ull)(-1)\
    \ / m + 1) {}\n    uint umod() const { return _m; }\n    uint mul(uint a, uint\
    \ b) const {\n        ull z = a;\n        z *= b;\n        ull x = ull((__uint128_t(z)\
    \ * im) >> 64);\n        uint v = (uint)(z - x * _m);\n        if (_m <= v) v\
    \ += _m;\n        return v;\n    }\n};\n\ntemplate <int m>\nstruct static_modint\
    \ {\n    using mint = static_modint;\n  public:\n    static constexpr int mod()\
    \ { return m; }\n    static mint raw(int v) {\n        mint x;\n        x._v =\
    \ v;\n        return x;\n    }\n    constexpr static_modint() : _v(0) {}\n   \
    \ template<signed_integral T>\n    constexpr static_modint(T v){\n        ll x\
    \ = (ll)(v % (ll)(umod()));\n        if (x < 0) x += umod();\n        _v = (uint)(x);\n\
    \    }\n    template<unsigned_integral T>\n    constexpr static_modint(T v){\n\
    \        _v = (uint)(v % umod());\n    }\n    constexpr unsigned int val() const\
    \ { return _v; }\n    mint& operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n    constexpr mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    constexpr mint& operator-=(const mint& rhs)\
    \ {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return\
    \ *this;\n    }\n    constexpr mint& operator*=(const mint& rhs) {\n        ull\
    \ z = _v;\n        z *= rhs._v;\n        _v = (uint)(z % umod());\n        return\
    \ *this;\n    }\n    constexpr mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n    constexpr mint operator+() const { return *this;\
    \ }\n    constexpr mint operator-() const { return mint() - *this; }\n    constexpr\
    \ mint pow(ll n) const {\n        assert(0 <= n);\n        mint x = *this, r =\
    \ 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    constexpr mint\
    \ inv() const {\n        if (prime) {\n            assert(_v);\n            return\
    \ pow(umod() - 2);\n        } else {\n            auto eg = inv_gcd(_v, m);\n\
    \            assert(eg.first == 1);\n            return eg.second;\n        }\n\
    \    }\n    friend constexpr mint operator+(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) += rhs;\n    }\n    friend constexpr mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend constexpr mint operator*(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) *= rhs;\n    }\n    friend constexpr mint operator/(const\
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
    \    dynamic_modint(T v){\n        ll x = (ll)(v % (ll)(mod()));\n        if (x\
    \ < 0) x += mod();\n        _v = (uint)(x);\n    }\n    template<unsigned_integral\
    \ T>\n    dynamic_modint(T v){\n        _v = (uint)(v % mod());\n    }\n    uint\
    \ val() const { return _v; }\n    mint& operator++() {\n        _v++;\n      \
    \  if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
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
    \    a.pow(declval<int>());\n};\n\n} // namespace noya2\n#line 2 \"math/binomial.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<typename mint>\nstruct binomial {\n    binomial(int\
    \ len = 300000){ extend(len); }\n    static mint fact(int n){\n        if (n <\
    \ 0) return 0;\n        while (n >= (int)_fact.size()) extend();\n        return\
    \ _fact[n];\n    }\n    static mint ifact(int n){\n        if (n < 0) return 0;\n\
    \        while (n >= (int)_fact.size()) extend();\n        return _ifact[n];\n\
    \    }\n    static mint inv(int n){\n        return ifact(n) * fact(n-1);\n  \
    \  }\n    static mint C(int n, int r){\n        if (!(0 <= r && r <= n)) return\
    \ 0;\n        return fact(n) * ifact(r) * ifact(n-r);\n    }\n    static mint\
    \ P(int n, int r){\n        if (!(0 <= r && r <= n)) return 0;\n        return\
    \ fact(n) * ifact(n-r);\n    }\n    inline mint operator()(int n, int r) { return\
    \ C(n, r); }\n    template<class... Cnts> static mint M(const Cnts&... cnts){\n\
    \        return multinomial(0,1,cnts...);\n    }\n  private:\n    static mint\
    \ multinomial(const int& sum, const mint& div_prod){\n        if (sum < 0) return\
    \ 0;\n        return fact(sum) * div_prod;\n    }\n    template<class... Tail>\
    \ static mint multinomial(const int& sum, const mint& div_prod, const int& n1,\
    \ const Tail&... tail){\n        if (n1 < 0) return 0;\n        return multinomial(sum+n1,div_prod*ifact(n1),tail...);\n\
    \    }\n    static vector<mint> _fact, _ifact;\n    static void extend(int len\
    \ = -1){\n        if (_fact.empty()){\n            _fact = _ifact = {1,1};\n \
    \       }\n        int siz = _fact.size();\n        if (len == -1) len = siz *\
    \ 2;\n        len = min<int>(len, mint::mod()-1);\n        if (len < siz) return\
    \ ;\n        _fact.resize(len+1), _ifact.resize(len+1);\n        for (int i =\
    \ siz; i <= len; i++) _fact[i] = _fact[i-1] * i;\n        _ifact[len] = _fact[len].inv();\n\
    \        for (int i = len; i > siz; i--) _ifact[i-1] = _ifact[i] * i;\n    }\n\
    };\ntemplate<typename T>\nstd::vector<T>binomial<T>::_fact = vector<T>(2,T(1));\n\
    template<typename T>\nstd::vector<T>binomial<T>::_ifact = vector<T>(2,T(1));\n\
    \n} // namespace noya2\n#line 6 \"test/math/Binomial_Coefficient_Prime_Mod.test.cpp\"\
    \n\nint main(){\n    int t, m; in(t,m);\n    modint::set_mod(m);\n    while (t--){\n\
    \        int n, k; in(n,k);\n        out(binomial<modint>::C(n,k).val());\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../utility/modint.hpp\"\
    \n#include\"../../math/binomial.hpp\"\n\nint main(){\n    int t, m; in(t,m);\n\
    \    modint::set_mod(m);\n    while (t--){\n        int n, k; in(n,k);\n     \
    \   out(binomial<modint>::C(n,k).val());\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - utility/modint.hpp
  - math/prime.hpp
  - math/binomial.hpp
  isVerificationFile: true
  path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  requiredBy: []
  timestamp: '2023-10-09 15:49:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
layout: document
redirect_from:
- /verify/test/math/Binomial_Coefficient_Prime_Mod.test.cpp
- /verify/test/math/Binomial_Coefficient_Prime_Mod.test.cpp.html
title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
---
