---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/inout.hpp\"\nnamespace noya2 {\n\ntemplate<typename\
    \ T> concept Scanable  = requires (ifstream &is, T &a){ is >> a; };\ntemplate<typename\
    \ T> concept Printable = requires (ofstream &os, T &a){ os << a; };\n\ntemplate\
    \ <typename Scanable> istream &operator>>(istream &is, vector<Scanable> &v);\n\
    template <typename Printable> ostream &operator<<(ostream &os, const vector<Printable>\
    \ &v);\n\ntemplate <typename T, typename U>\nrequires Scanable<T> && Scanable<U>\n\
    istream &operator>>(istream &is, pair<T, U> &p){\n    is >> p.first >> p.second;\n\
    \    return is;\n}\ntemplate <typename T, typename U>\nrequires Printable<T> &&\
    \ Printable<U>\nostream &operator<<(ostream &os, const pair<T, U> &p){\n    os\
    \ << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate <typename Scanable>\n\
    istream &operator>>(istream &is, vector<Scanable> &v){\n    for (auto &x : v)\
    \ is >> x;\n    return is;\n}\ntemplate <typename Printable>\nostream &operator<<(ostream\
    \ &os, const vector<Printable> &v){\n    int s = (int)v.size();\n    for (int\
    \ i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n    return os;\n}\n\n\
    void in() {}\ntemplate <typename Scanable, class... U>\nvoid in(Scanable &t, U\
    \ &...u){\n    cin >> t;\n    in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\n\
    template <typename Printable, class... U, char sep = ' '>\nvoid out(const Printable\
    \ &t, const U &...u){\n    cout << t;\n    if (sizeof...(u)) cout << sep;\n  \
    \  out(u...);\n}\ntemplate<typename Printable>\nvoid out(const vector<vector<Printable>>\
    \ &vv){\n    int s = (int)vv.size();\n    for (int i = 0; i < s; i++) out(vv[i]);\n\
    }\n\nstruct IoSetup {\n    IoSetup(){\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n\
    \    }\n} iosetup_noya2;\n\n} // namespace noya2\n"
  code: "namespace noya2 {\n\ntemplate<typename T> concept Scanable  = requires (ifstream\
    \ &is, T &a){ is >> a; };\ntemplate<typename T> concept Printable = requires (ofstream\
    \ &os, T &a){ os << a; };\n\ntemplate <typename Scanable> istream &operator>>(istream\
    \ &is, vector<Scanable> &v);\ntemplate <typename Printable> ostream &operator<<(ostream\
    \ &os, const vector<Printable> &v);\n\ntemplate <typename T, typename U>\nrequires\
    \ Scanable<T> && Scanable<U>\nistream &operator>>(istream &is, pair<T, U> &p){\n\
    \    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename T, typename\
    \ U>\nrequires Printable<T> && Printable<U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p){\n    os << p.first << \" \" << p.second;\n    return os;\n\
    }\n\ntemplate <typename Scanable>\nistream &operator>>(istream &is, vector<Scanable>\
    \ &v){\n    for (auto &x : v) is >> x;\n    return is;\n}\ntemplate <typename\
    \ Printable>\nostream &operator<<(ostream &os, const vector<Printable> &v){\n\
    \    int s = (int)v.size();\n    for (int i = 0; i < s; i++) os << (i ? \" \"\
    \ : \"\") << v[i];\n    return os;\n}\n\nvoid in() {}\ntemplate <typename Scanable,\
    \ class... U>\nvoid in(Scanable &t, U &...u){\n    cin >> t;\n    in(u...);\n\
    }\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename Printable, class... U,\
    \ char sep = ' '>\nvoid out(const Printable &t, const U &...u){\n    cout << t;\n\
    \    if (sizeof...(u)) cout << sep;\n    out(u...);\n}\ntemplate<typename Printable>\n\
    void out(const vector<vector<Printable>> &vv){\n    int s = (int)vv.size();\n\
    \    for (int i = 0; i < s; i++) out(vv[i]);\n}\n\nstruct IoSetup {\n    IoSetup(){\n\
    \        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout\
    \ << fixed << setprecision(15);\n        cerr << fixed << setprecision(7);\n \
    \   }\n} iosetup_noya2;\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: template/inout.hpp
  requiredBy: []
  timestamp: '2023-08-24 20:23:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/inout.hpp
layout: document
redirect_from:
- /library/template/inout.hpp
- /library/template/inout.hpp.html
title: template/inout.hpp
---
