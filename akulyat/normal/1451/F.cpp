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
vector<vector<ll>> v;
string ans[2] = {"Jeel\n", "Ashish\n"};
bool viv = false;

void clear(vector<vector<ll>> &v) {
	vector<bool> r(n), c(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j])
				r[i] = c[j] = true;
	vector<vector<ll>> res;
	for (int i = 0; i < n; i++)
		if (r[i]) {
			res.push_back({});
			for (int j = 0; j < m; j++)
				if (c[j])
					res.back().push_back(v[i][j]);
		}
	v = res;
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	ll sum = 0;
	for (auto &l : v) {
		l.resize(m);
		for (auto &i : l)
			cin >> i, sum += i;
	}
	vector<ll> sums(n + m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sums[i + j] ^= v[i][j];
	for (auto i : sums)
		if (i)
			return void(cout << ans[1]);
	return void(cout << ans[0]);
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