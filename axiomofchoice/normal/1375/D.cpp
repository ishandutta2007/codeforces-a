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
const int N=500010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int a[N],n;
vector<int> ans,f;
int getmex(){
	f.assign(n+1,0);
	repeat(i,0,n)f[a[i]]=1;
	repeat(i,0,n)if(f[i]==0)return i; return n;
}
bool nondec(){
	repeat(i,0,n-1)if(a[i]>a[i+1])return false;
	return true;
}
void Solve(){
	cin>>n;
	repeat(i,0,n)cin>>a[i];
	int z=n; ans.clear();
	while(!nondec()){
		int mex=getmex(),pos=mex; //orzarr(a,n); orz(mex);
		if(z==pos)pos--,z--;
		a[pos]=mex;
		ans.push_back(pos+1);
	} //orzarr(a,n);
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<' ';
	cout<<endl;
}
signed main(){
	int T=1; cin>>T;
	while(T--)Solve();
	return 0;
}