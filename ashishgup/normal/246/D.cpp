#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
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

ll n,m;
vll v;
vvll g;
int main()
{
	IOS;
	cin>>n>>m;
	v=vll(n+1);
	g=vvll(n+1);
	vvll col(1e5+1);
	for(ll i=1;i<=n;i++)
	{
		cin>>v[i];
		col[v[i]].pb(i);
	}
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<set<ll> > st(1e5+1);
	for(ll i=1;i<=1e5;i++)
	{
		for(auto it:col[i])
		{
			for(auto j:g[it])
			{
				//trace3(i,j,v[j]);
				st[i].insert(v[j]);
			}
		}
		if(st[i].find(i) !=st[i].end())
		{
			st[i].erase(i);
		}
	}
	vll size(1e5+1,0);
	ll max1=-1;
	ll ind=-1;
	for(ll i=1;i<=1e5+1;i++)
	{
		if(col[i].size()==0)
			continue;
		ll store=st[i].size();
		if(store>max1)
		{
			max1=store;
			ind=i;
		}
		else if(store==0&&max1==-1)
		{
			max1=0;
			ind=i;
		}
	}
	cout<<ind;
	return 0;
}