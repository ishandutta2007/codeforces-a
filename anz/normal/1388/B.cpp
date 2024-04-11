#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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
		int n; cin >> n;
		int er = (n - 1) / 4 + 1;
		for (int i = 0; i < n; i++)
		{
			if (i + er < n) cout << 9;
			else cout << 8;
		}
		cout << '\n';
	}
}