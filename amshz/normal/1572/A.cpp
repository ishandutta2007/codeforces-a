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
const int mod = 998244353;
const int base = 257;

int qq, n, dp[xn], d[xn], a[xn], ptr, ans;
vector <int> adj[xn];
queue <int> q;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		fill(d, d + n + 1, 0);
		fill(dp, dp + n + 1, 0);
		for (int i = 1; i <= n; ++ i){
			int s;
			cin >> s;
			adj[i].clear();
			while (s --){
				int v;
				cin >> v;
				adj[i].push_back(v);
				++ d[v];
			}
		}
		for (int i = 1; i <= n; ++ i)
			if (!d[i])
				q.push(i);
		ptr = 0;
		while (SZ(q)){
			int v = q.front();
			q.pop();
			a[++ ptr] = v;
			for (int u : adj[v]){
				-- d[u];
				if (!d[u])
					q.push(u);
			}
		}
		if (ptr < n){
			cout << - 1 << endl;
			continue;
		}
		ans = 1;
		for (int i = n; 1 <= i; -- i){
			int v = a[i];
			dp[v] = 1;
			for (int u : adj[v])
				dp[v] = max(dp[v], dp[u] + bool(v < u));
			ans = max(ans, dp[v]);
		}
		cout << ans << endl;
	}

	return 0;
}