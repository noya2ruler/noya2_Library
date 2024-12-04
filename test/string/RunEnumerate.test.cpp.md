---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/run_enumerate.hpp
    title: string/run_enumerate.hpp
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
    links:
    - https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "#line 1 \"test/string/RunEnumerate.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/runenumerate\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n#include<bits/stdc++.h>\n#line 1 \"template/inout_old.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"string/run_enumerate.hpp\"\n\n\
    #line 5 \"string/run_enumerate.hpp\"\n#include <ranges>\n#line 10 \"string/run_enumerate.hpp\"\
    \n\n#line 2 \"string/z_algorithm.hpp\"\n\n#line 8 \"string/z_algorithm.hpp\"\n\
    \n// atcoder/string\n\nnamespace noya2 {\n\n// Reference:\n// D. Gusfield,\n//\
    \ Algorithms on Strings, Trees, and Sequences: Computer Science and\n// Computational\
    \ Biology\ntemplate <class T> std::vector<int> z_algorithm(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    if (n == 0) return {};\n    std::vector<int>\
    \ z(n);\n    z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int&\
    \ k = z[i];\n        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\
    \        while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i\
    \ + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n} // namespace noya2\n#line 12 \"string/run_enumerate.hpp\"\n\nnamespace\
    \ noya2 {\n\nstd::vector<std::tuple<int,int,int>> run_enumerate(std::string s){\n\
    \    std::unordered_map<uint64_t,int> periods;\n    auto update = [&](int t, int\
    \ l, int r){\n        uint64_t h = ((uint64_t)(l) << 32) | r;\n        if (!periods.contains(h)\
    \ || periods[h] > t){\n            periods[h] = t;\n        }\n    };\n    auto\
    \ dfs = [&](auto sfs, int l, int r) -> void {\n        if (r - l == 1) return\
    \ ;\n        int m = (l + r) / 2;\n        std::string sl(s.begin() + l, s.begin()\
    \ + m);\n        std::string sr(s.begin() + m, s.begin() + r);\n        std::string\
    \ rev = sl; std::ranges::reverse(rev);\n        // L\n        {\n            auto\
    \ zl = z_algorithm(rev);\n            auto zr = z_algorithm(sr + sl);\n      \
    \      // [i, m) is period\n            for (int i = l; i < m; i++){\n       \
    \         int lextend = (i == l ? 0 : zl[m - i]);\n                int rextend\
    \ = zr[r - m + i - l];\n                if (rextend == m - i){\n             \
    \       rextend += zr[m - i];\n                    if (rextend > r - m){\n   \
    \                     rextend = r - m;\n                    }\n              \
    \  }\n                if (lextend + rextend >= m - i){\n                    if\
    \ (i - lextend == l && l > 0) continue;\n                    if (m + rextend ==\
    \ r && r < (int)(s.size())) continue;\n                    update(m - i, i - lextend,\
    \ m + rextend);\n                }\n            }\n        }\n        std::ranges::reverse_copy(sr,\
    \ std::back_inserter(rev));\n        // R\n        {\n            // [m, i) is\
    \ period\n            auto zl = z_algorithm(rev);\n            auto zr = z_algorithm(sr);\n\
    \            for (int i = m+1; i <= r; i++){\n                int lextend = zl[m\
    \ - l + r - i];\n                if (lextend == i - m){\n                    lextend\
    \ += zl[i - m];\n                    if (lextend > m - l){\n                 \
    \       lextend = m - l;\n                    }\n                }\n         \
    \       int rextend = (i == r ? 0 : zr[i - m]);\n                if (lextend +\
    \ rextend >= i - m){\n                    if (m - lextend == l && l > 0) continue;\n\
    \                    if (i + rextend == r && r < (int)(s.size())) continue;\n\
    \                    update(i - m, m - lextend, i + rextend);\n              \
    \  }\n            }\n        }\n        sfs(sfs, l, m);\n        sfs(sfs, m, r);\n\
    \    };\n    dfs(dfs,0,s.size());\n    std::vector<std::tuple<int,int,int>> ret;\
    \ ret.reserve(periods.size());\n    for (auto [lr, t] : periods){\n        int\
    \ r = lr & UINT32_MAX;\n        int l = lr >> 32;\n        ret.emplace_back(t,\
    \ l, r);\n    }\n    std::ranges::sort(ret);\n    return ret;\n}\n\n} // namespace\
    \ noya2\n#line 5 \"test/string/RunEnumerate.test.cpp\"\n\nint main(){\n    string\
    \ s; in(s);\n    auto ans = run_enumerate(s);\n    out(ans.size());\n    for (auto\
    \ [t, l, r] : ans){\n        out(t,l,r);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n\n#include\"\
    ../../template/template.hpp\"\n#include\"../../string/run_enumerate.hpp\"\n\n\
    int main(){\n    string s; in(s);\n    auto ans = run_enumerate(s);\n    out(ans.size());\n\
    \    for (auto [t, l, r] : ans){\n        out(t,l,r);\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - string/run_enumerate.hpp
  - string/z_algorithm.hpp
  isVerificationFile: true
  path: test/string/RunEnumerate.test.cpp
  requiredBy: []
  timestamp: '2024-12-04 14:23:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/RunEnumerate.test.cpp
layout: document
redirect_from:
- /verify/test/string/RunEnumerate.test.cpp
- /verify/test/string/RunEnumerate.test.cpp.html
title: test/string/RunEnumerate.test.cpp
---
