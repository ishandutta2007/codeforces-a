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
const int maxn = 100100;

int d[maxn], a[maxn], lst[maxn];
int n, m;


bool check(int c) {
	for (int i = 1; i <= m; i++) {
		lst[i] = -1;
	}
	for (int i = 0; i < c; i++) {
		lst[d[i]] = i;
	}

	vector<pair<int, int> > vc;
	for (int i = 1; i <= m; i++) {
		if (lst[i] == -1)
			return (0);
		vc.pb(mp(lst[i], a[i]));
	}
	sort(vc.begin(), vc.end());
	int em = 0, ld = -1;
	for (int i = 1; i <= m; i++) {
		em += vc[i - 1].fs - ld - 1;
		ld = vc[i - 1].fs;
		if (em < vc[i - 1].sc) {
			return (0);
		} else {
			em -= vc[i - 1].sc;
		}
	}
	return (1);
}

int solve() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
	}

//	cout << check(5);
//	return (0);

	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (check(m)) {
			r = m;
		} else {
			l = m;
		}
	}

	printf("%d", r == n + 1 ? -1 : r);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

// by Andrey Kim