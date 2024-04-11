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

const ll MAXN = 500 + 10;
const ll ALPHA = 26;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, cost[MAXN][ALPHA][2], dp[MAXN][ALPHA][ALPHA];
pll prv[MAXN][ALPHA][ALPHA];
string s[MAXN];

int main() {
    fast_io;

    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> s[i];
        for (ll j = 0; j < m; j++) cost[i][s[i][j] - 97][j % 2]++;
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < ALPHA; j++) {
            for (ll k = 0; k < ALPHA; k++) {
                dp[i][j][k] = INF;
                if (j == k) continue;
                for (ll l = 0; l < ALPHA; l++) {
                    if (l == j) continue;
                    for (ll I = 0; I < ALPHA; I++) {
                        if (I == k) continue;
                        if (dp[i][j][k] > dp[i - 1][l][I] + m - cost[i][j][0] - cost[i][k][1]) {
                            dp[i][j][k] = dp[i - 1][l][I] + m - cost[i][j][0] - cost[i][k][1];
                            prv[i][j][k] = {l, I};
                        }
                    }
                }
            }
        }
    }

    ll x = 0, y = 0;
    for (ll i = 0; i < ALPHA; i++) {
        for (ll j = 0; j < ALPHA; j++) {
            if (dp[n][i][j] < dp[n][x][y]) {
                x = i;
                y = j;
            }
        }
    }

    cout << dp[n][x][y] << endl;
    vector<pll> vec;
    vec.push_back({x, y});
    for (ll i = n; i > 1; i--) {
        pll t = prv[i][x][y];
        x = t.X, y = t.Y;
        vec.push_back({x, y});
    }
    reverse(all(vec));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) cout << (j % 2 == 0 ? char(vec[i].X + 97) : char(vec[i].Y + 97));
        cout << endl;
    }

    return 0;
}
/*

*/