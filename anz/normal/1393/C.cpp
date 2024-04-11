#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int cnt[100001];

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
			int a; cin >> a;
			cnt[a]++;
		}

		int mx = *max_element(cnt + 1, cnt + n + 1);

		int mx_cnt = 0;
		for (int i = 1; i <= n; i++) if (cnt[i] == mx) mx_cnt++;

		int res = (n - mx_cnt) / (mx - 1) - 1;
		cout << res << '\n';
	}
}