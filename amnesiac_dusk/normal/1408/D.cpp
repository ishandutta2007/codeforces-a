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
//const int mod=998244353;
const int mod=1000000007;
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

pii a[2005];
pii s[2005];
int anses[1000005];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n)
		cin>>a[i].fi>>a[i].se;
	fr(i,1,m)
		cin>>s[i].fi>>s[i].se;
	int ans=infi;
	bool yolo=1;
	fr(i,1,n) {
		fr(j,1,m) {
			if(s[j].se>=a[i].se&&s[j].fi>=a[i].fi) {
				anses[s[j].se-a[i].se]=max(anses[s[j].se-a[i].se],s[j].fi-a[i].fi+1);
				yolo=0;
			}
		}
	}
	if(yolo) {
		cout<<0<<endl;
		return;
	}
	for(int i=1000001; i>=0; i--) {
		anses[i]=max(anses[i],anses[i+1]);
		ans=min(anses[i]+i,ans);
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}