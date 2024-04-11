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
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5000 + 10;
const ll MAXM = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, ans, A[MAXN], dp[MAXN][MAXN];
vector<ll> v[MAXM], v2[MAXM];

ll calc(ll i, ll j) {
    if (i == j && i != 0) return -INF;
    if (i < j) swap(i, j);
    return dp[i][j] + 1;
}

ll solve(ll &j, vector<ll> &vec) {
    if (SZ(vec) == 1) return calc(j, vec[0]);
    if (SZ(vec) == 2) return max(calc(j, vec.back()), calc(j, vec[SZ(vec) - 2]));
    return max({calc(j, vec.back()), calc(j, vec[SZ(vec) - 2]), calc(j, vec[SZ(vec) - 3])});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 1; i < MAXN; i++) for (ll j = 1; j < MAXN; j++) dp[i][j] = -INF;

    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> A[i];

    for (ll i = 0; i < MAXM; i++) v[i].push_back(0), v2[i].push_back(0);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < i; j++) {
            dp[i][j] = max(dp[i][j], solve(j, v[A[i] - 1]));
            dp[i][j] = max(dp[i][j], solve(j, v[A[i] + 1]));
            dp[i][j] = max(dp[i][j], solve(j, v2[A[i] % 7]));
            ans = max(ans, dp[i][j]);
        }
        v[A[i]].push_back(i);
        v2[A[i] % 7].push_back(i);
    }
    cout << ans << endl;

    return 0;
}
/*

*/