#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ans[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(ans, 0, sizeof ans);

		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
				ans[i][(i + j) % n] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << ans[i][j] << ' ';
			cout << '\n';
		}
	}
}