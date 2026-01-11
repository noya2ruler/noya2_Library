---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_segment_tree.hpp
    title: data_structure/dynamic_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
  - icon: ':question:'
    path: template/const.hpp
    title: template/const.hpp
  - icon: ':question:'
    path: template/inout_old.hpp
    title: template/inout_old.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/dynamic_segment_tree.hpp\"\
    \n\n#line 4 \"data_structure/dynamic_segment_tree.hpp\"\n\nnamespace noya2{\n\n\
    template<class S, S(*op)(S, S), S(*e)()>\nstruct dynamic_segtree {\n    struct\
    \ Node;\n    using Ptr = shared_ptr<Node>;\n    struct Node {\n        S val;\n\
    \        Ptr lch, rch, par;\n        Node (Ptr par_ = nullptr) : val(e()), lch(nullptr),\
    \ rch(nullptr), par(par_) {}\n    };\n    Ptr root;\n    ll n;\n    dynamic_segtree\
    \ (ll n_ = 0) : n(2){\n        while (n < n_) n <<= 1;\n        root = make_shared<Node>();\n\
    \    }\n    void set(ll idx, S val_){\n        assert(0 <= idx && idx < n);\n\
    \        ll le = 0, ri = n;\n        Ptr cur = root;\n        while (ri - le >\
    \ 1){\n            ll md = (le + ri) / 2;\n            if (idx < md){\n      \
    \          if (cur->lch == nullptr) cur->lch = make_shared<Node>(cur);\n     \
    \           cur = cur->lch;\n                ri = md;\n            }\n       \
    \     else {\n                if (cur->rch == nullptr) cur->rch = make_shared<Node>(cur);\n\
    \                cur = cur->rch;\n                le = md;\n            }\n  \
    \      }\n        cur->val = val_;\n        while (cur->par){\n            cur\
    \ = cur->par;\n            cur->val = op(get(cur->lch),get(cur->rch));\n     \
    \   }\n    }\n    S prod(ll lid, ll rid){\n        assert(0 <= lid && lid <= rid\
    \ && rid <= n);\n        if (lid == rid) return e();\n        Ptr cur = root;\n\
    \        ll le = 0, ri = n;\n        while (ri - le > 1){\n            ll md =\
    \ (le + ri) / 2;\n            if (lid < md && md < rid){\n                if (lid\
    \ == le && rid == ri) return cur->val;\n                return op(prod_l(cur->lch,le,md,lid),prod_r(cur->rch,md,ri,rid));\n\
    \            }\n            if (rid <= md){\n                if (cur->lch == nullptr)\
    \ return e();\n                cur = cur->lch;\n                ri = md;\n   \
    \         }\n            else {\n                if (cur->rch == nullptr) return\
    \ e();\n                cur = cur->rch;\n                le = md;\n          \
    \  }\n        }\n        return cur->val;\n    }\n    S get(Ptr ptr){\n      \
    \  if (ptr) return ptr->val;\n        return e();\n    }\n    S prod_l(Ptr cur,\
    \ ll le, ll ri, ll lid){\n        S prd = e();\n        while (cur){\n       \
    \     ll md = (le + ri) / 2;\n            if (lid == le){\n                prd\
    \ = op(cur->val,prd);\n                break;\n            }\n            if (lid\
    \ < md){\n                prd = op(get(cur->rch),prd);\n                cur =\
    \ cur->lch;\n                ri = md;\n            }\n            else {\n   \
    \             cur = cur->rch;\n                le = md;\n            }\n     \
    \   }\n        return prd;\n    }\n    S prod_r(Ptr cur, ll le, ll ri, ll rid){\n\
    \        S prd = e();\n        while (cur){\n            ll md = (le + ri) / 2;\n\
    \            if (rid == ri){\n                prd = op(prd,cur->val);\n      \
    \          break;\n            }\n            if (rid > md){\n               \
    \ prd = op(prd,get(cur->lch));\n                cur = cur->rch;\n            \
    \    le = md;\n            }\n            else {\n                cur = cur->lch;\n\
    \                ri = md;\n            }\n        }\n        return prd;\n   \
    \ }\n    S all_prod(){\n        return root->val;\n    }\n    S get(ll idx){\n\
    \        assert(0 <= idx && idx < n);\n        ll le = 0, ri = n;\n        Ptr\
    \ cur = root;\n        while (ri - le > 1){\n            ll md = (le + ri) / 2;\n\
    \            if (idx < md){\n                if (cur->lch == nullptr) return e();\n\
    \                cur = cur->lch;\n                ri = md;\n            }\n  \
    \          else {\n                if (cur->rch == nullptr) return e();\n    \
    \            cur = cur->rch;\n                le = md;\n            }\n      \
    \  }\n        return cur->val;\n    }\n};\n\n} // namespace noya2\n#line 2 \"\
    utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\n\n#line 2 \"math/prime.hpp\"\
    \n\n#line 4 \"math/prime.hpp\"\nnamespace noya2 {\n\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\n\nconstexpr long long pow_mod_constexpr(long long x, long long n, int m) {\n\
    \    if (m == 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned\
    \ long long r = 1;\n    unsigned long long y = safe_mod(x, m);\n    while (n)\
    \ {\n        if (n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n       \
    \ n >>= 1;\n    }\n    return r;\n}\n\nconstexpr bool is_prime_constexpr(int n)\
    \ {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
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
    };\n\n} // namespace noya2\n#line 6 \"test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp\"\
    \nusing mint = modint998244353;\nusing pmm = pair<mint,mint>;\n\npmm op(pmm a,\
    \ pmm b){\n    return pmm(a.first*b.first,a.second*b.first+b.second);\n}\npmm\
    \ e(){\n    return pmm(1,0);\n}\n\nint main(){\n    int n, q; in(n,q);\n    dynamic_segtree<pmm,op,e>\
    \ seg(n);\n    rep(i,n){\n        mint a, b; in(a,b);\n        seg.set(i,pmm(a,b));\n\
    \    }\n    while (q--){\n        int t; in(t);\n        if (t == 0){\n      \
    \      int p, c, d; in(p,c,d);\n            seg.set(p,pmm(c,d));\n        }\n\
    \        if (t == 1){\n            int l, r, x; in(l,r,x);\n            auto [a,\
    \ b] = seg.prod(l,r);\n            out(a*x+b);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../data_structure/dynamic_segment_tree.hpp\"\
    \n#include\"../../utility/modint.hpp\"\nusing mint = modint998244353;\nusing pmm\
    \ = pair<mint,mint>;\n\npmm op(pmm a, pmm b){\n    return pmm(a.first*b.first,a.second*b.first+b.second);\n\
    }\npmm e(){\n    return pmm(1,0);\n}\n\nint main(){\n    int n, q; in(n,q);\n\
    \    dynamic_segtree<pmm,op,e> seg(n);\n    rep(i,n){\n        mint a, b; in(a,b);\n\
    \        seg.set(i,pmm(a,b));\n    }\n    while (q--){\n        int t; in(t);\n\
    \        if (t == 0){\n            int p, c, d; in(p,c,d);\n            seg.set(p,pmm(c,d));\n\
    \        }\n        if (t == 1){\n            int l, r, x; in(l,r,x);\n      \
    \      auto [a, b] = seg.prod(l,r);\n            out(a*x+b);\n        }\n    }\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/dynamic_segment_tree.hpp
  - utility/modint.hpp
  - math/prime.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-02-26 00:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
- /verify/test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp.html
title: test/data_structure/Point_Set_Range_Composite_dynamic_segment_tree.test.cpp
---
