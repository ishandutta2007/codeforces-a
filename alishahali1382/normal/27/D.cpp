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
const int MAXN = 110, LOG=20;

int n, m, k, u, v, x, y, t;
pii A[MAXN];
char ans[MAXN];
vector<int> G[MAXN];

bool collide(pii x, pii y){
	if (x.first>y.first) swap(x, y);
	return (x.first<y.first && y.first<x.second && x.second<y.second);
}

bool dfs(int node, char ch){
	ans[node]=ch;
	for (int v:G[node]) if (ans[v] && ans[v]==ch || !ans[v] && dfs(v, 'i'+'o'-ch)) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>m>>n;
	for (int i=1; i<=n; i++){
		cin>>x>>y;
		if (x>y) swap(x, y);
		A[i]={x, y};
		for (int j=1; j<i; j++) if (collide(A[i], A[j])){
			G[i].pb(j);
			G[j].pb(i);
		}
	}
	for (int i=1; i<=n; i++) if (!ans[i] && dfs(i, 'i')) kill("Impossible")
	for (int i=1; i<=n; i++) cout<<ans[i];
	
	
	return 0;
}