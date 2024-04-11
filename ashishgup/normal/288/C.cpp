#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef vector<long long> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const long long N=1e6+5;

int a[N];
int vis[N];
int n;

void swap1(int u, int v)
{
	swap(a[u],a[v]);
	vis[u]=1;
	vis[v]=1;
}
int main()
{
	IOS;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		a[i]=i;
	}
	int left=n;
	for(int j=21;j>=0;j--)
	{
		if((1<<j) <= n && !vis[1<<j])
		{
			int store=1<<j;
			swap1(store,store-1);
			int right=store+1;
			int left=store-2;
			while(!vis[right]&&right<=n&&left>=0)
			{
				swap1(right,left);
				right++;
				left--;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
	{
		ans+=(i^a[i]);
	}
	cout<<ans<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}