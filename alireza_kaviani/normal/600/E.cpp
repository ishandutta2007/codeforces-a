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

ll n, t, C[MAXN], sz[MAXN], ind[MAXN], mx[MAXN], sum[MAXN], ans[MAXN];
vector<ll> adj[MAXN];
map<ll, ll> cnt[MAXN];

void insert(ll ind, ll x, ll y) {
    cnt[ind][x] += y;
    if (cnt[ind][x] == mx[ind]) {
        sum[ind] += x;
    }
    if (cnt[ind][x] > mx[ind]) {
        mx[ind] = cnt[ind][x];
        sum[ind] = x;
    }
}

void merge(ll x, ll y) {
    for (auto &i : cnt[y]) insert(x, i.X, i.Y);
}

void DFS(ll v, ll p = -1) {
    ll mxInd = 0;
    sz[v] = 1;
    for (ll u : adj[v]) {
        if (u == p) continue;
        DFS(u, v);
        sz[v] += sz[u];
        if (sz[u] > sz[mxInd]) mxInd = u;
    }
    if (mxInd == 0) ind[v] = ++t;
    else ind[v] = ind[mxInd];
    for (ll u : adj[v]) {
        if (u == p || u == mxInd) continue;
        merge(ind[v], ind[u]);
    }
    insert(ind[v], C[v], 1);
    ans[v] = sum[ind[v]];
}

int main() {
    fast_io;

    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> C[i];
    for (ll i = 1; i < n; i++) {
        ll v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    DFS(1);
    for (ll i = 1; i <= n; i++) cout << ans[i] << sep;

    return 0;
}
/*

*/