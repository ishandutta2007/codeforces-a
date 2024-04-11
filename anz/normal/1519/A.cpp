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
		ll r, b, d; cin >> r >> b >> d;
		if (r > b) swap(r, b);

		if (b - r > r * d) cout << "NO\n";
		else cout << "YES\n";
	}
}