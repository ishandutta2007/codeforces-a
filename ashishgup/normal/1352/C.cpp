#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int lo = 1, hi = 2e18;
		while(lo < hi)
		{
			int mid = (lo + hi) / 2;
			int cnt = mid - mid / n;
			if(cnt >= k)
				hi = mid;
			else
				lo = mid + 1;
		}
		cout << lo << endl;
	}
	return 0;
}