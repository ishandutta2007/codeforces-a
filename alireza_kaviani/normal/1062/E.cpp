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
typedef pair<int, int> pii;
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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, q, t, st[MAXN], fn[MAXN], H[MAXN], par[LOG][MAXN];
pair<pii, pii> seg[MAXN * 4];
vector<ll> adj[MAXN];

pair<pii, pii> Merge(pair<pii, pii> A, pair<pii, pii> B) {
    pair<pii, pii> ans = {{0, 0},
                          {0, 0}};
    if (st[A.X.X] < st[B.X.X]) {
        ans.X.X = A.X.X;
        ans.X.Y = (st[A.X.Y] < st[B.X.X] ? A.X.Y : B.X.X);
    } else {
        ans.X.X = B.X.X;
        ans.X.Y = (st[A.X.X] < st[B.X.Y] ? A.X.X : B.X.Y);
    }
    if (fn[A.Y.X] > fn[B.Y.X]) {
        ans.Y.X = A.Y.X;
        ans.Y.Y = (fn[A.Y.Y] > fn[B.Y.X] ? A.Y.Y : B.Y.X);
    } else {
        ans.Y.X = B.Y.X;
        ans.Y.Y = (fn[A.Y.X] > fn[B.Y.Y] ? A.Y.X : B.Y.Y);
    }
    return ans;
}

void build(int id, int l = 0, int r = MAXN - 1) {
    if (l == r) {
        seg[id] = {{l, 0},
                   {l, 0}};
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = Merge(seg[id << 1], seg[id << 1 | 1]);
}

pair<pii, pii> get(int id, int ql, int qr, int l = 0, int r = MAXN - 1) {
    if (l > qr || r < ql)
        return {{0, 0},
                {0, 0}};
    if (ql <= l && r <= qr) return seg[id];
    ll mid = (l + r) >> 1;
    return Merge(get(id << 1, ql, qr, l, mid), get(id << 1 | 1, ql, qr, mid + 1, r));
}

void DFS(ll v, ll p = 0) {
    H[v] = H[p] + 1;
    par[0][v] = p;
    st[v] = ++t;
    for (ll u : adj[v]) DFS(u, v);
    fn[v] = t;
}

ll getPar(ll v, ll h) {
    for (ll i = 0; i < LOG; i++) {
        if (h & (1LL << i)) v = par[i][v];
    }
    return v;
}

ll LCA(ll v, ll u) {
    if (min(v, u) == 0) return max(v, u);
    if (H[v] > H[u]) swap(v, u);
    u = getPar(u, H[u] - H[v]);
    if (u == v) return u;

    for (ll i = LOG - 1; i >= 0; i--) {
        if (par[i][v] != par[i][u]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][v];
}

int main() {
    fast_io;

    cin >> n >> q;
    for (ll i = 2; i <= n; i++) {
        ll p;
        cin >> p;
        adj[p].push_back(i);
    }

    st[0] = n + 10;
    fn[0] = -1;
    DFS(1);
    for (ll i = 1; i < LOG; i++) {
        for (ll j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    build(1);
    while (q--) {
        ll l, r;
        cin >> l >> r;
        pair<pii, pii> p = get(1, l, r);
        ll L1 = LCA(p.X.Y, (p.X.X == p.Y.X ? p.Y.Y : p.Y.X)), L2 = LCA((p.X.X == p.Y.X ? p.X.Y : p.X.X), p.Y.Y);
        if (H[L1] >= H[L2]) cout << p.X.X << sep << H[L1] - 1 << endl;
        else cout << p.Y.X << sep << H[L2] - 1 << endl;
    }

    return 0;
}
/*

*/