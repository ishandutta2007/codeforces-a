#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

int main()
{
	ll n;
	cin>>n;
	vvll v(n,vll(n));
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>v[i][j];
		}
	}
	vvb vis(n,vb(n,false));
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		if(vis[n/2][i]==false)
		{
			vis[n/2][i]=true;
			sum+=v[n/2][i];
		}
		if(vis[i][n/2]==false)
		{
			vis[i][n/2]=true;
			sum+=v[i][n/2];
		}
	}
	for(ll i=0;i<n;i++)
	{
		if(vis[i][i]==false)
		{
			vis[i][i]=true;
			sum+=v[i][i];
		}
		if(vis[i][n-1-i]==false)
		{
			vis[i][n-1-i]=true;
			sum+=v[i][n-1-i];
		}
	}
	cout<<sum;
}