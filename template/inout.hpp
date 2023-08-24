namespace noya2 {

template<typename T> concept Scanable  = requires (ifstream &is, T &a){ is >> a; };
template<typename T> concept Printable = requires (ofstream &os, T &a){ os << a; };

template <typename Scanable> istream &operator>>(istream &is, vector<Scanable> &v);
template <typename Printable> ostream &operator<<(ostream &os, const vector<Printable> &v);

template <typename T, typename U>
requires Scanable<T> && Scanable<U>
istream &operator>>(istream &is, pair<T, U> &p){
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename U>
requires Printable<T> && Printable<U>
ostream &operator<<(ostream &os, const pair<T, U> &p){
    os << p.first << " " << p.second;
    return os;
}

template <typename Scanable>
istream &operator>>(istream &is, vector<Scanable> &v){
    for (auto &x : v) is >> x;
    return is;
}
template <typename Printable>
ostream &operator<<(ostream &os, const vector<Printable> &v){
    int s = (int)v.size();
    for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
    return os;
}

void in() {}
template <typename Scanable, class... U>
void in(Scanable &t, U &...u){
    cin >> t;
    in(u...);
}

void out() { cout << "\n"; }
template <typename Printable, class... U, char sep = ' '>
void out(const Printable &t, const U &...u){
    cout << t;
    if (sizeof...(u)) cout << sep;
    out(u...);
}
template<typename Printable>
void out(const vector<vector<Printable>> &vv){
    int s = (int)vv.size();
    for (int i = 0; i < s; i++) out(vv[i]);
}

struct IoSetup {
    IoSetup(){
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
        cerr << fixed << setprecision(7);
    }
} iosetup_noya2;

} // namespace noya2