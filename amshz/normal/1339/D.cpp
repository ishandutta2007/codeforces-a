# include <bits/stdc++.h>
 
using namespace std;

/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long          ll;
typedef long double        ld;
typedef pair <int, int>    pii;
typedef pair <pii, int>    ppi;
typedef pair <pii, pii>    pip;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 3e5 + 10;
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;

ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, d[xn], Root = 1, H[xn], par[xn], ans;
vector <int> adj[xn];
bool Mark[xn], flag = true, vis[xn];

void DFS(int v){
	Mark[v] = true;
	for (int u : adj[v]){
		if (Mark[u]) continue;
		H[u] = H[v] + 1;
		par[u] = v;
		DFS(u);
	}
}


int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		++ d[v], ++ d[u];
	}
	for (int i = 1; i <= n; ++ i) if (d[i] != 1) Root = i;
	DFS(Root);
	int last = -1;
	for (int i = 1; i <= n; ++ i){
		if (d[i] > 1) continue;
		vis[par[i]] = true;
		if (last != -1 && H[i] % 2 != H[last] % 2) flag = false;
		last = i;
	}
	ans = n - 1;
	for (int i = 1; i <= n; ++ i){
		if (!vis[i]) continue;
		for (int u : adj[i]){
			if (d[u] > 1) continue;
			-- ans;
		}
		++ ans;
	}
	
	if (flag) cout << 1 << sep;
	else cout << 3 << sep;
	cout << ans << endl;
	return 0;
}