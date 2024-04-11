#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int P[MAXN], Q[MAXN];
bool mark[MAXN];
int comp[MAXN];
char ans[MAXN];
vector<int> G[MAXN];
vector<int> GR[MAXN];
vector<int> topol;

void add_edge(int u, int v){
	G[u].pb(v);
	GR[v].pb(u);
}

void dfs1(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs1(v);
	topol.pb(node);
}

void dfs2(int node, int id){
	comp[node]=id;
	for (int v:GR[node]) if (!comp[v]) dfs2(v, id);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>P[i];
	for (int i=1; i<=n; i++) cin>>Q[i];
	for (int i=1; i<n; i++){
		add_edge(P[i], P[i+1]);
		add_edge(Q[i], Q[i+1]);
	}
	for (int i=1; i<=n; i++) if (!mark[i]) dfs1(i);
	reverse(all(topol));
	for (int v:topol) if (!comp[v]) dfs2(v, v);
	reverse(all(topol));
	for (int v:topol) if (comp[v]==v) ans[v]='a'+max(--k, 0);
	if (k>0) kill("NO")
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<ans[comp[i]];
	
	return 0;
}