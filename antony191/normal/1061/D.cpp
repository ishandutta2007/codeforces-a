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
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define int ll
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll x, y;
	cin >> n >> x >> y;
	vector<pair<ll, ll>> a(n);
	forn(i, n) cin >> a[i].x >> a[i].y;
	sort(all(a));
	ll ans = 0;
	multiset<ll> k;
	forn(i, n) {
		auto j = k.lower_bound(a[i].x);
		if (j == k.begin()) {
			ans = (ans + x + y * 1ll * (a[i].y - a[i].x)) % mod;
			k.insert(a[i].y);
		}
		else {
			j--;
			if (y * 1ll * (a[i].x - *j) > x) {
				ans = (ans + x + y * 1ll * (a[i].y - a[i].x)) % mod;
				k.insert(a[i].y);
			}
			else {
				ans = (ans + y * 1ll * (a[i].y - *j)) % mod;
				k.erase(j);
				k.insert(a[i].y);
			}
		}
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}