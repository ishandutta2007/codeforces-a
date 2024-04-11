/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(x) x.begin(),x.end()
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[1000001],lol[1000001];
signed main()
{
	IO;
	int n,te;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>te;
		a[te]++;
	}
	for(int i=1; i<=1000000; i++)
	{
		lol[i]+=a[i];
		for(int j=2*i; j<=1000000; j+=i)
			lol[j]=max(lol[j],lol[i]);
	}
	int ans=0;
	for(int i:lol)
		ans=max(ans,i);
	cout<<ans<<endl;
}
ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}