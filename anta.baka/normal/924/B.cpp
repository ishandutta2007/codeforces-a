//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
//#define int ll
using namespace std;
using ll = long long; using ull = unsigned ll; using ld = long double; using pii = pair<int, int>; using pll = pair<ll, ll>; using vi = vector<int>;
template<typename T> bool mind(T &x, const T &y) {if (y < x) return x = y, true; return false;}
template<typename T> bool maxd(T &x, const T &y) {if (x < y) return x = y, true; return false;}
int log2f(int x) {return 32 - __builtin_clz(x) - 1;}
const int mod = 1e9+7, mod9 = 1e9+9, infi = 1e9+100; const ll infl = 1e18L+1000, modl = 1e18L+3; const ld infd = INFINITY;

#define x(a) real(a)
#define y(a) imag(a)
using G = ll; using point = complex<G>;
istream& operator>>(istream &is, point &p){G x, y; is >> x >> y; p = {x, y}; return is;}
ostream& operator<<(ostream &os, const point &p){os << p.x() << ' ' << p.y(); return os;}
G dot(const point &a, const point &b) {return (conj(a)*b).x();}
G crs(const point &a, const point &b) {return (conj(a)*b).y();}
G ori(const point &a, const point &b, const point &c) {return crs(b-a, c-b);};
bool cmpyx(const point &a, const point &b) {return a.y()<b.y() || (a.y()==b.y()&&a.x()<b.x());};

signed main()
{
    #ifdef LOCAL
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    #endif // LOCAL
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout << fixed << setprecision(15);
    int n, u; cin >> n >> u;
    vector<int> a(n); for(auto &x : a) cin >> x;
    int r = 0;
    ld ans = -1;
    for(int i = 0; i < n-1; ++i) {
        while(r < n && a[r] - a[i] <= u) ++r;
        int e = r-1;
        if (e >= i+2) maxd(ans, ld(a[e]-a[i+1])/(a[e]-a[i]));
    }
    if (ans < 0) cout << -1;
    else cout << ans;
}