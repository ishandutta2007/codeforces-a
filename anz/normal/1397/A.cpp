#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int cnt[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			for (char c : s) cnt[c - 'a']++;
		}

		bool ans = true;
		for (int i = 0; i < 26; i++)
		{
			if (cnt[i] % n) ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}