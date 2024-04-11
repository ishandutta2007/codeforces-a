#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 350;

vector <int> adj[N];
vector <int> a(N);
map <int, int> m1[N];
int ans = 0;
vector <int> fa[N];

void dfs(int v, int pa) {
	for (int u : adj[v]) if (u != pa) {
		dfs(u, v);
	}
	for (int i : fa[a[v]]) {
		int xx = 0, yy = 0;
		for (int u : adj[v]) if (u != pa) {
			if (m1[u].count(i)) {
				int k = m1[u][i];
				if (xx <= k) tie(xx, yy) = mp(k, xx);
				else if (yy <= m1[u][i]) yy = k;
			}
		}
		m1[v][i] = xx + 1;
		ans = max(ans, xx + yy + 1);
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,2,N) if (fa[i].size() == 0) for (int j = i; j < N; j += i) fa[j].pb(i);
    int n, u, v;
    cin >> n;
    fop (i,0,n) cin >> a[i];
    fop (i,0,n - 1) {
    	cin >> u >> v;
    	u--; v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
	}
	dfs(0, -1);
	cout << ans << endl; 
}