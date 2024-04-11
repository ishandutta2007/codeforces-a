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
const ll SQ = 400;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, last, q, A[MAXN], R[MAXN], cnt[MAXN];
int ans[SQ][MAXN];
vector<ll> ind[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
        ind[A[i]].push_back(i);
    }
    for (ll i = 1; i <= n; i++) {
        if (i % SQ == 0) {
            ll all = 0;
            fill(cnt, cnt + MAXN, 0);
            for (ll j = i; j <= n; j++) {
                if (cnt[A[j]] < k) cnt[A[j]]++, all++;
                ans[i / SQ][j] = all;
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        ll x = lower_bound(all(ind[A[i]]), i) - ind[A[i]].begin();
        R[i] = (x + k < ind[A[i]].size() ? ind[A[i]][x + k] : INF);
    }

    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if (l > r) swap(l, r);
        last = ans[(l + SQ - 1) / SQ][r];
        for (ll i = l; i < min(r + 1, (l + SQ - 1) / SQ * SQ); i++) last += R[i] > r;
        cout << last << endl;
    }

    return 0;
}
/*

*/