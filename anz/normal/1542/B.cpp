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
		ll n, a, b; cin >> n >> a >> b;
		if (a == 1)
		{
			if ((n - 1) % b == 0) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}

		bool ans = false;
		ll mul = 1;
		while (mul <= n)
		{
			if ((n - mul) % b == 0) ans = true;
			mul *= a;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}