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
#include <deque>

#include <ctime>
#include <cassert>

using namespace std;

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
const string name = "a";

const int NMAX = 100100;

int n, m, f[NMAX], used1[NMAX], used2[NMAX];
vector <int> g[NMAX], ginv[NMAX];

void dfs1(int v)
{
	used1[v] = 1;
	forn(i, g[v].size())
		if (!used1[g[v][i]]) dfs1(g[v][i]);
}

void dfs2(int v)
{
	used2[v] = 1;
	if (f[v] == 1) return;
	forn(i, ginv[v].size())
		if (!used2[ginv[v][i]]) dfs2(ginv[v][i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, n)
		scanf("%d", &f[i]);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
		ginv[y].pb(x);
	}
	seta(used1, 0);
	forn(i, n)
		if (!used1[i] && f[i] == 1)
			dfs1(i);
	seta(used2, 0);
	forn(i, n)
		if (!used2[i] && f[i] == 2)
			dfs2(i);
	forn(i, n)
		if (used1[i] && used2[i]) printf("1\n");
		else printf("0\n");

	return 0;
}