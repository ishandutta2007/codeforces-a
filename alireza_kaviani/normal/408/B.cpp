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
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string s, t;
ll ans, cnts[MAXN], cntt[MAXN];

int main() {
    fast_io;

    cin >> s >> t;
    for (ll i = 0; i < SZ(s); i++) cnts[s[i]]++;
    for (ll i = 0; i < SZ(t); i++) cntt[t[i]]++;

    for (ll i = 0; i < MAXN; i++) if (cntt[i] != 0 && cnts[i] == 0) return cout << -1 << endl, 0;
    for (ll i = 0; i < MAXN; i++) ans += min(cntt[i], cnts[i]);
    cout << ans << endl;

    return 0;
}
/*

*/