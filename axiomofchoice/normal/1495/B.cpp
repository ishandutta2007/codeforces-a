// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> vector<T> &operator<<(vector<T> &a,T b){a.push_back(b); return a;} template<typename T> T sqr(T x){return x*x;} void print(ll x,bool e=0){printf("%lld%c",x," \n"[e]);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
// #define int ll
int a[N],pre[N],lst[N];
void out(int x){
	print(x,1);
	exit(0);
}
void Solve(){
	int n=read();
	repeat(i,1,n+1)a[i]=read();
	a[0]=a[n+1]=inf;
	repeat(i,1,n+1)
	if(a[i]>a[i-1])
		pre[i]=pre[i-1]+1;
	else
		pre[i]=1;
	repeat_back(i,1,n+1)
	if(a[i]>a[i+1])
		lst[i]=lst[i+1]+1;
	else
		lst[i]=1;
	// orzarr(pre+1,n);
	// orzarr(lst+1,n);
	int mx=max(*max_element(pre+1,pre+n+1),*max_element(lst+1,lst+n+1));
	if(count(pre+1,pre+n+1,mx)==1
	&& count(lst+1,lst+n+1,mx)==1
	&& max_element(pre+1,pre+n+1)-pre==max_element(lst+1,lst+n+1)-lst)
		out(mx%2);
	out(0);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; // T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}