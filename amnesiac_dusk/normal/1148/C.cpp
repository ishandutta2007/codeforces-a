/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast,unroll-loops")
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
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}


int powm(int a, int b) {
	a%=mod;
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}

int p[300005],anti[300005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>p[i];
		anti[p[i]]=i;
	}
	vector<pii> ans;
	fr(i,1,n/2) {
		if(p[i]!=i) {
			if(anti[i]==n||(i==1&&anti[i]>n/2)) {
				ans.pb({i,anti[i]});
				p[anti[i]]=p[i];
				anti[p[i]]=anti[i];
				p[i]=i;
				anti[i]=i;
			}
			else if(anti[i]>n/2) {
				ans.pb({anti[i],1});
				ans.pb({n,1});
				ans.pb({n,i});
				ans.pb({1,n});
				ans.pb({anti[i],1});
				p[anti[i]]=p[i];
				anti[p[i]]=anti[i];
				p[i]=i;
				anti[i]=i;
			} else {
				ans.pb({anti[i],n});
				ans.pb({n,i});
				ans.pb({anti[i],n});
				p[anti[i]]=p[i];
				anti[p[i]]=anti[i];
				p[i]=i;
				anti[i]=i;
			}
		}
	}
	fr(i,n/2+1,n) {
		if(p[i]!=i) {
			if(anti[i]==1||(i==n&&anti[i]<=n/2)) {
				ans.pb({i,anti[i]});
				p[anti[i]]=p[i];
				anti[p[i]]=anti[i];
				p[i]=i;
				anti[i]=i;
			}
			else if(anti[i]<=n/2) {
				ans.pb({anti[i],n});
				ans.pb({n,1});
				ans.pb({1,i});
				ans.pb({1,n});
				ans.pb({anti[i],n});
				p[anti[i]]=p[i];
				anti[p[i]]=anti[i];
				p[i]=i;
				anti[i]=i;
			} else {
				ans.pb({anti[i],1});
				ans.pb({1,i});
				ans.pb({anti[i],1});
				p[anti[i]]=p[i];
				anti[p[i]]=anti[i];
				p[i]=i;
				anti[i]=i;
			}
		}
	}
	cout<<sz(ans)<<endl;
	for(auto i:ans)
		cout<<i.fi<<" "<<i.se<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}