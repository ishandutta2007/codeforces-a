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

int const NMAX = 2010;
int const P = 1000000007;

int n, k, zn[NMAX], ans[NMAX], inv[NMAX];
long long kk[NMAX];

int power(long long x, int st)
{
	long long res = 1;
	while (st > 0)
	{
		if (st & 1) res = (res * x) % P;
		x = (x * x) % P;
		st >>= 1;
	}
	return (int) res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	forn(i, n)
		scanf("%d", &zn[i]);

	if (k == 0)
	{
		forn(i, n)
			printf("%d ", zn[i]);
		cout << endl;
		return 0;
	}

	forn(i, n)
		inv[i + 1] = power(i + 1, P - 2);

	k--;
	forn(i, n)
	{
		kk[i] = 1LL;
		forn(j, i)
			kk[i] = (kk[i] * (k + j + 1)) % P;
		forn(j, i)
			kk[i] = (kk[i] * inv[j + 1]) % P;
		//if (k == 0) kk[i] = 1LL;
	}

	forn(i, n)
	{
		ans[i] = 0;
		forn(j, i + 1)
			ans[i] = (ans[i] + zn[i - j] * kk[j]) % P;
	}

	forn(i, n)
		printf("%d ", ans[i]);
	cout << endl;

	return 0;
}