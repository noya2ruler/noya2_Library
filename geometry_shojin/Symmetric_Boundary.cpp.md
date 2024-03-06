---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry_shojin/Symmetric_Boundary.cpp\"\n#include<bits/stdc++.h>\n\
    #define all(v) (v).begin(),(v).end()\nusing namespace std;\nusing ld = long double;\n\
    using vec = complex<ld>;\nconst ld eps = 1e-10;\n \nint sgn(ld a){\n    return\
    \ (a > eps ? 1 : a < -eps ? -1 : 0);\n}\nld dot(vec a, vec b){\n    return (conj(a)\
    \ * b).real();\n}\nld cross(vec a, vec b){\n    return (conj(a) * b).imag();\n\
    }\n \nstruct line {\n    vec p, q;\n};\n \nbool is_parallel(line a, line b){\n\
    \    vec va = a.q - a.p;\n    vec vb = b.q - b.p;\n    return sgn(cross(va,vb))\
    \ == 0;\n}\n \nvec cross_point(line a, line b){\n    assert(!is_parallel(a,b));\n\
    \    return a.p + (a.q - a.p) * cross(b.p - a.p, b.q - b.p) / cross(a.q - a.p,\
    \ b.q - b.p);\n}\n \nbool is_on_line(vec a, line l){\n    return sgn(cross(l.p-a,l.q-a))\
    \ == 0;\n}\n \nld area_if_convex(vector<vec> a){\n    int n = a.size();\n    sort(all(a),[&](vec\
    \ l, vec r){\n        if (sgn(l.real() - r.real()) == 0){\n            return\
    \ l.imag() < r.imag();\n        }\n        return l.real() < r.real();\n    });\n\
    \    stack<int> uid, did;\n    vec ri = a[n-1];\n    auto make_half = [&](bool\
    \ isupper){\n        auto &id = (isupper ? uid : did);\n        id.push(0);\n\
    \        for (int i = 1; i < n-1; i++){\n            vec le = a[id.top()];\n \
    \           auto cr = cross(ri - le, a[i] - le);\n            if ((cr > 0 && isupper)\
    \ || (cr < 0 && !isupper)){\n                while ((int)(id.size()) >= 2){\n\
    \                    int test = id.top(); id.pop();\n                    vec from\
    \ = a[id.top()];\n                    auto cr2 = cross(a[i] - from, a[test] -\
    \ from);\n                    if ((cr2 > 0 && isupper) || (cr2 < 0 && !isupper)){\n\
    \                        id.push(test);\n                        break;\n    \
    \                }\n                }\n                id.push(i);\n         \
    \   }\n        }\n    };\n    make_half(true);\n    make_half(false);\n    vector<int>\
    \ ids(1,n-1);\n    while (!did.empty()) ids.emplace_back(did.top()), did.pop();\n\
    \    reverse(all(ids));\n    while (!uid.empty()) ids.emplace_back(uid.top()),\
    \ uid.pop();\n    ids.pop_back();\n    vector<vec> ans(ids.size());\n    for (int\
    \ i = 0; auto id : ids){\n        ans[i++] = a[id];\n    }\n    // check\n   \
    \ int sz = ans.size();\n    for (int i = 0; i < n; i++){\n        bool ok = is_on_line(a[i],line{ans[sz-1],ans[0]});\n\
    \        for (int j = 0; j < sz-1; j++){\n            if (ok) break;\n       \
    \     ok = is_on_line(a[i],line{ans[j],ans[j+1]});\n        }\n        if (!ok){\n\
    \            return 1e30;\n        }\n    }\n    // area\n    ld area = 0;\n \
    \   for (int i = 1; i < sz-1; i++){\n        area += abs(cross(ans[i]-ans[0],ans[i+1]-ans[0]));\n\
    \    }\n    area /= 2;\n    // cout << area << endl;\n    return area;\n}\n \n\
    vector<vec> compressed(vector<vec> a){\n    auto comp = [&](vec l, vec r){\n \
    \       if (sgn(l.real() - r.real()) == 0){\n            return l.imag() < r.imag();\n\
    \        }\n        return l.real() < r.real();\n    };\n    sort(all(a),comp);\n\
    \    vector<vec> ans;\n    int sz = a.size();\n    for (int l = 0, r = 0; l <\
    \ sz; l = r){\n        while (r < sz && sgn(abs(a[l]-a[r])) == 0) r++;\n     \
    \   ans.emplace_back(a[l]);\n    }\n    return ans;\n}\n \nvoid solve(){\n   \
    \ int n; cin >> n;\n    vector<vec> a(n);\n    for (auto &v : a){\n        ld\
    \ x, y; cin >> x >> y;\n        v = vec(x,y);\n    }\n    vector<line> ls;\n \
    \   for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){\n        vec m0 =\
    \ (a[i] + a[j]) * 0.5L;\n        vec m1 = (a[i] + a[(j == n-1 ? 0 : j+1)]) * 0.5L;\n\
    \        ls.push_back(line{m0,m1});\n    }\n    ld area_min = 1e30;\n    vector<vec>\
    \ ctrs;\n    for (auto l1 : ls) for (auto l2 : ls){\n        if (!is_parallel(l1,l2)){\n\
    \            ctrs.emplace_back(cross_point(l1,l2));\n        }\n    }\n    ctrs\
    \ = compressed(ctrs);\n    for (auto ctr : ctrs){\n        vector<vec> ps(n+n);\n\
    \        for (int i = 0; i < n; i++){\n            ps[i] = a[i];\n           \
    \ ps[n+i] = ctr * 2.L - a[i];\n        }\n        area_min = min(area_min, area_if_convex(ps));\n\
    \    }\n    if (area_min > 1e29){\n        cout << -1 << endl;\n    }\n    else\
    \ {\n        cout << area_min << endl;\n    }\n}\n \nint main(){\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cout << fixed << setprecision(15);\n    int t = 1; // cin >> t;\n    while\
    \ (t--){\n        solve();\n    }\n}\n"
  code: "#include<bits/stdc++.h>\n#define all(v) (v).begin(),(v).end()\nusing namespace\
    \ std;\nusing ld = long double;\nusing vec = complex<ld>;\nconst ld eps = 1e-10;\n\
    \ \nint sgn(ld a){\n    return (a > eps ? 1 : a < -eps ? -1 : 0);\n}\nld dot(vec\
    \ a, vec b){\n    return (conj(a) * b).real();\n}\nld cross(vec a, vec b){\n \
    \   return (conj(a) * b).imag();\n}\n \nstruct line {\n    vec p, q;\n};\n \n\
    bool is_parallel(line a, line b){\n    vec va = a.q - a.p;\n    vec vb = b.q -\
    \ b.p;\n    return sgn(cross(va,vb)) == 0;\n}\n \nvec cross_point(line a, line\
    \ b){\n    assert(!is_parallel(a,b));\n    return a.p + (a.q - a.p) * cross(b.p\
    \ - a.p, b.q - b.p) / cross(a.q - a.p, b.q - b.p);\n}\n \nbool is_on_line(vec\
    \ a, line l){\n    return sgn(cross(l.p-a,l.q-a)) == 0;\n}\n \nld area_if_convex(vector<vec>\
    \ a){\n    int n = a.size();\n    sort(all(a),[&](vec l, vec r){\n        if (sgn(l.real()\
    \ - r.real()) == 0){\n            return l.imag() < r.imag();\n        }\n   \
    \     return l.real() < r.real();\n    });\n    stack<int> uid, did;\n    vec\
    \ ri = a[n-1];\n    auto make_half = [&](bool isupper){\n        auto &id = (isupper\
    \ ? uid : did);\n        id.push(0);\n        for (int i = 1; i < n-1; i++){\n\
    \            vec le = a[id.top()];\n            auto cr = cross(ri - le, a[i]\
    \ - le);\n            if ((cr > 0 && isupper) || (cr < 0 && !isupper)){\n    \
    \            while ((int)(id.size()) >= 2){\n                    int test = id.top();\
    \ id.pop();\n                    vec from = a[id.top()];\n                   \
    \ auto cr2 = cross(a[i] - from, a[test] - from);\n                    if ((cr2\
    \ > 0 && isupper) || (cr2 < 0 && !isupper)){\n                        id.push(test);\n\
    \                        break;\n                    }\n                }\n  \
    \              id.push(i);\n            }\n        }\n    };\n    make_half(true);\n\
    \    make_half(false);\n    vector<int> ids(1,n-1);\n    while (!did.empty())\
    \ ids.emplace_back(did.top()), did.pop();\n    reverse(all(ids));\n    while (!uid.empty())\
    \ ids.emplace_back(uid.top()), uid.pop();\n    ids.pop_back();\n    vector<vec>\
    \ ans(ids.size());\n    for (int i = 0; auto id : ids){\n        ans[i++] = a[id];\n\
    \    }\n    // check\n    int sz = ans.size();\n    for (int i = 0; i < n; i++){\n\
    \        bool ok = is_on_line(a[i],line{ans[sz-1],ans[0]});\n        for (int\
    \ j = 0; j < sz-1; j++){\n            if (ok) break;\n            ok = is_on_line(a[i],line{ans[j],ans[j+1]});\n\
    \        }\n        if (!ok){\n            return 1e30;\n        }\n    }\n  \
    \  // area\n    ld area = 0;\n    for (int i = 1; i < sz-1; i++){\n        area\
    \ += abs(cross(ans[i]-ans[0],ans[i+1]-ans[0]));\n    }\n    area /= 2;\n    //\
    \ cout << area << endl;\n    return area;\n}\n \nvector<vec> compressed(vector<vec>\
    \ a){\n    auto comp = [&](vec l, vec r){\n        if (sgn(l.real() - r.real())\
    \ == 0){\n            return l.imag() < r.imag();\n        }\n        return l.real()\
    \ < r.real();\n    };\n    sort(all(a),comp);\n    vector<vec> ans;\n    int sz\
    \ = a.size();\n    for (int l = 0, r = 0; l < sz; l = r){\n        while (r <\
    \ sz && sgn(abs(a[l]-a[r])) == 0) r++;\n        ans.emplace_back(a[l]);\n    }\n\
    \    return ans;\n}\n \nvoid solve(){\n    int n; cin >> n;\n    vector<vec> a(n);\n\
    \    for (auto &v : a){\n        ld x, y; cin >> x >> y;\n        v = vec(x,y);\n\
    \    }\n    vector<line> ls;\n    for (int i = 0; i < n; i++) for (int j = 0;\
    \ j < n; j++){\n        vec m0 = (a[i] + a[j]) * 0.5L;\n        vec m1 = (a[i]\
    \ + a[(j == n-1 ? 0 : j+1)]) * 0.5L;\n        ls.push_back(line{m0,m1});\n   \
    \ }\n    ld area_min = 1e30;\n    vector<vec> ctrs;\n    for (auto l1 : ls) for\
    \ (auto l2 : ls){\n        if (!is_parallel(l1,l2)){\n            ctrs.emplace_back(cross_point(l1,l2));\n\
    \        }\n    }\n    ctrs = compressed(ctrs);\n    for (auto ctr : ctrs){\n\
    \        vector<vec> ps(n+n);\n        for (int i = 0; i < n; i++){\n        \
    \    ps[i] = a[i];\n            ps[n+i] = ctr * 2.L - a[i];\n        }\n     \
    \   area_min = min(area_min, area_if_convex(ps));\n    }\n    if (area_min > 1e29){\n\
    \        cout << -1 << endl;\n    }\n    else {\n        cout << area_min << endl;\n\
    \    }\n}\n \nint main(){\n    cin.tie(0)->sync_with_stdio(0);\n    cout << fixed\
    \ << setprecision(15);\n    int t = 1; // cin >> t;\n    while (t--){\n      \
    \  solve();\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry_shojin/Symmetric_Boundary.cpp
  requiredBy: []
  timestamp: '2024-03-06 14:43:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry_shojin/Symmetric_Boundary.cpp
layout: document
title: ICPC 2024 Asia Pacific Championship - I Symmetric Boundary
---

[出典](https://codeforces.com/contest/1938/problem/I)

## 問題概要

二次元平面上の凸多角形の頂点が与えられる。

点対称な凸多角形であって、与えられた点をすべて境界に含むようなものが存在するか判定せよ。存在するなら、面積の最小値を求めよ。

## 考察

## 備考

## 感想