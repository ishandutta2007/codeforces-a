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
const ll llinf = 1e18, mod = 1000'000'007;
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

int gcd(int a, int b) {
	if (!b) return a;
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	int l = 0, r = inf;
	while (r - l > 1) {
		int m = (r + l) >> 1;
		cout << "> " << m << endl;
		int k;
		cin >> k;
		if (k == 1) l = m;
		else r = m;
		cnt++;
	}
	int m = min(n, 60 - cnt);
	set<int> ind, val;
	forn(i, m) {
		int x = rnd() % n;
		while (ind.find(x) != ind.end())
			x = rnd() % n;
		cout << "? " << x + 1 << endl;
		int k;
		cin >> k;
		val.insert(k);
		ind.insert(x);
	}
	val.insert(r);
	vector<int> a;
	for (auto i : val) a.push_back(i);
	int g = 0;
	forn(i, a.size())
		forn(j, i)
		g = gcd(g, abs(a[i] - a[j]));
	cout << "! " << r - (n - 1) * g << ' ' << g << endl;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}