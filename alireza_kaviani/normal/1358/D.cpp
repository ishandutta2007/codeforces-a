/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-05-26 19:05:02
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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , x , ans , A[MAXN] , ps[MAXN] , ps2[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> x;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
        ps[i] = ps[i - 1] + A[i];
        ps2[i] = ps2[i - 1] + A[i] * (A[i] + 1) / 2;
    }
    for(int i = n + 1 ; i <= n + n ; i++){
        ps[i] = ps[i - 1] + A[i - n];
        ps2[i] = ps2[i - 1] + (A[i - n]) * (A[i - n] + 1) / 2;
    }
    for(int i = 0 ; i < n ; i++){
        int ind = lower_bound(ps , ps + n + n + 1 , ps[i] + x) - ps;
        ll S = ps[ind] - ps[i] , cost = ps2[ind] - ps2[i];
        ll k = S - x;
        ans = max(ans , cost - k * (k + 1) / 2);
    }
    cout << ans << endl;

    return 0;
}
/*

*/