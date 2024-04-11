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
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
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
typedef float f80;
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

const int N=1e5+5;
int a[N];
bool dist[N];
int n;
int ans[N];
int compute(int i) {
	if(ans[i])
		return ans[i];
	memset(dist,0,sizeof(dist));
//	dist.resize(n+1,0);
	int num=0,breaks=0;
	int last=1;
	for(int j=1; j<=n; j++) {
		if(dist[a[j]]==0) {
			dist[a[j]]=1;
			num++;
		}
		if(num>i) {
			for(int k=last; k<=j; k++)
				dist[a[k]]=0;
			last=j;
			j--;
			num=0;
			breaks++;
		}
	}
	return ans[i]=breaks+1;
}
void solve() {
	cin>>n;
//	n=1e5;
	fr(i,1,n) {
		cin>>a[i];
//		a[i]=rng(n)+1;
	}
	for(int i=n; i>0; ) {
//		trace(i);
		int lo=1,hi=i,mid=(lo+hi)/2;
		int tol=compute(i);
		while(lo<hi) {
			if(compute(mid)==tol)
				hi=mid;
			else
				lo=mid+1;
			mid=(lo+hi)/2;
		}
		for(int j=mid; j<=i; j++)
			ans[j]=tol;
		i=mid-1;
	}
	fr(i,1,n) {
		cout<<ans[i]<<" ";
	}

}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}