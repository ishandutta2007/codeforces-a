#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=1019260817;
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

int n,a[MAXN],m,cnt[MAXN];
pii b[MAXN];
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]),cnt[i]=0;
	m=0;
	int las=1;
	for(int i=2;i<=n;++i)
		if(a[i]==a[i-1])b[++m]=mp(a[las],a[i-1]),las=i;
	b[++m]=mp(a[las],a[n]);
	for(int i=1;i<=m;++i)++cnt[b[i].x],++cnt[b[i].y];
	int mc=0;
	for(int i=1;i<=n;++i)if(cnt[i]>cnt[mc])mc=i;
	if(cnt[mc]<=m+1){printf("%d\n",m-1);return;}
	int t=0;
	for(int i=1;i<n;++i)
		if(a[i]!=a[i+1] && a[i]!=mc && a[i+1]!=mc)
			++t;
	if(cnt[mc]-t>m+1)printf("-1\n");
	else printf("%d\n",cnt[mc]-2);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}