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

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dist[MAXN];
int W[MAXN];
int parid[MAXN];
bool ok[MAXN];
vector<piii> G[MAXN];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 63, sizeof(dist));
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>u>>v>>W[i];
		G[u].pb({{v, W[i]}, i});
		G[v].pb({{u, W[i]}, i});
	}
	cin>>u;
	pq.push({dist[u]=0, u});
	while (!pq.empty()){
		int v=pq.top().second;
		pq.pop();
		for (piii p:G[v]){
			int u=p.first.first, w=p.first.second, id=p.second;
			if (dist[v]+w==dist[u] && w<W[parid[u]]){
				ok[parid[u]]=0;
				ok[parid[u]=id]=1;
			}
			if (dist[v]+w<dist[u]){
				pq.push({dist[u]=dist[v]+w, u});
				ok[parid[u]]=0;
				ok[parid[u]=id]=1;
			}
		}
	}
	for (int i=1; i<=m; i++) ans+=W[i]*ok[i];
	cout<<ans<<'\n';
	for (int i=1; i<=m; i++) if (ok[i]) cout<<i<<' ';
	
	
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