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
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll k, n, fact[MAXN], Inv[MAXN], inv[MAXN], val[MAXN];
string s;

ll C(ll n, ll r) {
    if (r < 0 || r > n || n < 0) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    fast_io;

    fact[0] = 1;
    inv[0] = 1;
    Inv[1] = 1;
    for (ll i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    for (ll i = 2; i < MAXN; i++) Inv[i] = (-MOD / i + MOD) * Inv[MOD % i] % MOD;
    for (ll i = 1; i < MAXN; i++) inv[i] = inv[i - 1] * Inv[i] % MOD;

    cin >> n >> k >> s;
    s = "." + s;

    for (ll i = 1; i <= n; i++) val[i] = (val[i - 1] * 10 + ll(s[i] - 48)) % MOD;
    ll ans = val[n] * C(n - 1, k);
    ll x = C(n - 2, k - 1) * 10 % MOD;
    for (ll i = n - 1; i >= 1; i--) {
        ans += val[i] * C(n - 2, k - 1) % MOD;
        ans -= val[i] * x % MOD;
        ans = (ans % MOD + MOD) % MOD;
        x += (MOD - C(i - 1, k - 1) + C(i - 2, k - 2)) * poww(10, n - i, MOD) % MOD +
             C(i - 2, k - 1) * poww(10, n - i + 1, MOD) % MOD;
        x %= MOD;
    }
    cout << ans << endl;

    return 0;
}
/*

*/