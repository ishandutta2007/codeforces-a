/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)

//using int = long long
//using i128 = __int128;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(),(x).end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))
#define Time 1.0*clock()/CLOCKS_PER_SEC

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;

namespace IO{
	char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)
	inline ll read(){
		ll x=0; bool sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	} inline void print(ll x){if(x>9)print(x/10); pc(x%10+'0');}
}

const int mod=998244353;
const long double Pi=acos(-1);

namespace math{
	const int MAXN=1e6+5;
	ll ksm(ll a,ll b){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}
	ll fc[MAXN],ifc[MAXN];
	void init(){
		fc[0]=1; for(int i=1;i<MAXN;i++)fc[i]=fc[i-1]*i%mod;
		ifc[MAXN-1]=inv(fc[MAXN-1]);
		for(int i=MAXN-2;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll bin(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

// Please give me more points.

using namespace IO;
//using namespace math;

const int N=1e5+5;

ll a,buc[N];

int main(){
	ll n,t;
	string s;
	cin>>n>>t>>s;
	a+=1<<s[n-1]-'a';
	a-=1<<s[n-2]-'a';
	for(int i=0;i<n-2;i++)
		buc[s[i]-'a']++,a-=1<<s[i]-'a';
	ll nd=t-a;
	if(nd<0||nd&1)puts("No"),exit(0);
	for(int i=0;i<50;i++){
		if((nd>>i+1)&1){
			if(!buc[i])puts("No"),exit(0);
			buc[i]--;
		}
		buc[i+1]+=buc[i]>>1;
	} puts("Yes");
	return 0;
}