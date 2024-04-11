/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN64
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=getchar();
		while(!isdigit(s))sign|=s=='-',s=getchar();
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=1e9+7;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1; for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]); for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=1e3+5;

const int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};

char mp[N][N];
bool vis[N][N],apx[N],apy[N]; int ans,n,m;

void dfs(int x,int y){
	vis[x][y]=1; apx[x]=apy[y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&yy>0&&xx<=n&&yy<=m&&mp[xx][yy]=='#'&&!vis[xx][yy])dfs(xx,yy);
	} 
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mp[i][j];
	for(int i=1;i<=n;i++){
		int ap=0;
		for(int j=1;j<=m;j++)if(mp[i][j]=='#'){
			if(!ap)ap=1; else if(ap==2)puts("-1"),exit(0);
		}
		else if(ap==1)ap=2;
	}
	for(int i=1;i<=m;i++){
		int ap=0;
		for(int j=1;j<=n;j++)if(mp[j][i]=='#'){
			if(!ap)ap=1; else if(ap==2)puts("-1"),exit(0);
		}
		else if(ap==1)ap=2;
	}
	
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(mp[i][j]=='#'&&!vis[i][j])ans++,dfs(i,j);
	bool x=0,y=0;
	for(int i=1;i<=n;i++)x|=!apx[i];
	for(int i=1;i<=m;i++)y|=!apy[i];
	if(x^y)puts("-1"),exit(0);
	cout<<ans<<endl;
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}