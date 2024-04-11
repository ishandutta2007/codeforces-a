#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}


int mi[100005],ma[100005];
int yes[100005];
void solve() {
	int n;
	cin>>n;
	int yeah=0;
	fr(i,1,n) {
		int te;
		mi[i]=infl;
		cin>>te;
		rep(j,0,te) {
			int te1;
			cin>>te1;
			if(te1>mi[i]) {
				yes[i]=1;
			}
			mi[i]=min(mi[i],te1);
			ma[i]=max(ma[i],te1);
		}
	}
	vi lol;
	fr(i,1,n)
		if(yes[i]==0)
			lol.pb(mi[i]);
		else
			yeah++;
	int ans=2*yeah*n-yeah*yeah;
	sort(all(lol));
	fr(i,1,n)
		if(yes[i]==0)
			ans+=lower_bound(all(lol),ma[i])-lol.begin();
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
}