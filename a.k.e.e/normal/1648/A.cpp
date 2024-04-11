#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=100005;

int n,m,o;
vector<int> a[MAXN],b[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1,c;i<=n;++i)
		for(int j=1;j<=m;++j)
			readint(c),a[c].pb(i),b[c].pb(j),chkmax(o,c);
	ll res=0;
	for(int i=1;i<=o;++i)
	{
		sort(a[i].begin(),a[i].end());
		for(int j=0;j<a[i].size();++j)
			res+=1ll*(j+1-(int)a[i].size()+j)*a[i][j];
		sort(b[i].begin(),b[i].end());
		for(int j=0;j<b[i].size();++j)
			res+=1ll*(j+1-(int)b[i].size()+j)*b[i][j];
	}
	printf("%lld\n",res);
	return 0;
}