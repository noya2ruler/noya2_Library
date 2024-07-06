#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include"../../template/template.hpp"
#include"../../tree/simple_tree.hpp"
#include"../../tree/centroid_decomposition.hpp"
#include"../../utility/modint4724.hpp"
#include"../../fps/formal_power_series.hpp"

namespace noya2{

consteval unsigned long long primitive_root_4724(unsigned long long p){
    if (p == modint4724::mod()){
        return 3;
    }
    throw ;
}

template<Modint mint>
struct number_theoretic_transform {
    static constexpr mint pr = primitive_root_4724(mint::mod());
    static constexpr int level = std::countr_zero(mint::mod() - 1);
    static constexpr std::array<mint,level+1> wgen(mint r){
        std::array<mint,level+1> ret;
        ret[level] = r;
        for (int i = level-1; i >= 0; i--){
            ret[i] = ret[i+1] * ret[i+1];
        }
        return ret;
    }
    static constexpr std::array<mint,level+1> wp = wgen(pr.pow((mint::mod()-1) >> level));
    static constexpr std::array<mint,level+1> wm = wgen(pr.pow((mint::mod()-1) >> level).inv());
    void fft2(std::vector<mint> &a){
        if (a.empty()) return ;
        int n = a.size();
        int k = std::countr_zero((unsigned int)(n));
        assert(n == (1 << k));
        for (int t = 1, v = 1<<(k-1), wi = k; v > 0; t <<= 1, v >>= 1, wi -= 1){
            mint ww = 1;
            int pl = 1<<wi;
            for (int j = 0; j < v; j++, ww *= wm[wi]){
                int j0 = j, j1 = j0+v;
                for (int i = 0; i < t; i++, j0 += pl, j1 += pl){
                    mint a1 = a[j1];
                    a[j1] = (a[j0] - a1) * ww;
                    a[j0] += a1;
                }
            }
        }
    }
    void ifft2(std::vector<mint> &a){
        if (a.empty()) return ;
        int n = a.size();
        int k = std::countr_zero((unsigned int)(n));
        assert(n == (1 << k));
        for (int v = 1, t = 1<<(k-1), wi = 1; t > 0; v <<= 1, t >>= 1, wi += 1){
            mint ww = 1;
            int pl = 1<<wi;
            for (int j = 0; j < v; j++, ww *= wp[wi]){
                int j0 = j, j1 = j0+v;
                for (int i = 0; i < t; i++, j0 += pl, j1 += pl){
                    mint a1 = a[j1] * ww;
                    a[j1] = a[j0] - a1;
                    a[j0] += a1;
                }
            }
        }
    }
    std::vector<mint> multiply(const std::vector<mint> &a, const std::vector<mint> &b) {
        int l = a.size() + b.size() - 1;
        if (min<int>(a.size(), b.size()) <= 40){
            std::vector<mint> s(l);
            for (int i = 0; i < (int)a.size(); i++) for (int j = 0; j < (int)b.size(); j++) s[i + j] += a[i] * b[j];
            return s;
        }
        int k = 2, M = 4;
        while (M < l) M <<= 1, ++k;
        std::vector<mint> s(M);
        for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];
        fft2(s);
        if (a.size() == b.size() && a == b) {
            for (int i = 0; i < M; ++i) s[i] *= s[i];
        }
        else {
            std::vector<mint> t(M);
            for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];
            fft2(t);
            for (int i = 0; i < M; ++i) s[i] *= t[i];
        }
        ifft2(s);
        s.resize(l);
        mint invm = mint(M).inv();
        for (int i = 0; i < l; ++i) s[i] *= invm;
        return s;
    }
};

} // namespace noya2

struct fps4724info {
    using value_type = modint4724;
    using mint = modint4724;
    static std::vector<mint> multiply(const std::vector<mint> &a, const std::vector<mint> &b){
        static number_theoretic_transform<mint> ntt;
        return ntt.multiply(a,b);
    }
    static std::vector<mint> inv(const std::vector<mint> &a, int d = -1){
        assert(false);
    }
    static std::vector<mint> integral(const std::vector<mint> &a){
        assert(false);
    }
};

using mint = modint4724;
using fps = FormalPowerSeries<fps4724info>;

int main(){
    int n; in(n);
    simple_tree g(n);
    g.input(0);
    vector<bool> done(n,false);
    fps ans(n);
    for (int ctr : centroid_decomposition(g)){
        fps f;
        auto dfs = [&](auto sfs, int v, int ff, int d) -> void {
            for (int u : g[v]){
                if (u == ff) continue;
                if (done[u]) continue;
                sfs(sfs,u,v,d+1);
            }
            if ((int)f.size() <= d){
                f.resize(d+1);
            }
            f[d] += 1;
        };
        fps sum, sq;
        for (int v : g[ctr]){
            if (done[v]) continue;
            dfs(dfs,v,ctr,1);
            sum += f;
            sq += f*f;
            f = {};
        }
        ans += (sum*sum - sq) / 2;
        ans += sum;
        done[ctr] = true;
    }
    ans.erase(ans.begin());
    out(ans);
}