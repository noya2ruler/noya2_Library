---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: math/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: math/euler_circuit_counting.hpp
    title: math/euler_circuit_counting.hpp
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/spanning_tree_counting.hpp
    title: math/spanning_tree_counting.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/counting_eulerian_circuits
    links:
    - https://judge.yosupo.jp/problem/counting_eulerian_circuits
  bundledCode: "#line 1 \"test/math/CountingEulerianCircuits.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/counting_eulerian_circuits\"\n\n#line 2 \"\
    template/template.hpp\"\nusing namespace std;\n\n#include<bits/stdc++.h>\n#line\
    \ 1 \"template/inout_old.hpp\"\nnamespace noya2 {\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const pair<T, U> &p){\n    os << p.first\
    \ << \" \" << p.second;\n    return os;\n}\ntemplate <typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &p){\n    is >> p.first >> p.second;\n\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"math/euler_circuit_counting.hpp\"\
    \n\n#line 2 \"math/spanning_tree_counting.hpp\"\n\n#line 2 \"math/matrix.hpp\"\
    \n\n#line 6 \"math/matrix.hpp\"\n#include <ranges>\n#line 8 \"math/matrix.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<typename T, size_t hw = -1uz>\nstruct matrix\
    \ {\n    static constexpr int h = hw, w = hw;\n    std::array<T, hw*hw> m;\n \
    \   matrix () : m({}) {}\n    matrix (const std::array<T, hw*hw> &_m) : m(_m)\
    \ {}\n    matrix (const std::array<std::array<T, hw>, hw> &_m){\n        for (int\
    \ i = 0; i < h; i++) for (int j = 0; j < w; j++){\n            m[idx(i,j)] = _m[i][j];\n\
    \        }\n    }\n    matrix (const std::vector<std::vector<T>> &_m){\n     \
    \   for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){\n            m[idx(i,j)]\
    \ = _m[i][j];\n        }\n    }\n    auto operator[](int i) const {\n        return\
    \ std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);\n    }\n    auto operator[](int\
    \ i){\n        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);\n\
    \    }\n    matrix &operator+= (const matrix &r){\n        for (int i = 0; i <\
    \ h; ++i){\n            for (int j = 0; j < w; ++j){\n                m[idx(i,j)]\
    \ += r.m[idx(i,j)];\n            }\n        }\n        return *this;\n    }\n\
    \    matrix &operator-= (const matrix &r){\n        for (int i = 0; i < h; ++i){\n\
    \            for (int j = 0; j < w; ++j){\n                m[idx(i,j)] -= r.m[idx(i,j)];\n\
    \            }\n        }\n        return *this;\n    }\n    matrix &operator*=\
    \ (const matrix &r){\n        matrix ret;\n        for (int i = 0; i < h; i++){\n\
    \            for (int k = 0; k < w; k++){\n                for (int j = 0; j <\
    \ r.w; j++){\n                    ret.m[idx(i,j)] += m[idx(i,k)] * r.m[idx(k,j)];\n\
    \                }\n            }\n        }\n        return *this = ret;\n  \
    \  }\n    matrix operator+ (const matrix &r) const { return matrix(*this) += r;\
    \ }\n    matrix operator- (const matrix &r) const { return matrix(*this) -= r;\
    \ }\n    matrix operator* (const matrix &r) const { return matrix(*this) *= r;\
    \ }\n    matrix& operator*=(const T &r){\n        for (int i = 0; i < h; ++i){\n\
    \            for (int j = 0; j < w; ++j){\n                m[idx(i,j)] *= r;\n\
    \            }\n        }\n        return *this;\n    }\n    friend matrix operator*\
    \ (const T &r, const matrix &mat){\n        return matrix(mat) *= r;\n    }\n\
    \    friend matrix operator* (const matrix &mat, const T &r){\n        return\
    \ matrix(mat) *= r;\n    }\n    matrix pow(long long n){\n        if (n == 0)\
    \ return e();\n        matrix f = pow(n / 2);\n        matrix ret = f * f;\n \
    \       if (n & 1) ret *= (*this);\n        return ret;\n    }\n    int idx(int\
    \ i, int j){\n        return i * w + j;\n    }\n    static matrix e(){\n     \
    \   matrix ret;\n        for (int i = 0; i < h; i++){\n            ret[i][i] =\
    \ T(1);\n        }\n        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const matrix &mat){\n        for (int i = 0; i < mat.h; i++){\n       \
    \     if (i != 0) os << '\\n';\n            for (int j = 0; j < mat.w; j++){\n\
    \                if (j != 0) os << ' ';\n                os << mat[i][j];\n  \
    \          }\n        }\n        return os;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, matrix &mat){\n        for (int i = 0; i < mat.h; i++){\n            for\
    \ (int j = 0; j < mat.w; j++){\n                is >> mat[i][j];\n           \
    \ }\n        }\n        return is;\n    }\n    friend bool operator==(const matrix\
    \ &a, const matrix &b){\n        for (int i = 0; i < a.h; i++){\n            for\
    \ (int j = 0; j < a.w; j++){\n                if (a[i][j] != b[i][j]){\n     \
    \               return false;\n                }\n            }\n        }\n \
    \       return true;\n    }\n};\n\ntemplate<typename T>\nstruct matrix<T,-1uz>\
    \ {\n    int h, w;\n    std::vector<T> m;\n    matrix () {}\n    matrix (int _h)\
    \ : matrix(_h,_h) {}\n    matrix (int _h, int _w) : h(_h), w(_w), m(_h*_w) {}\n\
    \    matrix (int _h, int _w, const std::vector<T> &_m) : h(_h), w(_w), m(_m) {\n\
    \        assert((int)_m.size() == _h*_w);\n    }\n    matrix (const std::vector<std::vector<T>>\
    \ &_m){\n        h = _m.size();\n        assert(h >= 1);\n        w = _m[0].size();\n\
    \        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){\n          \
    \  m[idx(i,j)] = _m[i][j];\n        }\n    }\n    auto operator[](int i) const\
    \ {\n        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);\n\
    \    }\n    auto operator[](int i){\n        return std::ranges::subrange(m.begin()+i*w,m.begin()+(i+1)*w);\n\
    \    }\n    matrix &operator+= (const matrix &r){\n        for (int i = 0; i <\
    \ h; ++i){\n            for (int j = 0; j < w; ++j){\n                m[idx(i,j)]\
    \ += r.m[idx(i,j)];\n            }\n        }\n        return *this;\n    }\n\
    \    matrix &operator-= (const matrix &r){\n        for (int i = 0; i < h; ++i){\n\
    \            for (int j = 0; j < w; ++j){\n                m[idx(i,j)] -= r.m[idx(i,j)];\n\
    \            }\n        }\n        return *this;\n    }\n    matrix &operator*=\
    \ (const matrix &r){\n        matrix ret(h, r.w);\n        for (int i = 0; i <\
    \ h; i++){\n            for (int k = 0; k < w; k++){\n                for (int\
    \ j = 0; j < r.w; j++){\n                    ret.m[idx(i,j)] += m[idx(i,k)] *\
    \ r.m[idx(k,j)];\n                }\n            }\n        }\n        return\
    \ *this = ret;\n    }\n    matrix operator+ (const matrix &r) const { return matrix(*this)\
    \ += r; }\n    matrix operator- (const matrix &r) const { return matrix(*this)\
    \ -= r; }\n    matrix operator* (const matrix &r) const { return matrix(*this)\
    \ *= r; }\n    matrix& operator*=(const T &r){\n        for (int i = 0; i < h;\
    \ ++i){\n            for (int j = 0; j < w; ++j){\n                m[idx(i,j)]\
    \ *= r;\n            }\n        }\n        return *this;\n    }\n    friend matrix\
    \ operator* (const T &r, const matrix &mat){\n        return matrix(mat) *= r;\n\
    \    }\n    friend matrix operator* (const matrix &mat, const T &r){\n       \
    \ return matrix(mat) *= r;\n    }\n    matrix pow(long long n){\n        if (n\
    \ == 0) return e(h);\n        matrix f = pow(n / 2);\n        matrix ret = f *\
    \ f;\n        if (n & 1) ret *= (*this);\n        return ret;\n    }\n    int\
    \ idx(int i, int j){\n        return i * w + j;\n    }\n    static matrix e(int\
    \ _h){\n        auto ret = matrix(_h, _h);\n        for (int i = 0; i < _h; i++){\n\
    \            ret[i][i] = T(1);\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const matrix &mat){\n        for\
    \ (int i = 0; i < mat.h; i++){\n            if (i != 0) os << '\\n';\n       \
    \     for (int j = 0; j < mat.w; j++){\n                if (j != 0) os << ' ';\n\
    \                os << mat[i][j];\n            }\n        }\n        return os;\n\
    \    }\n    friend std::istream &operator>>(std::istream &is, matrix &mat){\n\
    \        for (int i = 0; i < mat.h; i++){\n            for (int j = 0; j < mat.w;\
    \ j++){\n                is >> mat[i][j];\n            }\n        }\n        return\
    \ is;\n    }\n};\n\ntemplate<typename T, size_t _hw = -1uz>\nT determinant(matrix<T,\
    \ _hw> mat){\n    int hw = mat.h;\n    T ret = 1;\n    for (int i = 0; i < hw;\
    \ i++) {\n        int idx = -1;\n        for (int j = i; j < hw; j++) {\n    \
    \        if (mat[j][i] != 0) {\n                idx = j;\n                break;\n\
    \            }\n        }\n        if (idx == -1) return 0;\n        if (i !=\
    \ idx) {\n            ret *= T(-1);\n            for (int j = 0; j < hw; j++){\n\
    \                std::swap(mat[i][j],mat[idx][j]);\n            }\n        }\n\
    \        ret *= mat[i][i];\n        T inv = T(1) / mat[i][i];\n        for (int\
    \ j = 0; j < hw; j++) {\n            mat[i][j] *= inv;\n        }\n        for\
    \ (int j = i + 1; j < hw; j++) {\n            T a = mat[j][i];\n            if\
    \ (a == 0) continue;\n            for (int k = i; k < hw; k++) {\n           \
    \     mat[j][k] -= mat[i][k] * a;\n            }\n        }\n    }\n    return\
    \ ret;\n}\n\n} // namespace noya2\n#line 4 \"math/spanning_tree_counting.hpp\"\
    \n\nnamespace noya2 {\n\ntemplate<typename T>\nT directed_spanning_tree_counting(int\
    \ n, const std::vector<std::tuple<int,int,T>> &es){\n    matrix<T> mat(n-1,n-1);\n\
    \    for (auto [u, v, c] : es){\n        if (u < n-1 && v < n-1){\n          \
    \  mat[u][v] -= c;\n        }\n        if (v < n-1){\n            mat[v][v] +=\
    \ c;\n        }\n    }\n    return determinant(mat);\n}\n\ntemplate<typename T>\n\
    T undirected_spanning_tree_counting(int n, const std::vector<std::tuple<int,int,T>>\
    \ &es){\n    matrix<T> mat(n-1,n-1);\n    for (auto [u, v, c] : es){\n       \
    \ if (u < n-1 && v < n-1){\n            mat[u][v] -= c;\n            mat[v][u]\
    \ -= c;\n        }\n        if (v < n-1){\n            mat[v][v] += c;\n     \
    \   }\n        if (u < n-1){\n            mat[u][u] += c;\n        }\n    }\n\
    \    return determinant(mat);\n}\n\n} // namespace noya2\n#line 2 \"math/binomial.hpp\"\
    \n\n#line 4 \"math/binomial.hpp\"\nnamespace noya2 {\n\ntemplate<typename mint>\n\
    struct binomial {\n    binomial(int len = 300000){ extend(len); }\n    static\
    \ mint fact(int n){\n        if (n < 0) return 0;\n        while (n >= (int)_fact.size())\
    \ extend();\n        return _fact[n];\n    }\n    static mint ifact(int n){\n\
    \        if (n < 0) return 0;\n        while (n >= (int)_fact.size()) extend();\n\
    \        return _ifact[n];\n    }\n    static mint inv(int n){\n        return\
    \ ifact(n) * fact(n-1);\n    }\n    static mint C(int n, int r){\n        if (!(0\
    \ <= r && r <= n)) return 0;\n        return fact(n) * ifact(r) * ifact(n-r);\n\
    \    }\n    static mint P(int n, int r){\n        if (!(0 <= r && r <= n)) return\
    \ 0;\n        return fact(n) * ifact(n-r);\n    }\n    inline mint operator()(int\
    \ n, int r) { return C(n, r); }\n    template<class... Cnts>\n    static mint\
    \ M(const Cnts&... cnts){\n        return multinomial(0,1,cnts...);\n    }\n \
    \   static void initialize(int len = 2){\n        _fact.clear();\n        _ifact.clear();\n\
    \        extend(len);\n    }\n  private:\n    static mint multinomial(const int&\
    \ sum, const mint& div_prod){\n        if (sum < 0) return 0;\n        return\
    \ fact(sum) * div_prod;\n    }\n    template<class... Tail>\n    static mint multinomial(const\
    \ int& sum, const mint& div_prod, const int& n1, const Tail&... tail){\n     \
    \   if (n1 < 0) return 0;\n        return multinomial(sum+n1,div_prod*ifact(n1),tail...);\n\
    \    }\n    static inline std::vector<mint> _fact, _ifact;\n    static void extend(int\
    \ len = -1){\n        if (_fact.empty()){\n            _fact = _ifact = {1,1};\n\
    \        }\n        int siz = _fact.size();\n        if (len == -1) len = siz\
    \ * 2;\n        len = (int)min<long long>(len, mint::mod() - 1);\n        if (len\
    \ < siz) return ;\n        _fact.resize(len+1), _ifact.resize(len+1);\n      \
    \  for (int i = siz; i <= len; i++) _fact[i] = _fact[i-1] * i;\n        _ifact[len]\
    \ = _fact[len].inv();\n        for (int i = len; i > siz; i--) _ifact[i-1] = _ifact[i]\
    \ * i;\n    }\n};\n\n} // namespace noya2\n#line 5 \"math/euler_circuit_counting.hpp\"\
    \n\nnamespace noya2 {\n\n// BEST theorem\n// https://en.wikipedia.org/wiki/BEST_theorem\n\
    template<typename T>\nT euler_circuit_counting(int n, const std::vector<std::tuple<int,\
    \ int, long long>> &es){\n    // i_deg == o_deg\n    std::vector<long long> deg(n,0);\n\
    \    for (auto [u, v, c] : es){\n        deg[u] -= c;\n        deg[v] += c;\n\
    \    }\n    for (int i = 0; i < n; i++) if (deg[i] != 0) return T(0);\n    //\
    \ edges are connected\n    int m = es.size();\n    std::vector<bool> vis(n,false);\n\
    \    std::vector<std::vector<int>> g(n);\n    for (auto [u, v, c] : es){\n   \
    \     if (c == 0) continue;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n    for (int s = 0; s < n; s++){\n        if (g[s].empty()) continue;\n\
    \        std::queue<int> que;\n        que.push(s);\n        vis[s] = true;\n\
    \        while (!que.empty()){\n            int v = que.front(); que.pop();\n\
    \            for (int u : g[v]){\n                if (!vis[u]){\n            \
    \        vis[u] = true;\n                    que.push(u);\n                }\n\
    \            }\n        }\n        break;\n    }\n    for (auto [u, v, c] : es){\n\
    \        if (!vis[u]) return T(0);\n    }\n    // directed spanning tree counting\n\
    \    std::vector<int> ids(n);\n    int nonzero = 0;\n    for (int v = 0; v < n;\
    \ v++){\n        if (!g[v].empty()){\n            ids[v] = nonzero++;\n      \
    \  }\n    }\n    std::vector<std::tuple<int, int, T>> nes(m);\n    for (int i\
    \ = 0; i < m; i++){\n        auto [u, v, c] = es[i];\n        nes[i] = {ids[u],ids[v],c};\n\
    \        deg[v] += c;\n    }\n    binomial<T> bnm;\n    T ans = directed_spanning_tree_counting(nonzero,nes);\n\
    \    for (int i = 0; i < n; i++){\n        if (deg[i] > 0){\n            ans *=\
    \ bnm.fact(deg[i]-1);\n        }\n    }\n    return ans;\n}\n\n} // namespace\
    \ noya2\n#line 2 \"utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\n\n\
    #line 2 \"math/prime.hpp\"\n\n#line 4 \"math/prime.hpp\"\nnamespace noya2 {\n\n\
    constexpr long long safe_mod(long long x, long long m) {\n    x %= m;\n    if\
    \ (x < 0) x += m;\n    return x;\n}\n\nconstexpr long long pow_mod_constexpr(long\
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
    #line 6 \"utility/modint.hpp\"\n\nnamespace noya2{\n\nstruct barrett {\n    unsigned\
    \ int _m;\n    unsigned long long im;\n    explicit barrett(unsigned int m) :\
    \ _m(m), im((unsigned long long)(-1) / m + 1) {}\n    unsigned int umod() const\
    \ { return _m; }\n    unsigned int mul(unsigned int a, unsigned int b) const {\n\
    \        unsigned long long z = a;\n        z *= b;\n        unsigned long long\
    \ x = (unsigned long long)((__uint128_t(z) * im) >> 64);\n        unsigned int\
    \ v = (unsigned int)(z - x * _m);\n        if (_m <= v) v += _m;\n        return\
    \ v;\n    }\n};\n\ntemplate <int m>\nstruct static_modint {\n    using mint =\
    \ static_modint;\n  public:\n    static constexpr int mod() { return m; }\n  \
    \  static mint raw(int v) {\n        mint x;\n        x._v = v;\n        return\
    \ x;\n    }\n    constexpr static_modint() : _v(0) {}\n    template<std::signed_integral\
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
    \    a.pow(declval<int>());\n};\n\n} // namespace noya2\n#line 6 \"test/math/CountingEulerianCircuits.test.cpp\"\
    \nusing mint = modint998244353;\n\nint main(){\n    int n, m; in(n,m);\n    vector<tuple<int,int,ll>>\
    \ es(m);\n    rep(i,m){\n        int u, v; in(u,v);\n        es[i] = {u,v,1};\n\
    \    }\n    out(euler_circuit_counting<mint>(n,es));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_eulerian_circuits\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../math/euler_circuit_counting.hpp\"\
    \n#include\"../../utility/modint.hpp\"\nusing mint = modint998244353;\n\nint main(){\n\
    \    int n, m; in(n,m);\n    vector<tuple<int,int,ll>> es(m);\n    rep(i,m){\n\
    \        int u, v; in(u,v);\n        es[i] = {u,v,1};\n    }\n    out(euler_circuit_counting<mint>(n,es));\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - math/euler_circuit_counting.hpp
  - math/spanning_tree_counting.hpp
  - math/matrix.hpp
  - math/binomial.hpp
  - utility/modint.hpp
  - math/prime.hpp
  isVerificationFile: true
  path: test/math/CountingEulerianCircuits.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 15:38:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/CountingEulerianCircuits.test.cpp
layout: document
redirect_from:
- /verify/test/math/CountingEulerianCircuits.test.cpp
- /verify/test/math/CountingEulerianCircuits.test.cpp.html
title: test/math/CountingEulerianCircuits.test.cpp
---