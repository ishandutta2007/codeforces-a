//#define opti
#ifdef opti
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#else
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
//#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
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

int a[300001];
vector<int> gra[300001];
bool involved[300001];
int fans;
int ans=0;
int dfs(int fr, int at,int runans)
{
	int teans=a[at];
	for(int i:gra[at])
		if(i!=fr)
		{
			int lol=dfs(at,i,max(0LL,teans+runans));
			teans+=max(lol,0LL);
		}
	fans=max(fans,runans+teans);
	return teans;
}
int dfser(int fr, int at,int runans)
{
	int teans=a[at];
	for(int i:gra[at])
		if(i!=fr)
		{
			int lol=dfser(at,i,max(0LL,teans+runans));
			teans+=max(lol,0LL);
		}
	if(fans==teans)
	{
		ans++;
		return 0;
	}
	return teans;
}
void solve()
{
	int n;
	cin>>n;
	int u,v;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<n; i++)
	{
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	fans=-inf;
	dfs(1,1,0);
	dfser(1,1,0);
	cout<<fans*ans<<" "<<ans<<endl;
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
	cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
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