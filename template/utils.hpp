namespace noya2{

unsigned long long inner_binary_gcd(unsigned long long a, unsigned long long b){
    if (a == 0 || b == 0) return a + b;
    int n = __builtin_ctzll(a);
    int m = __builtin_ctzll(b);
    a >>= n;
    b >>= m;
    while (a != b) {
        int m = __builtin_ctzll(a - b);
        bool f = a > b;
        unsigned long long c = f ? a : b;
        b = f ? b : a;
        a = (c - b) >> m;
    }
    return a << min(n, m);
}

template<typename T>
T gcd_fast(T a, T b){
    return static_cast<T>(inner_binary_gcd(abs(a),abs(b)));
}

template<typename T>
T floor_div(const T n, const T d) {
    assert(d != 0);
    return n / d - static_cast<T>((n ^ d) < 0 && n % d != 0);
}

template<typename T>
T ceil_div(const T n, const T d) {
    assert(d != 0);
    return n / d + static_cast<T>((n ^ d) >= 0 && n % d != 0);
}

template<typename T> void uniq(vector<T> &v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}

template <typename T, typename U>
inline bool chmin(T &x, U y) {
    return (y < x) ? (x = y, true) : false;
}

template <typename T, typename U>
inline bool chmax(T &x, U y) {
    return (x < y) ? (x = y, true) : false;
}

template<typename T>
inline bool range(T l, T x, T r){
    return l <= x && x < r;
}

} // namespace noya2