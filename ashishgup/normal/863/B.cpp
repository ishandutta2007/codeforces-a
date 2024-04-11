//Started 5 minutes late


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
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000009

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5;

int n;
bool check[205];
int a[205];

ll calc()
{
	vector<int> cur;
	for(int i=1;i<=2*n;i++)
	{
		if(!check[i])
			continue;
		cur.pb(a[i]);
	}	
	sort(cur.begin(),cur.end());
	ll ans=0;
	for(int i=0;i<2*n-2;i+=2)
	{
		ans+=(cur[i+1]-cur[i]);
	}
	return ans;
}

int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
		check[i]=1;
	}
	ll ans=LLONG_MAX;
	for(int i=1;i<=2*n;i++)
	{
		for(int j=i+1;j<=2*n;j++)
		{
			check[i]=false;
			check[j]=false;
			ans=min(ans, calc());
			check[i]=true;
			check[j]=true;
		}
	}
	cout<<ans;
	return 0;
}