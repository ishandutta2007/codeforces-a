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
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n;
vector<int> v;

bool bad(int val) {
	for (int i = 2; i < val; i++)
		if (val % i == 0)
			return false;
	return true;
}

void solve() {
	cin >> n;
	v.resize(n);
	ll sum = 0;
	for (auto &i : v)
		cin >> i, sum += i;
	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 1);
	if (bad(sum)) {
		ans.clear();
		bool nice = false;
		for (int i = 0; i < n; i++) {
			if (nice || ((v[i] & 1) == 0)) 
				ans.push_back(i + 1);
			if (v[i] & 1)
				nice = true;
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}