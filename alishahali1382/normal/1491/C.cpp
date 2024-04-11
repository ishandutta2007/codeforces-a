#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], B[MAXN];
int par[MAXN];

int get(int x){ return (par[x]==x?x:par[x]=get(par[x]));}

int Solve(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], par[i]=i;
	par[n+1]=n+1;
	ans=0;
	for (int i=1; i<=n; i++){
		ans+=A[i]-1;
		if (i+A[i]>=n+1) A[i]=n-i;
		while (A[i]>1){
			int j=i;
			while (j<=n){
				if (A[j]==1){
					par[j]=get(j+1);
					j=get(j);
					continue ;
				}
				int jj=j+A[j];
				A[j]--;
				j=jj;
			}
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}