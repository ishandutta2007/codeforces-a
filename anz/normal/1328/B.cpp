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
		ll n, k; cin >> n >> k;
		ll ck = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (ck + i + 1 >= k)
			{
				for (int j = 0; j < n; j++)
				{
					if (j == n - 2 - i) cout << 'b';
					else if (j == n - (k - ck)) cout << 'b';
					else cout << 'a';
				}
				cout << '\n';
				break;
			}

			ck += i + 1;
		}
	}
}