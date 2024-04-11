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

const ll MAXN = 15;
const ll MAXM = 2e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll q, n, m, A[MAXM][MAXN], dp[(1LL << MAXN)];

int main() {
    fast_io;

    cin >> q;
    while (q--) {
        cin >> n >> m;
        fill(dp, dp + (1LL << n), 0);

        vector<pll> vec;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) cin >> A[j][i], vec.push_back({A[j][i], j});
        }
        sort(all(vec), greater<pll>());

        set<ll> st;
        for (ll i = 0; i < min(SZ(vec), n * n); i++) {
            st.insert(vec[i].Y);
            if (st.size() >= n) break;
        }

        for (auto &i : st) {
            for (ll j = 0; j < (1 << n); j++) {
                for (ll k = 0; k < n; k++) {
                    if ((j & (1LL << k)) == 0) {
                        dp[j | (1LL << k)] = max(dp[j | (1LL << k)], dp[j] + A[i][k]);
                    }
                }
            }

            for (ll j = 0; j < (1LL << n); j++) {
                ll x = j, ans = 0;
                for (ll k = 0; k < n * 2; k++) {
                    ans = max(ans, dp[x]);
                    dp[x] = ans;
                    x = x / 2 + (x % 2) * (1LL << (n - 1));
                }
            }
        }

        cout << *max_element(dp, dp + (1LL << n)) << endl;
    }

    return 0;
}
/*

*/