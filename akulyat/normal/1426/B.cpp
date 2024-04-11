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

ll n, m;
vector<vector<vector<ll>>> v;
bool viv = false;

vector<vector<ll>> inv(vector<vector<ll>> vec) {
	vector<vector<ll>> res;
	res.resize(vec[0].size());
	for (auto &l : res)
		l.resize(vec.size());
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < vec[i].size(); j++)
			res[j][i] = vec[i][j];
	return res;
}

void solve() {
	cin >> n >> m;
	v.clear();
	v.resize(n);
	bool one = false, two = false;
	map<vector<vector<ll>>, bool> was;
	for (auto &l : v) {
		l.resize(2);
		for (auto &i : l) {
			i.resize(2);
			for (auto &j : i)
				cin >> j;
		}
		if (l[0][1] == l[1][0])
			one = true;
		was[l] = true;
		if (was.find(inv(l)) != was.end())
			two = true;
	}
	if (m == 2)
		two = true;
	if ((m & 1) || !one || !two) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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