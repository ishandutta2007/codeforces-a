/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-12 18:35:02
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

const ll MAXN = 8010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , cnt , source , adj[MAXN][MAXN] , inDeg[MAXN] , mark[MAXN];
ll ans;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n; cnt = n;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin >> s;
		for(int j = 0 ; j < n / 4 ; j++){
			int x = (s[j] <= '9' ? s[j] - '0' : s[j] - 'A' + 10);
			for(int k = 0 ; k < 4 ; k++){
				if(x & (1 << k)){
					adj[i][j * 4 + 3 - k] = 1;
					inDeg[j * 4 + 3 - k]++;
				}
			}
		}
	}
	source = -1;
	while(source == -1){
		int mnDeg = -1;
		for(int i = 0 ; i < n ; i++){
			if(!mark[i] && (mnDeg == -1 || inDeg[i] < inDeg[mnDeg])){
				mnDeg = i;
			}
		}
		if(mnDeg == -1 || inDeg[mnDeg] != 0){
			source = mnDeg;
			break;
		}
		mark[mnDeg] = 1;
		ans += 1ll * (cnt - 1) * (614 * n + 1);
		cnt--;
		for(int i = 0 ; i < n ; i++){
			inDeg[i] -= adj[mnDeg][i];
		}
	}
	if(source == -1)	return cout << ans << endl , 0;
	source = max_element(inDeg , inDeg + n) - inDeg;
	ans += cnt * (cnt - 1) / 2 * 3;
	
	vector<int> A , B;
	for(int i = 0 ; i < n ; i++){
		if(mark[i])	continue;
		if(adj[source][i]){
			B.push_back(i);
		}
		else{
			A.push_back(i);
		}
	}
	fill(inDeg , inDeg + MAXN , 0);
	for(int i : A){
		for(int j : B){
			inDeg[i] += adj[j][i];
			inDeg[j] += adj[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i])	continue;
		for(int j = i + 1 ; j < n ; j++){
			if(mark[j])	continue;
			if(adj[source][i] == adj[source][j] && inDeg[i] == inDeg[j]){
				ans++;
			}
		}
	}
	cout << ans << endl;

    return 0;
}
/*

*/