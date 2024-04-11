#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 300010;

struct DSU{
	int par[MAXN];
	int sz[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
		for (int i=1; i<MAXN; i++) sz[i]=1;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return ;
		if (sz[x]>sz[y]) swap(x, y);
		par[x]=y;
		sz[y]+=sz[x];
	}
} dsu;

int n, m, k, u, v, x, y, t, a, b, root=2;
int mark[MAXN];
vector<int> G[MAXN];
vector<int> out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	while (m--){
		cin>>u>>v;
		if (u>v) swap(u, v);
		if (u==1){
			G[1].pb(v);
			continue ;
		}
		G[u].pb(v);
		G[v].pb(u);
	}
	if (n-G[1].size()-1<k) kill("impossible");
	for (int i=3; i<=n; i++) if (G[i].size()<G[root].size()) root=i;
	for (int i=0; i<=n; i++) mark[i]=2;
	for (int i:G[root]) mark[i]=1;
	for (int i=2; i<=n; i++) if (mark[i]==2) dsu.join(root, i);
	for (int i:G[root]) mark[i]=0;
	
	for (int i:G[root]){
		int tmp=0;
		for (int j:G[i]){
			if (mark[j]==2) tmp++;
			else mark[j]=1;
		}
		if (tmp<n-G[root].size()-1) dsu.join(root, i);
		for (int j:G[root]) if (!mark[j]) dsu.join(i, j);
		for (int j:G[i]) if (mark[j]!=2) mark[j]=0;
	}
	//for (int i=1; i<=n; i++) cerr<<dsu.par[i]<<' ';cerr<<endl;
	memset(mark, 0, sizeof(mark));
	for (int i:G[1]) mark[i]=1;
	for (int i=1; i<=n; i++){
		if (dsu.get(1)==dsu.get(i) || mark[i]) continue ;
		if (!k) kill("impossible");
		k--;
		dsu.join(1, i);
	}
	for (int i=1; i<=n; i++) if (dsu.get(i)!=dsu.get(1)) kill("impossible");
	cout<<"possible"<<endl;
	
	return 0;
}
/*
          .---.                                                                     .---.              ...-'  |`. ..-'''-.       / .--. \        .-''-.
          |   |.--.                       .                     .                   |   |.--.          |      |  |\.-'''\ \     ' '    ' '     .' .-.  )
          |   ||__|                     .'|                   .'|                   |   ||__|          ....   |  |       | |    \ \    / /    / .'  / /
          |   |.--.                    <  |                  <  |                   |   |.--.            -|   |  |    __/ /      `.`'--.'    (_/   / /
    __    |   ||  |                     | |             __    | |             __    |   ||  |             |   |  |   |_  '.      / `'-. `.        / /
 .:--.'.  |   ||  |                 _   | | .'''-.   .:--.'.  | | .'''-.   .:--.'.  |   ||  |          ...'   `--'      `.  \   ' /    `. \      / /
/ |   \ | |   ||  |               .' |  | |/.'''. \ / |   \ | | |/.'''. \ / |   \ | |   ||  |          |         |`.      \ '. / /       \ '    . '
`" __ | | |   ||  |              .   | /|  /    | | `" __ | | |  /    | | `" __ | | |   ||  |          ` --------\ |       , || |         | |  / /    _.-')
 .'.''| | |   ||__|            .'.'| |//| |     | |  .'.''| | | |     | |  .'.''| | |   ||__|           `---------'        | || |         | |.' '  _.'.-''
/ /   | |_'---'              .'.'.-'  / | |     | | / /   | |_| |     | | / /   | |_'---'                                 / ,' \ \       / //  /.-'_.'
\ \._,\ '/                   .'   \_.'  | '.    | '.\ \._,\ '/| '.    | '.\ \._,\ '/                              -....--'  /   `.'-...-'.'/    _.'
 `--'  `"                               '---'   '---'`--'  `" '---'   '---'`--'  `"                               `.. __..-'       `-...-'( _.-'
*/