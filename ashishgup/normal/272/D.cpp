#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int N=2e5+5;

int n, mod;
int a[N], b[N];
map<int, int> m;
map<int, map<int, int> > g;

int fact(int k, int adjust)
{
	int ans=1;
	while(k!=1)
	{
		int cur=k;
		while((cur%2==0)&&adjust>0)
		{
			adjust--;
			cur/=2;
		}
		ans*=cur;
		ans%=mod;
		k--;
	}
	return ans;
}

int32_t main()
{
    IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		g[a[i]][i]++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		m[b[i]]++;
		g[b[i]][i]++;
	}
	int ans=1;
	cin>>mod;
	for(auto it:m)
	{
		int adjust=0;
		for(auto j: g[it.ff])
		{
			if(j.ss==2)
			{
				adjust++;
			}
		}
		ans*=fact(it.ss, adjust);
		ans%=mod;
	}
	cout<<ans;
    return 0;
}