#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int MAXN = 300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int mark[MAXN];
vector<pii> G[MAXN];
vector<int> out;

void solve(){
	cin>>n>>m;
	out.clear();
	for (int i=1; i<=3*n; i++) G[i].clear(), mark[i]=0;
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		if (u>v) swap(u, v);
		G[u].pb({v, i});
		//G[v].pb(u);
	}
	for (int i=1; i<=3*n; i++) if (!mark[i]){
		for (pii p:G[i]) if (!mark[p.first]){
			mark[i]=mark[p.first]=1;
			out.pb(p.second);
			break ;
		}
	}
	if (out.size()>=n){
		cout<<"Matching\n";
		out.resize(n);
		sort(all(out));
		for (int x:out) cout<<x<<' ';cout<<'\n';
		return ;
	}
	int cnt=n;
	cout<<"IndSet\n";
	for (int i=1; i<=3*n && cnt; i++) if (!mark[i]) cout<<i<<' ', cnt--;
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;cin>>T;
	while (T--) solve();
	
	return 0;
}