#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using namespace std;
using ld = long double;
using vec = complex<ld>;
const ld eps = 1e-10;
 
int sgn(ld a){
    return (a > eps ? 1 : a < -eps ? -1 : 0);
}
ld dot(vec a, vec b){
    return (conj(a) * b).real();
}
ld cross(vec a, vec b){
    return (conj(a) * b).imag();
}
 
struct line {
    vec p, q;
};
 
bool is_parallel(line a, line b){
    vec va = a.q - a.p;
    vec vb = b.q - b.p;
    return sgn(cross(va,vb)) == 0;
}
 
vec cross_point(line a, line b){
    assert(!is_parallel(a,b));
    return a.p + (a.q - a.p) * cross(b.p - a.p, b.q - b.p) / cross(a.q - a.p, b.q - b.p);
}
 
bool is_on_line(vec a, line l){
    return sgn(cross(l.p-a,l.q-a)) == 0;
}
 
ld area_if_convex(vector<vec> a){
    int n = a.size();
    sort(all(a),[&](vec l, vec r){
        if (sgn(l.real() - r.real()) == 0){
            return l.imag() < r.imag();
        }
        return l.real() < r.real();
    });
    stack<int> uid, did;
    vec ri = a[n-1];
    auto make_half = [&](bool isupper){
        auto &id = (isupper ? uid : did);
        id.push(0);
        for (int i = 1; i < n-1; i++){
            vec le = a[id.top()];
            auto cr = cross(ri - le, a[i] - le);
            if ((cr > 0 && isupper) || (cr < 0 && !isupper)){
                while ((int)(id.size()) >= 2){
                    int test = id.top(); id.pop();
                    vec from = a[id.top()];
                    auto cr2 = cross(a[i] - from, a[test] - from);
                    if ((cr2 > 0 && isupper) || (cr2 < 0 && !isupper)){
                        id.push(test);
                        break;
                    }
                }
                id.push(i);
            }
        }
    };
    make_half(true);
    make_half(false);
    vector<int> ids(1,n-1);
    while (!did.empty()) ids.emplace_back(did.top()), did.pop();
    reverse(all(ids));
    while (!uid.empty()) ids.emplace_back(uid.top()), uid.pop();
    ids.pop_back();
    vector<vec> ans(ids.size());
    for (int i = 0; auto id : ids){
        ans[i++] = a[id];
    }
    // check
    int sz = ans.size();
    for (int i = 0; i < n; i++){
        bool ok = is_on_line(a[i],line{ans[sz-1],ans[0]});
        for (int j = 0; j < sz-1; j++){
            if (ok) break;
            ok = is_on_line(a[i],line{ans[j],ans[j+1]});
        }
        if (!ok){
            return 1e30;
        }
    }
    // area
    ld area = 0;
    for (int i = 1; i < sz-1; i++){
        area += abs(cross(ans[i]-ans[0],ans[i+1]-ans[0]));
    }
    area /= 2;
    // cout << area << endl;
    return area;
}
 
vector<vec> compressed(vector<vec> a){
    auto comp = [&](vec l, vec r){
        if (sgn(l.real() - r.real()) == 0){
            return l.imag() < r.imag();
        }
        return l.real() < r.real();
    };
    sort(all(a),comp);
    vector<vec> ans;
    int sz = a.size();
    for (int l = 0, r = 0; l < sz; l = r){
        while (r < sz && sgn(abs(a[l]-a[r])) == 0) r++;
        ans.emplace_back(a[l]);
    }
    return ans;
}
 
void solve(){
    int n; cin >> n;
    vector<vec> a(n);
    for (auto &v : a){
        ld x, y; cin >> x >> y;
        v = vec(x,y);
    }
    vector<line> ls;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
        vec m0 = (a[i] + a[j]) * 0.5L;
        vec m1 = (a[i] + a[(j == n-1 ? 0 : j+1)]) * 0.5L;
        ls.push_back(line{m0,m1});
    }
    ld area_min = 1e30;
    vector<vec> ctrs;
    for (auto l1 : ls) for (auto l2 : ls){
        if (!is_parallel(l1,l2)){
            ctrs.emplace_back(cross_point(l1,l2));
        }
    }
    ctrs = compressed(ctrs);
    for (auto ctr : ctrs){
        vector<vec> ps(n+n);
        for (int i = 0; i < n; i++){
            ps[i] = a[i];
            ps[n+i] = ctr * 2.L - a[i];
        }
        area_min = min(area_min, area_if_convex(ps));
    }
    if (area_min > 1e29){
        cout << -1 << endl;
    }
    else {
        cout << area_min << endl;
    }
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(15);
    int t = 1; // cin >> t;
    while (t--){
        solve();
    }
}