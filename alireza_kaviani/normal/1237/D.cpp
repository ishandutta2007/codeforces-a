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
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], cnt[MAXN];
set<ll> bad;
vector<ll> Bad[MAXN];
vector<pll> vec;

int main() {
    fast_io;

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
        vec.push_back({A[i], i});
    }

    Sort(vec);
    for (ll i = 0; i < n; i++) {
        ll x = vec[i].X, y = vec[i].Y;
        for (ll j : Bad[i]) bad.insert(j);
        auto it = bad.lower_bound(y);
        if (it == bad.end()) cnt[y] = INF;
        else {
            cnt[y] = (*it) - y;
        }
        ll z = lower_bound(all(vec), pll(2 * x + 1, -INF)) - vec.begin();
        Bad[z].push_back(y);
        Bad[z].push_back(n + y);
    }

    set<ll> st;
    for (ll i = vec.size() - 1; i >= 0; i--) {
        ll x = vec[i].X, y = vec[i].Y;
        auto it = st.lower_bound(y);
        if (it != st.end()) {
            ll z = (*it);
            cnt[y] = min(cnt[y], cnt[(z > n ? z - n : z)] + z - y);
        }
        st.insert(y);
        st.insert(y + n);
    }
    for (ll i = 1; i <= n; i++) cout << (cnt[i] >= INF ? -1 : cnt[i]) << sep;

    return 0;
}
/*

*/