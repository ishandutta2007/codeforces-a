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

const int N=1e5+5;

ll n,m;
int check[N];
int prime[N];
int storeon[N];
bool sieve[N];


int main()
{
	IOS;
	cin>>n>>m;
	memset(sieve,true,sizeof(sieve));
	for(ll i=2;i<N;i++)
	{
		if(sieve[i])
		{
			for(ll j=1;i*j<N;j++)
			{
				sieve[i*j]=false;
				prime[i*j]=i;
			}
		}
	}
	while(m--)
	{
		char ch;
		cin>>ch;
		if(ch=='+')
		{
			ll k;
			cin>>k;
			if(storeon[k])
			{
				cout<<"Already on"<<endl;
				continue;
			}
			ll keep=k;
			ll st=k;
			bool temp=true;
			ll conflict;
			while(st!=1)
			{
				if(check[prime[st]])
				{
					temp=false;
					conflict=check[prime[st]];
					break;
				}
				st/=prime[st];
			}
			if(temp)
			{
				cout<<"Success"<<endl;
				storeon[keep]=1;
				while(k!=1)
				{
					check[prime[k]]=keep;
					k/=prime[k];
				}
			}
			else
			{
				cout<<"Conflict with "<<conflict<<endl;
			}
		}
		else
		{
			ll k;
			cin>>k;
			if(!storeon[k])
			{
				cout<<"Already off"<<endl;
			}
			else
			{
				cout<<"Success"<<endl;
				storeon[k]=0;
				while(k!=1)
				{
					check[prime[k]]=0;
					k/=prime[k];
				}
			}
		}
	}
	return 0; 
}