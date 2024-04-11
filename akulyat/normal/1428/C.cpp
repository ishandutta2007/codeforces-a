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
vector<ll> v;
string s;
bool viv = false;


void solve() {
	cin >> s;
	n = s.size();
	// vector<ll> sufb(n + 1, 0);
	// for (int i = n - 1; i >= 0; i--)
	// 	sufb[i] = sufb[i + 1] + (s[i] == 'B');
	// vector<ll> sufa(n + 1, 0);
	// for (int i = n - 1; i >= 0; i--)
	// 	sufa[i] = sufa[i + 1] + (s[i] == 'A');

	ll ans = 0;
	// for (int i = 0; i < n; i++)
	// 	if (s[i] == 'A' && sufa[i] <= sufb[i])
	// 		ans++;
	ll cnta, cntb;
	cnta = cntb = 0;
	for (int i = n - 1; i >= 0; i--) {
		cnta += (s[i] == 'A');
		cntb += (s[i] == 'B');
		if (viv)
			cout << cnta << ' ' << cntb << '\n';
		if (s[i] == 'A' && cntb)
			ans += 2, cnta--, cntb--;
	}
	if (viv)
		cout << "\t" << ans << endl;
	ll b = 0;
	for (auto i : s)
		b += (i == 'B');
	b -= ans / 2;

	ans += (b / 2) * 2;
	cout << n - ans << '\n';
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