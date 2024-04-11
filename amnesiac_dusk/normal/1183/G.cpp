#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=1e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}



int a[200005][2];
vector<pii> lol[200005];
bool these[200005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		a[i][0]=a[i][1]=0;
		lol[i].clear();
		these[i]=0;
	}
	fr(i,1,n) {
		int te,f;
		cin>>te>>f;
		a[te][f]++;
	}
	vi tol;
	fr(i,1,n) {
		if(a[i][0]+a[i][1]) {
			tol.pb(a[i][0]+a[i][1]);
			lol[a[i][0]+a[i][1]].pb({a[i][1],a[i][0]+a[i][1]});
		}
	}
	sort(all(tol));
	reverse(all(tol));
	for(int i=1; i<sz(tol); i++) {
		if(tol[i]>=tol[i-1])
			tol[i]=max(0LL,tol[i-1]-1);
	}
	int ans=0;
	while((!tol.empty())&&tol.back()==0)
		tol.pop_back();
	for(int i:tol)
		these[i]=1;
//	for(int i:tol)
//		cout<<i<<endl;
	ans=accumulate(all(tol),0LL);
	priority_queue<pii> tolol;
	int ans2=0;
	for(int i=n; i>0; i--) {
		for(pii j:lol[i]) {
			tolol.push(j);
		}
		if(these[i]) {
			ans2+=min(tolol.top().fi,i);
			tolol.pop();
		}
	}
	cout<<ans<<" "<<ans2<<endl;

}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}