/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, X1, X2, Y1, Y2, x[MAXN], y[MAXN], vx[MAXN], vy[MAXN];
double L[MAXN], R[MAXN], mx = -INF, mn = INF;

ll check(double mid, double x, double y, double vx, double vy) {
    return ((vx >= 0 && x + vx * mid > X1 || vx < 0 && x + vx * mid < X2) &&
            (vy >= 0 && y + vy * mid > Y1 || vy < 0 && y + vy * mid < Y2));
}

ll check2(double mid, double x, double y, double vx, double vy) {
    return ((vx < 0 && x + vx * mid > X1 || vx >= 0 && x + vx * mid < X2) &&
            (vy < 0 && y + vy * mid > Y1 || vy >= 0 && y + vy * mid < Y2));
}

int main() {
    fast_io;

    cin >> n >> X1 >> Y1 >> X2 >> Y2;

    for (ll i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> vx[i] >> vy[i];

        double l = 0, r = INF;
        for (ll j = 0; j < 100; j++) {
            double mid = (l + r) / 2;
            if (check(mid, x[i], y[i], vx[i], vy[i])) r = mid;
            else l = mid;
        }
        L[i] = l;

        l = 0, r = INF;
        for (ll j = 0; j < 100; j++) {
            double mid = (l + r) / 2;
            if (check2(mid, x[i], y[i], vx[i], vy[i])) l = mid;
            else r = mid;
        }
        R[i] = l;
        if (vx[i] == 0 && (x[i] <= X1 || x[i] >= X2)) return !printf("-1");
        if (vy[i] == 0 && (y[i] <= Y1 || y[i] >= Y2)) return !printf("-1");
        mx = max(mx, L[i]);
        mn = min(mn, R[i]);
    }

    if (mx >= 1e18 || mx >= mn) return !printf("-1");
    printf("%.20f", mx);

    return 0;
}
/*

*/