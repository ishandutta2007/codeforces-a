#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	while (n--)
	{
		ll c, sum; cin >> c >> sum;

		ll rad = sum / c;
		ll remain = sum - rad * c;

		ll ans = 0;
		for (int i = 0; i < c; i++)
		{
			if (remain)
			{
				ans += (rad + 1)*(rad + 1);
				remain--;
			}
			else
			{
				ans += rad * rad;
			}
		}
		cout << ans << '\n';
	}
}