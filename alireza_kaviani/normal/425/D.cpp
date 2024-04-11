/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-12-03 12:40:55
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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll SQ = 100;

int n , ans , mark[MAXN] , x[MAXN] , y[MAXN];
vector<int> vec[MAXN];

int find(int x , int y){
	return binary_search(all(vec[x]) , y);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> x[i] >> y[i];
		vec[x[i]].push_back(y[i]);
	}
	for(int i = 0 ; i < MAXN ; i++){
		sort(all(vec[i]));
		for(int j : vec[i]){
			mark[j] = 1;
		}
		if(SZ(vec[i]) > SQ){
			for(int j = 0 ; j < i ; j++){
				int x = i - j , ptr = 0;
				for(int k : vec[j]){
					while(ptr + 1 < SZ(vec[j]) && vec[j][ptr] < k - x)	ptr++;
					if(k - x == vec[j][ptr] && mark[k] && mark[k - x])	ans++;
				}
			}
		}
		else{
			for(int j = 0 ; j < SZ(vec[i]) ; j++){
				for(int k = j + 1 ; k < SZ(vec[i]) ; k++){
					int l = vec[i][k] - vec[i][j];
					if(l <= i && find(i - l , vec[i][j]) && find(i - l , vec[i][k]))	ans++;
				}
			}
		}
		for(int j : vec[i]){
			mark[j] = 0;
		}
	}
	cout << ans << endl;


    return 0;
}
/*

*/