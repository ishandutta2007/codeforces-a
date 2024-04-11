#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int MOD = 998244353;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int pw = 1;
		int x = a[i];
		while(x > 0)
		{
			int dig = x % 10;
			ans += (n * pw * dig) % MOD;
			ans %= MOD;
			pw *= 10;
			ans += (n * pw * dig) % MOD;
			ans %= MOD;
			pw *= 10;
			pw %= MOD;
			x /= 10;
		}
	}
	cout << ans;
	return 0;
}