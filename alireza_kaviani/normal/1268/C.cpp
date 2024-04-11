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

ll n, A[MAXN], ind[MAXN], fen[MAXN];
Tree<ll> tr;

void add(ll x, ll val) {
    for (; x < MAXN; x += x & -x) fen[x] += val;
}

ll get(ll x) {
    ll ans = 0;
    for (; x > 0; x -= x & -x) ans += fen[x];
    return ans;
}

ll C2(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    fast_io;

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
        ind[A[i]] = i;
    }

    ll invs = 0, ans = 0;
    for (ll i = 1; i <= n; i++) {
        invs += (i - 1 - ll(tr.order_of_key(ind[i])));
        tr.insert(ind[i]);
        add(ind[i], ind[i]);
        ll x = *tr.find_by_order((i - 1) / 2);
        ans = get(MAXN - 1) - get(x) * 2 - C2(i / 2) - C2((i - 1) / 2);
        cout << invs + ans + (i % 2) * x << sep;
    }

    return 0;
}
/*

*/