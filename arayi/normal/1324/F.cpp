#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
#define pir pair<int, int> 
#define all(x) (x).begin(), (x).end()
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 2e5 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 74e-9;

lli bp(lli a, lli b = -2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}


int n;
int a[N];
vector <int> g[N];
int dp[N];
void dfs(int v, int par)
{
	dp[v] = a[v];
	for (auto p : g[v])
	{
		if (p == par) continue;
		dfs(p, v);
		dp[v] += max(0, dp[p]);
	}
}
void dfs1(int v, int par)
{
	if (dp[v] < 0)
	{
		dp[v] = max(dp[v], dp[par] - 1);
	}
	else
	{
		dp[v] = max(dp[v], dp[par]);
	}
	for (auto p : g[v])
	{
		if (p == par) continue;
		dfs1(p, v);
	}
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0) a[i]--;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].PB(b);
		g[b].PB(a);
	}
	dfs(1, 0);
	dfs1(1, 0);
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}
	return 0;
}
/*
  __
*(><)*
  \/ /
  ||/
--||
  ||
  /\
 /  \
/    \
*/