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

ll n, m, mark[MAXN], dist[MAXN], DIST[MAXN], par[MAXN], mark2[MAXN];
vector<pll> adj[MAXN];
vector<ll> vec[MAXN];
map<pll, ll> W;

void BFS(ll v) {
    fill(DIST, DIST + MAXN, INF);
    queue<ll> q;
    q.push(v);
    DIST[v] = 0;
    mark[v] = 1;

    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (pll i : adj[v]) {
            ll u = i.X, w = i.Y;
            if (DIST[u] == INF && w == 0) {
                DIST[u] = DIST[v] + 1;
                mark[u] = 1;
                par[u] = v;
                q.push(u);
            }
        }
    }
}

void BFS() {
    fill(dist, dist + MAXN, INF);
    queue<ll> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (pll i : adj[v]) {
            ll u = i.X, w = i.Y;
            if (dist[u] == INF) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

ll cmp(ll x, ll y) {
    return DIST[x] < DIST[y];
}

void FindPath() {
    pll mn = {INF, INF};
    for (ll i = 0; i < n; i++) {
        if (mark[i]) {
            mn = min(mn, pll(dist[i], DIST[i]));
        }
    }

    for (ll i = 0; i < n; i++) {
        if (mark[i] && dist[i] == mn.X) {
            vec[0].push_back(i);
            mark2[i] = 1;
        }
    }
    sort(all(vec[0]), cmp);

    for (ll i = 0; i < n; i++) {
        ll mn = 10;
        for (ll v : vec[i]) {
            for (pll j : adj[v]) {
                ll u = j.X, w = j.Y;
                if (dist[u] == dist[v] - 1) {
                    mn = min(mn, w);
                }
            }
        }
        for (ll v : vec[i]) {
            for (pll j : adj[v]) {
                ll u = j.X, w = j.Y;
                if (dist[u] == dist[v] - 1 && w == mn && mark2[u] == 0) {
                    vec[i + 1].push_back(u);
                    mark2[u] = 1;
                    par[u] = v;
                }
            }
        }
    }
}

int main() {
    fast_io;

    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
        W[{v, u}] = W[{u, v}] = w;
    }

    BFS(n - 1);
    BFS();
    FindPath();

    ll x = 0;
    vector<ll> ans;
    while (x != n - 1) {
        ans.push_back(x);
        x = par[x];
    }
    ans.push_back(n - 1);
    for (ll i = SZ(ans) - 1; i >= 1; i--) {
        if (!mark[ans[i - 1]])
            cout << W[{ans[i], ans[i - 1]}];
    }
    if (mark[0]) cout << 0;
    cout << endl << ans.size() << endl;
    for (ll i : ans) cout << i << sep;

    return 0;
}
/*

*/