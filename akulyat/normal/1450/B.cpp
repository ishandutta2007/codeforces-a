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

ll n, k;
vector<pll> v;
bool viv = false;

ll d(pll a, pll b) {
	return abs(a.F - b.F) + abs(a.S - b.S);
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F >> p.S;
	for (int i = 0; i < n; i++) {
		ll mx = 0;
		for (int j = 0; j < n; j++) {
			mx = max(mx, d(v[i], v[j]));
		}
		if (mx <= k) {
			cout << "1\n";
			return;
		}
	}	
	cout << "-1\n";
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