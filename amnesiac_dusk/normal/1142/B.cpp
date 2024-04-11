/*
 * 	If you gave me a chance
 * 		I'll take it
 * 			It's a shot in the dark
 * 				But I will make it:D
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
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
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

const int N=2e5+5;
int a[N],p[2*N],anti[2*N];
int dp[18][N],lps[N];
int anses[2*N];
int m;
int query(int l, int r) {
	l--;
	int res=m+1;
	for(l+=m,r+=m; l<r; l>>=1,r>>=1) {
		if(l&1) res=min(res,anses[l++]);
		if(r&1) res=min(res,anses[--r]);
	}
	return res;
}
void solve() {
	int n,q;
	cin>>n>>m>>q;
	fr(i,1,n) {
		cin>>p[i];
		anti[p[i]]=i;
		p[i+n]=p[i];
		lps[i]=m+1;
	}
	fr(i,1,m) {
		cin>>a[i];
	}
	dp[0][m+1]=m+1;
	for(int i=m; i>0; i--) {
		dp[0][i]=lps[p[anti[a[i]]+1]];
//		dp[0][i]=min(dp[0][i],dp[0][i+1]);
		lps[a[i]]=i;
	}
	for(int j=1; j<18; j++) {
		dp[j][m+1]=m+1;
		for(int i=m; i>0; i--) {
			dp[j][i]=dp[j-1][dp[j-1][i]];
//			dp[j][i]=min(dp[j][i],dp[j][i+1]);
		}
	}
	for(int i=1; i<=m; i++) {
		int te=n-1;
		int lol=i;
		for(int j=0; j<18; j++) {
			if(te&(1<<j)) {
				lol=dp[j][lol];
			}
		}
		anses[m+i-1]=lol;
	}
	for(int i=m-1; i>0; i--) {
		anses[i]=min(anses[i<<1],anses[i<<1|1]);
	}
	while(q--) {
		int l,r;
		cin>>l>>r;
		if(query(l,r)<=r) {
			cout<<'1';
		} else
			cout<<'0';
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}