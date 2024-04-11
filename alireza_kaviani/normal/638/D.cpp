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

const ll MAXN = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> g[MAXN * MAXN * MAXN], gr[MAXN * MAXN * MAXN];
ll n, m, k, ans, A[MAXN][MAXN][MAXN];

ll ind(ll x, ll y, ll z) {
    return x * (m + 1) * (k + 1) + y * (k + 1) + z;
}

int main() {
    fast_io;

    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            string s;
            cin >> s;
            s = "." + s;
            for (ll l = 1; l <= k; l++) {
                A[i][j][l] = s[l] - 48;
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            for (ll l = 1; l <= k; l++) {
                if (A[i][j][l] == 0) continue;
                if (A[i][j][l + 1]) {
                    g[ind(i, j, l)].push_back(ind(i, j, l + 1));
                    gr[ind(i, j, l + 1)].push_back(ind(i, j, l));
                }
                if (A[i][j + 1][l]) {
                    g[ind(i, j, l)].push_back(ind(i, j + 1, l));
                    gr[ind(i, j + 1, l)].push_back(ind(i, j, l));
                }
                if (A[i + 1][j][l]) {
                    g[ind(i, j, l)].push_back(ind(i + 1, j, l));
                    gr[ind(i + 1, j, l)].push_back(ind(i, j, l));
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            for (ll l = 1; l <= k; l++) {
                if (g[ind(i, j, l)].size() == 0 || gr[ind(i, j, l)].size() == 0) continue;
                ll ok = 0;
                for (ll v : g[ind(i, j, l)]) {
                    for (ll u : gr[ind(i, j, l)]) {
                        ll cnt = 0;
                        for (ll A : g[u]) {
                            for (ll B : gr[v]) {
                                if (A == B) cnt++;
                            }
                        }
                        if (cnt <= 1) ok = 1;
                    }
                }
                ans += ok;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
/*

*/