#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
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

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int P = 1000000007;
const int NMAX = 101;

char s[NMAX];
int n, x[NMAX][26], y[NMAX][26], f[NMAX][26], ans[NMAX][26* NMAX + 1];

void solve()
{
	scanf("%s", s);
	n = strlen(s);
	int sum = 0;
	forn(i, n)
		sum += s[i] - 'a';
	printf("%d\n", (ans[n][sum] + P - 1) % P);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	seta(ans, 0);
	ans[0][0] = 1;
	forn(i, 100)
		forn(j, i * 25 + 1)
			forn(f, 26)
				ans[i + 1][j + f] = (ans[i + 1][j + f] + ans[i][j]) % P;

	int tst;
	cin >> tst;
	forn(i, tst)
		solve();

	return 0;
}