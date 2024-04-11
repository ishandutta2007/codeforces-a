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

ll n;
vector<pll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F;
	for (auto &p : v)
		cin >> p.S;
	sort(v.begin(), v.end());
	reverse(v.rbegin(), v.rend());
	vector<ll> sum(1, 0);
	for (auto p : v)
		sum.push_back(sum.back() + p.S);
	reverse(v.rbegin(), v.rend());
	reverse(sum.rbegin(), sum.rend());

	ll ans = sum[0];
	for (int i = 0; i < n; i++) {
		ll lans = max(v[i].F, sum[i + 1]);
		ans = min(ans, lans);		
	}
	cout << ans << '\n';
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