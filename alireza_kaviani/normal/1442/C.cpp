/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-11-02 18:07:59
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
const ll LOG = 20;
const ll INF = 1e18;
const ll MOD = 998244353; // 1e9 + 9;

ll n , m , dist[MAXN];
vector<int> adj[2][MAXN];
priority_queue<pll , vector<pll> , greater<pll>> pq;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(dist , dist + MAXN , INF);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		adj[0][v].push_back(u);
		adj[1][u].push_back(v);
	}
	dist[1] = 0;
	ll ans = INF;
	for(int i = 0 ; i < LOG ; i++){
		int ind = i % 2;
		for(int j = 1 ; j <= n ; j++){
			if(i > 0){
				dist[j] += (1 << (i - 1));
			}
			pq.push({dist[j] , j});
		}
		while(!pq.empty()){
			int v = pq.top().Y; pq.pop();
			for(int u : adj[ind][v]){
				if(dist[u] > dist[v] + 1){
					dist[u] = dist[v] + 1;
					pq.push({dist[u] , u});
				}
			}
		}
		ans = min(ans , dist[n]);
	}
	if(ans < INF){
		cout << ans % MOD << endl;
		return 0;
	}
	fill(dist , dist + MAXN , INF);
	dist[1 * 2 + 0] = 0;
	pq.push({dist[2] , 2});
	while(!pq.empty()){
		int v = pq.top().Y; pq.pop();
		// cout << v << sep << dist[v] << endl;
		int ind = v % 2 , num = v / 2;
		if(dist[v] + MAXN < dist[(v ^ 1)]){
			dist[v ^ 1] = dist[v] + MAXN;
			pq.push({dist[(v ^ 1)] , (v ^ 1)});
		}
		for(int u : adj[ind][num]){
			if(dist[u * 2 + ind] > dist[v] + 1){
				dist[u * 2 + ind] = dist[v] + 1;
				pq.push({dist[u * 2 + ind] , u * 2 + ind});
			}
		}
	}
	ll res = min(dist[n * 2] , dist[n * 2 + 1]);
	cout << (res % MAXN + poww(2 , res / MAXN , MOD) - 1) % MOD;

    return 0;
}
/*

*/