#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> edge;
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
const int MAXN = 100010;

int n, m, k, u, v, x, y, t, a, b, ans;
edge E[MAXN];
int deg[MAXN];
int vis[MAXN];
vector<int> G[MAXN];
vector<int> topol;
queue<int> q;

void topsort(){
	for (int i=1; i<=n; i++) if (!deg[i]) q.push(i);
	while (!q.empty()){
		int v=q.front();
		q.pop();
		topol.pb(v);
		for (int i:G[v]) if (!(--deg[i])) q.push(i);
	}
}

bool check(int x){
	memset(deg, 0, sizeof(deg));
	topol.clear();
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=0; i<m; i++){
		if (E[i].second<=x) continue ;
		int u=E[i].first.first, v=E[i].first.second;
		G[u].pb(v);
		deg[v]++;
	}
	topsort();
	return topol.size()==n;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v>>x;
		E[i]={{u, v}, x};
	}
	int dwn=-1, up=1e9;
	while (up-dwn>1){
		int mid=(dwn+up)/2;
		if (check(mid)) up=mid;
		else dwn=mid;
	}
	ans=up;
	check(ans);
	//debug(topol.size());
	for (int i=0; i<n; i++) vis[topol[i]]=i;
	vector<int> out;
	for (int i=0; i<m; i++){
		int u=E[i].first.first, v=E[i].first.second;
		if (vis[u]>vis[v]) out.pb(i);
	}
	sort(all(out));
	cout<<ans<<' '<<out.size()<<endl;
	for (int i:out) cout<<i+1<<' ';
	
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