/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
//typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int lol[500001];
void solve()
{
	int n,k;
	cin>>n>>k;
	string s,t;
	cin>>s>>t;
	int ans=0;
	int lul=0;
	bool first=1;
	for(int i=0; i<s.length()&&k>0; i++)
	{
		if(first)
		{
			int mi=min(k,t[i]-s[i]+1LL);
			k-=mi;
			ans+=mi*(s.length()-i);
			lul=t[i]-s[i];
			first=0;
		}
		else
		{
			int mi=min(k,lul+t[i]-s[i]);
			k-=mi;
			ans+=mi*(s.length()-i);
			lul=lul*2+t[i]-s[i];
		}
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	clk=clock()-clk;
	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}