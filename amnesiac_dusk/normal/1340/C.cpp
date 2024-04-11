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

bool vis[10005][1005];
int d[10005];
queue<int> p[1005],p2;
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,m)
		cin>>d[i];
	sort(d+1,d+m+1);
	int r,g;
	cin>>g>>r;
	p[0].push(1);
	int ptr=0;
	int yes=1;
	int ans=infl;
	vis[1][0]=1;
	int turn=0;
	while(yes) {
//		trace(ptr,yes);
		if(ptr==g) {
			turn++;
			ptr=0;
			p[0].swap(p2);
			if(ans!=infl)
				break;
		}
		while(sz(p[ptr])) {
			int j=p[ptr].front();
			p[ptr].pop();
			yes--;
			if(j>1) {
				int to=j-1;
				int dist=d[j]-d[to];
				if(dist+ptr<g&&vis[to][dist+ptr]==0) {
					vis[to][dist+ptr]=1;
					p[dist+ptr].push(to);
					yes++;
				} else if(dist+ptr==g&&vis[to][0]==0) {
					vis[to][0]=1;
					p2.push(to);
					yes++;
				}
			}
			if(j<m) {
				int to=j+1;
				int dist=d[to]-d[j];
//				trace(to,dist,g);
				if(dist+ptr<g&&vis[to][dist+ptr]==0) {
					vis[to][dist+ptr]=1;
					p[dist+ptr].push(to);
					yes++;
					if(to==m)
						ans=min(ans,turn*(r+g)+ptr+dist);
				} else if(dist+ptr==g&&vis[to][0]==0) {
					vis[to][0]=1;
					p2.push(to);
					yes++;
					if(to==m) {
						ans=min(ans,turn*(r+g)+g);
					}
				}
			}
		}
		ptr++;
		trace(ptr,yes);
	}
	if(ans==infl)
		ans=-1;
	cout<<ans<<endl;
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