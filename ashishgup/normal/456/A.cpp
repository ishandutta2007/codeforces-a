#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], b[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		m[a[i]]=b[i];
	}
	int prev=0;
	for(auto &it:m)
	{
		if(it.second<prev)
		{
			cout<<"Happy Alex";
			return 0;
		}
		prev=it.second;
	}
	cout<<"Poor Alex";
	return 0;
}