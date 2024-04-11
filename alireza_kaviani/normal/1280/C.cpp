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

ll q, n, ans1, ans2, sz[MAXN];
vector<pll> adj[MAXN];

void DFS(ll v, ll p = -1) {
    sz[v] = 1;
    //cout << v << endl;
    for (pll i : adj[v]) {
        ll u = i.X, w = i.Y;
        if (u == p) continue;
        DFS(u, v);
        sz[v] += sz[u];
        ans1 += (sz[u] % 2) * w;
        ans2 += min(sz[u], n - sz[u]) * w;
    }
    //cout << v << sep << ans1 << sep << ans2 << endl;
}

int main() {
    fast_io;

    cin >> q;
    while (q--) {
        cin >> n;
        n *= 2;
        fill(adj, adj + n + 10, vector<pll>());
        for (ll i = 1; i < n; i++) {
            ll v, u, w;
            cin >> v >> u >> w;
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
        }

        ans1 = ans2 = 0;
        DFS(1);
        cout << ans1 << sep << ans2 << endl;
    }

    return 0;
}
/*

*/