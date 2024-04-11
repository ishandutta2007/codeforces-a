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
const ll llinf = 1e18, mod = 998244353, md = 998244352;
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

const int mx = 500'010;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> s(n);
	forn(i, n) cin >> s[i];
	vector<int> fir(mx), sec(mx);
	int good = 0;
	forn(i, n) {
		int c = 0, mn = 0;
		forn(j, s[i].size()) {
			if (s[i][j] == '(')
				c++;
			else c--;
			uin(mn, c);
		}
		if (mn >= 0) {
			fir[c]++;
		}
		else
			if (c <= 0 && 0 - mn <= 0 - c)
				sec[0 - c]++;
	}
	int ans = 0;
	firn(i, mx)
		ans += min(fir[i], sec[i]);
	if (sec[0] >= fir[0]) ans += fir[0];
	else ans += (fir[0] + sec[0]) / 2;
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}