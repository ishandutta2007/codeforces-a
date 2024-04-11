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

vector<ll> ans, adj[MAXN];
ll n, m, mark[MAXN], cur[MAXN], x[MAXN];

void DFS(ll v, ll p = 0) {
    cur[v] ^= 1;
    mark[v] = 1;
    ans.push_back(v);
    for (ll u : adj[v]) {
        if (mark[u]) continue;
        DFS(u, v);
    }
    if (cur[v] != x[v]) {
        if (p == 0) ans.pop_back();
        else {
            ans.push_back(p);
            ans.push_back(v);
        }
        cur[p] ^= 1;
        cur[v] ^= 1;
    }
    ans.push_back(p);
    cur[p] ^= 1;
}

int main() {
    fast_io;

    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (ll i = 1; i <= n; i++) cin >> x[i];

    for (ll i = 1; i <= n; i++) {
        if (x[i] == 1) {
            DFS(i);
            break;
        }
    }
    for (ll i = 1; i <= n; i++) if (x[i] != cur[i]) return cout << -1 << endl, 0;

    if (ans.size() > 0 && ans.back() == 0) ans.pop_back();
    cout << ans.size() << endl;
    for (ll i : ans) cout << i << sep;

    return 0;
}
/*

*/