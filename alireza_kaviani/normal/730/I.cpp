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

const ll MAXN = 3e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, p, s, cost, A[MAXN], B[MAXN], C[MAXN], mark[MAXN], dp[MAXN][MAXN], prv[MAXN][MAXN];
set<pll> st;
pair<ll, pll> skill[MAXN];
vector<ll> sp, pr;

int main() {
    fast_io;
    for (ll i = 0; i < MAXN; i++) {
        for (ll j = 0; j < MAXN; j++) {
            prv[i][j] = -1;
        }
    }

    cin >> n >> p >> s;
    for (ll i = 1; i <= n; i++) cin >> A[i];
    for (ll i = 1; i <= n; i++) cin >> B[i];
    for (ll i = 1; i <= n; i++) skill[i] = {A[i], {B[i], i}};
    sort(skill + 1, skill + n + 1, greater<pair<ll, pll>>());
    for (ll i = 1; i <= n; i++) A[i] = skill[i].X, B[i] = skill[i].Y.X, C[i] = skill[i].Y.Y;

    for (ll i = 1; i <= p; i++) cost += A[i], st.insert({A[i] - B[i], C[i]});
    dp[p][0] = cost;
    for (ll i = p + 1; i <= n; i++) {
        cost += A[i];
        st.insert({A[i] - B[i], C[i]});
        pll x = *st.begin();
        cost -= x.X;
        st.erase(x);
        dp[i][i - p] = cost;
        prv[i][i - p] = x.Y;
    }

    for (ll i = p; i <= n; i++) {
        for (ll j = 0; j < i - p; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1] + B[i] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + B[i];
                prv[i][j] = C[i];
            }
        }
    }

    cout << dp[n][s] << endl;
    for (ll i = n; i >= 0; i--) {
        if (s == 0) break;
        if (prv[i][s] == -1) continue;
        sp.push_back(prv[i][s]);
        mark[sp.back()] = 1;
        s--;
    }

    for (ll i = 1; i <= n; i++) {
        if (p == 0) break;
        if (!mark[C[i]]) {
            p--;
            pr.push_back(C[i]);
        }
    }

    Sort(pr);
    Sort(sp);

    for (ll i : pr) cout << i << sep;
    cout << endl;
    for (ll i : sp) cout << i << sep;
    cout << endl;

    return 0;
}
/*

*/