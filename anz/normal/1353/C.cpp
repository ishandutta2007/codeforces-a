#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		ll ans = 0;
		for (ll i = 1; i <= n / 2; i++)
		{
			ans += i * ((2 * i + 1) * (2 * i + 1) - (2 * i - 1) * (2 * i - 1));
		}
		cout << ans << '\n';
	}
}