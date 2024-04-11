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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, h, ans, B[MAXN], A[MAXN];
int seg[MAXN << 2], lz[MAXN << 2];

void shift(int id) {
    lz[id << 1] += lz[id];
    lz[id << 1 | 1] += lz[id];
    seg[id << 1] += lz[id];
    seg[id << 1 | 1] += lz[id];
    lz[id] = 0;
}

void update(int ql, int qr, int x, int id = 1, int l = 0, int r = MAXN) {
    if (qr <= l || r <= ql || qr <= ql) return;
    if (ql <= l && r <= qr) {
        lz[id] += x;
        seg[id] += x;
        return;
    }
    shift(id);
    int mid = l + r >> 1;
    update(ql, qr, x, id << 1, l, mid);
    update(ql, qr, x, id << 1 | 1, mid, r);
    seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

int get(int ql, int qr, int id = 1, int l = 0, int r = MAXN) {
    if (qr <= l || r <= ql) return int(1e9);
    if (ql <= l && r <= qr) return seg[id];
    shift(id);
    int mid = l + r >> 1;
    return min(get(ql, qr, id << 1, l, mid), get(ql, qr, id << 1 | 1, mid, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> h;
    A[0] = B[0] = -INF;
    for (ll i = 1; i <= m; i++) cin >> B[i];
    for (ll i = 1; i <= n; i++) cin >> A[i];
    for (ll i = 1; i <= n; i++) update(i, i + 1, -i);
    sort(B + 1, B + m + 1);
    for (ll i = 1; i < m; i++) update(lower_bound(B, B + m + 1, h - A[i]) - B, m + 2, 1);
    for (ll i = m; i <= n; i++) {
        update(lower_bound(B, B + m + 1, h - A[i - m]) - B, m + 2, -1);
        update(lower_bound(B, B + m + 1, h - A[i]) - B, m + 2, 1);
        ans += get(1, m + 1) >= 0;
    }
    cout << ans << endl;

    return 0;
}
/*

*/