/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-06 20:33:33
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

const ll MAXN = 1e6 + 10;
const ll LOG = 32;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , ans , val[MAXN] , A[MAXN] , B[MAXN];
map<ll , ll> cntA[LOG] , cntB[LOG] , cnt;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> A[0];
    for(ll i = 0 ; i < LOG ; i++)   val[i] = (1ll << (i + 1)) - 1;
    for(ll i = 0 ; i < n ; i++){
        cin >> A[i];
        cnt[A[i]]++;
        for(ll j = 0 ; j < LOG ; j++)   cntA[j][A[i] & val[j]]++;
    }
    cin >> m >> B[0];
    for(ll i = 0 ; i < m ; i++){
        cin >> B[i];
        cnt[B[i]]++;
        for(ll j = 0 ; j < LOG ; j++)   cntB[j][B[i] & val[j]]++;
    }

    for(ll i = 0 ; i < LOG ; i++){
        for(auto &j : cntA[i])  ans = max(ans , j.Y + cntB[i][j.X ^ (1LL << i)]);
        for(auto &j : cntB[i])  ans = max(ans , j.Y);
    }
    for(auto i : cnt)   ans = max(ans , i.Y);
    cout << ans << endl;

    return 0;
}
/*

*/