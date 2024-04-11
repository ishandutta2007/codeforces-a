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
		int n, k; cin >> n >> k;
		if (n < k) cout << k - n << '\n';
		else
		{
			if (k % 2 != n % 2) cout << "1\n";
			else cout << "0\n";
		}
	}
}