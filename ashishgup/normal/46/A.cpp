#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int cur=0;
	for(int i=1;i<=n-1;i++)
	{
		cur+=i;
		cur%=n;
		cout<<cur+1<<" ";
	}
	return 0;
}