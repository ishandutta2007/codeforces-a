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
#define int ll
int a[N],b[N],n,m,x,k,y,ans;
void work(int l,int r){
	if(l>r)return;
	int len=r-l+1;
	int res=INF;
	if(*max_element(a+l,a+r+1)<max(a[l-1],a[r+1])){
		res=min(res,len*y);
	}
	if(len>=k){
		res=min(res,x+(len-k)*y);
		res=min(res,len/k*x+(len%k)*y);
	}
	if(res==INF)cout<<-1<<endl,exit(0);
	ans+=res;
}
void Solve(){
	n=read(),m=read(),x=read(),k=read(),y=read();
	repeat(i,1,n+1)a[i]=read(); a[0]=a[n+1]=-1;
	repeat(i,1,m+1)b[i]=read(); b[m+1]=-1;
	int t=1,pre=1;
	repeat(i,1,n+1)
	if(a[i]==b[t])
		work(pre,i-1),pre=i+1,t++;
	work(pre,n);
	if(t!=m+1)cout<<-1<<endl,exit(0);
	cout<<ans<<endl;
}
signed main(){
	int T=1; //T=read();
	while(T--)Solve();
	return 0;
}