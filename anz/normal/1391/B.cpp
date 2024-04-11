#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
string cb[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> cb[i];

		int ans = 0;
		for (int i = 0; i < n - 1; i++) if (cb[i][m - 1] == 'R') ans++;
		for (int i = 0; i < m - 1; i++) if (cb[n - 1][i] == 'D') ans++;
		cout << ans << '\n';
	}
}