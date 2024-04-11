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
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
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
const int MAXN=105;

int n,a[3][MAXN],p[MAXN];
void solve()
{
	readint(n);
	for(int k=0;k<3;++k)
		for(int i=1;i<=n;++i)
			readint(a[k][i]);
	p[1]=a[0][1];
	for(int i=2;i<n;++i)
		for(int k=0;k<3;++k)
			if(a[k][i]!=p[i-1]){p[i]=a[k][i];break;}
	for(int k=0;k<3;++k)
		if(a[k][n]!=p[1] && a[k][n]!=p[n-1]){p[n]=a[k][n];break;}
	for(int i=1;i<=n;++i)printf("%d ",p[i]);putchar('\n');
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