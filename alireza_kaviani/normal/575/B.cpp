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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, v[MAXN], u[MAXN], w[MAXN], A[MAXN], par[LOG][MAXN], H[MAXN], ps[MAXN], ps2[MAXN];
vector<ll> adj[MAXN];

void DFS(ll v, ll p = 0) {
    H[v] = H[p] + 1;
    par[0][v] = p;
    for (ll u : adj[v]) if (u != p) DFS(u, v);
}

ll getPar(ll v, ll h) {
    for (ll i = 0; i < LOG; i++) {
        if (h & (1ll << i)) v = par[i][v];
    }
    return v;
}

ll LCA(ll v, ll u) {
    if (H[v] > H[u]) swap(v, u);
    u = getPar(u, H[u] - H[v]);
    if (u == v) return u;
    for (ll i = LOG - 1; i >= 0; i--) {
        if (par[i][v] != par[i][u]) {
            v = par[i][v];
            u = par[i][u];
        }
    }
    return par[0][v];
}

void DFS2(ll v, ll p = 0) {
    for (ll u : adj[v]) {
        if (u != p) {
            DFS2(u, v);
            ps[v] += ps[u];
            ps2[v] += ps2[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i = 1; i < n; i++) {
        cin >> v[i] >> u[i] >> w[i];
        adj[v[i]].push_back(u[i]);
        adj[u[i]].push_back(v[i]);
    }
    DFS(1);

    for (ll i = 1; i < LOG; i++) {
        for (ll j = 0; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    A[0] = 1;
    //for(ll i = 1 ; i <= n ; i++)    cout << par[0][i] << sep;
    //cout << endl;
    cin >> k;
    for (ll i = 1; i <= k; i++) cin >> A[i];
    for (ll i = 0; i < k; i++) {
        ll v = A[i], u = A[i + 1];
        ll lca = LCA(v, u);
        //cout << v << sep << u << sep << lca << endl;
        ps[v]++;
        ps2[u]++;
        ps[lca]--;
        ps2[lca]--;
        //cout << v << sep << u << sep << lca << endl;
    }
    //for(ll i = 1 ; i <= n ; i++)    cout << ps[i] << sep << ps2[i] << endl;
    DFS2(1);

    ll ans = 0;
    //for(ll i = 0 ; i <= n ; i++)    cout << ps[i] << sep << ps2[i] << endl;
    for (ll i = 1; i < n; i++) {
        //cout << i << sep << v[i] << sep << u[i] << sep << w[i] << sep;
        //cout << H[v[i]] << sep << H[u[i]] << sep << ps[u[i]] << sep << ps2[v[i]] << endl;
        ans += w[i] * (poww(2, (H[v[i]] < H[u[i]] ? ps[u[i]] : ps2[v[i]]), MOD) - 1) % MOD;
        //cout << u[i] << sep << ps[u[i]] << endl;
    }
    cout << ans % MOD << endl;

    return 0;
}
/*

*/