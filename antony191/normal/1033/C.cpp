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

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

template<typename T> bool uin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<typename T> bool uax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream & out = cerr) {
	while (begin != end) {
		out << (*begin) << ' ';
		begin++;
	}
	out << '\n';
}

template<class T> void output(T x, ostream & out = cerr) {
	output(all(x), out);
}

mt19937 rnd(time(NULL));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> ans(n, 0);
	vector<pair<int, int>> b(n);
	forn(i, n) {
		cin >> a[i];
		b[i] = {a[i], i};
	}
	sort(all(b)); reverse(all(b));
	forn(i, n) {
		int v = b[i].second;
		for (int j = v - a[v]; j >= 0 && !ans[v]; j -= a[v])
			if (a[j] > a[v] && !ans[j])
				ans[v] = 1;
		for (int j = v + a[v]; j < n && !ans[v]; j += a[v])
			if (a[j] > a[v] && !ans[j])
				ans[v] = 1;
	}
	forn(i, n)
		cout << (ans[i] ? 'A' : 'B');
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}