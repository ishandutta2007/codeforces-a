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
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e5;
const lli mod = 1e9 + 7;

int n, m;
lli dp[N][3];
int main()
{
	fastio;
	cin >> n >> m;
	if(n < m) swap(n, m);
	dp[0][1] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][2] = dp[i - 1][1];
	}
	n--, m--;
	cout << (2LL * (dp[n][1] + dp[n][2] + dp[m][1] + dp[m][2] - 1) + mod) % mod;

	return 0;
}