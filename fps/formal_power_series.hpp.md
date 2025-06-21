---
data:
  _extendedDependsOn:
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/fps_arbitrary.hpp
    title: fps/fps_arbitrary.hpp
  - icon: ':warning:'
    path: fps/fps_atcoder.hpp
    title: fps/fps_atcoder.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_modint.hpp
    title: fps/fps_modint.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_ntt.hpp
    title: fps/fps_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/multipoint_evaluation.hpp
    title: fps/multipoint_evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sample_point_shift.hpp
    title: fps/sample_point_shift.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/Convolution1000000007.test.cpp
    title: test/fps/Convolution1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Inv_of_Formal_Power_Series.test.cpp
    title: test/fps/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
    title: test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
    title: test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/convolution.test.cpp
    title: test/fps/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/FrequencyTableofTreeDistance.test.cpp
    title: test/tree/FrequencyTableofTreeDistance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/formal_power_series.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    */\n\n}\n\nusing namespace noya2;\n\n\n#line 4 \"fps/formal_power_series.hpp\"\
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
    \ noya2\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace noya2{\n\
    \ntemplate<typename T>\nconcept Field = requires (T a, T b){\n    a + b; a - b;\
    \ a / b; a * b;\n    T(0); T(1);\n};\n\ntemplate<class Info>\nconcept Fps_Info\
    \ = requires {\n    typename Info::value_type;\n    requires Field<typename Info::value_type>;\n\
    \    {Info::multiply(declval<vector<typename Info::value_type>>(),declval<vector<typename\
    \ Info::value_type>>())} -> convertible_to<vector<typename Info::value_type>>;\n\
    \    {Info::inv(declval<vector<typename Info::value_type>>(),declval<int>())}\
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
    \ noya2"
  dependsOn:
  - template/template.hpp
  - template/inout_old.hpp
  - template/const.hpp
  - template/utils.hpp
  isVerificationFile: false
  path: fps/formal_power_series.hpp
  requiredBy:
  - fps/fps_atcoder.hpp
  - fps/sample_point_shift.hpp
  - fps/multipoint_evaluation.hpp
  - fps/fps_arbitrary.hpp
  - fps/fps_modint.hpp
  - fps/fps_ntt.hpp
  timestamp: '2024-07-01 23:39:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/convolution.test.cpp
  - test/fps/Multipoint_Evaluation_Geometric_Sequence.test.cpp
  - test/fps/Inv_of_Formal_Power_Series.test.cpp
  - test/fps/Convolution1000000007.test.cpp
  - test/fps/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - test/tree/FrequencyTableofTreeDistance.test.cpp
documentation_of: fps/formal_power_series.hpp
layout: document
redirect_from:
- /library/fps/formal_power_series.hpp
- /library/fps/formal_power_series.hpp.html
title: fps/formal_power_series.hpp
---
