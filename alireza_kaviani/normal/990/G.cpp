/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-09-06 09:09:02
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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , cnt , mark[MAXN] , A[MAXN] , pr[MAXN] , u[MAXN];
vector<int> adj[MAXN] , V[MAXN];
ll ans[MAXN];

void DFS(int v , int x){
	mark[v] = 1;
	cnt++;
	for(int u : adj[v]){
		if(!mark[u] && A[u] % x == 0)	DFS(u , x);
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	fill(u , u + MAXN , 1);
	for(int i = 2 ; i < MAXN ; i++){
		if(pr[i])	continue;
		for(int j = i ; j < MAXN ; j += i){
			u[j] *= -1;
			if(j % (i * i) == 0)	u[j] = 0;
			pr[j] = 1;
		}
	}

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		V[A[i]].push_back(i);
	}
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for(int i = 1 ; i < MAXN ; i++){
		for(int j = i ; j < MAXN ; j+= i){
			for(int v : V[j]){
				if(!mark[v]){
					cnt = 0;
					DFS(v , i);
					ans[i] += 1ll * cnt * (cnt + 1) / 2;
				}
			}
		}
		for(int j = i ; j < MAXN ; j+= i){
			for(int v : V[j]){
				mark[v] = 0;
			}
		}
	}
	for(int i = 1 ; i < MAXN ; i++){
		ll res = 0;
		for(int j = 1 ; j * i < MAXN ; j++){
			res += ans[j * i] * u[j];
		}
		if(res){
			cout << i << sep << res << endl;
		}
	}

    return 0;
}
/*








*/