#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;
 
#define PI 3.141592653589793
#define MOD 1000000007

int main()
{
	vector<bool> sieve(1e6+1,true);
	sieve[0]=false;
	sieve[1]=false;
	for(ll i=2;i<1e6+1;i++)
	{
		if(sieve[i]==true)
		{
			for(ll j=2;i*j<1e6+1;j++)
			{
				sieve[i*j]=false;
			}
		}
	}
 	ll n;
 	cin>>n;
 	for(ll i=1;i<=1000;i++)
 	{
 		if(sieve[n*i+1]==false)
 		{
 			cout<<i;
 			return 0;
		}
	}
	return 0;
}