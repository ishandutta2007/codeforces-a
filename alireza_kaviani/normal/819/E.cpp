/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-12-03 12:24:12
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

int n;
vector<vector<int>> ans;

void solve(int n){
	if(n <= 4){
		for(int i = 0 ; i < 5 - n ; i++){
			for(int j = 1 ; j <= n ; j++){
				for(int k = j + 1 ; k <= n ; k++){
					for(int l = k + 1 ; l <= n ; l++){
						ans.push_back({j , k , l});
					}
				}
			}
		}
		return;
	}
	solve(n - 2);
	ans.push_back({n - 2 , n - 1 , n});
	ans.push_back({n - 2 , n - 1 , n});
	for(int i = 1 ; i < n - 2 ; i++){
		int j = i % (n - 3) + 1;
		ans.push_back({i , n - 1 , j , n});
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	solve(n);
	cout << SZ(ans) << endl;
	for(vector<int> i : ans){
		cout << SZ(i) << sep;
		for(int j : i){
			cout << j << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/