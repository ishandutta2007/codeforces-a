#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
//#define vector basic_string
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=400010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int T,n,x,a[N],s[N],sum[N];
signed main(){
	cin>>n>>x;
	repeat(i,1,n+1){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		sum[i]=sum[i-1]+(1+a[i])*a[i]/2;
	}
	repeat(i,n+1,2*n+1){
		a[i]=a[i-n];
		s[i]=s[i-1]+a[i];
		sum[i]=sum[i-1]+(1+a[i])*a[i]/2;
	}
	n*=2;
	int ans=0;
	repeat(i,0,n+1){
		int p=upper_bound(s,s+n+1,s[i]-x)-s;
		if(p==0)continue;
		int t=s[i]-x-s[p-1];
		ans=max(ans,sum[i]-sum[p-1]-(1+t)*t/2);
	}
	cout<<ans<<endl;
	return 0;
}