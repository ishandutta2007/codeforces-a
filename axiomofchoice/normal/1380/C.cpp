#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
const int mod=(0?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
int a[N];
void Solve(){
	int n=read(),x=read();
	repeat(i,0,n)a[i]=read(),a[i]=(x+a[i]-1)/a[i];
	sort(a,a+n);
	//orzarr(a,n);
	int pre=0,ans=0;
	repeat(i,0,n){
		if(a[i]<=i-pre+1){
			pre=i+1;
			ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}