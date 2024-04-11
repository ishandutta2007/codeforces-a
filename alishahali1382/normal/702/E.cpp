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
const int MAXN = 100010, LOG=34;

ll n, k, u, v, x, y, t, a, b;
int par[MAXN][LOG];
int mn[MAXN][LOG];
ll sum[MAXN][LOG];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>par[i][0], par[i][0]++;
	for (int i=1; i<=n; i++) cin>>sum[i][0], mn[i][0]=sum[i][0];
	for (int j=1; j<LOG; j++) for (int i=1; i<=n; i++){
		par[i][j]=par[par[i][j-1]][j-1];
		mn[i][j]=min(mn[i][j-1], mn[par[i][j-1]][j-1]);
		sum[i][j]=sum[i][j-1] + sum[par[i][j-1]][j-1];
	}
	for (int i=1; i<=n; i++){
		ll s=0;
		int m=inf;
		int v=i;
		for (int j=0; j<LOG; j++) if ((1ll<<j)&k){
			s+=sum[v][j];
			m=min(m, mn[v][j]);
			v=par[v][j];
		}
		cout<<s<<' '<<m<<'\n';
	}
	
	return 0;
}