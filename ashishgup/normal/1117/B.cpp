#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, k;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	int value = k * a[1] + a[2];
	int take = m/(k+1);
	int ans = take * value;
	m%=(k+1);
	ans += m * a[1];
	cout<<ans;
	return 0;
}