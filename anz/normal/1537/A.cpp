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
		int n; cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			sum += x;
		}

		if (sum < n) cout << "1\n";
		else cout << llabs(sum - n) << '\n';
	}
}