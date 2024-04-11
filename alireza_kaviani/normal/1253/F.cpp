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

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, k, q, mark[MAXN], dist[MAXN], root[MAXN], par[MAXN], ans[MAXN];
set<ll> ver[MAXN];
vector<pll> adj[MAXN], Q[MAXN];
vector<pair<ll, pll>> E, E2;

void Dijkstra() {
    fill(dist, dist + MAXN, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (ll i = 1; i <= k; i++) {
        dist[i] = 0;
        root[i] = i;
        pq.push({dist[i], i});
    }

    while (!pq.empty()) {
        ll v = pq.top().Y;
        pq.pop();
        if (mark[v]) continue;
        mark[v] = 1;
        for (pll i : adj[v]) {
            ll u = i.X, w = i.Y;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                root[u] = root[v];
                pq.push({dist[u], u});
            }
        }
    }
}

ll Find(ll v) {
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v, ll u, ll w) {
    //cout << v << sep << u << sep << w << sep;
    v = Find(v), u = Find(u);
    //cout << v << sep << u << sep << w << endl;
    if (u == v) return;
    if (SZ(ver[v]) < SZ(ver[u])) swap(v, u);
    for (auto &i : ver[u]) {
        for (pll j : Q[i]) {
            if (ver[v].find(j.Y) != ver[v].end()) ans[j.X] = w;
        }
    }
    for (auto &i : ver[u]) ver[v].insert(i);
    par[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(par, par + MAXN, -1);
    for (ll i = 0; i < MAXN; i++) ver[i].insert(i);

    cin >> n >> m >> k >> q;
    for (ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        E.push_back({w, {v, u}});
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    for (ll i = 0; i < q; i++) {
        ll v, u;
        cin >> v >> u;
        Q[v].push_back({i, u});
        Q[u].push_back({i, v});
    }

    Dijkstra();
    Sort(E);
    //for(ll i = 1 ; i <= n ; i++)    cout << i << sep << dist[i] << sep << root[i] << endl;
    for (pair<ll, pll> i : E) {
        ll w = i.X, v = i.Y.X, u = i.Y.Y;
        if (root[u] != root[v]) E2.push_back({dist[v] + dist[u] + w, {root[v], root[u]}});
    }
    Sort(E2);
    for (pair<ll, pll> i : E2) {
        ll w = i.X, v = i.Y.X, u = i.Y.Y;
        Union(v, u, w);
    }
    for (ll i = 0; i < q; i++) cout << ans[i] << endl;

    return 0;
}
/*

*/