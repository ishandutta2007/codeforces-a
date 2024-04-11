//#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
using namespace std;
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
template<typename A, typename B>
string to_string(pair<A, B> a) {
	return "{"+to_string(a.first)+","+to_string(a.second)+"}";
}
template<typename A>
string to_string(A v) {
	bool first=1;
	std::string res="{";
	for(auto x : v) {
		if(!first)
			res+=",";
		else
			first=0;
		res+=to_string(x);
	}
	res+="}";
	return res;
}
template<typename T>
void __f(const char* name, T arg1) {
	cout<<name<<" : "<<to_string(arg1)<<endl;
}
template<typename T, typename ... Args>
void __f(const char* names, T arg1, Args ... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<to_string(arg1)<<" | ";
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

int a[200005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	int sum=accumulate(a+1,a+n+1,0LL);
	int xo=0;
	fr(i,1,n) {
		xo^=a[i];
	}
	xo<<=1;
	vi a;
	for(int ii=0; ii<3; ii++) {
		int ff=0;
		for(int i=0; i<60; i++) {
			if(((xo&(1LL<<i))^(sum&(1LL<<i)))) {
				ff|=(1LL<<i);
				xo^=(1LL<<(i+1));
				sum+=(1LL<<i);
			}
		}
		a.pb(ff);
	}
	cout<<sz(a)<<endl;
	for(int i:a) {
		cout<<i<<" ";
	}
	cout<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
  cin>>t;
	fr(i,1,t)
		solve();
#ifndef ONLINE_JUDGE
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
}