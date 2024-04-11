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
const ll MAXM = 4e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct MaxQ {
    deque<pll> dq;

    void push(ll i, ll x) {
        while (dq.size() > 0 && dq.back().Y < x) dq.pop_back();
        dq.push_back({i, x});
    }

    void pull(ll i) {
        while (dq.size() > 0 && dq.front().X <= i) dq.pop_front();
    }

    ll getMax() {
        return dq.front().Y;
    }
};

ll n, m, d, A[MAXN], B[MAXN], T[MAXN], dp[2][MAXN];

int main() {
    fast_io;

    cin >> n >> m >> d;
    for (ll i = 1; i <= m; i++) cin >> A[i] >> B[i] >> T[i];

    for (ll i = 1; i <= m; i++) {
        ll dt = T[i] - T[i - 1];
        MaxQ Q;
        for (ll j = 1; j <= min(n, dt * d); j++) Q.push(j, dp[0][j]);
        for (ll j = 1; j <= n; j++) {
            ll ind = j + dt * d;
            if (ind <= n) Q.push(ind, dp[0][ind]);
            dp[1][j] = Q.getMax() + B[i] - abs(A[i] - j);
            Q.pull(j - dt * d);
        }

        for (ll i = 0; i < MAXN; i++) dp[0][i] = dp[1][i];
    }
    cout << *max_element(dp[0] + 1, dp[0] + n + 1) << endl;

    return 0;
}
/*

*/