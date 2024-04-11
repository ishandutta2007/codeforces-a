/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
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
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

string a[1005];
int dsu[1025005];
int fpar(int i) {
	return (dsu[i]<=0)?i:dsu[i]=fpar(dsu[i]);
}
void merge(int i, int j) {
	if((i=fpar(i))!=(j=fpar(j))) {
		if(dsu[i]>dsu[j])
			swap(i,j);
		dsu[i]+=dsu[j];
		dsu[j]=i;
	}
}
inline int get(int i, int j) {
	return (i<<10)|j;
}
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	fill(dsu,dsu+1025005,0);
	fr(i,1,n) {
		cin>>a[i];
		a[i]='#'+a[i];
	}
	fr(i,0,m+1) {
		a[0]+='#';
		a[n+1]+='#';
	}
	fr(i,1,n)
		fr(j,1,m)
			if(a[i][j]=='*')
				for(int k=0; k<4; k++)
					if(a[i+d[k][0]][j+d[k][1]]=='.') {
						dsu[get(i+d[k][0],j+d[k][1])]--;
					}

	fr(i,1,n)
		fr(j,1,m-1)
			if(a[i][j]=='.'&&a[i][j+1]=='.')
				merge(get(i,j),get(i,j+1));
	fr(i,1,n-1)
		fr(j,1,m)
			if(a[i][j]=='.'&&a[i+1][j]=='.')
				merge(get(i,j),get(i+1,j));
	while(k--) {
		int x,y;
		cin>>x>>y;
		cout<<-dsu[fpar(get(x,y))]<<endl;
	}
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
//	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}