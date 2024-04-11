#pragma GCC optimze("Ofast")
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

char a[1005][1005];
int dist[1005][1005];
void solve() {
	memset(dist,0x3f,sizeof(dist));
	int n,m,t;
	cin>>n>>m>>t;
	fr(i,1,n)
		fr(j,1,m) {
			cin>>a[i][j];
			dist[i][j]=-1;
		}
	queue<pii> poo;
	int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
	fr(i,1,n)
		fr(j,1,m)
			rep(k,0,4)
				if(i+dx[k]>=1&&i+dx[k]<=n)
					if(j+dy[k]>=1&&j+dy[k]<=m)
						if(a[i][j]==a[i+dx[k]][j+dy[k]]) {
							dist[i][j]=0;
							poo.push({i,j});
						}
	while(!poo.empty()) {
		pii at=poo.front();
		poo.pop();
		rep(j,0,4)
			if(dist[at.fi+dx[j]][at.se+dy[j]]==-1) {
				dist[at.fi+dx[j]][at.se+dy[j]]=dist[at.fi][at.se]+1;
				poo.push({at.fi+dx[j],at.se+dy[j]});
			}
	}
	while(t--) {
		int x,y,p;
		cin>>x>>y>>p;
		if(dist[x][y]==-1) {
			cout<<a[x][y]<<endl;
		} else {
			p-=dist[x][y];
			if(p<=0) {
				cout<<a[x][y]<<endl;
			} else {
				if(p&1) {
					if(a[x][y]=='0')
						cout<<'1'<<endl;
					else
						cout<<'0'<<endl;
				} else
					cout<<a[x][y]<<endl;
			}
		}

	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}