#pragma GCC optimize("Ofast")
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
typedef double f80;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll,ll> pll;
#define double long double
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
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
	while(b>0) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int a[200005];
bool used[200005];
void solve() {
	int n,p;
	cin>>n>>p;
	fr(i,1,n)
		cin>>a[i];
	vector<pii> lotor;
	fr(i,1,n)
		lotor.pb({a[i],i});
	sort(all(lotor));
	fr(i,1,n)
		used[i]=0;
	used[0]=used[n+1]=1;
	int ans=0,rem=n-1;
	for(auto i:lotor) {
		if(i.fi>=p)
			break;
		int l=i.se,r=i.se;
		while(used[l]==0&&l-1&&a[l-1]%i.fi==0)
			l--;
		while(used[r]==0&&r+1<=n&&a[r+1]%i.fi==0)
			r++;
		for(int i=l; i<=r; i++)
			used[i]=1;
		ans+=(r-l)*i.fi;
		rem-=r-l;
	}
	cout<<ans+rem*p<<endl;




}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}