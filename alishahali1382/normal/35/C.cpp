#include <bits/stdc++.h>
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

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 2010;

char A[MAXN][MAXN];
bool mask[MAXN][MAXN][4];

bool right(int x, int y, int t){
	return mask[x][y][(t+1)%4] && mask[x][y+1][(t+3)%4];
}
bool left(int x, int y, int t){
	return mask[x][y][(t+3)%4] && mask[x][y-1][(t+1)%4];
}
bool up(int x, int y, int t){
	return mask[x][y][t%4] && mask[x-1][y][(t+2)%4];
}
bool down(int x, int y, int t){
	return mask[x][y][(t+2)%4] && mask[x+1][y][t%4];
}

int n, m, k, x, y, w, t=1, ans, v, u, xt, yt, xm, ym;
int dist[MAXN][MAXN];
queue<pii> q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	memset(dist, 63, sizeof(dist));
	while (k--){
		cin>>x>>y;
		q.push({x, y});
		dist[x][y]=0;
	}
	while (!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		if (!x || !y || x>n || y>m) continue ;
		ans=max(ans, dist[x][y]);
		
		if (dist[x][y]+1<dist[x-1][y]){
			dist[x-1][y]=dist[x][y]+1;
			q.push({x-1, y});
		}
		if (dist[x][y]+1<dist[x+1][y]){
			dist[x+1][y]=dist[x][y]+1;
			q.push({x+1, y});
		}
		if (dist[x][y]+1<dist[x][y-1]){
			dist[x][y-1]=dist[x][y]+1;
			q.push({x, y-1});
		}
		if (dist[x][y]+1<dist[x][y+1]){
			dist[x][y+1]=dist[x][y]+1;
			q.push({x, y+1});
		}
	}
	for (int x=1; x<=n; x++) for (int y=1; y<=m; y++) if (dist[x][y]==ans){
		cout<<x<<' '<<y<<endl;
		return 0;
	}
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