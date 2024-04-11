//#pragma GCC optimize("Ofast")
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
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
vector<pair<pii,int>> lr;
void solve() {
	int n,l,r;
	cin>>n;
	fr(i,1,n) {
		cin>>l>>r;
		lr.pb({{l,r},i});
	}
	sort(all(lr));
	int covered=0;
	for(int i=0; i+1<n; i++)
		if(lr[i].fi.fi==lr[i+1].fi.fi) {
			cout<<lr[i].se<<endl;
			return;
		}
	covered=lr[0].fi.se+1;
	for(int i=1; i<n; i++) {
		if(covered>lr[i].fi.se) {
			cout<<lr[i].se<<endl;
			return;
		}
		if(i+1<n) {
			if(lr[i].fi.fi<=covered&&lr[i+1].fi.fi<=covered) {
				if(lr[i].fi.se<lr[i+1].fi.se) {
					cout<<lr[i].se<<endl;
					return;
				} else {
					cout<<lr[i+1].se<<endl;
					return;
				}
			}
			covered=lr[i].fi.se+1;
		}
	}
	cout<<-1<<endl;
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