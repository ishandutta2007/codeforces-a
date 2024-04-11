//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, m, k, c[xn], cnt[xn], mx, ans;
bool mark[xn];
vector <int> adj[xn], vec;

void DFS(int v){
	mark[v] = true;
	vec.push_back(v);
	++ cnt[c[v]];
	mx = max(mx, cnt[c[v]]);
	for (int u : adj[v])
		if (!mark[u])
			DFS(u);
}

int main(){
	fast_io;

	cin >> n >> m >> k, ans = n;
	for (int i = 1; i <= n; ++ i)
		cin >> c[i];
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i){
		if (mark[i])
			continue;
		vec.clear();
		mx = 0;
		DFS(i);
		ans -= mx;
		for (int v : vec)
			-- cnt[c[v]];
	}
	kill(ans);

	return 0;
}