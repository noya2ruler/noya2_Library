---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/csr.hpp
    title: data_structure/csr.hpp
  - icon: ':question:'
    path: fps/formal_power_series.hpp
    title: fps/formal_power_series.hpp
  - icon: ':question:'
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
  - icon: ':x:'
    path: tree/centroid_decomposition.hpp
    title: tree/centroid_decomposition.hpp
  - icon: ':question:'
    path: tree/simple_tree.hpp
    title: tree/simple_tree.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':x:'
    path: utility/modint4724.hpp
    title: utility/modint4724.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/tree/FrequencyTableofTreeDistance.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"tree/simple_tree.hpp\"\n\n#line\
    \ 2 \"data_structure/csr.hpp\"\n\n#line 4 \"data_structure/csr.hpp\"\n#include<ranges>\n\
    #line 7 \"data_structure/csr.hpp\"\n\nnamespace noya2::internal {\n\ntemplate<class\
    \ E>\nstruct csr {\n    csr () {}\n    csr (int _n) : n(_n) {}\n    csr (int _n,\
    \ int m) : n(_n){\n        start.reserve(m);\n        elist.reserve(m);\n    }\n\
    \    // ACL style constructor (do not have to call build)\n    csr (int _n, const\
    \ std::vector<std::pair<int,E>> &idx_elem) : n(_n), start(_n + 2), elist(idx_elem.size())\
    \ {\n        for (auto &[i, e] : idx_elem){\n            start[i + 2]++;\n   \
    \     }\n        for (int i = 1; i < n; i++){\n            start[i + 2] += start[i\
    \ + 1];\n        }\n        for (auto &[i, e] : idx_elem){\n            elist[start[i\
    \ + 1]++] = e;\n        }\n        prepared = true;\n    }\n    int add(int idx,\
    \ E elem){\n        int eid = start.size();\n        start.emplace_back(idx);\n\
    \        elist.emplace_back(elem);\n        return eid;\n    }\n    void build(){\n\
    \        if (prepared) return ;\n        int m = start.size();\n        std::vector<E>\
    \ nelist(m);\n        std::vector<int> nstart(n + 2, 0);\n        for (int i =\
    \ 0; i < m; i++){\n            nstart[start[i] + 2]++;\n        }\n        for\
    \ (int i = 1; i < n; i++){\n            nstart[i + 2] += nstart[i + 1];\n    \
    \    }\n        for (int i = 0; i < m; i++){\n            nelist[nstart[start[i]\
    \ + 1]++] = elist[i];\n        }\n        swap(elist,nelist);\n        swap(start,nstart);\n\
    \        prepared = true;\n    }\n    const auto operator[](int idx) const {\n\
    \        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    auto operator[](int idx){\n        return std::ranges::subrange(elist.begin()+start[idx],elist.begin()+start[idx+1]);\n\
    \    }\n    const auto operator()(int idx, int l, int r) const {\n        return\
    \ std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    auto operator()(int idx, int l, int r){\n        return std::ranges::subrange(elist.begin()+start[idx]+l,elist.begin()+start[idx]+r);\n\
    \    }\n    int n;\n    std::vector<int> start;\n    std::vector<E> elist;\n \
    \   bool prepared = false;\n};\n\n} // namespace noya2::internal\n#line 5 \"tree/simple_tree.hpp\"\
    \n\nnamespace noya2 {\n\nstruct simple_tree {\n    internal::csr<int> g;\n   \
    \ simple_tree () {}\n    simple_tree (int _n) : g(_n, (_n - 1)*2) {\n        if\
    \ (_n == 1){\n            g.build();\n        }\n    }\n    void add_edge(int\
    \ u, int v){\n        g.add(u, v);\n        int id = g.add(v, u);\n        if\
    \ (id + 1 == (g.n - 1)*2) g.build();\n    }\n    void input(int indexed = 1){\n\
    \        for (int i = 0; i < g.n - 1; i++){\n            int u, v; cin >> u >>\
    \ v;\n            u -= indexed, v -= indexed;\n            add_edge(u, v);\n \
    \       }\n    }\n    void input_parents(int indexed = 1){\n        for (int i\
    \ = 0; i < g.n - 1; i++){\n            int v; cin >> v;\n            v -= indexed;\n\
    \            add_edge(i + 1, v);\n        }\n    }\n    const auto operator[](int\
    \ v) const {\n        return g[v];\n    }\n    auto operator[](int v){\n     \
    \   return g[v];\n    }\n    int size() const {\n        return g.n;\n    }\n\
    };\n\n} // namespace noya2\n#line 2 \"tree/centroid_decomposition.hpp\"\n\n#line\
    \ 4 \"tree/centroid_decomposition.hpp\"\n\nnamespace noya2 {\n\nstd::vector<int>\
    \ centroid_decomposition(const auto &g){\n    int n = g.size();\n    if (n ==\
    \ 0){\n        return {};\n    }\n    std::vector<int> sub(n), order;\n    order.reserve(n);\n\
    \    auto subtree = [&](auto sfs, int v, int f) -> void {\n        sub[v] = 1;\n\
    \        for (int u : g[v]){\n            if (u == f) continue;\n            sfs(sfs,\
    \ u, v);\n            sub[v] += sub[u];\n        }\n    };\n    subtree(subtree,0,-1);\n\
    \    auto fixed_root = [&](auto self, int root, int par, int cur_size) -> void\
    \ {\n        auto dfs = [&](auto sfs, int v, int f, int sz) -> int {\n       \
    \     int heavy = 0, child = -1;\n            for (int u : g[v]){\n          \
    \      if (u == f) continue;\n                if (heavy < sub[u]){\n         \
    \           heavy = sub[u];\n                    child = u;\n                }\n\
    \            }\n            if (heavy > sz/2){\n                int ret = sfs(sfs,\
    \ child, v, sz);\n                sub[v] -= ret;\n                return ret;\n\
    \            }\n            else {\n                order.emplace_back(v);\n \
    \               for (int u : g[v]){\n                    if (u == f) continue;\n\
    \                    self(self, u, v, sub[u]);\n                }\n          \
    \      int ret = sub[v];\n                sub[v] = 0;\n                return\
    \ ret;\n            }\n        };\n        while (cur_size > 0){\n           \
    \ cur_size -= dfs(dfs, root, par, cur_size);\n        }\n    };\n    fixed_root(fixed_root,\
    \ 0, -1, n);\n    return order;\n}\n\nstd::vector<int> centroid_decomposition_tree(const\
    \ auto &g){\n    int n = g.size();\n    if (n == 0){\n        return {};\n   \
    \ }\n    std::vector<int> sub(n), par_tree(n);\n    auto subtree = [&](auto sfs,\
    \ int v, int f) -> void {\n        sub[v] = 1;\n        for (int u : g[v]){\n\
    \            if (u == f) continue;\n            sfs(sfs, u, v);\n            sub[v]\
    \ += sub[u];\n        }\n    };\n    subtree(subtree,0,-1);\n    auto fixed_root\
    \ = [&](auto self, int root, int par, int cur_size, int cpre) -> void {\n    \
    \    auto dfs = [&](auto sfs, int v, int f, int sz) -> int {\n            int\
    \ heavy = 0, child = -1;\n            for (int u : g[v]){\n                if\
    \ (u == f) continue;\n                if (heavy < sub[u]){\n                 \
    \   heavy = sub[u];\n                    child = u;\n                }\n     \
    \       }\n            if (heavy > sz/2){\n                int ret = sfs(sfs,\
    \ child, v, sz);\n                sub[v] -= ret;\n                return ret;\n\
    \            }\n            else {\n                par_tree[v] = cpre;\n    \
    \            for (int u : g[v]){\n                    if (u == f) continue;\n\
    \                    self(self, u, v, sub[u], v);\n                }\n       \
    \         int ret = sub[v];\n                cpre = v;\n                sub[v]\
    \ = 0;\n                return ret;\n            }\n        };\n        while\
    \ (cur_size > 0){\n            cur_size -= dfs(dfs, root, par, cur_size);\n  \
    \      }\n    };\n    fixed_root(fixed_root, 0, -1, n, -1);\n    return par_tree;\n\
    }\n\n} // namespace noya2\n#line 2 \"utility/modint4724.hpp\"\n\n#line 2 \"utility/modint.hpp\"\
    \n\n#line 4 \"utility/modint.hpp\"\n\n#line 2 \"math/prime.hpp\"\n\n#line 4 \"\
    math/prime.hpp\"\nnamespace noya2 {\n\nconstexpr long long safe_mod(long long\
    \ x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n\
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
    \    a.pow(declval<int>());\n};\n\n} // namespace noya2\n#line 4 \"utility/modint4724.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<>\nstruct static_modint<-4724> {\n    static\
    \ constexpr unsigned long long mod(){\n        return m;\n    }\n    static constexpr\
    \ unsigned long long cal_mod(unsigned long long x){\n        unsigned long long\
    \ xu = x >> 47;\n        unsigned long long xd = x & MASK47;\n        unsigned\
    \ long long res = (xu << 24) + xd - xu;\n        if (res >= m) res -= m;\n   \
    \     return res;\n    }\n    constexpr static_modint() : _v(0) {}\n    constexpr\
    \ static_modint(long long x){\n        if (x < 0){\n            _v = cal_mod(-x);\n\
    \            if (_v != 0){\n                _v = m - _v;\n            }\n    \
    \    }\n        else {\n            _v = cal_mod(x);\n        }\n    }\n    constexpr\
    \ static_modint(unsigned long long x){\n        _v = cal_mod(x);\n    }\n    template<std::signed_integral\
    \ T>\n    constexpr static_modint(T x) : static_modint((long long)x) {}\n    template<std::unsigned_integral\
    \ T>\n    constexpr static_modint(T x) : static_modint((unsigned long long)x)\
    \ {}\n    \n    using modint4724 = static_modint;\n    constexpr modint4724 &operator+=(const\
    \ modint4724 &p){\n        _v += p._v;\n        if (_v >= m) _v -= m;\n      \
    \  return *this;\n    }\n    constexpr modint4724 &operator-=(const modint4724\
    \ &p){\n        _v += m - p._v;\n        if (_v >= m) _v -= m;\n        return\
    \ *this;\n    }\n    constexpr modint4724 &operator*=(const modint4724 &p){\n\
    \        unsigned long long a = _v, b = p._v;\n        unsigned long long au =\
    \ a >> 24, ad = a & MASK24;\n        unsigned long long bu = b >> 24, bd = b &\
    \ MASK24;\n        unsigned long long X = (au + ad) * (bu + bd);\n        unsigned\
    \ long long Y = ad * bd;\n        unsigned long long Z = au * bu;\n        unsigned\
    \ long long A = X - Y + Z, B = Y + m4 - 2*Z;\n        unsigned long long Au =\
    \ A >> 23, Ad = A & MASK23;\n        _v = cal_mod(((Au + Ad) << 24) + B + m -\
    \ Au);\n        return *this;\n    }\n    constexpr modint4724 &operator/=(const\
    \ modint4724 &p){\n        *this *= p.inv();\n        return *this;\n    }\n \
    \   friend constexpr modint4724 operator+(const modint4724 &lhs, const modint4724\
    \ &rhs){\n        return modint4724(lhs) += rhs;\n    }\n    friend constexpr\
    \ modint4724 operator-(const modint4724 &lhs, const modint4724 &rhs){\n      \
    \  return modint4724(lhs) -= rhs;\n    }\n    friend constexpr modint4724 operator*(const\
    \ modint4724 &lhs, const modint4724 &rhs){\n        return modint4724(lhs) *=\
    \ rhs;\n    }\n    friend constexpr modint4724 operator/(const modint4724 &lhs,\
    \ const modint4724 &rhs){\n        return modint4724(lhs) /= rhs;\n    }\n   \
    \ constexpr modint4724 operator+() const {\n        return *this;\n    }\n   \
    \ constexpr modint4724 operator-() const {\n        return modint4724() - *this;\n\
    \    }\n    constexpr modint4724 inv() const {\n        long long a = _v, b =\
    \ m, u = 1, v = 0;\n        while (b > 0){\n            long long t = a / b;\n\
    \            std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n\
    \        }\n        return modint4724(u);\n    }\n    constexpr modint4724 pow(long\
    \ long n) const {\n        modint4724 ret(1ULL), mul(_v);\n        while (n !=\
    \ 0){\n            if (n & 1) ret *= mul;\n            mul *= mul;\n         \
    \   n >>= 1;\n        }\n        return ret;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, modint4724 &p){\n        unsigned long long x;\n        is >> x;\n    \
    \    p = modint4724(x);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const modint4724 &p){\n        return os << p._v;\n    }\n    constexpr\
    \ unsigned long long val() const {\n        return _v;\n    }\n    constexpr auto\
    \ operator<=>(const modint4724 &) const = default;\n\n  private:\n    unsigned\
    \ long long _v;\n    static constexpr unsigned long long m = (1ULL << 47) - (1ULL\
    \ << 24) + 1;\n    static constexpr unsigned long long m4 = m << 2;\n    static\
    \ constexpr unsigned long long MASK23 = (1ULL << 23) - 1;\n    static constexpr\
    \ unsigned long long MASK24 = (1ULL << 24) - 1;\n    static constexpr unsigned\
    \ long long MASK47 = (1ULL << 47) - 1;\n};\nusing modint4724 = static_modint<-4724>;\n\
    \n} // namespace noya2\n#line 2 \"fps/formal_power_series.hpp\"\n\n#line 4 \"\
    fps/formal_power_series.hpp\"\n\nnamespace noya2{\n\ntemplate<typename T>\nconcept\
    \ Field = requires (T a, T b){\n    a + b; a - b; a / b; a * b;\n    T(0); T(1);\n\
    };\n\ntemplate<class Info>\nconcept Fps_Info = requires {\n    typename Info::value_type;\n\
    \    requires Field<typename Info::value_type>;\n    {Info::multiply(declval<vector<typename\
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
    \ noya2\n#line 8 \"test/tree/FrequencyTableofTreeDistance.test.cpp\"\n\nnamespace\
    \ noya2{\n\nconsteval unsigned long long primitive_root_4724(unsigned long long\
    \ p){\n    if (p == modint4724::mod()){\n        return 3;\n    }\n    throw ;\n\
    }\n\ntemplate<Modint mint>\nstruct number_theoretic_transform {\n    static constexpr\
    \ mint pr = primitive_root_4724(mint::mod());\n    static constexpr int level\
    \ = std::countr_zero(mint::mod() - 1);\n    static constexpr std::array<mint,level+1>\
    \ wgen(mint r){\n        std::array<mint,level+1> ret;\n        ret[level] = r;\n\
    \        for (int i = level-1; i >= 0; i--){\n            ret[i] = ret[i+1] *\
    \ ret[i+1];\n        }\n        return ret;\n    }\n    static constexpr std::array<mint,level+1>\
    \ wp = wgen(pr.pow((mint::mod()-1) >> level));\n    static constexpr std::array<mint,level+1>\
    \ wm = wgen(pr.pow((mint::mod()-1) >> level).inv());\n    void fft2(std::vector<mint>\
    \ &a){\n        if (a.empty()) return ;\n        int n = a.size();\n        int\
    \ k = std::countr_zero((unsigned int)(n));\n        assert(n == (1 << k));\n \
    \       for (int t = 1, v = 1<<(k-1), wi = k; v > 0; t <<= 1, v >>= 1, wi -= 1){\n\
    \            mint ww = 1;\n            int pl = 1<<wi;\n            for (int j\
    \ = 0; j < v; j++, ww *= wm[wi]){\n                int j0 = j, j1 = j0+v;\n  \
    \              for (int i = 0; i < t; i++, j0 += pl, j1 += pl){\n            \
    \        mint a1 = a[j1];\n                    a[j1] = (a[j0] - a1) * ww;\n  \
    \                  a[j0] += a1;\n                }\n            }\n        }\n\
    \    }\n    void ifft2(std::vector<mint> &a){\n        if (a.empty()) return ;\n\
    \        int n = a.size();\n        int k = std::countr_zero((unsigned int)(n));\n\
    \        assert(n == (1 << k));\n        for (int v = 1, t = 1<<(k-1), wi = 1;\
    \ t > 0; v <<= 1, t >>= 1, wi += 1){\n            mint ww = 1;\n            int\
    \ pl = 1<<wi;\n            for (int j = 0; j < v; j++, ww *= wp[wi]){\n      \
    \          int j0 = j, j1 = j0+v;\n                for (int i = 0; i < t; i++,\
    \ j0 += pl, j1 += pl){\n                    mint a1 = a[j1] * ww;\n          \
    \          a[j1] = a[j0] - a1;\n                    a[j0] += a1;\n           \
    \     }\n            }\n        }\n    }\n    std::vector<mint> multiply(const\
    \ std::vector<mint> &a, const std::vector<mint> &b) {\n        int l = a.size()\
    \ + b.size() - 1;\n        if (min<int>(a.size(), b.size()) <= 40){\n        \
    \    std::vector<mint> s(l);\n            for (int i = 0; i < (int)a.size(); i++)\
    \ for (int j = 0; j < (int)b.size(); j++) s[i + j] += a[i] * b[j];\n         \
    \   return s;\n        }\n        int k = 2, M = 4;\n        while (M < l) M <<=\
    \ 1, ++k;\n        std::vector<mint> s(M);\n        for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n        fft2(s);\n        if (a.size() == b.size() && a ==\
    \ b) {\n            for (int i = 0; i < M; ++i) s[i] *= s[i];\n        }\n   \
    \     else {\n            std::vector<mint> t(M);\n            for (int i = 0;\
    \ i < (int)b.size(); ++i) t[i] = b[i];\n            fft2(t);\n            for\
    \ (int i = 0; i < M; ++i) s[i] *= t[i];\n        }\n        ifft2(s);\n      \
    \  s.resize(l);\n        mint invm = mint(M).inv();\n        for (int i = 0; i\
    \ < l; ++i) s[i] *= invm;\n        return s;\n    }\n};\n\n} // namespace noya2\n\
    \nstruct fps4724info {\n    using value_type = modint4724;\n    using mint = modint4724;\n\
    \    static std::vector<mint> multiply(const std::vector<mint> &a, const std::vector<mint>\
    \ &b){\n        static number_theoretic_transform<mint> ntt;\n        return ntt.multiply(a,b);\n\
    \    }\n    static std::vector<mint> inv(const std::vector<mint> &a, int d = -1){\n\
    \        assert(false);\n    }\n    static std::vector<mint> integral(const std::vector<mint>\
    \ &a){\n        assert(false);\n    }\n};\n\nusing mint = modint4724;\nusing fps\
    \ = FormalPowerSeries<fps4724info>;\n\nint main(){\n    int n; in(n);\n    simple_tree\
    \ g(n);\n    g.input(0);\n    vector<bool> done(n,false);\n    fps ans(n);\n \
    \   for (int ctr : centroid_decomposition(g)){\n        fps f;\n        auto dfs\
    \ = [&](auto sfs, int v, int ff, int d) -> void {\n            for (int u : g[v]){\n\
    \                if (u == ff) continue;\n                if (done[u]) continue;\n\
    \                sfs(sfs,u,v,d+1);\n            }\n            if ((int)f.size()\
    \ <= d){\n                f.resize(d+1);\n            }\n            f[d] += 1;\n\
    \        };\n        fps sum, sq;\n        for (int v : g[ctr]){\n           \
    \ if (done[v]) continue;\n            dfs(dfs,v,ctr,1);\n            sum += f;\n\
    \            sq += f*f;\n            f = {};\n        }\n        ans += (sum*sum\
    \ - sq) / 2;\n        ans += sum;\n        done[ctr] = true;\n    }\n    ans.erase(ans.begin());\n\
    \    out(ans);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../tree/simple_tree.hpp\"\
    \n#include\"../../tree/centroid_decomposition.hpp\"\n#include\"../../utility/modint4724.hpp\"\
    \n#include\"../../fps/formal_power_series.hpp\"\n\nnamespace noya2{\n\nconsteval\
    \ unsigned long long primitive_root_4724(unsigned long long p){\n    if (p ==\
    \ modint4724::mod()){\n        return 3;\n    }\n    throw ;\n}\n\ntemplate<Modint\
    \ mint>\nstruct number_theoretic_transform {\n    static constexpr mint pr = primitive_root_4724(mint::mod());\n\
    \    static constexpr int level = std::countr_zero(mint::mod() - 1);\n    static\
    \ constexpr std::array<mint,level+1> wgen(mint r){\n        std::array<mint,level+1>\
    \ ret;\n        ret[level] = r;\n        for (int i = level-1; i >= 0; i--){\n\
    \            ret[i] = ret[i+1] * ret[i+1];\n        }\n        return ret;\n \
    \   }\n    static constexpr std::array<mint,level+1> wp = wgen(pr.pow((mint::mod()-1)\
    \ >> level));\n    static constexpr std::array<mint,level+1> wm = wgen(pr.pow((mint::mod()-1)\
    \ >> level).inv());\n    void fft2(std::vector<mint> &a){\n        if (a.empty())\
    \ return ;\n        int n = a.size();\n        int k = std::countr_zero((unsigned\
    \ int)(n));\n        assert(n == (1 << k));\n        for (int t = 1, v = 1<<(k-1),\
    \ wi = k; v > 0; t <<= 1, v >>= 1, wi -= 1){\n            mint ww = 1;\n     \
    \       int pl = 1<<wi;\n            for (int j = 0; j < v; j++, ww *= wm[wi]){\n\
    \                int j0 = j, j1 = j0+v;\n                for (int i = 0; i < t;\
    \ i++, j0 += pl, j1 += pl){\n                    mint a1 = a[j1];\n          \
    \          a[j1] = (a[j0] - a1) * ww;\n                    a[j0] += a1;\n    \
    \            }\n            }\n        }\n    }\n    void ifft2(std::vector<mint>\
    \ &a){\n        if (a.empty()) return ;\n        int n = a.size();\n        int\
    \ k = std::countr_zero((unsigned int)(n));\n        assert(n == (1 << k));\n \
    \       for (int v = 1, t = 1<<(k-1), wi = 1; t > 0; v <<= 1, t >>= 1, wi += 1){\n\
    \            mint ww = 1;\n            int pl = 1<<wi;\n            for (int j\
    \ = 0; j < v; j++, ww *= wp[wi]){\n                int j0 = j, j1 = j0+v;\n  \
    \              for (int i = 0; i < t; i++, j0 += pl, j1 += pl){\n            \
    \        mint a1 = a[j1] * ww;\n                    a[j1] = a[j0] - a1;\n    \
    \                a[j0] += a1;\n                }\n            }\n        }\n \
    \   }\n    std::vector<mint> multiply(const std::vector<mint> &a, const std::vector<mint>\
    \ &b) {\n        int l = a.size() + b.size() - 1;\n        if (min<int>(a.size(),\
    \ b.size()) <= 40){\n            std::vector<mint> s(l);\n            for (int\
    \ i = 0; i < (int)a.size(); i++) for (int j = 0; j < (int)b.size(); j++) s[i +\
    \ j] += a[i] * b[j];\n            return s;\n        }\n        int k = 2, M =\
    \ 4;\n        while (M < l) M <<= 1, ++k;\n        std::vector<mint> s(M);\n \
    \       for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];\n        fft2(s);\n\
    \        if (a.size() == b.size() && a == b) {\n            for (int i = 0; i\
    \ < M; ++i) s[i] *= s[i];\n        }\n        else {\n            std::vector<mint>\
    \ t(M);\n            for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n  \
    \          fft2(t);\n            for (int i = 0; i < M; ++i) s[i] *= t[i];\n \
    \       }\n        ifft2(s);\n        s.resize(l);\n        mint invm = mint(M).inv();\n\
    \        for (int i = 0; i < l; ++i) s[i] *= invm;\n        return s;\n    }\n\
    };\n\n} // namespace noya2\n\nstruct fps4724info {\n    using value_type = modint4724;\n\
    \    using mint = modint4724;\n    static std::vector<mint> multiply(const std::vector<mint>\
    \ &a, const std::vector<mint> &b){\n        static number_theoretic_transform<mint>\
    \ ntt;\n        return ntt.multiply(a,b);\n    }\n    static std::vector<mint>\
    \ inv(const std::vector<mint> &a, int d = -1){\n        assert(false);\n    }\n\
    \    static std::vector<mint> integral(const std::vector<mint> &a){\n        assert(false);\n\
    \    }\n};\n\nusing mint = modint4724;\nusing fps = FormalPowerSeries<fps4724info>;\n\
    \nint main(){\n    int n; in(n);\n    simple_tree g(n);\n    g.input(0);\n   \
    \ vector<bool> done(n,false);\n    fps ans(n);\n    for (int ctr : centroid_decomposition(g)){\n\
    \        fps f;\n        auto dfs = [&](auto sfs, int v, int ff, int d) -> void\
    \ {\n            for (int u : g[v]){\n                if (u == ff) continue;\n\
    \                if (done[u]) continue;\n                sfs(sfs,u,v,d+1);\n \
    \           }\n            if ((int)f.size() <= d){\n                f.resize(d+1);\n\
    \            }\n            f[d] += 1;\n        };\n        fps sum, sq;\n   \
    \     for (int v : g[ctr]){\n            if (done[v]) continue;\n            dfs(dfs,v,ctr,1);\n\
    \            sum += f;\n            sq += f*f;\n            f = {};\n        }\n\
    \        ans += (sum*sum - sq) / 2;\n        ans += sum;\n        done[ctr] =\
    \ true;\n    }\n    ans.erase(ans.begin());\n    out(ans);\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - tree/simple_tree.hpp
  - data_structure/csr.hpp
  - tree/centroid_decomposition.hpp
  - utility/modint4724.hpp
  - utility/modint.hpp
  - math/prime.hpp
  - fps/formal_power_series.hpp
  isVerificationFile: true
  path: test/tree/FrequencyTableofTreeDistance.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 19:06:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/FrequencyTableofTreeDistance.test.cpp
layout: document
redirect_from:
- /verify/test/tree/FrequencyTableofTreeDistance.test.cpp
- /verify/test/tree/FrequencyTableofTreeDistance.test.cpp.html
title: test/tree/FrequencyTableofTreeDistance.test.cpp
---
