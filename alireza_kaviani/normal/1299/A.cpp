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

const ll MAXN = 1e6 + 10;
const ll LOG = 40;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, mxInd = 1, mx, A[MAXN], cnt[LOG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
        for (ll j = 0; j < LOG; j++) {
            if (A[i] & (1ll << j)) cnt[j]++;
        }
    }

    for (ll i = 1; i <= n; i++) {
        ll val = 0;
        for (ll j = 0; j < LOG; j++) {
            if (A[i] & (1ll << j)) {
                if (cnt[j] == 1) val += (1ll << j);
            }
        }
        if (val > mx) {
            mx = val;
            mxInd = i;
        }
    }

    cout << A[mxInd] << sep;
    for (ll i = 1; i <= n; i++) {
        if (i != mxInd) cout << A[i] << sep;
    }

    return 0;
}
/*

*/