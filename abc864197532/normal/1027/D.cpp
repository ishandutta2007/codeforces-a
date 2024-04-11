#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200000, logN = 18, K = 350;

set <int> adj[N];
vector <int> back_degree(N, 0);

vector <int> toposort(int n) {
	vector <int> degree(n), ans;
	queue <int> q;
	for (int i = 0; i < n; ++i) {
		degree[i] = back_degree[i];
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int v = q.front(); q.pop();
		ans.push_back(v);
		for (int u : adj[v]) {
			degree[u]--;
			if (degree[u] == 0) q.push(u);
		}
		adj[v].clear();
	}
	if (ans.size() != n) {
		ans.clear();
		ans.push_back(-1);
	}
	return ans;
}

vector <bool> vis;
vector <int> p;
int cost[N];

void dfs(int v) {
	vis[v] = true;
	p.pb(cost[v]);
	for (int u : adj[v]) if (!vis[u]) {
		dfs(u);
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int room[n];
    fop (i,0,n) cin >> cost[i];
    fop (i,0,n) cin >> room[i], room[i]--, adj[i].insert(room[i]), back_degree[room[i]]++;
    toposort(n);
    vis.assign(n, false);
    int ans = 0;
    fop (i,0,n) if (!vis[i] && adj[i].size()) dfs(i), sort(all(p)), ans += p[0], p.clear();
    cout << ans << endl;
}