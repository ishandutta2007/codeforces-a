/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: AmShZ6
 * Time: 2020-05-31 19:05:01
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
typedef pair<int, int> pii;

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

const ll MAXN = 2e3 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll q , n , dp[MAXN][MAXN] , cnt[MAXN];
string s , t;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> s >> t; s = "." + s; t = "." + t;
        for(int i = 0 ; i <= n ; i++)   for(int j = 0 ; j <= n ; j++)   dp[i][j] = 0;
        for(int i = 1 ; i <= n ; i++){
            ll diff = 0;
            for(int j = 1 ; j <= i ; j++)   cnt[s[j]]++;
            for(int j = 1 ; j <= n ; j++){
                cnt[t[j]]--;
                if(cnt[t[j]] == -1) diff++ , cnt[t[j]] = 0;
                if(s[i] == t[j] && i + diff <= j)   dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[i][j] = max(dp[i][j] , dp[i - 1][j]);
                dp[i][j] = max(dp[i][j] , dp[i][j - 1]);
            }
        }
        sort(all(s)) ; sort(all(t));
        if(s != t)  cout << -1 << endl;
        else    cout << n - dp[n][n] << endl;
    }

    return 0;
}
/*

*/