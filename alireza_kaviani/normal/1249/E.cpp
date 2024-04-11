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

ll n , c , A[MAXN] , B[MAXN] , dp[MAXN][2];

int main() {
    fast_io;

    cin >> n >> c;
    for(ll i = 2 ; i <= n ; i++)    cin >> A[i];
    for(ll i = 2 ; i <= n ; i++)    cin >> B[i];

    dp[1][0] = INF;
    dp[1][1] = 0;
    for(ll i = 2 ; i <= n ; i++){
        dp[i][0] = min(dp[i - 1][0] , dp[i - 1][1] + c) + B[i];
        dp[i][1] = min(dp[i - 1][1] , dp[i - 1][0]) + A[i];
    }
    for(ll i = 1 ; i <= n ; i++)    cout << min(dp[i][0] , dp[i][1]) << sep;

    return 0;
}
/*

*/