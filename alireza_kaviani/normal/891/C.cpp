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

ll n, m, q, v[MAXN], u[MAXN], w[MAXN], sz[MAXN], par[MAXN], ok[MAXN], x[MAXN];
vector<ll> E[MAXN];

ll Find(ll v) {
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v, ll u) {
    v = Find(v), u = Find(u);
    if (v == u) return;
    if (sz[v] < sz[u]) swap(v, u);
    par[u] = v;
    sz[v] += sz[u];
}

int main() {
    fast_io;
    fill(par, par + MAXN, -1);
    fill(sz, sz + MAXN, 1);

    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        cin >> v[i] >> u[i] >> w[i];
        E[w[i]].push_back(i);
    }

    for (ll i = 0; i < MAXN; i++) {
        for (ll j : E[i]) {
            v[j] = Find(v[j]);
            u[j] = Find(u[j]);
        }
        for (ll j : E[i]) Union(v[j], u[j]);
    }

    for (ll i = 1; i <= m; i++) if (v[i] > u[i]) swap(v[i], u[i]);

    fill(par, par + MAXN, -1);
    fill(sz, sz + MAXN, 1);
    cin >> q;
    while (q--) {
        ll k, ans = 1;
        cin >> k;
        for (ll i = 0; i < k; i++) {
            cin >> x[i];
            if (Find(v[x[i]]) == Find(u[x[i]])) ans = 0;
            Union(v[x[i]], u[x[i]]);
        }
        cout << (ans ? "YES" : "NO") << endl;

        for (ll i = 0; i < k; i++) {
            par[v[x[i]]] = par[u[x[i]]] = -1;
            sz[v[x[i]]] = sz[u[x[i]]] = 1;
        }
    }


    return 0;
}
/*

*/