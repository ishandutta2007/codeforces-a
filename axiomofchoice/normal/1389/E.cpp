#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=100010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii;
ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int n,m,d,ans;
void work(int x){
	int t=(n-x)/mod;
	ans+=(n-x+n-x-t*mod)*(t+1)/2;
}
void Solve(){
	m=read(),d=read(),mod=read(),ans=0,n=min(m,d);
	if(m==1 || mod==1 || d==1){printf("%lld\n",n*(n-1)/2); return;}
	mod/=__gcd(mod,d-1);
	work(0);
	ans-=n;
	printf("%lld\n",ans);
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}