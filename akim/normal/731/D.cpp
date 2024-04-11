#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

void initialization() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(time(0));
	const string file = useinout().sc.fs;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
	if(useinout().sc.sc) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
}

int solve();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	initialization();
	int exitval = solve();
	finish(exitval);
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 1000100;

int c[maxn];
vector<int> vc[maxn];

int fv[maxn];

void add(int u, int val) {
	for (; u < maxn; u |= u + 1) {
		fv[u] += val;
	}
}

void addlr(int l, int r) {
	add(l, 1), add(r, -1);
}
void addnlr(int l, int r) {
	add(0, 1), add(l, -1), add(r, 1);
}

int get(int u) {
	int ret = 0;
	for (; u >= 0; u &= u + 1, u--) {
		ret += fv[u];
	}
	return (ret);
}

int solve() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		for (int j = 0; j < c[i]; j++) {
			int x;
			scanf("%d", &x);
			x--;
			vc[i].pb(x);
		}
	}
	for (int i = 0; i + 1 < n; i++) {
		bool ok = c[i] <= c[i + 1];
		for (int j = 0; j < min(c[i], c[i + 1]); j++) {
			if (vc[i][j] != vc[i + 1][j]) {
				ll c1 = vc[i][j], c2 = vc[i + 1][j];
				if (c1 < c2) {
					addlr(m - c2, m - c1);
				} else {
					addnlr(m - c1, m - c2);
				}
				ok = 1;
				break;
			}
		}
		if (!ok) {
			printf("-1\n");
			return (0);
		}
	}

	for (int i = 0; i < m; i++) {
		if (!get(i)) {
			printf("%d\n", i);
			return (0);
		}
	}
	printf("-1");

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

// by Andrey Kim