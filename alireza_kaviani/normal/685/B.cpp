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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, q, timer, mx[MAXN], st[MAXN], sz[MAXN], ans[MAXN];
pii seg[4 * MAXN];
vector<ll> adj[MAXN], A[MAXN], B[MAXN];

void modify(int id, int l, int r, int x, pii val) {
    if (x < l || x > r) return;
    if (l == r) {
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    modify(id << 1, l, mid, x, val);
    modify(id << 1 | 1, mid + 1, r, x, val);
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

pii get(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return {-INF, -INF};
    if (ql <= l && r <= qr) return seg[id];
    int mid = (l + r) / 2;
    return max(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid + 1, r, ql, qr));
}

void DFS(ll v) {
    sz[v] = 1;
    st[v] = ++timer;
    for (ll u : adj[v]) {
        DFS(u);
        sz[v] += sz[u];
        mx[v] = max(mx[v], sz[u]);
    }
}

int main() {
    fast_io;

    cin >> n >> q;
    for (ll i = 2; i <= n; i++) {
        ll p;
        cin >> p;
        adj[p].push_back(i);
    }
    DFS(1);

    for (ll i = 1; i <= n; i++) {
        A[mx[i]].push_back(i);
        B[sz[i] / 2].push_back(i);
    }

    for (ll i = 0; i < MAXN; i++) {
        for (ll j : A[i]) {
            modify(1, 0, MAXN - 1, st[j], {sz[j], j});
        }
        for (ll j : B[i]) {
            ans[j] = get(1, 0, MAXN - 1, st[j], st[j] + sz[j] - 1).Y;
        }
    }

    while (q--) {
        ll v;
        cin >> v;
        cout << ans[v] << endl;
    }

    return 0;
}
/*

*/