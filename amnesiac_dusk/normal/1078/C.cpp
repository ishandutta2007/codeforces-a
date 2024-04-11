#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

vi gra[300005];
int dp[300005][3];
void dfs(int fr, int at) {
	dp[at][0]=0;
	dp[at][1]=1;
	int pol=1;
	int prod=1;
	for(int i:gra[at]) {
		if(i!=fr) {
			dfs(at,i);
			pol=(pol*dp[i][0])%mod;
			dp[at][0]=(dp[at][0]*(dp[i][0]+dp[i][2]))%mod;
			dp[at][0]=(dp[at][0]+dp[i][1]*prod)%mod;
			prod=(prod*(dp[i][0]+dp[i][2]))%mod;
			dp[at][1]=(dp[at][1]*(dp[i][0]+dp[i][2]))%mod;
		}
	}
	dp[at][2]=dp[at][0];
	dp[at][0]=(dp[at][0]+pol)%mod;
}
void solve() {
	int n;
	cin>>n;
	fr(i,2,n) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(1,1);
	fr(i,1,n) {
		trace(i,dp[i][0],dp[i][1],dp[i][2]);
	}
	cout<<dp[1][0]<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}