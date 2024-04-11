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
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl= 0x3f3f3f3f3f3f3f3fLL;
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


vi tro1,tr2;

void add(vi &a, int p, int n, int val) {
	while(p<=n) {
		a[p]+=val;
		p+=p&(-p);
	}
}
int gsum(vi &a, int p) {
	int su=0;
	while(p) {
		su+=a[p];
		p-=(p&(-p));
	}
	return su;
}
int poo[200005];
void solve() {
	int n,k,a,b,q;
	cin>>n>>k>>a>>b>>q;
	tro1.resize(n+1,0LL);
	tr2.resize(n+1,0LL);
	while(q--) {
		int ty;
		cin>>ty;
		if(ty==1) {
			int d,ai;
			cin>>d>>ai;
			add(tro1,d,n,max(0LL,min(ai,a-poo[d])));
			add(tr2,d,n,max(0LL,min(ai,b-poo[d])));
			poo[d]+=ai;
		} else {
			int p;
			cin>>p;
			int lol=gsum(tr2,p-1)+gsum(tro1,n)-gsum(tro1,p+k-1);
			cout<<lol<<endl;
		}
	}


}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}