#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
int a[N],cnt[2];
void Solve(){
	int n=read(),s=0;
	repeat(i,0,n){
		a[i]=read();
		s^=a[i];
	}
	if(s==0){puts("DRAW"); return;}
	int b=1<<(31-__builtin_clz(s)); //orz(b);
	mst(cnt,0);
	repeat(i,0,n)cnt[bool(a[i]&b)]++;
	if(cnt[1]%4==1 || n%2==0)puts("WIN");
	else puts("LOSE");
}
signed main(){
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}