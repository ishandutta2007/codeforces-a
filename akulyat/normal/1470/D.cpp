#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<vector<int>> e;
vector<int> c;
bool viv = false;

void DFS(int v) {
	c[v] = 1;
	for (auto u : e[v])
		if (c[u] == 1)
			c[v] = 0;
	for (auto u : e[v])
		if (c[u] == -1)
			DFS(u);
}

void solve() {
	cin >> n >> m;
	e.assign(n, {});
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	c.assign(n, -1);
	DFS(0);
	for (auto i : c)
		if (i == -1) 
			return void(cout << "NO\n");

	cout << "YES\n";
	vector<int> ans;
	for (int i = 0; i < n; i++)
		if (c[i] == 1)
			ans.push_back(i);
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}