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

点 $p_1,p_2,\dots ,p_N$ が反時計回りで与えられるとする。

適当に点対称の中心 $X$ を取ることにし、これが次の条件を満たすかを確かめる。

- $S(X)=\lbrace p_i,2X-p_i\mid 1\le i\le N\rbrace$ の凸包は、その境界に $S(X)$ を含む。

この言い換えは素朴だが重要である。これで、凸多角形の全探索から点の全探索に落ちた。

当然、まだまだ探索範囲を絞る必要がある。

次に、$X$ が条件を満たすとき、 $X$ の近傍が（もっと良い）条件を満たしていないかを調べる。これも探索範囲を絞る典型的思考のひとつである。

$S(X)$ の凸包の特徴を見る。一般に、点集合 $P$ の凸包 $C(P)$ について考え、 $C(P)$ の境界に $P$ が含まれるという条件を $Z(P)$ と書くことにする。

$P$ の元がそれぞれ独立に微小な移動を行ったとき $Z(P)$ が不変である十分条件を考える。$P$ 全体での条件を考えるのは難しいが、十分条件を与えるだけなら $P$ の任意の $3$ 点の位置関係に注目するのが良い。

$P$ から $3$ 点 $(a,b,c)$ を取ってその $CCW$ を返す関数 $CCW(P):P^3\rightarrow\lbrace 0,1\rbrace$ を考える。（ここでは細かい符号は気にしないので、外積 $(b-a)\times (c-a)$ が非負かどうかで $CCW$ を定義する。）

このとき点集合 $P,Q$ について、全単射 $\iota :P\rightarrow Q$ が存在して $CCW(P)(a,b,c)=CCW(Q)(\iota(a),\iota(b),\iota(c))$ が成り立つとき、 $P,Q$ は本質的に同じであり、 $Z(P)\leftrightarrow Z(Q)$ ということである。

$S(X)$ の話に戻る。 $S(X)$ が本質的に同じである限り、つまり $CCW$ が変わらない限り、 $X$ をギリギリまで動かして良い、ということである（少なくとも、面積の最小化を考えなければ）。

もし $X$ がある領域内にある間は $S(X)$ が本質的に同じだとすれば、その領域の縁まで動かして良いことになる。実際、そのような領域を取ることができることを見る。

$S(X)$ から $3$ 点を取って $CCW$ が変わらない条件を考えると、ある直線を境に $X$ の存在領域がふたつに分かれることになる。単純な考察ではそのような直線を $N^3$ 個考えることができそうであるが、多少の飛躍（要理解）により $N^2$ 個のみ考えれば良い。

そのような直線で平面を分割したとき、各領域内では $S(X)$ は本質的に同じで、さらに、面積が $X$ の線形な式で書けることから、領域の縁よりもさらに探索範囲を絞れて領域の角、つまり、直線どうしの交点のみを調べれば良いことになる。（区間内で線形な式の最大値・最小値は端点で達成する）

ここまでで、ようやく探索範囲を有限個に絞ることができた。実際に $N^2$ 個の直線のすべての交点（ $N^4$ 個程度ある）を $X$ として試し、　$Z(S(X))$ を調べればよい。丁寧にやれば $O(N^5\log N)$ 時間になるが、自分の実装は $O(N^6)$ 時間である。


## 感想

$CCW(P)$ が不変なら $Z(P)$ が不変、典型かも。

少なくとも、 $X$ の全探索にはするべきで、さらには探索範囲を絞る考察に注力するべきであった。

また、候補を絞るには、「実はこういうものだけ考えれば良い」という発想は典型で、今回のように平面上の点の全探索であれば $X$ の微小変化による条件の変化を探るのは思いつくべきであった。

また、そのような考察はたいてい「領域の縁・角のみで良い」に行き着くが、このことと「閉集合上の一次式の最大最小は境界で達成する」は相性が良く、しばしばセットで出題されることを念頭に置いておくべきであった。