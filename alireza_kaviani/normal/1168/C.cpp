/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-09 15:26:31
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

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

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , dp[MAXN][LOG] , prv[LOG] , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q;
    fill(prv , prv + LOG , n + 1);
    for(ll i = 1 ; i <= n ; i++)    cin >> A[i];
    fill(dp[n + 1] , dp[n + 1] + LOG , INF);
    for(ll i = n ; i >= 1 ; i--){
        fill(dp[i] , dp[i] + LOG , INF);
        for(ll j = 0 ; j < LOG ; j++){
            if(A[i] & (1 << j)){
                dp[i][j] = i;
                ll x = prv[j];
                prv[j] = i;
                for(ll k = 0 ; k < LOG ; k++)   dp[i][k] = min(dp[i][k] , dp[x][k]);
            }
        }
    }

    while(q--){
        ll v , u;
        cin >> v >> u;
        ll ok = 0;
        for(ll i = 0 ; i < LOG ; i++){
            if(A[u] & (1 << i)) if(dp[v][i] <= u)   ok = 1;
        }
        cout << (ok ? "Shi" : "Fou") << endl;
    }

    return 0;
}
/*

*/