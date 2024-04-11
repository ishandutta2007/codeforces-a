#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const int  N     =  1e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, m, a[N], vis[N];
vll adj[N], rev[N], v;
stack <int> s;

void dfs1(int x){
	vis[x] = 1;
	for(auto it : adj[x]){
		if(vis[it]) continue;
		dfs1(it);
	}
	s.push(x);
}

void dfs2(int x){
	vis[x] = 1;
	v.pb(x);
	for(auto it : rev[x]){
		if(vis[it]) continue;
		dfs2(it);
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		rev[v].pb(u);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]) dfs1(i);
	}
	mset(vis, 0);
	ll ans = 1, res = 0;
	while(s.size()){
		int x = s.top();
		s.pop();
		if(!vis[x]){
			v.clear();
			dfs2(x);
			ll ct = 0, mn = INF;
			for(auto it : v){
				if(a[it] < mn){
					mn = a[it];
					ct = 1;
				} else if(a[it] == mn) ct++;
			}
			res += mn;
			ans = (ans * ct) % mod;
		}
	}
	deb2(res, ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}