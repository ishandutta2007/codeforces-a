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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, q, C[MAXN], H[MAXN];
int par[LOG][MAXN], vertex[LOG][MAXN][LOG], ans[LOG], ind[MAXN];
vector<ll> adj[MAXN];

void DFS(ll v, ll p = 0) {
    par[0][v] = p;
    H[v] = H[p] + 1;
    for (ll u : adj[v]) if (u != p) DFS(u, v);
}

int getPar(ll v, ll h) {
    for (ll i = 0; i < LOG; i++) {
        if (h & (1LL << i)) {
            merge(vertex[i][v], vertex[i][v] + 10, ans, ans + 10, ans + 10);
            copy(ans + 10, ans + 20, ans);
            v = par[i][v];
        }
    }
    return v;
}

int LCA(ll v, ll u) {
    if (H[v] > H[u]) swap(v, u);
    u = getPar(u, H[u] - H[v]);
    if (u == v) {
        merge(vertex[0][v], vertex[0][v] + 10, ans, ans + 10, ans + 10);
        copy(ans + 10, ans + 20, ans);
        return v;
    }
    for (ll i = LOG - 1; i >= 0; i--) {
        if (par[i][v] != par[i][u]) {
            merge(vertex[i][v], vertex[i][v] + 10, ans, ans + 10, ans + 10);
            copy(ans + 10, ans + 20, ans);
            merge(vertex[i][u], vertex[i][u] + 10, ans, ans + 10, ans + 10);
            copy(ans + 10, ans + 20, ans);
            u = par[i][u];
            v = par[i][v];
        }
    }
    merge(vertex[1][v], vertex[1][v] + 10, ans, ans + 10, ans + 10);
    copy(ans + 10, ans + 20, ans);
    merge(vertex[0][u], vertex[0][u] + 10, ans, ans + 10, ans + 10);
    copy(ans + 10, ans + 20, ans);
    return par[0][v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (ll i = 1; i < n; i++) {
        ll v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (ll i = 0; i <= n; i++) fill(vertex[0][i], vertex[0][i] + LOG, INF);
    for (ll i = 1; i <= m; i++) {
        ll x;
        cin >> x;
        vertex[0][x][ind[x]++] = i;
        ind[x] = min(ind[x], 10);
        sort(vertex[0][x], vertex[0][x] + LOG);
    }
    DFS(1);

    for (ll i = 1; i < LOG; i++) {
        for (ll j = 0; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
            merge(vertex[i - 1][j], vertex[i - 1][j] + 10, vertex[i - 1][par[i - 1][j]],
                  vertex[i - 1][par[i - 1][j]] + 10, vertex[i][j]);
        }
    }

    while (q--) {
        ll v, u, a;
        cin >> v >> u >> a;
        fill(ans, ans + LOG, INF);
        ll x = LCA(v, u);
        ll sz = lower_bound(ans, ans + 10, INF) - ans;
        cout << min(sz, a) << sep;
        for (ll i = 0; i < min(sz, a); i++) cout << ans[i] << sep;
        cout << endl;
    }

    return 0;
}
/*

*/