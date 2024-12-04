---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/eertree.hpp
    title: string/eertree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/eertree
    links:
    - https://judge.yosupo.jp/problem/eertree
  bundledCode: "#line 1 \"test/string/Eertree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/eertree\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 2 \"string/eertree.hpp\"\n\n#line\
    \ 7 \"string/eertree.hpp\"\n\nnamespace noya2 {\n\ntemplate<int sigma = 26>\n\
    struct eertree {\n    static_assert(sigma <= 256);\n    using child = std::array<int,sigma>;\n\
    \    static constexpr child makeleaf(){\n        child ret = {};\n        ret.fill(-1);\n\
    \        return ret;\n    }\n    static constexpr child leaf = makeleaf();\n \
    \   struct node {\n        int suffix_link;\n        int length;\n        child\
    \ ch;\n        explicit node (int _suffix_link, int _length) : suffix_link(_suffix_link),\
    \ length(_length), ch(leaf) {}\n        friend ostream &operator<<(ostream &os,\
    \ const node &p){\n            return os << \"suffix link : \" << p.suffix_link\
    \ << \" length : \" << p.length;\n        }\n    };\n    int cursor = 1;\n   \
    \ std::vector<node> nodes;\n    std::vector<uint8_t> str;\n    int find_suffix(int\
    \ pos, int cur){\n        while (cur >= 0){\n            int len = nodes[cur].length;\n\
    \            int sop = pos - len - 1;\n            if (sop >= 0 && str[sop] ==\
    \ str[pos]) return cur;\n            cur = nodes[cur].suffix_link;\n        }\n\
    \        return 0;\n    }\n    eertree (){\n        nodes = {node(-1,-1),node(0,0)};\n\
    \    }\n    // if 'a' is added, call add_char(0)\n    // current cursor, parent\
    \ of child_tree, parent of suffix_tree\n    std::tuple<int,int,int> add_char(int\
    \ c){\n        int pos = str.size();\n        str.emplace_back(c);\n        cursor\
    \ = find_suffix(pos, cursor);\n        // add child to str(cursor)\n        int\
    \ ch = nodes[cursor].ch[c];\n        // already exists\n        if (ch != -1){\n\
    \            auto ret = std::make_tuple(ch, cursor, nodes[ch].suffix_link);\n\
    \            cursor = ch;\n            return ret;\n        }\n        // new\
    \ node\n        const int ncursor = nodes.size();\n        const int nlength =\
    \ nodes[cursor].length + 2;\n        const int npar = find_suffix(pos, nodes[cursor].suffix_link);\n\
    \        int nsuffix_link = nodes[npar].ch[c];\n        // c is new char\n   \
    \     if (nsuffix_link == -1){\n            nsuffix_link = 1;\n        }\n   \
    \     nodes[cursor].ch[c] = ncursor;\n        nodes.emplace_back(nsuffix_link,\
    \ nlength);\n        auto ret = make_tuple(ncursor, cursor, nsuffix_link);\n \
    \       cursor = ncursor;\n        return ret;\n    }\n    node operator[](int\
    \ idx) const {\n        return nodes[idx];\n    }\n};\n\n\n} // namespace noya2\n\
    #line 5 \"test/string/Eertree.test.cpp\"\n\nint main(){\n    string s; in(s);\n\
    \    int n = s.size();\n    eertree et;\n    vector<pii> pss;\n    vector<int>\
    \ vs; vs.reserve(n);\n    int ma = 1;\n    for (auto c : s){\n        auto [v,\
    \ cp, sp] = et.add_char(c - 'a');\n        if (ma < v){\n            pss.emplace_back(cp-1,sp-1);\n\
    \            ma = v;\n        }\n        vs.emplace_back(v-1);\n    }\n    out(pss.size());\n\
    \    for (auto &ps : pss) out(ps);\n    out(vs);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eertree\"\n\n#include\"\
    ../../template/template.hpp\"\n#include\"../../string/eertree.hpp\"\n\nint main(){\n\
    \    string s; in(s);\n    int n = s.size();\n    eertree et;\n    vector<pii>\
    \ pss;\n    vector<int> vs; vs.reserve(n);\n    int ma = 1;\n    for (auto c :\
    \ s){\n        auto [v, cp, sp] = et.add_char(c - 'a');\n        if (ma < v){\n\
    \            pss.emplace_back(cp-1,sp-1);\n            ma = v;\n        }\n  \
    \      vs.emplace_back(v-1);\n    }\n    out(pss.size());\n    for (auto &ps :\
    \ pss) out(ps);\n    out(vs);\n}"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  - string/eertree.hpp
  isVerificationFile: true
  path: test/string/Eertree.test.cpp
  requiredBy: []
  timestamp: '2024-12-04 14:23:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/Eertree.test.cpp
layout: document
redirect_from:
- /verify/test/string/Eertree.test.cpp
- /verify/test/string/Eertree.test.cpp.html
title: test/string/Eertree.test.cpp
---
