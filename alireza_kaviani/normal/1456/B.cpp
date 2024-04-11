/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-11-29 10:35:01
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

int n , A[MAXN] , ans = MOD;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	if(n > 100){
		cout << 1 << endl;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++)	cin >> A[i];
	A[0] = 0 , A[n + 1] = MOD * 2;
	for(int i = 1 ; i <= n ; i++){
		int xr = 0;
		for(int j = i ; j <= n ; j++){
			xr ^= A[j];
			if(xr <  A[i - 1] || xr > A[j + 1]){
				ans = min(ans , j - i);
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		int xr1 = 0;
		for(int j = i ; j <= n ; j++){
			xr1 ^= A[j];
			int xr2 = 0;
			for(int k = j + 1 ; k <= n ; k++){
				xr2 ^= A[k];
				if(xr1 > xr2){
					ans = min(ans , k - i - 1);
				}
			}
		}
	}
	cout << (ans == MOD ? -1 : ans) << endl;

    return 0;
}
/*

*/