#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=2e5+5, INF=1e9+5, mod=1e9+7;
int F[30], siz[N];
vi edg;
vi E[N];
int blo[2*N];
vi todo[30];
int czy;
void dfs(int v, int e, int k){
	//cout<<v<<" "<<e<<" "<<k<<" "<<*czy<<"\n";
	if(F[k]<5)czy=0;
	if(!czy)return;
	siz[v]=1;
	for(int u:E[v]){
		if(u!=(e^1) && !blo[u]){
			dfs(edg[u], u, k);
			siz[v]+=siz[edg[u]];
		}
		if(!czy)break;
	}
	if(czy && siz[v]==F[k-1]){
		if(e!=-1)blo[e]=1, blo[e^1]=1;
		czy=0;
		todo[k-1].pb(v);
		todo[k-2].pb(edg[e^1]);
	}
	else if(czy && siz[v]==F[k-2]){
		if(e!=-1)blo[e]=1, blo[e^1]=1;
		czy=0;
		todo[k-2].pb(v);
		todo[k-1].pb(edg[e^1]);
	}
}
int main(){
	BOOST;
	int n=28657;
	cin>>n;
	F[0]=0;
	F[1]=1;
	int k=50;
	for(int i=2; i<30; i++){F[i]=F[i-1]+F[i-2];if(F[i]==n)k=i;}
	if(k==50){
		cout<<"NO";
		return 0;
	}
	for(int i=1; i<n; i++){
		int u, v;
		cin>>u>>v;
		E[u].pb(sz(edg));
		edg.pb(v);
		E[v].pb(sz(edg));
		edg.pb(u);
	}
	todo[k].pb(1);
	bool b=1;
	for(int i=k; i>=0; i--){
		for(int j:todo[i]){
			czy=1;
			dfs(j, -1, i);
			if(czy==1)b=0;
		}
	}
	if(b)cout<<"YES";
	else cout<<"NO";
}