---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: data_structure/lazy_segment_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n\
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
    ~ (. _________ . /)\u3000*/\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"data_structure/lazy_segment_tree.hpp\"\
    \n\n#line 4 \"data_structure/lazy_segment_tree.hpp\"\n\nnamespace noya2{\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F,\
    \ F), F (*id)()>\nstruct lazy_segtree {\n  public:\n    lazy_segtree() : lazy_segtree(0)\
    \ {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n    lazy_segtree(const\
    \ std::vector<S>& v) : _n(int(v.size())) {\n        log = 0;\n        size = 1;\n\
    \        while (size < _n) size <<= 1, log++;\n        d = std::vector<S>(2 *\
    \ size, e());\n        lz = std::vector<F>(size, id());\n        for (int i =\
    \ 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n    void set(int p, S x) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n    S get(int p) {\n        assert(0 <= p\
    \ && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return d[p];\n    }\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return e();\n        l += size,\
    \ r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if (((l\
    \ >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push(r\
    \ >> i);\n        }\n\n        S sml = e(), smr = e();\n        while (l < r)\
    \ {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    S all_prod() { return d[1]; }\n    void\
    \ apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = mapping(f,\
    \ d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    void\
    \ apply(int l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n \
    \       if (l == r) return;\n        l += size, r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n      \
    \  {\n            int l2 = l, r2 = r;\n            while (l < r) {\n         \
    \       if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2, r = r2;\n        }\n        for (int i = 1; i <= log; i++) {\n\
    \            if (((l >> i) << i) != l) update(l >> i);\n            if (((r >>\
    \ i) << i) != r) update((r - 1) >> i);\n        }\n    }\n    template <bool (*g)(S)>\
    \ int max_right(int l) {\n        return max_right(l, [](S x) { return g(x); });\n\
    \    }\n    template <class G> int max_right(int l, G g) {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(g(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n   \
    \     S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n   \
    \         if (!g(op(sm, d[l]))) {\n                while (l < size) {\n      \
    \              push(l);\n                    l = (2 * l);\n                  \
    \  if (g(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n      \
    \                  l++;\n                    }\n                }\n          \
    \      return l - size;\n            }\n            sm = op(sm, d[l]);\n     \
    \       l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n  \
    \  template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r, [](S\
    \ x) { return g(x); });\n    }\n    template <class G> int min_left(int r, G g)\
    \ {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n        if (r\
    \ == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n \
    \           while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n  private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n};\n\n} // namespace noya2\n#line 2 \"utility/modint.hpp\"\
    \n\n// AtCoderLibrary \u3092\u305D\u306E\u307E\u307E\u30D1\u30AF\u3063\u3066\u3044\
    \u308B \u306A\u306B\u3082\u308F\u304B\u3063\u3066\u3044\u306A\u3044\n// \\( x\
    \ _______ x) ~\n\n#line 8 \"utility/modint.hpp\"\n#include <type_traits>\n#line\
    \ 10 \"utility/modint.hpp\"\n\nnamespace noya2 {\n\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\n\nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n\n  \
    \  explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m +\
    \ 1) {}\n\n    unsigned int umod() const { return _m; }\n\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        unsigned long long z = a;\n        z\
    \ *= b;\n#ifdef _MSC_VER\n        unsigned long long x;\n        _umul128(z, im,\
    \ &x);\n#else\n        unsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n#endif\n        unsigned int v = (unsigned int)(z\
    \ - x * _m);\n        if (_m <= v) v += _m;\n        return v;\n    }\n};\n\n\
    constexpr long long pow_mod_constexpr(long long x, long long n, int m) {\n   \
    \ if (m == 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned\
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
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    long long\
    \ s = b, t = a;\n    long long m0 = 0, m1 = 1;\n\n    while (t) {\n        long\
    \ long u = s / t;\n        s -= t * u;\n        m0 -= m1 * u; \n\n        auto\
    \ tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 =\
    \ m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n    return {s,\
    \ m0};\n}\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2)\
    \ return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return\
    \ 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n\
    \    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x = (m -\
    \ 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n}  // namespace noya2\n\nnamespace noya2 {\n\
    \n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value || std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 = typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value || std::is_same<T, unsigned __int128>::value, std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128 =\
    \ typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ || is_signed_int128<T>::value || is_unsigned_int128<T>::value, std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_signed_int = typename\
    \ std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || is_signed_int128<T>::value,\
    \ std::true_type, std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int\
    \ = typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value)\
    \ || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\n\n\
    template <class T>\nusing to_unsigned = typename std::conditional<is_signed_int128<T>::value,\
    \ make_unsigned_int128<T>, typename std::conditional<std::is_signed<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type>::type;\n\n#else\n\ntemplate\
    \ <class T> using is_integral = typename std::is_integral<T>;\n\ntemplate <class\
    \ T>\nusing is_signed_int = typename std::conditional<is_integral<T>::value &&\
    \ std::is_signed<T>::value, std::true_type, std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int = typename std::conditional<is_integral<T>::value\
    \ && std::is_unsigned<T>::value, std::true_type, std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing to_unsigned = typename std::conditional<is_signed_int<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type;\n\n#endif\n\ntemplate <class\
    \ T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace noya2\n\nnamespace noya2 {\n\nstruct modint_base {};\nstruct static_modint_base\
    \ : modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace noya2\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : noya2::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, noya2::is_signed_int_t<T>* = nullptr>\n \
    \   static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, noya2::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = noya2::inv_gcd(_v, m);\n      \
    \      assert(eg.first == 1);\n            return eg.second;\n        }\n    }\n\
    \n    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr\
    \ unsigned int umod() { return m; }\n    static constexpr bool prime = noya2::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : noya2::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = noya2::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, noya2::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n      \
    \  long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x +=\
    \ mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, noya2::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = noya2::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint& p) {\n       \
    \ return os << p.val();\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        long long t; is >> t;\n        a = mint(t);\n     \
    \   return (is);\n    }\n\n  private:\n    unsigned int _v;\n    static noya2::barrett\
    \ bt;\n    static unsigned int umod() { return bt.umod(); }\n};\ntemplate <int\
    \ id> noya2::barrett dynamic_modint<id>::bt(998244353);\n\nusing modint998244353\
    \ = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n\nnamespace noya2 {\n\ntemplate <class T>\n\
    using is_static_modint = std::is_base_of<noya2::static_modint_base, T>;\n\ntemplate\
    \ <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace noya2\n#line 6 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n\nusing mint = modint998244353;\nusing pmm = pair<mint,mint>;\n\npmm op(pmm\
    \ a, pmm b){\n    return pmm(a.first+b.first,a.second+b.second);\n}\npmm e(){\n\
    \    return pmm(0,0);\n}\npmm mapping(pmm f, pmm x){\n    return pmm(x.first*f.first\
    \ + x.second*f.second, x.second);\n}\npmm composition(pmm f, pmm g){\n    return\
    \ pmm(f.first*g.first,f.first*g.second+f.second);\n}\npmm ideal(){\n    return\
    \ pmm(1,0);\n}\n\nint main(){\n    int n, q; in(n,q);\n    lazy_segtree<pmm,op,e,pmm,mapping,composition,ideal>\
    \ seg([&]{\n        vector<pmm> a(n);\n        rep(i,n){\n            ll x; in(x);\n\
    \            a[i] = pmm(x,1);\n        }\n        return a;\n    }());\n    while\
    \ (q--){\n        int t; in(t);\n        if (t == 0){\n            int l, r, b,\
    \ c; in(l,r,b,c);\n            seg.apply(l,r,pmm(b,c));\n        }\n        else\
    \ {\n            int l, r; in(l,r);\n            out(seg.prod(l,r).first.val());\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../data_structure/lazy_segment_tree.hpp\"\
    \n#include\"../../utility/modint.hpp\"\n\nusing mint = modint998244353;\nusing\
    \ pmm = pair<mint,mint>;\n\npmm op(pmm a, pmm b){\n    return pmm(a.first+b.first,a.second+b.second);\n\
    }\npmm e(){\n    return pmm(0,0);\n}\npmm mapping(pmm f, pmm x){\n    return pmm(x.first*f.first\
    \ + x.second*f.second, x.second);\n}\npmm composition(pmm f, pmm g){\n    return\
    \ pmm(f.first*g.first,f.first*g.second+f.second);\n}\npmm ideal(){\n    return\
    \ pmm(1,0);\n}\n\nint main(){\n    int n, q; in(n,q);\n    lazy_segtree<pmm,op,e,pmm,mapping,composition,ideal>\
    \ seg([&]{\n        vector<pmm> a(n);\n        rep(i,n){\n            ll x; in(x);\n\
    \            a[i] = pmm(x,1);\n        }\n        return a;\n    }());\n    while\
    \ (q--){\n        int t; in(t);\n        if (t == 0){\n            int l, r, b,\
    \ c; in(l,r,b,c);\n            seg.apply(l,r,pmm(b,c));\n        }\n        else\
    \ {\n            int l, r; in(l,r);\n            out(seg.prod(l,r).first.val());\n\
    \        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - data_structure/lazy_segment_tree.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 19:55:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/data_structure/Range_Affine_Range_Sum.test.cpp
---