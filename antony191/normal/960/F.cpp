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
const ll llinf = 1e18, mod = 998'244'353ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

const int maxn = 100000;
map<int, int> a[maxn];
inline void biba(int v, int k, int w) {
	auto j = a[v].upper_bound(w);
	if (j == a[v].begin() || ((--j)->y < k)) {
		j = a[v].upper_bound(w);
		while (j != a[v].end() && j->y <= k) {
			a[v].erase(j);
			j = a[v].upper_bound(w);
		}
		a[v][w] = k;
	}
}
void upd(int v, int u, int w) {
	auto i = a[u].lower_bound(w);
	if (i == a[u].begin()) {
		biba(v, 1, w);
	}
	else {
		i--;
		biba(v, i->y + 1, w);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	forn(i, m) {
		int v, u, w;
		cin >> v >> u >> w;
		v--; u--;
		upd(u, v, w);
	}
	int ans = 0;
	forn(i, n) {
		if (!a[i].empty())
			uax(ans, a[i].rbegin()->y);
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}