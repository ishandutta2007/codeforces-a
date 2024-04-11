#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 3e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
//#define int ll

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

bool a[500][500], b[500][500];
int n;
vector<ll> s, tmin, tmax;
void build(int v = 1, int tl = 0, int tr = n) {
	if (tl + 1 == tr) {
		tmin[v] = tmax[v] = s[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v + v, tl, m);
	build(v + v, m, tr);
	tmax[v] = max(tmax[v + v], tmax[v + v + 1]);
	tmin[v] = min(tmin[v + v], tmin[v + v + 1]);
}
ll getmn(int v, int tl, int tr, int l, int r) {
	if (l >= r) return llinf;
	if (l == tl && r == tr) return tmin[v];
	int m = (tl + tr) >> 1;
	return min(getmn(v + v, tl, m, l, min(m, r)), getmn(v + v + 1, m, tr, max(m, l), r));
}
ll getmx(int v, int tl, int tr, int l, int r) {
	if (l >= r) return llinf;
	if (l == tl && r == tr) return tmax[v];
	int m = (tl + tr) >> 1;
	return max(getmx(v + v, tl, m, l, min(m, r)), getmx(v + v + 1, m, tr, max(m, l), r));
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	forn(i, n) cin >> a[i];
	vector<ll> dp(n);
	dp[0] = a[0] % 3;
	firn(i, n) {
		ll tmp = dp[i - 1];
		ll t = min(a[i] / 2ll, tmp);
		dp[i] = (a[i] - t * 2) % 3 + (tmp - t);
		if (t > 0) t--;
		uin(dp[i], (a[i] - t * 2) % 3 + (tmp - t));
		if (t > 0) t--;
		uin(dp[i], (a[i] - t * 2) % 3 + (tmp - t));
	}
	ll sum = 0;
	forn(i, n) sum += a[i] * 1ll;
	cout << (sum - dp[n - 1]) / 3;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}