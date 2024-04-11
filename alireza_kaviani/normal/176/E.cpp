#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , q , timer , start[MAXN] , H[MAXN] , par[LOG][MAXN];
ll ans , D[MAXN];
vector<pii> adj[MAXN];
set<pii> st;

void DFS(int v , int p){
	par[0][v] = p;
	H[v] = H[p] + 1;
	start[v] = ++timer;
	for(pii i : adj[v]){
		int u = i.X , w = i.Y; 
		if(u == p)	continue;
		D[u] = D[v] + w;
		DFS(u , v);
	}
}

int getPar(int v , int h){
	for(int i = 0 ; i < LOG ; i++){
		if(h & (1 << i)){
			v = par[i][v];
		}
	}
	return v;
}

int LCA(int v , int u){
	if(H[v] > H[u])	swap(v , u);
	u = getPar(u , H[u] - H[v]);
	if(v == u)	return v;
	for(int i = LOG - 1 ; i >= 0 ; i--){
		if(par[i][v] != par[i][u]){
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

ll Dist(int v , int u){
	return D[v] + D[u] - 2 * D[LCA(v , u)];
}

ll calc(int v){
	if(SZ(st) == 0)	return 0;
	auto nxt = st.lower_bound({start[v] , v});
	auto prv = nxt;
	if(nxt == st.begin()){
		prv = prev(st.end());
	}
	else{
		prv = prev(nxt);
	}
	if(nxt == st.end()){
		nxt = st.begin();
	}
	int A = (*nxt).Y , B = (*prv).Y;
	return Dist(A , v) + Dist(B , v) - Dist(A , B);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int v , u , w;
		cin >> v >> u >> w;
		adj[v].push_back({u , w});
		adj[u].push_back({v , w});
	}
	DFS(1 , 0);
	for(int i = 1 ; i < LOG ; i++){
		for(int j = 0 ; j <= n ; j++){
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	cin >> q;
	while(q--){
		string s;
		int v;
		cin >> s;
		if(s == "+"){
			cin >> v;
			ans += calc(v);
			st.insert({start[v] , v});
		}
		if(s == "-"){
			cin >> v;
			st.erase({start[v] , v});
			ans -= calc(v);
		}
		if(s == "?"){
			cout << ans / 2 << endl;
		}
	}

	return 0;
}
/*

*/