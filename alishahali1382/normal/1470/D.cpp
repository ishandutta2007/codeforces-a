#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int mark[MAXN];
vector<int> G[MAXN], vec, out;

void dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs(v);
	vec.pb(node);
}

int Solve(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) mark[i]=0, G[i].clear();
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	vec.clear();
	out.clear();
	dfs(1);
	if (vec.size()!=n) kill("NO")
	reverse(all(vec));
//	debugv(vec)
	for (int v:vec){
		bool bad=0;
		for (int u:G[v]) if (mark[u]==2) bad=1;
		if (bad) continue ;
		mark[v]=2;
		out.pb(v);
	}
	cout<<"YES\n";
	cout<<out.size()<<"\n";
	for (int v:out) cout<<v<<" ";cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}