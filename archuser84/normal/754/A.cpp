///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int n;
	cin >> n;
	int *a = new int[n];
	int sum = 0;
	int j = -1;
	Loop(i,0,n)
	{
		cin >> a[i];
		sum += a[i];
		if (a[i] != 0 && j == -1) j = i;
	}
	if(sum) cout << "YES\n1\n1 " << n << "\n";
	else if(j != -1) cout << "YES\n2\n1 " << j+1 << "\n" << j+2 << " " << n << "\n";
	else cout << "NO\n";
}