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

const ll MAXN = 2e5 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct Node {
    ll val = INF;

    Node(ll v = INF) {
        val = v;
    }

    friend Node merge(const Node &x, const Node &y) {
        if (x.val > y.val) return y;
        else return x;
    }
};

template<class T, ll N>
struct SegTree {
    T seg[4 * N];

    void Build(ll id, ll l, ll r, ll arr[]) {
        if (l == r) {
            seg[id] = T(arr[l]);
            return;
        }
        ll mid = (l + r) >> 1;
        Build((id << 1), l, mid, arr);
        Build((id << 1) | 1, mid + 1, r, arr);
        seg[id] = merge(seg[(id << 1)], seg[(id << 1) | 1]);
    }

    void Modify(ll id, ll l, ll r, ll x, ll val) {
        if (x < l || r < x) return;
        if (l == r) {
            seg[id] = T(val);
            return;
        }
        ll mid = (l + r) >> 1;
        Modify((id << 1), l, mid, x, val);
        Modify((id << 1) | 1, mid + 1, r, x, val);
        seg[id] = merge(seg[(id << 1)], seg[(id << 1) | 1]);
    }

    T Get(ll id, ll l, ll r, ll ql, ll qr) {
        if (qr < l || r < ql || ql > qr) return T();
        if (ql <= l && r <= qr) return seg[id];

        ll mid = (l + r) >> 1;
        return merge(Get((id << 1), l, mid, ql, qr), Get((id << 1) | 1, mid + 1, r, ql, qr));
    }

    void build(ll arr[]) {
        Build(1, 0, N - 1, arr);
    }

    void modify(ll x, ll val) {
        Modify(1, 0, N - 1, x, val);
    }

    T get(ll ql, ll qr) {
        return Get(1, 0, N - 1, ql, qr);
    }
};

ll n, k;
string s;
SegTree<Node, MAXN> dp[2];

int main() {
    fast_io;

    cin >> n >> k >> s;
    s = "." + s;

    dp[0].modify(0, 0);
    for (ll i = 1; i <= n; i++) {
        dp[0].modify(i, min(dp[1].get(max(0LL, i - k), i - 1).val, dp[0].get(i - 1, i - 1).val + i));
        if (s[i] == '1') {
            dp[1].modify(i,
                         min(dp[1].get(max(0LL, i - k - k - 1), i - 1).val, dp[0].get(max(0LL, i - k - 1), i - 1).val) +
                         i);
        }
    }
    cout << min(dp[0].get(n, n).val, dp[1].get(n, n).val) << endl;

    return 0;
}
/*

*/