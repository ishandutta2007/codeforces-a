#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
const ll infl=4e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	a%=mod;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

const int N=2e5+5;
map<int,int> p;
map<int,vi> lol;
pii s[N];
int aco[N],sco[N];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n) {
		int te;
		cin>>te;
		p[te]++;
		if(p[te]==1) {
			lol[te]=vi();
		}
		lol[te].pb(i);
	}
	fr(i,1,m) {
		cin>>s[i].fi;
		s[i].se=i;
	}
	sort(s+1,s+m+1);
	int co=0,soc=0;
	fr(i,1,m) {
		int te=s[i].fi,tes=0;
		while(1) {
			if(p.find(te)!=p.end()&&p[te]>0) {
				p[te]--;
				co++;
				soc+=tes;
				sco[s[i].se]=tes;
				aco[lol[te].back()]=s[i].se;
				lol[te].pop_back();
				break;
			}
			if(te==1) {
				break;
			}
			te=(te+1)/2;
			tes++;
		}
	}
	cout<<co<<" "<<soc<<endl;
	fr(i,1,m)
		cout<<sco[i]<<" ";
	cout<<endl;
	fr(i,1,n)
		cout<<aco[i]<<" ";
	cout<<endl;
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
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}