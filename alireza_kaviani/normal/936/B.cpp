/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-10-27 11:21:02
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

int n , m , s , flag , d[MAXN] , par[MAXN] , mark[MAXN];
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
	mark[v] = 1;
	par[v] = p;
	for(int u : adj[v]){
		if(mark[u]){
			continue;
		}
		DFS(u , v);
	}
}

void DFS2(int v){
	mark[v] = 1;
	for(int i : adj[v * 2]){
		int u = i / 2;
		if(mark[u] == 1){
			flag = 1;
		}
		if(mark[u])	continue;
		DFS2(u);
	}
	mark[v] = 2;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> d[i];
		for(int j = 0 ; j < d[i] ; j++){
			int x;
			cin >> x;
			adj[i * 2].push_back(x * 2 + 1);
			adj[i * 2 + 1].push_back(x * 2);
		}
	}
	cin >> s;
	DFS(s * 2);
	for(int i = 1 ; i <= n ; i++){
		// cout << i << sep << d[i] << endl;
		if(d[i] == 0 && mark[i * 2 + 1]){
			cout << "Win" << endl;
			vector<int> ans;
			int v = i * 2 + 1;
			while(v != -1){
				ans.push_back(v / 2);
				v = par[v];
			}
			reverse(all(ans));
			for(int j : ans){
				cout << j << sep;
			}
			cout << endl;
			return 0;
		}
	}
	fill(mark , mark + MAXN , 0);
	DFS2(s);
	if(flag)	cout << "Draw" << endl;
	else	cout << "Lose" << endl;

    return 0;
}
/*

*/