#pragma comment(linker, "/STACK:600000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
#define sz(s) int((s).size())

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int NMAX = 101100;

int n, k, ans1[NMAX], ans2[NMAX], c[NMAX];
pii q[NMAX];

int main() {
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> k;
	seta(q, 0);
	forn(i, n) {
		cin >> c[i];
		c[i]--;
		q[c[i]].fs++;
	}
	forn(i, k)
		q[i].sc = i;
	sort(q, q + k);
	int now = 0;
	ford(i, k)
		forn(j, q[i].fs)
			ans1[now++] = q[i].sc;
	now = 0;
	ford(i, k)
		if (i != k - 1)
			forn(j, q[i].fs)
				ans2[now++] = q[i].sc;
	forn(j, q[k - 1].fs)
		ans2[now++] = q[k - 1].sc;

	int answer = 0;
	forn(i, n)
		if (ans1[i] != ans2[i]) answer++;
	cout << answer << endl;
	forn(i, n) {
		printf("%d %d\n", ans1[i] + 1, ans2[i] + 1);
	}

	return 0;
}