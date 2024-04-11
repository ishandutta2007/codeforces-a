/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define pdd pair <double,double>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO {
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read() {
		int x=0,sign=0; char s=gc;
		while(!isdigit(s)) sign|=s=='-',s=gc;
		while(isdigit(s)) x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math {
	const int mod=1e9+7;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b) {ll s=1,m=a; while(b) {if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x) {return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n) {
		fc[0]=1;
		for(int i=1;i<=n;i++) fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--) ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m) {return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}


// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=3e3+5;

ll t,n,a[N];

int main(){
	cin>>t;
	while(t--){
		cin>>n; ll ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n-2;i++){
			vector <int> pre(n+1),suf(n+1);
			ll s=0;
			for(int j=i+2;j<=n;j++)suf[a[j]]++;
			for(int j=i+2;j<n;j++){
				pre[a[j-1]]++,s+=suf[a[j-1]];
				suf[a[j]]--,s-=pre[a[j]];
				if(a[i]==a[j])ans+=s;
			}
		} cout<<ans<<endl;
	}
	return 0;
}