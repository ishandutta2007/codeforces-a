/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-08 19:05:03
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
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll q , n , A[MAXN] , B[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        for(ll i = 1 ; i <= n ; i++)    cin >> A[i];
        for(ll i = 1 ; i <= n ; i++)    cin >> B[i];
        ll x = 0 , y = 0 , ok = 1;
        for(ll i = 1 ; i <= n ; i++){
            //cout << B[i] - A[i] << sep << A[i] << sep << x << sep << y << endl;
            if(B[i] - A[i] > 0 && x == 0)   ok = 0;// , cout << i << endl;
            if(B[i] - A[i] < 0 && y == 0)   ok = 0;// , cout << i << endl;
            if(A[i] < 0)    y = 1;
            if(A[i] > 0)    x = 1;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
/*

*/