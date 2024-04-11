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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, k, cost, p[MAXN], root[MAXN], par[MAXN], sz[MAXN], dist[MAXN];
vector<pll> adj[MAXN];
vector<pair<ll, pll>> E;
priority_queue<pll, vector<pll>, greater<pll>> pq;

void Dijkstra() {
    fill(dist, dist + MAXN, INF);
    for (ll i = 0; i < k; i++) {
        dist[p[i]] = 0;
        root[p[i]] = p[i];
        pq.push({0, p[i]});
    }

    while (!pq.empty()) {
        ll v = pq.top().Y, d = pq.top().X;
        pq.pop();
        if (dist[v] < d) continue;

        for (pll i : adj[v]) {
            ll u = i.X, w = i.Y;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                root[u] = root[v];
                pq.push({dist[u], u});
            }
            E.push_back({dist[v] + dist[u] + w, {root[v], root[u]}});
        }
    }
}

ll Find(ll v) {
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v, ll u) {
    v = Find(v);
    u = Find(u);
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
    for (ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    cin >> k;
    for (ll i = 0; i < k; i++) cin >> p[i];

    Dijkstra();
    Sort(E);

    for (pair<ll, pll> i : E) {
        ll w = i.X, v = i.Y.X, u = i.Y.Y;
        if (Find(v) != Find(u)) {
            Union(v, u);
            cost += w;
        }
    }
    cout << cost + dist[1] << endl;

    return 0;
}
/*

*/