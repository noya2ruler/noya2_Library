---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal_power_series.hpp
    title: fps/formal_power_series.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_ntt.hpp
    title: fps/fps_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt.hpp
    title: fps/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sample_point_shift.hpp
    title: fps/sample_point_shift.hpp
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
  bundledCode: "#line 1 \"test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp\"\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"fps/fps_ntt.hpp\"\
    \n\n#line 2 \"fps/formal_power_series.hpp\"\n\n#line 4 \"fps/formal_power_series.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<typename T>\nconcept Field = requires (T a, T\
    \ b){\n    a + b; a - b; a / b; a * b;\n    T(0); T(1);\n};\n\ntemplate<class\
    \ Info>\nconcept Fps_Info = requires {\n    typename Info::value_type;\n    requires\
    \ Field<typename Info::value_type>;\n    {Info::multiply(declval<vector<typename\
    \ Info::value_type>>(),declval<vector<typename Info::value_type>>())} -> convertible_to<vector<typename\
    \ Info::value_type>>;\n    {Info::inv(declval<vector<typename Info::value_type>>(),declval<int>())}\
    \ -> convertible_to<vector<typename Info::value_type>>;\n    {Info::integral(declval<vector<typename\
    \ Info::value_type>>())} -> convertible_to<vector<typename Info::value_type>>;\n\
    };\n\ntemplate<Fps_Info Info>\nstruct FormalPowerSeries : vector<typename Info::value_type>\
    \ {\n    using T = typename Info::value_type;\n    using vector<T>::vector;\n\
    \    using vector<T>::operator=;\n    using FPS = FormalPowerSeries;\n    FormalPowerSeries\
    \ (const vector<T> &init_ = {}){ (*this) = init_; }\n    void shrink(){ while\
    \ (!(*this).empty() && (*this).back() == T(0)) (*this).pop_back(); }\n    FPS\
    \ &operator+=(const T &r){\n        if ((*this).empty()) (*this).resize(1);\n\
    \        (*this)[0] += r;\n        return *this;\n    }\n    FPS &operator-=(const\
    \ T &r){\n        if ((*this).empty()) (*this).resize(1);\n        (*this)[0]\
    \ -= r;\n        return *this;\n    }\n    FPS &operator*=(const T &r){\n    \
    \    for (auto &x : *this) x *= r;\n        return *this;\n    }\n    FPS &operator/=(const\
    \ T &r){\n        (*this) *= T(1)/r;\n        return *this;\n    }\n    FPS &operator<<=(const\
    \ int &d){\n        (*this).insert((*this).begin(),d,T(0));\n        return *this;\n\
    \    }\n    FPS &operator>>=(const int &d){\n        if ((int)(*this).size() <=\
    \ d) (*this).clear();\n        else (*this).erase((*this).begin(),(*this).begin()+d);\n\
    \        return *this;\n    }\n    FPS &operator+=(const FPS &r){\n        if\
    \ ((*this).size() < r.size()) (*this).resize(r.size());\n        for (int i =\
    \ 0; i < (int)(r.size()); i++) (*this)[i] += r[i];\n        return *this;\n  \
    \  }\n    FPS &operator-=(const FPS &r){\n        if ((*this).size() < r.size())\
    \ (*this).resize(r.size());\n        for (int i = 0; i < (int)(r.size()); i++)\
    \ (*this)[i] -= r[i];\n        return *this;\n    }\n    FPS &operator*=(const\
    \ FPS &r){\n        if ((*this).empty() || r.empty()){\n            (*this).clear();\n\
    \            return *this;\n        }\n        (*this) = Info::multiply(*this,r);\n\
    \        return *this;\n    }\n    FPS operator+(const T &r) const { return FPS(*this)\
    \ += r; }\n    FPS operator-(const T &r) const { return FPS(*this) -= r; }\n \
    \   FPS operator*(const T &r) const { return FPS(*this) *= r; }\n    FPS operator/(const\
    \ T &r) const { return FPS(*this) /= r; }\n    FPS operator<<(const int &d) const\
    \ { return FPS(*this) <<= d; }\n    FPS operator>>(const int &d) const { return\
    \ FPS(*this) >>= d; }\n    FPS operator+(const FPS &r) const { return FPS(*this)\
    \ += r; }\n    FPS operator-(const FPS &r) const { return FPS(*this) -= r; }\n\
    \    FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n    FPS operator+()\
    \ const { return *this; }\n    FPS operator-() const {\n        FPS res(*this);\n\
    \        for (auto &x : res) x = -x;\n        return res;\n    }\n    T eval(const\
    \ T &x) const {\n        T res = T(0), w = T(1);\n        for (auto &e : *this)\
    \ res += e * w, w *= x;\n        return res;\n    }\n    static FPS dot(const\
    \ FPS &lhs, const FPS &rhs){\n        FPS res(min(lhs.size(),rhs.size()));\n \
    \       for (int i = 0; i < (int)res.size(); i++) res[i] = lhs[i] * rhs[i];\n\
    \        return res;\n    }\n    FPS pre(int siz) const {\n        FPS ret((*this).begin(),\
    \ (*this).begin() + min((int)this->size(), siz));\n        if ((int)ret.size()\
    \ < siz) ret.resize(siz);\n        return ret;\n    }\n    FPS rev() const {\n\
    \        FPS ret(*this);\n        reverse(ret.begin(), ret.end());\n        return\
    \ ret;\n    }\n    FPS diff() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(max(0, n - 1));\n        T one(1), coeff(1);\n        for (int\
    \ i = 1; i < n; i++) {\n            ret[i - 1] = (*this)[i] * coeff;\n       \
    \     coeff += one;\n        }\n        return ret;\n    }\n    FPS integral()\
    \ const {\n        FPS ret = Info::integral(*this);\n        return ret;\n   \
    \ }\n    FPS inv(int d = -1) const {\n        FPS ret = Info::inv(*this,d);\n\
    \        return ret;\n    }\n    FPS exp(int d = -1) const {\n        const int\
    \ n = (*this).size();\n        if (d == -1) d = n;\n        FPS f = {T(1)+(*this)[0],(*this)[1]},\
    \ res = {1,(n > 1 ? (*this)[1] : 0)};\n        for (int sz = 2; sz < d; sz <<=\
    \ 1){\n            f.insert(f.end(),(*this).begin()+min(n,sz),(*this).begin()+min(n,sz*2));\n\
    \            if ((int)f.size() < sz*2) f.resize(sz*2);\n            res = res\
    \ * (f - res.log(2*sz));\n            res.resize(sz*2);\n        }\n        res.resize(d);\n\
    \        return res;\n    }\n    FPS log(int d = -1) const {\n        assert(!(*this).empty()\
    \ && (*this)[0] == T(1));\n        if (d == -1) d = (*this).size();\n        return\
    \ (this->diff() * this->inv(d)).pre(d - 1).integral();\n    }\n};\n\n} // namespace\
    \ noya2\n#line 2 \"math/binomial.hpp\"\n\nnamespace noya2 {\n\ntemplate<typename\
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
    \ = vector<T>(2,T(1));\n\n} // namespace noya2\n#line 2 \"fps/ntt.hpp\"\n\n#line\
    \ 2 \"utility/modint.hpp\"\n\n#line 2 \"math/prime.hpp\"\n\n#line 4 \"math/prime.hpp\"\
    \n\nnamespace noya2 {\n\nconstexpr ll safe_mod(ll x, ll m) {\n    x %= m;\n  \
    \  if (x < 0) x += m;\n    return x;\n}\n\nconstexpr ll pow_mod_constexpr(ll x,\
    \ ll n, int m) {\n    if (m == 1) return 0;\n    uint _m = (uint)(m);\n    ull\
    \ r = 1;\n    ull y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r =\
    \ (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return\
    \ r;\n}\n\nconstexpr bool is_prime_constexpr(int n) {\n    if (n <= 1) return\
    \ false;\n    if (n == 2 || n == 7 || n == 61) return true;\n    if (n % 2 ==\
    \ 0) return false;\n    ll d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    constexpr\
    \ ll bases[3] = {2, 7, 61};\n    for (ll a : bases) {\n        ll t = d;\n   \
    \     ll y = pow_mod_constexpr(a, t, n);\n        while (t != n - 1 && y != 1\
    \ && y != n - 1) {\n            y = y * y % n;\n            t <<= 1;\n       \
    \ }\n        if (y != n - 1 && t % 2 == 0) {\n            return false;\n    \
    \    }\n    }\n    return true;\n}\ntemplate <int n> constexpr bool is_prime_flag\
    \ = is_prime_constexpr(n);\n\nconstexpr std::pair<long long, long long> inv_gcd(long\
    \ long a, long long b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b,\
    \ 0};\n    long long s = b, t = a;\n    long long m0 = 0, m1 = 1;\n    while (t)\
    \ {\n        long long u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\
    \ \n        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n  \
    \  return {s, m0};\n}\n\nconstexpr int primitive_root_constexpr(int m) {\n   \
    \ if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (ll)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root_flag\
    \ = primitive_root_constexpr(m);\n\n} // namespace noya2\n#line 4 \"utility/modint.hpp\"\
    \n\nnamespace noya2{\n\nstruct barrett {\n    uint _m;\n    ull  im;\n    explicit\
    \ barrett(uint m) : _m(m), im((ull)(-1) / m + 1) {}\n    uint umod() const { return\
    \ _m; }\n    uint mul(uint a, uint b) const {\n        ull z = a;\n        z *=\
    \ b;\n        ull x = ull((__uint128_t(z) * im) >> 64);\n        uint v = (uint)(z\
    \ - x * _m);\n        if (_m <= v) v += _m;\n        return v;\n    }\n};\n\n\
    template <int m>\nstruct static_modint {\n    using mint = static_modint;\n  public:\n\
    \    static constexpr int mod() { return m; }\n    static mint raw(int v) {\n\
    \        mint x;\n        x._v = v;\n        return x;\n    }\n    constexpr static_modint()\
    \ : _v(0) {}\n    template<signed_integral T>\n    constexpr static_modint(T v){\n\
    \        ll x = (ll)(v % (ll)(umod()));\n        if (x < 0) x += umod();\n   \
    \     _v = (uint)(x);\n    }\n    template<unsigned_integral T>\n    constexpr\
    \ static_modint(T v){\n        _v = (uint)(v % umod());\n    }\n    constexpr\
    \ unsigned int val() const { return _v; }\n    mint& operator++() {\n        _v++;\n\
    \        if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
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
    \    a.pow(declval<int>());\n};\n\n} // namespace noya2\n#line 5 \"fps/ntt.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<Modint mint>\nstruct NTT {\n    static constexpr\
    \ uint mod = mint::mod();\n    static constexpr uint pr  = primitive_root_constexpr(mod);\n\
    \    static constexpr int level = countr_zero(mod-1);\n    mint wp[level+1], wm[level+1];\n\
    \    void set_ws(){\n        mint r = mint(pr).pow((mod-1) >> level);\n      \
    \  wp[level] = r, wm[level] = r.inv();\n        for (int i = level-1; i >= 0;\
    \ i--){\n            wp[i] = wp[i+1] * wp[i+1];\n            wm[i] = wm[i+1] *\
    \ wm[i+1];\n        }\n    }\n    NTT () { set_ws(); }\n    void fft2(vector<mint>\
    \ &a, int k, int l = -1){\n        if (k <= 0 || a.empty()) return ;\n       \
    \ if (l == -1) l = 0;\n        for (int t = 1, v = 1<<(k-1), wi = k; v > 0; t\
    \ <<= 1, v >>= 1, wi -= 1){\n            mint ww = 1;\n            int pl = 1<<wi;\n\
    \            for (int j = 0; j < v; j++, ww *= wm[wi]){\n                int j0\
    \ = l+j, j1 = j0+v;\n                for (int i = 0; i < t; i++, j0 += pl, j1\
    \ += pl){\n                    mint a1 = a[j1];\n                    a[j1] = (a[j0]\
    \ - a1) * ww;\n                    a[j0] += a1;\n                }\n         \
    \   }\n        }\n    }\n    void ifft2(vector<mint> &a, int k, int l = -1){\n\
    \        if (k <= 0 || a.empty()) return ;\n        if (l == -1) l = 0;\n    \
    \    for (int v = 1, t = 1<<(k-1), wi = 1; t > 0; v <<= 1, t >>= 1, wi += 1){\n\
    \            mint ww = 1;\n            int pl = 1<<wi;\n            for (int j\
    \ = 0; j < v; j++, ww *= wp[wi]){\n                int j0 = l+j, j1 = j0+v;\n\
    \                for (int i = 0; i < t; i++, j0 += pl, j1 += pl){\n          \
    \          mint a1 = a[j1] * ww;\n                    a[j1] = a[j0] - a1;\n  \
    \                  a[j0] += a1;\n                }\n            }\n        }\n\
    \    }\n    void fft4(vector<mint> &a, int k, int l = -1){\n        if (k <= 0\
    \ || a.empty()) return ;\n        if (l == -1) l = 0;\n        if (k == 1){\n\
    \            mint a1 = a[l+1];\n            a[l+1] = a[l] - a1;\n            a[l]\
    \ += a1;\n            return ;\n        }\n        if (k & 1){\n            int\
    \ v = 1 << (k - 1);\n            mint ww = 1;\n            for (int i = 0; i <\
    \ v; i++, ww *= wm[k]){\n                mint aiv = a[l+i+v];\n              \
    \  a[l+i+v] = (a[l+i] - aiv) * ww;\n                a[l+i]   = a[l+i] + aiv;\n\
    \            }\n        }\n        mint im = wm[2];\n        for (int t = 1 <<\
    \ (k & 1), v = 1 << (k - 2 - (k & 1)), wi = k - (k & 1); v > 0; t <<= 2, v >>=\
    \ 2, wi -= 2){\n            mint ww = 1, xx = 1;\n            int pl = 1 << wi;\n\
    \            for (int j = 0; j < v; j++, ww *= wm[wi], xx = ww * ww){\n      \
    \          int j0 = l+j, j1 = j0 + v, j2 = j1 + v, j3 = j2 + v;\n            \
    \    for (int i = 0; i < t; i++, j0 += pl, j1 += pl, j2 += pl, j3 += pl){\n  \
    \                  mint a0 = a[j0], a1 = a[j1], a2 = a[j2], a3 = a[j3];\n    \
    \                mint a0p2 = a0 + a2, a0m2 = (a0 - a2) * ww;\n               \
    \     mint a1p3 = a1 + a3, a1m3 = (a1 - a3) * im * ww;\n                    a[j0]\
    \ = a0p2 + a1p3, a[j2] = (a0p2 - a1p3) * xx;\n                    a[j1] = a0m2\
    \ + a1m3, a[j3] = (a0m2 - a1m3) * xx;\n                }\n            }\n    \
    \    }\n    }\n    void ifft4(vector<mint> &a, int k, int l = -1){\n        if\
    \ (k <= 0 || a.empty()) return ;\n        if (l == -1) l = 0;\n        if (k ==\
    \ 1){\n            mint a1 = a[l+1];\n            a[l+1] = a[l] - a1;\n      \
    \      a[l+0] += a1;\n            return ;\n        }\n        mint im = wp[2];\n\
    \        for (int v = 1, t = 1 << (k - 2), wi = 2; t > 0; v <<= 2, t >>= 2, wi\
    \ += 2){\n            mint ww = 1, xx = 1;\n            int pl = 1 << wi;\n  \
    \          for (int j = 0; j < v; j++, ww *= wp[wi], xx = ww * ww){\n        \
    \        int j0 = l+j, j1 = j0 + v, j2 = j1 + v, j3 = j2 + v;\n              \
    \  for (int i = 0; i < t; i++, j0 += pl, j1 += pl, j2 += pl, j3 += pl){\n    \
    \                mint a0 = a[j0], a1 = a[j1] * ww, a2 = a[j2] * xx, a3 = a[j3]\
    \ * ww * xx;\n                    mint a0p2 = a0 + a2, a0m2 = a0 - a2;\n     \
    \               mint a1p3 = a1 + a3, a1m3 = (a1 - a3) * im;\n                \
    \    a[j0] = a0p2 + a1p3, a[j2] = a0p2 - a1p3;\n                    a[j1] = a0m2\
    \ + a1m3, a[j3] = a0m2 - a1m3;\n                }\n            }\n        }\n\
    \        if (k & 1){\n            int v = 1 << (k - 1);\n            mint ww =\
    \ 1;\n            for (int i = 0; i < v; i++, ww *= wp[k]){\n                mint\
    \ aiv = a[l+i+v] * ww;\n                a[l+i+v] = a[l+i] - aiv;\n           \
    \     a[l+i] += aiv;\n            }\n        }\n    }\n    void ntt(vector<mint>\
    \ &a) {\n        if ((int)a.size() <= 1) return;\n        fft4(a, 63-countl_zero(a.size()));\n\
    \    }\n    void intt(vector<mint> &a, bool stop = false) {\n        if ((int)a.size()\
    \ <= 1) return;\n        ifft4(a, 63-countl_zero(a.size()));\n        if (stop)\
    \ return ;\n        mint iv = mint(a.size()).inv();\n        for (auto &x : a)\
    \ x *= iv;\n    }\n    vector<mint> multiply(const vector<mint> &a, const vector<mint>\
    \ &b) {\n        int l = a.size() + b.size() - 1;\n        if (min<int>(a.size(),\
    \ b.size()) <= 40){\n            vector<mint> s(l);\n            for (int i =\
    \ 0; i < (int)a.size(); i++) for (int j = 0; j < (int)b.size(); j++) s[i + j]\
    \ += a[i] * b[j];\n            return s;\n        }\n        int k = 2, M = 4;\n\
    \        while (M < l) M <<= 1, ++k;\n        set_ws();\n        vector<mint>\
    \ s(M);\n        for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];\n      \
    \  fft4(s, k);\n        if (a.size() == b.size() && a == b) {\n            for\
    \ (int i = 0; i < M; ++i) s[i] *= s[i];\n        }\n        else {\n         \
    \   vector<mint> t(M);\n            for (int i = 0; i < (int)b.size(); ++i) t[i]\
    \ = b[i];\n            fft4(t, k);\n            for (int i = 0; i < M; ++i) s[i]\
    \ *= t[i];\n        }\n        ifft4(s, k);\n        s.resize(l);\n        mint\
    \ invm = mint(M).inv();\n        for (int i = 0; i < l; ++i) s[i] *= invm;\n \
    \       return s;\n    }\n};\n\n\n} // namespace noya2\n#line 6 \"fps/fps_ntt.hpp\"\
    \n\nnamespace noya2{\n\ntemplate<typename T>\nstruct fps_ntt{\n    using value_type\
    \ = T;\n    static NTT<T> ntt;\n    static vector<T> multiply(const vector<T>\
    \ &a, const vector<T> &b){\n        return ntt.multiply(a,b);\n    }\n    static\
    \ vector<T> inv(const vector<T> &a, int d = -1){\n        const int n = a.size();\n\
    \        if (d == -1) d = n;\n        vector<T> res = {a[0].inv()};\n        for\
    \ (int siz = 1; siz < d; siz <<= 1){\n            vector<T> f(a.begin(),a.begin()+min(n,siz*2)),\
    \ g(res);\n            f.resize(siz*2), g.resize(siz*2);\n            ntt.ntt(f),\
    \ ntt.ntt(g);\n            for (int i = 0; i < siz*2; i++) f[i] *= g[i];\n   \
    \         ntt.intt(f,true);\n            f.erase(f.begin(),f.begin()+siz);\n \
    \           f.resize(siz*2);\n            ntt.ntt(f);\n            for (int i\
    \ = 0; i < siz*2; i++) f[i] *= g[i];\n            ntt.intt(f,true);\n        \
    \    T siz2_inv = T(siz*2).inv(); siz2_inv *= -siz2_inv;\n            for (int\
    \ i = 0; i < siz; i++) f[i] *= siz2_inv;\n            res.insert(res.end(),f.begin(),f.begin()+siz);\n\
    \        }\n        res.resize(d);\n        return res;\n    }\n    static binomial<T>\
    \ bnm;\n    static vector<T> integral(const vector<T> &a){\n        const int\
    \ n = a.size();\n        vector<T> res(n+1);\n        for (int i = 1; i <= n;\
    \ i++) res[i] = a[i-1] * bnm.inv(i);\n        return res;\n    }\n};\ntemplate<typename\
    \ T> NTT<T> fps_ntt<T>::ntt;\ntemplate<typename T> using FPS_ntt = FormalPowerSeries<fps_ntt<T>>;\n\
    \n} // namespace noya2\n\n#line 2 \"fps/sample_point_shift.hpp\"\n\n#line 7 \"\
    fps/sample_point_shift.hpp\"\n\nnamespace noya2{\n\ntemplate<Fps_Info Info>\n\
    requires Modint<typename Info::value_type>\nFormalPowerSeries<Info> sample_point_shift(FormalPowerSeries<Info>\
    \ y, typename Info::value_type t, int m){\n    using fps = FormalPowerSeries<Info>;\n\
    \    using mint = typename Info::value_type;\n    ll T = t.val();\n    int k =\
    \ (int)(y.size()) - 1;\n    if (T <= k){\n        fps ret(m);\n        int ptr\
    \ = 0;\n        for (ll i = T; i <= k && ptr < m; i++){\n            ret[ptr++]\
    \ = y[i];\n        }\n        if (k+1 < T+m){\n            auto suf = sample_point_shift(y,k+1,m-ptr);\n\
    \            for (int i = k+1; i < T+m; i++){\n                ret[ptr++] = suf[i-(k+1)];\n\
    \            }\n        }\n        return ret;\n    }\n    if (T+m > mint::mod()){\n\
    \        auto pref = sample_point_shift(y,T,mint::mod()-T);\n        auto suf\
    \  = sample_point_shift(y,0,m-(int)(pref.size()));\n        copy(suf.begin(),suf.end(),back_inserter(pref));\n\
    \        return pref;\n    }\n    binomial<mint> bnm;\n    fps d(k+1);\n    for\
    \ (int i = 0; i <= k; i++){\n        d[i] = bnm.ifact(i) * bnm.ifact(k-i) * y[i];\n\
    \        if ((k-i)&1) d[i] = -d[i];\n    }\n    vector<mint> fact(m+k+1); fact[0]\
    \ = 1;\n    for (int i = 0; i < m+k; i++) fact[i+1] = fact[i] * (T-k+i);\n   \
    \ fps h(m+k); h[m+k-1] = fact[m+k].inv();\n    for (int i = m+k-1; i >= 1; i--)\
    \ h[i-1] = h[i] * (T-k+i);\n    for (int i = 0; i < m+k; i++) h[i] *= fact[i];\n\
    \    auto dh = d * h;\n    fps ret(m);\n    mint cur = T;\n    for (int i = 1;\
    \ i <= k; i++) cur *= T-i;\n    for (int i = 0; i < m; i++){\n        ret[i] =\
    \ cur * dh[k+i];\n        cur *= T+i+1;\n        cur *= h[i];\n    }\n    return\
    \ ret;\n}\n\n} // namespace noya2\n#line 6 \"test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp\"\
    \nusing mint = modint998244353;\nusing fps = FPS_ntt<mint>;\n\nint main(){\n \
    \   int n, m; in(n,m);\n    mint c; in(c);\n    fps y(n); in(y);\n    out(sample_point_shift(y,c,m));\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../fps/fps_ntt.hpp\"\
    \n#include\"../../fps/sample_point_shift.hpp\"\nusing mint = modint998244353;\n\
    using fps = FPS_ntt<mint>;\n\nint main(){\n    int n, m; in(n,m);\n    mint c;\
    \ in(c);\n    fps y(n); in(y);\n    out(sample_point_shift(y,c,m));\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - fps/fps_ntt.hpp
  - fps/formal_power_series.hpp
  - math/binomial.hpp
  - fps/ntt.hpp
  - utility/modint.hpp
  - math/prime.hpp
  - fps/sample_point_shift.hpp
  isVerificationFile: true
  path: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 18:29:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
- /verify/test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp.html
title: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
---