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
vector<pll> v;
bool viv = false;


void solve() {
	cin >> n >> m;
	v.resize(m);
	for (auto &p : v) 
		cin >> p.S >> p.F, p.F--, p.S--;
	sort(v.begin(), v.end());
	if (v.size() & 1)
		return void(cout << "NO\n");
	for (int i = 0; i < m; i += 2) {
		if (!((v[i].S == v[i + 1].S) ^ ((v[i].F & 1) == (v[i + 1].F & 1))))
			return void(cout << "NO\n");
		if (i + 2 < m && (v[i + 1].F == v[i + 2].F))
			return void(cout << "NO\n");
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