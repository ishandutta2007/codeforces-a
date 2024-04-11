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
const ll LOG = 22;
const ll INF = 4e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll x, y, t, ans, l, r;
vector<ll> vec, A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> l >> r;
    ll t = 1;
    while (1) {
        A.push_back(t);
        if ((INF + x - 1) / x > t) t *= x;
        else break;
    }
    t = 1;
    while (1) {
        B.push_back(t);
        if ((INF + y - 1) / y > t) t *= y;
        else break;
    }

    for (ll i : A) for (ll j : B) vec.push_back(i + j);
    vec.push_back(l - 1);
    vec.push_back(r + 1);
    Sort(vec);
    for (ll i = 0; i + 1 < SZ(vec); i++) {
        //cout << vec[i] << sep;
        if (vec[i] >= l - 1 && vec[i] <= r) ans = max(ans, vec[i + 1] - vec[i] - 1);
    }
    cout << ans << endl;

    return 0;
}
/*

*/