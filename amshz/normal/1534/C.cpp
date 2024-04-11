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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 4e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, ans, a[xn], b[xn];
vector <int> adj[xn];
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	for (int u : adj[v])
		if (!mark[u])
			DFS(u);
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n, ans = 1;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], adj[i].clear(), mark[i] = false;
		for (int i = 1; i <= n; ++ i){
			cin >> b[i];
			adj[a[i]].push_back(b[i]);
			adj[b[i]].push_back(a[i]);
		}
		for (int i = 1; i <= n; ++ i)
			if (!mark[i])
				DFS(i), ans = 2ll * ans % mod;
		cout << ans << endl;
	}

	return 0;
}