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

const ll MAXN = 150 + 10;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, s, cur = 1, A[MAXN], dp[2][MAXN][MAXN * MAXN];

int main() {
    fast_io;
    for (ll i = 0; i < MAXN; i++)
        fill(dp[0][i], dp[0][i] + MAXN * MAXN, INF), fill(dp[1][i], dp[1][i] + MAXN * MAXN, INF);
    dp[0][0][0] = 0;

    cin >> n >> k >> s;
    for (ll i = 1; i <= n; i++) cin >> A[i];
    if (s >= n * (n - 1) / 2) {
        sort(A + 1, A + n + 1);
        ll sum = 0;
        for (ll i = 1; i <= k; i++) sum += A[i];
        cout << sum << endl;
        return 0;
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= min(k, i); j++) {
            for (ll l = 0; l <= min(s, i * (i - 1) / 2); l++) {
                dp[cur][j][l] = min(dp[cur ^ 1][j][l],
                                    (l - i + j < 0 || j == 0 ? INF : dp[cur ^ 1][j - 1][l - i + j]) + A[i]);
            }
        }
        cur ^= 1;
    }
    cout << *min_element(dp[cur ^ 1][k], dp[cur ^ 1][k] + s + 1) << endl;

    return 0;
}
/*

*/